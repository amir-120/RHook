#pragma once
#include <RHook/utility/Address.hpp>

#include <functional>
#include <vector>
#include <memory>
#include <mutex>

#include <xmmintrin.h>

namespace RHook {
#pragma pack(push, r1, 16)
#ifdef _M_X64
	/*struct __declspec(align(16)) VolatileContext {
		// Vector registers
		__m128 XMM0;
		__m128 XMM1;
		__m128 XMM2;
		__m128 XMM3;
		__m128 XMM4;
		__m128 XMM5;

		// Integer Registers
		unsigned __int64 EFlags;
		unsigned __int64 R11;
		unsigned __int64 R10;
		unsigned __int64 R9;
		unsigned __int64 R8;
		unsigned __int64 RDX;
		unsigned __int64 RCX;
		unsigned __int64 RAX;
	};

	static_assert(sizeof(VolatileContext) == 160, "Volatile thread context size mismatch!");*/

	struct __declspec(align(16)) Context {
		// Integer Registers
		unsigned __int64 RAX;		// 0x00 - 0
		unsigned __int64 RBX;		// 0x08 - 8
		unsigned __int64 RCX;		// 0x10 - 16
		unsigned __int64 RDX;		// 0x18 - 24
		unsigned __int64 RSP;		// 0x20 - 32
		unsigned __int64 RBP;		// 0x28 - 40
		unsigned __int64 RSI;		// 0x30 - 48
		unsigned __int64 RDI;		// 0x38 - 56
		unsigned __int64 R8;		// 0x40 - 64
		unsigned __int64 R9;		// 0x48 - 72
		unsigned __int64 R10;		// 0x50 - 80
		unsigned __int64 R11;		// 0x58 - 88
		unsigned __int64 R12;		// 0x60 - 96
		unsigned __int64 R13;		// 0x68 - 104
		unsigned __int64 R14;		// 0x70 - 112
		unsigned __int64 R15;		// 0x78 - 120
		unsigned __int64 EFlags;	// 0x80 - 128

		// Vector registers
		__m128 XMM0;				// 0x90 - 144
		__m128 XMM1;				// 0xA0 - 160
		__m128 XMM2;				// 0xB0 - 176
		__m128 XMM3;				// 0xC0 - 192
		__m128 XMM4;				// 0xD0 - 208
		__m128 XMM5;				// 0xE0 - 224
		__m128 XMM6;				// 0xF0 - 240
		__m128 XMM7;				// 0x100 - 256
		__m128 XMM8;				// 0x110 - 272
		__m128 XMM9;				// 0x120 - 288
		__m128 XMM10;				// 0x130 - 304
		__m128 XMM11;				// 0x140 - 320
		__m128 XMM12;				// 0x150 - 336
		__m128 XMM13;				// 0x160 - 352
		__m128 XMM14;				// 0x170 - 368
		__m128 XMM15;				// 0x180 - 384
	}; // 0x188 - 400

	static_assert(sizeof(Context) == 0x190, "Thread context size mismatch!");
#else
	/*struct __declspec(align(16)) VolatileContext {
		// Vector registers
		__m128 XMM0;
		__m128 XMM1;
		__m128 XMM2;
		__m128 XMM3;
		__m128 XMM4;
		__m128 XMM5;

		// Integer Registers
		unsigned __int32 EFlags;
		unsigned __int32 EAX;
		unsigned __int32 ECX;
		unsigned __int32 EDX;
	};

	static_assert(sizeof(VolatileContext) == 112, "Volatile thread context size mismatch!");*/

	struct __declspec(align(16)) Context {
		// Integer Registers
		unsigned __int32 EAX;		// 0x00 - 0
		unsigned __int32 EBX;		// 0x04 - 4
		unsigned __int32 ECX;		// 0x08 - 8
		unsigned __int32 EDX;		// 0x0C - 12
		unsigned __int32 ESI;		// 0x10 - 16
		unsigned __int32 EDI;		// 0x14 - 20
		unsigned __int32 ESP;		// 0x18 - 24
		unsigned __int32 EBP;		// 0x1C - 28
		unsigned __int32 EFlags;	// 0x20 - 32

		// Vector registers
		__m128 XMM0;				// 0x30 - 48
		__m128 XMM1;				// 0x40 - 64
		__m128 XMM2;				// 0x50 - 80
		__m128 XMM3;				// 0x60 - 96
		__m128 XMM4;				// 0x70 - 112
		__m128 XMM5;				// 0x80 - 128
		__m128 XMM6;				// 0x90 - 144
		__m128 XMM7;				// 0xA0 - 160
	}; // 0xB0 - 176

	static_assert(sizeof(Context) == 0xB0, "Thread context size mismatch!");
#endif
#pragma pack(pop, r1)

	// Aligned to 16 because in the shellcode movaps is used for copying vector registers
	class __declspec(align(16)) MidHookCodeBlock {
	public:
		//************************************
		// Method:    MidHookCodeBlock
		// FullName:  RHook::MidHookCodeBlock::MidHookCodeBlock
		// Access:    public 
		// Returns:   
		// Qualifier:
		// Parameter: CRType(*destFn)(CArgs...) - Function pointer of the hook destination, this must have the current function type 
		// Parameter: Address trampoline - Address of the stolen bytes of the hook
		// Parameter: Address closeTo - nullptr by default, address of where the shellcode is preffered to be close to, if nullptr it will allocate anywhere possible in the memory
		// Parameter: size_t align - Shellcode memory alignment
		//************************************
		template <typename CRType, typename... CArgs>
		MidHookCodeBlock(CRType(*destFn)(CArgs...), Address trampoline, Address closeTo = nullptr, size_t align = 0) {
			AllocateCode(closeTo, align);
			LoadShellCodeVariableAddresses();

			// CheckValidity the variables inside the shellcode
			*m_ppContext = &m_Context;
			*m_ppThis = this;
			SetDestination<CRType, CArgs...>(destFn);
			SetTrampoline(trampoline);

			// Argument count
			constexpr auto argc = sizeof...(CArgs);

			// Allocate memory for pointer to arguments if there is any argument
			if constexpr (argc > 0) {
				m_ppArguments = new Address[argc];
			}

			// Allocate space for the return value if it's not void
			if constexpr (!std::is_same_v<CRType, void>) {
				m_pReturnValue = new CRType;
			}
		}

		virtual ~MidHookCodeBlock();


		//************************************
		// Method:    IsValid
		// FullName:  RHook::MidHookCodeBlock::IsValid
		// Access:    public 
		// Returns:   bool
		// Qualifier:
		// Caption:   Returns true if the shellcode is allocated, doesn't check if the variables are all set and the shellcode is ready for execution
		//************************************
		bool IsValid() {
			return m_Address != nullptr;
		}

		//************************************
		// Method:    IsReadyToExecute
		// FullName:  RHook::MidHookCodeBlock::IsReadyToExecute
		// Access:    public 
		// Returns:   bool
		// Qualifier:
		// Caption:   Returns true if the shellcode is allocate, variables are set and the it is ready to be executed
		//************************************
		bool IsReadyToExecute() {
			return m_Address != nullptr && m_ppThis != nullptr && *m_ppThis == this &&
				m_ppContext != nullptr && *m_ppContext == &m_Context && 
				m_pFnCallWrapper != nullptr && *m_pFnCallWrapper != nullptr &&
				m_ppTrampoline != nullptr && *m_ppTrampoline != nullptr;
		}

		//************************************
		// Method:    GetCodeAddress
		// FullName:  RHook::MidHookCodeBlock::GetCodeAddress
		// Access:    public 
		// Returns:   RHook::Address
		// Qualifier: const
		// Caption:   Get the address to the beginning of the code section of the allocated bytes 
		//************************************
		Address GetCodeAddress() const { return m_Start; }

		//************************************
		// Method:    GetBlockSize
		// FullName:  RHook::MidHookCodeBlock::GetBlockSize
		// Access:    public 
		// Returns:   size_t
		// Qualifier: const
		// Caption:   Get the size of the allocated bytes, including the variable offsets at the beginning
		//************************************
		size_t GetBlockSize() const { m_Address.As<uintptr_t>() - m_End.As<uintptr_t>(); }

		//************************************
		// Method:    GetCodeSize
		// FullName:  RHook::MidHookCodeBlock::GetCodeSize
		// Access:    public 
		// Returns:   size_t
		// Qualifier: const
		// Caption:   Get the allocated code size, this doesn't include the variable offsets at the beginning of the allocated bytes
		//************************************
		size_t GetCodeSize() const { m_Start.As<uintptr_t>() - m_End.As<uintptr_t>(); }

		//************************************
		// Method:    GetDestination
		// FullName:  RHook::MidHookCodeBlock::GetDestination
		// Access:    public 
		// Returns:   RHook::Address
		// Qualifier: const
		// Caption:   Get the destination function address from the shellcode
		//************************************
		Address GetDestination() const { return m_pFnCallWrapper->Deref(); }

		//************************************
		// Method:    SetDestination
		// FullName:  RHook::MidHookCodeBlock::SetDestination
		// Access:    public 
		// Returns:   void
		// Qualifier:
		// Caption:   Set the pointer to the hook destination function inside the shellcode
		// Parameter: CRType(*destination)(CArgs...) - Function pointer to the hook destination, this must be the correct function type
		//************************************
		template <typename CRType, typename... CArgs>
		void SetDestination(CRType(*destination)(CArgs...)) {
			using FnCallWrapper_t = void __cdecl(MidHookCodeBlock*);
			auto fnCallWrapper = &MidHookCodeBlock::CallWrapper<CRType, CArgs...>;

			m_pFnCallWrapper->Set((FnCallWrapper_t*&)fnCallWrapper);

			m_Destination.Set(destination);
		}

		//************************************
		// Method:    GetContext
		// FullName:  RHook::MidHookCodeBlock::GetContext
		// Access:    public 
		// Returns:   RHook::Context&
		// Qualifier:
		// Caption:   Get the context which stores the registers of the thread where the hook was place
		//************************************
		Context& GetContext() { return m_Context; };

		//************************************
		// Method:    GetTrampoline
		// FullName:  RHook::MidHookCodeBlock::GetTrampoline
		// Access:    public 
		// Returns:   RHook::Address
		// Qualifier: const
		// Caption:   Get the address of the stolen bytes from the shellcode
		//************************************
		Address GetTrampoline() const { return m_ppTrampoline->Deref(); }


		//************************************
		// Method:    SetTrampoline
		// FullName:  RHook::MidHookCodeBlock::SetTrampoline
		// Access:    public 
		// Returns:   void
		// Qualifier:
		// Parameter: Address trampoline - Address of the stolen bytes
		// Caption:   Get the address of the stolen bytes in the shellcode
		//************************************
		void SetTrampoline(Address trampoline) { m_ppTrampoline->Set(trampoline); }

		//************************************
		// Method:    SetArgLoaderCallback
		// FullName:  RHook::MidHookCodeBlock::SetArgLoaderCallback
		// Access:    public 
		// Returns:   void
		// Qualifier:
		// Caption:   Called once per each argument before the pre call callback and the destination call
		// Parameter: std::function<void(Context* pContext, Address* ppArguments, size_t index, bool vec)> fn - The callback
		// Parameter: Context * pContext - Pointer to a context object storing all the register stats where the hook is put down
		// Parameter: Address * ppArguments - An array of pointers which need to be set to point to the restored arguments in this callback
		// Parameter: size_t index - Index of the current argument the function is called for
		// Parameter: bool vec - If the argument is a floating point type, these are passed in vector registers in x64 
		//************************************
		void SetArgLoaderCallback(std::function<void(Context* pContext, Address* ppArguments, size_t index, bool vec)> fn) { m_FnCustomLoadArguments = fn; }
		
		//************************************
		// Method:    SetPreCallCallback
		// FullName:  RHook::MidHookCodeBlock::SetPreCallCallback
		// Access:    public 
		// Returns:   void
		// Qualifier:
		// Caption:	  Called once before the call to the destination and after the arguments are loaded
		// Parameter: std::function<void(MidHookCodeBlock* pThis, Address* ppArguments, size_t argc)> fn - The call back
		// Parameter: MidHookCodeBlock * pThis - Pointer to the current MidHookCodeBlock object
		// Parameter: Address * ppArguments - An array of pointers to the arguments which already have been set
		// Parameter: size_t argc - Argument count of the function
		//************************************
		void SetPreCallCallback(std::function<void(MidHookCodeBlock* pThis, Address* ppArguments, size_t argc)> fn) { m_FnPreCallCallback = fn; }
		
		//************************************
		// Method:    SetPostCallCallback
		// FullName:  RHook::MidHookCodeBlock::SetPostCallCallback
		// Access:    public 
		// Returns:   void
		// Qualifier:
		// Caption:   Called once after the call to the destination
		// Parameter: std::function<void(MidHookCodeBlock* pThis, Address pReturnValue)> fn
		// Parameter: MidHookCodeBlock * pThis - Pointer to the current MidHookCodeBlock object
		// Parameter: Address pReturnValue - Pointer to the return value, nullptr if the return value is void
		//************************************
		void SetPostCallCallback(std::function<void(MidHookCodeBlock* pThis, Address pReturnValue)> fn) { m_FnPostCallCallback = fn; }

	private:
		void AllocateCode(Address closeTo, size_t align);
		bool LoadShellCodeVariableAddresses();

	private:
		Address				m_Address{ nullptr }; // The allocated bytes (including the offsets)
		Address				m_Start{ nullptr }; // The allocated shell code
		Address				m_End{ nullptr }; // End of the allocated bytes (including the variables)

		// Where we save the thread context
		Context				m_Context{};

		// Address of variables inside the shellcode
		Context**			m_ppContext{ nullptr };
		MidHookCodeBlock**	m_ppThis{ nullptr };
		Address*			m_pFnCallWrapper{ nullptr };
		Address*			m_ppTrampoline{ nullptr };

		// The destination function we call from inside the callwrapper
		Address				m_Destination{ nullptr };

		Address*			m_ppArguments{ nullptr };
		Address				m_pReturnValue{ nullptr };

		// This is going to be called before the call to the destination function to set the arguments
		std::function<void(Context* pContext, Address* ppArguments, size_t argc, bool vec)> m_FnCustomLoadArguments{};

		// This is going to be called before the call to the destination function and after custom arg loader is called
		std::function<void(MidHookCodeBlock* pThis, Address* ppArguments, size_t argc)> m_FnPreCallCallback{};

		// This is going to be called after the call to the destination
		std::function<void(MidHookCodeBlock* pThis, Address pReturnValue)> m_FnPostCallCallback{};

#ifdef _M_X64
		constexpr static uint8_t s_ShellCode[]{ 0xD8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
												0xE0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
												0x50, 0x48, 0x8B, 0x05, 0xD0, 0x01, 0x00, 0x00, 0x48, 0x89, 0x58, 0x08, 0x48, 0x89, 0x48, 0x10,
												0x48, 0x89, 0x50, 0x18, 0x48, 0x89, 0x68, 0x28, 0x48, 0x89, 0x70, 0x30, 0x48, 0x89, 0x78, 0x38,
												0x4C, 0x89, 0x40, 0x40, 0x4C, 0x89, 0x48, 0x48, 0x4C, 0x89, 0x50, 0x50, 0x4C, 0x89, 0x58, 0x58,
												0x4C, 0x89, 0x60, 0x60, 0x4C, 0x89, 0x68, 0x68, 0x4C, 0x89, 0x70, 0x70, 0x4C, 0x89, 0x78, 0x78,
												0x48, 0x83, 0xC4, 0x08, 0x48, 0x89, 0x60, 0x20, 0x48, 0x83, 0xEC, 0x08, 0x53, 0x9C, 0x5B, 0x48,
												0x89, 0x98, 0x80, 0x00, 0x00, 0x00, 0x5B, 0x0F, 0x29, 0x80, 0x90, 0x00, 0x00, 0x00, 0x0F, 0x29,
												0x88, 0xA0, 0x00, 0x00, 0x00, 0x0F, 0x29, 0x90, 0xB0, 0x00, 0x00, 0x00, 0x0F, 0x29, 0x98, 0xC0,
												0x00, 0x00, 0x00, 0x0F, 0x29, 0xA0, 0xD0, 0x00, 0x00, 0x00, 0x0F, 0x29, 0xA8, 0xE0, 0x00, 0x00,
												0x00, 0x0F, 0x29, 0xB0, 0xF0, 0x00, 0x00, 0x00, 0x0F, 0x29, 0xB8, 0x00, 0x01, 0x00, 0x00, 0x44,
												0x0F, 0x29, 0x80, 0x10, 0x01, 0x00, 0x00, 0x44, 0x0F, 0x29, 0x88, 0x20, 0x01, 0x00, 0x00, 0x44,
												0x0F, 0x29, 0x90, 0x30, 0x01, 0x00, 0x00, 0x44, 0x0F, 0x29, 0x98, 0x40, 0x01, 0x00, 0x00, 0x44,
												0x0F, 0x29, 0xA0, 0x50, 0x01, 0x00, 0x00, 0x44, 0x0F, 0x29, 0xA8, 0x60, 0x01, 0x00, 0x00, 0x44,
												0x0F, 0x29, 0xB0, 0x70, 0x01, 0x00, 0x00, 0x44, 0x0F, 0x29, 0xB8, 0x80, 0x01, 0x00, 0x00, 0x53,
												0x48, 0x8B, 0x1C, 0x24, 0x48, 0x89, 0x18, 0x5B, 0x58, 0x48, 0x83, 0xEC, 0x10, 0x48, 0x83, 0xE4,
												0xF0, 0x48, 0x83, 0xEC, 0x20, 0x48, 0x8B, 0x0D, 0xE4, 0x00, 0x00, 0x00, 0xFF, 0x15, 0xEE, 0x00,
												0x00, 0x00, 0x48, 0x8B, 0x05, 0xDF, 0x00, 0x00, 0x00, 0x48, 0x8B, 0x58, 0x08, 0x48, 0x8B, 0x48,
												0x10, 0x48, 0x8B, 0x50, 0x18, 0x48, 0x8B, 0x60, 0x20, 0x48, 0x8B, 0x68, 0x28, 0x48, 0x8B, 0x70,
												0x30, 0x48, 0x8B, 0x78, 0x38, 0x4C, 0x8B, 0x40, 0x40, 0x4C, 0x8B, 0x48, 0x48, 0x4C, 0x8B, 0x50,
												0x50, 0x4C, 0x8B, 0x58, 0x58, 0x4C, 0x8B, 0x60, 0x60, 0x4C, 0x8B, 0x68, 0x68, 0x4C, 0x8B, 0x70,
												0x70, 0x4C, 0x8B, 0x78, 0x78, 0x53, 0x48, 0x8B, 0x98, 0x80, 0x00, 0x00, 0x00, 0x53, 0x9D, 0x5B,
												0x0F, 0x28, 0x80, 0x90, 0x00, 0x00, 0x00, 0x0F, 0x28, 0x88, 0xA0, 0x00, 0x00, 0x00, 0x0F, 0x28,
												0x90, 0xB0, 0x00, 0x00, 0x00, 0x0F, 0x28, 0x98, 0xC0, 0x00, 0x00, 0x00, 0x0F, 0x28, 0xA0, 0xD0,
												0x00, 0x00, 0x00, 0x0F, 0x28, 0xA8, 0xE0, 0x00, 0x00, 0x00, 0x0F, 0x28, 0xB0, 0xF0, 0x00, 0x00,
												0x00, 0x0F, 0x28, 0xB8, 0x00, 0x01, 0x00, 0x00, 0x44, 0x0F, 0x28, 0x80, 0x10, 0x01, 0x00, 0x00,
												0x44, 0x0F, 0x28, 0x88, 0x20, 0x01, 0x00, 0x00, 0x44, 0x0F, 0x28, 0x90, 0x30, 0x01, 0x00, 0x00,
												0x44, 0x0F, 0x28, 0x98, 0x40, 0x01, 0x00, 0x00, 0x44, 0x0F, 0x28, 0xA0, 0x50, 0x01, 0x00, 0x00,
												0x44, 0x0F, 0x28, 0xA8, 0x60, 0x01, 0x00, 0x00, 0x44, 0x0F, 0x28, 0xB0, 0x70, 0x01, 0x00, 0x00,
												0x44, 0x0F, 0x28, 0xB8, 0x80, 0x01, 0x00, 0x00, 0x48, 0x8B, 0x00, 0xFF, 0x25, 0x27, 0x00, 0x00,
												0x00, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
												0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
												0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, };
#else
		constexpr static uint8_t s_ShellCode[]{ 0xC4, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0xC8, 0x00, 0x00, 0x00, 0xCC, 0x00, 0x00, 0x00,
												0x50, 0xA1, 0xD4, 0x00, 0x00, 0x00, 0x89, 0x58, 0x04, 0x89, 0x48, 0x08, 0x89, 0x50, 0x0C, 0x89,
												0x70, 0x10, 0x89, 0x78, 0x14, 0x89, 0x68, 0x1C, 0x83, 0xC4, 0x04, 0x89, 0x60, 0x18, 0x83, 0xEC,
												0x04, 0x53, 0x9C, 0x5B, 0x89, 0x58, 0x20, 0x5B, 0x0F, 0x29, 0x40, 0x30, 0x0F, 0x29, 0x48, 0x40,
												0x0F, 0x29, 0x50, 0x50, 0x0F, 0x29, 0x58, 0x60, 0x0F, 0x29, 0x60, 0x70, 0x0F, 0x29, 0xA8, 0x80,
												0x00, 0x00, 0x00, 0x0F, 0x29, 0xB0, 0x90, 0x00, 0x00, 0x00, 0x0F, 0x29, 0xB8, 0xA0, 0x00, 0x00,
												0x00, 0x53, 0x8B, 0x1C, 0x24, 0x89, 0x18, 0x5B, 0x58, 0x83, 0xEC, 0x04, 0x8B, 0x0D, 0xD0, 0x00,
												0x00, 0x00, 0x89, 0x0C, 0x24, 0xFF, 0x15, 0xD8, 0x00, 0x00, 0x00, 0xA1, 0xD4, 0x00, 0x00, 0x00,
												0x8B, 0x58, 0x04, 0x8B, 0x48, 0x08, 0x8B, 0x50, 0x0C, 0x8B, 0x70, 0x10, 0x8B, 0x78, 0x14, 0x8B,
												0x60, 0x18, 0x8B, 0x68, 0x1C, 0x50, 0x8B, 0x80, 0x80, 0x00, 0x00, 0x00, 0x50, 0x9D, 0x58, 0x0F,
												0x29, 0x40, 0x30, 0x0F, 0x29, 0x48, 0x40, 0x0F, 0x29, 0x50, 0x50, 0x0F, 0x29, 0x58, 0x60, 0x0F,
												0x29, 0x60, 0x70, 0x0F, 0x29, 0xA8, 0x80, 0x00, 0x00, 0x00, 0x0F, 0x29, 0xB0, 0x90, 0x00, 0x00,
												0x00, 0x0F, 0x29, 0xB8, 0xA0, 0x00, 0x00, 0x00, 0x8B, 0x00, 0xFF, 0x25, 0xDC, 0x00, 0x00, 0x00,
												0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, };
#endif

	private:
#ifdef _M_X64
		static void DefaultX64DecideArg(Context* pContext, Address* ppArguments, size_t index, bool vectorRegister);

		template <typename CRType, typename... CArgs, size_t... N>
		static void X64LoadArgs(Context* pContext, Address* ppArguments, std::index_sequence<N...>) {

			// If the user has provided a callback we use that, if not we use the fefault callback
			if (m_FnCustomLoadArguments) {
				(m_FnCustomLoadArguments(pContext, ppArguments, N, std::is_floating_point<CArgs>::value), ...);
			}
			else {
				(DefaultX64DecideArg(pContext, ppArguments, N, std::is_floating_point<CArgs>::value), ...);
			}
		}
#else

#endif

		template<typename Ret, typename... Args, size_t... N>
		inline static Ret CallDestination(Address* args, Ret(*fn)(Args...), std::index_sequence<N...>)
		{
			return fn(*(Args*)(args[N].Ptr())...);
		}

		// We call this from our shellcode and then jump to the trampoline
		template <typename CRType, typename... CArgs>
		void __cdecl CallWrapper() {

			// Argument count
			constexpr auto argc = sizeof...(CArgs);

			// Put the pointers to the arguments inside the array
#ifdef _M_X64
			X64LoadArgs<CRType, CArgs...>(&m_Context, m_ppArguments, std::make_index_sequence<argc> {});
#else
#endif

			if (m_FnPreCallCallback) {
				m_FnPreCallCallback(this, m_ppArguments, argc);
			}

			if constexpr (std::is_same_v<CRType, void>) {
				CallDestination(m_ppArguments, m_Destination.As<CRType(*)(CArgs...)>(), std::make_index_sequence<argc> {});
			}
			else {
				m_pReturnValue.To<CRType>() = CallDestination(m_ppArguments, m_Destination.As<CRType(*)(CArgs...)>(), std::make_index_sequence<argc> {});
			}

			if (m_FnPostCallCallback) {
				m_FnPostCallCallback(this, m_pReturnValue);
			}
		}
	};

	class MidFunctionHook {
	public:
		template <typename CRType, typename... CArgs>
		MidFunctionHook(Address target, CRType(*destination)(CArgs...), std::string_view name = "Unnamed")
			: m_Target(target), m_Destination(destination), m_Name(name)
		{
			m_Code = std::make_unique<MidHookCodeBlock>(destination, nullptr, m_Target, 16);

			Initialize();
		}

		virtual ~MidFunctionHook();

	private:
		void Initialize();

	public:

		//************************************
		// Method:    GetName
		// FullName:  RHook::MidFunctionHook::GetName
		// Access:    public 
		// Returns:   const auto&
		// Qualifier: const
		// Caption:   Returns the name of the hook
		//************************************
		const auto& GetName() const {
			return m_Name;
		}

		//************************************
		// Method:    GetTarget
		// FullName:  RHook::MidFunctionHook::GetTarget
		// Access:    public 
		// Returns:   const T& - Templated, the type for the target which is the original type of the function we hooked
		// Qualifier: const
		// Caption:   Returns the address of where the detour should be placed
		//************************************
		template <typename T>
		const T& GetTarget() const {
			if constexpr (std::is_same_v<T, Address>) {
				return m_Target;
			}
			else {
				return m_Target.As<T>();
			}
		}

		//************************************
		// Method:    GetDestination
		// FullName:  RHook::MidFunctionHook::GetDestination
		// Access:    public 
		// Returns:   const T& - Templated, the type for the destination which is the original type of the destination we passed the function pointer
		// Qualifier: const
		// Caption:   Returns the address of the code the detour wouldl jump to
		//************************************
		template <typename T>
		const T& GetDestination() const {
			if constexpr (std::is_same_v<T, Address>) {
				return m_Destination;
			}
			else {
				return m_Destination.As<T>();
			}
		}

		//************************************
		// Method:    GetTrampoline
		// FullName:  RHook::MidFunctionHook::GetTrampoline
		// Access:    public 
		// Returns:   const T& - Template, "Address" by default, the type for the trampoline which is the original type of the function we hooked
		// Qualifier: const
		// Caption:   Returns the address of the trampoline
		//************************************
		template <typename T = Address>
		const T& GetTrampoline() const {
			if constexpr (std::is_same_v<T, Address>) {
				return m_Trampoline;
			}
			else {
				return m_Trampoline.As<T>();
			}
		}

		//************************************
		// Method:    SetName
		// FullName:  RHook::MidFunctionHook::SetName
		// Access:    public 
		// Returns:   void
		// Qualifier:
		// Parameter: const std::string & newName
		// Caption:   Sets the name of the detour
		//************************************
		void SetName(const std::string& newName) {
			m_Name = newName;
		}

		//************************************
		// Method:    IsValid
		// FullName:  RHook::MidFunctionHook::IsValid
		// Access:    public 
		// Returns:   bool
		// Qualifier: const
		// Caption:   Returns true if hook is valid
		//************************************
		bool IsValid() const { return m_Trampoline != nullptr && m_Code->IsReadyToExecute(); }

		//************************************
		// Method:    IsEnabled
		// FullName:  RHook::MidFunctionHook::IsEnabled
		// Access:    public 
		// Returns:   const bool&
		// Qualifier: const
		// Caption:   Returns a bool that indicates the state of the detour whether if the detour is in place (true) or not (false)
		//************************************
		const bool& IsEnabled() const { return m_IsEnabled; }

		//************************************
		// Method:    Hook
		// FullName:  RHook::MidFunctionHook::Hook
		// Access:    public 
		// Returns:   bool
		// Qualifier:
		// Caption:   Places the detour in place, returns true if succeeded and fale if failed
		//************************************
		bool Hook();

		//************************************
		// Method:    Create
		// FullName:  RHook::MidFunctionHook::Create
		// Access:    public 
		// Returns:   bool
		// Qualifier:
		// Caption:   Adds the detour to the list but doesn't place the detour in place, returns true if succeeded and false if failed
		//************************************
		bool Create();

		//************************************
		// Method:    Unhook
		// FullName:  RHook::MidFunctionHook::Unhook
		// Access:    public 
		// Returns:   bool
		// Qualifier:
		// Caption:   Disables the detour, returns true if succeeded and false if failed
		//************************************
		bool Unhook();

		//************************************
		// Method:    Toggle
		// FullName:  RHook::MidFunctionHook::Toggle
		// Access:    public 
		// Returns:   bool
		// Qualifier:
		// Caption:   Calls Hook() if the detour is not in place (Is disabled) or calls Unhook() if the detour is already in place (Is enabled), returns the current state of the hook after enabling (true) or disabling (false) it
		//************************************
		bool Toggle();

		//************************************
		// Method:    Toggle
		// FullName:  RHook::MidFunctionHook::Toggle
		// Access:    public 
		// Returns:   bool
		// Qualifier:
		// Parameter: bool state
		// Caption:   Takes a bool and enables (true) or disables (false) the detour based on that, returns the current state of the hook after enabling (true) or disabling (false) it
		//************************************
		bool Toggle(bool state);

		//************************************
		// Method:    SetPreHookEnableCallback
		// FullName:  RHook::MidFunctionHook::SetPreHookEnableCallback
		// Access:    public 
		// Returns:   void
		// Qualifier:
		// Parameter: const std::function<void(MidFunctionHook*)>& cb - Callback
		// Parameter: MidFunctionHook* pThis - Pointer to the current MidFunctionHook object
		// Caption:   Set a callback that will be called before the detour is placed
		//************************************
		void SetPreHookEnableCallback(const std::function<void(MidFunctionHook* pThis)>& cb) { m_PreHookEnableCallback = cb; }

		//************************************
		// Method:    SetPostHookEnableCallback
		// FullName:  RHook::MidFunctionHook::SetPostHookEnableCallback
		// Access:    public 
		// Returns:   void
		// Qualifier:
		// Parameter: const std::function<void(MidFunctionHook*)>& cb - Callback
		// Parameter: MidFunctionHook* pThis - Pointer to the current MidFunctionHook object
		// Caption:   Set a callback that will be called after the detour is placed
		//************************************
		void SetPostHookEnableCallback(const std::function<void(MidFunctionHook* pThis)>& cb) { m_PostHookEnableCallback = cb; }

		//************************************
		// Method:    SetPreHookDisableCallback
		// FullName:  RHook::MidFunctionHook::SetPreHookDisableCallback
		// Access:    public 
		// Returns:   void
		// Qualifier:
		// Parameter: const std::function<void(MidFunctionHook*)>& cb - Callback
		// Parameter: MidFunctionHook* pThis - Pointer to the current MidFunctionHook object
		// Caption:   Set a callback that will be called before the detour is removed
		//************************************
		void SetPreHookDisableCallback(const std::function<void(MidFunctionHook* pThis)>& cb) { m_PreHookDisableCallback = cb; }

		//************************************
		// Method:    SetPostHookDisableCallback
		// FullName:  RHook::MidFunctionHook::SetPostHookDisableCallback
		// Access:    public 
		// Returns:   void
		// Qualifier:
		// Parameter: const std::function<void(MidFunctionHook*)>& cb - Callback
		// Parameter: MidFunctionHook* pThis - Pointer to the current MidFunctionHook object
		// Caption:   Set a callback that will be called after the detour is removed
		//************************************
		void SetPostHookDisableCallback(const std::function<void(MidFunctionHook* pThis)>& cb) { m_PostHookDisableCallback = cb; }
	
	private:
		std::unique_ptr<MidHookCodeBlock> m_Code{}; // The shellcode that is allocated
		std::recursive_mutex m_HookMutex{};
		bool m_IsEnabled{ false };

		std::function<void(MidFunctionHook* pThis)> m_PreHookEnableCallback{}, m_PostHookEnableCallback{},
			m_PreHookDisableCallback{}, m_PostHookDisableCallback{};

		Address m_Target{ nullptr }; // Address of the target code
		Address m_Destination{ nullptr }; // Address of the code to detour to
		Address m_Trampoline{ nullptr }; // Address of the trampoline

		std::string m_Name{};
	};
}