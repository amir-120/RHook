#pragma once

#include <d3d11_4.h>

namespace D3D11MethodParameters
{
	class IUnknown
	{
	public:
		//Virtual
		struct QueryInterface
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IUnknown* pThis;
			const ::IID& riid;
			void** ppvObject;
		};

		//Virtual
		struct AddRef
		{
			using ReturnType_t = ::ULONG;
			static constexpr size_t Argc = 1;

			::IUnknown* pThis;
		};

		//Virtual
		struct Release
		{
			using ReturnType_t = ::ULONG;
			static constexpr size_t Argc = 1;

			::IUnknown* pThis;
		};

	private:
		 virtual ~IUnknown() = 0;
	};

	class ID3DInclude
	{
	public:
		//Virtual
		struct Open
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::ID3DInclude* pThis;
			::D3D_INCLUDE_TYPE IncludeType;
			::LPCSTR pFileName;
			::LPCVOID pParentData;
			::LPCVOID* ppData;
			::UINT* pBytes;
		};

		//Virtual
		struct Close
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3DInclude* pThis;
			::LPCVOID pData;
		};

	private:
		 virtual ~ID3DInclude() = 0;
	};

	class ID3D10EffectType
	{
	public:
		//Virtual
		struct IsValid
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 1;

			::ID3D10EffectType* pThis;
		};

		//Virtual
		struct GetDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectType* pThis;
			::D3D10_EFFECT_TYPE_DESC* pDesc;
		};

		//Virtual
		struct GetMemberTypeByIndex
		{
			using ReturnType_t = ::ID3D10EffectType*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectType* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetMemberTypeByName
		{
			using ReturnType_t = ::ID3D10EffectType*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectType* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetMemberTypeBySemantic
		{
			using ReturnType_t = ::ID3D10EffectType*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectType* pThis;
			::LPCSTR Semantic;
		};

		//Virtual
		struct GetMemberName
		{
			using ReturnType_t = ::LPCSTR;
			static constexpr size_t Argc = 2;

			::ID3D10EffectType* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetMemberSemantic
		{
			using ReturnType_t = ::LPCSTR;
			static constexpr size_t Argc = 2;

			::ID3D10EffectType* pThis;
			::UINT Index;
		};

	private:
		 virtual ~ID3D10EffectType() = 0;
	};

	class ID3D10EffectVariable
	{
	public:
		//Virtual
		struct IsValid
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVariable* pThis;
		};

		//Virtual
		struct GetType
		{
			using ReturnType_t = ::ID3D10EffectType*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVariable* pThis;
		};

		//Virtual
		struct GetDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectVariable* pThis;
			::D3D10_EFFECT_VARIABLE_DESC* pDesc;
		};

		//Virtual
		struct GetAnnotationByIndex
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetAnnotationByName
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectVariable* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetMemberByIndex
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetMemberByName
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectVariable* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetMemberBySemantic
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectVariable* pThis;
			::LPCSTR Semantic;
		};

		//Virtual
		struct GetElement
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetParentConstantBuffer
		{
			using ReturnType_t = ::ID3D10EffectConstantBuffer*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVariable* pThis;
		};

		//Virtual
		struct AsScalar
		{
			using ReturnType_t = ::ID3D10EffectScalarVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVariable* pThis;
		};

		//Virtual
		struct AsVector
		{
			using ReturnType_t = ::ID3D10EffectVectorVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVariable* pThis;
		};

		//Virtual
		struct AsMatrix
		{
			using ReturnType_t = ::ID3D10EffectMatrixVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVariable* pThis;
		};

		//Virtual
		struct AsString
		{
			using ReturnType_t = ::ID3D10EffectStringVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVariable* pThis;
		};

		//Virtual
		struct AsShaderResource
		{
			using ReturnType_t = ::ID3D10EffectShaderResourceVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVariable* pThis;
		};

		//Virtual
		struct AsRenderTargetView
		{
			using ReturnType_t = ::ID3D10EffectRenderTargetViewVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVariable* pThis;
		};

		//Virtual
		struct AsDepthStencilView
		{
			using ReturnType_t = ::ID3D10EffectDepthStencilViewVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVariable* pThis;
		};

		//Virtual
		struct AsConstantBuffer
		{
			using ReturnType_t = ::ID3D10EffectConstantBuffer*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVariable* pThis;
		};

		//Virtual
		struct AsShader
		{
			using ReturnType_t = ::ID3D10EffectShaderVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVariable* pThis;
		};

		//Virtual
		struct AsBlend
		{
			using ReturnType_t = ::ID3D10EffectBlendVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVariable* pThis;
		};

		//Virtual
		struct AsDepthStencil
		{
			using ReturnType_t = ::ID3D10EffectDepthStencilVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVariable* pThis;
		};

		//Virtual
		struct AsRasterizer
		{
			using ReturnType_t = ::ID3D10EffectRasterizerVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVariable* pThis;
		};

		//Virtual
		struct AsSampler
		{
			using ReturnType_t = ::ID3D10EffectSamplerVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVariable* pThis;
		};

		//Virtual
		struct SetRawValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectVariable* pThis;
			void* pData;
			::UINT Offset;
			::UINT ByteCount;
		};

		//Virtual
		struct GetRawValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectVariable* pThis;
			void* pData;
			::UINT Offset;
			::UINT ByteCount;
		};

	private:
		 virtual ~ID3D10EffectVariable() = 0;
	};

	class ID3D10EffectPass
	{
	public:
		//Virtual
		struct IsValid
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 1;

			::ID3D10EffectPass* pThis;
		};

		//Virtual
		struct GetDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectPass* pThis;
			::D3D10_PASS_DESC* pDesc;
		};

		//Virtual
		struct GetVertexShaderDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectPass* pThis;
			::D3D10_PASS_SHADER_DESC* pDesc;
		};

		//Virtual
		struct GetGeometryShaderDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectPass* pThis;
			::D3D10_PASS_SHADER_DESC* pDesc;
		};

		//Virtual
		struct GetPixelShaderDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectPass* pThis;
			::D3D10_PASS_SHADER_DESC* pDesc;
		};

		//Virtual
		struct GetAnnotationByIndex
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectPass* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetAnnotationByName
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectPass* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct Apply
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectPass* pThis;
			::UINT Flags;
		};

		//Virtual
		struct ComputeStateBlockMask
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectPass* pThis;
			::D3D10_STATE_BLOCK_MASK* pStateBlockMask;
		};

	private:
		 virtual ~ID3D10EffectPass() = 0;
	};

	class ID3D10EffectTechnique
	{
	public:
		//Virtual
		struct IsValid
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 1;

			::ID3D10EffectTechnique* pThis;
		};

		//Virtual
		struct GetDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectTechnique* pThis;
			::D3D10_TECHNIQUE_DESC* pDesc;
		};

		//Virtual
		struct GetAnnotationByIndex
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectTechnique* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetAnnotationByName
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectTechnique* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetPassByIndex
		{
			using ReturnType_t = ::ID3D10EffectPass*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectTechnique* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetPassByName
		{
			using ReturnType_t = ::ID3D10EffectPass*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectTechnique* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct ComputeStateBlockMask
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectTechnique* pThis;
			::D3D10_STATE_BLOCK_MASK* pStateBlockMask;
		};

	private:
		 virtual ~ID3D10EffectTechnique() = 0;
	};

	class AsyncIUnknown : IUnknown
	{
	public:
		//Virtual
		struct Begin_QueryInterface
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::AsyncIUnknown* pThis;
			const ::IID& riid;
		};

		//Virtual
		struct Finish_QueryInterface
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::AsyncIUnknown* pThis;
			void** ppvObject;
		};

		//Virtual
		struct Begin_AddRef
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::AsyncIUnknown* pThis;
		};

		//Virtual
		struct Finish_AddRef
		{
			using ReturnType_t = ::ULONG;
			static constexpr size_t Argc = 1;

			::AsyncIUnknown* pThis;
		};

		//Virtual
		struct Begin_Release
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::AsyncIUnknown* pThis;
		};

		//Virtual
		struct Finish_Release
		{
			using ReturnType_t = ::ULONG;
			static constexpr size_t Argc = 1;

			::AsyncIUnknown* pThis;
		};

	private:
		 virtual ~AsyncIUnknown() = 0;
	};

	class IClassFactory : IUnknown
	{
	public:
		//Virtual
		struct CreateInstance
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IClassFactory* pThis;
			::IUnknown* pUnkOuter;
			const ::IID& riid;
			void** ppvObject;
		};

		//Virtual
		struct LockServer
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IClassFactory* pThis;
			::BOOL fLock;
		};

	private:
		 virtual ~IClassFactory() = 0;
	};

	class IMarshal : IUnknown
	{
	public:
		//Virtual
		struct GetUnmarshalClass
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 7;

			::IMarshal* pThis;
			const ::IID& riid;
			void* pv;
			::DWORD dwDestContext;
			void* pvDestContext;
			::DWORD mshlflags;
			::CLSID* pCid;
		};

		//Virtual
		struct GetMarshalSizeMax
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 7;

			::IMarshal* pThis;
			const ::IID& riid;
			void* pv;
			::DWORD dwDestContext;
			void* pvDestContext;
			::DWORD mshlflags;
			::DWORD* pSize;
		};

		//Virtual
		struct MarshalInterface
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 7;

			::IMarshal* pThis;
			::IStream* pStm;
			const ::IID& riid;
			void* pv;
			::DWORD dwDestContext;
			void* pvDestContext;
			::DWORD mshlflags;
		};

		//Virtual
		struct UnmarshalInterface
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IMarshal* pThis;
			::IStream* pStm;
			const ::IID& riid;
			void** ppv;
		};

		//Virtual
		struct ReleaseMarshalData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IMarshal* pThis;
			::IStream* pStm;
		};

		//Virtual
		struct DisconnectObject
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IMarshal* pThis;
			::DWORD dwReserved;
		};

	private:
		 virtual ~IMarshal() = 0;
	};

	class IActivationFilter : IUnknown
	{
	public:
		//Virtual
		struct HandleActivation
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IActivationFilter* pThis;
			::DWORD dwActivationType;
			const ::IID& rclsid;
			::CLSID* pReplacementClsId;
		};

	private:
		 virtual ~IActivationFilter() = 0;
	};

	class IMalloc : IUnknown
	{
	public:
		//Virtual
		struct Alloc
		{
			using ReturnType_t = void*;
			static constexpr size_t Argc = 2;

			::IMalloc* pThis;
			::SIZE_T cb;
		};

		//Virtual
		struct Realloc
		{
			using ReturnType_t = void*;
			static constexpr size_t Argc = 3;

			::IMalloc* pThis;
			void* pv;
			::SIZE_T cb;
		};

		//Virtual
		struct Free
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::IMalloc* pThis;
			void* pv;
		};

		//Virtual
		struct GetSize
		{
			using ReturnType_t = ::SIZE_T;
			static constexpr size_t Argc = 2;

			::IMalloc* pThis;
			void* pv;
		};

		//Virtual
		struct DidAlloc
		{
			using ReturnType_t = int;
			static constexpr size_t Argc = 2;

			::IMalloc* pThis;
			void* pv;
		};

		//Virtual
		struct HeapMinimize
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::IMalloc* pThis;
		};

	private:
		 virtual ~IMalloc() = 0;
	};

	class IStdMarshalInfo : IUnknown
	{
	public:
		//Virtual
		struct GetClassForHandler
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IStdMarshalInfo* pThis;
			::DWORD dwDestContext;
			void* pvDestContext;
			::CLSID* pClsid;
		};

	private:
		 virtual ~IStdMarshalInfo() = 0;
	};

	class IExternalConnection : IUnknown
	{
	public:
		//Virtual
		struct AddConnection
		{
			using ReturnType_t = ::DWORD;
			static constexpr size_t Argc = 3;

			::IExternalConnection* pThis;
			::DWORD extconn;
			::DWORD reserved;
		};

		//Virtual
		struct ReleaseConnection
		{
			using ReturnType_t = ::DWORD;
			static constexpr size_t Argc = 4;

			::IExternalConnection* pThis;
			::DWORD extconn;
			::DWORD reserved;
			::BOOL fLastReleaseCloses;
		};

	private:
		 virtual ~IExternalConnection() = 0;
	};

	class IMultiQI : IUnknown
	{
	public:
		//Virtual
		struct QueryMultipleInterfaces
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IMultiQI* pThis;
			::ULONG cMQIs;
			::MULTI_QI* pMQIs;
		};

	private:
		 virtual ~IMultiQI() = 0;
	};

	class AsyncIMultiQI : IUnknown
	{
	public:
		//Virtual
		struct Begin_QueryMultipleInterfaces
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::AsyncIMultiQI* pThis;
			::ULONG cMQIs;
			::MULTI_QI* pMQIs;
		};

		//Virtual
		struct Finish_QueryMultipleInterfaces
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::AsyncIMultiQI* pThis;
			::MULTI_QI* pMQIs;
		};

	private:
		 virtual ~AsyncIMultiQI() = 0;
	};

	class IInternalUnknown : IUnknown
	{
	public:
		//Virtual
		struct QueryInternalInterface
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IInternalUnknown* pThis;
			const ::IID& riid;
			void** ppv;
		};

	private:
		 virtual ~IInternalUnknown() = 0;
	};

	class IEnumUnknown : IUnknown
	{
	public:
		//Virtual
		struct Next
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IEnumUnknown* pThis;
			::ULONG celt;
			::IUnknown** rgelt;
			::ULONG* pceltFetched;
		};

		//Virtual
		struct Skip
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IEnumUnknown* pThis;
			::ULONG celt;
		};

		//Virtual
		struct Reset
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IEnumUnknown* pThis;
		};

		//Virtual
		struct Clone
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IEnumUnknown* pThis;
			::IEnumUnknown** ppenum;
		};

	private:
		 virtual ~IEnumUnknown() = 0;
	};

	class IEnumString : IUnknown
	{
	public:
		//Virtual
		struct Next
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IEnumString* pThis;
			::ULONG celt;
			::LPOLESTR* rgelt;
			::ULONG* pceltFetched;
		};

		//Virtual
		struct Skip
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IEnumString* pThis;
			::ULONG celt;
		};

		//Virtual
		struct Reset
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IEnumString* pThis;
		};

		//Virtual
		struct Clone
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IEnumString* pThis;
			::IEnumString** ppenum;
		};

	private:
		 virtual ~IEnumString() = 0;
	};

	class ISequentialStream : IUnknown
	{
	public:
		//Virtual
		struct Read
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ISequentialStream* pThis;
			void* pv;
			::ULONG cb;
			::ULONG* pcbRead;
		};

		//Virtual
		struct Write
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ISequentialStream* pThis;
			const void* pv;
			::ULONG cb;
			::ULONG* pcbWritten;
		};

	private:
		 virtual ~ISequentialStream() = 0;
	};

	class IStream : ISequentialStream
	{
	public:
		//Virtual
		struct Seek
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IStream* pThis;
			::LARGE_INTEGER dlibMove;
			::DWORD dwOrigin;
			::ULARGE_INTEGER* plibNewPosition;
		};

		//Virtual
		struct SetSize
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IStream* pThis;
			::ULARGE_INTEGER libNewSize;
		};

		//Virtual
		struct CopyTo
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IStream* pThis;
			::IStream* pstm;
			::ULARGE_INTEGER cb;
			::ULARGE_INTEGER* pcbRead;
			::ULARGE_INTEGER* pcbWritten;
		};

		//Virtual
		struct Commit
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IStream* pThis;
			::DWORD grfCommitFlags;
		};

		//Virtual
		struct Revert
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IStream* pThis;
		};

		//Virtual
		struct LockRegion
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IStream* pThis;
			::ULARGE_INTEGER libOffset;
			::ULARGE_INTEGER cb;
			::DWORD dwLockType;
		};

		//Virtual
		struct UnlockRegion
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IStream* pThis;
			::ULARGE_INTEGER libOffset;
			::ULARGE_INTEGER cb;
			::DWORD dwLockType;
		};

		//Virtual
		struct Stat
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IStream* pThis;
			::STATSTG* pstatstg;
			::DWORD grfStatFlag;
		};

		//Virtual
		struct Clone
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IStream* pThis;
			::IStream** ppstm;
		};

	private:
		 virtual ~IStream() = 0;
	};

	class IRpcChannelBuffer : IUnknown
	{
	public:
		//Virtual
		struct GetBuffer
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IRpcChannelBuffer* pThis;
			::RPCOLEMESSAGE* pMessage;
			const ::IID& riid;
		};

		//Virtual
		struct SendReceive
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IRpcChannelBuffer* pThis;
			::RPCOLEMESSAGE* pMessage;
			::ULONG* pStatus;
		};

		//Virtual
		struct FreeBuffer
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IRpcChannelBuffer* pThis;
			::RPCOLEMESSAGE* pMessage;
		};

		//Virtual
		struct GetDestCtx
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IRpcChannelBuffer* pThis;
			::DWORD* pdwDestContext;
			void** ppvDestContext;
		};

		//Virtual
		struct IsConnected
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IRpcChannelBuffer* pThis;
		};

	private:
		 virtual ~IRpcChannelBuffer() = 0;
	};

	class IRpcChannelBuffer2 : IRpcChannelBuffer
	{
	public:
		//Virtual
		struct GetProtocolVersion
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IRpcChannelBuffer2* pThis;
			::DWORD* pdwVersion;
		};

	private:
		 virtual ~IRpcChannelBuffer2() = 0;
	};

	class IAsyncRpcChannelBuffer : IRpcChannelBuffer2
	{
	public:
		//Virtual
		struct Send
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IAsyncRpcChannelBuffer* pThis;
			::RPCOLEMESSAGE* pMsg;
			::ISynchronize* pSync;
			::ULONG* pulStatus;
		};

		//Virtual
		struct Receive
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IAsyncRpcChannelBuffer* pThis;
			::RPCOLEMESSAGE* pMsg;
			::ULONG* pulStatus;
		};

		//Virtual
		struct GetDestCtxEx
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IAsyncRpcChannelBuffer* pThis;
			::RPCOLEMESSAGE* pMsg;
			::DWORD* pdwDestContext;
			void** ppvDestContext;
		};

	private:
		 virtual ~IAsyncRpcChannelBuffer() = 0;
	};

	class IRpcChannelBuffer3 : IRpcChannelBuffer2
	{
	public:
		//Virtual
		struct Send
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IRpcChannelBuffer3* pThis;
			::RPCOLEMESSAGE* pMsg;
			::ULONG* pulStatus;
		};

		//Virtual
		struct Receive
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IRpcChannelBuffer3* pThis;
			::RPCOLEMESSAGE* pMsg;
			::ULONG ulSize;
			::ULONG* pulStatus;
		};

		//Virtual
		struct Cancel
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IRpcChannelBuffer3* pThis;
			::RPCOLEMESSAGE* pMsg;
		};

		//Virtual
		struct GetCallContext
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IRpcChannelBuffer3* pThis;
			::RPCOLEMESSAGE* pMsg;
			const ::IID& riid;
			void** pInterface;
		};

		//Virtual
		struct GetDestCtxEx
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IRpcChannelBuffer3* pThis;
			::RPCOLEMESSAGE* pMsg;
			::DWORD* pdwDestContext;
			void** ppvDestContext;
		};

		//Virtual
		struct GetState
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IRpcChannelBuffer3* pThis;
			::RPCOLEMESSAGE* pMsg;
			::DWORD* pState;
		};

		//Virtual
		struct RegisterAsync
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IRpcChannelBuffer3* pThis;
			::RPCOLEMESSAGE* pMsg;
			::IAsyncManager* pAsyncMgr;
		};

	private:
		 virtual ~IRpcChannelBuffer3() = 0;
	};

	class IRpcSyntaxNegotiate : IUnknown
	{
	public:
		//Virtual
		struct NegotiateSyntax
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IRpcSyntaxNegotiate* pThis;
			::RPCOLEMESSAGE* pMsg;
		};

	private:
		 virtual ~IRpcSyntaxNegotiate() = 0;
	};

	class IRpcProxyBuffer : IUnknown
	{
	public:
		//Virtual
		struct Connect
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IRpcProxyBuffer* pThis;
			::IRpcChannelBuffer* pRpcChannelBuffer;
		};

		//Virtual
		struct Disconnect
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::IRpcProxyBuffer* pThis;
		};

	private:
		 virtual ~IRpcProxyBuffer() = 0;
	};

	class IRpcStubBuffer : IUnknown
	{
	public:
		//Virtual
		struct Connect
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IRpcStubBuffer* pThis;
			::IUnknown* pUnkServer;
		};

		//Virtual
		struct Disconnect
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::IRpcStubBuffer* pThis;
		};

		//Virtual
		struct Invoke
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IRpcStubBuffer* pThis;
			::RPCOLEMESSAGE* _prpcmsg;
			::IRpcChannelBuffer* _pRpcChannelBuffer;
		};

		//Virtual
		struct IsIIDSupported
		{
			using ReturnType_t = ::IRpcStubBuffer*;
			static constexpr size_t Argc = 2;

			::IRpcStubBuffer* pThis;
			const ::IID& riid;
		};

		//Virtual
		struct CountRefs
		{
			using ReturnType_t = ::ULONG;
			static constexpr size_t Argc = 1;

			::IRpcStubBuffer* pThis;
		};

		//Virtual
		struct DebugServerQueryInterface
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IRpcStubBuffer* pThis;
			void** ppv;
		};

		//Virtual
		struct DebugServerRelease
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::IRpcStubBuffer* pThis;
			void* pv;
		};

	private:
		 virtual ~IRpcStubBuffer() = 0;
	};

	class IPSFactoryBuffer : IUnknown
	{
	public:
		//Virtual
		struct CreateProxy
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IPSFactoryBuffer* pThis;
			::IUnknown* pUnkOuter;
			const ::IID& riid;
			::IRpcProxyBuffer** ppProxy;
			void** ppv;
		};

		//Virtual
		struct CreateStub
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IPSFactoryBuffer* pThis;
			const ::IID& riid;
			::IUnknown* pUnkServer;
			::IRpcStubBuffer** ppStub;
		};

	private:
		 virtual ~IPSFactoryBuffer() = 0;
	};

	class IChannelHook : IUnknown
	{
	public:
		//Virtual
		struct ClientGetSize
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::IChannelHook* pThis;
			const ::GUID& uExtent;
			const ::IID& riid;
			::ULONG* pDataSize;
		};

		//Virtual
		struct ClientFillBuffer
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 5;

			::IChannelHook* pThis;
			const ::GUID& uExtent;
			const ::IID& riid;
			::ULONG* pDataSize;
			void* pDataBuffer;
		};

		//Virtual
		struct ClientNotify
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 7;

			::IChannelHook* pThis;
			const ::GUID& uExtent;
			const ::IID& riid;
			::ULONG cbDataSize;
			void* pDataBuffer;
			::DWORD lDataRep;
			::HRESULT hrFault;
		};

		//Virtual
		struct ServerNotify
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::IChannelHook* pThis;
			const ::GUID& uExtent;
			const ::IID& riid;
			::ULONG cbDataSize;
			void* pDataBuffer;
			::DWORD lDataRep;
		};

		//Virtual
		struct ServerGetSize
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 5;

			::IChannelHook* pThis;
			const ::GUID& uExtent;
			const ::IID& riid;
			::HRESULT hrFault;
			::ULONG* pDataSize;
		};

		//Virtual
		struct ServerFillBuffer
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::IChannelHook* pThis;
			const ::GUID& uExtent;
			const ::IID& riid;
			::ULONG* pDataSize;
			void* pDataBuffer;
			::HRESULT hrFault;
		};

	private:
		 virtual ~IChannelHook() = 0;
	};

	class IClientSecurity : IUnknown
	{
	public:
		//Virtual
		struct QueryBlanket
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 9;

			::IClientSecurity* pThis;
			::IUnknown* pProxy;
			::DWORD* pAuthnSvc;
			::DWORD* pAuthzSvc;
			::OLECHAR** pServerPrincName;
			::DWORD* pAuthnLevel;
			::DWORD* pImpLevel;
			void** pAuthInfo;
			::DWORD* pCapabilites;
		};

		//Virtual
		struct SetBlanket
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 9;

			::IClientSecurity* pThis;
			::IUnknown* pProxy;
			::DWORD dwAuthnSvc;
			::DWORD dwAuthzSvc;
			::OLECHAR* pServerPrincName;
			::DWORD dwAuthnLevel;
			::DWORD dwImpLevel;
			void* pAuthInfo;
			::DWORD dwCapabilities;
		};

		//Virtual
		struct CopyProxy
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IClientSecurity* pThis;
			::IUnknown* pProxy;
			::IUnknown** ppCopy;
		};

	private:
		 virtual ~IClientSecurity() = 0;
	};

	class IServerSecurity : IUnknown
	{
	public:
		//Virtual
		struct QueryBlanket
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 8;

			::IServerSecurity* pThis;
			::DWORD* pAuthnSvc;
			::DWORD* pAuthzSvc;
			::OLECHAR** pServerPrincName;
			::DWORD* pAuthnLevel;
			::DWORD* pImpLevel;
			void** pPrivs;
			::DWORD* pCapabilities;
		};

		//Virtual
		struct ImpersonateClient
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IServerSecurity* pThis;
		};

		//Virtual
		struct RevertToSelf
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IServerSecurity* pThis;
		};

		//Virtual
		struct IsImpersonating
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 1;

			::IServerSecurity* pThis;
		};

	private:
		 virtual ~IServerSecurity() = 0;
	};

	class IRpcOptions : IUnknown
	{
	public:
		//Virtual
		struct Set
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IRpcOptions* pThis;
			::IUnknown* pPrx;
			::RPCOPT_PROPERTIES dwProperty;
			::ULONG_PTR dwValue;
		};

		//Virtual
		struct Query
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IRpcOptions* pThis;
			::IUnknown* pPrx;
			::RPCOPT_PROPERTIES dwProperty;
			::ULONG_PTR* pdwValue;
		};

	private:
		 virtual ~IRpcOptions() = 0;
	};

	class IGlobalOptions : IUnknown
	{
	public:
		//Virtual
		struct Set
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IGlobalOptions* pThis;
			::GLOBALOPT_PROPERTIES dwProperty;
			::ULONG_PTR dwValue;
		};

		//Virtual
		struct Query
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IGlobalOptions* pThis;
			::GLOBALOPT_PROPERTIES dwProperty;
			::ULONG_PTR* pdwValue;
		};

	private:
		 virtual ~IGlobalOptions() = 0;
	};

	class ISurrogate : IUnknown
	{
	public:
		//Virtual
		struct LoadDllServer
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ISurrogate* pThis;
			const ::IID& Clsid;
		};

		//Virtual
		struct FreeSurrogate
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ISurrogate* pThis;
		};

	private:
		 virtual ~ISurrogate() = 0;
	};

	class IGlobalInterfaceTable : IUnknown
	{
	public:
		//Virtual
		struct RegisterInterfaceInGlobal
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IGlobalInterfaceTable* pThis;
			::IUnknown* pUnk;
			const ::IID& riid;
			::DWORD* pdwCookie;
		};

		//Virtual
		struct RevokeInterfaceFromGlobal
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IGlobalInterfaceTable* pThis;
			::DWORD dwCookie;
		};

		//Virtual
		struct GetInterfaceFromGlobal
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IGlobalInterfaceTable* pThis;
			::DWORD dwCookie;
			const ::IID& riid;
			void** ppv;
		};

	private:
		 virtual ~IGlobalInterfaceTable() = 0;
	};

	class ISynchronize : IUnknown
	{
	public:
		//Virtual
		struct Wait
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ISynchronize* pThis;
			::DWORD dwFlags;
			::DWORD dwMilliseconds;
		};

		//Virtual
		struct Signal
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ISynchronize* pThis;
		};

		//Virtual
		struct Reset
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ISynchronize* pThis;
		};

	private:
		 virtual ~ISynchronize() = 0;
	};

	class ISynchronizeHandle : IUnknown
	{
	public:
		//Virtual
		struct GetHandle
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ISynchronizeHandle* pThis;
			::HANDLE* ph;
		};

	private:
		 virtual ~ISynchronizeHandle() = 0;
	};

	class ISynchronizeEvent : ISynchronizeHandle
	{
	public:
		//Virtual
		struct SetEventHandle
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ISynchronizeEvent* pThis;
			::HANDLE* ph;
		};

	private:
		 virtual ~ISynchronizeEvent() = 0;
	};

	class ISynchronizeContainer : IUnknown
	{
	public:
		//Virtual
		struct AddSynchronize
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ISynchronizeContainer* pThis;
			::ISynchronize* pSync;
		};

		//Virtual
		struct WaitMultiple
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ISynchronizeContainer* pThis;
			::DWORD dwFlags;
			::DWORD dwTimeOut;
			::ISynchronize** ppSync;
		};

	private:
		 virtual ~ISynchronizeContainer() = 0;
	};

	class ISynchronizeMutex : ISynchronize
	{
	public:
		//Virtual
		struct ReleaseMutex
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ISynchronizeMutex* pThis;
		};

	private:
		 virtual ~ISynchronizeMutex() = 0;
	};

	class ICancelMethodCalls : IUnknown
	{
	public:
		//Virtual
		struct Cancel
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICancelMethodCalls* pThis;
			::ULONG ulSeconds;
		};

		//Virtual
		struct TestCancel
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ICancelMethodCalls* pThis;
		};

	private:
		 virtual ~ICancelMethodCalls() = 0;
	};

	class IAsyncManager : IUnknown
	{
	public:
		//Virtual
		struct CompleteCall
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IAsyncManager* pThis;
			::HRESULT Result;
		};

		//Virtual
		struct GetCallContext
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IAsyncManager* pThis;
			const ::IID& riid;
			void** pInterface;
		};

		//Virtual
		struct GetState
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IAsyncManager* pThis;
			::ULONG* pulStateFlags;
		};

	private:
		 virtual ~IAsyncManager() = 0;
	};

	class ICallFactory : IUnknown
	{
	public:
		//Virtual
		struct CreateCall
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ICallFactory* pThis;
			const ::IID& riid;
			::IUnknown* pCtrlUnk;
			const ::IID& riid2;
			::IUnknown** ppv;
		};

	private:
		 virtual ~ICallFactory() = 0;
	};

	class IRpcHelper : IUnknown
	{
	public:
		//Virtual
		struct GetDCOMProtocolVersion
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IRpcHelper* pThis;
			::DWORD* pComVersion;
		};

		//Virtual
		struct GetIIDFromOBJREF
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IRpcHelper* pThis;
			void* pObjRef;
			::IID** piid;
		};

	private:
		 virtual ~IRpcHelper() = 0;
	};

	class IReleaseMarshalBuffers : IUnknown
	{
	public:
		//Virtual
		struct ReleaseMarshalBuffer
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IReleaseMarshalBuffers* pThis;
			::RPCOLEMESSAGE* pMsg;
			::DWORD dwFlags;
			::IUnknown* pChnl;
		};

	private:
		 virtual ~IReleaseMarshalBuffers() = 0;
	};

	class IWaitMultiple : IUnknown
	{
	public:
		//Virtual
		struct WaitMultiple
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IWaitMultiple* pThis;
			::DWORD timeout;
			::ISynchronize** pSync;
		};

		//Virtual
		struct AddSynchronize
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IWaitMultiple* pThis;
			::ISynchronize* pSync;
		};

	private:
		 virtual ~IWaitMultiple() = 0;
	};

	class IAddrTrackingControl : IUnknown
	{
	public:
		//Virtual
		struct EnableCOMDynamicAddrTracking
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IAddrTrackingControl* pThis;
		};

		//Virtual
		struct DisableCOMDynamicAddrTracking
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IAddrTrackingControl* pThis;
		};

	private:
		 virtual ~IAddrTrackingControl() = 0;
	};

	class IAddrExclusionControl : IUnknown
	{
	public:
		//Virtual
		struct GetCurrentAddrExclusionList
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IAddrExclusionControl* pThis;
			const ::IID& riid;
			void** ppEnumerator;
		};

		//Virtual
		struct UpdateAddrExclusionList
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IAddrExclusionControl* pThis;
			::IUnknown* pEnumerator;
		};

	private:
		 virtual ~IAddrExclusionControl() = 0;
	};

	class IPipeByte : IUnknown
	{
	public:
		//Virtual
		struct Pull
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IPipeByte* pThis;
			::BYTE* buf;
			::ULONG cRequest;
			::ULONG* pcReturned;
		};

		//Virtual
		struct Push
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IPipeByte* pThis;
			::BYTE* buf;
			::ULONG cSent;
		};

	private:
		 virtual ~IPipeByte() = 0;
	};

	class AsyncIPipeByte : IUnknown
	{
	public:
		//Virtual
		struct Begin_Pull
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::AsyncIPipeByte* pThis;
			::ULONG cRequest;
		};

		//Virtual
		struct Finish_Pull
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::AsyncIPipeByte* pThis;
			::BYTE* buf;
			::ULONG* pcReturned;
		};

		//Virtual
		struct Begin_Push
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::AsyncIPipeByte* pThis;
			::BYTE* buf;
			::ULONG cSent;
		};

		//Virtual
		struct Finish_Push
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::AsyncIPipeByte* pThis;
		};

	private:
		 virtual ~AsyncIPipeByte() = 0;
	};

	class IPipeLong : IUnknown
	{
	public:
		//Virtual
		struct Pull
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IPipeLong* pThis;
			::LONG* buf;
			::ULONG cRequest;
			::ULONG* pcReturned;
		};

		//Virtual
		struct Push
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IPipeLong* pThis;
			::LONG* buf;
			::ULONG cSent;
		};

	private:
		 virtual ~IPipeLong() = 0;
	};

	class AsyncIPipeLong : IUnknown
	{
	public:
		//Virtual
		struct Begin_Pull
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::AsyncIPipeLong* pThis;
			::ULONG cRequest;
		};

		//Virtual
		struct Finish_Pull
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::AsyncIPipeLong* pThis;
			::LONG* buf;
			::ULONG* pcReturned;
		};

		//Virtual
		struct Begin_Push
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::AsyncIPipeLong* pThis;
			::LONG* buf;
			::ULONG cSent;
		};

		//Virtual
		struct Finish_Push
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::AsyncIPipeLong* pThis;
		};

	private:
		 virtual ~AsyncIPipeLong() = 0;
	};

	class IPipeDouble : IUnknown
	{
	public:
		//Virtual
		struct Pull
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IPipeDouble* pThis;
			::DOUBLE* buf;
			::ULONG cRequest;
			::ULONG* pcReturned;
		};

		//Virtual
		struct Push
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IPipeDouble* pThis;
			::DOUBLE* buf;
			::ULONG cSent;
		};

	private:
		 virtual ~IPipeDouble() = 0;
	};

	class AsyncIPipeDouble : IUnknown
	{
	public:
		//Virtual
		struct Begin_Pull
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::AsyncIPipeDouble* pThis;
			::ULONG cRequest;
		};

		//Virtual
		struct Finish_Pull
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::AsyncIPipeDouble* pThis;
			::DOUBLE* buf;
			::ULONG* pcReturned;
		};

		//Virtual
		struct Begin_Push
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::AsyncIPipeDouble* pThis;
			::DOUBLE* buf;
			::ULONG cSent;
		};

		//Virtual
		struct Finish_Push
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::AsyncIPipeDouble* pThis;
		};

	private:
		 virtual ~AsyncIPipeDouble() = 0;
	};

	class IComThreadingInfo : IUnknown
	{
	public:
		//Virtual
		struct GetCurrentApartmentType
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IComThreadingInfo* pThis;
			::APTTYPE* pAptType;
		};

		//Virtual
		struct GetCurrentThreadType
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IComThreadingInfo* pThis;
			::THDTYPE* pThreadType;
		};

		//Virtual
		struct GetCurrentLogicalThreadId
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IComThreadingInfo* pThis;
			::GUID* pguidLogicalThreadId;
		};

		//Virtual
		struct SetCurrentLogicalThreadId
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IComThreadingInfo* pThis;
			const ::GUID& rguid;
		};

	private:
		 virtual ~IComThreadingInfo() = 0;
	};

	class IProcessInitControl : IUnknown
	{
	public:
		//Virtual
		struct ResetInitializerTimeout
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IProcessInitControl* pThis;
			::DWORD dwSecondsRemaining;
		};

	private:
		 virtual ~IProcessInitControl() = 0;
	};

	class IMarshalingStream : IStream
	{
	public:
		//Virtual
		struct GetMarshalingContextAttribute
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IMarshalingStream* pThis;
			::CO_MARSHALING_CONTEXT_ATTRIBUTES attribute;
			::ULONG_PTR* pAttributeValue;
		};

	private:
		 virtual ~IMarshalingStream() = 0;
	};

	class IAgileReference : IUnknown
	{
	public:
		//Virtual
		struct Resolve
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IAgileReference* pThis;
			const ::IID& riid;
			void** ppvObjectReference;
		};

	private:
		 virtual ~IAgileReference() = 0;
	};

	class IMachineGlobalObjectTable : IUnknown
	{
	public:
		//Virtual
		struct RegisterObject
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IMachineGlobalObjectTable* pThis;
			const ::IID& clsid;
			::LPCWSTR identifier;
			::IUnknown* object;
			::MachineGlobalObjectTableRegistrationToken* token;
		};

		//Virtual
		struct GetObjectA
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IMachineGlobalObjectTable* pThis;
			const ::IID& clsid;
			::LPCWSTR identifier;
			const ::IID& riid;
			void** ppv;
		};

		//Virtual
		struct RevokeObject
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IMachineGlobalObjectTable* pThis;
			::MachineGlobalObjectTableRegistrationToken token;
		};

	private:
		 virtual ~IMachineGlobalObjectTable() = 0;
	};

	class IMallocSpy : IUnknown
	{
	public:
		//Virtual
		struct PreAlloc
		{
			using ReturnType_t = ::SIZE_T;
			static constexpr size_t Argc = 2;

			::IMallocSpy* pThis;
			::SIZE_T cbRequest;
		};

		//Virtual
		struct PostAlloc
		{
			using ReturnType_t = void*;
			static constexpr size_t Argc = 2;

			::IMallocSpy* pThis;
			void* pActual;
		};

		//Virtual
		struct PreFree
		{
			using ReturnType_t = void*;
			static constexpr size_t Argc = 3;

			::IMallocSpy* pThis;
			void* pRequest;
			::BOOL fSpyed;
		};

		//Virtual
		struct PostFree
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::IMallocSpy* pThis;
			::BOOL fSpyed;
		};

		//Virtual
		struct PreRealloc
		{
			using ReturnType_t = ::SIZE_T;
			static constexpr size_t Argc = 5;

			::IMallocSpy* pThis;
			void* pRequest;
			::SIZE_T cbRequest;
			void** ppNewRequest;
			::BOOL fSpyed;
		};

		//Virtual
		struct PostRealloc
		{
			using ReturnType_t = void*;
			static constexpr size_t Argc = 3;

			::IMallocSpy* pThis;
			void* pActual;
			::BOOL fSpyed;
		};

		//Virtual
		struct PreGetSize
		{
			using ReturnType_t = void*;
			static constexpr size_t Argc = 3;

			::IMallocSpy* pThis;
			void* pRequest;
			::BOOL fSpyed;
		};

		//Virtual
		struct PostGetSize
		{
			using ReturnType_t = ::SIZE_T;
			static constexpr size_t Argc = 3;

			::IMallocSpy* pThis;
			::SIZE_T cbActual;
			::BOOL fSpyed;
		};

		//Virtual
		struct PreDidAlloc
		{
			using ReturnType_t = void*;
			static constexpr size_t Argc = 3;

			::IMallocSpy* pThis;
			void* pRequest;
			::BOOL fSpyed;
		};

		//Virtual
		struct PostDidAlloc
		{
			using ReturnType_t = int;
			static constexpr size_t Argc = 4;

			::IMallocSpy* pThis;
			void* pRequest;
			::BOOL fSpyed;
			int fActual;
		};

		//Virtual
		struct PreHeapMinimize
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::IMallocSpy* pThis;
		};

		//Virtual
		struct PostHeapMinimize
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::IMallocSpy* pThis;
		};

	private:
		 virtual ~IMallocSpy() = 0;
	};

	class IBindCtx : IUnknown
	{
	public:
		//Virtual
		struct RegisterObjectBound
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IBindCtx* pThis;
			::IUnknown* punk;
		};

		//Virtual
		struct RevokeObjectBound
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IBindCtx* pThis;
			::IUnknown* punk;
		};

		//Virtual
		struct ReleaseBoundObjects
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IBindCtx* pThis;
		};

		//Virtual
		struct SetBindOptions
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IBindCtx* pThis;
			::BIND_OPTS* pbindopts;
		};

		//Virtual
		struct GetBindOptions
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IBindCtx* pThis;
			::BIND_OPTS* pbindopts;
		};

		//Virtual
		struct GetRunningObjectTable
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IBindCtx* pThis;
			::IRunningObjectTable** pprot;
		};

		//Virtual
		struct RegisterObjectParam
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IBindCtx* pThis;
			::LPOLESTR pszKey;
			::IUnknown* punk;
		};

		//Virtual
		struct GetObjectParam
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IBindCtx* pThis;
			::LPOLESTR pszKey;
			::IUnknown** ppunk;
		};

		//Virtual
		struct EnumObjectParam
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IBindCtx* pThis;
			::IEnumString** ppenum;
		};

		//Virtual
		struct RevokeObjectParam
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IBindCtx* pThis;
			::LPOLESTR pszKey;
		};

	private:
		 virtual ~IBindCtx() = 0;
	};

	class IEnumMoniker : IUnknown
	{
	public:
		//Virtual
		struct Next
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IEnumMoniker* pThis;
			::ULONG celt;
			::IMoniker** rgelt;
			::ULONG* pceltFetched;
		};

		//Virtual
		struct Skip
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IEnumMoniker* pThis;
			::ULONG celt;
		};

		//Virtual
		struct Reset
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IEnumMoniker* pThis;
		};

		//Virtual
		struct Clone
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IEnumMoniker* pThis;
			::IEnumMoniker** ppenum;
		};

	private:
		 virtual ~IEnumMoniker() = 0;
	};

	class IRunnableObject : IUnknown
	{
	public:
		//Virtual
		struct GetRunningClass
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IRunnableObject* pThis;
			::LPCLSID lpClsid;
		};

		//Virtual
		struct Run
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IRunnableObject* pThis;
			::LPBINDCTX pbc;
		};

		//Virtual
		struct IsRunning
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 1;

			::IRunnableObject* pThis;
		};

		//Virtual
		struct LockRunning
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IRunnableObject* pThis;
			::BOOL fLock;
			::BOOL fLastUnlockCloses;
		};

		//Virtual
		struct SetContainedObject
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IRunnableObject* pThis;
			::BOOL fContained;
		};

	private:
		 virtual ~IRunnableObject() = 0;
	};

	class IRunningObjectTable : IUnknown
	{
	public:
		//Virtual
		struct Register
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IRunningObjectTable* pThis;
			::DWORD grfFlags;
			::IUnknown* punkObject;
			::IMoniker* pmkObjectName;
			::DWORD* pdwRegister;
		};

		//Virtual
		struct Revoke
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IRunningObjectTable* pThis;
			::DWORD dwRegister;
		};

		//Virtual
		struct IsRunning
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IRunningObjectTable* pThis;
			::IMoniker* pmkObjectName;
		};

		//Virtual
		struct GetObjectA
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IRunningObjectTable* pThis;
			::IMoniker* pmkObjectName;
			::IUnknown** ppunkObject;
		};

		//Virtual
		struct NoteChangeTime
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IRunningObjectTable* pThis;
			::DWORD dwRegister;
			::FILETIME* pfiletime;
		};

		//Virtual
		struct GetTimeOfLastChange
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IRunningObjectTable* pThis;
			::IMoniker* pmkObjectName;
			::FILETIME* pfiletime;
		};

		//Virtual
		struct EnumRunning
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IRunningObjectTable* pThis;
			::IEnumMoniker** ppenumMoniker;
		};

	private:
		 virtual ~IRunningObjectTable() = 0;
	};

	class IPersist : IUnknown
	{
	public:
		//Virtual
		struct GetClassID
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPersist* pThis;
			::CLSID* pClassID;
		};

	private:
		 virtual ~IPersist() = 0;
	};

	class IPersistStream : IPersist
	{
	public:
		//Virtual
		struct IsDirty
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IPersistStream* pThis;
		};

		//Virtual
		struct Load
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPersistStream* pThis;
			::IStream* pStm;
		};

		//Virtual
		struct Save
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IPersistStream* pThis;
			::IStream* pStm;
			::BOOL fClearDirty;
		};

		//Virtual
		struct GetSizeMax
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPersistStream* pThis;
			::ULARGE_INTEGER* pcbSize;
		};

	private:
		 virtual ~IPersistStream() = 0;
	};

	class IMoniker : IPersistStream
	{
	public:
		//Virtual
		struct BindToObject
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IMoniker* pThis;
			::IBindCtx* pbc;
			::IMoniker* pmkToLeft;
			const ::IID& riidResult;
			void** ppvResult;
		};

		//Virtual
		struct BindToStorage
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IMoniker* pThis;
			::IBindCtx* pbc;
			::IMoniker* pmkToLeft;
			const ::IID& riid;
			void** ppvObj;
		};

		//Virtual
		struct Reduce
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IMoniker* pThis;
			::IBindCtx* pbc;
			::DWORD dwReduceHowFar;
			::IMoniker** ppmkToLeft;
			::IMoniker** ppmkReduced;
		};

		//Virtual
		struct ComposeWith
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IMoniker* pThis;
			::IMoniker* pmkRight;
			::BOOL fOnlyIfNotGeneric;
			::IMoniker** ppmkComposite;
		};

		//Virtual
		struct Enum
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IMoniker* pThis;
			::BOOL fForward;
			::IEnumMoniker** ppenumMoniker;
		};

		//Virtual
		struct IsEqual
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IMoniker* pThis;
			::IMoniker* pmkOtherMoniker;
		};

		//Virtual
		struct Hash
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IMoniker* pThis;
			::DWORD* pdwHash;
		};

		//Virtual
		struct IsRunning
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IMoniker* pThis;
			::IBindCtx* pbc;
			::IMoniker* pmkToLeft;
			::IMoniker* pmkNewlyRunning;
		};

		//Virtual
		struct GetTimeOfLastChange
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IMoniker* pThis;
			::IBindCtx* pbc;
			::IMoniker* pmkToLeft;
			::FILETIME* pFileTime;
		};

		//Virtual
		struct Inverse
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IMoniker* pThis;
			::IMoniker** ppmk;
		};

		//Virtual
		struct CommonPrefixWith
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IMoniker* pThis;
			::IMoniker* pmkOther;
			::IMoniker** ppmkPrefix;
		};

		//Virtual
		struct RelativePathTo
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IMoniker* pThis;
			::IMoniker* pmkOther;
			::IMoniker** ppmkRelPath;
		};

		//Virtual
		struct GetDisplayName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IMoniker* pThis;
			::IBindCtx* pbc;
			::IMoniker* pmkToLeft;
			::LPOLESTR* ppszDisplayName;
		};

		//Virtual
		struct ParseDisplayName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IMoniker* pThis;
			::IBindCtx* pbc;
			::IMoniker* pmkToLeft;
			::LPOLESTR pszDisplayName;
			::ULONG* pchEaten;
			::IMoniker** ppmkOut;
		};

		//Virtual
		struct IsSystemMoniker
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IMoniker* pThis;
			::DWORD* pdwMksys;
		};

	private:
		 virtual ~IMoniker() = 0;
	};

	class IROTData : IUnknown
	{
	public:
		//Virtual
		struct GetComparisonData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IROTData* pThis;
			::byte* pbData;
			::ULONG cbMax;
			::ULONG* pcbData;
		};

	private:
		 virtual ~IROTData() = 0;
	};

	class IEnumSTATSTG : IUnknown
	{
	public:
		//Virtual
		struct Next
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IEnumSTATSTG* pThis;
			::ULONG celt;
			::STATSTG* rgelt;
			::ULONG* pceltFetched;
		};

		//Virtual
		struct Skip
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IEnumSTATSTG* pThis;
			::ULONG celt;
		};

		//Virtual
		struct Reset
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IEnumSTATSTG* pThis;
		};

		//Virtual
		struct Clone
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IEnumSTATSTG* pThis;
			::IEnumSTATSTG** ppenum;
		};

	private:
		 virtual ~IEnumSTATSTG() = 0;
	};

	class IStorage : IUnknown
	{
	public:
		//Virtual
		struct CreateStream
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IStorage* pThis;
			const ::OLECHAR* pwcsName;
			::DWORD grfMode;
			::DWORD reserved1;
			::DWORD reserved2;
			::IStream** ppstm;
		};

		//Virtual
		struct OpenStream
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IStorage* pThis;
			const ::OLECHAR* pwcsName;
			void* reserved1;
			::DWORD grfMode;
			::DWORD reserved2;
			::IStream** ppstm;
		};

		//Virtual
		struct CreateStorage
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IStorage* pThis;
			const ::OLECHAR* pwcsName;
			::DWORD grfMode;
			::DWORD reserved1;
			::DWORD reserved2;
			::IStorage** ppstg;
		};

		//Virtual
		struct OpenStorage
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 7;

			::IStorage* pThis;
			const ::OLECHAR* pwcsName;
			::IStorage* pstgPriority;
			::DWORD grfMode;
			::SNB snbExclude;
			::DWORD reserved;
			::IStorage** ppstg;
		};

		//Virtual
		struct CopyTo
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IStorage* pThis;
			::DWORD ciidExclude;
			const ::IID* rgiidExclude;
			::SNB snbExclude;
			::IStorage* pstgDest;
		};

		//Virtual
		struct MoveElementTo
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IStorage* pThis;
			const ::OLECHAR* pwcsName;
			::IStorage* pstgDest;
			const ::OLECHAR* pwcsNewName;
			::DWORD grfFlags;
		};

		//Virtual
		struct Commit
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IStorage* pThis;
			::DWORD grfCommitFlags;
		};

		//Virtual
		struct Revert
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IStorage* pThis;
		};

		//Virtual
		struct EnumElements
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IStorage* pThis;
			::DWORD reserved1;
			void* reserved2;
			::DWORD reserved3;
			::IEnumSTATSTG** ppenum;
		};

		//Virtual
		struct DestroyElement
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IStorage* pThis;
			const ::OLECHAR* pwcsName;
		};

		//Virtual
		struct RenameElement
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IStorage* pThis;
			const ::OLECHAR* pwcsOldName;
			const ::OLECHAR* pwcsNewName;
		};

		//Virtual
		struct SetElementTimes
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IStorage* pThis;
			const ::OLECHAR* pwcsName;
			const ::FILETIME* pctime;
			const ::FILETIME* patime;
			const ::FILETIME* pmtime;
		};

		//Virtual
		struct SetClass
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IStorage* pThis;
			const ::IID& clsid;
		};

		//Virtual
		struct SetStateBits
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IStorage* pThis;
			::DWORD grfStateBits;
			::DWORD grfMask;
		};

		//Virtual
		struct Stat
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IStorage* pThis;
			::STATSTG* pstatstg;
			::DWORD grfStatFlag;
		};

	private:
		 virtual ~IStorage() = 0;
	};

	class IPersistFile : IPersist
	{
	public:
		//Virtual
		struct IsDirty
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IPersistFile* pThis;
		};

		//Virtual
		struct Load
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IPersistFile* pThis;
			::LPCOLESTR pszFileName;
			::DWORD dwMode;
		};

		//Virtual
		struct Save
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IPersistFile* pThis;
			::LPCOLESTR pszFileName;
			::BOOL fRemember;
		};

		//Virtual
		struct SaveCompleted
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPersistFile* pThis;
			::LPCOLESTR pszFileName;
		};

		//Virtual
		struct GetCurFile
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPersistFile* pThis;
			::LPOLESTR* ppszFileName;
		};

	private:
		 virtual ~IPersistFile() = 0;
	};

	class IPersistStorage : IPersist
	{
	public:
		//Virtual
		struct IsDirty
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IPersistStorage* pThis;
		};

		//Virtual
		struct InitNew
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPersistStorage* pThis;
			::IStorage* pStg;
		};

		//Virtual
		struct Load
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPersistStorage* pThis;
			::IStorage* pStg;
		};

		//Virtual
		struct Save
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IPersistStorage* pThis;
			::IStorage* pStgSave;
			::BOOL fSameAsLoad;
		};

		//Virtual
		struct SaveCompleted
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPersistStorage* pThis;
			::IStorage* pStgNew;
		};

		//Virtual
		struct HandsOffStorage
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IPersistStorage* pThis;
		};

	private:
		 virtual ~IPersistStorage() = 0;
	};

	class ILockBytes : IUnknown
	{
	public:
		//Virtual
		struct ReadAt
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ILockBytes* pThis;
			::ULARGE_INTEGER ulOffset;
			void* pv;
			::ULONG cb;
			::ULONG* pcbRead;
		};

		//Virtual
		struct WriteAt
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ILockBytes* pThis;
			::ULARGE_INTEGER ulOffset;
			const void* pv;
			::ULONG cb;
			::ULONG* pcbWritten;
		};

		//Virtual
		struct Flush
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ILockBytes* pThis;
		};

		//Virtual
		struct SetSize
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ILockBytes* pThis;
			::ULARGE_INTEGER cb;
		};

		//Virtual
		struct LockRegion
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ILockBytes* pThis;
			::ULARGE_INTEGER libOffset;
			::ULARGE_INTEGER cb;
			::DWORD dwLockType;
		};

		//Virtual
		struct UnlockRegion
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ILockBytes* pThis;
			::ULARGE_INTEGER libOffset;
			::ULARGE_INTEGER cb;
			::DWORD dwLockType;
		};

		//Virtual
		struct Stat
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ILockBytes* pThis;
			::STATSTG* pstatstg;
			::DWORD grfStatFlag;
		};

	private:
		 virtual ~ILockBytes() = 0;
	};

	class IEnumFORMATETC : IUnknown
	{
	public:
		//Virtual
		struct Next
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IEnumFORMATETC* pThis;
			::ULONG celt;
			::FORMATETC* rgelt;
			::ULONG* pceltFetched;
		};

		//Virtual
		struct Skip
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IEnumFORMATETC* pThis;
			::ULONG celt;
		};

		//Virtual
		struct Reset
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IEnumFORMATETC* pThis;
		};

		//Virtual
		struct Clone
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IEnumFORMATETC* pThis;
			::IEnumFORMATETC** ppenum;
		};

	private:
		 virtual ~IEnumFORMATETC() = 0;
	};

	class IEnumSTATDATA : IUnknown
	{
	public:
		//Virtual
		struct Next
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IEnumSTATDATA* pThis;
			::ULONG celt;
			::STATDATA* rgelt;
			::ULONG* pceltFetched;
		};

		//Virtual
		struct Skip
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IEnumSTATDATA* pThis;
			::ULONG celt;
		};

		//Virtual
		struct Reset
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IEnumSTATDATA* pThis;
		};

		//Virtual
		struct Clone
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IEnumSTATDATA* pThis;
			::IEnumSTATDATA** ppenum;
		};

	private:
		 virtual ~IEnumSTATDATA() = 0;
	};

	class IRootStorage : IUnknown
	{
	public:
		//Virtual
		struct SwitchToFile
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IRootStorage* pThis;
			::LPOLESTR pszFile;
		};

	private:
		 virtual ~IRootStorage() = 0;
	};

	class IAdviseSink : IUnknown
	{
	public:
		//Virtual
		struct OnDataChange
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::IAdviseSink* pThis;
			::FORMATETC* pFormatetc;
			::STGMEDIUM* pStgmed;
		};

		//Virtual
		struct OnViewChange
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::IAdviseSink* pThis;
			::DWORD dwAspect;
			::LONG lindex;
		};

		//Virtual
		struct OnRename
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::IAdviseSink* pThis;
			::IMoniker* pmk;
		};

		//Virtual
		struct OnSave
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::IAdviseSink* pThis;
		};

		//Virtual
		struct OnClose
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::IAdviseSink* pThis;
		};

	private:
		 virtual ~IAdviseSink() = 0;
	};

	class AsyncIAdviseSink : IUnknown
	{
	public:
		//Virtual
		struct Begin_OnDataChange
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::AsyncIAdviseSink* pThis;
			::FORMATETC* pFormatetc;
			::STGMEDIUM* pStgmed;
		};

		//Virtual
		struct Finish_OnDataChange
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::AsyncIAdviseSink* pThis;
		};

		//Virtual
		struct Begin_OnViewChange
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::AsyncIAdviseSink* pThis;
			::DWORD dwAspect;
			::LONG lindex;
		};

		//Virtual
		struct Finish_OnViewChange
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::AsyncIAdviseSink* pThis;
		};

		//Virtual
		struct Begin_OnRename
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::AsyncIAdviseSink* pThis;
			::IMoniker* pmk;
		};

		//Virtual
		struct Finish_OnRename
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::AsyncIAdviseSink* pThis;
		};

		//Virtual
		struct Begin_OnSave
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::AsyncIAdviseSink* pThis;
		};

		//Virtual
		struct Finish_OnSave
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::AsyncIAdviseSink* pThis;
		};

		//Virtual
		struct Begin_OnClose
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::AsyncIAdviseSink* pThis;
		};

		//Virtual
		struct Finish_OnClose
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::AsyncIAdviseSink* pThis;
		};

	private:
		 virtual ~AsyncIAdviseSink() = 0;
	};

	class IAdviseSink2 : IAdviseSink
	{
	public:
		//Virtual
		struct OnLinkSrcChange
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::IAdviseSink2* pThis;
			::IMoniker* pmk;
		};

	private:
		 virtual ~IAdviseSink2() = 0;
	};

	class AsyncIAdviseSink2 : AsyncIAdviseSink
	{
	public:
		//Virtual
		struct Begin_OnLinkSrcChange
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::AsyncIAdviseSink2* pThis;
			::IMoniker* pmk;
		};

		//Virtual
		struct Finish_OnLinkSrcChange
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::AsyncIAdviseSink2* pThis;
		};

	private:
		 virtual ~AsyncIAdviseSink2() = 0;
	};

	class IDataObject : IUnknown
	{
	public:
		//Virtual
		struct GetData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDataObject* pThis;
			::FORMATETC* pformatetcIn;
			::STGMEDIUM* pmedium;
		};

		//Virtual
		struct GetDataHere
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDataObject* pThis;
			::FORMATETC* pformatetc;
			::STGMEDIUM* pmedium;
		};

		//Virtual
		struct QueryGetData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDataObject* pThis;
			::FORMATETC* pformatetc;
		};

		//Virtual
		struct GetCanonicalFormatEtc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDataObject* pThis;
			::FORMATETC* pformatectIn;
			::FORMATETC* pformatetcOut;
		};

		//Virtual
		struct SetData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IDataObject* pThis;
			::FORMATETC* pformatetc;
			::STGMEDIUM* pmedium;
			::BOOL fRelease;
		};

		//Virtual
		struct EnumFormatEtc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDataObject* pThis;
			::DWORD dwDirection;
			::IEnumFORMATETC** ppenumFormatEtc;
		};

		//Virtual
		struct DAdvise
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IDataObject* pThis;
			::FORMATETC* pformatetc;
			::DWORD advf;
			::IAdviseSink* pAdvSink;
			::DWORD* pdwConnection;
		};

		//Virtual
		struct DUnadvise
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDataObject* pThis;
			::DWORD dwConnection;
		};

		//Virtual
		struct EnumDAdvise
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDataObject* pThis;
			::IEnumSTATDATA** ppenumAdvise;
		};

	private:
		 virtual ~IDataObject() = 0;
	};

	class IDataAdviseHolder : IUnknown
	{
	public:
		//Virtual
		struct Advise
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IDataAdviseHolder* pThis;
			::IDataObject* pDataObject;
			::FORMATETC* pFetc;
			::DWORD advf;
			::IAdviseSink* pAdvise;
			::DWORD* pdwConnection;
		};

		//Virtual
		struct Unadvise
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDataAdviseHolder* pThis;
			::DWORD dwConnection;
		};

		//Virtual
		struct EnumAdvise
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDataAdviseHolder* pThis;
			::IEnumSTATDATA** ppenumAdvise;
		};

		//Virtual
		struct SendOnDataChange
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IDataAdviseHolder* pThis;
			::IDataObject* pDataObject;
			::DWORD dwReserved;
			::DWORD advf;
		};

	private:
		 virtual ~IDataAdviseHolder() = 0;
	};

	class IMessageFilter : IUnknown
	{
	public:
		//Virtual
		struct HandleInComingCall
		{
			using ReturnType_t = ::DWORD;
			static constexpr size_t Argc = 5;

			::IMessageFilter* pThis;
			::DWORD dwCallType;
			::HTASK htaskCaller;
			::DWORD dwTickCount;
			::LPINTERFACEINFO lpInterfaceInfo;
		};

		//Virtual
		struct RetryRejectedCall
		{
			using ReturnType_t = ::DWORD;
			static constexpr size_t Argc = 4;

			::IMessageFilter* pThis;
			::HTASK htaskCallee;
			::DWORD dwTickCount;
			::DWORD dwRejectType;
		};

		//Virtual
		struct MessagePending
		{
			using ReturnType_t = ::DWORD;
			static constexpr size_t Argc = 4;

			::IMessageFilter* pThis;
			::HTASK htaskCallee;
			::DWORD dwTickCount;
			::DWORD dwPendingType;
		};

	private:
		 virtual ~IMessageFilter() = 0;
	};

	class IClassActivator : IUnknown
	{
	public:
		//Virtual
		struct GetClassObject
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IClassActivator* pThis;
			const ::IID& rclsid;
			::DWORD dwClassContext;
			::LCID locale;
			const ::IID& riid;
			void** ppv;
		};

	private:
		 virtual ~IClassActivator() = 0;
	};

	class IFillLockBytes : IUnknown
	{
	public:
		//Virtual
		struct FillAppend
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IFillLockBytes* pThis;
			const void* pv;
			::ULONG cb;
			::ULONG* pcbWritten;
		};

		//Virtual
		struct FillAt
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IFillLockBytes* pThis;
			::ULARGE_INTEGER ulOffset;
			const void* pv;
			::ULONG cb;
			::ULONG* pcbWritten;
		};

		//Virtual
		struct SetFillSize
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IFillLockBytes* pThis;
			::ULARGE_INTEGER ulSize;
		};

		//Virtual
		struct Terminate
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IFillLockBytes* pThis;
			::BOOL bCanceled;
		};

	private:
		 virtual ~IFillLockBytes() = 0;
	};

	class IProgressNotify : IUnknown
	{
	public:
		//Virtual
		struct OnProgress
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IProgressNotify* pThis;
			::DWORD dwProgressCurrent;
			::DWORD dwProgressMaximum;
			::BOOL fAccurate;
			::BOOL fOwner;
		};

	private:
		 virtual ~IProgressNotify() = 0;
	};

	class ILayoutStorage : IUnknown
	{
	public:
		//Virtual
		struct LayoutScript
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ILayoutStorage* pThis;
			::StorageLayout* pStorageLayout;
			::DWORD nEntries;
			::DWORD glfInterleavedFlag;
		};

		//Virtual
		struct BeginMonitor
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ILayoutStorage* pThis;
		};

		//Virtual
		struct EndMonitor
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ILayoutStorage* pThis;
		};

		//Virtual
		struct ReLayoutDocfile
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ILayoutStorage* pThis;
			::OLECHAR* pwcsNewDfName;
		};

		//Virtual
		struct ReLayoutDocfileOnILockBytes
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ILayoutStorage* pThis;
			::ILockBytes* pILockBytes;
		};

	private:
		 virtual ~ILayoutStorage() = 0;
	};

	class IBlockingLock : IUnknown
	{
	public:
		//Virtual
		struct Lock
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IBlockingLock* pThis;
			::DWORD dwTimeout;
		};

		//Virtual
		struct Unlock
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IBlockingLock* pThis;
		};

	private:
		 virtual ~IBlockingLock() = 0;
	};

	class ITimeAndNoticeControl : IUnknown
	{
	public:
		//Virtual
		struct SuppressChanges
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ITimeAndNoticeControl* pThis;
			::DWORD res1;
			::DWORD res2;
		};

	private:
		 virtual ~ITimeAndNoticeControl() = 0;
	};

	class IOplockStorage : IUnknown
	{
	public:
		//Virtual
		struct CreateStorageEx
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 7;

			::IOplockStorage* pThis;
			::LPCWSTR pwcsName;
			::DWORD grfMode;
			::DWORD stgfmt;
			::DWORD grfAttrs;
			const ::IID& riid;
			void** ppstgOpen;
		};

		//Virtual
		struct OpenStorageEx
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 7;

			::IOplockStorage* pThis;
			::LPCWSTR pwcsName;
			::DWORD grfMode;
			::DWORD stgfmt;
			::DWORD grfAttrs;
			const ::IID& riid;
			void** ppstgOpen;
		};

	private:
		 virtual ~IOplockStorage() = 0;
	};

	class IDirectWriterLock : IUnknown
	{
	public:
		//Virtual
		struct WaitForWriteAccess
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDirectWriterLock* pThis;
			::DWORD dwTimeout;
		};

		//Virtual
		struct ReleaseWriteAccess
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IDirectWriterLock* pThis;
		};

		//Virtual
		struct HaveWriteAccess
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IDirectWriterLock* pThis;
		};

	private:
		 virtual ~IDirectWriterLock() = 0;
	};

	class IUrlMon : IUnknown
	{
	public:
		//Virtual
		struct AsyncGetClassBits
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 11;

			::IUrlMon* pThis;
			const ::IID& rclsid;
			::LPCWSTR pszTYPE;
			::LPCWSTR pszExt;
			::DWORD dwFileVersionMS;
			::DWORD dwFileVersionLS;
			::LPCWSTR pszCodeBase;
			::IBindCtx* pbc;
			::DWORD dwClassContext;
			const ::IID& riid;
			::DWORD flags;
		};

	private:
		 virtual ~IUrlMon() = 0;
	};

	class IForegroundTransfer : IUnknown
	{
	public:
		//Virtual
		struct AllowForegroundTransfer
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IForegroundTransfer* pThis;
			void* lpvReserved;
		};

	private:
		 virtual ~IForegroundTransfer() = 0;
	};

	class IThumbnailExtractor : IUnknown
	{
	public:
		//Virtual
		struct ExtractThumbnail
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 7;

			::IThumbnailExtractor* pThis;
			::IStorage* pStg;
			::ULONG ulLength;
			::ULONG ulHeight;
			::ULONG* pulOutputLength;
			::ULONG* pulOutputHeight;
			::HBITMAP* phOutputBitmap;
		};

		//Virtual
		struct OnFileUpdated
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IThumbnailExtractor* pThis;
			::IStorage* pStg;
		};

	private:
		 virtual ~IThumbnailExtractor() = 0;
	};

	class IDummyHICONIncluder : IUnknown
	{
	public:
		//Virtual
		struct Dummy
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDummyHICONIncluder* pThis;
			::HICON h1;
			::HDC h2;
		};

	private:
		 virtual ~IDummyHICONIncluder() = 0;
	};

	class IProcessLock : IUnknown
	{
	public:
		//Virtual
		struct AddRefOnProcess
		{
			using ReturnType_t = ::ULONG;
			static constexpr size_t Argc = 1;

			::IProcessLock* pThis;
		};

		//Virtual
		struct ReleaseRefOnProcess
		{
			using ReturnType_t = ::ULONG;
			static constexpr size_t Argc = 1;

			::IProcessLock* pThis;
		};

	private:
		 virtual ~IProcessLock() = 0;
	};

	class ISurrogateService : IUnknown
	{
	public:
		//Virtual
		struct Init
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ISurrogateService* pThis;
			const ::GUID& rguidProcessID;
			::IProcessLock* pProcessLock;
			::BOOL* pfApplicationAware;
		};

		//Virtual
		struct ApplicationLaunch
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ISurrogateService* pThis;
			const ::GUID& rguidApplID;
			::ApplicationType appType;
		};

		//Virtual
		struct ApplicationFree
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ISurrogateService* pThis;
			const ::GUID& rguidApplID;
		};

		//Virtual
		struct CatalogRefresh
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ISurrogateService* pThis;
			::ULONG ulReserved;
		};

		//Virtual
		struct ProcessShutdown
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ISurrogateService* pThis;
			::ShutdownType shutdownType;
		};

	private:
		 virtual ~ISurrogateService() = 0;
	};

	class IInitializeSpy : IUnknown
	{
	public:
		//Virtual
		struct PreInitialize
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IInitializeSpy* pThis;
			::DWORD dwCoInit;
			::DWORD dwCurThreadAptRefs;
		};

		//Virtual
		struct PostInitialize
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IInitializeSpy* pThis;
			::HRESULT hrCoInit;
			::DWORD dwCoInit;
			::DWORD dwNewThreadAptRefs;
		};

		//Virtual
		struct PreUninitialize
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IInitializeSpy* pThis;
			::DWORD dwCurThreadAptRefs;
		};

		//Virtual
		struct PostUninitialize
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IInitializeSpy* pThis;
			::DWORD dwNewThreadAptRefs;
		};

	private:
		 virtual ~IInitializeSpy() = 0;
	};

	class IApartmentShutdown : IUnknown
	{
	public:
		//Virtual
		struct OnUninitialize
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::IApartmentShutdown* pThis;
			::UINT64 ui64ApartmentIdentifier;
		};

	private:
		 virtual ~IApartmentShutdown() = 0;
	};

	class ICreateTypeInfo : IUnknown
	{
	public:
		//Virtual
		struct SetGuid
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICreateTypeInfo* pThis;
			const ::GUID& guid;
		};

		//Virtual
		struct SetTypeFlags
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICreateTypeInfo* pThis;
			::UINT uTypeFlags;
		};

		//Virtual
		struct SetDocString
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICreateTypeInfo* pThis;
			::LPOLESTR pStrDoc;
		};

		//Virtual
		struct SetHelpContext
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICreateTypeInfo* pThis;
			::DWORD dwHelpContext;
		};

		//Virtual
		struct SetVersion
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ICreateTypeInfo* pThis;
			::WORD wMajorVerNum;
			::WORD wMinorVerNum;
		};

		//Virtual
		struct AddRefTypeInfo
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ICreateTypeInfo* pThis;
			::ITypeInfo* pTInfo;
			::HREFTYPE* phRefType;
		};

		//Virtual
		struct AddFuncDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ICreateTypeInfo* pThis;
			::UINT index;
			::FUNCDESC* pFuncDesc;
		};

		//Virtual
		struct AddImplType
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ICreateTypeInfo* pThis;
			::UINT index;
			::HREFTYPE hRefType;
		};

		//Virtual
		struct SetImplTypeFlags
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ICreateTypeInfo* pThis;
			::UINT index;
			::INT implTypeFlags;
		};

		//Virtual
		struct SetAlignment
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICreateTypeInfo* pThis;
			::WORD cbAlignment;
		};

		//Virtual
		struct SetSchema
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICreateTypeInfo* pThis;
			::LPOLESTR pStrSchema;
		};

		//Virtual
		struct AddVarDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ICreateTypeInfo* pThis;
			::UINT index;
			::VARDESC* pVarDesc;
		};

		//Virtual
		struct SetFuncAndParamNames
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ICreateTypeInfo* pThis;
			::UINT index;
			::LPOLESTR* rgszNames;
			::UINT cNames;
		};

		//Virtual
		struct SetVarName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ICreateTypeInfo* pThis;
			::UINT index;
			::LPOLESTR szName;
		};

		//Virtual
		struct SetTypeDescAlias
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICreateTypeInfo* pThis;
			::TYPEDESC* pTDescAlias;
		};

		//Virtual
		struct DefineFuncAsDllEntry
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ICreateTypeInfo* pThis;
			::UINT index;
			::LPOLESTR szDllName;
			::LPOLESTR szProcName;
		};

		//Virtual
		struct SetFuncDocString
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ICreateTypeInfo* pThis;
			::UINT index;
			::LPOLESTR szDocString;
		};

		//Virtual
		struct SetVarDocString
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ICreateTypeInfo* pThis;
			::UINT index;
			::LPOLESTR szDocString;
		};

		//Virtual
		struct SetFuncHelpContext
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ICreateTypeInfo* pThis;
			::UINT index;
			::DWORD dwHelpContext;
		};

		//Virtual
		struct SetVarHelpContext
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ICreateTypeInfo* pThis;
			::UINT index;
			::DWORD dwHelpContext;
		};

		//Virtual
		struct SetMops
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ICreateTypeInfo* pThis;
			::UINT index;
			::BSTR bstrMops;
		};

		//Virtual
		struct SetTypeIdldesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICreateTypeInfo* pThis;
			::IDLDESC* pIdlDesc;
		};

		//Virtual
		struct LayOut
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ICreateTypeInfo* pThis;
		};

	private:
		 virtual ~ICreateTypeInfo() = 0;
	};

	class ICreateTypeInfo2 : ICreateTypeInfo
	{
	public:
		//Virtual
		struct DeleteFuncDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICreateTypeInfo2* pThis;
			::UINT index;
		};

		//Virtual
		struct DeleteFuncDescByMemId
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ICreateTypeInfo2* pThis;
			::MEMBERID memid;
			::INVOKEKIND invKind;
		};

		//Virtual
		struct DeleteVarDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICreateTypeInfo2* pThis;
			::UINT index;
		};

		//Virtual
		struct DeleteVarDescByMemId
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICreateTypeInfo2* pThis;
			::MEMBERID memid;
		};

		//Virtual
		struct DeleteImplType
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICreateTypeInfo2* pThis;
			::UINT index;
		};

		//Virtual
		struct SetCustData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ICreateTypeInfo2* pThis;
			const ::GUID& guid;
			::VARIANT* pVarVal;
		};

		//Virtual
		struct SetFuncCustData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ICreateTypeInfo2* pThis;
			::UINT index;
			const ::GUID& guid;
			::VARIANT* pVarVal;
		};

		//Virtual
		struct SetParamCustData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ICreateTypeInfo2* pThis;
			::UINT indexFunc;
			::UINT indexParam;
			const ::GUID& guid;
			::VARIANT* pVarVal;
		};

		//Virtual
		struct SetVarCustData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ICreateTypeInfo2* pThis;
			::UINT index;
			const ::GUID& guid;
			::VARIANT* pVarVal;
		};

		//Virtual
		struct SetImplTypeCustData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ICreateTypeInfo2* pThis;
			::UINT index;
			const ::GUID& guid;
			::VARIANT* pVarVal;
		};

		//Virtual
		struct SetHelpStringContext
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICreateTypeInfo2* pThis;
			::ULONG dwHelpStringContext;
		};

		//Virtual
		struct SetFuncHelpStringContext
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ICreateTypeInfo2* pThis;
			::UINT index;
			::ULONG dwHelpStringContext;
		};

		//Virtual
		struct SetVarHelpStringContext
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ICreateTypeInfo2* pThis;
			::UINT index;
			::ULONG dwHelpStringContext;
		};

		//Virtual
		struct Invalidate
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ICreateTypeInfo2* pThis;
		};

		//Virtual
		struct SetName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICreateTypeInfo2* pThis;
			::LPOLESTR szName;
		};

	private:
		 virtual ~ICreateTypeInfo2() = 0;
	};

	class ICreateTypeLib : IUnknown
	{
	public:
		//Virtual
		struct CreateTypeInfo
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ICreateTypeLib* pThis;
			::LPOLESTR szName;
			::TYPEKIND tkind;
			::ICreateTypeInfo** ppCTInfo;
		};

		//Virtual
		struct SetName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICreateTypeLib* pThis;
			::LPOLESTR szName;
		};

		//Virtual
		struct SetVersion
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ICreateTypeLib* pThis;
			::WORD wMajorVerNum;
			::WORD wMinorVerNum;
		};

		//Virtual
		struct SetGuid
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICreateTypeLib* pThis;
			const ::GUID& guid;
		};

		//Virtual
		struct SetDocString
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICreateTypeLib* pThis;
			::LPOLESTR szDoc;
		};

		//Virtual
		struct SetHelpFileName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICreateTypeLib* pThis;
			::LPOLESTR szHelpFileName;
		};

		//Virtual
		struct SetHelpContext
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICreateTypeLib* pThis;
			::DWORD dwHelpContext;
		};

		//Virtual
		struct SetLcid
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICreateTypeLib* pThis;
			::LCID lcid;
		};

		//Virtual
		struct SetLibFlags
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICreateTypeLib* pThis;
			::UINT uLibFlags;
		};

		//Virtual
		struct SaveAllChanges
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ICreateTypeLib* pThis;
		};

	private:
		 virtual ~ICreateTypeLib() = 0;
	};

	class ICreateTypeLib2 : ICreateTypeLib
	{
	public:
		//Virtual
		struct DeleteTypeInfo
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICreateTypeLib2* pThis;
			::LPOLESTR szName;
		};

		//Virtual
		struct SetCustData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ICreateTypeLib2* pThis;
			const ::GUID& guid;
			::VARIANT* pVarVal;
		};

		//Virtual
		struct SetHelpStringContext
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICreateTypeLib2* pThis;
			::ULONG dwHelpStringContext;
		};

		//Virtual
		struct SetHelpStringDll
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICreateTypeLib2* pThis;
			::LPOLESTR szFileName;
		};

	private:
		 virtual ~ICreateTypeLib2() = 0;
	};

	class IDispatch : IUnknown
	{
	public:
		//Virtual
		struct GetTypeInfoCount
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDispatch* pThis;
			::UINT* pctinfo;
		};

		//Virtual
		struct GetTypeInfo
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IDispatch* pThis;
			::UINT iTInfo;
			::LCID lcid;
			::ITypeInfo** ppTInfo;
		};

		//Virtual
		struct GetIDsOfNames
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IDispatch* pThis;
			const ::IID& riid;
			::LPOLESTR* rgszNames;
			::UINT cNames;
			::LCID lcid;
			::DISPID* rgDispId;
		};

		//Virtual
		struct Invoke
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 9;

			::IDispatch* pThis;
			::DISPID dispIdMember;
			const ::IID& riid;
			::LCID lcid;
			::WORD wFlags;
			::DISPPARAMS* pDispParams;
			::VARIANT* pVarResult;
			::EXCEPINFO* pExcepInfo;
			::UINT* puArgErr;
		};

	private:
		 virtual ~IDispatch() = 0;
	};

	class IEnumVARIANT : IUnknown
	{
	public:
		//Virtual
		struct Next
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IEnumVARIANT* pThis;
			::ULONG celt;
			::VARIANT* rgVar;
			::ULONG* pCeltFetched;
		};

		//Virtual
		struct Skip
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IEnumVARIANT* pThis;
			::ULONG celt;
		};

		//Virtual
		struct Reset
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IEnumVARIANT* pThis;
		};

		//Virtual
		struct Clone
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IEnumVARIANT* pThis;
			::IEnumVARIANT** ppEnum;
		};

	private:
		 virtual ~IEnumVARIANT() = 0;
	};

	class ITypeComp : IUnknown
	{
	public:
		//Virtual
		struct Bind
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 7;

			::ITypeComp* pThis;
			::LPOLESTR szName;
			::ULONG lHashVal;
			::WORD wFlags;
			::ITypeInfo** ppTInfo;
			::DESCKIND* pDescKind;
			::BINDPTR* pBindPtr;
		};

		//Virtual
		struct BindType
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ITypeComp* pThis;
			::LPOLESTR szName;
			::ULONG lHashVal;
			::ITypeInfo** ppTInfo;
			::ITypeComp** ppTComp;
		};

	private:
		 virtual ~ITypeComp() = 0;
	};

	class ITypeInfo : IUnknown
	{
	public:
		//Virtual
		struct GetTypeAttr
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ITypeInfo* pThis;
			::TYPEATTR** ppTypeAttr;
		};

		//Virtual
		struct GetTypeComp
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ITypeInfo* pThis;
			::ITypeComp** ppTComp;
		};

		//Virtual
		struct GetFuncDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ITypeInfo* pThis;
			::UINT index;
			::FUNCDESC** ppFuncDesc;
		};

		//Virtual
		struct GetVarDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ITypeInfo* pThis;
			::UINT index;
			::VARDESC** ppVarDesc;
		};

		//Virtual
		struct GetNames
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ITypeInfo* pThis;
			::MEMBERID memid;
			::BSTR* rgBstrNames;
			::UINT cMaxNames;
			::UINT* pcNames;
		};

		//Virtual
		struct GetRefTypeOfImplType
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ITypeInfo* pThis;
			::UINT index;
			::HREFTYPE* pRefType;
		};

		//Virtual
		struct GetImplTypeFlags
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ITypeInfo* pThis;
			::UINT index;
			::INT* pImplTypeFlags;
		};

		//Virtual
		struct GetIDsOfNames
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ITypeInfo* pThis;
			::LPOLESTR* rgszNames;
			::UINT cNames;
			::MEMBERID* pMemId;
		};

		//Virtual
		struct Invoke
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 8;

			::ITypeInfo* pThis;
			::PVOID pvInstance;
			::MEMBERID memid;
			::WORD wFlags;
			::DISPPARAMS* pDispParams;
			::VARIANT* pVarResult;
			::EXCEPINFO* pExcepInfo;
			::UINT* puArgErr;
		};

		//Virtual
		struct GetDocumentation
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::ITypeInfo* pThis;
			::MEMBERID memid;
			::BSTR* pBstrName;
			::BSTR* pBstrDocString;
			::DWORD* pdwHelpContext;
			::BSTR* pBstrHelpFile;
		};

		//Virtual
		struct GetDllEntry
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::ITypeInfo* pThis;
			::MEMBERID memid;
			::INVOKEKIND invKind;
			::BSTR* pBstrDllName;
			::BSTR* pBstrName;
			::WORD* pwOrdinal;
		};

		//Virtual
		struct GetRefTypeInfo
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ITypeInfo* pThis;
			::HREFTYPE hRefType;
			::ITypeInfo** ppTInfo;
		};

		//Virtual
		struct AddressOfMember
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ITypeInfo* pThis;
			::MEMBERID memid;
			::INVOKEKIND invKind;
			::PVOID* ppv;
		};

		//Virtual
		struct CreateInstance
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ITypeInfo* pThis;
			::IUnknown* pUnkOuter;
			const ::IID& riid;
			::PVOID* ppvObj;
		};

		//Virtual
		struct GetMops
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ITypeInfo* pThis;
			::MEMBERID memid;
			::BSTR* pBstrMops;
		};

		//Virtual
		struct GetContainingTypeLib
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ITypeInfo* pThis;
			::ITypeLib** ppTLib;
			::UINT* pIndex;
		};

		//Virtual
		struct ReleaseTypeAttr
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ITypeInfo* pThis;
			::TYPEATTR* pTypeAttr;
		};

		//Virtual
		struct ReleaseFuncDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ITypeInfo* pThis;
			::FUNCDESC* pFuncDesc;
		};

		//Virtual
		struct ReleaseVarDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ITypeInfo* pThis;
			::VARDESC* pVarDesc;
		};

	private:
		 virtual ~ITypeInfo() = 0;
	};

	class ITypeInfo2 : ITypeInfo
	{
	public:
		//Virtual
		struct GetTypeKind
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ITypeInfo2* pThis;
			::TYPEKIND* pTypeKind;
		};

		//Virtual
		struct GetTypeFlags
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ITypeInfo2* pThis;
			::ULONG* pTypeFlags;
		};

		//Virtual
		struct GetFuncIndexOfMemId
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ITypeInfo2* pThis;
			::MEMBERID memid;
			::INVOKEKIND invKind;
			::UINT* pFuncIndex;
		};

		//Virtual
		struct GetVarIndexOfMemId
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ITypeInfo2* pThis;
			::MEMBERID memid;
			::UINT* pVarIndex;
		};

		//Virtual
		struct GetCustData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ITypeInfo2* pThis;
			const ::GUID& guid;
			::VARIANT* pVarVal;
		};

		//Virtual
		struct GetFuncCustData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ITypeInfo2* pThis;
			::UINT index;
			const ::GUID& guid;
			::VARIANT* pVarVal;
		};

		//Virtual
		struct GetParamCustData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ITypeInfo2* pThis;
			::UINT indexFunc;
			::UINT indexParam;
			const ::GUID& guid;
			::VARIANT* pVarVal;
		};

		//Virtual
		struct GetVarCustData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ITypeInfo2* pThis;
			::UINT index;
			const ::GUID& guid;
			::VARIANT* pVarVal;
		};

		//Virtual
		struct GetImplTypeCustData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ITypeInfo2* pThis;
			::UINT index;
			const ::GUID& guid;
			::VARIANT* pVarVal;
		};

		//Virtual
		struct GetDocumentation2
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::ITypeInfo2* pThis;
			::MEMBERID memid;
			::LCID lcid;
			::BSTR* pbstrHelpString;
			::DWORD* pdwHelpStringContext;
			::BSTR* pbstrHelpStringDll;
		};

		//Virtual
		struct GetAllCustData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ITypeInfo2* pThis;
			::CUSTDATA* pCustData;
		};

		//Virtual
		struct GetAllFuncCustData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ITypeInfo2* pThis;
			::UINT index;
			::CUSTDATA* pCustData;
		};

		//Virtual
		struct GetAllParamCustData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ITypeInfo2* pThis;
			::UINT indexFunc;
			::UINT indexParam;
			::CUSTDATA* pCustData;
		};

		//Virtual
		struct GetAllVarCustData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ITypeInfo2* pThis;
			::UINT index;
			::CUSTDATA* pCustData;
		};

		//Virtual
		struct GetAllImplTypeCustData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ITypeInfo2* pThis;
			::UINT index;
			::CUSTDATA* pCustData;
		};

	private:
		 virtual ~ITypeInfo2() = 0;
	};

	class ITypeLib : IUnknown
	{
	public:
		//Virtual
		struct GetTypeInfoCount
		{
			using ReturnType_t = ::UINT;
			static constexpr size_t Argc = 1;

			::ITypeLib* pThis;
		};

		//Virtual
		struct GetTypeInfo
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ITypeLib* pThis;
			::UINT index;
			::ITypeInfo** ppTInfo;
		};

		//Virtual
		struct GetTypeInfoType
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ITypeLib* pThis;
			::UINT index;
			::TYPEKIND* pTKind;
		};

		//Virtual
		struct GetTypeInfoOfGuid
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ITypeLib* pThis;
			const ::GUID& guid;
			::ITypeInfo** ppTinfo;
		};

		//Virtual
		struct GetLibAttr
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ITypeLib* pThis;
			::TLIBATTR** ppTLibAttr;
		};

		//Virtual
		struct GetTypeComp
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ITypeLib* pThis;
			::ITypeComp** ppTComp;
		};

		//Virtual
		struct GetDocumentation
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::ITypeLib* pThis;
			::INT index;
			::BSTR* pBstrName;
			::BSTR* pBstrDocString;
			::DWORD* pdwHelpContext;
			::BSTR* pBstrHelpFile;
		};

		//Virtual
		struct IsName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ITypeLib* pThis;
			::LPOLESTR szNameBuf;
			::ULONG lHashVal;
			::BOOL* pfName;
		};

		//Virtual
		struct FindName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::ITypeLib* pThis;
			::LPOLESTR szNameBuf;
			::ULONG lHashVal;
			::ITypeInfo** ppTInfo;
			::MEMBERID* rgMemId;
			::USHORT* pcFound;
		};

		//Virtual
		struct ReleaseTLibAttr
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ITypeLib* pThis;
			::TLIBATTR* pTLibAttr;
		};

	private:
		 virtual ~ITypeLib() = 0;
	};

	class ITypeLib2 : ITypeLib
	{
	public:
		//Virtual
		struct GetCustData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ITypeLib2* pThis;
			const ::GUID& guid;
			::VARIANT* pVarVal;
		};

		//Virtual
		struct GetLibStatistics
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ITypeLib2* pThis;
			::ULONG* pcUniqueNames;
			::ULONG* pcchUniqueNames;
		};

		//Virtual
		struct GetDocumentation2
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::ITypeLib2* pThis;
			::INT index;
			::LCID lcid;
			::BSTR* pbstrHelpString;
			::DWORD* pdwHelpStringContext;
			::BSTR* pbstrHelpStringDll;
		};

		//Virtual
		struct GetAllCustData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ITypeLib2* pThis;
			::CUSTDATA* pCustData;
		};

	private:
		 virtual ~ITypeLib2() = 0;
	};

	class ITypeChangeEvents : IUnknown
	{
	public:
		//Virtual
		struct RequestTypeChange
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ITypeChangeEvents* pThis;
			::CHANGEKIND changeKind;
			::ITypeInfo* pTInfoBefore;
			::LPOLESTR pStrName;
			::INT* pfCancel;
		};

		//Virtual
		struct AfterTypeChange
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ITypeChangeEvents* pThis;
			::CHANGEKIND changeKind;
			::ITypeInfo* pTInfoAfter;
			::LPOLESTR pStrName;
		};

	private:
		 virtual ~ITypeChangeEvents() = 0;
	};

	class IErrorInfo : IUnknown
	{
	public:
		//Virtual
		struct GetGUID
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IErrorInfo* pThis;
			::GUID* pGUID;
		};

		//Virtual
		struct GetSource
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IErrorInfo* pThis;
			::BSTR* pBstrSource;
		};

		//Virtual
		struct GetDescription
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IErrorInfo* pThis;
			::BSTR* pBstrDescription;
		};

		//Virtual
		struct GetHelpFile
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IErrorInfo* pThis;
			::BSTR* pBstrHelpFile;
		};

		//Virtual
		struct GetHelpContext
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IErrorInfo* pThis;
			::DWORD* pdwHelpContext;
		};

	private:
		 virtual ~IErrorInfo() = 0;
	};

	class ICreateErrorInfo : IUnknown
	{
	public:
		//Virtual
		struct SetGUID
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICreateErrorInfo* pThis;
			const ::GUID& rguid;
		};

		//Virtual
		struct SetSource
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICreateErrorInfo* pThis;
			::LPOLESTR szSource;
		};

		//Virtual
		struct SetDescription
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICreateErrorInfo* pThis;
			::LPOLESTR szDescription;
		};

		//Virtual
		struct SetHelpFile
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICreateErrorInfo* pThis;
			::LPOLESTR szHelpFile;
		};

		//Virtual
		struct SetHelpContext
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICreateErrorInfo* pThis;
			::DWORD dwHelpContext;
		};

	private:
		 virtual ~ICreateErrorInfo() = 0;
	};

	class ISupportErrorInfo : IUnknown
	{
	public:
		//Virtual
		struct InterfaceSupportsErrorInfo
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ISupportErrorInfo* pThis;
			const ::IID& riid;
		};

	private:
		 virtual ~ISupportErrorInfo() = 0;
	};

	class ITypeFactory : IUnknown
	{
	public:
		//Virtual
		struct CreateFromTypeInfo
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ITypeFactory* pThis;
			::ITypeInfo* pTypeInfo;
			const ::IID& riid;
			::IUnknown** ppv;
		};

	private:
		 virtual ~ITypeFactory() = 0;
	};

	class ITypeMarshal : IUnknown
	{
	public:
		//Virtual
		struct Size
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ITypeMarshal* pThis;
			::PVOID pvType;
			::DWORD dwDestContext;
			::PVOID pvDestContext;
			::ULONG* pSize;
		};

		//Virtual
		struct Marshal
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 7;

			::ITypeMarshal* pThis;
			::PVOID pvType;
			::DWORD dwDestContext;
			::PVOID pvDestContext;
			::ULONG cbBufferLength;
			::BYTE* pBuffer;
			::ULONG* pcbWritten;
		};

		//Virtual
		struct Unmarshal
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::ITypeMarshal* pThis;
			::PVOID pvType;
			::DWORD dwFlags;
			::ULONG cbBufferLength;
			::BYTE* pBuffer;
			::ULONG* pcbRead;
		};

		//Virtual
		struct Free
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ITypeMarshal* pThis;
			::PVOID pvType;
		};

	private:
		 virtual ~ITypeMarshal() = 0;
	};

	class IRecordInfo : IUnknown
	{
	public:
		//Virtual
		struct RecordInit
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IRecordInfo* pThis;
			::PVOID pvNew;
		};

		//Virtual
		struct RecordClear
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IRecordInfo* pThis;
			::PVOID pvExisting;
		};

		//Virtual
		struct RecordCopy
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IRecordInfo* pThis;
			::PVOID pvExisting;
			::PVOID pvNew;
		};

		//Virtual
		struct GetGuid
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IRecordInfo* pThis;
			::GUID* pguid;
		};

		//Virtual
		struct GetName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IRecordInfo* pThis;
			::BSTR* pbstrName;
		};

		//Virtual
		struct GetSize
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IRecordInfo* pThis;
			::ULONG* pcbSize;
		};

		//Virtual
		struct GetTypeInfo
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IRecordInfo* pThis;
			::ITypeInfo** ppTypeInfo;
		};

		//Virtual
		struct GetField
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IRecordInfo* pThis;
			::PVOID pvData;
			::LPCOLESTR szFieldName;
			::VARIANT* pvarField;
		};

		//Virtual
		struct GetFieldNoCopy
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IRecordInfo* pThis;
			::PVOID pvData;
			::LPCOLESTR szFieldName;
			::VARIANT* pvarField;
			::PVOID* ppvDataCArray;
		};

		//Virtual
		struct PutField
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IRecordInfo* pThis;
			::ULONG wFlags;
			::PVOID pvData;
			::LPCOLESTR szFieldName;
			::VARIANT* pvarField;
		};

		//Virtual
		struct PutFieldNoCopy
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IRecordInfo* pThis;
			::ULONG wFlags;
			::PVOID pvData;
			::LPCOLESTR szFieldName;
			::VARIANT* pvarField;
		};

		//Virtual
		struct GetFieldNames
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IRecordInfo* pThis;
			::ULONG* pcNames;
			::BSTR* rgBstrNames;
		};

		//Virtual
		struct IsMatchingType
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 2;

			::IRecordInfo* pThis;
			::IRecordInfo* pRecordInfo;
		};

		//Virtual
		struct RecordCreate
		{
			using ReturnType_t = ::PVOID;
			static constexpr size_t Argc = 1;

			::IRecordInfo* pThis;
		};

		//Virtual
		struct RecordCreateCopy
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IRecordInfo* pThis;
			::PVOID pvSource;
			::PVOID* ppvDest;
		};

		//Virtual
		struct RecordDestroy
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IRecordInfo* pThis;
			::PVOID pvRecord;
		};

	private:
		 virtual ~IRecordInfo() = 0;
	};

	class IErrorLog : IUnknown
	{
	public:
		//Virtual
		struct AddError
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IErrorLog* pThis;
			::LPCOLESTR pszPropName;
			::EXCEPINFO* pExcepInfo;
		};

	private:
		 virtual ~IErrorLog() = 0;
	};

	class IPropertyBag : IUnknown
	{
	public:
		//Virtual
		struct Read
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IPropertyBag* pThis;
			::LPCOLESTR pszPropName;
			::VARIANT* pVar;
			::IErrorLog* pErrorLog;
		};

		//Virtual
		struct Write
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IPropertyBag* pThis;
			::LPCOLESTR pszPropName;
			::VARIANT* pVar;
		};

	private:
		 virtual ~IPropertyBag() = 0;
	};

	class ITypeLibRegistrationReader : IUnknown
	{
	public:
		//Virtual
		struct EnumTypeLibRegistrations
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ITypeLibRegistrationReader* pThis;
			::IEnumUnknown** ppEnumUnknown;
		};

	private:
		 virtual ~ITypeLibRegistrationReader() = 0;
	};

	class ITypeLibRegistration : IUnknown
	{
	public:
		//Virtual
		struct GetGuid
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ITypeLibRegistration* pThis;
			::GUID* pGuid;
		};

		//Virtual
		struct GetVersion
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ITypeLibRegistration* pThis;
			::BSTR* pVersion;
		};

		//Virtual
		struct GetLcid
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ITypeLibRegistration* pThis;
			::LCID* pLcid;
		};

		//Virtual
		struct GetWin32Path
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ITypeLibRegistration* pThis;
			::BSTR* pWin32Path;
		};

		//Virtual
		struct GetWin64Path
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ITypeLibRegistration* pThis;
			::BSTR* pWin64Path;
		};

		//Virtual
		struct GetDisplayName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ITypeLibRegistration* pThis;
			::BSTR* pDisplayName;
		};

		//Virtual
		struct GetFlags
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ITypeLibRegistration* pThis;
			::DWORD* pFlags;
		};

		//Virtual
		struct GetHelpDir
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ITypeLibRegistration* pThis;
			::BSTR* pHelpDir;
		};

	private:
		 virtual ~ITypeLibRegistration() = 0;
	};

	class IPropertyStorage : IUnknown
	{
	public:
		//Virtual
		struct ReadMultiple
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IPropertyStorage* pThis;
			::ULONG cpspec;
			const ::PROPSPEC* rgpspec;
			::PROPVARIANT* rgpropvar;
		};

		//Virtual
		struct WriteMultiple
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IPropertyStorage* pThis;
			::ULONG cpspec;
			const ::PROPSPEC* rgpspec;
			const ::PROPVARIANT* rgpropvar;
			::PROPID propidNameFirst;
		};

		//Virtual
		struct DeleteMultiple
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IPropertyStorage* pThis;
			::ULONG cpspec;
			const ::PROPSPEC* rgpspec;
		};

		//Virtual
		struct ReadPropertyNames
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IPropertyStorage* pThis;
			::ULONG cpropid;
			const ::PROPID* rgpropid;
			::LPOLESTR* rglpwstrName;
		};

		//Virtual
		struct WritePropertyNames
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IPropertyStorage* pThis;
			::ULONG cpropid;
			const ::PROPID* rgpropid;
			const ::LPOLESTR* rglpwstrName;
		};

		//Virtual
		struct DeletePropertyNames
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IPropertyStorage* pThis;
			::ULONG cpropid;
			const ::PROPID* rgpropid;
		};

		//Virtual
		struct Commit
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPropertyStorage* pThis;
			::DWORD grfCommitFlags;
		};

		//Virtual
		struct Revert
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IPropertyStorage* pThis;
		};

		//Virtual
		struct Enum
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPropertyStorage* pThis;
			::IEnumSTATPROPSTG** ppenum;
		};

		//Virtual
		struct SetTimes
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IPropertyStorage* pThis;
			const ::FILETIME* pctime;
			const ::FILETIME* patime;
			const ::FILETIME* pmtime;
		};

		//Virtual
		struct SetClass
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPropertyStorage* pThis;
			const ::IID& clsid;
		};

		//Virtual
		struct Stat
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPropertyStorage* pThis;
			::STATPROPSETSTG* pstatpsstg;
		};

	private:
		 virtual ~IPropertyStorage() = 0;
	};

	class IPropertySetStorage : IUnknown
	{
	public:
		//Virtual
		struct Create
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IPropertySetStorage* pThis;
			const ::IID& rfmtid;
			const ::CLSID* pclsid;
			::DWORD grfFlags;
			::DWORD grfMode;
			::IPropertyStorage** ppprstg;
		};

		//Virtual
		struct Open
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IPropertySetStorage* pThis;
			const ::IID& rfmtid;
			::DWORD grfMode;
			::IPropertyStorage** ppprstg;
		};

		//Virtual
		struct Delete
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPropertySetStorage* pThis;
			const ::IID& rfmtid;
		};

		//Virtual
		struct Enum
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPropertySetStorage* pThis;
			::IEnumSTATPROPSETSTG** ppenum;
		};

	private:
		 virtual ~IPropertySetStorage() = 0;
	};

	class IEnumSTATPROPSTG : IUnknown
	{
	public:
		//Virtual
		struct Next
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IEnumSTATPROPSTG* pThis;
			::ULONG celt;
			::STATPROPSTG* rgelt;
			::ULONG* pceltFetched;
		};

		//Virtual
		struct Skip
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IEnumSTATPROPSTG* pThis;
			::ULONG celt;
		};

		//Virtual
		struct Reset
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IEnumSTATPROPSTG* pThis;
		};

		//Virtual
		struct Clone
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IEnumSTATPROPSTG* pThis;
			::IEnumSTATPROPSTG** ppenum;
		};

	private:
		 virtual ~IEnumSTATPROPSTG() = 0;
	};

	class IEnumSTATPROPSETSTG : IUnknown
	{
	public:
		//Virtual
		struct Next
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IEnumSTATPROPSETSTG* pThis;
			::ULONG celt;
			::STATPROPSETSTG* rgelt;
			::ULONG* pceltFetched;
		};

		//Virtual
		struct Skip
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IEnumSTATPROPSETSTG* pThis;
			::ULONG celt;
		};

		//Virtual
		struct Reset
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IEnumSTATPROPSETSTG* pThis;
		};

		//Virtual
		struct Clone
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IEnumSTATPROPSETSTG* pThis;
			::IEnumSTATPROPSETSTG** ppenum;
		};

	private:
		 virtual ~IEnumSTATPROPSETSTG() = 0;
	};

	class IOleAdviseHolder : IUnknown
	{
	public:
		//Virtual
		struct Advise
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IOleAdviseHolder* pThis;
			::IAdviseSink* pAdvise;
			::DWORD* pdwConnection;
		};

		//Virtual
		struct Unadvise
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleAdviseHolder* pThis;
			::DWORD dwConnection;
		};

		//Virtual
		struct EnumAdvise
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleAdviseHolder* pThis;
			::IEnumSTATDATA** ppenumAdvise;
		};

		//Virtual
		struct SendOnRename
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleAdviseHolder* pThis;
			::IMoniker* pmk;
		};

		//Virtual
		struct SendOnSave
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IOleAdviseHolder* pThis;
		};

		//Virtual
		struct SendOnClose
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IOleAdviseHolder* pThis;
		};

	private:
		 virtual ~IOleAdviseHolder() = 0;
	};

	class IOleCache : IUnknown
	{
	public:
		//Virtual
		struct Cache
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IOleCache* pThis;
			::FORMATETC* pformatetc;
			::DWORD advf;
			::DWORD* pdwConnection;
		};

		//Virtual
		struct Uncache
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleCache* pThis;
			::DWORD dwConnection;
		};

		//Virtual
		struct EnumCache
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleCache* pThis;
			::IEnumSTATDATA** ppenumSTATDATA;
		};

		//Virtual
		struct InitCache
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleCache* pThis;
			::IDataObject* pDataObject;
		};

		//Virtual
		struct SetData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IOleCache* pThis;
			::FORMATETC* pformatetc;
			::STGMEDIUM* pmedium;
			::BOOL fRelease;
		};

	private:
		 virtual ~IOleCache() = 0;
	};

	class IOleCache2 : IOleCache
	{
	public:
		//Virtual
		struct UpdateCache
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IOleCache2* pThis;
			::LPDATAOBJECT pDataObject;
			::DWORD grfUpdf;
			::LPVOID pReserved;
		};

		//Virtual
		struct DiscardCache
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleCache2* pThis;
			::DWORD dwDiscardOptions;
		};

	private:
		 virtual ~IOleCache2() = 0;
	};

	class IOleCacheControl : IUnknown
	{
	public:
		//Virtual
		struct OnRun
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleCacheControl* pThis;
			::LPDATAOBJECT pDataObject;
		};

		//Virtual
		struct OnStop
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IOleCacheControl* pThis;
		};

	private:
		 virtual ~IOleCacheControl() = 0;
	};

	class IParseDisplayName : IUnknown
	{
	public:
		//Virtual
		struct ParseDisplayName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IParseDisplayName* pThis;
			::IBindCtx* pbc;
			::LPOLESTR pszDisplayName;
			::ULONG* pchEaten;
			::IMoniker** ppmkOut;
		};

	private:
		 virtual ~IParseDisplayName() = 0;
	};

	class IOleContainer : IParseDisplayName
	{
	public:
		//Virtual
		struct EnumObjects
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IOleContainer* pThis;
			::DWORD grfFlags;
			::IEnumUnknown** ppenum;
		};

		//Virtual
		struct LockContainer
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleContainer* pThis;
			::BOOL fLock;
		};

	private:
		 virtual ~IOleContainer() = 0;
	};

	class IOleClientSite : IUnknown
	{
	public:
		//Virtual
		struct SaveObject
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IOleClientSite* pThis;
		};

		//Virtual
		struct GetMoniker
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IOleClientSite* pThis;
			::DWORD dwAssign;
			::DWORD dwWhichMoniker;
			::IMoniker** ppmk;
		};

		//Virtual
		struct GetContainer
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleClientSite* pThis;
			::IOleContainer** ppContainer;
		};

		//Virtual
		struct ShowObject
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IOleClientSite* pThis;
		};

		//Virtual
		struct OnShowWindow
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleClientSite* pThis;
			::BOOL fShow;
		};

		//Virtual
		struct RequestNewObjectLayout
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IOleClientSite* pThis;
		};

	private:
		 virtual ~IOleClientSite() = 0;
	};

	class IOleObject : IUnknown
	{
	public:
		//Virtual
		struct SetClientSite
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleObject* pThis;
			::IOleClientSite* pClientSite;
		};

		//Virtual
		struct GetClientSite
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleObject* pThis;
			::IOleClientSite** ppClientSite;
		};

		//Virtual
		struct SetHostNames
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IOleObject* pThis;
			::LPCOLESTR szContainerApp;
			::LPCOLESTR szContainerObj;
		};

		//Virtual
		struct Close
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleObject* pThis;
			::DWORD dwSaveOption;
		};

		//Virtual
		struct SetMoniker
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IOleObject* pThis;
			::DWORD dwWhichMoniker;
			::IMoniker* pmk;
		};

		//Virtual
		struct GetMoniker
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IOleObject* pThis;
			::DWORD dwAssign;
			::DWORD dwWhichMoniker;
			::IMoniker** ppmk;
		};

		//Virtual
		struct InitFromData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IOleObject* pThis;
			::IDataObject* pDataObject;
			::BOOL fCreation;
			::DWORD dwReserved;
		};

		//Virtual
		struct GetClipboardData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IOleObject* pThis;
			::DWORD dwReserved;
			::IDataObject** ppDataObject;
		};

		//Virtual
		struct DoVerb
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 7;

			::IOleObject* pThis;
			::LONG iVerb;
			::LPMSG lpmsg;
			::IOleClientSite* pActiveSite;
			::LONG lindex;
			::HWND hwndParent;
			::LPCRECT lprcPosRect;
		};

		//Virtual
		struct EnumVerbs
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleObject* pThis;
			::IEnumOLEVERB** ppEnumOleVerb;
		};

		//Virtual
		struct Update
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IOleObject* pThis;
		};

		//Virtual
		struct IsUpToDate
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IOleObject* pThis;
		};

		//Virtual
		struct GetUserClassID
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleObject* pThis;
			::CLSID* pClsid;
		};

		//Virtual
		struct GetUserType
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IOleObject* pThis;
			::DWORD dwFormOfType;
			::LPOLESTR* pszUserType;
		};

		//Virtual
		struct SetExtent
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IOleObject* pThis;
			::DWORD dwDrawAspect;
			::SIZEL* psizel;
		};

		//Virtual
		struct GetExtent
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IOleObject* pThis;
			::DWORD dwDrawAspect;
			::SIZEL* psizel;
		};

		//Virtual
		struct Advise
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IOleObject* pThis;
			::IAdviseSink* pAdvSink;
			::DWORD* pdwConnection;
		};

		//Virtual
		struct Unadvise
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleObject* pThis;
			::DWORD dwConnection;
		};

		//Virtual
		struct EnumAdvise
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleObject* pThis;
			::IEnumSTATDATA** ppenumAdvise;
		};

		//Virtual
		struct GetMiscStatus
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IOleObject* pThis;
			::DWORD dwAspect;
			::DWORD* pdwStatus;
		};

		//Virtual
		struct SetColorScheme
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleObject* pThis;
			::LOGPALETTE* pLogpal;
		};

	private:
		 virtual ~IOleObject() = 0;
	};

	class IOleWindow : IUnknown
	{
	public:
		//Virtual
		struct GetWindow
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleWindow* pThis;
			::HWND* phwnd;
		};

		//Virtual
		struct ContextSensitiveHelp
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleWindow* pThis;
			::BOOL fEnterMode;
		};

	private:
		 virtual ~IOleWindow() = 0;
	};

	class IOleLink : IUnknown
	{
	public:
		//Virtual
		struct SetUpdateOptions
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleLink* pThis;
			::DWORD dwUpdateOpt;
		};

		//Virtual
		struct GetUpdateOptions
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleLink* pThis;
			::DWORD* pdwUpdateOpt;
		};

		//Virtual
		struct SetSourceMoniker
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IOleLink* pThis;
			::IMoniker* pmk;
			const ::IID& rclsid;
		};

		//Virtual
		struct GetSourceMoniker
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleLink* pThis;
			::IMoniker** ppmk;
		};

		//Virtual
		struct SetSourceDisplayName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleLink* pThis;
			::LPCOLESTR pszStatusText;
		};

		//Virtual
		struct GetSourceDisplayName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleLink* pThis;
			::LPOLESTR* ppszDisplayName;
		};

		//Virtual
		struct BindToSource
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IOleLink* pThis;
			::DWORD bindflags;
			::IBindCtx* pbc;
		};

		//Virtual
		struct BindIfRunning
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IOleLink* pThis;
		};

		//Virtual
		struct GetBoundSource
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleLink* pThis;
			::IUnknown** ppunk;
		};

		//Virtual
		struct UnbindSource
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IOleLink* pThis;
		};

		//Virtual
		struct Update
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleLink* pThis;
			::IBindCtx* pbc;
		};

	private:
		 virtual ~IOleLink() = 0;
	};

	class IOleItemContainer : IOleContainer
	{
	public:
		//Virtual
		struct GetObjectA
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IOleItemContainer* pThis;
			::LPOLESTR pszItem;
			::DWORD dwSpeedNeeded;
			::IBindCtx* pbc;
			const ::IID& riid;
			void** ppvObject;
		};

		//Virtual
		struct GetObjectStorage
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IOleItemContainer* pThis;
			::LPOLESTR pszItem;
			::IBindCtx* pbc;
			const ::IID& riid;
			void** ppvStorage;
		};

		//Virtual
		struct IsRunning
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleItemContainer* pThis;
			::LPOLESTR pszItem;
		};

	private:
		 virtual ~IOleItemContainer() = 0;
	};

	class IOleInPlaceUIWindow : IOleWindow
	{
	public:
		//Virtual
		struct GetBorder
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleInPlaceUIWindow* pThis;
			::LPRECT lprectBorder;
		};

		//Virtual
		struct RequestBorderSpace
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleInPlaceUIWindow* pThis;
			::LPCBORDERWIDTHS pborderwidths;
		};

		//Virtual
		struct SetBorderSpace
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleInPlaceUIWindow* pThis;
			::LPCBORDERWIDTHS pborderwidths;
		};

		//Virtual
		struct SetActiveObject
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IOleInPlaceUIWindow* pThis;
			::IOleInPlaceActiveObject* pActiveObject;
			::LPCOLESTR pszObjName;
		};

	private:
		 virtual ~IOleInPlaceUIWindow() = 0;
	};

	class IOleInPlaceActiveObject : IOleWindow
	{
	public:
		//Virtual
		struct TranslateAcceleratorA
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleInPlaceActiveObject* pThis;
			::LPMSG lpmsg;
		};

		//Virtual
		struct OnFrameWindowActivate
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleInPlaceActiveObject* pThis;
			::BOOL fActivate;
		};

		//Virtual
		struct OnDocWindowActivate
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleInPlaceActiveObject* pThis;
			::BOOL fActivate;
		};

		//Virtual
		struct ResizeBorder
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IOleInPlaceActiveObject* pThis;
			::LPCRECT prcBorder;
			::IOleInPlaceUIWindow* pUIWindow;
			::BOOL fFrameWindow;
		};

		//Virtual
		struct EnableModeless
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleInPlaceActiveObject* pThis;
			::BOOL fEnable;
		};

	private:
		 virtual ~IOleInPlaceActiveObject() = 0;
	};

	class IOleInPlaceFrame : IOleInPlaceUIWindow
	{
	public:
		//Virtual
		struct InsertMenus
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IOleInPlaceFrame* pThis;
			::HMENU hmenuShared;
			::LPOLEMENUGROUPWIDTHS lpMenuWidths;
		};

		//Virtual
		struct SetMenu
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IOleInPlaceFrame* pThis;
			::HMENU hmenuShared;
			::HOLEMENU holemenu;
			::HWND hwndActiveObject;
		};

		//Virtual
		struct RemoveMenus
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleInPlaceFrame* pThis;
			::HMENU hmenuShared;
		};

		//Virtual
		struct SetStatusText
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleInPlaceFrame* pThis;
			::LPCOLESTR pszStatusText;
		};

		//Virtual
		struct EnableModeless
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleInPlaceFrame* pThis;
			::BOOL fEnable;
		};

		//Virtual
		struct TranslateAcceleratorA
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IOleInPlaceFrame* pThis;
			::LPMSG lpmsg;
			::WORD wID;
		};

	private:
		 virtual ~IOleInPlaceFrame() = 0;
	};

	class IOleInPlaceObject : IOleWindow
	{
	public:
		//Virtual
		struct InPlaceDeactivate
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IOleInPlaceObject* pThis;
		};

		//Virtual
		struct UIDeactivate
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IOleInPlaceObject* pThis;
		};

		//Virtual
		struct SetObjectRects
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IOleInPlaceObject* pThis;
			::LPCRECT lprcPosRect;
			::LPCRECT lprcClipRect;
		};

		//Virtual
		struct ReactivateAndUndo
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IOleInPlaceObject* pThis;
		};

	private:
		 virtual ~IOleInPlaceObject() = 0;
	};

	class IOleInPlaceSite : IOleWindow
	{
	public:
		//Virtual
		struct CanInPlaceActivate
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IOleInPlaceSite* pThis;
		};

		//Virtual
		struct OnInPlaceActivate
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IOleInPlaceSite* pThis;
		};

		//Virtual
		struct OnUIActivate
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IOleInPlaceSite* pThis;
		};

		//Virtual
		struct GetWindowContext
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IOleInPlaceSite* pThis;
			::IOleInPlaceFrame** ppFrame;
			::IOleInPlaceUIWindow** ppDoc;
			::LPRECT lprcPosRect;
			::LPRECT lprcClipRect;
			::LPOLEINPLACEFRAMEINFO lpFrameInfo;
		};

		//Virtual
		struct Scroll
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleInPlaceSite* pThis;
			::SIZE scrollExtant;
		};

		//Virtual
		struct OnUIDeactivate
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleInPlaceSite* pThis;
			::BOOL fUndoable;
		};

		//Virtual
		struct OnInPlaceDeactivate
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IOleInPlaceSite* pThis;
		};

		//Virtual
		struct DiscardUndoState
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IOleInPlaceSite* pThis;
		};

		//Virtual
		struct DeactivateAndUndo
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IOleInPlaceSite* pThis;
		};

		//Virtual
		struct OnPosRectChange
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleInPlaceSite* pThis;
			::LPCRECT lprcPosRect;
		};

	private:
		 virtual ~IOleInPlaceSite() = 0;
	};

	class IContinue : IUnknown
	{
	public:
		//Virtual
		struct FContinue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IContinue* pThis;
		};

	private:
		 virtual ~IContinue() = 0;
	};

	class IViewObject : IUnknown
	{
	public:
		//Virtual
		struct Draw
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 11;

			::IViewObject* pThis;
			::DWORD dwDrawAspect;
			::LONG lindex;
			void* pvAspect;
			::DVTARGETDEVICE* ptd;
			::HDC hdcTargetDev;
			::HDC hdcDraw;
			::LPCRECTL lprcBounds;
			::LPCRECTL lprcWBounds;
			::BOOL (_stdcall* pfnContinue)(ULONG_PTR);
			::ULONG_PTR dwContinue;
		};

		//Virtual
		struct GetColorSet
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 7;

			::IViewObject* pThis;
			::DWORD dwDrawAspect;
			::LONG lindex;
			void* pvAspect;
			::DVTARGETDEVICE* ptd;
			::HDC hicTargetDev;
			::LOGPALETTE** ppColorSet;
		};

		//Virtual
		struct Freeze
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IViewObject* pThis;
			::DWORD dwDrawAspect;
			::LONG lindex;
			void* pvAspect;
			::DWORD* pdwFreeze;
		};

		//Virtual
		struct Unfreeze
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IViewObject* pThis;
			::DWORD dwFreeze;
		};

		//Virtual
		struct SetAdvise
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IViewObject* pThis;
			::DWORD aspects;
			::DWORD advf;
			::IAdviseSink* pAdvSink;
		};

		//Virtual
		struct GetAdvise
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IViewObject* pThis;
			::DWORD* pAspects;
			::DWORD* pAdvf;
			::IAdviseSink** ppAdvSink;
		};

	private:
		 virtual ~IViewObject() = 0;
	};

	class IViewObject2 : IViewObject
	{
	public:
		//Virtual
		struct GetExtent
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IViewObject2* pThis;
			::DWORD dwDrawAspect;
			::LONG lindex;
			::DVTARGETDEVICE* ptd;
			::LPSIZEL lpsizel;
		};

	private:
		 virtual ~IViewObject2() = 0;
	};

	class IDropSource : IUnknown
	{
	public:
		//Virtual
		struct QueryContinueDrag
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDropSource* pThis;
			::BOOL fEscapePressed;
			::DWORD grfKeyState;
		};

		//Virtual
		struct GiveFeedback
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDropSource* pThis;
			::DWORD dwEffect;
		};

	private:
		 virtual ~IDropSource() = 0;
	};

	class IDropTarget : IUnknown
	{
	public:
		//Virtual
		struct DragEnter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IDropTarget* pThis;
			::IDataObject* pDataObj;
			::DWORD grfKeyState;
			::POINTL pt;
			::DWORD* pdwEffect;
		};

		//Virtual
		struct DragOver
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IDropTarget* pThis;
			::DWORD grfKeyState;
			::POINTL pt;
			::DWORD* pdwEffect;
		};

		//Virtual
		struct DragLeave
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IDropTarget* pThis;
		};

		//Virtual
		struct Drop
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IDropTarget* pThis;
			::IDataObject* pDataObj;
			::DWORD grfKeyState;
			::POINTL pt;
			::DWORD* pdwEffect;
		};

	private:
		 virtual ~IDropTarget() = 0;
	};

	class IDropSourceNotify : IUnknown
	{
	public:
		//Virtual
		struct DragEnterTarget
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDropSourceNotify* pThis;
			::HWND hwndTarget;
		};

		//Virtual
		struct DragLeaveTarget
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IDropSourceNotify* pThis;
		};

	private:
		 virtual ~IDropSourceNotify() = 0;
	};

	class IEnterpriseDropTarget : IUnknown
	{
	public:
		//Virtual
		struct SetDropSourceEnterpriseId
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IEnterpriseDropTarget* pThis;
			::LPCWSTR identity;
		};

		//Virtual
		struct IsEvaluatingEdpPolicy
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IEnterpriseDropTarget* pThis;
			::BOOL* value;
		};

	private:
		 virtual ~IEnterpriseDropTarget() = 0;
	};

	class IEnumOLEVERB : IUnknown
	{
	public:
		//Virtual
		struct Next
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IEnumOLEVERB* pThis;
			::ULONG celt;
			::LPOLEVERB rgelt;
			::ULONG* pceltFetched;
		};

		//Virtual
		struct Skip
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IEnumOLEVERB* pThis;
			::ULONG celt;
		};

		//Virtual
		struct Reset
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IEnumOLEVERB* pThis;
		};

		//Virtual
		struct Clone
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IEnumOLEVERB* pThis;
			::IEnumOLEVERB** ppenum;
		};

	private:
		 virtual ~IEnumOLEVERB() = 0;
	};

	class IServiceProvider : IUnknown
	{
	public:
		//Virtual
		struct QueryService
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IServiceProvider* pThis;
			const ::GUID& guidService;
			const ::IID& riid;
			void** ppvObject;
		};

	private:
		 virtual ~IServiceProvider() = 0;
	};

	class IXMLDOMImplementation : IDispatch
	{
	public:
		//Virtual
		struct hasFeature
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IXMLDOMImplementation* pThis;
			::BSTR feature;
			::BSTR version;
			::VARIANT_BOOL* hasFeature;
		};

	private:
		 virtual ~IXMLDOMImplementation() = 0;
	};

	class IXMLDOMNode : IDispatch
	{
	public:
		//Virtual
		struct get_nodeName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNode* pThis;
			::BSTR* name;
		};

		//Virtual
		struct get_nodeValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNode* pThis;
			::VARIANT* value;
		};

		//Virtual
		struct put_nodeValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNode* pThis;
			::VARIANT value;
		};

		//Virtual
		struct get_nodeType
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNode* pThis;
			::DOMNodeType* type;
		};

		//Virtual
		struct get_parentNode
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNode* pThis;
			::IXMLDOMNode** parent;
		};

		//Virtual
		struct get_childNodes
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNode* pThis;
			::IXMLDOMNodeList** childList;
		};

		//Virtual
		struct get_firstChild
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNode* pThis;
			::IXMLDOMNode** firstChild;
		};

		//Virtual
		struct get_lastChild
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNode* pThis;
			::IXMLDOMNode** lastChild;
		};

		//Virtual
		struct get_previousSibling
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNode* pThis;
			::IXMLDOMNode** previousSibling;
		};

		//Virtual
		struct get_nextSibling
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNode* pThis;
			::IXMLDOMNode** nextSibling;
		};

		//Virtual
		struct get_attributes
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNode* pThis;
			::IXMLDOMNamedNodeMap** attributeMap;
		};

		//Virtual
		struct insertBefore
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IXMLDOMNode* pThis;
			::IXMLDOMNode* newChild;
			::VARIANT refChild;
			::IXMLDOMNode** outNewChild;
		};

		//Virtual
		struct replaceChild
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IXMLDOMNode* pThis;
			::IXMLDOMNode* newChild;
			::IXMLDOMNode* oldChild;
			::IXMLDOMNode** outOldChild;
		};

		//Virtual
		struct removeChild
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLDOMNode* pThis;
			::IXMLDOMNode* childNode;
			::IXMLDOMNode** oldChild;
		};

		//Virtual
		struct appendChild
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLDOMNode* pThis;
			::IXMLDOMNode* newChild;
			::IXMLDOMNode** outNewChild;
		};

		//Virtual
		struct hasChildNodes
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNode* pThis;
			::VARIANT_BOOL* hasChild;
		};

		//Virtual
		struct get_ownerDocument
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNode* pThis;
			::IXMLDOMDocument** XMLDOMDocument;
		};

		//Virtual
		struct cloneNode
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLDOMNode* pThis;
			::VARIANT_BOOL deep;
			::IXMLDOMNode** cloneRoot;
		};

		//Virtual
		struct get_nodeTypeString
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNode* pThis;
			::BSTR* nodeType;
		};

		//Virtual
		struct get_text
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNode* pThis;
			::BSTR* text;
		};

		//Virtual
		struct put_text
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNode* pThis;
			::BSTR text;
		};

		//Virtual
		struct get_specified
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNode* pThis;
			::VARIANT_BOOL* isSpecified;
		};

		//Virtual
		struct get_definition
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNode* pThis;
			::IXMLDOMNode** definitionNode;
		};

		//Virtual
		struct get_nodeTypedValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNode* pThis;
			::VARIANT* typedValue;
		};

		//Virtual
		struct put_nodeTypedValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNode* pThis;
			::VARIANT typedValue;
		};

		//Virtual
		struct get_dataType
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNode* pThis;
			::VARIANT* dataTypeName;
		};

		//Virtual
		struct put_dataType
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNode* pThis;
			::BSTR dataTypeName;
		};

		//Virtual
		struct get_xml
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNode* pThis;
			::BSTR* xmlString;
		};

		//Virtual
		struct transformNode
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLDOMNode* pThis;
			::IXMLDOMNode* stylesheet;
			::BSTR* xmlString;
		};

		//Virtual
		struct selectNodes
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLDOMNode* pThis;
			::BSTR queryString;
			::IXMLDOMNodeList** resultList;
		};

		//Virtual
		struct selectSingleNode
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLDOMNode* pThis;
			::BSTR queryString;
			::IXMLDOMNode** resultNode;
		};

		//Virtual
		struct get_parsed
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNode* pThis;
			::VARIANT_BOOL* isParsed;
		};

		//Virtual
		struct get_namespaceURI
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNode* pThis;
			::BSTR* namespaceURI;
		};

		//Virtual
		struct get_prefix
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNode* pThis;
			::BSTR* prefixString;
		};

		//Virtual
		struct get_baseName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNode* pThis;
			::BSTR* nameString;
		};

		//Virtual
		struct transformNodeToObject
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLDOMNode* pThis;
			::IXMLDOMNode* stylesheet;
			::VARIANT outputObject;
		};

	private:
		 virtual ~IXMLDOMNode() = 0;
	};

	class IXMLDOMDocument : IXMLDOMNode
	{
	public:
		//Virtual
		struct get_doctype
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMDocument* pThis;
			::IXMLDOMDocumentType** documentType;
		};

		//Virtual
		struct get_implementation
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMDocument* pThis;
			::IXMLDOMImplementation** impl;
		};

		//Virtual
		struct get_documentElement
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMDocument* pThis;
			::IXMLDOMElement** DOMElement;
		};

		//Virtual
		struct putref_documentElement
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMDocument* pThis;
			::IXMLDOMElement* DOMElement;
		};

		//Virtual
		struct createElement
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLDOMDocument* pThis;
			::BSTR tagName;
			::IXMLDOMElement** element;
		};

		//Virtual
		struct createDocumentFragment
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMDocument* pThis;
			::IXMLDOMDocumentFragment** docFrag;
		};

		//Virtual
		struct createTextNode
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLDOMDocument* pThis;
			::BSTR data;
			::IXMLDOMText** text;
		};

		//Virtual
		struct createComment
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLDOMDocument* pThis;
			::BSTR data;
			::IXMLDOMComment** comment;
		};

		//Virtual
		struct createCDATASection
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLDOMDocument* pThis;
			::BSTR data;
			::IXMLDOMCDATASection** cdata;
		};

		//Virtual
		struct createProcessingInstruction
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IXMLDOMDocument* pThis;
			::BSTR target;
			::BSTR data;
			::IXMLDOMProcessingInstruction** pi;
		};

		//Virtual
		struct createAttribute
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLDOMDocument* pThis;
			::BSTR name;
			::IXMLDOMAttribute** attribute;
		};

		//Virtual
		struct createEntityReference
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLDOMDocument* pThis;
			::BSTR name;
			::IXMLDOMEntityReference** entityRef;
		};

		//Virtual
		struct getElementsByTagName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLDOMDocument* pThis;
			::BSTR tagName;
			::IXMLDOMNodeList** resultList;
		};

		//Virtual
		struct createNode
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IXMLDOMDocument* pThis;
			::VARIANT Type;
			::BSTR name;
			::BSTR namespaceURI;
			::IXMLDOMNode** node;
		};

		//Virtual
		struct nodeFromID
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLDOMDocument* pThis;
			::BSTR idString;
			::IXMLDOMNode** node;
		};

		//Virtual
		struct load
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLDOMDocument* pThis;
			::VARIANT xmlSource;
			::VARIANT_BOOL* isSuccessful;
		};

		//Virtual
		struct get_readyState
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMDocument* pThis;
			long* value;
		};

		//Virtual
		struct get_parseError
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMDocument* pThis;
			::IXMLDOMParseError** errorObj;
		};

		//Virtual
		struct get_url
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMDocument* pThis;
			::BSTR* urlString;
		};

		//Virtual
		struct get_async
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMDocument* pThis;
			::VARIANT_BOOL* isAsync;
		};

		//Virtual
		struct put_async
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMDocument* pThis;
			::VARIANT_BOOL isAsync;
		};

		//Virtual
		struct abort
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IXMLDOMDocument* pThis;
		};

		//Virtual
		struct loadXML
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLDOMDocument* pThis;
			::BSTR bstrXML;
			::VARIANT_BOOL* isSuccessful;
		};

		//Virtual
		struct save
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMDocument* pThis;
			::VARIANT destination;
		};

		//Virtual
		struct get_validateOnParse
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMDocument* pThis;
			::VARIANT_BOOL* isValidating;
		};

		//Virtual
		struct put_validateOnParse
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMDocument* pThis;
			::VARIANT_BOOL isValidating;
		};

		//Virtual
		struct get_resolveExternals
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMDocument* pThis;
			::VARIANT_BOOL* isResolving;
		};

		//Virtual
		struct put_resolveExternals
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMDocument* pThis;
			::VARIANT_BOOL isResolving;
		};

		//Virtual
		struct get_preserveWhiteSpace
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMDocument* pThis;
			::VARIANT_BOOL* isPreserving;
		};

		//Virtual
		struct put_preserveWhiteSpace
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMDocument* pThis;
			::VARIANT_BOOL isPreserving;
		};

		//Virtual
		struct put_onreadystatechange
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMDocument* pThis;
			::VARIANT readystatechangeSink;
		};

		//Virtual
		struct put_ondataavailable
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMDocument* pThis;
			::VARIANT ondataavailableSink;
		};

		//Virtual
		struct put_ontransformnode
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMDocument* pThis;
			::VARIANT ontransformnodeSink;
		};

	private:
		 virtual ~IXMLDOMDocument() = 0;
	};

	class IXMLDOMNodeList : IDispatch
	{
	public:
		//Virtual
		struct get_item
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLDOMNodeList* pThis;
			long index;
			::IXMLDOMNode** listItem;
		};

		//Virtual
		struct get_length
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNodeList* pThis;
			long* listLength;
		};

		//Virtual
		struct nextNode
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNodeList* pThis;
			::IXMLDOMNode** nextItem;
		};

		//Virtual
		struct reset
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IXMLDOMNodeList* pThis;
		};

		//Virtual
		struct get__newEnum
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNodeList* pThis;
			::IUnknown** ppUnk;
		};

	private:
		 virtual ~IXMLDOMNodeList() = 0;
	};

	class IXMLDOMNamedNodeMap : IDispatch
	{
	public:
		//Virtual
		struct getNamedItem
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLDOMNamedNodeMap* pThis;
			::BSTR name;
			::IXMLDOMNode** namedItem;
		};

		//Virtual
		struct setNamedItem
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLDOMNamedNodeMap* pThis;
			::IXMLDOMNode* newItem;
			::IXMLDOMNode** nameItem;
		};

		//Virtual
		struct removeNamedItem
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLDOMNamedNodeMap* pThis;
			::BSTR name;
			::IXMLDOMNode** namedItem;
		};

		//Virtual
		struct get_item
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLDOMNamedNodeMap* pThis;
			long index;
			::IXMLDOMNode** listItem;
		};

		//Virtual
		struct get_length
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNamedNodeMap* pThis;
			long* listLength;
		};

		//Virtual
		struct getQualifiedItem
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IXMLDOMNamedNodeMap* pThis;
			::BSTR baseName;
			::BSTR namespaceURI;
			::IXMLDOMNode** qualifiedItem;
		};

		//Virtual
		struct removeQualifiedItem
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IXMLDOMNamedNodeMap* pThis;
			::BSTR baseName;
			::BSTR namespaceURI;
			::IXMLDOMNode** qualifiedItem;
		};

		//Virtual
		struct nextNode
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNamedNodeMap* pThis;
			::IXMLDOMNode** nextItem;
		};

		//Virtual
		struct reset
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IXMLDOMNamedNodeMap* pThis;
		};

		//Virtual
		struct get__newEnum
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNamedNodeMap* pThis;
			::IUnknown** ppUnk;
		};

	private:
		 virtual ~IXMLDOMNamedNodeMap() = 0;
	};

	class IXMLDOMCharacterData : IXMLDOMNode
	{
	public:
		//Virtual
		struct get_data
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMCharacterData* pThis;
			::BSTR* data;
		};

		//Virtual
		struct put_data
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMCharacterData* pThis;
			::BSTR data;
		};

		//Virtual
		struct get_length
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMCharacterData* pThis;
			long* dataLength;
		};

		//Virtual
		struct substringData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IXMLDOMCharacterData* pThis;
			long offset;
			long count;
			::BSTR* data;
		};

		//Virtual
		struct appendData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMCharacterData* pThis;
			::BSTR data;
		};

		//Virtual
		struct insertData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLDOMCharacterData* pThis;
			long offset;
			::BSTR data;
		};

		//Virtual
		struct deleteData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLDOMCharacterData* pThis;
			long offset;
			long count;
		};

		//Virtual
		struct replaceData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IXMLDOMCharacterData* pThis;
			long offset;
			long count;
			::BSTR data;
		};

	private:
		 virtual ~IXMLDOMCharacterData() = 0;
	};

	class IXMLDOMAttribute : IXMLDOMNode
	{
	public:
		//Virtual
		struct get_name
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMAttribute* pThis;
			::BSTR* attributeName;
		};

		//Virtual
		struct get_value
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMAttribute* pThis;
			::VARIANT* attributeValue;
		};

		//Virtual
		struct put_value
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMAttribute* pThis;
			::VARIANT attributeValue;
		};

	private:
		 virtual ~IXMLDOMAttribute() = 0;
	};

	class IXMLDOMElement : IXMLDOMNode
	{
	public:
		//Virtual
		struct get_tagName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMElement* pThis;
			::BSTR* tagName;
		};

		//Virtual
		struct getAttribute
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLDOMElement* pThis;
			::BSTR name;
			::VARIANT* value;
		};

		//Virtual
		struct setAttribute
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLDOMElement* pThis;
			::BSTR name;
			::VARIANT value;
		};

		//Virtual
		struct removeAttribute
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMElement* pThis;
			::BSTR name;
		};

		//Virtual
		struct getAttributeNode
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLDOMElement* pThis;
			::BSTR name;
			::IXMLDOMAttribute** attributeNode;
		};

		//Virtual
		struct setAttributeNode
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLDOMElement* pThis;
			::IXMLDOMAttribute* DOMAttribute;
			::IXMLDOMAttribute** attributeNode;
		};

		//Virtual
		struct removeAttributeNode
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLDOMElement* pThis;
			::IXMLDOMAttribute* DOMAttribute;
			::IXMLDOMAttribute** attributeNode;
		};

		//Virtual
		struct getElementsByTagName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLDOMElement* pThis;
			::BSTR tagName;
			::IXMLDOMNodeList** resultList;
		};

		//Virtual
		struct normalize
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IXMLDOMElement* pThis;
		};

	private:
		 virtual ~IXMLDOMElement() = 0;
	};

	class IXMLDOMText : IXMLDOMCharacterData
	{
	public:
		//Virtual
		struct splitText
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLDOMText* pThis;
			long offset;
			::IXMLDOMText** rightHandTextNode;
		};

	private:
		 virtual ~IXMLDOMText() = 0;
	};

	class IXMLDOMProcessingInstruction : IXMLDOMNode
	{
	public:
		//Virtual
		struct get_target
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMProcessingInstruction* pThis;
			::BSTR* name;
		};

		//Virtual
		struct get_data
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMProcessingInstruction* pThis;
			::BSTR* value;
		};

		//Virtual
		struct put_data
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMProcessingInstruction* pThis;
			::BSTR value;
		};

	private:
		 virtual ~IXMLDOMProcessingInstruction() = 0;
	};

	class IXMLDOMDocumentType : IXMLDOMNode
	{
	public:
		//Virtual
		struct get_name
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMDocumentType* pThis;
			::BSTR* rootName;
		};

		//Virtual
		struct get_entities
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMDocumentType* pThis;
			::IXMLDOMNamedNodeMap** entityMap;
		};

		//Virtual
		struct get_notations
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMDocumentType* pThis;
			::IXMLDOMNamedNodeMap** notationMap;
		};

	private:
		 virtual ~IXMLDOMDocumentType() = 0;
	};

	class IXMLDOMNotation : IXMLDOMNode
	{
	public:
		//Virtual
		struct get_publicId
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNotation* pThis;
			::VARIANT* publicID;
		};

		//Virtual
		struct get_systemId
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMNotation* pThis;
			::VARIANT* systemID;
		};

	private:
		 virtual ~IXMLDOMNotation() = 0;
	};

	class IXMLDOMEntity : IXMLDOMNode
	{
	public:
		//Virtual
		struct get_publicId
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMEntity* pThis;
			::VARIANT* publicID;
		};

		//Virtual
		struct get_systemId
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMEntity* pThis;
			::VARIANT* systemID;
		};

		//Virtual
		struct get_notationName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMEntity* pThis;
			::BSTR* name;
		};

	private:
		 virtual ~IXMLDOMEntity() = 0;
	};

	class IXMLDOMParseError : IDispatch
	{
	public:
		//Virtual
		struct get_errorCode
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMParseError* pThis;
			long* errorCode;
		};

		//Virtual
		struct get_url
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMParseError* pThis;
			::BSTR* urlString;
		};

		//Virtual
		struct get_reason
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMParseError* pThis;
			::BSTR* reasonString;
		};

		//Virtual
		struct get_srcText
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMParseError* pThis;
			::BSTR* sourceString;
		};

		//Virtual
		struct get_line
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMParseError* pThis;
			long* lineNumber;
		};

		//Virtual
		struct get_linepos
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMParseError* pThis;
			long* linePosition;
		};

		//Virtual
		struct get_filepos
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDOMParseError* pThis;
			long* filePosition;
		};

	private:
		 virtual ~IXMLDOMParseError() = 0;
	};

	class IXTLRuntime : IXMLDOMNode
	{
	public:
		//Virtual
		struct uniqueID
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXTLRuntime* pThis;
			::IXMLDOMNode* pNode;
			long* pID;
		};

		//Virtual
		struct depth
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXTLRuntime* pThis;
			::IXMLDOMNode* pNode;
			long* pDepth;
		};

		//Virtual
		struct childNumber
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXTLRuntime* pThis;
			::IXMLDOMNode* pNode;
			long* pNumber;
		};

		//Virtual
		struct ancestorChildNumber
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IXTLRuntime* pThis;
			::BSTR bstrNodeName;
			::IXMLDOMNode* pNode;
			long* pNumber;
		};

		//Virtual
		struct absoluteChildNumber
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXTLRuntime* pThis;
			::IXMLDOMNode* pNode;
			long* pNumber;
		};

		//Virtual
		struct formatIndex
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IXTLRuntime* pThis;
			long lIndex;
			::BSTR bstrFormat;
			::BSTR* pbstrFormattedString;
		};

		//Virtual
		struct formatNumber
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IXTLRuntime* pThis;
			double dblNumber;
			::BSTR bstrFormat;
			::BSTR* pbstrFormattedString;
		};

		//Virtual
		struct formatDate
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IXTLRuntime* pThis;
			::VARIANT varDate;
			::BSTR bstrFormat;
			::VARIANT varDestLocale;
			::BSTR* pbstrFormattedString;
		};

		//Virtual
		struct formatTime
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IXTLRuntime* pThis;
			::VARIANT varTime;
			::BSTR bstrFormat;
			::VARIANT varDestLocale;
			::BSTR* pbstrFormattedString;
		};

	private:
		 virtual ~IXTLRuntime() = 0;
	};

	class IXMLHttpRequest : IDispatch
	{
	public:
		//Virtual
		struct open
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IXMLHttpRequest* pThis;
			::BSTR bstrMethod;
			::BSTR bstrUrl;
			::VARIANT varAsync;
			::VARIANT bstrUser;
			::VARIANT bstrPassword;
		};

		//Virtual
		struct setRequestHeader
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLHttpRequest* pThis;
			::BSTR bstrHeader;
			::BSTR bstrValue;
		};

		//Virtual
		struct getResponseHeader
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLHttpRequest* pThis;
			::BSTR bstrHeader;
			::BSTR* pbstrValue;
		};

		//Virtual
		struct getAllResponseHeaders
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLHttpRequest* pThis;
			::BSTR* pbstrHeaders;
		};

		//Virtual
		struct send
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLHttpRequest* pThis;
			::VARIANT varBody;
		};

		//Virtual
		struct abort
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IXMLHttpRequest* pThis;
		};

		//Virtual
		struct get_status
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLHttpRequest* pThis;
			long* plStatus;
		};

		//Virtual
		struct get_statusText
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLHttpRequest* pThis;
			::BSTR* pbstrStatus;
		};

		//Virtual
		struct get_responseXML
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLHttpRequest* pThis;
			::IDispatch** ppBody;
		};

		//Virtual
		struct get_responseText
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLHttpRequest* pThis;
			::BSTR* pbstrBody;
		};

		//Virtual
		struct get_responseBody
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLHttpRequest* pThis;
			::VARIANT* pvarBody;
		};

		//Virtual
		struct get_responseStream
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLHttpRequest* pThis;
			::VARIANT* pvarBody;
		};

		//Virtual
		struct get_readyState
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLHttpRequest* pThis;
			long* plState;
		};

		//Virtual
		struct put_onreadystatechange
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLHttpRequest* pThis;
			::IDispatch* pReadyStateSink;
		};

	private:
		 virtual ~IXMLHttpRequest() = 0;
	};

	class IXMLDSOControl : IDispatch
	{
	public:
		//Virtual
		struct get_XMLDocument
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDSOControl* pThis;
			::IXMLDOMDocument** ppDoc;
		};

		//Virtual
		struct put_XMLDocument
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDSOControl* pThis;
			::IXMLDOMDocument* ppDoc;
		};

		//Virtual
		struct get_JavaDSOCompatible
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDSOControl* pThis;
			::BOOL* fJavaDSOCompatible;
		};

		//Virtual
		struct put_JavaDSOCompatible
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDSOControl* pThis;
			::BOOL fJavaDSOCompatible;
		};

		//Virtual
		struct get_readyState
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDSOControl* pThis;
			long* state;
		};

	private:
		 virtual ~IXMLDSOControl() = 0;
	};

	class IXMLElementCollection : IDispatch
	{
	public:
		//Virtual
		struct put_length
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLElementCollection* pThis;
			long v;
		};

		//Virtual
		struct get_length
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLElementCollection* pThis;
			long* p;
		};

		//Virtual
		struct get__newEnum
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLElementCollection* pThis;
			::IUnknown** ppUnk;
		};

		//Virtual
		struct item
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IXMLElementCollection* pThis;
			::VARIANT var1;
			::VARIANT var2;
			::IDispatch** ppDisp;
		};

	private:
		 virtual ~IXMLElementCollection() = 0;
	};

	class IXMLDocument : IDispatch
	{
	public:
		//Virtual
		struct get_root
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDocument* pThis;
			::IXMLElement** p;
		};

		//Virtual
		struct get_fileSize
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDocument* pThis;
			::BSTR* p;
		};

		//Virtual
		struct get_fileModifiedDate
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDocument* pThis;
			::BSTR* p;
		};

		//Virtual
		struct get_fileUpdatedDate
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDocument* pThis;
			::BSTR* p;
		};

		//Virtual
		struct get_URL
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDocument* pThis;
			::BSTR* p;
		};

		//Virtual
		struct put_URL
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDocument* pThis;
			::BSTR p;
		};

		//Virtual
		struct get_mimeType
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDocument* pThis;
			::BSTR* p;
		};

		//Virtual
		struct get_readyState
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDocument* pThis;
			long* pl;
		};

		//Virtual
		struct get_charset
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDocument* pThis;
			::BSTR* p;
		};

		//Virtual
		struct put_charset
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDocument* pThis;
			::BSTR p;
		};

		//Virtual
		struct get_version
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDocument* pThis;
			::BSTR* p;
		};

		//Virtual
		struct get_doctype
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDocument* pThis;
			::BSTR* p;
		};

		//Virtual
		struct get_dtdURL
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDocument* pThis;
			::BSTR* p;
		};

		//Virtual
		struct createElement
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IXMLDocument* pThis;
			::VARIANT vType;
			::VARIANT var1;
			::IXMLElement** ppElem;
		};

	private:
		 virtual ~IXMLDocument() = 0;
	};

	class IXMLDocument2 : IDispatch
	{
	public:
		//Virtual
		struct get_root
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDocument2* pThis;
			::IXMLElement2** p;
		};

		//Virtual
		struct get_fileSize
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDocument2* pThis;
			::BSTR* p;
		};

		//Virtual
		struct get_fileModifiedDate
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDocument2* pThis;
			::BSTR* p;
		};

		//Virtual
		struct get_fileUpdatedDate
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDocument2* pThis;
			::BSTR* p;
		};

		//Virtual
		struct get_URL
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDocument2* pThis;
			::BSTR* p;
		};

		//Virtual
		struct put_URL
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDocument2* pThis;
			::BSTR p;
		};

		//Virtual
		struct get_mimeType
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDocument2* pThis;
			::BSTR* p;
		};

		//Virtual
		struct get_readyState
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDocument2* pThis;
			long* pl;
		};

		//Virtual
		struct get_charset
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDocument2* pThis;
			::BSTR* p;
		};

		//Virtual
		struct put_charset
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDocument2* pThis;
			::BSTR p;
		};

		//Virtual
		struct get_version
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDocument2* pThis;
			::BSTR* p;
		};

		//Virtual
		struct get_doctype
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDocument2* pThis;
			::BSTR* p;
		};

		//Virtual
		struct get_dtdURL
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDocument2* pThis;
			::BSTR* p;
		};

		//Virtual
		struct createElement
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IXMLDocument2* pThis;
			::VARIANT vType;
			::VARIANT var1;
			::IXMLElement2** ppElem;
		};

		//Virtual
		struct get_async
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDocument2* pThis;
			::VARIANT_BOOL* pf;
		};

		//Virtual
		struct put_async
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLDocument2* pThis;
			::VARIANT_BOOL f;
		};

	private:
		 virtual ~IXMLDocument2() = 0;
	};

	class IXMLElement : IDispatch
	{
	public:
		//Virtual
		struct get_tagName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLElement* pThis;
			::BSTR* p;
		};

		//Virtual
		struct put_tagName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLElement* pThis;
			::BSTR p;
		};

		//Virtual
		struct get_parent
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLElement* pThis;
			::IXMLElement** ppParent;
		};

		//Virtual
		struct setAttribute
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLElement* pThis;
			::BSTR strPropertyName;
			::VARIANT PropertyValue;
		};

		//Virtual
		struct getAttribute
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLElement* pThis;
			::BSTR strPropertyName;
			::VARIANT* PropertyValue;
		};

		//Virtual
		struct removeAttribute
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLElement* pThis;
			::BSTR strPropertyName;
		};

		//Virtual
		struct get_children
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLElement* pThis;
			::IXMLElementCollection** pp;
		};

		//Virtual
		struct get_type
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLElement* pThis;
			long* plType;
		};

		//Virtual
		struct get_text
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLElement* pThis;
			::BSTR* p;
		};

		//Virtual
		struct put_text
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLElement* pThis;
			::BSTR p;
		};

		//Virtual
		struct addChild
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IXMLElement* pThis;
			::IXMLElement* pChildElem;
			long lIndex;
			long lReserved;
		};

		//Virtual
		struct removeChild
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLElement* pThis;
			::IXMLElement* pChildElem;
		};

	private:
		 virtual ~IXMLElement() = 0;
	};

	class IXMLElement2 : IDispatch
	{
	public:
		//Virtual
		struct get_tagName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLElement2* pThis;
			::BSTR* p;
		};

		//Virtual
		struct put_tagName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLElement2* pThis;
			::BSTR p;
		};

		//Virtual
		struct get_parent
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLElement2* pThis;
			::IXMLElement2** ppParent;
		};

		//Virtual
		struct setAttribute
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLElement2* pThis;
			::BSTR strPropertyName;
			::VARIANT PropertyValue;
		};

		//Virtual
		struct getAttribute
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IXMLElement2* pThis;
			::BSTR strPropertyName;
			::VARIANT* PropertyValue;
		};

		//Virtual
		struct removeAttribute
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLElement2* pThis;
			::BSTR strPropertyName;
		};

		//Virtual
		struct get_children
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLElement2* pThis;
			::IXMLElementCollection** pp;
		};

		//Virtual
		struct get_type
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLElement2* pThis;
			long* plType;
		};

		//Virtual
		struct get_text
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLElement2* pThis;
			::BSTR* p;
		};

		//Virtual
		struct put_text
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLElement2* pThis;
			::BSTR p;
		};

		//Virtual
		struct addChild
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IXMLElement2* pThis;
			::IXMLElement2* pChildElem;
			long lIndex;
			long lReserved;
		};

		//Virtual
		struct removeChild
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLElement2* pThis;
			::IXMLElement2* pChildElem;
		};

		//Virtual
		struct get_attributes
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLElement2* pThis;
			::IXMLElementCollection** pp;
		};

	private:
		 virtual ~IXMLElement2() = 0;
	};

	class IXMLAttribute : IDispatch
	{
	public:
		//Virtual
		struct get_name
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLAttribute* pThis;
			::BSTR* n;
		};

		//Virtual
		struct get_value
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLAttribute* pThis;
			::BSTR* v;
		};

	private:
		 virtual ~IXMLAttribute() = 0;
	};

	class IXMLError : IUnknown
	{
	public:
		//Virtual
		struct GetErrorInfo
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IXMLError* pThis;
			::XML_ERROR* pErrorReturn;
		};

	private:
		 virtual ~IXMLError() = 0;
	};

	class IPersistMoniker : IUnknown
	{
	public:
		//Virtual
		struct GetClassID
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPersistMoniker* pThis;
			::CLSID* pClassID;
		};

		//Virtual
		struct IsDirty
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IPersistMoniker* pThis;
		};

		//Virtual
		struct Load
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IPersistMoniker* pThis;
			::BOOL fFullyAvailable;
			::IMoniker* pimkName;
			::LPBC pibc;
			::DWORD grfMode;
		};

		//Virtual
		struct Save
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IPersistMoniker* pThis;
			::IMoniker* pimkName;
			::LPBC pbc;
			::BOOL fRemember;
		};

		//Virtual
		struct SaveCompleted
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IPersistMoniker* pThis;
			::IMoniker* pimkName;
			::LPBC pibc;
		};

		//Virtual
		struct GetCurMoniker
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPersistMoniker* pThis;
			::IMoniker** ppimkName;
		};

	private:
		 virtual ~IPersistMoniker() = 0;
	};

	class IMonikerProp : IUnknown
	{
	public:
		//Virtual
		struct PutProperty
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IMonikerProp* pThis;
			::MONIKERPROPERTY mkp;
			::LPCWSTR val;
		};

	private:
		 virtual ~IMonikerProp() = 0;
	};

	class IBindProtocol : IUnknown
	{
	public:
		//Virtual
		struct CreateBinding
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IBindProtocol* pThis;
			::LPCWSTR szUrl;
			::IBindCtx* pbc;
			::IBinding** ppb;
		};

	private:
		 virtual ~IBindProtocol() = 0;
	};

	class IBinding : IUnknown
	{
	public:
		//Virtual
		struct Abort
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IBinding* pThis;
		};

		//Virtual
		struct Suspend
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IBinding* pThis;
		};

		//Virtual
		struct Resume
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IBinding* pThis;
		};

		//Virtual
		struct SetPriority
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IBinding* pThis;
			::LONG nPriority;
		};

		//Virtual
		struct GetPriority
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IBinding* pThis;
			::LONG* pnPriority;
		};

		//Virtual
		struct GetBindResult
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IBinding* pThis;
			::CLSID* pclsidProtocol;
			::DWORD* pdwResult;
			::LPOLESTR* pszResult;
			::DWORD* pdwReserved;
		};

	private:
		 virtual ~IBinding() = 0;
	};

	class IBindStatusCallback : IUnknown
	{
	public:
		//Virtual
		struct OnStartBinding
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IBindStatusCallback* pThis;
			::DWORD dwReserved;
			::IBinding* pib;
		};

		//Virtual
		struct GetPriority
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IBindStatusCallback* pThis;
			::LONG* pnPriority;
		};

		//Virtual
		struct OnLowResource
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IBindStatusCallback* pThis;
			::DWORD reserved;
		};

		//Virtual
		struct OnProgress
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IBindStatusCallback* pThis;
			::ULONG ulProgress;
			::ULONG ulProgressMax;
			::ULONG ulStatusCode;
			::LPCWSTR szStatusText;
		};

		//Virtual
		struct OnStopBinding
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IBindStatusCallback* pThis;
			::HRESULT hresult;
			::LPCWSTR szError;
		};

		//Virtual
		struct GetBindInfo
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IBindStatusCallback* pThis;
			::DWORD* grfBINDF;
			::BINDINFO* pbindinfo;
		};

		//Virtual
		struct OnDataAvailable
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IBindStatusCallback* pThis;
			::DWORD grfBSCF;
			::DWORD dwSize;
			::FORMATETC* pformatetc;
			::STGMEDIUM* pstgmed;
		};

		//Virtual
		struct OnObjectAvailable
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IBindStatusCallback* pThis;
			const ::IID& riid;
			::IUnknown* punk;
		};

	private:
		 virtual ~IBindStatusCallback() = 0;
	};

	class IBindStatusCallbackEx : IBindStatusCallback
	{
	public:
		//Virtual
		struct GetBindInfoEx
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IBindStatusCallbackEx* pThis;
			::DWORD* grfBINDF;
			::BINDINFO* pbindinfo;
			::DWORD* grfBINDF2;
			::DWORD* pdwReserved;
		};

	private:
		 virtual ~IBindStatusCallbackEx() = 0;
	};

	class IAuthenticate : IUnknown
	{
	public:
		//Virtual
		struct Authenticate
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IAuthenticate* pThis;
			::HWND* phwnd;
			::LPWSTR* pszUsername;
			::LPWSTR* pszPassword;
		};

	private:
		 virtual ~IAuthenticate() = 0;
	};

	class IAuthenticateEx : IAuthenticate
	{
	public:
		//Virtual
		struct AuthenticateEx
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IAuthenticateEx* pThis;
			::HWND* phwnd;
			::LPWSTR* pszUsername;
			::LPWSTR* pszPassword;
			::AUTHENTICATEINFO* pauthinfo;
		};

	private:
		 virtual ~IAuthenticateEx() = 0;
	};

	class IHttpNegotiate : IUnknown
	{
	public:
		//Virtual
		struct BeginningTransaction
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IHttpNegotiate* pThis;
			::LPCWSTR szURL;
			::LPCWSTR szHeaders;
			::DWORD dwReserved;
			::LPWSTR* pszAdditionalHeaders;
		};

		//Virtual
		struct OnResponse
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IHttpNegotiate* pThis;
			::DWORD dwResponseCode;
			::LPCWSTR szResponseHeaders;
			::LPCWSTR szRequestHeaders;
			::LPWSTR* pszAdditionalRequestHeaders;
		};

	private:
		 virtual ~IHttpNegotiate() = 0;
	};

	class IHttpNegotiate2 : IHttpNegotiate
	{
	public:
		//Virtual
		struct GetRootSecurityId
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IHttpNegotiate2* pThis;
			::BYTE* pbSecurityId;
			::DWORD* pcbSecurityId;
			::DWORD_PTR dwReserved;
		};

	private:
		 virtual ~IHttpNegotiate2() = 0;
	};

	class IHttpNegotiate3 : IHttpNegotiate2
	{
	public:
		//Virtual
		struct GetSerializedClientCertContext
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IHttpNegotiate3* pThis;
			::BYTE** ppbCert;
			::DWORD* pcbCert;
		};

	private:
		 virtual ~IHttpNegotiate3() = 0;
	};

	class IWinInetFileStream : IUnknown
	{
	public:
		//Virtual
		struct SetHandleForUnlock
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IWinInetFileStream* pThis;
			::DWORD_PTR hWinInetLockHandle;
			::DWORD_PTR dwReserved;
		};

		//Virtual
		struct SetDeleteFile
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IWinInetFileStream* pThis;
			::DWORD_PTR dwReserved;
		};

	private:
		 virtual ~IWinInetFileStream() = 0;
	};

	class IWindowForBindingUI : IUnknown
	{
	public:
		//Virtual
		struct GetWindow
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IWindowForBindingUI* pThis;
			const ::GUID& rguidReason;
			::HWND* phwnd;
		};

	private:
		 virtual ~IWindowForBindingUI() = 0;
	};

	class ICodeInstall : IWindowForBindingUI
	{
	public:
		//Virtual
		struct OnCodeInstallProblem
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ICodeInstall* pThis;
			::ULONG ulStatusCode;
			::LPCWSTR szDestination;
			::LPCWSTR szSource;
			::DWORD dwReserved;
		};

	private:
		 virtual ~ICodeInstall() = 0;
	};

	class IUri : IUnknown
	{
	public:
		//Virtual
		struct GetPropertyBSTR
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IUri* pThis;
			::Uri_PROPERTY uriProp;
			::BSTR* pbstrProperty;
			::DWORD dwFlags;
		};

		//Virtual
		struct GetPropertyLength
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IUri* pThis;
			::Uri_PROPERTY uriProp;
			::DWORD* pcchProperty;
			::DWORD dwFlags;
		};

		//Virtual
		struct GetPropertyDWORD
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IUri* pThis;
			::Uri_PROPERTY uriProp;
			::DWORD* pdwProperty;
			::DWORD dwFlags;
		};

		//Virtual
		struct HasProperty
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IUri* pThis;
			::Uri_PROPERTY uriProp;
			::BOOL* pfHasProperty;
		};

		//Virtual
		struct GetAbsoluteUri
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUri* pThis;
			::BSTR* pbstrAbsoluteUri;
		};

		//Virtual
		struct GetAuthority
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUri* pThis;
			::BSTR* pbstrAuthority;
		};

		//Virtual
		struct GetDisplayUri
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUri* pThis;
			::BSTR* pbstrDisplayString;
		};

		//Virtual
		struct GetDomain
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUri* pThis;
			::BSTR* pbstrDomain;
		};

		//Virtual
		struct GetExtension
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUri* pThis;
			::BSTR* pbstrExtension;
		};

		//Virtual
		struct GetFragment
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUri* pThis;
			::BSTR* pbstrFragment;
		};

		//Virtual
		struct GetHost
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUri* pThis;
			::BSTR* pbstrHost;
		};

		//Virtual
		struct GetPassword
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUri* pThis;
			::BSTR* pbstrPassword;
		};

		//Virtual
		struct GetPath
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUri* pThis;
			::BSTR* pbstrPath;
		};

		//Virtual
		struct GetPathAndQuery
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUri* pThis;
			::BSTR* pbstrPathAndQuery;
		};

		//Virtual
		struct GetQuery
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUri* pThis;
			::BSTR* pbstrQuery;
		};

		//Virtual
		struct GetRawUri
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUri* pThis;
			::BSTR* pbstrRawUri;
		};

		//Virtual
		struct GetSchemeName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUri* pThis;
			::BSTR* pbstrSchemeName;
		};

		//Virtual
		struct GetUserInfo
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUri* pThis;
			::BSTR* pbstrUserInfo;
		};

		//Virtual
		struct GetUserNameA
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUri* pThis;
			::BSTR* pbstrUserName;
		};

		//Virtual
		struct GetHostType
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUri* pThis;
			::DWORD* pdwHostType;
		};

		//Virtual
		struct GetPort
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUri* pThis;
			::DWORD* pdwPort;
		};

		//Virtual
		struct GetScheme
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUri* pThis;
			::DWORD* pdwScheme;
		};

		//Virtual
		struct GetZone
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUri* pThis;
			::DWORD* pdwZone;
		};

		//Virtual
		struct GetProperties
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUri* pThis;
			::LPDWORD pdwFlags;
		};

		//Virtual
		struct IsEqual
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IUri* pThis;
			::IUri* pUri;
			::BOOL* pfEqual;
		};

	private:
		 virtual ~IUri() = 0;
	};

	class IUriContainer : IUnknown
	{
	public:
		//Virtual
		struct GetIUri
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUriContainer* pThis;
			::IUri** ppIUri;
		};

	private:
		 virtual ~IUriContainer() = 0;
	};

	class IUriBuilder : IUnknown
	{
	public:
		//Virtual
		struct CreateUriSimple
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IUriBuilder* pThis;
			::DWORD dwAllowEncodingPropertyMask;
			::DWORD_PTR dwReserved;
			::IUri** ppIUri;
		};

		//Virtual
		struct CreateUri
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IUriBuilder* pThis;
			::DWORD dwCreateFlags;
			::DWORD dwAllowEncodingPropertyMask;
			::DWORD_PTR dwReserved;
			::IUri** ppIUri;
		};

		//Virtual
		struct CreateUriWithFlags
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IUriBuilder* pThis;
			::DWORD dwCreateFlags;
			::DWORD dwUriBuilderFlags;
			::DWORD dwAllowEncodingPropertyMask;
			::DWORD_PTR dwReserved;
			::IUri** ppIUri;
		};

		//Virtual
		struct GetIUri
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUriBuilder* pThis;
			::IUri** ppIUri;
		};

		//Virtual
		struct SetIUri
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUriBuilder* pThis;
			::IUri* pIUri;
		};

		//Virtual
		struct GetFragment
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IUriBuilder* pThis;
			::DWORD* pcchFragment;
			::LPCWSTR* ppwzFragment;
		};

		//Virtual
		struct GetHost
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IUriBuilder* pThis;
			::DWORD* pcchHost;
			::LPCWSTR* ppwzHost;
		};

		//Virtual
		struct GetPassword
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IUriBuilder* pThis;
			::DWORD* pcchPassword;
			::LPCWSTR* ppwzPassword;
		};

		//Virtual
		struct GetPath
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IUriBuilder* pThis;
			::DWORD* pcchPath;
			::LPCWSTR* ppwzPath;
		};

		//Virtual
		struct GetPort
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IUriBuilder* pThis;
			::BOOL* pfHasPort;
			::DWORD* pdwPort;
		};

		//Virtual
		struct GetQuery
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IUriBuilder* pThis;
			::DWORD* pcchQuery;
			::LPCWSTR* ppwzQuery;
		};

		//Virtual
		struct GetSchemeName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IUriBuilder* pThis;
			::DWORD* pcchSchemeName;
			::LPCWSTR* ppwzSchemeName;
		};

		//Virtual
		struct GetUserNameA
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IUriBuilder* pThis;
			::DWORD* pcchUserName;
			::LPCWSTR* ppwzUserName;
		};

		//Virtual
		struct SetFragment
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUriBuilder* pThis;
			::LPCWSTR pwzNewValue;
		};

		//Virtual
		struct SetHost
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUriBuilder* pThis;
			::LPCWSTR pwzNewValue;
		};

		//Virtual
		struct SetPassword
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUriBuilder* pThis;
			::LPCWSTR pwzNewValue;
		};

		//Virtual
		struct SetPath
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUriBuilder* pThis;
			::LPCWSTR pwzNewValue;
		};

		//Virtual
		struct SetPortA
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IUriBuilder* pThis;
			::BOOL fHasPort;
			::DWORD dwNewValue;
		};

		//Virtual
		struct SetQuery
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUriBuilder* pThis;
			::LPCWSTR pwzNewValue;
		};

		//Virtual
		struct SetSchemeName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUriBuilder* pThis;
			::LPCWSTR pwzNewValue;
		};

		//Virtual
		struct SetUserName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUriBuilder* pThis;
			::LPCWSTR pwzNewValue;
		};

		//Virtual
		struct RemoveProperties
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUriBuilder* pThis;
			::DWORD dwPropertyMask;
		};

		//Virtual
		struct HasBeenModified
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IUriBuilder* pThis;
			::BOOL* pfModified;
		};

	private:
		 virtual ~IUriBuilder() = 0;
	};

	class IUriBuilderFactory : IUnknown
	{
	public:
		//Virtual
		struct CreateIUriBuilder
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IUriBuilderFactory* pThis;
			::DWORD dwFlags;
			::DWORD_PTR dwReserved;
			::IUriBuilder** ppIUriBuilder;
		};

		//Virtual
		struct CreateInitializedIUriBuilder
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IUriBuilderFactory* pThis;
			::DWORD dwFlags;
			::DWORD_PTR dwReserved;
			::IUriBuilder** ppIUriBuilder;
		};

	private:
		 virtual ~IUriBuilderFactory() = 0;
	};

	class IWinInetInfo : IUnknown
	{
	public:
		//Virtual
		struct QueryOption
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IWinInetInfo* pThis;
			::DWORD dwOption;
			::LPVOID pBuffer;
			::DWORD* pcbBuf;
		};

	private:
		 virtual ~IWinInetInfo() = 0;
	};

	class IHttpSecurity : IWindowForBindingUI
	{
	public:
		//Virtual
		struct OnSecurityProblem
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IHttpSecurity* pThis;
			::DWORD dwProblem;
		};

	private:
		 virtual ~IHttpSecurity() = 0;
	};

	class IWinInetHttpInfo : IWinInetInfo
	{
	public:
		//Virtual
		struct QueryInfo
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IWinInetHttpInfo* pThis;
			::DWORD dwOption;
			::LPVOID pBuffer;
			::DWORD* pcbBuf;
			::DWORD* pdwFlags;
			::DWORD* pdwReserved;
		};

	private:
		 virtual ~IWinInetHttpInfo() = 0;
	};

	class IWinInetHttpTimeouts : IUnknown
	{
	public:
		//Virtual
		struct GetRequestTimeouts
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IWinInetHttpTimeouts* pThis;
			::DWORD* pdwConnectTimeout;
			::DWORD* pdwSendTimeout;
			::DWORD* pdwReceiveTimeout;
		};

	private:
		 virtual ~IWinInetHttpTimeouts() = 0;
	};

	class IWinInetCacheHints : IUnknown
	{
	public:
		//Virtual
		struct SetCacheExtension
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IWinInetCacheHints* pThis;
			::LPCWSTR pwzExt;
			::LPVOID pszCacheFile;
			::DWORD* pcbCacheFile;
			::DWORD* pdwWinInetError;
			::DWORD* pdwReserved;
		};

	private:
		 virtual ~IWinInetCacheHints() = 0;
	};

	class IWinInetCacheHints2 : IWinInetCacheHints
	{
	public:
		//Virtual
		struct SetCacheExtension2
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IWinInetCacheHints2* pThis;
			::LPCWSTR pwzExt;
			::WCHAR* pwzCacheFile;
			::DWORD* pcchCacheFile;
			::DWORD* pdwWinInetError;
			::DWORD* pdwReserved;
		};

	private:
		 virtual ~IWinInetCacheHints2() = 0;
	};

	class IBindHost : IUnknown
	{
	public:
		//Virtual
		struct CreateMoniker
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IBindHost* pThis;
			::LPOLESTR szName;
			::IBindCtx* pBC;
			::IMoniker** ppmk;
			::DWORD dwReserved;
		};

		//Virtual
		struct MonikerBindToStorage
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IBindHost* pThis;
			::IMoniker* pMk;
			::IBindCtx* pBC;
			::IBindStatusCallback* pBSC;
			const ::IID& riid;
			void** ppvObj;
		};

		//Virtual
		struct MonikerBindToObject
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IBindHost* pThis;
			::IMoniker* pMk;
			::IBindCtx* pBC;
			::IBindStatusCallback* pBSC;
			const ::IID& riid;
			void** ppvObj;
		};

	private:
		 virtual ~IBindHost() = 0;
	};

	class IInternetBindInfo : IUnknown
	{
	public:
		//Virtual
		struct GetBindInfo
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IInternetBindInfo* pThis;
			::DWORD* grfBINDF;
			::BINDINFO* pbindinfo;
		};

		//Virtual
		struct GetBindString
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IInternetBindInfo* pThis;
			::ULONG ulStringType;
			::LPOLESTR* ppwzStr;
			::ULONG cEl;
			::ULONG* pcElFetched;
		};

	private:
		 virtual ~IInternetBindInfo() = 0;
	};

	class IInternetBindInfoEx : IInternetBindInfo
	{
	public:
		//Virtual
		struct GetBindInfoEx
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IInternetBindInfoEx* pThis;
			::DWORD* grfBINDF;
			::BINDINFO* pbindinfo;
			::DWORD* grfBINDF2;
			::DWORD* pdwReserved;
		};

	private:
		 virtual ~IInternetBindInfoEx() = 0;
	};

	class IInternetProtocolRoot : IUnknown
	{
	public:
		//Virtual
		struct Start
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IInternetProtocolRoot* pThis;
			::LPCWSTR szUrl;
			::IInternetProtocolSink* pOIProtSink;
			::IInternetBindInfo* pOIBindInfo;
			::DWORD grfPI;
			::HANDLE_PTR dwReserved;
		};

		//Virtual
		struct Continue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IInternetProtocolRoot* pThis;
			::PROTOCOLDATA* pProtocolData;
		};

		//Virtual
		struct Abort
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IInternetProtocolRoot* pThis;
			::HRESULT hrReason;
			::DWORD dwOptions;
		};

		//Virtual
		struct Terminate
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IInternetProtocolRoot* pThis;
			::DWORD dwOptions;
		};

		//Virtual
		struct Suspend
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IInternetProtocolRoot* pThis;
		};

		//Virtual
		struct Resume
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IInternetProtocolRoot* pThis;
		};

	private:
		 virtual ~IInternetProtocolRoot() = 0;
	};

	class IInternetProtocol : IInternetProtocolRoot
	{
	public:
		//Virtual
		struct Read
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IInternetProtocol* pThis;
			void* pv;
			::ULONG cb;
			::ULONG* pcbRead;
		};

		//Virtual
		struct Seek
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IInternetProtocol* pThis;
			::LARGE_INTEGER dlibMove;
			::DWORD dwOrigin;
			::ULARGE_INTEGER* plibNewPosition;
		};

		//Virtual
		struct LockRequest
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IInternetProtocol* pThis;
			::DWORD dwOptions;
		};

		//Virtual
		struct UnlockRequest
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IInternetProtocol* pThis;
		};

	private:
		 virtual ~IInternetProtocol() = 0;
	};

	class IInternetProtocolEx : IInternetProtocol
	{
	public:
		//Virtual
		struct StartEx
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IInternetProtocolEx* pThis;
			::IUri* pUri;
			::IInternetProtocolSink* pOIProtSink;
			::IInternetBindInfo* pOIBindInfo;
			::DWORD grfPI;
			::HANDLE_PTR dwReserved;
		};

	private:
		 virtual ~IInternetProtocolEx() = 0;
	};

	class IInternetProtocolSink : IUnknown
	{
	public:
		//Virtual
		struct Switch
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IInternetProtocolSink* pThis;
			::PROTOCOLDATA* pProtocolData;
		};

		//Virtual
		struct ReportProgress
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IInternetProtocolSink* pThis;
			::ULONG ulStatusCode;
			::LPCWSTR szStatusText;
		};

		//Virtual
		struct ReportData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IInternetProtocolSink* pThis;
			::DWORD grfBSCF;
			::ULONG ulProgress;
			::ULONG ulProgressMax;
		};

		//Virtual
		struct ReportResult
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IInternetProtocolSink* pThis;
			::HRESULT hrResult;
			::DWORD dwError;
			::LPCWSTR szResult;
		};

	private:
		 virtual ~IInternetProtocolSink() = 0;
	};

	class IInternetProtocolSinkStackable : IUnknown
	{
	public:
		//Virtual
		struct SwitchSink
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IInternetProtocolSinkStackable* pThis;
			::IInternetProtocolSink* pOIProtSink;
		};

		//Virtual
		struct CommitSwitch
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IInternetProtocolSinkStackable* pThis;
		};

		//Virtual
		struct RollbackSwitch
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IInternetProtocolSinkStackable* pThis;
		};

	private:
		 virtual ~IInternetProtocolSinkStackable() = 0;
	};

	class IInternetSession : IUnknown
	{
	public:
		//Virtual
		struct RegisterNameSpace
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 7;

			::IInternetSession* pThis;
			::IClassFactory* pCF;
			const ::IID& rclsid;
			::LPCWSTR pwzProtocol;
			::ULONG cPatterns;
			const ::LPCWSTR* ppwzPatterns;
			::DWORD dwReserved;
		};

		//Virtual
		struct UnregisterNameSpace
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IInternetSession* pThis;
			::IClassFactory* pCF;
			::LPCWSTR pszProtocol;
		};

		//Virtual
		struct RegisterMimeFilter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IInternetSession* pThis;
			::IClassFactory* pCF;
			const ::IID& rclsid;
			::LPCWSTR pwzType;
		};

		//Virtual
		struct UnregisterMimeFilter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IInternetSession* pThis;
			::IClassFactory* pCF;
			::LPCWSTR pwzType;
		};

		//Virtual
		struct CreateBinding
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 7;

			::IInternetSession* pThis;
			::LPBC pBC;
			::LPCWSTR szUrl;
			::IUnknown* pUnkOuter;
			::IUnknown** ppUnk;
			::IInternetProtocol** ppOInetProt;
			::DWORD dwOption;
		};

		//Virtual
		struct SetSessionOption
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IInternetSession* pThis;
			::DWORD dwOption;
			::LPVOID pBuffer;
			::DWORD dwBufferLength;
			::DWORD dwReserved;
		};

		//Virtual
		struct GetSessionOption
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IInternetSession* pThis;
			::DWORD dwOption;
			::LPVOID pBuffer;
			::DWORD* pdwBufferLength;
			::DWORD dwReserved;
		};

	private:
		 virtual ~IInternetSession() = 0;
	};

	class IInternetThreadSwitch : IUnknown
	{
	public:
		//Virtual
		struct Prepare
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IInternetThreadSwitch* pThis;
		};

		//Virtual
		struct Continue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IInternetThreadSwitch* pThis;
		};

	private:
		 virtual ~IInternetThreadSwitch() = 0;
	};

	class IInternetPriority : IUnknown
	{
	public:
		//Virtual
		struct SetPriority
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IInternetPriority* pThis;
			::LONG nPriority;
		};

		//Virtual
		struct GetPriority
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IInternetPriority* pThis;
			::LONG* pnPriority;
		};

	private:
		 virtual ~IInternetPriority() = 0;
	};

	class IInternetProtocolInfo : IUnknown
	{
	public:
		//Virtual
		struct ParseUrl
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 8;

			::IInternetProtocolInfo* pThis;
			::LPCWSTR pwzUrl;
			::PARSEACTION ParseAction;
			::DWORD dwParseFlags;
			::LPWSTR pwzResult;
			::DWORD cchResult;
			::DWORD* pcchResult;
			::DWORD dwReserved;
		};

		//Virtual
		struct CombineUrl
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 8;

			::IInternetProtocolInfo* pThis;
			::LPCWSTR pwzBaseUrl;
			::LPCWSTR pwzRelativeUrl;
			::DWORD dwCombineFlags;
			::LPWSTR pwzResult;
			::DWORD cchResult;
			::DWORD* pcchResult;
			::DWORD dwReserved;
		};

		//Virtual
		struct CompareUrl
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IInternetProtocolInfo* pThis;
			::LPCWSTR pwzUrl1;
			::LPCWSTR pwzUrl2;
			::DWORD dwCompareFlags;
		};

		//Virtual
		struct QueryInfo
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 8;

			::IInternetProtocolInfo* pThis;
			::LPCWSTR pwzUrl;
			::QUERYOPTION OueryOption;
			::DWORD dwQueryFlags;
			::LPVOID pBuffer;
			::DWORD cbBuffer;
			::DWORD* pcbBuf;
			::DWORD dwReserved;
		};

	private:
		 virtual ~IInternetProtocolInfo() = 0;
	};

	class IInternetSecurityMgrSite : IUnknown
	{
	public:
		//Virtual
		struct GetWindow
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IInternetSecurityMgrSite* pThis;
			::HWND* phwnd;
		};

		//Virtual
		struct EnableModeless
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IInternetSecurityMgrSite* pThis;
			::BOOL fEnable;
		};

	private:
		 virtual ~IInternetSecurityMgrSite() = 0;
	};

	class IInternetSecurityManager : IUnknown
	{
	public:
		//Virtual
		struct SetSecuritySite
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IInternetSecurityManager* pThis;
			::IInternetSecurityMgrSite* pSite;
		};

		//Virtual
		struct GetSecuritySite
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IInternetSecurityManager* pThis;
			::IInternetSecurityMgrSite** ppSite;
		};

		//Virtual
		struct MapUrlToZone
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IInternetSecurityManager* pThis;
			::LPCWSTR pwszUrl;
			::DWORD* pdwZone;
			::DWORD dwFlags;
		};

		//Virtual
		struct GetSecurityId
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IInternetSecurityManager* pThis;
			::LPCWSTR pwszUrl;
			::BYTE* pbSecurityId;
			::DWORD* pcbSecurityId;
			::DWORD_PTR dwReserved;
		};

		//Virtual
		struct ProcessUrlAction
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 9;

			::IInternetSecurityManager* pThis;
			::LPCWSTR pwszUrl;
			::DWORD dwAction;
			::BYTE* pPolicy;
			::DWORD cbPolicy;
			::BYTE* pContext;
			::DWORD cbContext;
			::DWORD dwFlags;
			::DWORD dwReserved;
		};

		//Virtual
		struct QueryCustomPolicy
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 8;

			::IInternetSecurityManager* pThis;
			::LPCWSTR pwszUrl;
			const ::GUID& guidKey;
			::BYTE** ppPolicy;
			::DWORD* pcbPolicy;
			::BYTE* pContext;
			::DWORD cbContext;
			::DWORD dwReserved;
		};

		//Virtual
		struct SetZoneMapping
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IInternetSecurityManager* pThis;
			::DWORD dwZone;
			::LPCWSTR lpszPattern;
			::DWORD dwFlags;
		};

		//Virtual
		struct GetZoneMappings
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IInternetSecurityManager* pThis;
			::DWORD dwZone;
			::IEnumString** ppenumString;
			::DWORD dwFlags;
		};

	private:
		 virtual ~IInternetSecurityManager() = 0;
	};

	class IInternetSecurityManagerEx : IInternetSecurityManager
	{
	public:
		//Virtual
		struct ProcessUrlActionEx
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 10;

			::IInternetSecurityManagerEx* pThis;
			::LPCWSTR pwszUrl;
			::DWORD dwAction;
			::BYTE* pPolicy;
			::DWORD cbPolicy;
			::BYTE* pContext;
			::DWORD cbContext;
			::DWORD dwFlags;
			::DWORD dwReserved;
			::DWORD* pdwOutFlags;
		};

	private:
		 virtual ~IInternetSecurityManagerEx() = 0;
	};

	class IInternetSecurityManagerEx2 : IInternetSecurityManagerEx
	{
	public:
		//Virtual
		struct MapUrlToZoneEx2
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IInternetSecurityManagerEx2* pThis;
			::IUri* pUri;
			::DWORD* pdwZone;
			::DWORD dwFlags;
			::LPWSTR* ppwszMappedUrl;
			::DWORD* pdwOutFlags;
		};

		//Virtual
		struct ProcessUrlActionEx2
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 10;

			::IInternetSecurityManagerEx2* pThis;
			::IUri* pUri;
			::DWORD dwAction;
			::BYTE* pPolicy;
			::DWORD cbPolicy;
			::BYTE* pContext;
			::DWORD cbContext;
			::DWORD dwFlags;
			::DWORD_PTR dwReserved;
			::DWORD* pdwOutFlags;
		};

		//Virtual
		struct GetSecurityIdEx2
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IInternetSecurityManagerEx2* pThis;
			::IUri* pUri;
			::BYTE* pbSecurityId;
			::DWORD* pcbSecurityId;
			::DWORD_PTR dwReserved;
		};

		//Virtual
		struct QueryCustomPolicyEx2
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 8;

			::IInternetSecurityManagerEx2* pThis;
			::IUri* pUri;
			const ::GUID& guidKey;
			::BYTE** ppPolicy;
			::DWORD* pcbPolicy;
			::BYTE* pContext;
			::DWORD cbContext;
			::DWORD_PTR dwReserved;
		};

	private:
		 virtual ~IInternetSecurityManagerEx2() = 0;
	};

	class IZoneIdentifier : IUnknown
	{
	public:
		//Virtual
		struct GetId
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IZoneIdentifier* pThis;
			::DWORD* pdwZone;
		};

		//Virtual
		struct SetId
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IZoneIdentifier* pThis;
			::DWORD dwZone;
		};

		//Virtual
		struct Remove
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IZoneIdentifier* pThis;
		};

	private:
		 virtual ~IZoneIdentifier() = 0;
	};

	class IZoneIdentifier2 : IZoneIdentifier
	{
	public:
		//Virtual
		struct GetLastWriterPackageFamilyName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IZoneIdentifier2* pThis;
			::LPWSTR* packageFamilyName;
		};

		//Virtual
		struct SetLastWriterPackageFamilyName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IZoneIdentifier2* pThis;
			::LPCWSTR packageFamilyName;
		};

		//Virtual
		struct RemoveLastWriterPackageFamilyName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IZoneIdentifier2* pThis;
		};

		//Virtual
		struct GetAppZoneId
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IZoneIdentifier2* pThis;
			::DWORD* zone;
		};

		//Virtual
		struct SetAppZoneId
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IZoneIdentifier2* pThis;
			::DWORD zone;
		};

		//Virtual
		struct RemoveAppZoneId
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IZoneIdentifier2* pThis;
		};

	private:
		 virtual ~IZoneIdentifier2() = 0;
	};

	class IInternetHostSecurityManager : IUnknown
	{
	public:
		//Virtual
		struct GetSecurityId
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IInternetHostSecurityManager* pThis;
			::BYTE* pbSecurityId;
			::DWORD* pcbSecurityId;
			::DWORD_PTR dwReserved;
		};

		//Virtual
		struct ProcessUrlAction
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 8;

			::IInternetHostSecurityManager* pThis;
			::DWORD dwAction;
			::BYTE* pPolicy;
			::DWORD cbPolicy;
			::BYTE* pContext;
			::DWORD cbContext;
			::DWORD dwFlags;
			::DWORD dwReserved;
		};

		//Virtual
		struct QueryCustomPolicy
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 7;

			::IInternetHostSecurityManager* pThis;
			const ::GUID& guidKey;
			::BYTE** ppPolicy;
			::DWORD* pcbPolicy;
			::BYTE* pContext;
			::DWORD cbContext;
			::DWORD dwReserved;
		};

	private:
		 virtual ~IInternetHostSecurityManager() = 0;
	};

	class IInternetZoneManager : IUnknown
	{
	public:
		//Virtual
		struct GetZoneAttributes
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IInternetZoneManager* pThis;
			::DWORD dwZone;
			::ZONEATTRIBUTES* pZoneAttributes;
		};

		//Virtual
		struct SetZoneAttributes
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IInternetZoneManager* pThis;
			::DWORD dwZone;
			::ZONEATTRIBUTES* pZoneAttributes;
		};

		//Virtual
		struct GetZoneCustomPolicy
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IInternetZoneManager* pThis;
			::DWORD dwZone;
			const ::GUID& guidKey;
			::BYTE** ppPolicy;
			::DWORD* pcbPolicy;
			::URLZONEREG urlZoneReg;
		};

		//Virtual
		struct SetZoneCustomPolicy
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IInternetZoneManager* pThis;
			::DWORD dwZone;
			const ::GUID& guidKey;
			::BYTE* pPolicy;
			::DWORD cbPolicy;
			::URLZONEREG urlZoneReg;
		};

		//Virtual
		struct GetZoneActionPolicy
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IInternetZoneManager* pThis;
			::DWORD dwZone;
			::DWORD dwAction;
			::BYTE* pPolicy;
			::DWORD cbPolicy;
			::URLZONEREG urlZoneReg;
		};

		//Virtual
		struct SetZoneActionPolicy
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IInternetZoneManager* pThis;
			::DWORD dwZone;
			::DWORD dwAction;
			::BYTE* pPolicy;
			::DWORD cbPolicy;
			::URLZONEREG urlZoneReg;
		};

		//Virtual
		struct PromptAction
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IInternetZoneManager* pThis;
			::DWORD dwAction;
			::HWND hwndParent;
			::LPCWSTR pwszUrl;
			::LPCWSTR pwszText;
			::DWORD dwPromptFlags;
		};

		//Virtual
		struct LogAction
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IInternetZoneManager* pThis;
			::DWORD dwAction;
			::LPCWSTR pwszUrl;
			::LPCWSTR pwszText;
			::DWORD dwLogFlags;
		};

		//Virtual
		struct CreateZoneEnumerator
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IInternetZoneManager* pThis;
			::DWORD* pdwEnum;
			::DWORD* pdwCount;
			::DWORD dwFlags;
		};

		//Virtual
		struct GetZoneAt
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IInternetZoneManager* pThis;
			::DWORD dwEnum;
			::DWORD dwIndex;
			::DWORD* pdwZone;
		};

		//Virtual
		struct DestroyZoneEnumerator
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IInternetZoneManager* pThis;
			::DWORD dwEnum;
		};

		//Virtual
		struct CopyTemplatePoliciesToZone
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IInternetZoneManager* pThis;
			::DWORD dwTemplate;
			::DWORD dwZone;
			::DWORD dwReserved;
		};

	private:
		 virtual ~IInternetZoneManager() = 0;
	};

	class IInternetZoneManagerEx : IInternetZoneManager
	{
	public:
		//Virtual
		struct GetZoneActionPolicyEx
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 7;

			::IInternetZoneManagerEx* pThis;
			::DWORD dwZone;
			::DWORD dwAction;
			::BYTE* pPolicy;
			::DWORD cbPolicy;
			::URLZONEREG urlZoneReg;
			::DWORD dwFlags;
		};

		//Virtual
		struct SetZoneActionPolicyEx
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 7;

			::IInternetZoneManagerEx* pThis;
			::DWORD dwZone;
			::DWORD dwAction;
			::BYTE* pPolicy;
			::DWORD cbPolicy;
			::URLZONEREG urlZoneReg;
			::DWORD dwFlags;
		};

	private:
		 virtual ~IInternetZoneManagerEx() = 0;
	};

	class IInternetZoneManagerEx2 : IInternetZoneManagerEx
	{
	public:
		//Virtual
		struct GetZoneAttributesEx
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IInternetZoneManagerEx2* pThis;
			::DWORD dwZone;
			::ZONEATTRIBUTES* pZoneAttributes;
			::DWORD dwFlags;
		};

		//Virtual
		struct GetZoneSecurityState
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IInternetZoneManagerEx2* pThis;
			::DWORD dwZoneIndex;
			::BOOL fRespectPolicy;
			::LPDWORD pdwState;
			::BOOL* pfPolicyEncountered;
		};

		//Virtual
		struct GetIESecurityState
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IInternetZoneManagerEx2* pThis;
			::BOOL fRespectPolicy;
			::LPDWORD pdwState;
			::BOOL* pfPolicyEncountered;
			::BOOL fNoCache;
		};

		//Virtual
		struct FixUnsecureSettings
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IInternetZoneManagerEx2* pThis;
		};

	private:
		 virtual ~IInternetZoneManagerEx2() = 0;
	};

	class ISoftDistExt : IUnknown
	{
	public:
		//Virtual
		struct ProcessSoftDist
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ISoftDistExt* pThis;
			::LPCWSTR szCDFURL;
			::IXMLElement* pSoftDistElement;
			::LPSOFTDISTINFO lpsdi;
		};

		//Virtual
		struct GetFirstCodeBase
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ISoftDistExt* pThis;
			::LPWSTR* szCodeBase;
			::LPDWORD dwMaxSize;
		};

		//Virtual
		struct GetNextCodeBase
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ISoftDistExt* pThis;
			::LPWSTR* szCodeBase;
			::LPDWORD dwMaxSize;
		};

		//Virtual
		struct AsyncInstallDistributionUnit
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ISoftDistExt* pThis;
			::IBindCtx* pbc;
			::LPVOID pvReserved;
			::DWORD flags;
			::LPCODEBASEHOLD lpcbh;
		};

	private:
		 virtual ~ISoftDistExt() = 0;
	};

	class ICatalogFileInfo : IUnknown
	{
	public:
		//Virtual
		struct GetCatalogFile
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICatalogFileInfo* pThis;
			::LPSTR* ppszCatalogFile;
		};

		//Virtual
		struct GetJavaTrust
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ICatalogFileInfo* pThis;
			void** ppJavaTrust;
		};

	private:
		 virtual ~ICatalogFileInfo() = 0;
	};

	class IDataFilter : IUnknown
	{
	public:
		//Virtual
		struct DoEncode
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 10;

			::IDataFilter* pThis;
			::DWORD dwFlags;
			::LONG lInBufferSize;
			::BYTE* pbInBuffer;
			::LONG lOutBufferSize;
			::BYTE* pbOutBuffer;
			::LONG lInBytesAvailable;
			::LONG* plInBytesRead;
			::LONG* plOutBytesWritten;
			::DWORD dwReserved;
		};

		//Virtual
		struct DoDecode
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 10;

			::IDataFilter* pThis;
			::DWORD dwFlags;
			::LONG lInBufferSize;
			::BYTE* pbInBuffer;
			::LONG lOutBufferSize;
			::BYTE* pbOutBuffer;
			::LONG lInBytesAvailable;
			::LONG* plInBytesRead;
			::LONG* plOutBytesWritten;
			::DWORD dwReserved;
		};

		//Virtual
		struct SetEncodingLevel
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDataFilter* pThis;
			::DWORD dwEncLevel;
		};

	private:
		 virtual ~IDataFilter() = 0;
	};

	class IEncodingFilterFactory : IUnknown
	{
	public:
		//Virtual
		struct FindBestFilter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IEncodingFilterFactory* pThis;
			::LPCWSTR pwzCodeIn;
			::LPCWSTR pwzCodeOut;
			::DATAINFO info;
			::IDataFilter** ppDF;
		};

		//Virtual
		struct GetDefaultFilter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IEncodingFilterFactory* pThis;
			::LPCWSTR pwzCodeIn;
			::LPCWSTR pwzCodeOut;
			::IDataFilter** ppDF;
		};

	private:
		 virtual ~IEncodingFilterFactory() = 0;
	};

	class IWrappedProtocol : IUnknown
	{
	public:
		//Virtual
		struct GetWrapperCode
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IWrappedProtocol* pThis;
			::LONG* pnCode;
			::DWORD_PTR dwReserved;
		};

	private:
		 virtual ~IWrappedProtocol() = 0;
	};

	class IGetBindHandle : IUnknown
	{
	public:
		//Virtual
		struct GetBindHandle
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IGetBindHandle* pThis;
			::BINDHANDLETYPES enumRequestedHandle;
			::HANDLE* pRetHandle;
		};

	private:
		 virtual ~IGetBindHandle() = 0;
	};

	class IBindCallbackRedirect : IUnknown
	{
	public:
		//Virtual
		struct Redirect
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IBindCallbackRedirect* pThis;
			::LPCWSTR lpcUrl;
			::VARIANT_BOOL* vbCancel;
		};

	private:
		 virtual ~IBindCallbackRedirect() = 0;
	};

	class IBindHttpSecurity : IUnknown
	{
	public:
		//Virtual
		struct GetIgnoreCertMask
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IBindHttpSecurity* pThis;
			::DWORD* pdwIgnoreCertMask;
		};

	private:
		 virtual ~IBindHttpSecurity() = 0;
	};

	class IPrintDialogCallback : IUnknown
	{
	public:
		//Virtual
		struct QueryInterface
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IPrintDialogCallback* pThis;
			const ::IID& riid;
			void** ppvObj;
		};

		//Virtual
		struct AddRef
		{
			using ReturnType_t = ::ULONG;
			static constexpr size_t Argc = 1;

			::IPrintDialogCallback* pThis;
		};

		//Virtual
		struct Release
		{
			using ReturnType_t = ::ULONG;
			static constexpr size_t Argc = 1;

			::IPrintDialogCallback* pThis;
		};

		//Virtual
		struct InitDone
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IPrintDialogCallback* pThis;
		};

		//Virtual
		struct SelectionChange
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IPrintDialogCallback* pThis;
		};

		//Virtual
		struct HandleMessage
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IPrintDialogCallback* pThis;
			::HWND hDlg;
			::UINT uMsg;
			::WPARAM wParam;
			::LPARAM lParam;
			::LRESULT* pResult;
		};

	private:
		 virtual ~IPrintDialogCallback() = 0;
	};

	class IPrintDialogServices : IUnknown
	{
	public:
		//Virtual
		struct QueryInterface
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IPrintDialogServices* pThis;
			const ::IID& riid;
			void** ppvObj;
		};

		//Virtual
		struct AddRef
		{
			using ReturnType_t = ::ULONG;
			static constexpr size_t Argc = 1;

			::IPrintDialogServices* pThis;
		};

		//Virtual
		struct Release
		{
			using ReturnType_t = ::ULONG;
			static constexpr size_t Argc = 1;

			::IPrintDialogServices* pThis;
		};

		//Virtual
		struct GetCurrentDevMode
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IPrintDialogServices* pThis;
			::LPDEVMODE pDevMode;
			::UINT* pcbSize;
		};

		//Virtual
		struct GetCurrentPrinterName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IPrintDialogServices* pThis;
			::LPWSTR pPrinterName;
			::UINT* pcchSize;
		};

		//Virtual
		struct GetCurrentPortName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IPrintDialogServices* pThis;
			::LPWSTR pPortName;
			::UINT* pcchSize;
		};

	private:
		 virtual ~IPrintDialogServices() = 0;
	};

	class IEnumConnections : IUnknown
	{
	public:
		//Virtual
		struct Next
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IEnumConnections* pThis;
			::ULONG cConnections;
			::LPCONNECTDATA rgcd;
			::ULONG* pcFetched;
		};

		//Virtual
		struct Skip
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IEnumConnections* pThis;
			::ULONG cConnections;
		};

		//Virtual
		struct Reset
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IEnumConnections* pThis;
		};

		//Virtual
		struct Clone
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IEnumConnections* pThis;
			::IEnumConnections** ppEnum;
		};

	private:
		 virtual ~IEnumConnections() = 0;
	};

	class IConnectionPoint : IUnknown
	{
	public:
		//Virtual
		struct GetConnectionInterface
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IConnectionPoint* pThis;
			::IID* pIID;
		};

		//Virtual
		struct GetConnectionPointContainer
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IConnectionPoint* pThis;
			IConnectionPointContainer** ppCPC;
		};

		//Virtual
		struct Advise
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IConnectionPoint* pThis;
			::IUnknown* pUnkSink;
			::DWORD* pdwCookie;
		};

		//Virtual
		struct Unadvise
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IConnectionPoint* pThis;
			::DWORD dwCookie;
		};

		//Virtual
		struct EnumConnections
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IConnectionPoint* pThis;
			::IEnumConnections** ppEnum;
		};

	private:
		 virtual ~IConnectionPoint() = 0;
	};

	class IEnumConnectionPoints : IUnknown
	{
	public:
		//Virtual
		struct Next
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IEnumConnectionPoints* pThis;
			::ULONG cConnections;
			::LPCONNECTIONPOINT* ppCP;
			::ULONG* pcFetched;
		};

		//Virtual
		struct Skip
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IEnumConnectionPoints* pThis;
			::ULONG cConnections;
		};

		//Virtual
		struct Reset
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IEnumConnectionPoints* pThis;
		};

		//Virtual
		struct Clone
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IEnumConnectionPoints* pThis;
			IEnumConnectionPoints** ppEnum;
		};

	private:
		 virtual ~IEnumConnectionPoints() = 0;
	};

	class IConnectionPointContainer : IUnknown
	{
	public:
		//Virtual
		struct EnumConnectionPoints
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IConnectionPointContainer* pThis;
			IEnumConnectionPoints** ppEnum;
		};

		//Virtual
		struct FindConnectionPoint
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IConnectionPointContainer* pThis;
			const ::IID& riid;
			IConnectionPoint** ppCP;
		};

	private:
		 virtual ~IConnectionPointContainer() = 0;
	};

	class IClassFactory2 : IClassFactory
	{
	public:
		//Virtual
		struct GetLicInfo
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IClassFactory2* pThis;
			::LICINFO* pLicInfo;
		};

		//Virtual
		struct RequestLicKey
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IClassFactory2* pThis;
			::DWORD dwReserved;
			::BSTR* pBstrKey;
		};

		//Virtual
		struct CreateInstanceLic
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IClassFactory2* pThis;
			::IUnknown* pUnkOuter;
			::IUnknown* pUnkReserved;
			const ::IID& riid;
			::BSTR bstrKey;
			::PVOID* ppvObj;
		};

	private:
		 virtual ~IClassFactory2() = 0;
	};

	class IProvideClassInfo : IUnknown
	{
	public:
		//Virtual
		struct GetClassInfoA
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IProvideClassInfo* pThis;
			::ITypeInfo** ppTI;
		};

	private:
		 virtual ~IProvideClassInfo() = 0;
	};

	class IProvideClassInfo2 : IProvideClassInfo
	{
	public:
		//Virtual
		struct GetGUID
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IProvideClassInfo2* pThis;
			::DWORD dwGuidKind;
			::GUID* pGUID;
		};

	private:
		 virtual ~IProvideClassInfo2() = 0;
	};

	class IProvideMultipleClassInfo : IProvideClassInfo2
	{
	public:
		//Virtual
		struct GetMultiTypeInfoCount
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IProvideMultipleClassInfo* pThis;
			::ULONG* pcti;
		};

		//Virtual
		struct GetInfoOfIndex
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 8;

			::IProvideMultipleClassInfo* pThis;
			::ULONG iti;
			::DWORD dwFlags;
			::ITypeInfo** pptiCoClass;
			::DWORD* pdwTIFlags;
			::ULONG* pcdispidReserved;
			::IID* piidPrimary;
			::IID* piidSource;
		};

	private:
		 virtual ~IProvideMultipleClassInfo() = 0;
	};

	class IOleControl : IUnknown
	{
	public:
		//Virtual
		struct GetControlInfo
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleControl* pThis;
			::CONTROLINFO* pCI;
		};

		//Virtual
		struct OnMnemonic
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleControl* pThis;
			::MSG* pMsg;
		};

		//Virtual
		struct OnAmbientPropertyChange
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleControl* pThis;
			::DISPID dispID;
		};

		//Virtual
		struct FreezeEvents
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleControl* pThis;
			::BOOL bFreeze;
		};

	private:
		 virtual ~IOleControl() = 0;
	};

	class IOleControlSite : IUnknown
	{
	public:
		//Virtual
		struct OnControlInfoChanged
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IOleControlSite* pThis;
		};

		//Virtual
		struct LockInPlaceActive
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleControlSite* pThis;
			::BOOL fLock;
		};

		//Virtual
		struct GetExtendedControl
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleControlSite* pThis;
			::IDispatch** ppDisp;
		};

		//Virtual
		struct TransformCoords
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IOleControlSite* pThis;
			::POINTL* pPtlHimetric;
			::POINTF* pPtfContainer;
			::DWORD dwFlags;
		};

		//Virtual
		struct TranslateAcceleratorA
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IOleControlSite* pThis;
			::MSG* pMsg;
			::DWORD grfModifiers;
		};

		//Virtual
		struct OnFocus
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleControlSite* pThis;
			::BOOL fGotFocus;
		};

		//Virtual
		struct ShowPropertyFrame
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IOleControlSite* pThis;
		};

	private:
		 virtual ~IOleControlSite() = 0;
	};

	class IPropertyPage : IUnknown
	{
	public:
		//Virtual
		struct SetPageSite
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPropertyPage* pThis;
			::IPropertyPageSite* pPageSite;
		};

		//Virtual
		struct Activate
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IPropertyPage* pThis;
			::HWND hWndParent;
			::LPCRECT pRect;
			::BOOL bModal;
		};

		//Virtual
		struct Deactivate
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IPropertyPage* pThis;
		};

		//Virtual
		struct GetPageInfo
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPropertyPage* pThis;
			::PROPPAGEINFO* pPageInfo;
		};

		//Virtual
		struct SetObjects
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IPropertyPage* pThis;
			::ULONG cObjects;
			::IUnknown** ppUnk;
		};

		//Virtual
		struct Show
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPropertyPage* pThis;
			::UINT nCmdShow;
		};

		//Virtual
		struct Move
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPropertyPage* pThis;
			::LPCRECT pRect;
		};

		//Virtual
		struct IsPageDirty
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IPropertyPage* pThis;
		};

		//Virtual
		struct Apply
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IPropertyPage* pThis;
		};

		//Virtual
		struct Help
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPropertyPage* pThis;
			::LPCOLESTR pszHelpDir;
		};

		//Virtual
		struct TranslateAcceleratorA
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPropertyPage* pThis;
			::MSG* pMsg;
		};

	private:
		 virtual ~IPropertyPage() = 0;
	};

	class IPropertyPage2 : IPropertyPage
	{
	public:
		//Virtual
		struct EditProperty
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPropertyPage2* pThis;
			::DISPID dispID;
		};

	private:
		 virtual ~IPropertyPage2() = 0;
	};

	class IPropertyPageSite : IUnknown
	{
	public:
		//Virtual
		struct OnStatusChange
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPropertyPageSite* pThis;
			::DWORD dwFlags;
		};

		//Virtual
		struct GetLocaleID
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPropertyPageSite* pThis;
			::LCID* pLocaleID;
		};

		//Virtual
		struct GetPageContainer
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPropertyPageSite* pThis;
			::IUnknown** ppUnk;
		};

		//Virtual
		struct TranslateAcceleratorA
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPropertyPageSite* pThis;
			::MSG* pMsg;
		};

	private:
		 virtual ~IPropertyPageSite() = 0;
	};

	class IPropertyNotifySink : IUnknown
	{
	public:
		//Virtual
		struct OnChanged
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPropertyNotifySink* pThis;
			::DISPID dispID;
		};

		//Virtual
		struct OnRequestEdit
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPropertyNotifySink* pThis;
			::DISPID dispID;
		};

	private:
		 virtual ~IPropertyNotifySink() = 0;
	};

	class ISpecifyPropertyPages : IUnknown
	{
	public:
		//Virtual
		struct GetPages
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ISpecifyPropertyPages* pThis;
			::CAUUID* pPages;
		};

	private:
		 virtual ~ISpecifyPropertyPages() = 0;
	};

	class IPersistMemory : IPersist
	{
	public:
		//Virtual
		struct IsDirty
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IPersistMemory* pThis;
		};

		//Virtual
		struct Load
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IPersistMemory* pThis;
			::LPVOID pMem;
			::ULONG cbSize;
		};

		//Virtual
		struct Save
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IPersistMemory* pThis;
			::LPVOID pMem;
			::BOOL fClearDirty;
			::ULONG cbSize;
		};

		//Virtual
		struct GetSizeMax
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPersistMemory* pThis;
			::ULONG* pCbSize;
		};

		//Virtual
		struct InitNew
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IPersistMemory* pThis;
		};

	private:
		 virtual ~IPersistMemory() = 0;
	};

	class IPersistStreamInit : IPersist
	{
	public:
		//Virtual
		struct IsDirty
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IPersistStreamInit* pThis;
		};

		//Virtual
		struct Load
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPersistStreamInit* pThis;
			::LPSTREAM pStm;
		};

		//Virtual
		struct Save
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IPersistStreamInit* pThis;
			::LPSTREAM pStm;
			::BOOL fClearDirty;
		};

		//Virtual
		struct GetSizeMax
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPersistStreamInit* pThis;
			::ULARGE_INTEGER* pCbSize;
		};

		//Virtual
		struct InitNew
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IPersistStreamInit* pThis;
		};

	private:
		 virtual ~IPersistStreamInit() = 0;
	};

	class IPersistPropertyBag : IPersist
	{
	public:
		//Virtual
		struct InitNew
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IPersistPropertyBag* pThis;
		};

		//Virtual
		struct Load
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IPersistPropertyBag* pThis;
			::IPropertyBag* pPropBag;
			::IErrorLog* pErrorLog;
		};

		//Virtual
		struct Save
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IPersistPropertyBag* pThis;
			::IPropertyBag* pPropBag;
			::BOOL fClearDirty;
			::BOOL fSaveAllProperties;
		};

	private:
		 virtual ~IPersistPropertyBag() = 0;
	};

	class ISimpleFrameSite : IUnknown
	{
	public:
		//Virtual
		struct PreMessageFilter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 7;

			::ISimpleFrameSite* pThis;
			::HWND hWnd;
			::UINT msg;
			::WPARAM wp;
			::LPARAM lp;
			::LRESULT* plResult;
			::DWORD* pdwCookie;
		};

		//Virtual
		struct PostMessageFilter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 7;

			::ISimpleFrameSite* pThis;
			::HWND hWnd;
			::UINT msg;
			::WPARAM wp;
			::LPARAM lp;
			::LRESULT* plResult;
			::DWORD dwCookie;
		};

	private:
		 virtual ~ISimpleFrameSite() = 0;
	};

	class IFont : IUnknown
	{
	public:
		//Virtual
		struct get_Name
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IFont* pThis;
			::BSTR* pName;
		};

		//Virtual
		struct put_Name
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IFont* pThis;
			::BSTR name;
		};

		//Virtual
		struct get_Size
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IFont* pThis;
			::CY* pSize;
		};

		//Virtual
		struct put_Size
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IFont* pThis;
			::CY size;
		};

		//Virtual
		struct get_Bold
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IFont* pThis;
			::BOOL* pBold;
		};

		//Virtual
		struct put_Bold
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IFont* pThis;
			::BOOL bold;
		};

		//Virtual
		struct get_Italic
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IFont* pThis;
			::BOOL* pItalic;
		};

		//Virtual
		struct put_Italic
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IFont* pThis;
			::BOOL italic;
		};

		//Virtual
		struct get_Underline
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IFont* pThis;
			::BOOL* pUnderline;
		};

		//Virtual
		struct put_Underline
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IFont* pThis;
			::BOOL underline;
		};

		//Virtual
		struct get_Strikethrough
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IFont* pThis;
			::BOOL* pStrikethrough;
		};

		//Virtual
		struct put_Strikethrough
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IFont* pThis;
			::BOOL strikethrough;
		};

		//Virtual
		struct get_Weight
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IFont* pThis;
			::SHORT* pWeight;
		};

		//Virtual
		struct put_Weight
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IFont* pThis;
			::SHORT weight;
		};

		//Virtual
		struct get_Charset
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IFont* pThis;
			::SHORT* pCharset;
		};

		//Virtual
		struct put_Charset
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IFont* pThis;
			::SHORT charset;
		};

		//Virtual
		struct get_hFont
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IFont* pThis;
			::HFONT* phFont;
		};

		//Virtual
		struct Clone
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IFont* pThis;
			::IFont** ppFont;
		};

		//Virtual
		struct IsEqual
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IFont* pThis;
			::IFont* pFontOther;
		};

		//Virtual
		struct SetRatio
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IFont* pThis;
			::LONG cyLogical;
			::LONG cyHimetric;
		};

		//Virtual
		struct QueryTextMetrics
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IFont* pThis;
			::TEXTMETRICOLE* pTM;
		};

		//Virtual
		struct AddRefHfont
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IFont* pThis;
			::HFONT hFont;
		};

		//Virtual
		struct ReleaseHfont
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IFont* pThis;
			::HFONT hFont;
		};

		//Virtual
		struct SetHdc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IFont* pThis;
			::HDC hDC;
		};

	private:
		 virtual ~IFont() = 0;
	};

	class IPicture : IUnknown
	{
	public:
		//Virtual
		struct get_Handle
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPicture* pThis;
			::OLE_HANDLE* pHandle;
		};

		//Virtual
		struct get_hPal
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPicture* pThis;
			::OLE_HANDLE* phPal;
		};

		//Virtual
		struct get_Type
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPicture* pThis;
			::SHORT* pType;
		};

		//Virtual
		struct get_Width
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPicture* pThis;
			::OLE_XSIZE_HIMETRIC* pWidth;
		};

		//Virtual
		struct get_Height
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPicture* pThis;
			::OLE_YSIZE_HIMETRIC* pHeight;
		};

		//Virtual
		struct Render
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 11;

			::IPicture* pThis;
			::HDC hDC;
			::LONG x;
			::LONG y;
			::LONG cx;
			::LONG cy;
			::OLE_XPOS_HIMETRIC xSrc;
			::OLE_YPOS_HIMETRIC ySrc;
			::OLE_XSIZE_HIMETRIC cxSrc;
			::OLE_YSIZE_HIMETRIC cySrc;
			::LPCRECT pRcWBounds;
		};

		//Virtual
		struct set_hPal
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPicture* pThis;
			::OLE_HANDLE hPal;
		};

		//Virtual
		struct get_CurDC
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPicture* pThis;
			::HDC* phDC;
		};

		//Virtual
		struct SelectPicture
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IPicture* pThis;
			::HDC hDCIn;
			::HDC* phDCOut;
			::OLE_HANDLE* phBmpOut;
		};

		//Virtual
		struct get_KeepOriginalFormat
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPicture* pThis;
			::BOOL* pKeep;
		};

		//Virtual
		struct put_KeepOriginalFormat
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPicture* pThis;
			::BOOL keep;
		};

		//Virtual
		struct PictureChanged
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IPicture* pThis;
		};

		//Virtual
		struct SaveAsFile
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IPicture* pThis;
			::LPSTREAM pStream;
			::BOOL fSaveMemCopy;
			::LONG* pCbSize;
		};

		//Virtual
		struct get_Attributes
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPicture* pThis;
			::DWORD* pDwAttr;
		};

	private:
		 virtual ~IPicture() = 0;
	};

	class IPicture2 : IUnknown
	{
	public:
		//Virtual
		struct get_Handle
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPicture2* pThis;
			::HHANDLE* pHandle;
		};

		//Virtual
		struct get_hPal
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPicture2* pThis;
			::HHANDLE* phPal;
		};

		//Virtual
		struct get_Type
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPicture2* pThis;
			::SHORT* pType;
		};

		//Virtual
		struct get_Width
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPicture2* pThis;
			::OLE_XSIZE_HIMETRIC* pWidth;
		};

		//Virtual
		struct get_Height
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPicture2* pThis;
			::OLE_YSIZE_HIMETRIC* pHeight;
		};

		//Virtual
		struct Render
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 11;

			::IPicture2* pThis;
			::HDC hDC;
			::LONG x;
			::LONG y;
			::LONG cx;
			::LONG cy;
			::OLE_XPOS_HIMETRIC xSrc;
			::OLE_YPOS_HIMETRIC ySrc;
			::OLE_XSIZE_HIMETRIC cxSrc;
			::OLE_YSIZE_HIMETRIC cySrc;
			::LPCRECT pRcWBounds;
		};

		//Virtual
		struct set_hPal
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPicture2* pThis;
			::HHANDLE hPal;
		};

		//Virtual
		struct get_CurDC
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPicture2* pThis;
			::HDC* phDC;
		};

		//Virtual
		struct SelectPicture
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IPicture2* pThis;
			::HDC hDCIn;
			::HDC* phDCOut;
			::HHANDLE* phBmpOut;
		};

		//Virtual
		struct get_KeepOriginalFormat
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPicture2* pThis;
			::BOOL* pKeep;
		};

		//Virtual
		struct put_KeepOriginalFormat
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPicture2* pThis;
			::BOOL keep;
		};

		//Virtual
		struct PictureChanged
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IPicture2* pThis;
		};

		//Virtual
		struct SaveAsFile
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IPicture2* pThis;
			::LPSTREAM pStream;
			::BOOL fSaveMemCopy;
			::LONG* pCbSize;
		};

		//Virtual
		struct get_Attributes
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPicture2* pThis;
			::DWORD* pDwAttr;
		};

	private:
		 virtual ~IPicture2() = 0;
	};

	class IOleInPlaceObjectWindowless : IOleInPlaceObject
	{
	public:
		//Virtual
		struct OnWindowMessage
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IOleInPlaceObjectWindowless* pThis;
			::UINT msg;
			::WPARAM wParam;
			::LPARAM lParam;
			::LRESULT* plResult;
		};

		//Virtual
		struct GetDropTarget
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleInPlaceObjectWindowless* pThis;
			::IDropTarget** ppDropTarget;
		};

	private:
		 virtual ~IOleInPlaceObjectWindowless() = 0;
	};

	class IOleInPlaceSiteEx : IOleInPlaceSite
	{
	public:
		//Virtual
		struct OnInPlaceActivateEx
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IOleInPlaceSiteEx* pThis;
			::BOOL* pfNoRedraw;
			::DWORD dwFlags;
		};

		//Virtual
		struct OnInPlaceDeactivateEx
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleInPlaceSiteEx* pThis;
			::BOOL fNoRedraw;
		};

		//Virtual
		struct RequestUIActivate
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IOleInPlaceSiteEx* pThis;
		};

	private:
		 virtual ~IOleInPlaceSiteEx() = 0;
	};

	class IOleInPlaceSiteWindowless : IOleInPlaceSiteEx
	{
	public:
		//Virtual
		struct CanWindowlessActivate
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IOleInPlaceSiteWindowless* pThis;
		};

		//Virtual
		struct GetCapture
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IOleInPlaceSiteWindowless* pThis;
		};

		//Virtual
		struct SetCapture
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleInPlaceSiteWindowless* pThis;
			::BOOL fCapture;
		};

		//Virtual
		struct GetFocus
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IOleInPlaceSiteWindowless* pThis;
		};

		//Virtual
		struct SetFocus
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleInPlaceSiteWindowless* pThis;
			::BOOL fFocus;
		};

		//Virtual
		struct GetDC
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IOleInPlaceSiteWindowless* pThis;
			::LPCRECT pRect;
			::DWORD grfFlags;
			::HDC* phDC;
		};

		//Virtual
		struct ReleaseDC
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleInPlaceSiteWindowless* pThis;
			::HDC hDC;
		};

		//Virtual
		struct InvalidateRect
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IOleInPlaceSiteWindowless* pThis;
			::LPCRECT pRect;
			::BOOL fErase;
		};

		//Virtual
		struct InvalidateRgn
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IOleInPlaceSiteWindowless* pThis;
			::HRGN hRGN;
			::BOOL fErase;
		};

		//Virtual
		struct ScrollRect
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IOleInPlaceSiteWindowless* pThis;
			::INT dx;
			::INT dy;
			::LPCRECT pRectScroll;
			::LPCRECT pRectClip;
		};

		//Virtual
		struct AdjustRect
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleInPlaceSiteWindowless* pThis;
			::LPRECT prc;
		};

		//Virtual
		struct OnDefWindowMessage
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IOleInPlaceSiteWindowless* pThis;
			::UINT msg;
			::WPARAM wParam;
			::LPARAM lParam;
			::LRESULT* plResult;
		};

	private:
		 virtual ~IOleInPlaceSiteWindowless() = 0;
	};

	class IViewObjectEx : IViewObject2
	{
	public:
		//Virtual
		struct GetRect
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IViewObjectEx* pThis;
			::DWORD dwAspect;
			::LPRECTL pRect;
		};

		//Virtual
		struct GetViewStatus
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IViewObjectEx* pThis;
			::DWORD* pdwStatus;
		};

		//Virtual
		struct QueryHitPoint
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IViewObjectEx* pThis;
			::DWORD dwAspect;
			::LPCRECT pRectBounds;
			::POINT ptlLoc;
			::LONG lCloseHint;
			::DWORD* pHitResult;
		};

		//Virtual
		struct QueryHitRect
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IViewObjectEx* pThis;
			::DWORD dwAspect;
			::LPCRECT pRectBounds;
			::LPCRECT pRectLoc;
			::LONG lCloseHint;
			::DWORD* pHitResult;
		};

		//Virtual
		struct GetNaturalExtent
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 7;

			::IViewObjectEx* pThis;
			::DWORD dwAspect;
			::LONG lindex;
			::DVTARGETDEVICE* ptd;
			::HDC hicTargetDev;
			::DVEXTENTINFO* pExtentInfo;
			::LPSIZEL pSizel;
		};

	private:
		 virtual ~IViewObjectEx() = 0;
	};

	class IOleUndoUnit : IUnknown
	{
	public:
		//Virtual
		struct Do
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleUndoUnit* pThis;
			::IOleUndoManager* pUndoManager;
		};

		//Virtual
		struct GetDescription
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleUndoUnit* pThis;
			::BSTR* pBstr;
		};

		//Virtual
		struct GetUnitType
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IOleUndoUnit* pThis;
			::CLSID* pClsid;
			::LONG* plID;
		};

		//Virtual
		struct OnNextAdd
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IOleUndoUnit* pThis;
		};

	private:
		 virtual ~IOleUndoUnit() = 0;
	};

	class IOleParentUndoUnit : IOleUndoUnit
	{
	public:
		//Virtual
		struct Open
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleParentUndoUnit* pThis;
			::IOleParentUndoUnit* pPUU;
		};

		//Virtual
		struct Close
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IOleParentUndoUnit* pThis;
			::IOleParentUndoUnit* pPUU;
			::BOOL fCommit;
		};

		//Virtual
		struct Add
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleParentUndoUnit* pThis;
			::IOleUndoUnit* pUU;
		};

		//Virtual
		struct FindUnit
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleParentUndoUnit* pThis;
			::IOleUndoUnit* pUU;
		};

		//Virtual
		struct GetParentState
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleParentUndoUnit* pThis;
			::DWORD* pdwState;
		};

	private:
		 virtual ~IOleParentUndoUnit() = 0;
	};

	class IEnumOleUndoUnits : IUnknown
	{
	public:
		//Virtual
		struct Next
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IEnumOleUndoUnits* pThis;
			::ULONG cElt;
			::IOleUndoUnit** rgElt;
			::ULONG* pcEltFetched;
		};

		//Virtual
		struct Skip
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IEnumOleUndoUnits* pThis;
			::ULONG cElt;
		};

		//Virtual
		struct Reset
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IEnumOleUndoUnits* pThis;
		};

		//Virtual
		struct Clone
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IEnumOleUndoUnits* pThis;
			::IEnumOleUndoUnits** ppEnum;
		};

	private:
		 virtual ~IEnumOleUndoUnits() = 0;
	};

	class IOleUndoManager : IUnknown
	{
	public:
		//Virtual
		struct Open
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleUndoManager* pThis;
			::IOleParentUndoUnit* pPUU;
		};

		//Virtual
		struct Close
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IOleUndoManager* pThis;
			::IOleParentUndoUnit* pPUU;
			::BOOL fCommit;
		};

		//Virtual
		struct Add
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleUndoManager* pThis;
			::IOleUndoUnit* pUU;
		};

		//Virtual
		struct GetOpenParentState
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleUndoManager* pThis;
			::DWORD* pdwState;
		};

		//Virtual
		struct DiscardFrom
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleUndoManager* pThis;
			::IOleUndoUnit* pUU;
		};

		//Virtual
		struct UndoTo
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleUndoManager* pThis;
			::IOleUndoUnit* pUU;
		};

		//Virtual
		struct RedoTo
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleUndoManager* pThis;
			::IOleUndoUnit* pUU;
		};

		//Virtual
		struct EnumUndoable
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleUndoManager* pThis;
			::IEnumOleUndoUnits** ppEnum;
		};

		//Virtual
		struct EnumRedoable
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleUndoManager* pThis;
			::IEnumOleUndoUnits** ppEnum;
		};

		//Virtual
		struct GetLastUndoDescription
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleUndoManager* pThis;
			::BSTR* pBstr;
		};

		//Virtual
		struct GetLastRedoDescription
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleUndoManager* pThis;
			::BSTR* pBstr;
		};

		//Virtual
		struct Enable
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IOleUndoManager* pThis;
			::BOOL fEnable;
		};

	private:
		 virtual ~IOleUndoManager() = 0;
	};

	class IPointerInactive : IUnknown
	{
	public:
		//Virtual
		struct GetActivationPolicy
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPointerInactive* pThis;
			::DWORD* pdwPolicy;
		};

		//Virtual
		struct OnInactiveMouseMove
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IPointerInactive* pThis;
			::LPCRECT pRectBounds;
			::LONG x;
			::LONG y;
			::DWORD grfKeyState;
		};

		//Virtual
		struct OnInactiveSetCursor
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IPointerInactive* pThis;
			::LPCRECT pRectBounds;
			::LONG x;
			::LONG y;
			::DWORD dwMouseMsg;
			::BOOL fSetAlways;
		};

	private:
		 virtual ~IPointerInactive() = 0;
	};

	class IObjectWithSite : IUnknown
	{
	public:
		//Virtual
		struct SetSite
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IObjectWithSite* pThis;
			::IUnknown* pUnkSite;
		};

		//Virtual
		struct GetSite
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IObjectWithSite* pThis;
			const ::IID& riid;
			void** ppvSite;
		};

	private:
		 virtual ~IObjectWithSite() = 0;
	};

	class IPerPropertyBrowsing : IUnknown
	{
	public:
		//Virtual
		struct GetDisplayString
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IPerPropertyBrowsing* pThis;
			::DISPID dispID;
			::BSTR* pBstr;
		};

		//Virtual
		struct MapPropertyToPage
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IPerPropertyBrowsing* pThis;
			::DISPID dispID;
			::CLSID* pClsid;
		};

		//Virtual
		struct GetPredefinedStrings
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IPerPropertyBrowsing* pThis;
			::DISPID dispID;
			::CALPOLESTR* pCaStringsOut;
			::CADWORD* pCaCookiesOut;
		};

		//Virtual
		struct GetPredefinedValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IPerPropertyBrowsing* pThis;
			::DISPID dispID;
			::DWORD dwCookie;
			::VARIANT* pVarOut;
		};

	private:
		 virtual ~IPerPropertyBrowsing() = 0;
	};

	class IPropertyBag2 : IUnknown
	{
	public:
		//Virtual
		struct Read
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IPropertyBag2* pThis;
			::ULONG cProperties;
			::PROPBAG2* pPropBag;
			::IErrorLog* pErrLog;
			::VARIANT* pvarValue;
			::HRESULT* phrError;
		};

		//Virtual
		struct Write
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IPropertyBag2* pThis;
			::ULONG cProperties;
			::PROPBAG2* pPropBag;
			::VARIANT* pvarValue;
		};

		//Virtual
		struct CountProperties
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IPropertyBag2* pThis;
			::ULONG* pcProperties;
		};

		//Virtual
		struct GetPropertyInfo
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IPropertyBag2* pThis;
			::ULONG iProperty;
			::ULONG cProperties;
			::PROPBAG2* pPropBag;
			::ULONG* pcProperties;
		};

		//Virtual
		struct LoadObject
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IPropertyBag2* pThis;
			::LPCOLESTR pstrName;
			::DWORD dwHint;
			::IUnknown* pUnkObject;
			::IErrorLog* pErrLog;
		};

	private:
		 virtual ~IPropertyBag2() = 0;
	};

	class IPersistPropertyBag2 : IPersist
	{
	public:
		//Virtual
		struct InitNew
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IPersistPropertyBag2* pThis;
		};

		//Virtual
		struct Load
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IPersistPropertyBag2* pThis;
			::IPropertyBag2* pPropBag;
			::IErrorLog* pErrLog;
		};

		//Virtual
		struct Save
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IPersistPropertyBag2* pThis;
			::IPropertyBag2* pPropBag;
			::BOOL fClearDirty;
			::BOOL fSaveAllProperties;
		};

		//Virtual
		struct IsDirty
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IPersistPropertyBag2* pThis;
		};

	private:
		 virtual ~IPersistPropertyBag2() = 0;
	};

	class IAdviseSinkEx : IAdviseSink
	{
	public:
		//Virtual
		struct OnViewStatusChange
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::IAdviseSinkEx* pThis;
			::DWORD dwViewStatus;
		};

	private:
		 virtual ~IAdviseSinkEx() = 0;
	};

	class IQuickActivate : IUnknown
	{
	public:
		//Virtual
		struct QuickActivate
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IQuickActivate* pThis;
			::QACONTAINER* pQaContainer;
			::QACONTROL* pQaControl;
		};

		//Virtual
		struct SetContentExtent
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IQuickActivate* pThis;
			::LPSIZEL pSizel;
		};

		//Virtual
		struct GetContentExtent
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IQuickActivate* pThis;
			::LPSIZEL pSizel;
		};

	private:
		 virtual ~IQuickActivate() = 0;
	};

	class IDXGIObject : IUnknown
	{
	public:
		//Virtual
		struct SetPrivateData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IDXGIObject* pThis;
			const ::GUID& Name;
			::UINT DataSize;
			const void* pData;
		};

		//Virtual
		struct SetPrivateDataInterface
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDXGIObject* pThis;
			const ::GUID& Name;
			const ::IUnknown* pUnknown;
		};

		//Virtual
		struct GetPrivateData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IDXGIObject* pThis;
			const ::GUID& Name;
			::UINT* pDataSize;
			void* pData;
		};

		//Virtual
		struct GetParent
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDXGIObject* pThis;
			const ::IID& riid;
			void** ppParent;
		};

	private:
		 virtual ~IDXGIObject() = 0;
	};

	class IDXGIDeviceSubObject : IDXGIObject
	{
	public:
		//Virtual
		struct GetDevice
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDXGIDeviceSubObject* pThis;
			const ::IID& riid;
			void** ppDevice;
		};

	private:
		 virtual ~IDXGIDeviceSubObject() = 0;
	};

	class IDXGIResource : IDXGIDeviceSubObject
	{
	public:
		//Virtual
		struct GetSharedHandle
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGIResource* pThis;
			::HANDLE* pSharedHandle;
		};

		//Virtual
		struct GetUsage
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGIResource* pThis;
			::DXGI_USAGE* pUsage;
		};

		//Virtual
		struct SetEvictionPriority
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGIResource* pThis;
			::UINT EvictionPriority;
		};

		//Virtual
		struct GetEvictionPriority
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGIResource* pThis;
			::UINT* pEvictionPriority;
		};

	private:
		 virtual ~IDXGIResource() = 0;
	};

	class IDXGIKeyedMutex : IDXGIDeviceSubObject
	{
	public:
		//Virtual
		struct AcquireSync
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDXGIKeyedMutex* pThis;
			::UINT64 Key;
			::DWORD dwMilliseconds;
		};

		//Virtual
		struct ReleaseSync
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGIKeyedMutex* pThis;
			::UINT64 Key;
		};

	private:
		 virtual ~IDXGIKeyedMutex() = 0;
	};

	class IDXGISurface : IDXGIDeviceSubObject
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGISurface* pThis;
			::DXGI_SURFACE_DESC* pDesc;
		};

		//Virtual
		struct Map
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDXGISurface* pThis;
			::DXGI_MAPPED_RECT* pLockedRect;
			::UINT MapFlags;
		};

		//Virtual
		struct Unmap
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IDXGISurface* pThis;
		};

	private:
		 virtual ~IDXGISurface() = 0;
	};

	class IDXGISurface1 : IDXGISurface
	{
	public:
		//Virtual
		struct GetDC
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDXGISurface1* pThis;
			::BOOL Discard;
			::HDC* phdc;
		};

		//Virtual
		struct ReleaseDC
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGISurface1* pThis;
			::RECT* pDirtyRect;
		};

	private:
		 virtual ~IDXGISurface1() = 0;
	};

	class IDXGIAdapter : IDXGIObject
	{
	public:
		//Virtual
		struct EnumOutputs
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDXGIAdapter* pThis;
			::UINT Output;
			::IDXGIOutput** ppOutput;
		};

		//Virtual
		struct GetDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGIAdapter* pThis;
			::DXGI_ADAPTER_DESC* pDesc;
		};

		//Virtual
		struct CheckInterfaceSupport
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDXGIAdapter* pThis;
			const ::GUID& InterfaceName;
			::LARGE_INTEGER* pUMDVersion;
		};

	private:
		 virtual ~IDXGIAdapter() = 0;
	};

	class IDXGIOutput : IDXGIObject
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGIOutput* pThis;
			::DXGI_OUTPUT_DESC* pDesc;
		};

		//Virtual
		struct GetDisplayModeList
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IDXGIOutput* pThis;
			::DXGI_FORMAT EnumFormat;
			::UINT Flags;
			::UINT* pNumModes;
			::DXGI_MODE_DESC* pDesc;
		};

		//Virtual
		struct FindClosestMatchingMode
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IDXGIOutput* pThis;
			const ::DXGI_MODE_DESC* pModeToMatch;
			::DXGI_MODE_DESC* pClosestMatch;
			::IUnknown* pConcernedDevice;
		};

		//Virtual
		struct WaitForVBlank
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IDXGIOutput* pThis;
		};

		//Virtual
		struct TakeOwnership
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDXGIOutput* pThis;
			::IUnknown* pDevice;
			::BOOL Exclusive;
		};

		//Virtual
		struct ReleaseOwnership
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::IDXGIOutput* pThis;
		};

		//Virtual
		struct GetGammaControlCapabilities
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGIOutput* pThis;
			::DXGI_GAMMA_CONTROL_CAPABILITIES* pGammaCaps;
		};

		//Virtual
		struct SetGammaControl
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGIOutput* pThis;
			const ::DXGI_GAMMA_CONTROL* pArray;
		};

		//Virtual
		struct GetGammaControl
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGIOutput* pThis;
			::DXGI_GAMMA_CONTROL* pArray;
		};

		//Virtual
		struct SetDisplaySurface
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGIOutput* pThis;
			::IDXGISurface* pScanoutSurface;
		};

		//Virtual
		struct GetDisplaySurfaceData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGIOutput* pThis;
			::IDXGISurface* pDestination;
		};

		//Virtual
		struct GetFrameStatistics
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGIOutput* pThis;
			::DXGI_FRAME_STATISTICS* pStats;
		};

	private:
		 virtual ~IDXGIOutput() = 0;
	};

	class IDXGISwapChain : IDXGIDeviceSubObject
	{
	public:
		//Virtual
		struct Present
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDXGISwapChain* pThis;
			::UINT SyncInterval;
			::UINT Flags;
		};

		//Virtual
		struct GetBuffer
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IDXGISwapChain* pThis;
			::UINT Buffer;
			const ::IID& riid;
			void** ppSurface;
		};

		//Virtual
		struct SetFullscreenState
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDXGISwapChain* pThis;
			::BOOL Fullscreen;
			::IDXGIOutput* pTarget;
		};

		//Virtual
		struct GetFullscreenState
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDXGISwapChain* pThis;
			::BOOL* pFullscreen;
			::IDXGIOutput** ppTarget;
		};

		//Virtual
		struct GetDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGISwapChain* pThis;
			::DXGI_SWAP_CHAIN_DESC* pDesc;
		};

		//Virtual
		struct ResizeBuffers
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IDXGISwapChain* pThis;
			::UINT BufferCount;
			::UINT Width;
			::UINT Height;
			::DXGI_FORMAT NewFormat;
			::UINT SwapChainFlags;
		};

		//Virtual
		struct ResizeTarget
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGISwapChain* pThis;
			const ::DXGI_MODE_DESC* pNewTargetParameters;
		};

		//Virtual
		struct GetContainingOutput
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGISwapChain* pThis;
			::IDXGIOutput** ppOutput;
		};

		//Virtual
		struct GetFrameStatistics
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGISwapChain* pThis;
			::DXGI_FRAME_STATISTICS* pStats;
		};

		//Virtual
		struct GetLastPresentCount
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGISwapChain* pThis;
			::UINT* pLastPresentCount;
		};

	private:
		 virtual ~IDXGISwapChain() = 0;
	};

	class IDXGIFactory : IDXGIObject
	{
	public:
		//Virtual
		struct EnumAdapters
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDXGIFactory* pThis;
			::UINT Adapter;
			::IDXGIAdapter** ppAdapter;
		};

		//Virtual
		struct MakeWindowAssociation
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDXGIFactory* pThis;
			::HWND WindowHandle;
			::UINT Flags;
		};

		//Virtual
		struct GetWindowAssociation
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGIFactory* pThis;
			::HWND* pWindowHandle;
		};

		//Virtual
		struct CreateSwapChain
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IDXGIFactory* pThis;
			::IUnknown* pDevice;
			::DXGI_SWAP_CHAIN_DESC* pDesc;
			::IDXGISwapChain** ppSwapChain;
		};

		//Virtual
		struct CreateSoftwareAdapter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDXGIFactory* pThis;
			::HMODULE Module;
			::IDXGIAdapter** ppAdapter;
		};

	private:
		 virtual ~IDXGIFactory() = 0;
	};

	class IDXGIDevice : IDXGIObject
	{
	public:
		//Virtual
		struct GetAdapter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGIDevice* pThis;
			::IDXGIAdapter** pAdapter;
		};

		//Virtual
		struct CreateSurface
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IDXGIDevice* pThis;
			const ::DXGI_SURFACE_DESC* pDesc;
			::UINT NumSurfaces;
			::DXGI_USAGE Usage;
			const ::DXGI_SHARED_RESOURCE* pSharedResource;
			::IDXGISurface** ppSurface;
		};

		//Virtual
		struct QueryResourceResidency
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IDXGIDevice* pThis;
			::IUnknown*const* ppResources;
			::DXGI_RESIDENCY* pResidencyStatus;
			::UINT NumResources;
		};

		//Virtual
		struct SetGPUThreadPriority
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGIDevice* pThis;
			::INT Priority;
		};

		//Virtual
		struct GetGPUThreadPriority
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGIDevice* pThis;
			::INT* pPriority;
		};

	private:
		 virtual ~IDXGIDevice() = 0;
	};

	class IDXGIFactory1 : IDXGIFactory
	{
	public:
		//Virtual
		struct EnumAdapters1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDXGIFactory1* pThis;
			::UINT Adapter;
			::IDXGIAdapter1** ppAdapter;
		};

		//Virtual
		struct IsCurrent
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 1;

			::IDXGIFactory1* pThis;
		};

	private:
		 virtual ~IDXGIFactory1() = 0;
	};

	class IDXGIAdapter1 : IDXGIAdapter
	{
	public:
		//Virtual
		struct GetDesc1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGIAdapter1* pThis;
			::DXGI_ADAPTER_DESC1* pDesc;
		};

	private:
		 virtual ~IDXGIAdapter1() = 0;
	};

	class IDXGIDevice1 : IDXGIDevice
	{
	public:
		//Virtual
		struct SetMaximumFrameLatency
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGIDevice1* pThis;
			::UINT MaxLatency;
		};

		//Virtual
		struct GetMaximumFrameLatency
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGIDevice1* pThis;
			::UINT* pMaxLatency;
		};

	private:
		 virtual ~IDXGIDevice1() = 0;
	};

	class IDXGIDisplayControl : IUnknown
	{
	public:
		//Virtual
		struct IsStereoEnabled
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 1;

			::IDXGIDisplayControl* pThis;
		};

		//Virtual
		struct SetStereoEnabled
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::IDXGIDisplayControl* pThis;
			::BOOL enabled;
		};

	private:
		 virtual ~IDXGIDisplayControl() = 0;
	};

	class IDXGIOutputDuplication : IDXGIObject
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::IDXGIOutputDuplication* pThis;
			::DXGI_OUTDUPL_DESC* pDesc;
		};

		//Virtual
		struct AcquireNextFrame
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IDXGIOutputDuplication* pThis;
			::UINT TimeoutInMilliseconds;
			::DXGI_OUTDUPL_FRAME_INFO* pFrameInfo;
			::IDXGIResource** ppDesktopResource;
		};

		//Virtual
		struct GetFrameDirtyRects
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IDXGIOutputDuplication* pThis;
			::UINT DirtyRectsBufferSize;
			::RECT* pDirtyRectsBuffer;
			::UINT* pDirtyRectsBufferSizeRequired;
		};

		//Virtual
		struct GetFrameMoveRects
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IDXGIOutputDuplication* pThis;
			::UINT MoveRectsBufferSize;
			::DXGI_OUTDUPL_MOVE_RECT* pMoveRectBuffer;
			::UINT* pMoveRectsBufferSizeRequired;
		};

		//Virtual
		struct GetFramePointerShape
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IDXGIOutputDuplication* pThis;
			::UINT PointerShapeBufferSize;
			void* pPointerShapeBuffer;
			::UINT* pPointerShapeBufferSizeRequired;
			::DXGI_OUTDUPL_POINTER_SHAPE_INFO* pPointerShapeInfo;
		};

		//Virtual
		struct MapDesktopSurface
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGIOutputDuplication* pThis;
			::DXGI_MAPPED_RECT* pLockedRect;
		};

		//Virtual
		struct UnMapDesktopSurface
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IDXGIOutputDuplication* pThis;
		};

		//Virtual
		struct ReleaseFrame
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::IDXGIOutputDuplication* pThis;
		};

	private:
		 virtual ~IDXGIOutputDuplication() = 0;
	};

	class IDXGISurface2 : IDXGISurface1
	{
	public:
		//Virtual
		struct GetResource
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IDXGISurface2* pThis;
			const ::IID& riid;
			void** ppParentResource;
			::UINT* pSubresourceIndex;
		};

	private:
		 virtual ~IDXGISurface2() = 0;
	};

	class IDXGIResource1 : IDXGIResource
	{
	public:
		//Virtual
		struct CreateSubresourceSurface
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDXGIResource1* pThis;
			::UINT index;
			::IDXGISurface2** ppSurface;
		};

		//Virtual
		struct CreateSharedHandle
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IDXGIResource1* pThis;
			const ::SECURITY_ATTRIBUTES* pAttributes;
			::DWORD dwAccess;
			::LPCWSTR lpName;
			::HANDLE* pHandle;
		};

	private:
		 virtual ~IDXGIResource1() = 0;
	};

	class IDXGIDevice2 : IDXGIDevice1
	{
	public:
		//Virtual
		struct OfferResources
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IDXGIDevice2* pThis;
			::UINT NumResources;
			::IDXGIResource*const* ppResources;
			::DXGI_OFFER_RESOURCE_PRIORITY Priority;
		};

		//Virtual
		struct ReclaimResources
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IDXGIDevice2* pThis;
			::UINT NumResources;
			::IDXGIResource*const* ppResources;
			::BOOL* pDiscarded;
		};

		//Virtual
		struct EnqueueSetEvent
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGIDevice2* pThis;
			::HANDLE hEvent;
		};

	private:
		 virtual ~IDXGIDevice2() = 0;
	};

	class IDXGISwapChain1 : IDXGISwapChain
	{
	public:
		//Virtual
		struct GetDesc1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGISwapChain1* pThis;
			::DXGI_SWAP_CHAIN_DESC1* pDesc;
		};

		//Virtual
		struct GetFullscreenDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGISwapChain1* pThis;
			::DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pDesc;
		};

		//Virtual
		struct GetHwnd
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGISwapChain1* pThis;
			::HWND* pHwnd;
		};

		//Virtual
		struct GetCoreWindow
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDXGISwapChain1* pThis;
			const ::IID& refiid;
			void** ppUnk;
		};

		//Virtual
		struct Present1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IDXGISwapChain1* pThis;
			::UINT SyncInterval;
			::UINT PresentFlags;
			const ::DXGI_PRESENT_PARAMETERS* pPresentParameters;
		};

		//Virtual
		struct IsTemporaryMonoSupported
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 1;

			::IDXGISwapChain1* pThis;
		};

		//Virtual
		struct GetRestrictToOutput
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGISwapChain1* pThis;
			::IDXGIOutput** ppRestrictToOutput;
		};

		//Virtual
		struct SetBackgroundColor
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGISwapChain1* pThis;
			const ::DXGI_RGBA* pColor;
		};

		//Virtual
		struct GetBackgroundColor
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGISwapChain1* pThis;
			::DXGI_RGBA* pColor;
		};

		//Virtual
		struct SetRotation
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGISwapChain1* pThis;
			::DXGI_MODE_ROTATION Rotation;
		};

		//Virtual
		struct GetRotation
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGISwapChain1* pThis;
			::DXGI_MODE_ROTATION* pRotation;
		};

	private:
		 virtual ~IDXGISwapChain1() = 0;
	};

	class IDXGIFactory2 : IDXGIFactory1
	{
	public:
		//Virtual
		struct IsWindowedStereoEnabled
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 1;

			::IDXGIFactory2* pThis;
		};

		//Virtual
		struct CreateSwapChainForHwnd
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 7;

			::IDXGIFactory2* pThis;
			::IUnknown* pDevice;
			::HWND hWnd;
			const ::DXGI_SWAP_CHAIN_DESC1* pDesc;
			const ::DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pFullscreenDesc;
			::IDXGIOutput* pRestrictToOutput;
			::IDXGISwapChain1** ppSwapChain;
		};

		//Virtual
		struct CreateSwapChainForCoreWindow
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IDXGIFactory2* pThis;
			::IUnknown* pDevice;
			::IUnknown* pWindow;
			const ::DXGI_SWAP_CHAIN_DESC1* pDesc;
			::IDXGIOutput* pRestrictToOutput;
			::IDXGISwapChain1** ppSwapChain;
		};

		//Virtual
		struct GetSharedResourceAdapterLuid
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDXGIFactory2* pThis;
			::HANDLE hResource;
			::LUID* pLuid;
		};

		//Virtual
		struct RegisterStereoStatusWindow
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IDXGIFactory2* pThis;
			::HWND WindowHandle;
			::UINT wMsg;
			::DWORD* pdwCookie;
		};

		//Virtual
		struct RegisterStereoStatusEvent
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDXGIFactory2* pThis;
			::HANDLE hEvent;
			::DWORD* pdwCookie;
		};

		//Virtual
		struct UnregisterStereoStatus
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::IDXGIFactory2* pThis;
			::DWORD dwCookie;
		};

		//Virtual
		struct RegisterOcclusionStatusWindow
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IDXGIFactory2* pThis;
			::HWND WindowHandle;
			::UINT wMsg;
			::DWORD* pdwCookie;
		};

		//Virtual
		struct RegisterOcclusionStatusEvent
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDXGIFactory2* pThis;
			::HANDLE hEvent;
			::DWORD* pdwCookie;
		};

		//Virtual
		struct UnregisterOcclusionStatus
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::IDXGIFactory2* pThis;
			::DWORD dwCookie;
		};

		//Virtual
		struct CreateSwapChainForComposition
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IDXGIFactory2* pThis;
			::IUnknown* pDevice;
			const ::DXGI_SWAP_CHAIN_DESC1* pDesc;
			::IDXGIOutput* pRestrictToOutput;
			::IDXGISwapChain1** ppSwapChain;
		};

	private:
		 virtual ~IDXGIFactory2() = 0;
	};

	class IDXGIAdapter2 : IDXGIAdapter1
	{
	public:
		//Virtual
		struct GetDesc2
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGIAdapter2* pThis;
			::DXGI_ADAPTER_DESC2* pDesc;
		};

	private:
		 virtual ~IDXGIAdapter2() = 0;
	};

	class IDXGIOutput1 : IDXGIOutput
	{
	public:
		//Virtual
		struct GetDisplayModeList1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IDXGIOutput1* pThis;
			::DXGI_FORMAT EnumFormat;
			::UINT Flags;
			::UINT* pNumModes;
			::DXGI_MODE_DESC1* pDesc;
		};

		//Virtual
		struct FindClosestMatchingMode1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IDXGIOutput1* pThis;
			const ::DXGI_MODE_DESC1* pModeToMatch;
			::DXGI_MODE_DESC1* pClosestMatch;
			::IUnknown* pConcernedDevice;
		};

		//Virtual
		struct GetDisplaySurfaceData1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGIOutput1* pThis;
			::IDXGIResource* pDestination;
		};

		//Virtual
		struct DuplicateOutput
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDXGIOutput1* pThis;
			::IUnknown* pDevice;
			::IDXGIOutputDuplication** ppOutputDuplication;
		};

	private:
		 virtual ~IDXGIOutput1() = 0;
	};

	class IDXGIDevice3 : IDXGIDevice2
	{
	public:
		//Virtual
		struct Trim
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::IDXGIDevice3* pThis;
		};

	private:
		 virtual ~IDXGIDevice3() = 0;
	};

	class IDXGISwapChain2 : IDXGISwapChain1
	{
	public:
		//Virtual
		struct SetSourceSize
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDXGISwapChain2* pThis;
			::UINT Width;
			::UINT Height;
		};

		//Virtual
		struct GetSourceSize
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDXGISwapChain2* pThis;
			::UINT* pWidth;
			::UINT* pHeight;
		};

		//Virtual
		struct SetMaximumFrameLatency
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGISwapChain2* pThis;
			::UINT MaxLatency;
		};

		//Virtual
		struct GetMaximumFrameLatency
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGISwapChain2* pThis;
			::UINT* pMaxLatency;
		};

		//Virtual
		struct GetFrameLatencyWaitableObject
		{
			using ReturnType_t = ::HANDLE;
			static constexpr size_t Argc = 1;

			::IDXGISwapChain2* pThis;
		};

		//Virtual
		struct SetMatrixTransform
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGISwapChain2* pThis;
			const ::DXGI_MATRIX_3X2_F* pMatrix;
		};

		//Virtual
		struct GetMatrixTransform
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGISwapChain2* pThis;
			::DXGI_MATRIX_3X2_F* pMatrix;
		};

	private:
		 virtual ~IDXGISwapChain2() = 0;
	};

	class IDXGIOutput2 : IDXGIOutput1
	{
	public:
		//Virtual
		struct SupportsOverlays
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 1;

			::IDXGIOutput2* pThis;
		};

	private:
		 virtual ~IDXGIOutput2() = 0;
	};

	class IDXGIFactory3 : IDXGIFactory2
	{
	public:
		//Virtual
		struct GetCreationFlags
		{
			using ReturnType_t = ::UINT;
			static constexpr size_t Argc = 1;

			::IDXGIFactory3* pThis;
		};

	private:
		 virtual ~IDXGIFactory3() = 0;
	};

	class IDXGIDecodeSwapChain : IUnknown
	{
	public:
		//Virtual
		struct PresentBuffer
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IDXGIDecodeSwapChain* pThis;
			::UINT BufferToPresent;
			::UINT SyncInterval;
			::UINT Flags;
		};

		//Virtual
		struct SetSourceRect
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGIDecodeSwapChain* pThis;
			const ::RECT* pRect;
		};

		//Virtual
		struct SetTargetRect
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGIDecodeSwapChain* pThis;
			const ::RECT* pRect;
		};

		//Virtual
		struct SetDestSize
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDXGIDecodeSwapChain* pThis;
			::UINT Width;
			::UINT Height;
		};

		//Virtual
		struct GetSourceRect
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGIDecodeSwapChain* pThis;
			::RECT* pRect;
		};

		//Virtual
		struct GetTargetRect
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGIDecodeSwapChain* pThis;
			::RECT* pRect;
		};

		//Virtual
		struct GetDestSize
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDXGIDecodeSwapChain* pThis;
			::UINT* pWidth;
			::UINT* pHeight;
		};

		//Virtual
		struct SetColorSpace
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGIDecodeSwapChain* pThis;
			::DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS ColorSpace;
		};

		//Virtual
		struct GetColorSpace
		{
			using ReturnType_t = ::DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS;
			static constexpr size_t Argc = 1;

			::IDXGIDecodeSwapChain* pThis;
		};

	private:
		 virtual ~IDXGIDecodeSwapChain() = 0;
	};

	class IDXGIFactoryMedia : IUnknown
	{
	public:
		//Virtual
		struct CreateSwapChainForCompositionSurfaceHandle
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IDXGIFactoryMedia* pThis;
			::IUnknown* pDevice;
			::HANDLE hSurface;
			const ::DXGI_SWAP_CHAIN_DESC1* pDesc;
			::IDXGIOutput* pRestrictToOutput;
			::IDXGISwapChain1** ppSwapChain;
		};

		//Virtual
		struct CreateDecodeSwapChainForCompositionSurfaceHandle
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 7;

			::IDXGIFactoryMedia* pThis;
			::IUnknown* pDevice;
			::HANDLE hSurface;
			::DXGI_DECODE_SWAP_CHAIN_DESC* pDesc;
			::IDXGIResource* pYuvDecodeBuffers;
			::IDXGIOutput* pRestrictToOutput;
			::IDXGIDecodeSwapChain** ppSwapChain;
		};

	private:
		 virtual ~IDXGIFactoryMedia() = 0;
	};

	class IDXGISwapChainMedia : IUnknown
	{
	public:
		//Virtual
		struct GetFrameStatisticsMedia
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGISwapChainMedia* pThis;
			::DXGI_FRAME_STATISTICS_MEDIA* pStats;
		};

		//Virtual
		struct SetPresentDuration
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGISwapChainMedia* pThis;
			::UINT Duration;
		};

		//Virtual
		struct CheckPresentDurationSupport
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IDXGISwapChainMedia* pThis;
			::UINT DesiredPresentDuration;
			::UINT* pClosestSmallerPresentDuration;
			::UINT* pClosestLargerPresentDuration;
		};

	private:
		 virtual ~IDXGISwapChainMedia() = 0;
	};

	class IDXGIOutput3 : IDXGIOutput2
	{
	public:
		//Virtual
		struct CheckOverlaySupport
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IDXGIOutput3* pThis;
			::DXGI_FORMAT EnumFormat;
			::IUnknown* pConcernedDevice;
			::UINT* pFlags;
		};

	private:
		 virtual ~IDXGIOutput3() = 0;
	};

	class IDXGISwapChain3 : IDXGISwapChain2
	{
	public:
		//Virtual
		struct GetCurrentBackBufferIndex
		{
			using ReturnType_t = ::UINT;
			static constexpr size_t Argc = 1;

			::IDXGISwapChain3* pThis;
		};

		//Virtual
		struct CheckColorSpaceSupport
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDXGISwapChain3* pThis;
			::DXGI_COLOR_SPACE_TYPE ColorSpace;
			::UINT* pColorSpaceSupport;
		};

		//Virtual
		struct SetColorSpace1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::IDXGISwapChain3* pThis;
			::DXGI_COLOR_SPACE_TYPE ColorSpace;
		};

		//Virtual
		struct ResizeBuffers1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 8;

			::IDXGISwapChain3* pThis;
			::UINT BufferCount;
			::UINT Width;
			::UINT Height;
			::DXGI_FORMAT Format;
			::UINT SwapChainFlags;
			const ::UINT* pCreationNodeMask;
			::IUnknown*const* ppPresentQueue;
		};

	private:
		 virtual ~IDXGISwapChain3() = 0;
	};

	class IDXGIOutput4 : IDXGIOutput3
	{
	public:
		//Virtual
		struct CheckOverlayColorSpaceSupport
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IDXGIOutput4* pThis;
			::DXGI_FORMAT Format;
			::DXGI_COLOR_SPACE_TYPE ColorSpace;
			::IUnknown* pConcernedDevice;
			::UINT* pFlags;
		};

	private:
		 virtual ~IDXGIOutput4() = 0;
	};

	class IDXGIFactory4 : IDXGIFactory3
	{
	public:
		//Virtual
		struct EnumAdapterByLuid
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IDXGIFactory4* pThis;
			::LUID AdapterLuid;
			const ::IID& riid;
			void** ppvAdapter;
		};

		//Virtual
		struct EnumWarpAdapter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDXGIFactory4* pThis;
			const ::IID& riid;
			void** ppvAdapter;
		};

	private:
		 virtual ~IDXGIFactory4() = 0;
	};

	class IDXGIAdapter3 : IDXGIAdapter2
	{
	public:
		//Virtual
		struct RegisterHardwareContentProtectionTeardownStatusEvent
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDXGIAdapter3* pThis;
			::HANDLE hEvent;
			::DWORD* pdwCookie;
		};

		//Virtual
		struct UnregisterHardwareContentProtectionTeardownStatus
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::IDXGIAdapter3* pThis;
			::DWORD dwCookie;
		};

		//Virtual
		struct QueryVideoMemoryInfo
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IDXGIAdapter3* pThis;
			::UINT NodeIndex;
			::DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup;
			::DXGI_QUERY_VIDEO_MEMORY_INFO* pVideoMemoryInfo;
		};

		//Virtual
		struct SetVideoMemoryReservation
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IDXGIAdapter3* pThis;
			::UINT NodeIndex;
			::DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup;
			::UINT64 Reservation;
		};

		//Virtual
		struct RegisterVideoMemoryBudgetChangeNotificationEvent
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::IDXGIAdapter3* pThis;
			::HANDLE hEvent;
			::DWORD* pdwCookie;
		};

		//Virtual
		struct UnregisterVideoMemoryBudgetChangeNotification
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::IDXGIAdapter3* pThis;
			::DWORD dwCookie;
		};

	private:
		 virtual ~IDXGIAdapter3() = 0;
	};

	class IDXGIOutput5 : IDXGIOutput4
	{
	public:
		//Virtual
		struct DuplicateOutput1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::IDXGIOutput5* pThis;
			::IUnknown* pDevice;
			::UINT Flags;
			::UINT SupportedFormatsCount;
			const ::DXGI_FORMAT* pSupportedFormats;
			::IDXGIOutputDuplication** ppOutputDuplication;
		};

	private:
		 virtual ~IDXGIOutput5() = 0;
	};

	class IDXGISwapChain4 : IDXGISwapChain3
	{
	public:
		//Virtual
		struct SetHDRMetaData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IDXGISwapChain4* pThis;
			::DXGI_HDR_METADATA_TYPE Type;
			::UINT Size;
			void* pMetaData;
		};

	private:
		 virtual ~IDXGISwapChain4() = 0;
	};

	class IDXGIDevice4 : IDXGIDevice3
	{
	public:
		//Virtual
		struct OfferResources1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::IDXGIDevice4* pThis;
			::UINT NumResources;
			::IDXGIResource*const* ppResources;
			::DXGI_OFFER_RESOURCE_PRIORITY Priority;
			::UINT Flags;
		};

		//Virtual
		struct ReclaimResources1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IDXGIDevice4* pThis;
			::UINT NumResources;
			::IDXGIResource*const* ppResources;
			::DXGI_RECLAIM_RESOURCE_RESULTS* pResults;
		};

	private:
		 virtual ~IDXGIDevice4() = 0;
	};

	class IDXGIFactory5 : IDXGIFactory4
	{
	public:
		//Virtual
		struct CheckFeatureSupport
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::IDXGIFactory5* pThis;
			::DXGI_FEATURE Feature;
			void* pFeatureSupportData;
			::UINT FeatureSupportDataSize;
		};

	private:
		 virtual ~IDXGIFactory5() = 0;
	};

	class ID3D10Blob : IUnknown
	{
	public:
		//Virtual
		struct GetBufferPointer
		{
			using ReturnType_t = ::LPVOID;
			static constexpr size_t Argc = 1;

			::ID3D10Blob* pThis;
		};

		//Virtual
		struct GetBufferSize
		{
			using ReturnType_t = ::SIZE_T;
			static constexpr size_t Argc = 1;

			::ID3D10Blob* pThis;
		};

	private:
		 virtual ~ID3D10Blob() = 0;
	};

	class ID3DDestructionNotifier : IUnknown
	{
	public:
		//Virtual
		struct RegisterDestructionCallback
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3DDestructionNotifier* pThis;
			::PFN_DESTRUCTION_CALLBACK callbackFn;
			void* pData;
			::UINT* pCallbackID;
		};

		//Virtual
		struct UnregisterDestructionCallback
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3DDestructionNotifier* pThis;
			::UINT callbackID;
		};

	private:
		 virtual ~ID3DDestructionNotifier() = 0;
	};

	class ID3D11DeviceChild : IUnknown
	{
	public:
		//Virtual
		struct GetDevice
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11DeviceChild* pThis;
			::ID3D11Device** ppDevice;
		};

		//Virtual
		struct GetPrivateData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceChild* pThis;
			const ::GUID& guid;
			::UINT* pDataSize;
			void* pData;
		};

		//Virtual
		struct SetPrivateData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceChild* pThis;
			const ::GUID& guid;
			::UINT DataSize;
			const void* pData;
		};

		//Virtual
		struct SetPrivateDataInterface
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11DeviceChild* pThis;
			const ::GUID& guid;
			const ::IUnknown* pData;
		};

	private:
		 virtual ~ID3D11DeviceChild() = 0;
	};

	class ID3D11DepthStencilState : ID3D11DeviceChild
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11DepthStencilState* pThis;
			::D3D11_DEPTH_STENCIL_DESC* pDesc;
		};

	private:
		 virtual ~ID3D11DepthStencilState() = 0;
	};

	class ID3D11BlendState : ID3D11DeviceChild
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11BlendState* pThis;
			::D3D11_BLEND_DESC* pDesc;
		};

	private:
		 virtual ~ID3D11BlendState() = 0;
	};

	class ID3D11RasterizerState : ID3D11DeviceChild
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11RasterizerState* pThis;
			::D3D11_RASTERIZER_DESC* pDesc;
		};

	private:
		 virtual ~ID3D11RasterizerState() = 0;
	};

	class ID3D11Resource : ID3D11DeviceChild
	{
	public:
		//Virtual
		struct GetType
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11Resource* pThis;
			::D3D11_RESOURCE_DIMENSION* pResourceDimension;
		};

		//Virtual
		struct SetEvictionPriority
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11Resource* pThis;
			::UINT EvictionPriority;
		};

		//Virtual
		struct GetEvictionPriority
		{
			using ReturnType_t = ::UINT;
			static constexpr size_t Argc = 1;

			::ID3D11Resource* pThis;
		};

	private:
		 virtual ~ID3D11Resource() = 0;
	};

	class ID3D11Buffer : ID3D11Resource
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11Buffer* pThis;
			::D3D11_BUFFER_DESC* pDesc;
		};

	private:
		 virtual ~ID3D11Buffer() = 0;
	};

	class ID3D11Texture1D : ID3D11Resource
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11Texture1D* pThis;
			::D3D11_TEXTURE1D_DESC* pDesc;
		};

	private:
		 virtual ~ID3D11Texture1D() = 0;
	};

	class ID3D11Texture2D : ID3D11Resource
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11Texture2D* pThis;
			::D3D11_TEXTURE2D_DESC* pDesc;
		};

	private:
		 virtual ~ID3D11Texture2D() = 0;
	};

	class ID3D11Texture3D : ID3D11Resource
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11Texture3D* pThis;
			::D3D11_TEXTURE3D_DESC* pDesc;
		};

	private:
		 virtual ~ID3D11Texture3D() = 0;
	};

	class ID3D11View : ID3D11DeviceChild
	{
	public:
		//Virtual
		struct GetResource
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11View* pThis;
			::ID3D11Resource** ppResource;
		};

	private:
		 virtual ~ID3D11View() = 0;
	};

	class ID3D11ShaderResourceView : ID3D11View
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11ShaderResourceView* pThis;
			::D3D11_SHADER_RESOURCE_VIEW_DESC* pDesc;
		};

	private:
		 virtual ~ID3D11ShaderResourceView() = 0;
	};

	class ID3D11RenderTargetView : ID3D11View
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11RenderTargetView* pThis;
			::D3D11_RENDER_TARGET_VIEW_DESC* pDesc;
		};

	private:
		 virtual ~ID3D11RenderTargetView() = 0;
	};

	class ID3D11DepthStencilView : ID3D11View
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11DepthStencilView* pThis;
			::D3D11_DEPTH_STENCIL_VIEW_DESC* pDesc;
		};

	private:
		 virtual ~ID3D11DepthStencilView() = 0;
	};

	class ID3D11UnorderedAccessView : ID3D11View
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11UnorderedAccessView* pThis;
			::D3D11_UNORDERED_ACCESS_VIEW_DESC* pDesc;
		};

	private:
		 virtual ~ID3D11UnorderedAccessView() = 0;
	};

	class ID3D11SamplerState : ID3D11DeviceChild
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11SamplerState* pThis;
			::D3D11_SAMPLER_DESC* pDesc;
		};

	private:
		 virtual ~ID3D11SamplerState() = 0;
	};

	class ID3D11Asynchronous : ID3D11DeviceChild
	{
	public:
		//Virtual
		struct GetDataSize
		{
			using ReturnType_t = ::UINT;
			static constexpr size_t Argc = 1;

			::ID3D11Asynchronous* pThis;
		};

	private:
		 virtual ~ID3D11Asynchronous() = 0;
	};

	class ID3D11Query : ID3D11Asynchronous
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11Query* pThis;
			::D3D11_QUERY_DESC* pDesc;
		};

	private:
		 virtual ~ID3D11Query() = 0;
	};

	class ID3D11Counter : ID3D11Asynchronous
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11Counter* pThis;
			::D3D11_COUNTER_DESC* pDesc;
		};

	private:
		 virtual ~ID3D11Counter() = 0;
	};

	class ID3D11ClassInstance : ID3D11DeviceChild
	{
	public:
		//Virtual
		struct GetClassLinkage
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11ClassInstance* pThis;
			::ID3D11ClassLinkage** ppLinkage;
		};

		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11ClassInstance* pThis;
			::D3D11_CLASS_INSTANCE_DESC* pDesc;
		};

		//Virtual
		struct GetInstanceName
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11ClassInstance* pThis;
			::LPSTR pInstanceName;
			::SIZE_T* pBufferLength;
		};

		//Virtual
		struct GetTypeName
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11ClassInstance* pThis;
			::LPSTR pTypeName;
			::SIZE_T* pBufferLength;
		};

	private:
		 virtual ~ID3D11ClassInstance() = 0;
	};

	class ID3D11ClassLinkage : ID3D11DeviceChild
	{
	public:
		//Virtual
		struct GetClassInstance
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11ClassLinkage* pThis;
			::LPCSTR pClassInstanceName;
			::UINT InstanceIndex;
			::ID3D11ClassInstance** ppInstance;
		};

		//Virtual
		struct CreateClassInstance
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 7;

			::ID3D11ClassLinkage* pThis;
			::LPCSTR pClassTypeName;
			::UINT ConstantBufferOffset;
			::UINT ConstantVectorOffset;
			::UINT TextureOffset;
			::UINT SamplerOffset;
			::ID3D11ClassInstance** ppInstance;
		};

	private:
		 virtual ~ID3D11ClassLinkage() = 0;
	};

	class ID3D11CommandList : ID3D11DeviceChild
	{
	public:
		//Virtual
		struct GetContextFlags
		{
			using ReturnType_t = ::UINT;
			static constexpr size_t Argc = 1;

			::ID3D11CommandList* pThis;
		};

	private:
		 virtual ~ID3D11CommandList() = 0;
	};

	class ID3D11DeviceContext : ID3D11DeviceChild
	{
	public:
		//Virtual
		struct VSSetConstantBuffers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D11Buffer*const* ppConstantBuffers;
		};

		//Virtual
		struct PSSetShaderResources
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumViews;
			::ID3D11ShaderResourceView*const* ppShaderResourceViews;
		};

		//Virtual
		struct PSSetShader
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::ID3D11PixelShader* pPixelShader;
			::ID3D11ClassInstance*const* ppClassInstances;
			::UINT NumClassInstances;
		};

		//Virtual
		struct PSSetSamplers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumSamplers;
			::ID3D11SamplerState*const* ppSamplers;
		};

		//Virtual
		struct VSSetShader
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::ID3D11VertexShader* pVertexShader;
			::ID3D11ClassInstance*const* ppClassInstances;
			::UINT NumClassInstances;
		};

		//Virtual
		struct DrawIndexed
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT IndexCount;
			::UINT StartIndexLocation;
			::INT BaseVertexLocation;
		};

		//Virtual
		struct Draw
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11DeviceContext* pThis;
			::UINT VertexCount;
			::UINT StartVertexLocation;
		};

		//Virtual
		struct Map
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::ID3D11DeviceContext* pThis;
			::ID3D11Resource* pResource;
			::UINT Subresource;
			::D3D11_MAP MapType;
			::UINT MapFlags;
			::D3D11_MAPPED_SUBRESOURCE* pMappedResource;
		};

		//Virtual
		struct Unmap
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11DeviceContext* pThis;
			::ID3D11Resource* pResource;
			::UINT Subresource;
		};

		//Virtual
		struct PSSetConstantBuffers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D11Buffer*const* ppConstantBuffers;
		};

		//Virtual
		struct IASetInputLayout
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11DeviceContext* pThis;
			::ID3D11InputLayout* pInputLayout;
		};

		//Virtual
		struct IASetVertexBuffers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D11Buffer*const* ppVertexBuffers;
			const ::UINT* pStrides;
			const ::UINT* pOffsets;
		};

		//Virtual
		struct IASetIndexBuffer
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::ID3D11Buffer* pIndexBuffer;
			::DXGI_FORMAT Format;
			::UINT Offset;
		};

		//Virtual
		struct DrawIndexedInstanced
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D11DeviceContext* pThis;
			::UINT IndexCountPerInstance;
			::UINT InstanceCount;
			::UINT StartIndexLocation;
			::INT BaseVertexLocation;
			::UINT StartInstanceLocation;
		};

		//Virtual
		struct DrawInstanced
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 5;

			::ID3D11DeviceContext* pThis;
			::UINT VertexCountPerInstance;
			::UINT InstanceCount;
			::UINT StartVertexLocation;
			::UINT StartInstanceLocation;
		};

		//Virtual
		struct GSSetConstantBuffers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D11Buffer*const* ppConstantBuffers;
		};

		//Virtual
		struct GSSetShader
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::ID3D11GeometryShader* pShader;
			::ID3D11ClassInstance*const* ppClassInstances;
			::UINT NumClassInstances;
		};

		//Virtual
		struct IASetPrimitiveTopology
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11DeviceContext* pThis;
			::D3D11_PRIMITIVE_TOPOLOGY Topology;
		};

		//Virtual
		struct VSSetShaderResources
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumViews;
			::ID3D11ShaderResourceView*const* ppShaderResourceViews;
		};

		//Virtual
		struct VSSetSamplers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumSamplers;
			::ID3D11SamplerState*const* ppSamplers;
		};

		//Virtual
		struct Begin
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11DeviceContext* pThis;
			::ID3D11Asynchronous* pAsync;
		};

		//Virtual
		struct End
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11DeviceContext* pThis;
			::ID3D11Asynchronous* pAsync;
		};

		//Virtual
		struct GetData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D11DeviceContext* pThis;
			::ID3D11Asynchronous* pAsync;
			void* pData;
			::UINT DataSize;
			::UINT GetDataFlags;
		};

		//Virtual
		struct SetPredication
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11DeviceContext* pThis;
			::ID3D11Predicate* pPredicate;
			::BOOL PredicateValue;
		};

		//Virtual
		struct GSSetShaderResources
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumViews;
			::ID3D11ShaderResourceView*const* ppShaderResourceViews;
		};

		//Virtual
		struct GSSetSamplers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumSamplers;
			::ID3D11SamplerState*const* ppSamplers;
		};

		//Virtual
		struct OMSetRenderTargets
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT NumViews;
			::ID3D11RenderTargetView*const* ppRenderTargetViews;
			::ID3D11DepthStencilView* pDepthStencilView;
		};

		//Virtual
		struct OMSetRenderTargetsAndUnorderedAccessViews
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 8;

			::ID3D11DeviceContext* pThis;
			::UINT NumRTVs;
			::ID3D11RenderTargetView*const* ppRenderTargetViews;
			::ID3D11DepthStencilView* pDepthStencilView;
			::UINT UAVStartSlot;
			::UINT NumUAVs;
			::ID3D11UnorderedAccessView*const* ppUnorderedAccessViews;
			const ::UINT* pUAVInitialCounts;
		};

		//Virtual
		struct OMSetBlendState
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::ID3D11BlendState* pBlendState;
			const ::FLOAT BlendFactor[4];
			::UINT SampleMask;
		};

		//Virtual
		struct OMSetDepthStencilState
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11DeviceContext* pThis;
			::ID3D11DepthStencilState* pDepthStencilState;
			::UINT StencilRef;
		};

		//Virtual
		struct SOSetTargets
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT NumBuffers;
			::ID3D11Buffer*const* ppSOTargets;
			const ::UINT* pOffsets;
		};

		//Virtual
		struct DrawAuto
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D11DeviceContext* pThis;
		};

		//Virtual
		struct DrawIndexedInstancedIndirect
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11DeviceContext* pThis;
			::ID3D11Buffer* pBufferForArgs;
			::UINT AlignedByteOffsetForArgs;
		};

		//Virtual
		struct DrawInstancedIndirect
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11DeviceContext* pThis;
			::ID3D11Buffer* pBufferForArgs;
			::UINT AlignedByteOffsetForArgs;
		};

		//Virtual
		struct Dispatch
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT ThreadGroupCountX;
			::UINT ThreadGroupCountY;
			::UINT ThreadGroupCountZ;
		};

		//Virtual
		struct DispatchIndirect
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11DeviceContext* pThis;
			::ID3D11Buffer* pBufferForArgs;
			::UINT AlignedByteOffsetForArgs;
		};

		//Virtual
		struct RSSetState
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11DeviceContext* pThis;
			::ID3D11RasterizerState* pRasterizerState;
		};

		//Virtual
		struct RSSetViewports
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11DeviceContext* pThis;
			::UINT NumViewports;
			const ::D3D11_VIEWPORT* pViewports;
		};

		//Virtual
		struct RSSetScissorRects
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11DeviceContext* pThis;
			::UINT NumRects;
			const ::D3D11_RECT* pRects;
		};

		//Virtual
		struct CopySubresourceRegion
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 9;

			::ID3D11DeviceContext* pThis;
			::ID3D11Resource* pDstResource;
			::UINT DstSubresource;
			::UINT DstX;
			::UINT DstY;
			::UINT DstZ;
			::ID3D11Resource* pSrcResource;
			::UINT SrcSubresource;
			const ::D3D11_BOX* pSrcBox;
		};

		//Virtual
		struct CopyResource
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11DeviceContext* pThis;
			::ID3D11Resource* pDstResource;
			::ID3D11Resource* pSrcResource;
		};

		//Virtual
		struct UpdateSubresource
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 7;

			::ID3D11DeviceContext* pThis;
			::ID3D11Resource* pDstResource;
			::UINT DstSubresource;
			const ::D3D11_BOX* pDstBox;
			const void* pSrcData;
			::UINT SrcRowPitch;
			::UINT SrcDepthPitch;
		};

		//Virtual
		struct CopyStructureCount
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::ID3D11Buffer* pDstBuffer;
			::UINT DstAlignedByteOffset;
			::ID3D11UnorderedAccessView* pSrcView;
		};

		//Virtual
		struct ClearRenderTargetView
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11DeviceContext* pThis;
			::ID3D11RenderTargetView* pRenderTargetView;
			const ::FLOAT ColorRGBA[4];
		};

		//Virtual
		struct ClearUnorderedAccessViewUint
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11DeviceContext* pThis;
			::ID3D11UnorderedAccessView* pUnorderedAccessView;
			const ::UINT Values[4];
		};

		//Virtual
		struct ClearUnorderedAccessViewFloat
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11DeviceContext* pThis;
			::ID3D11UnorderedAccessView* pUnorderedAccessView;
			const ::FLOAT Values[4];
		};

		//Virtual
		struct ClearDepthStencilView
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 5;

			::ID3D11DeviceContext* pThis;
			::ID3D11DepthStencilView* pDepthStencilView;
			::UINT ClearFlags;
			::FLOAT Depth;
			::UINT8 Stencil;
		};

		//Virtual
		struct GenerateMips
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11DeviceContext* pThis;
			::ID3D11ShaderResourceView* pShaderResourceView;
		};

		//Virtual
		struct SetResourceMinLOD
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11DeviceContext* pThis;
			::ID3D11Resource* pResource;
			::FLOAT MinLOD;
		};

		//Virtual
		struct GetResourceMinLOD
		{
			using ReturnType_t = ::FLOAT;
			static constexpr size_t Argc = 2;

			::ID3D11DeviceContext* pThis;
			::ID3D11Resource* pResource;
		};

		//Virtual
		struct ResolveSubresource
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D11DeviceContext* pThis;
			::ID3D11Resource* pDstResource;
			::UINT DstSubresource;
			::ID3D11Resource* pSrcResource;
			::UINT SrcSubresource;
			::DXGI_FORMAT Format;
		};

		//Virtual
		struct ExecuteCommandList
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11DeviceContext* pThis;
			::ID3D11CommandList* pCommandList;
			::BOOL RestoreContextState;
		};

		//Virtual
		struct HSSetShaderResources
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumViews;
			::ID3D11ShaderResourceView*const* ppShaderResourceViews;
		};

		//Virtual
		struct HSSetShader
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::ID3D11HullShader* pHullShader;
			::ID3D11ClassInstance*const* ppClassInstances;
			::UINT NumClassInstances;
		};

		//Virtual
		struct HSSetSamplers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumSamplers;
			::ID3D11SamplerState*const* ppSamplers;
		};

		//Virtual
		struct HSSetConstantBuffers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D11Buffer*const* ppConstantBuffers;
		};

		//Virtual
		struct DSSetShaderResources
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumViews;
			::ID3D11ShaderResourceView*const* ppShaderResourceViews;
		};

		//Virtual
		struct DSSetShader
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::ID3D11DomainShader* pDomainShader;
			::ID3D11ClassInstance*const* ppClassInstances;
			::UINT NumClassInstances;
		};

		//Virtual
		struct DSSetSamplers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumSamplers;
			::ID3D11SamplerState*const* ppSamplers;
		};

		//Virtual
		struct DSSetConstantBuffers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D11Buffer*const* ppConstantBuffers;
		};

		//Virtual
		struct CSSetShaderResources
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumViews;
			::ID3D11ShaderResourceView*const* ppShaderResourceViews;
		};

		//Virtual
		struct CSSetUnorderedAccessViews
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 5;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumUAVs;
			::ID3D11UnorderedAccessView*const* ppUnorderedAccessViews;
			const ::UINT* pUAVInitialCounts;
		};

		//Virtual
		struct CSSetShader
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::ID3D11ComputeShader* pComputeShader;
			::ID3D11ClassInstance*const* ppClassInstances;
			::UINT NumClassInstances;
		};

		//Virtual
		struct CSSetSamplers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumSamplers;
			::ID3D11SamplerState*const* ppSamplers;
		};

		//Virtual
		struct CSSetConstantBuffers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D11Buffer*const* ppConstantBuffers;
		};

		//Virtual
		struct VSGetConstantBuffers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D11Buffer** ppConstantBuffers;
		};

		//Virtual
		struct PSGetShaderResources
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumViews;
			::ID3D11ShaderResourceView** ppShaderResourceViews;
		};

		//Virtual
		struct PSGetShader
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::ID3D11PixelShader** ppPixelShader;
			::ID3D11ClassInstance** ppClassInstances;
			::UINT* pNumClassInstances;
		};

		//Virtual
		struct PSGetSamplers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumSamplers;
			::ID3D11SamplerState** ppSamplers;
		};

		//Virtual
		struct VSGetShader
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::ID3D11VertexShader** ppVertexShader;
			::ID3D11ClassInstance** ppClassInstances;
			::UINT* pNumClassInstances;
		};

		//Virtual
		struct PSGetConstantBuffers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D11Buffer** ppConstantBuffers;
		};

		//Virtual
		struct IAGetInputLayout
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11DeviceContext* pThis;
			::ID3D11InputLayout** ppInputLayout;
		};

		//Virtual
		struct IAGetVertexBuffers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D11Buffer** ppVertexBuffers;
			::UINT* pStrides;
			::UINT* pOffsets;
		};

		//Virtual
		struct IAGetIndexBuffer
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::ID3D11Buffer** pIndexBuffer;
			::DXGI_FORMAT* Format;
			::UINT* Offset;
		};

		//Virtual
		struct GSGetConstantBuffers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D11Buffer** ppConstantBuffers;
		};

		//Virtual
		struct GSGetShader
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::ID3D11GeometryShader** ppGeometryShader;
			::ID3D11ClassInstance** ppClassInstances;
			::UINT* pNumClassInstances;
		};

		//Virtual
		struct IAGetPrimitiveTopology
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11DeviceContext* pThis;
			::D3D11_PRIMITIVE_TOPOLOGY* pTopology;
		};

		//Virtual
		struct VSGetShaderResources
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumViews;
			::ID3D11ShaderResourceView** ppShaderResourceViews;
		};

		//Virtual
		struct VSGetSamplers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumSamplers;
			::ID3D11SamplerState** ppSamplers;
		};

		//Virtual
		struct GetPredication
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11DeviceContext* pThis;
			::ID3D11Predicate** ppPredicate;
			::BOOL* pPredicateValue;
		};

		//Virtual
		struct GSGetShaderResources
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumViews;
			::ID3D11ShaderResourceView** ppShaderResourceViews;
		};

		//Virtual
		struct GSGetSamplers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumSamplers;
			::ID3D11SamplerState** ppSamplers;
		};

		//Virtual
		struct OMGetRenderTargets
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT NumViews;
			::ID3D11RenderTargetView** ppRenderTargetViews;
			::ID3D11DepthStencilView** ppDepthStencilView;
		};

		//Virtual
		struct OMGetRenderTargetsAndUnorderedAccessViews
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 7;

			::ID3D11DeviceContext* pThis;
			::UINT NumRTVs;
			::ID3D11RenderTargetView** ppRenderTargetViews;
			::ID3D11DepthStencilView** ppDepthStencilView;
			::UINT UAVStartSlot;
			::UINT NumUAVs;
			::ID3D11UnorderedAccessView** ppUnorderedAccessViews;
		};

		//Virtual
		struct OMGetBlendState
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::ID3D11BlendState** ppBlendState;
			::FLOAT BlendFactor[4];
			::UINT* pSampleMask;
		};

		//Virtual
		struct OMGetDepthStencilState
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11DeviceContext* pThis;
			::ID3D11DepthStencilState** ppDepthStencilState;
			::UINT* pStencilRef;
		};

		//Virtual
		struct SOGetTargets
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11DeviceContext* pThis;
			::UINT NumBuffers;
			::ID3D11Buffer** ppSOTargets;
		};

		//Virtual
		struct RSGetState
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11DeviceContext* pThis;
			::ID3D11RasterizerState** ppRasterizerState;
		};

		//Virtual
		struct RSGetViewports
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11DeviceContext* pThis;
			::UINT* pNumViewports;
			::D3D11_VIEWPORT* pViewports;
		};

		//Virtual
		struct RSGetScissorRects
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11DeviceContext* pThis;
			::UINT* pNumRects;
			::D3D11_RECT* pRects;
		};

		//Virtual
		struct HSGetShaderResources
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumViews;
			::ID3D11ShaderResourceView** ppShaderResourceViews;
		};

		//Virtual
		struct HSGetShader
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::ID3D11HullShader** ppHullShader;
			::ID3D11ClassInstance** ppClassInstances;
			::UINT* pNumClassInstances;
		};

		//Virtual
		struct HSGetSamplers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumSamplers;
			::ID3D11SamplerState** ppSamplers;
		};

		//Virtual
		struct HSGetConstantBuffers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D11Buffer** ppConstantBuffers;
		};

		//Virtual
		struct DSGetShaderResources
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumViews;
			::ID3D11ShaderResourceView** ppShaderResourceViews;
		};

		//Virtual
		struct DSGetShader
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::ID3D11DomainShader** ppDomainShader;
			::ID3D11ClassInstance** ppClassInstances;
			::UINT* pNumClassInstances;
		};

		//Virtual
		struct DSGetSamplers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumSamplers;
			::ID3D11SamplerState** ppSamplers;
		};

		//Virtual
		struct DSGetConstantBuffers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D11Buffer** ppConstantBuffers;
		};

		//Virtual
		struct CSGetShaderResources
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumViews;
			::ID3D11ShaderResourceView** ppShaderResourceViews;
		};

		//Virtual
		struct CSGetUnorderedAccessViews
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumUAVs;
			::ID3D11UnorderedAccessView** ppUnorderedAccessViews;
		};

		//Virtual
		struct CSGetShader
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::ID3D11ComputeShader** ppComputeShader;
			::ID3D11ClassInstance** ppClassInstances;
			::UINT* pNumClassInstances;
		};

		//Virtual
		struct CSGetSamplers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumSamplers;
			::ID3D11SamplerState** ppSamplers;
		};

		//Virtual
		struct CSGetConstantBuffers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D11Buffer** ppConstantBuffers;
		};

		//Virtual
		struct ClearState
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D11DeviceContext* pThis;
		};

		//Virtual
		struct Flush
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D11DeviceContext* pThis;
		};

		//Virtual
		struct GetType
		{
			using ReturnType_t = ::D3D11_DEVICE_CONTEXT_TYPE;
			static constexpr size_t Argc = 1;

			::ID3D11DeviceContext* pThis;
		};

		//Virtual
		struct GetContextFlags
		{
			using ReturnType_t = ::UINT;
			static constexpr size_t Argc = 1;

			::ID3D11DeviceContext* pThis;
		};

		//Virtual
		struct FinishCommandList
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11DeviceContext* pThis;
			::BOOL RestoreDeferredContextState;
			::ID3D11CommandList** ppCommandList;
		};

	private:
		 virtual ~ID3D11DeviceContext() = 0;
	};

	class ID3D11VideoDecoder : ID3D11DeviceChild
	{
	public:
		//Virtual
		struct GetCreationParameters
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11VideoDecoder* pThis;
			::D3D11_VIDEO_DECODER_DESC* pVideoDesc;
			::D3D11_VIDEO_DECODER_CONFIG* pConfig;
		};

		//Virtual
		struct GetDriverHandle
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D11VideoDecoder* pThis;
			::HANDLE* pDriverHandle;
		};

	private:
		 virtual ~ID3D11VideoDecoder() = 0;
	};

	class ID3D11VideoProcessorEnumerator : ID3D11DeviceChild
	{
	public:
		//Virtual
		struct GetVideoProcessorContentDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D11VideoProcessorEnumerator* pThis;
			::D3D11_VIDEO_PROCESSOR_CONTENT_DESC* pContentDesc;
		};

		//Virtual
		struct CheckVideoProcessorFormat
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11VideoProcessorEnumerator* pThis;
			::DXGI_FORMAT Format;
			::UINT* pFlags;
		};

		//Virtual
		struct GetVideoProcessorCaps
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D11VideoProcessorEnumerator* pThis;
			::D3D11_VIDEO_PROCESSOR_CAPS* pCaps;
		};

		//Virtual
		struct GetVideoProcessorRateConversionCaps
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11VideoProcessorEnumerator* pThis;
			::UINT TypeIndex;
			::D3D11_VIDEO_PROCESSOR_RATE_CONVERSION_CAPS* pCaps;
		};

		//Virtual
		struct GetVideoProcessorCustomRate
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11VideoProcessorEnumerator* pThis;
			::UINT TypeIndex;
			::UINT CustomRateIndex;
			::D3D11_VIDEO_PROCESSOR_CUSTOM_RATE* pRate;
		};

		//Virtual
		struct GetVideoProcessorFilterRange
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11VideoProcessorEnumerator* pThis;
			::D3D11_VIDEO_PROCESSOR_FILTER Filter;
			::D3D11_VIDEO_PROCESSOR_FILTER_RANGE* pRange;
		};

	private:
		 virtual ~ID3D11VideoProcessorEnumerator() = 0;
	};

	class ID3D11VideoProcessor : ID3D11DeviceChild
	{
	public:
		//Virtual
		struct GetContentDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11VideoProcessor* pThis;
			::D3D11_VIDEO_PROCESSOR_CONTENT_DESC* pDesc;
		};

		//Virtual
		struct GetRateConversionCaps
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11VideoProcessor* pThis;
			::D3D11_VIDEO_PROCESSOR_RATE_CONVERSION_CAPS* pCaps;
		};

	private:
		 virtual ~ID3D11VideoProcessor() = 0;
	};

	class ID3D11AuthenticatedChannel : ID3D11DeviceChild
	{
	public:
		//Virtual
		struct GetCertificateSize
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D11AuthenticatedChannel* pThis;
			::UINT* pCertificateSize;
		};

		//Virtual
		struct GetCertificate
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11AuthenticatedChannel* pThis;
			::UINT CertificateSize;
			::BYTE* pCertificate;
		};

		//Virtual
		struct GetChannelHandle
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11AuthenticatedChannel* pThis;
			::HANDLE* pChannelHandle;
		};

	private:
		 virtual ~ID3D11AuthenticatedChannel() = 0;
	};

	class ID3D11CryptoSession : ID3D11DeviceChild
	{
	public:
		//Virtual
		struct GetCryptoType
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11CryptoSession* pThis;
			::GUID* pCryptoType;
		};

		//Virtual
		struct GetDecoderProfile
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11CryptoSession* pThis;
			::GUID* pDecoderProfile;
		};

		//Virtual
		struct GetCertificateSize
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D11CryptoSession* pThis;
			::UINT* pCertificateSize;
		};

		//Virtual
		struct GetCertificate
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11CryptoSession* pThis;
			::UINT CertificateSize;
			::BYTE* pCertificate;
		};

		//Virtual
		struct GetCryptoSessionHandle
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11CryptoSession* pThis;
			::HANDLE* pCryptoSessionHandle;
		};

	private:
		 virtual ~ID3D11CryptoSession() = 0;
	};

	class ID3D11VideoDecoderOutputView : ID3D11View
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11VideoDecoderOutputView* pThis;
			::D3D11_VIDEO_DECODER_OUTPUT_VIEW_DESC* pDesc;
		};

	private:
		 virtual ~ID3D11VideoDecoderOutputView() = 0;
	};

	class ID3D11VideoProcessorInputView : ID3D11View
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11VideoProcessorInputView* pThis;
			::D3D11_VIDEO_PROCESSOR_INPUT_VIEW_DESC* pDesc;
		};

	private:
		 virtual ~ID3D11VideoProcessorInputView() = 0;
	};

	class ID3D11VideoProcessorOutputView : ID3D11View
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11VideoProcessorOutputView* pThis;
			::D3D11_VIDEO_PROCESSOR_OUTPUT_VIEW_DESC* pDesc;
		};

	private:
		 virtual ~ID3D11VideoProcessorOutputView() = 0;
	};

	class ID3D11VideoContext : ID3D11DeviceChild
	{
	public:
		//Virtual
		struct GetDecoderBuffer
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoDecoder* pDecoder;
			::D3D11_VIDEO_DECODER_BUFFER_TYPE Type;
			::UINT* pBufferSize;
			void** ppBuffer;
		};

		//Virtual
		struct ReleaseDecoderBuffer
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoDecoder* pDecoder;
			::D3D11_VIDEO_DECODER_BUFFER_TYPE Type;
		};

		//Virtual
		struct DecoderBeginFrame
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoDecoder* pDecoder;
			::ID3D11VideoDecoderOutputView* pView;
			::UINT ContentKeySize;
			const void* pContentKey;
		};

		//Virtual
		struct DecoderEndFrame
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoDecoder* pDecoder;
		};

		//Virtual
		struct SubmitDecoderBuffers
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoDecoder* pDecoder;
			::UINT NumBuffers;
			const ::D3D11_VIDEO_DECODER_BUFFER_DESC* pBufferDesc;
		};

		//Virtual
		struct DecoderExtension
		{
			using ReturnType_t = ::APP_DEPRECATED_HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoDecoder* pDecoder;
			const ::D3D11_VIDEO_DECODER_EXTENSION* pExtensionData;
		};

		//Virtual
		struct VideoProcessorSetOutputTargetRect
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::BOOL Enable;
			const ::RECT* pRect;
		};

		//Virtual
		struct VideoProcessorSetOutputBackgroundColor
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::BOOL YCbCr;
			const ::D3D11_VIDEO_COLOR* pColor;
		};

		//Virtual
		struct VideoProcessorSetOutputColorSpace
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			const ::D3D11_VIDEO_PROCESSOR_COLOR_SPACE* pColorSpace;
		};

		//Virtual
		struct VideoProcessorSetOutputAlphaFillMode
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::D3D11_VIDEO_PROCESSOR_ALPHA_FILL_MODE AlphaFillMode;
			::UINT StreamIndex;
		};

		//Virtual
		struct VideoProcessorSetOutputConstriction
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::BOOL Enable;
			::SIZE Size;
		};

		//Virtual
		struct VideoProcessorSetOutputStereoMode
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::BOOL Enable;
		};

		//Virtual
		struct VideoProcessorSetOutputExtension
		{
			using ReturnType_t = ::APP_DEPRECATED_HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			const ::GUID* pExtensionGuid;
			::UINT DataSize;
			void* pData;
		};

		//Virtual
		struct VideoProcessorGetOutputTargetRect
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::BOOL* Enabled;
			::RECT* pRect;
		};

		//Virtual
		struct VideoProcessorGetOutputBackgroundColor
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::BOOL* pYCbCr;
			::D3D11_VIDEO_COLOR* pColor;
		};

		//Virtual
		struct VideoProcessorGetOutputColorSpace
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::D3D11_VIDEO_PROCESSOR_COLOR_SPACE* pColorSpace;
		};

		//Virtual
		struct VideoProcessorGetOutputAlphaFillMode
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::D3D11_VIDEO_PROCESSOR_ALPHA_FILL_MODE* pAlphaFillMode;
			::UINT* pStreamIndex;
		};

		//Virtual
		struct VideoProcessorGetOutputConstriction
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::BOOL* pEnabled;
			::SIZE* pSize;
		};

		//Virtual
		struct VideoProcessorGetOutputStereoMode
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::BOOL* pEnabled;
		};

		//Virtual
		struct VideoProcessorGetOutputExtension
		{
			using ReturnType_t = ::APP_DEPRECATED_HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			const ::GUID* pExtensionGuid;
			::UINT DataSize;
			void* pData;
		};

		//Virtual
		struct VideoProcessorSetStreamFrameFormat
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			::D3D11_VIDEO_FRAME_FORMAT FrameFormat;
		};

		//Virtual
		struct VideoProcessorSetStreamColorSpace
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			const ::D3D11_VIDEO_PROCESSOR_COLOR_SPACE* pColorSpace;
		};

		//Virtual
		struct VideoProcessorSetStreamOutputRate
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			::D3D11_VIDEO_PROCESSOR_OUTPUT_RATE OutputRate;
			::BOOL RepeatFrame;
			const ::DXGI_RATIONAL* pCustomRate;
		};

		//Virtual
		struct VideoProcessorSetStreamSourceRect
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 5;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			::BOOL Enable;
			const ::RECT* pRect;
		};

		//Virtual
		struct VideoProcessorSetStreamDestRect
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 5;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			::BOOL Enable;
			const ::RECT* pRect;
		};

		//Virtual
		struct VideoProcessorSetStreamAlpha
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 5;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			::BOOL Enable;
			::FLOAT Alpha;
		};

		//Virtual
		struct VideoProcessorSetStreamPalette
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 5;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			::UINT Count;
			const ::UINT* pEntries;
		};

		//Virtual
		struct VideoProcessorSetStreamPixelAspectRatio
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			::BOOL Enable;
			const ::DXGI_RATIONAL* pSourceAspectRatio;
			const ::DXGI_RATIONAL* pDestinationAspectRatio;
		};

		//Virtual
		struct VideoProcessorSetStreamLumaKey
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			::BOOL Enable;
			::FLOAT Lower;
			::FLOAT Upper;
		};

		//Virtual
		struct VideoProcessorSetStreamStereoFormat
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 9;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			::BOOL Enable;
			::D3D11_VIDEO_PROCESSOR_STEREO_FORMAT Format;
			::BOOL LeftViewFrame0;
			::BOOL BaseViewFrame0;
			::D3D11_VIDEO_PROCESSOR_STEREO_FLIP_MODE FlipMode;
			int MonoOffset;
		};

		//Virtual
		struct VideoProcessorSetStreamAutoProcessingMode
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			::BOOL Enable;
		};

		//Virtual
		struct VideoProcessorSetStreamFilter
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			::D3D11_VIDEO_PROCESSOR_FILTER Filter;
			::BOOL Enable;
			int Level;
		};

		//Virtual
		struct VideoProcessorSetStreamExtension
		{
			using ReturnType_t = ::APP_DEPRECATED_HRESULT;
			static constexpr size_t Argc = 6;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			const ::GUID* pExtensionGuid;
			::UINT DataSize;
			void* pData;
		};

		//Virtual
		struct VideoProcessorGetStreamFrameFormat
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			::D3D11_VIDEO_FRAME_FORMAT* pFrameFormat;
		};

		//Virtual
		struct VideoProcessorGetStreamColorSpace
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			::D3D11_VIDEO_PROCESSOR_COLOR_SPACE* pColorSpace;
		};

		//Virtual
		struct VideoProcessorGetStreamOutputRate
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			::D3D11_VIDEO_PROCESSOR_OUTPUT_RATE* pOutputRate;
			::BOOL* pRepeatFrame;
			::DXGI_RATIONAL* pCustomRate;
		};

		//Virtual
		struct VideoProcessorGetStreamSourceRect
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 5;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			::BOOL* pEnabled;
			::RECT* pRect;
		};

		//Virtual
		struct VideoProcessorGetStreamDestRect
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 5;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			::BOOL* pEnabled;
			::RECT* pRect;
		};

		//Virtual
		struct VideoProcessorGetStreamAlpha
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 5;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			::BOOL* pEnabled;
			::FLOAT* pAlpha;
		};

		//Virtual
		struct VideoProcessorGetStreamPalette
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 5;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			::UINT Count;
			::UINT* pEntries;
		};

		//Virtual
		struct VideoProcessorGetStreamPixelAspectRatio
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			::BOOL* pEnabled;
			::DXGI_RATIONAL* pSourceAspectRatio;
			::DXGI_RATIONAL* pDestinationAspectRatio;
		};

		//Virtual
		struct VideoProcessorGetStreamLumaKey
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			::BOOL* pEnabled;
			::FLOAT* pLower;
			::FLOAT* pUpper;
		};

		//Virtual
		struct VideoProcessorGetStreamStereoFormat
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 9;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			::BOOL* pEnable;
			::D3D11_VIDEO_PROCESSOR_STEREO_FORMAT* pFormat;
			::BOOL* pLeftViewFrame0;
			::BOOL* pBaseViewFrame0;
			::D3D11_VIDEO_PROCESSOR_STEREO_FLIP_MODE* pFlipMode;
			int* MonoOffset;
		};

		//Virtual
		struct VideoProcessorGetStreamAutoProcessingMode
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			::BOOL* pEnabled;
		};

		//Virtual
		struct VideoProcessorGetStreamFilter
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			::D3D11_VIDEO_PROCESSOR_FILTER Filter;
			::BOOL* pEnabled;
			int* pLevel;
		};

		//Virtual
		struct VideoProcessorGetStreamExtension
		{
			using ReturnType_t = ::APP_DEPRECATED_HRESULT;
			static constexpr size_t Argc = 6;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			const ::GUID* pExtensionGuid;
			::UINT DataSize;
			void* pData;
		};

		//Virtual
		struct VideoProcessorBlt
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::ID3D11VideoProcessorOutputView* pView;
			::UINT OutputFrame;
			::UINT StreamCount;
			const ::D3D11_VIDEO_PROCESSOR_STREAM* pStreams;
		};

		//Virtual
		struct NegotiateCryptoSessionKeyExchange
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11VideoContext* pThis;
			::ID3D11CryptoSession* pCryptoSession;
			::UINT DataSize;
			void* pData;
		};

		//Virtual
		struct EncryptionBlt
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D11VideoContext* pThis;
			::ID3D11CryptoSession* pCryptoSession;
			::ID3D11Texture2D* pSrcSurface;
			::ID3D11Texture2D* pDstSurface;
			::UINT IVSize;
			void* pIV;
		};

		//Virtual
		struct DecryptionBlt
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 9;

			::ID3D11VideoContext* pThis;
			::ID3D11CryptoSession* pCryptoSession;
			::ID3D11Texture2D* pSrcSurface;
			::ID3D11Texture2D* pDstSurface;
			::D3D11_ENCRYPTED_BLOCK_INFO* pEncryptedBlockInfo;
			::UINT ContentKeySize;
			const void* pContentKey;
			::UINT IVSize;
			void* pIV;
		};

		//Virtual
		struct StartSessionKeyRefresh
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11VideoContext* pThis;
			::ID3D11CryptoSession* pCryptoSession;
			::UINT RandomNumberSize;
			void* pRandomNumber;
		};

		//Virtual
		struct FinishSessionKeyRefresh
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11VideoContext* pThis;
			::ID3D11CryptoSession* pCryptoSession;
		};

		//Virtual
		struct GetEncryptionBltKey
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11VideoContext* pThis;
			::ID3D11CryptoSession* pCryptoSession;
			::UINT KeySize;
			void* pReadbackKey;
		};

		//Virtual
		struct NegotiateAuthenticatedChannelKeyExchange
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11VideoContext* pThis;
			::ID3D11AuthenticatedChannel* pChannel;
			::UINT DataSize;
			void* pData;
		};

		//Virtual
		struct QueryAuthenticatedChannel
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::ID3D11VideoContext* pThis;
			::ID3D11AuthenticatedChannel* pChannel;
			::UINT InputSize;
			const void* pInput;
			::UINT OutputSize;
			void* pOutput;
		};

		//Virtual
		struct ConfigureAuthenticatedChannel
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D11VideoContext* pThis;
			::ID3D11AuthenticatedChannel* pChannel;
			::UINT InputSize;
			const void* pInput;
			::D3D11_AUTHENTICATED_CONFIGURE_OUTPUT* pOutput;
		};

		//Virtual
		struct VideoProcessorSetStreamRotation
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 5;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			::BOOL Enable;
			::D3D11_VIDEO_PROCESSOR_ROTATION Rotation;
		};

		//Virtual
		struct VideoProcessorGetStreamRotation
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 5;

			::ID3D11VideoContext* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			::BOOL* pEnable;
			::D3D11_VIDEO_PROCESSOR_ROTATION* pRotation;
		};

	private:
		 virtual ~ID3D11VideoContext() = 0;
	};

	class ID3D11VideoDevice : IUnknown
	{
	public:
		//Virtual
		struct CreateVideoDecoder
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11VideoDevice* pThis;
			const ::D3D11_VIDEO_DECODER_DESC* pVideoDesc;
			const ::D3D11_VIDEO_DECODER_CONFIG* pConfig;
			::ID3D11VideoDecoder** ppDecoder;
		};

		//Virtual
		struct CreateVideoProcessor
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11VideoDevice* pThis;
			::ID3D11VideoProcessorEnumerator* pEnum;
			::UINT RateConversionIndex;
			::ID3D11VideoProcessor** ppVideoProcessor;
		};

		//Virtual
		struct CreateAuthenticatedChannel
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11VideoDevice* pThis;
			::D3D11_AUTHENTICATED_CHANNEL_TYPE ChannelType;
			::ID3D11AuthenticatedChannel** ppAuthenticatedChannel;
		};

		//Virtual
		struct CreateCryptoSession
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D11VideoDevice* pThis;
			const ::GUID* pCryptoType;
			const ::GUID* pDecoderProfile;
			const ::GUID* pKeyExchangeType;
			::ID3D11CryptoSession** ppCryptoSession;
		};

		//Virtual
		struct CreateVideoDecoderOutputView
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11VideoDevice* pThis;
			::ID3D11Resource* pResource;
			const ::D3D11_VIDEO_DECODER_OUTPUT_VIEW_DESC* pDesc;
			::ID3D11VideoDecoderOutputView** ppVDOVView;
		};

		//Virtual
		struct CreateVideoProcessorInputView
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D11VideoDevice* pThis;
			::ID3D11Resource* pResource;
			::ID3D11VideoProcessorEnumerator* pEnum;
			const ::D3D11_VIDEO_PROCESSOR_INPUT_VIEW_DESC* pDesc;
			::ID3D11VideoProcessorInputView** ppVPIView;
		};

		//Virtual
		struct CreateVideoProcessorOutputView
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D11VideoDevice* pThis;
			::ID3D11Resource* pResource;
			::ID3D11VideoProcessorEnumerator* pEnum;
			const ::D3D11_VIDEO_PROCESSOR_OUTPUT_VIEW_DESC* pDesc;
			::ID3D11VideoProcessorOutputView** ppVPOView;
		};

		//Virtual
		struct CreateVideoProcessorEnumerator
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11VideoDevice* pThis;
			const ::D3D11_VIDEO_PROCESSOR_CONTENT_DESC* pDesc;
			::ID3D11VideoProcessorEnumerator** ppEnum;
		};

		//Virtual
		struct GetVideoDecoderProfileCount
		{
			using ReturnType_t = ::UINT;
			static constexpr size_t Argc = 1;

			::ID3D11VideoDevice* pThis;
		};

		//Virtual
		struct GetVideoDecoderProfile
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11VideoDevice* pThis;
			::UINT Index;
			::GUID* pDecoderProfile;
		};

		//Virtual
		struct CheckVideoDecoderFormat
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11VideoDevice* pThis;
			const ::GUID* pDecoderProfile;
			::DXGI_FORMAT Format;
			::BOOL* pSupported;
		};

		//Virtual
		struct GetVideoDecoderConfigCount
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11VideoDevice* pThis;
			const ::D3D11_VIDEO_DECODER_DESC* pDesc;
			::UINT* pCount;
		};

		//Virtual
		struct GetVideoDecoderConfig
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11VideoDevice* pThis;
			const ::D3D11_VIDEO_DECODER_DESC* pDesc;
			::UINT Index;
			::D3D11_VIDEO_DECODER_CONFIG* pConfig;
		};

		//Virtual
		struct GetContentProtectionCaps
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11VideoDevice* pThis;
			const ::GUID* pCryptoType;
			const ::GUID* pDecoderProfile;
			::D3D11_VIDEO_CONTENT_PROTECTION_CAPS* pCaps;
		};

		//Virtual
		struct CheckCryptoKeyExchange
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D11VideoDevice* pThis;
			const ::GUID* pCryptoType;
			const ::GUID* pDecoderProfile;
			::UINT Index;
			::GUID* pKeyExchangeType;
		};

		//Virtual
		struct SetPrivateData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11VideoDevice* pThis;
			const ::GUID& guid;
			::UINT DataSize;
			const void* pData;
		};

		//Virtual
		struct SetPrivateDataInterface
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11VideoDevice* pThis;
			const ::GUID& guid;
			const ::IUnknown* pData;
		};

	private:
		 virtual ~ID3D11VideoDevice() = 0;
	};

	class ID3D11Device : IUnknown
	{
	public:
		//Virtual
		struct CreateBuffer
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11Device* pThis;
			const ::D3D11_BUFFER_DESC* pDesc;
			const ::D3D11_SUBRESOURCE_DATA* pInitialData;
			::ID3D11Buffer** ppBuffer;
		};

		//Virtual
		struct CreateTexture1D
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11Device* pThis;
			const ::D3D11_TEXTURE1D_DESC* pDesc;
			const ::D3D11_SUBRESOURCE_DATA* pInitialData;
			::ID3D11Texture1D** ppTexture1D;
		};

		//Virtual
		struct CreateTexture2D
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11Device* pThis;
			const ::D3D11_TEXTURE2D_DESC* pDesc;
			const ::D3D11_SUBRESOURCE_DATA* pInitialData;
			::ID3D11Texture2D** ppTexture2D;
		};

		//Virtual
		struct CreateTexture3D
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11Device* pThis;
			const ::D3D11_TEXTURE3D_DESC* pDesc;
			const ::D3D11_SUBRESOURCE_DATA* pInitialData;
			::ID3D11Texture3D** ppTexture3D;
		};

		//Virtual
		struct CreateShaderResourceView
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11Device* pThis;
			::ID3D11Resource* pResource;
			const ::D3D11_SHADER_RESOURCE_VIEW_DESC* pDesc;
			::ID3D11ShaderResourceView** ppSRView;
		};

		//Virtual
		struct CreateUnorderedAccessView
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11Device* pThis;
			::ID3D11Resource* pResource;
			const ::D3D11_UNORDERED_ACCESS_VIEW_DESC* pDesc;
			::ID3D11UnorderedAccessView** ppUAView;
		};

		//Virtual
		struct CreateRenderTargetView
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11Device* pThis;
			::ID3D11Resource* pResource;
			const ::D3D11_RENDER_TARGET_VIEW_DESC* pDesc;
			::ID3D11RenderTargetView** ppRTView;
		};

		//Virtual
		struct CreateDepthStencilView
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11Device* pThis;
			::ID3D11Resource* pResource;
			const ::D3D11_DEPTH_STENCIL_VIEW_DESC* pDesc;
			::ID3D11DepthStencilView** ppDepthStencilView;
		};

		//Virtual
		struct CreateInputLayout
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::ID3D11Device* pThis;
			const ::D3D11_INPUT_ELEMENT_DESC* pInputElementDescs;
			::UINT NumElements;
			const void* pShaderBytecodeWithInputSignature;
			::SIZE_T BytecodeLength;
			::ID3D11InputLayout** ppInputLayout;
		};

		//Virtual
		struct CreateVertexShader
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D11Device* pThis;
			const void* pShaderBytecode;
			::SIZE_T BytecodeLength;
			::ID3D11ClassLinkage* pClassLinkage;
			::ID3D11VertexShader** ppVertexShader;
		};

		//Virtual
		struct CreateGeometryShader
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D11Device* pThis;
			const void* pShaderBytecode;
			::SIZE_T BytecodeLength;
			::ID3D11ClassLinkage* pClassLinkage;
			::ID3D11GeometryShader** ppGeometryShader;
		};

		//Virtual
		struct CreateGeometryShaderWithStreamOutput
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 10;

			::ID3D11Device* pThis;
			const void* pShaderBytecode;
			::SIZE_T BytecodeLength;
			const ::D3D11_SO_DECLARATION_ENTRY* pSODeclaration;
			::UINT NumEntries;
			const ::UINT* pBufferStrides;
			::UINT NumStrides;
			::UINT RasterizedStream;
			::ID3D11ClassLinkage* pClassLinkage;
			::ID3D11GeometryShader** ppGeometryShader;
		};

		//Virtual
		struct CreatePixelShader
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D11Device* pThis;
			const void* pShaderBytecode;
			::SIZE_T BytecodeLength;
			::ID3D11ClassLinkage* pClassLinkage;
			::ID3D11PixelShader** ppPixelShader;
		};

		//Virtual
		struct CreateHullShader
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D11Device* pThis;
			const void* pShaderBytecode;
			::SIZE_T BytecodeLength;
			::ID3D11ClassLinkage* pClassLinkage;
			::ID3D11HullShader** ppHullShader;
		};

		//Virtual
		struct CreateDomainShader
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D11Device* pThis;
			const void* pShaderBytecode;
			::SIZE_T BytecodeLength;
			::ID3D11ClassLinkage* pClassLinkage;
			::ID3D11DomainShader** ppDomainShader;
		};

		//Virtual
		struct CreateComputeShader
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D11Device* pThis;
			const void* pShaderBytecode;
			::SIZE_T BytecodeLength;
			::ID3D11ClassLinkage* pClassLinkage;
			::ID3D11ComputeShader** ppComputeShader;
		};

		//Virtual
		struct CreateClassLinkage
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D11Device* pThis;
			::ID3D11ClassLinkage** ppLinkage;
		};

		//Virtual
		struct CreateBlendState
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11Device* pThis;
			const ::D3D11_BLEND_DESC* pBlendStateDesc;
			::ID3D11BlendState** ppBlendState;
		};

		//Virtual
		struct CreateDepthStencilState
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11Device* pThis;
			const ::D3D11_DEPTH_STENCIL_DESC* pDepthStencilDesc;
			::ID3D11DepthStencilState** ppDepthStencilState;
		};

		//Virtual
		struct CreateRasterizerState
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11Device* pThis;
			const ::D3D11_RASTERIZER_DESC* pRasterizerDesc;
			::ID3D11RasterizerState** ppRasterizerState;
		};

		//Virtual
		struct CreateSamplerState
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11Device* pThis;
			const ::D3D11_SAMPLER_DESC* pSamplerDesc;
			::ID3D11SamplerState** ppSamplerState;
		};

		//Virtual
		struct CreateQuery
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11Device* pThis;
			const ::D3D11_QUERY_DESC* pQueryDesc;
			::ID3D11Query** ppQuery;
		};

		//Virtual
		struct CreatePredicate
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11Device* pThis;
			const ::D3D11_QUERY_DESC* pPredicateDesc;
			::ID3D11Predicate** ppPredicate;
		};

		//Virtual
		struct CreateCounter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11Device* pThis;
			const ::D3D11_COUNTER_DESC* pCounterDesc;
			::ID3D11Counter** ppCounter;
		};

		//Virtual
		struct CreateDeferredContext
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11Device* pThis;
			::UINT ContextFlags;
			::ID3D11DeviceContext** ppDeferredContext;
		};

		//Virtual
		struct OpenSharedResource
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11Device* pThis;
			::HANDLE hResource;
			const ::IID& ReturnedInterface;
			void** ppResource;
		};

		//Virtual
		struct CheckFormatSupport
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11Device* pThis;
			::DXGI_FORMAT Format;
			::UINT* pFormatSupport;
		};

		//Virtual
		struct CheckMultisampleQualityLevels
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11Device* pThis;
			::DXGI_FORMAT Format;
			::UINT SampleCount;
			::UINT* pNumQualityLevels;
		};

		//Virtual
		struct CheckCounterInfo
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11Device* pThis;
			::D3D11_COUNTER_INFO* pCounterInfo;
		};

		//Virtual
		struct CheckCounter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 10;

			::ID3D11Device* pThis;
			const ::D3D11_COUNTER_DESC* pDesc;
			::D3D11_COUNTER_TYPE* pType;
			::UINT* pActiveCounters;
			::LPSTR szName;
			::UINT* pNameLength;
			::LPSTR szUnits;
			::UINT* pUnitsLength;
			::LPSTR szDescription;
			::UINT* pDescriptionLength;
		};

		//Virtual
		struct CheckFeatureSupport
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11Device* pThis;
			::D3D11_FEATURE Feature;
			void* pFeatureSupportData;
			::UINT FeatureSupportDataSize;
		};

		//Virtual
		struct GetPrivateData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11Device* pThis;
			const ::GUID& guid;
			::UINT* pDataSize;
			void* pData;
		};

		//Virtual
		struct SetPrivateData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11Device* pThis;
			const ::GUID& guid;
			::UINT DataSize;
			const void* pData;
		};

		//Virtual
		struct SetPrivateDataInterface
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11Device* pThis;
			const ::GUID& guid;
			const ::IUnknown* pData;
		};

		//Virtual
		struct GetFeatureLevel
		{
			using ReturnType_t = ::D3D_FEATURE_LEVEL;
			static constexpr size_t Argc = 1;

			::ID3D11Device* pThis;
		};

		//Virtual
		struct GetCreationFlags
		{
			using ReturnType_t = ::UINT;
			static constexpr size_t Argc = 1;

			::ID3D11Device* pThis;
		};

		//Virtual
		struct GetDeviceRemovedReason
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ID3D11Device* pThis;
		};

		//Virtual
		struct GetImmediateContext
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11Device* pThis;
			::ID3D11DeviceContext** ppImmediateContext;
		};

		//Virtual
		struct SetExceptionMode
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D11Device* pThis;
			::UINT RaiseFlags;
		};

		//Virtual
		struct GetExceptionMode
		{
			using ReturnType_t = ::UINT;
			static constexpr size_t Argc = 1;

			::ID3D11Device* pThis;
		};

	private:
		 virtual ~ID3D11Device() = 0;
	};

	class ID3D11Debug : IUnknown
	{
	public:
		//Virtual
		struct SetFeatureMask
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D11Debug* pThis;
			::UINT Mask;
		};

		//Virtual
		struct GetFeatureMask
		{
			using ReturnType_t = ::UINT;
			static constexpr size_t Argc = 1;

			::ID3D11Debug* pThis;
		};

		//Virtual
		struct SetPresentPerRenderOpDelay
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D11Debug* pThis;
			::UINT Milliseconds;
		};

		//Virtual
		struct GetPresentPerRenderOpDelay
		{
			using ReturnType_t = ::UINT;
			static constexpr size_t Argc = 1;

			::ID3D11Debug* pThis;
		};

		//Virtual
		struct SetSwapChain
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D11Debug* pThis;
			::IDXGISwapChain* pSwapChain;
		};

		//Virtual
		struct GetSwapChain
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D11Debug* pThis;
			::IDXGISwapChain** ppSwapChain;
		};

		//Virtual
		struct ValidateContext
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D11Debug* pThis;
			::ID3D11DeviceContext* pContext;
		};

		//Virtual
		struct ReportLiveDeviceObjects
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D11Debug* pThis;
			::D3D11_RLDO_FLAGS Flags;
		};

		//Virtual
		struct ValidateContextForDispatch
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D11Debug* pThis;
			::ID3D11DeviceContext* pContext;
		};

	private:
		 virtual ~ID3D11Debug() = 0;
	};

	class ID3D11SwitchToRef : IUnknown
	{
	public:
		//Virtual
		struct SetUseRef
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 2;

			::ID3D11SwitchToRef* pThis;
			::BOOL UseRef;
		};

		//Virtual
		struct GetUseRef
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 1;

			::ID3D11SwitchToRef* pThis;
		};

	private:
		 virtual ~ID3D11SwitchToRef() = 0;
	};

	class ID3D11TracingDevice : IUnknown
	{
	public:
		//Virtual
		struct SetShaderTrackingOptionsByType
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11TracingDevice* pThis;
			::UINT ResourceTypeFlags;
			::UINT Options;
		};

		//Virtual
		struct SetShaderTrackingOptions
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11TracingDevice* pThis;
			::IUnknown* pShader;
			::UINT Options;
		};

	private:
		 virtual ~ID3D11TracingDevice() = 0;
	};

	class ID3D11RefTrackingOptions : IUnknown
	{
	public:
		//Virtual
		struct SetTrackingOptions
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D11RefTrackingOptions* pThis;
			::UINT uOptions;
		};

	private:
		 virtual ~ID3D11RefTrackingOptions() = 0;
	};

	class ID3D11RefDefaultTrackingOptions : IUnknown
	{
	public:
		//Virtual
		struct SetTrackingOptions
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11RefDefaultTrackingOptions* pThis;
			::UINT ResourceTypeFlags;
			::UINT Options;
		};

	private:
		 virtual ~ID3D11RefDefaultTrackingOptions() = 0;
	};

	class ID3D11InfoQueue : IUnknown
	{
	public:
		//Virtual
		struct SetMessageCountLimit
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D11InfoQueue* pThis;
			::UINT64 MessageCountLimit;
		};

		//Virtual
		struct ClearStoredMessages
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D11InfoQueue* pThis;
		};

		//Virtual
		struct GetMessageA
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11InfoQueue* pThis;
			::UINT64 MessageIndex;
			::D3D11_MESSAGE* pMessage;
			::SIZE_T* pMessageByteLength;
		};

		//Virtual
		struct GetNumMessagesAllowedByStorageFilter
		{
			using ReturnType_t = ::UINT64;
			static constexpr size_t Argc = 1;

			::ID3D11InfoQueue* pThis;
		};

		//Virtual
		struct GetNumMessagesDeniedByStorageFilter
		{
			using ReturnType_t = ::UINT64;
			static constexpr size_t Argc = 1;

			::ID3D11InfoQueue* pThis;
		};

		//Virtual
		struct GetNumStoredMessages
		{
			using ReturnType_t = ::UINT64;
			static constexpr size_t Argc = 1;

			::ID3D11InfoQueue* pThis;
		};

		//Virtual
		struct GetNumStoredMessagesAllowedByRetrievalFilter
		{
			using ReturnType_t = ::UINT64;
			static constexpr size_t Argc = 1;

			::ID3D11InfoQueue* pThis;
		};

		//Virtual
		struct GetNumMessagesDiscardedByMessageCountLimit
		{
			using ReturnType_t = ::UINT64;
			static constexpr size_t Argc = 1;

			::ID3D11InfoQueue* pThis;
		};

		//Virtual
		struct GetMessageCountLimit
		{
			using ReturnType_t = ::UINT64;
			static constexpr size_t Argc = 1;

			::ID3D11InfoQueue* pThis;
		};

		//Virtual
		struct AddStorageFilterEntries
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D11InfoQueue* pThis;
			::D3D11_INFO_QUEUE_FILTER* pFilter;
		};

		//Virtual
		struct GetStorageFilter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11InfoQueue* pThis;
			::D3D11_INFO_QUEUE_FILTER* pFilter;
			::SIZE_T* pFilterByteLength;
		};

		//Virtual
		struct ClearStorageFilter
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D11InfoQueue* pThis;
		};

		//Virtual
		struct PushEmptyStorageFilter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ID3D11InfoQueue* pThis;
		};

		//Virtual
		struct PushCopyOfStorageFilter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ID3D11InfoQueue* pThis;
		};

		//Virtual
		struct PushStorageFilter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D11InfoQueue* pThis;
			::D3D11_INFO_QUEUE_FILTER* pFilter;
		};

		//Virtual
		struct PopStorageFilter
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D11InfoQueue* pThis;
		};

		//Virtual
		struct GetStorageFilterStackSize
		{
			using ReturnType_t = ::UINT;
			static constexpr size_t Argc = 1;

			::ID3D11InfoQueue* pThis;
		};

		//Virtual
		struct AddRetrievalFilterEntries
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D11InfoQueue* pThis;
			::D3D11_INFO_QUEUE_FILTER* pFilter;
		};

		//Virtual
		struct GetRetrievalFilter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11InfoQueue* pThis;
			::D3D11_INFO_QUEUE_FILTER* pFilter;
			::SIZE_T* pFilterByteLength;
		};

		//Virtual
		struct ClearRetrievalFilter
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D11InfoQueue* pThis;
		};

		//Virtual
		struct PushEmptyRetrievalFilter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ID3D11InfoQueue* pThis;
		};

		//Virtual
		struct PushCopyOfRetrievalFilter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ID3D11InfoQueue* pThis;
		};

		//Virtual
		struct PushRetrievalFilter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D11InfoQueue* pThis;
			::D3D11_INFO_QUEUE_FILTER* pFilter;
		};

		//Virtual
		struct PopRetrievalFilter
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D11InfoQueue* pThis;
		};

		//Virtual
		struct GetRetrievalFilterStackSize
		{
			using ReturnType_t = ::UINT;
			static constexpr size_t Argc = 1;

			::ID3D11InfoQueue* pThis;
		};

		//Virtual
		struct AddMessage
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D11InfoQueue* pThis;
			::D3D11_MESSAGE_CATEGORY Category;
			::D3D11_MESSAGE_SEVERITY Severity;
			::D3D11_MESSAGE_ID ID;
			::LPCSTR pDescription;
		};

		//Virtual
		struct AddApplicationMessage
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11InfoQueue* pThis;
			::D3D11_MESSAGE_SEVERITY Severity;
			::LPCSTR pDescription;
		};

		//Virtual
		struct SetBreakOnCategory
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11InfoQueue* pThis;
			::D3D11_MESSAGE_CATEGORY Category;
			::BOOL bEnable;
		};

		//Virtual
		struct SetBreakOnSeverity
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11InfoQueue* pThis;
			::D3D11_MESSAGE_SEVERITY Severity;
			::BOOL bEnable;
		};

		//Virtual
		struct SetBreakOnID
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11InfoQueue* pThis;
			::D3D11_MESSAGE_ID ID;
			::BOOL bEnable;
		};

		//Virtual
		struct GetBreakOnCategory
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 2;

			::ID3D11InfoQueue* pThis;
			::D3D11_MESSAGE_CATEGORY Category;
		};

		//Virtual
		struct GetBreakOnSeverity
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 2;

			::ID3D11InfoQueue* pThis;
			::D3D11_MESSAGE_SEVERITY Severity;
		};

		//Virtual
		struct GetBreakOnID
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 2;

			::ID3D11InfoQueue* pThis;
			::D3D11_MESSAGE_ID ID;
		};

		//Virtual
		struct SetMuteDebugOutput
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11InfoQueue* pThis;
			::BOOL bMute;
		};

		//Virtual
		struct GetMuteDebugOutput
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 1;

			::ID3D11InfoQueue* pThis;
		};

	private:
		 virtual ~ID3D11InfoQueue() = 0;
	};

	class ID3D10DeviceChild : IUnknown
	{
	public:
		//Virtual
		struct GetDevice
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10DeviceChild* pThis;
			::ID3D10Device** ppDevice;
		};

		//Virtual
		struct GetPrivateData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10DeviceChild* pThis;
			const ::GUID& guid;
			::UINT* pDataSize;
			void* pData;
		};

		//Virtual
		struct SetPrivateData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10DeviceChild* pThis;
			const ::GUID& guid;
			::UINT DataSize;
			const void* pData;
		};

		//Virtual
		struct SetPrivateDataInterface
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10DeviceChild* pThis;
			const ::GUID& guid;
			const ::IUnknown* pData;
		};

	private:
		 virtual ~ID3D10DeviceChild() = 0;
	};

	class ID3D10DepthStencilState : ID3D10DeviceChild
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10DepthStencilState* pThis;
			::D3D10_DEPTH_STENCIL_DESC* pDesc;
		};

	private:
		 virtual ~ID3D10DepthStencilState() = 0;
	};

	class ID3D10BlendState : ID3D10DeviceChild
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10BlendState* pThis;
			::D3D10_BLEND_DESC* pDesc;
		};

	private:
		 virtual ~ID3D10BlendState() = 0;
	};

	class ID3D10RasterizerState : ID3D10DeviceChild
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10RasterizerState* pThis;
			::D3D10_RASTERIZER_DESC* pDesc;
		};

	private:
		 virtual ~ID3D10RasterizerState() = 0;
	};

	class ID3D10Resource : ID3D10DeviceChild
	{
	public:
		//Virtual
		struct GetType
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10Resource* pThis;
			::D3D10_RESOURCE_DIMENSION* rType;
		};

		//Virtual
		struct SetEvictionPriority
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10Resource* pThis;
			::UINT EvictionPriority;
		};

		//Virtual
		struct GetEvictionPriority
		{
			using ReturnType_t = ::UINT;
			static constexpr size_t Argc = 1;

			::ID3D10Resource* pThis;
		};

	private:
		 virtual ~ID3D10Resource() = 0;
	};

	class ID3D10Buffer : ID3D10Resource
	{
	public:
		//Virtual
		struct Map
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10Buffer* pThis;
			::D3D10_MAP MapType;
			::UINT MapFlags;
			void** ppData;
		};

		//Virtual
		struct Unmap
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D10Buffer* pThis;
		};

		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10Buffer* pThis;
			::D3D10_BUFFER_DESC* pDesc;
		};

	private:
		 virtual ~ID3D10Buffer() = 0;
	};

	class ID3D10Texture1D : ID3D10Resource
	{
	public:
		//Virtual
		struct Map
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D10Texture1D* pThis;
			::UINT Subresource;
			::D3D10_MAP MapType;
			::UINT MapFlags;
			void** ppData;
		};

		//Virtual
		struct Unmap
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10Texture1D* pThis;
			::UINT Subresource;
		};

		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10Texture1D* pThis;
			::D3D10_TEXTURE1D_DESC* pDesc;
		};

	private:
		 virtual ~ID3D10Texture1D() = 0;
	};

	class ID3D10Texture2D : ID3D10Resource
	{
	public:
		//Virtual
		struct Map
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D10Texture2D* pThis;
			::UINT Subresource;
			::D3D10_MAP MapType;
			::UINT MapFlags;
			::D3D10_MAPPED_TEXTURE2D* pMappedTex2D;
		};

		//Virtual
		struct Unmap
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10Texture2D* pThis;
			::UINT Subresource;
		};

		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10Texture2D* pThis;
			::D3D10_TEXTURE2D_DESC* pDesc;
		};

	private:
		 virtual ~ID3D10Texture2D() = 0;
	};

	class ID3D10Texture3D : ID3D10Resource
	{
	public:
		//Virtual
		struct Map
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D10Texture3D* pThis;
			::UINT Subresource;
			::D3D10_MAP MapType;
			::UINT MapFlags;
			::D3D10_MAPPED_TEXTURE3D* pMappedTex3D;
		};

		//Virtual
		struct Unmap
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10Texture3D* pThis;
			::UINT Subresource;
		};

		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10Texture3D* pThis;
			::D3D10_TEXTURE3D_DESC* pDesc;
		};

	private:
		 virtual ~ID3D10Texture3D() = 0;
	};

	class ID3D10View : ID3D10DeviceChild
	{
	public:
		//Virtual
		struct GetResource
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10View* pThis;
			::ID3D10Resource** ppResource;
		};

	private:
		 virtual ~ID3D10View() = 0;
	};

	class ID3D10ShaderResourceView : ID3D10View
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10ShaderResourceView* pThis;
			::D3D10_SHADER_RESOURCE_VIEW_DESC* pDesc;
		};

	private:
		 virtual ~ID3D10ShaderResourceView() = 0;
	};

	class ID3D10RenderTargetView : ID3D10View
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10RenderTargetView* pThis;
			::D3D10_RENDER_TARGET_VIEW_DESC* pDesc;
		};

	private:
		 virtual ~ID3D10RenderTargetView() = 0;
	};

	class ID3D10DepthStencilView : ID3D10View
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10DepthStencilView* pThis;
			::D3D10_DEPTH_STENCIL_VIEW_DESC* pDesc;
		};

	private:
		 virtual ~ID3D10DepthStencilView() = 0;
	};

	class ID3D10SamplerState : ID3D10DeviceChild
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10SamplerState* pThis;
			::D3D10_SAMPLER_DESC* pDesc;
		};

	private:
		 virtual ~ID3D10SamplerState() = 0;
	};

	class ID3D10Asynchronous : ID3D10DeviceChild
	{
	public:
		//Virtual
		struct Begin
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D10Asynchronous* pThis;
		};

		//Virtual
		struct End
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D10Asynchronous* pThis;
		};

		//Virtual
		struct GetData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10Asynchronous* pThis;
			void* pData;
			::UINT DataSize;
			::UINT GetDataFlags;
		};

		//Virtual
		struct GetDataSize
		{
			using ReturnType_t = ::UINT;
			static constexpr size_t Argc = 1;

			::ID3D10Asynchronous* pThis;
		};

	private:
		 virtual ~ID3D10Asynchronous() = 0;
	};

	class ID3D10Query : ID3D10Asynchronous
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10Query* pThis;
			::D3D10_QUERY_DESC* pDesc;
		};

	private:
		 virtual ~ID3D10Query() = 0;
	};

	class ID3D10Counter : ID3D10Asynchronous
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10Counter* pThis;
			::D3D10_COUNTER_DESC* pDesc;
		};

	private:
		 virtual ~ID3D10Counter() = 0;
	};

	class ID3D10Device : IUnknown
	{
	public:
		//Virtual
		struct VSSetConstantBuffers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D10Buffer*const* ppConstantBuffers;
		};

		//Virtual
		struct PSSetShaderResources
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::UINT StartSlot;
			::UINT NumViews;
			::ID3D10ShaderResourceView*const* ppShaderResourceViews;
		};

		//Virtual
		struct PSSetShader
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10Device* pThis;
			::ID3D10PixelShader* pPixelShader;
		};

		//Virtual
		struct PSSetSamplers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::UINT StartSlot;
			::UINT NumSamplers;
			::ID3D10SamplerState*const* ppSamplers;
		};

		//Virtual
		struct VSSetShader
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10Device* pThis;
			::ID3D10VertexShader* pVertexShader;
		};

		//Virtual
		struct DrawIndexed
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::UINT IndexCount;
			::UINT StartIndexLocation;
			::INT BaseVertexLocation;
		};

		//Virtual
		struct Draw
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D10Device* pThis;
			::UINT VertexCount;
			::UINT StartVertexLocation;
		};

		//Virtual
		struct PSSetConstantBuffers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D10Buffer*const* ppConstantBuffers;
		};

		//Virtual
		struct IASetInputLayout
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10Device* pThis;
			::ID3D10InputLayout* pInputLayout;
		};

		//Virtual
		struct IASetVertexBuffers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D10Device* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D10Buffer*const* ppVertexBuffers;
			const ::UINT* pStrides;
			const ::UINT* pOffsets;
		};

		//Virtual
		struct IASetIndexBuffer
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::ID3D10Buffer* pIndexBuffer;
			::DXGI_FORMAT Format;
			::UINT Offset;
		};

		//Virtual
		struct DrawIndexedInstanced
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D10Device* pThis;
			::UINT IndexCountPerInstance;
			::UINT InstanceCount;
			::UINT StartIndexLocation;
			::INT BaseVertexLocation;
			::UINT StartInstanceLocation;
		};

		//Virtual
		struct DrawInstanced
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 5;

			::ID3D10Device* pThis;
			::UINT VertexCountPerInstance;
			::UINT InstanceCount;
			::UINT StartVertexLocation;
			::UINT StartInstanceLocation;
		};

		//Virtual
		struct GSSetConstantBuffers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D10Buffer*const* ppConstantBuffers;
		};

		//Virtual
		struct GSSetShader
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10Device* pThis;
			::ID3D10GeometryShader* pShader;
		};

		//Virtual
		struct IASetPrimitiveTopology
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10Device* pThis;
			::D3D10_PRIMITIVE_TOPOLOGY Topology;
		};

		//Virtual
		struct VSSetShaderResources
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::UINT StartSlot;
			::UINT NumViews;
			::ID3D10ShaderResourceView*const* ppShaderResourceViews;
		};

		//Virtual
		struct VSSetSamplers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::UINT StartSlot;
			::UINT NumSamplers;
			::ID3D10SamplerState*const* ppSamplers;
		};

		//Virtual
		struct SetPredication
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D10Device* pThis;
			::ID3D10Predicate* pPredicate;
			::BOOL PredicateValue;
		};

		//Virtual
		struct GSSetShaderResources
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::UINT StartSlot;
			::UINT NumViews;
			::ID3D10ShaderResourceView*const* ppShaderResourceViews;
		};

		//Virtual
		struct GSSetSamplers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::UINT StartSlot;
			::UINT NumSamplers;
			::ID3D10SamplerState*const* ppSamplers;
		};

		//Virtual
		struct OMSetRenderTargets
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::UINT NumViews;
			::ID3D10RenderTargetView*const* ppRenderTargetViews;
			::ID3D10DepthStencilView* pDepthStencilView;
		};

		//Virtual
		struct OMSetBlendState
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::ID3D10BlendState* pBlendState;
			const ::FLOAT BlendFactor[4];
			::UINT SampleMask;
		};

		//Virtual
		struct OMSetDepthStencilState
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D10Device* pThis;
			::ID3D10DepthStencilState* pDepthStencilState;
			::UINT StencilRef;
		};

		//Virtual
		struct SOSetTargets
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::UINT NumBuffers;
			::ID3D10Buffer*const* ppSOTargets;
			const ::UINT* pOffsets;
		};

		//Virtual
		struct DrawAuto
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D10Device* pThis;
		};

		//Virtual
		struct RSSetState
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10Device* pThis;
			::ID3D10RasterizerState* pRasterizerState;
		};

		//Virtual
		struct RSSetViewports
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D10Device* pThis;
			::UINT NumViewports;
			const ::D3D10_VIEWPORT* pViewports;
		};

		//Virtual
		struct RSSetScissorRects
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D10Device* pThis;
			::UINT NumRects;
			const ::D3D10_RECT* pRects;
		};

		//Virtual
		struct CopySubresourceRegion
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 9;

			::ID3D10Device* pThis;
			::ID3D10Resource* pDstResource;
			::UINT DstSubresource;
			::UINT DstX;
			::UINT DstY;
			::UINT DstZ;
			::ID3D10Resource* pSrcResource;
			::UINT SrcSubresource;
			const ::D3D10_BOX* pSrcBox;
		};

		//Virtual
		struct CopyResource
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D10Device* pThis;
			::ID3D10Resource* pDstResource;
			::ID3D10Resource* pSrcResource;
		};

		//Virtual
		struct UpdateSubresource
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 7;

			::ID3D10Device* pThis;
			::ID3D10Resource* pDstResource;
			::UINT DstSubresource;
			const ::D3D10_BOX* pDstBox;
			const void* pSrcData;
			::UINT SrcRowPitch;
			::UINT SrcDepthPitch;
		};

		//Virtual
		struct ClearRenderTargetView
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D10Device* pThis;
			::ID3D10RenderTargetView* pRenderTargetView;
			const ::FLOAT ColorRGBA[4];
		};

		//Virtual
		struct ClearDepthStencilView
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 5;

			::ID3D10Device* pThis;
			::ID3D10DepthStencilView* pDepthStencilView;
			::UINT ClearFlags;
			::FLOAT Depth;
			::UINT8 Stencil;
		};

		//Virtual
		struct GenerateMips
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10Device* pThis;
			::ID3D10ShaderResourceView* pShaderResourceView;
		};

		//Virtual
		struct ResolveSubresource
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D10Device* pThis;
			::ID3D10Resource* pDstResource;
			::UINT DstSubresource;
			::ID3D10Resource* pSrcResource;
			::UINT SrcSubresource;
			::DXGI_FORMAT Format;
		};

		//Virtual
		struct VSGetConstantBuffers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D10Buffer** ppConstantBuffers;
		};

		//Virtual
		struct PSGetShaderResources
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::UINT StartSlot;
			::UINT NumViews;
			::ID3D10ShaderResourceView** ppShaderResourceViews;
		};

		//Virtual
		struct PSGetShader
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10Device* pThis;
			::ID3D10PixelShader** ppPixelShader;
		};

		//Virtual
		struct PSGetSamplers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::UINT StartSlot;
			::UINT NumSamplers;
			::ID3D10SamplerState** ppSamplers;
		};

		//Virtual
		struct VSGetShader
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10Device* pThis;
			::ID3D10VertexShader** ppVertexShader;
		};

		//Virtual
		struct PSGetConstantBuffers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D10Buffer** ppConstantBuffers;
		};

		//Virtual
		struct IAGetInputLayout
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10Device* pThis;
			::ID3D10InputLayout** ppInputLayout;
		};

		//Virtual
		struct IAGetVertexBuffers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D10Device* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D10Buffer** ppVertexBuffers;
			::UINT* pStrides;
			::UINT* pOffsets;
		};

		//Virtual
		struct IAGetIndexBuffer
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::ID3D10Buffer** pIndexBuffer;
			::DXGI_FORMAT* Format;
			::UINT* Offset;
		};

		//Virtual
		struct GSGetConstantBuffers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D10Buffer** ppConstantBuffers;
		};

		//Virtual
		struct GSGetShader
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10Device* pThis;
			::ID3D10GeometryShader** ppGeometryShader;
		};

		//Virtual
		struct IAGetPrimitiveTopology
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10Device* pThis;
			::D3D10_PRIMITIVE_TOPOLOGY* pTopology;
		};

		//Virtual
		struct VSGetShaderResources
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::UINT StartSlot;
			::UINT NumViews;
			::ID3D10ShaderResourceView** ppShaderResourceViews;
		};

		//Virtual
		struct VSGetSamplers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::UINT StartSlot;
			::UINT NumSamplers;
			::ID3D10SamplerState** ppSamplers;
		};

		//Virtual
		struct GetPredication
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D10Device* pThis;
			::ID3D10Predicate** ppPredicate;
			::BOOL* pPredicateValue;
		};

		//Virtual
		struct GSGetShaderResources
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::UINT StartSlot;
			::UINT NumViews;
			::ID3D10ShaderResourceView** ppShaderResourceViews;
		};

		//Virtual
		struct GSGetSamplers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::UINT StartSlot;
			::UINT NumSamplers;
			::ID3D10SamplerState** ppSamplers;
		};

		//Virtual
		struct OMGetRenderTargets
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::UINT NumViews;
			::ID3D10RenderTargetView** ppRenderTargetViews;
			::ID3D10DepthStencilView** ppDepthStencilView;
		};

		//Virtual
		struct OMGetBlendState
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::ID3D10BlendState** ppBlendState;
			::FLOAT BlendFactor[4];
			::UINT* pSampleMask;
		};

		//Virtual
		struct OMGetDepthStencilState
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D10Device* pThis;
			::ID3D10DepthStencilState** ppDepthStencilState;
			::UINT* pStencilRef;
		};

		//Virtual
		struct SOGetTargets
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::UINT NumBuffers;
			::ID3D10Buffer** ppSOTargets;
			::UINT* pOffsets;
		};

		//Virtual
		struct RSGetState
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10Device* pThis;
			::ID3D10RasterizerState** ppRasterizerState;
		};

		//Virtual
		struct RSGetViewports
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D10Device* pThis;
			::UINT* NumViewports;
			::D3D10_VIEWPORT* pViewports;
		};

		//Virtual
		struct RSGetScissorRects
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D10Device* pThis;
			::UINT* NumRects;
			::D3D10_RECT* pRects;
		};

		//Virtual
		struct GetDeviceRemovedReason
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ID3D10Device* pThis;
		};

		//Virtual
		struct SetExceptionMode
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10Device* pThis;
			::UINT RaiseFlags;
		};

		//Virtual
		struct GetExceptionMode
		{
			using ReturnType_t = ::UINT;
			static constexpr size_t Argc = 1;

			::ID3D10Device* pThis;
		};

		//Virtual
		struct GetPrivateData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			const ::GUID& guid;
			::UINT* pDataSize;
			void* pData;
		};

		//Virtual
		struct SetPrivateData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			const ::GUID& guid;
			::UINT DataSize;
			const void* pData;
		};

		//Virtual
		struct SetPrivateDataInterface
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10Device* pThis;
			const ::GUID& guid;
			const ::IUnknown* pData;
		};

		//Virtual
		struct ClearState
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D10Device* pThis;
		};

		//Virtual
		struct Flush
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D10Device* pThis;
		};

		//Virtual
		struct CreateBuffer
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			const ::D3D10_BUFFER_DESC* pDesc;
			const ::D3D10_SUBRESOURCE_DATA* pInitialData;
			::ID3D10Buffer** ppBuffer;
		};

		//Virtual
		struct CreateTexture1D
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			const ::D3D10_TEXTURE1D_DESC* pDesc;
			const ::D3D10_SUBRESOURCE_DATA* pInitialData;
			::ID3D10Texture1D** ppTexture1D;
		};

		//Virtual
		struct CreateTexture2D
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			const ::D3D10_TEXTURE2D_DESC* pDesc;
			const ::D3D10_SUBRESOURCE_DATA* pInitialData;
			::ID3D10Texture2D** ppTexture2D;
		};

		//Virtual
		struct CreateTexture3D
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			const ::D3D10_TEXTURE3D_DESC* pDesc;
			const ::D3D10_SUBRESOURCE_DATA* pInitialData;
			::ID3D10Texture3D** ppTexture3D;
		};

		//Virtual
		struct CreateShaderResourceView
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::ID3D10Resource* pResource;
			const ::D3D10_SHADER_RESOURCE_VIEW_DESC* pDesc;
			::ID3D10ShaderResourceView** ppSRView;
		};

		//Virtual
		struct CreateRenderTargetView
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::ID3D10Resource* pResource;
			const ::D3D10_RENDER_TARGET_VIEW_DESC* pDesc;
			::ID3D10RenderTargetView** ppRTView;
		};

		//Virtual
		struct CreateDepthStencilView
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::ID3D10Resource* pResource;
			const ::D3D10_DEPTH_STENCIL_VIEW_DESC* pDesc;
			::ID3D10DepthStencilView** ppDepthStencilView;
		};

		//Virtual
		struct CreateInputLayout
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::ID3D10Device* pThis;
			const ::D3D10_INPUT_ELEMENT_DESC* pInputElementDescs;
			::UINT NumElements;
			const void* pShaderBytecodeWithInputSignature;
			::SIZE_T BytecodeLength;
			::ID3D10InputLayout** ppInputLayout;
		};

		//Virtual
		struct CreateVertexShader
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			const void* pShaderBytecode;
			::SIZE_T BytecodeLength;
			::ID3D10VertexShader** ppVertexShader;
		};

		//Virtual
		struct CreateGeometryShader
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			const void* pShaderBytecode;
			::SIZE_T BytecodeLength;
			::ID3D10GeometryShader** ppGeometryShader;
		};

		//Virtual
		struct CreateGeometryShaderWithStreamOutput
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 7;

			::ID3D10Device* pThis;
			const void* pShaderBytecode;
			::SIZE_T BytecodeLength;
			const ::D3D10_SO_DECLARATION_ENTRY* pSODeclaration;
			::UINT NumEntries;
			::UINT OutputStreamStride;
			::ID3D10GeometryShader** ppGeometryShader;
		};

		//Virtual
		struct CreatePixelShader
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			const void* pShaderBytecode;
			::SIZE_T BytecodeLength;
			::ID3D10PixelShader** ppPixelShader;
		};

		//Virtual
		struct CreateBlendState
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10Device* pThis;
			const ::D3D10_BLEND_DESC* pBlendStateDesc;
			::ID3D10BlendState** ppBlendState;
		};

		//Virtual
		struct CreateDepthStencilState
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10Device* pThis;
			const ::D3D10_DEPTH_STENCIL_DESC* pDepthStencilDesc;
			::ID3D10DepthStencilState** ppDepthStencilState;
		};

		//Virtual
		struct CreateRasterizerState
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10Device* pThis;
			const ::D3D10_RASTERIZER_DESC* pRasterizerDesc;
			::ID3D10RasterizerState** ppRasterizerState;
		};

		//Virtual
		struct CreateSamplerState
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10Device* pThis;
			const ::D3D10_SAMPLER_DESC* pSamplerDesc;
			::ID3D10SamplerState** ppSamplerState;
		};

		//Virtual
		struct CreateQuery
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10Device* pThis;
			const ::D3D10_QUERY_DESC* pQueryDesc;
			::ID3D10Query** ppQuery;
		};

		//Virtual
		struct CreatePredicate
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10Device* pThis;
			const ::D3D10_QUERY_DESC* pPredicateDesc;
			::ID3D10Predicate** ppPredicate;
		};

		//Virtual
		struct CreateCounter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10Device* pThis;
			const ::D3D10_COUNTER_DESC* pCounterDesc;
			::ID3D10Counter** ppCounter;
		};

		//Virtual
		struct CheckFormatSupport
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10Device* pThis;
			::DXGI_FORMAT Format;
			::UINT* pFormatSupport;
		};

		//Virtual
		struct CheckMultisampleQualityLevels
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::DXGI_FORMAT Format;
			::UINT SampleCount;
			::UINT* pNumQualityLevels;
		};

		//Virtual
		struct CheckCounterInfo
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10Device* pThis;
			::D3D10_COUNTER_INFO* pCounterInfo;
		};

		//Virtual
		struct CheckCounter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 10;

			::ID3D10Device* pThis;
			const ::D3D10_COUNTER_DESC* pDesc;
			::D3D10_COUNTER_TYPE* pType;
			::UINT* pActiveCounters;
			::LPSTR szName;
			::UINT* pNameLength;
			::LPSTR szUnits;
			::UINT* pUnitsLength;
			::LPSTR szDescription;
			::UINT* pDescriptionLength;
		};

		//Virtual
		struct GetCreationFlags
		{
			using ReturnType_t = ::UINT;
			static constexpr size_t Argc = 1;

			::ID3D10Device* pThis;
		};

		//Virtual
		struct OpenSharedResource
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10Device* pThis;
			::HANDLE hResource;
			const ::IID& ReturnedInterface;
			void** ppResource;
		};

		//Virtual
		struct SetTextFilterSize
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D10Device* pThis;
			::UINT Width;
			::UINT Height;
		};

		//Virtual
		struct GetTextFilterSize
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D10Device* pThis;
			::UINT* pWidth;
			::UINT* pHeight;
		};

	private:
		 virtual ~ID3D10Device() = 0;
	};

	class ID3D10Multithread : IUnknown
	{
	public:
		//Virtual
		struct Enter
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D10Multithread* pThis;
		};

		//Virtual
		struct Leave
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D10Multithread* pThis;
		};

		//Virtual
		struct SetMultithreadProtected
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 2;

			::ID3D10Multithread* pThis;
			::BOOL bMTProtect;
		};

		//Virtual
		struct GetMultithreadProtected
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 1;

			::ID3D10Multithread* pThis;
		};

	private:
		 virtual ~ID3D10Multithread() = 0;
	};

	class ID3D10Debug : IUnknown
	{
	public:
		//Virtual
		struct SetFeatureMask
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10Debug* pThis;
			::UINT Mask;
		};

		//Virtual
		struct GetFeatureMask
		{
			using ReturnType_t = ::UINT;
			static constexpr size_t Argc = 1;

			::ID3D10Debug* pThis;
		};

		//Virtual
		struct SetPresentPerRenderOpDelay
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10Debug* pThis;
			::UINT Milliseconds;
		};

		//Virtual
		struct GetPresentPerRenderOpDelay
		{
			using ReturnType_t = ::UINT;
			static constexpr size_t Argc = 1;

			::ID3D10Debug* pThis;
		};

		//Virtual
		struct SetSwapChain
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10Debug* pThis;
			::IDXGISwapChain* pSwapChain;
		};

		//Virtual
		struct GetSwapChain
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10Debug* pThis;
			::IDXGISwapChain** ppSwapChain;
		};

		//Virtual
		struct Validate
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ID3D10Debug* pThis;
		};

	private:
		 virtual ~ID3D10Debug() = 0;
	};

	class ID3D10SwitchToRef : IUnknown
	{
	public:
		//Virtual
		struct SetUseRef
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 2;

			::ID3D10SwitchToRef* pThis;
			::BOOL UseRef;
		};

		//Virtual
		struct GetUseRef
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 1;

			::ID3D10SwitchToRef* pThis;
		};

	private:
		 virtual ~ID3D10SwitchToRef() = 0;
	};

	class ID3D10InfoQueue : IUnknown
	{
	public:
		//Virtual
		struct SetMessageCountLimit
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10InfoQueue* pThis;
			::UINT64 MessageCountLimit;
		};

		//Virtual
		struct ClearStoredMessages
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D10InfoQueue* pThis;
		};

		//Virtual
		struct GetMessageA
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10InfoQueue* pThis;
			::UINT64 MessageIndex;
			::D3D10_MESSAGE* pMessage;
			::SIZE_T* pMessageByteLength;
		};

		//Virtual
		struct GetNumMessagesAllowedByStorageFilter
		{
			using ReturnType_t = ::UINT64;
			static constexpr size_t Argc = 1;

			::ID3D10InfoQueue* pThis;
		};

		//Virtual
		struct GetNumMessagesDeniedByStorageFilter
		{
			using ReturnType_t = ::UINT64;
			static constexpr size_t Argc = 1;

			::ID3D10InfoQueue* pThis;
		};

		//Virtual
		struct GetNumStoredMessages
		{
			using ReturnType_t = ::UINT64;
			static constexpr size_t Argc = 1;

			::ID3D10InfoQueue* pThis;
		};

		//Virtual
		struct GetNumStoredMessagesAllowedByRetrievalFilter
		{
			using ReturnType_t = ::UINT64;
			static constexpr size_t Argc = 1;

			::ID3D10InfoQueue* pThis;
		};

		//Virtual
		struct GetNumMessagesDiscardedByMessageCountLimit
		{
			using ReturnType_t = ::UINT64;
			static constexpr size_t Argc = 1;

			::ID3D10InfoQueue* pThis;
		};

		//Virtual
		struct GetMessageCountLimit
		{
			using ReturnType_t = ::UINT64;
			static constexpr size_t Argc = 1;

			::ID3D10InfoQueue* pThis;
		};

		//Virtual
		struct AddStorageFilterEntries
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10InfoQueue* pThis;
			::D3D10_INFO_QUEUE_FILTER* pFilter;
		};

		//Virtual
		struct GetStorageFilter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10InfoQueue* pThis;
			::D3D10_INFO_QUEUE_FILTER* pFilter;
			::SIZE_T* pFilterByteLength;
		};

		//Virtual
		struct ClearStorageFilter
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D10InfoQueue* pThis;
		};

		//Virtual
		struct PushEmptyStorageFilter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ID3D10InfoQueue* pThis;
		};

		//Virtual
		struct PushCopyOfStorageFilter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ID3D10InfoQueue* pThis;
		};

		//Virtual
		struct PushStorageFilter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10InfoQueue* pThis;
			::D3D10_INFO_QUEUE_FILTER* pFilter;
		};

		//Virtual
		struct PopStorageFilter
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D10InfoQueue* pThis;
		};

		//Virtual
		struct GetStorageFilterStackSize
		{
			using ReturnType_t = ::UINT;
			static constexpr size_t Argc = 1;

			::ID3D10InfoQueue* pThis;
		};

		//Virtual
		struct AddRetrievalFilterEntries
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10InfoQueue* pThis;
			::D3D10_INFO_QUEUE_FILTER* pFilter;
		};

		//Virtual
		struct GetRetrievalFilter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10InfoQueue* pThis;
			::D3D10_INFO_QUEUE_FILTER* pFilter;
			::SIZE_T* pFilterByteLength;
		};

		//Virtual
		struct ClearRetrievalFilter
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D10InfoQueue* pThis;
		};

		//Virtual
		struct PushEmptyRetrievalFilter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ID3D10InfoQueue* pThis;
		};

		//Virtual
		struct PushCopyOfRetrievalFilter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ID3D10InfoQueue* pThis;
		};

		//Virtual
		struct PushRetrievalFilter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10InfoQueue* pThis;
			::D3D10_INFO_QUEUE_FILTER* pFilter;
		};

		//Virtual
		struct PopRetrievalFilter
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D10InfoQueue* pThis;
		};

		//Virtual
		struct GetRetrievalFilterStackSize
		{
			using ReturnType_t = ::UINT;
			static constexpr size_t Argc = 1;

			::ID3D10InfoQueue* pThis;
		};

		//Virtual
		struct AddMessage
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D10InfoQueue* pThis;
			::D3D10_MESSAGE_CATEGORY Category;
			::D3D10_MESSAGE_SEVERITY Severity;
			::D3D10_MESSAGE_ID ID;
			::LPCSTR pDescription;
		};

		//Virtual
		struct AddApplicationMessage
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10InfoQueue* pThis;
			::D3D10_MESSAGE_SEVERITY Severity;
			::LPCSTR pDescription;
		};

		//Virtual
		struct SetBreakOnCategory
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10InfoQueue* pThis;
			::D3D10_MESSAGE_CATEGORY Category;
			::BOOL bEnable;
		};

		//Virtual
		struct SetBreakOnSeverity
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10InfoQueue* pThis;
			::D3D10_MESSAGE_SEVERITY Severity;
			::BOOL bEnable;
		};

		//Virtual
		struct SetBreakOnID
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10InfoQueue* pThis;
			::D3D10_MESSAGE_ID ID;
			::BOOL bEnable;
		};

		//Virtual
		struct GetBreakOnCategory
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 2;

			::ID3D10InfoQueue* pThis;
			::D3D10_MESSAGE_CATEGORY Category;
		};

		//Virtual
		struct GetBreakOnSeverity
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 2;

			::ID3D10InfoQueue* pThis;
			::D3D10_MESSAGE_SEVERITY Severity;
		};

		//Virtual
		struct GetBreakOnID
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 2;

			::ID3D10InfoQueue* pThis;
			::D3D10_MESSAGE_ID ID;
		};

		//Virtual
		struct SetMuteDebugOutput
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10InfoQueue* pThis;
			::BOOL bMute;
		};

		//Virtual
		struct GetMuteDebugOutput
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 1;

			::ID3D10InfoQueue* pThis;
		};

	private:
		 virtual ~ID3D10InfoQueue() = 0;
	};

	class ID3D10StateBlock : IUnknown
	{
	public:
		//Virtual
		struct QueryInterface
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10StateBlock* pThis;
			const ::IID& iid;
			::LPVOID* ppv;
		};

		//Virtual
		struct AddRef
		{
			using ReturnType_t = ::ULONG;
			static constexpr size_t Argc = 1;

			::ID3D10StateBlock* pThis;
		};

		//Virtual
		struct Release
		{
			using ReturnType_t = ::ULONG;
			static constexpr size_t Argc = 1;

			::ID3D10StateBlock* pThis;
		};

		//Virtual
		struct Capture
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ID3D10StateBlock* pThis;
		};

		//Virtual
		struct Apply
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ID3D10StateBlock* pThis;
		};

		//Virtual
		struct ReleaseAllDeviceObjects
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ID3D10StateBlock* pThis;
		};

		//Virtual
		struct GetDevice
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10StateBlock* pThis;
			::ID3D10Device** ppDevice;
		};

	private:
		 virtual ~ID3D10StateBlock() = 0;
	};

	class ID3D10EffectScalarVariable : ID3D10EffectVariable
	{
	public:
		//Virtual
		struct IsValid
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 1;

			::ID3D10EffectScalarVariable* pThis;
		};

		//Virtual
		struct GetType
		{
			using ReturnType_t = ::ID3D10EffectType*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectScalarVariable* pThis;
		};

		//Virtual
		struct GetDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectScalarVariable* pThis;
			::D3D10_EFFECT_VARIABLE_DESC* pDesc;
		};

		//Virtual
		struct GetAnnotationByIndex
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectScalarVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetAnnotationByName
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectScalarVariable* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetMemberByIndex
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectScalarVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetMemberByName
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectScalarVariable* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetMemberBySemantic
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectScalarVariable* pThis;
			::LPCSTR Semantic;
		};

		//Virtual
		struct GetElement
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectScalarVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetParentConstantBuffer
		{
			using ReturnType_t = ::ID3D10EffectConstantBuffer*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectScalarVariable* pThis;
		};

		//Virtual
		struct AsScalar
		{
			using ReturnType_t = ::ID3D10EffectScalarVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectScalarVariable* pThis;
		};

		//Virtual
		struct AsVector
		{
			using ReturnType_t = ::ID3D10EffectVectorVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectScalarVariable* pThis;
		};

		//Virtual
		struct AsMatrix
		{
			using ReturnType_t = ::ID3D10EffectMatrixVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectScalarVariable* pThis;
		};

		//Virtual
		struct AsString
		{
			using ReturnType_t = ::ID3D10EffectStringVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectScalarVariable* pThis;
		};

		//Virtual
		struct AsShaderResource
		{
			using ReturnType_t = ::ID3D10EffectShaderResourceVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectScalarVariable* pThis;
		};

		//Virtual
		struct AsRenderTargetView
		{
			using ReturnType_t = ::ID3D10EffectRenderTargetViewVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectScalarVariable* pThis;
		};

		//Virtual
		struct AsDepthStencilView
		{
			using ReturnType_t = ::ID3D10EffectDepthStencilViewVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectScalarVariable* pThis;
		};

		//Virtual
		struct AsConstantBuffer
		{
			using ReturnType_t = ::ID3D10EffectConstantBuffer*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectScalarVariable* pThis;
		};

		//Virtual
		struct AsShader
		{
			using ReturnType_t = ::ID3D10EffectShaderVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectScalarVariable* pThis;
		};

		//Virtual
		struct AsBlend
		{
			using ReturnType_t = ::ID3D10EffectBlendVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectScalarVariable* pThis;
		};

		//Virtual
		struct AsDepthStencil
		{
			using ReturnType_t = ::ID3D10EffectDepthStencilVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectScalarVariable* pThis;
		};

		//Virtual
		struct AsRasterizer
		{
			using ReturnType_t = ::ID3D10EffectRasterizerVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectScalarVariable* pThis;
		};

		//Virtual
		struct AsSampler
		{
			using ReturnType_t = ::ID3D10EffectSamplerVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectScalarVariable* pThis;
		};

		//Virtual
		struct SetRawValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectScalarVariable* pThis;
			void* pData;
			::UINT ByteOffset;
			::UINT ByteCount;
		};

		//Virtual
		struct GetRawValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectScalarVariable* pThis;
			void* pData;
			::UINT ByteOffset;
			::UINT ByteCount;
		};

		//Virtual
		struct SetFloat
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectScalarVariable* pThis;
			float Value;
		};

		//Virtual
		struct GetFloat
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectScalarVariable* pThis;
			float* pValue;
		};

		//Virtual
		struct SetFloatArray
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectScalarVariable* pThis;
			float* pData;
			::UINT Offset;
			::UINT Count;
		};

		//Virtual
		struct GetFloatArray
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectScalarVariable* pThis;
			float* pData;
			::UINT Offset;
			::UINT Count;
		};

		//Virtual
		struct SetInt
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectScalarVariable* pThis;
			int Value;
		};

		//Virtual
		struct GetInt
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectScalarVariable* pThis;
			int* pValue;
		};

		//Virtual
		struct SetIntArray
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectScalarVariable* pThis;
			int* pData;
			::UINT Offset;
			::UINT Count;
		};

		//Virtual
		struct GetIntArray
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectScalarVariable* pThis;
			int* pData;
			::UINT Offset;
			::UINT Count;
		};

		//Virtual
		struct SetBool
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectScalarVariable* pThis;
			::BOOL Value;
		};

		//Virtual
		struct GetBool
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectScalarVariable* pThis;
			::BOOL* pValue;
		};

		//Virtual
		struct SetBoolArray
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectScalarVariable* pThis;
			::BOOL* pData;
			::UINT Offset;
			::UINT Count;
		};

		//Virtual
		struct GetBoolArray
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectScalarVariable* pThis;
			::BOOL* pData;
			::UINT Offset;
			::UINT Count;
		};

	private:
		 virtual ~ID3D10EffectScalarVariable() = 0;
	};

	class ID3D10EffectVectorVariable : ID3D10EffectVariable
	{
	public:
		//Virtual
		struct IsValid
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVectorVariable* pThis;
		};

		//Virtual
		struct GetType
		{
			using ReturnType_t = ::ID3D10EffectType*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVectorVariable* pThis;
		};

		//Virtual
		struct GetDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectVectorVariable* pThis;
			::D3D10_EFFECT_VARIABLE_DESC* pDesc;
		};

		//Virtual
		struct GetAnnotationByIndex
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectVectorVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetAnnotationByName
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectVectorVariable* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetMemberByIndex
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectVectorVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetMemberByName
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectVectorVariable* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetMemberBySemantic
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectVectorVariable* pThis;
			::LPCSTR Semantic;
		};

		//Virtual
		struct GetElement
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectVectorVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetParentConstantBuffer
		{
			using ReturnType_t = ::ID3D10EffectConstantBuffer*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVectorVariable* pThis;
		};

		//Virtual
		struct AsScalar
		{
			using ReturnType_t = ::ID3D10EffectScalarVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVectorVariable* pThis;
		};

		//Virtual
		struct AsVector
		{
			using ReturnType_t = ::ID3D10EffectVectorVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVectorVariable* pThis;
		};

		//Virtual
		struct AsMatrix
		{
			using ReturnType_t = ::ID3D10EffectMatrixVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVectorVariable* pThis;
		};

		//Virtual
		struct AsString
		{
			using ReturnType_t = ::ID3D10EffectStringVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVectorVariable* pThis;
		};

		//Virtual
		struct AsShaderResource
		{
			using ReturnType_t = ::ID3D10EffectShaderResourceVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVectorVariable* pThis;
		};

		//Virtual
		struct AsRenderTargetView
		{
			using ReturnType_t = ::ID3D10EffectRenderTargetViewVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVectorVariable* pThis;
		};

		//Virtual
		struct AsDepthStencilView
		{
			using ReturnType_t = ::ID3D10EffectDepthStencilViewVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVectorVariable* pThis;
		};

		//Virtual
		struct AsConstantBuffer
		{
			using ReturnType_t = ::ID3D10EffectConstantBuffer*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVectorVariable* pThis;
		};

		//Virtual
		struct AsShader
		{
			using ReturnType_t = ::ID3D10EffectShaderVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVectorVariable* pThis;
		};

		//Virtual
		struct AsBlend
		{
			using ReturnType_t = ::ID3D10EffectBlendVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVectorVariable* pThis;
		};

		//Virtual
		struct AsDepthStencil
		{
			using ReturnType_t = ::ID3D10EffectDepthStencilVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVectorVariable* pThis;
		};

		//Virtual
		struct AsRasterizer
		{
			using ReturnType_t = ::ID3D10EffectRasterizerVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVectorVariable* pThis;
		};

		//Virtual
		struct AsSampler
		{
			using ReturnType_t = ::ID3D10EffectSamplerVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectVectorVariable* pThis;
		};

		//Virtual
		struct SetRawValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectVectorVariable* pThis;
			void* pData;
			::UINT ByteOffset;
			::UINT ByteCount;
		};

		//Virtual
		struct GetRawValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectVectorVariable* pThis;
			void* pData;
			::UINT ByteOffset;
			::UINT ByteCount;
		};

		//Virtual
		struct SetBoolVector
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectVectorVariable* pThis;
			::BOOL* pData;
		};

		//Virtual
		struct SetIntVector
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectVectorVariable* pThis;
			int* pData;
		};

		//Virtual
		struct SetFloatVector
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectVectorVariable* pThis;
			float* pData;
		};

		//Virtual
		struct GetBoolVector
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectVectorVariable* pThis;
			::BOOL* pData;
		};

		//Virtual
		struct GetIntVector
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectVectorVariable* pThis;
			int* pData;
		};

		//Virtual
		struct GetFloatVector
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectVectorVariable* pThis;
			float* pData;
		};

		//Virtual
		struct SetBoolVectorArray
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectVectorVariable* pThis;
			::BOOL* pData;
			::UINT Offset;
			::UINT Count;
		};

		//Virtual
		struct SetIntVectorArray
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectVectorVariable* pThis;
			int* pData;
			::UINT Offset;
			::UINT Count;
		};

		//Virtual
		struct SetFloatVectorArray
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectVectorVariable* pThis;
			float* pData;
			::UINT Offset;
			::UINT Count;
		};

		//Virtual
		struct GetBoolVectorArray
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectVectorVariable* pThis;
			::BOOL* pData;
			::UINT Offset;
			::UINT Count;
		};

		//Virtual
		struct GetIntVectorArray
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectVectorVariable* pThis;
			int* pData;
			::UINT Offset;
			::UINT Count;
		};

		//Virtual
		struct GetFloatVectorArray
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectVectorVariable* pThis;
			float* pData;
			::UINT Offset;
			::UINT Count;
		};

	private:
		 virtual ~ID3D10EffectVectorVariable() = 0;
	};

	class ID3D10EffectMatrixVariable : ID3D10EffectVariable
	{
	public:
		//Virtual
		struct IsValid
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 1;

			::ID3D10EffectMatrixVariable* pThis;
		};

		//Virtual
		struct GetType
		{
			using ReturnType_t = ::ID3D10EffectType*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectMatrixVariable* pThis;
		};

		//Virtual
		struct GetDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectMatrixVariable* pThis;
			::D3D10_EFFECT_VARIABLE_DESC* pDesc;
		};

		//Virtual
		struct GetAnnotationByIndex
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectMatrixVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetAnnotationByName
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectMatrixVariable* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetMemberByIndex
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectMatrixVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetMemberByName
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectMatrixVariable* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetMemberBySemantic
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectMatrixVariable* pThis;
			::LPCSTR Semantic;
		};

		//Virtual
		struct GetElement
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectMatrixVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetParentConstantBuffer
		{
			using ReturnType_t = ::ID3D10EffectConstantBuffer*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectMatrixVariable* pThis;
		};

		//Virtual
		struct AsScalar
		{
			using ReturnType_t = ::ID3D10EffectScalarVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectMatrixVariable* pThis;
		};

		//Virtual
		struct AsVector
		{
			using ReturnType_t = ::ID3D10EffectVectorVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectMatrixVariable* pThis;
		};

		//Virtual
		struct AsMatrix
		{
			using ReturnType_t = ::ID3D10EffectMatrixVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectMatrixVariable* pThis;
		};

		//Virtual
		struct AsString
		{
			using ReturnType_t = ::ID3D10EffectStringVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectMatrixVariable* pThis;
		};

		//Virtual
		struct AsShaderResource
		{
			using ReturnType_t = ::ID3D10EffectShaderResourceVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectMatrixVariable* pThis;
		};

		//Virtual
		struct AsRenderTargetView
		{
			using ReturnType_t = ::ID3D10EffectRenderTargetViewVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectMatrixVariable* pThis;
		};

		//Virtual
		struct AsDepthStencilView
		{
			using ReturnType_t = ::ID3D10EffectDepthStencilViewVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectMatrixVariable* pThis;
		};

		//Virtual
		struct AsConstantBuffer
		{
			using ReturnType_t = ::ID3D10EffectConstantBuffer*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectMatrixVariable* pThis;
		};

		//Virtual
		struct AsShader
		{
			using ReturnType_t = ::ID3D10EffectShaderVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectMatrixVariable* pThis;
		};

		//Virtual
		struct AsBlend
		{
			using ReturnType_t = ::ID3D10EffectBlendVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectMatrixVariable* pThis;
		};

		//Virtual
		struct AsDepthStencil
		{
			using ReturnType_t = ::ID3D10EffectDepthStencilVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectMatrixVariable* pThis;
		};

		//Virtual
		struct AsRasterizer
		{
			using ReturnType_t = ::ID3D10EffectRasterizerVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectMatrixVariable* pThis;
		};

		//Virtual
		struct AsSampler
		{
			using ReturnType_t = ::ID3D10EffectSamplerVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectMatrixVariable* pThis;
		};

		//Virtual
		struct SetRawValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectMatrixVariable* pThis;
			void* pData;
			::UINT ByteOffset;
			::UINT ByteCount;
		};

		//Virtual
		struct GetRawValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectMatrixVariable* pThis;
			void* pData;
			::UINT ByteOffset;
			::UINT ByteCount;
		};

		//Virtual
		struct SetMatrix
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectMatrixVariable* pThis;
			float* pData;
		};

		//Virtual
		struct GetMatrix
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectMatrixVariable* pThis;
			float* pData;
		};

		//Virtual
		struct SetMatrixArray
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectMatrixVariable* pThis;
			float* pData;
			::UINT Offset;
			::UINT Count;
		};

		//Virtual
		struct GetMatrixArray
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectMatrixVariable* pThis;
			float* pData;
			::UINT Offset;
			::UINT Count;
		};

		//Virtual
		struct SetMatrixTranspose
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectMatrixVariable* pThis;
			float* pData;
		};

		//Virtual
		struct GetMatrixTranspose
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectMatrixVariable* pThis;
			float* pData;
		};

		//Virtual
		struct SetMatrixTransposeArray
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectMatrixVariable* pThis;
			float* pData;
			::UINT Offset;
			::UINT Count;
		};

		//Virtual
		struct GetMatrixTransposeArray
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectMatrixVariable* pThis;
			float* pData;
			::UINT Offset;
			::UINT Count;
		};

	private:
		 virtual ~ID3D10EffectMatrixVariable() = 0;
	};

	class ID3D10EffectStringVariable : ID3D10EffectVariable
	{
	public:
		//Virtual
		struct IsValid
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 1;

			::ID3D10EffectStringVariable* pThis;
		};

		//Virtual
		struct GetType
		{
			using ReturnType_t = ::ID3D10EffectType*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectStringVariable* pThis;
		};

		//Virtual
		struct GetDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectStringVariable* pThis;
			::D3D10_EFFECT_VARIABLE_DESC* pDesc;
		};

		//Virtual
		struct GetAnnotationByIndex
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectStringVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetAnnotationByName
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectStringVariable* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetMemberByIndex
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectStringVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetMemberByName
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectStringVariable* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetMemberBySemantic
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectStringVariable* pThis;
			::LPCSTR Semantic;
		};

		//Virtual
		struct GetElement
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectStringVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetParentConstantBuffer
		{
			using ReturnType_t = ::ID3D10EffectConstantBuffer*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectStringVariable* pThis;
		};

		//Virtual
		struct AsScalar
		{
			using ReturnType_t = ::ID3D10EffectScalarVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectStringVariable* pThis;
		};

		//Virtual
		struct AsVector
		{
			using ReturnType_t = ::ID3D10EffectVectorVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectStringVariable* pThis;
		};

		//Virtual
		struct AsMatrix
		{
			using ReturnType_t = ::ID3D10EffectMatrixVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectStringVariable* pThis;
		};

		//Virtual
		struct AsString
		{
			using ReturnType_t = ::ID3D10EffectStringVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectStringVariable* pThis;
		};

		//Virtual
		struct AsShaderResource
		{
			using ReturnType_t = ::ID3D10EffectShaderResourceVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectStringVariable* pThis;
		};

		//Virtual
		struct AsRenderTargetView
		{
			using ReturnType_t = ::ID3D10EffectRenderTargetViewVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectStringVariable* pThis;
		};

		//Virtual
		struct AsDepthStencilView
		{
			using ReturnType_t = ::ID3D10EffectDepthStencilViewVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectStringVariable* pThis;
		};

		//Virtual
		struct AsConstantBuffer
		{
			using ReturnType_t = ::ID3D10EffectConstantBuffer*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectStringVariable* pThis;
		};

		//Virtual
		struct AsShader
		{
			using ReturnType_t = ::ID3D10EffectShaderVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectStringVariable* pThis;
		};

		//Virtual
		struct AsBlend
		{
			using ReturnType_t = ::ID3D10EffectBlendVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectStringVariable* pThis;
		};

		//Virtual
		struct AsDepthStencil
		{
			using ReturnType_t = ::ID3D10EffectDepthStencilVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectStringVariable* pThis;
		};

		//Virtual
		struct AsRasterizer
		{
			using ReturnType_t = ::ID3D10EffectRasterizerVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectStringVariable* pThis;
		};

		//Virtual
		struct AsSampler
		{
			using ReturnType_t = ::ID3D10EffectSamplerVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectStringVariable* pThis;
		};

		//Virtual
		struct SetRawValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectStringVariable* pThis;
			void* pData;
			::UINT Offset;
			::UINT ByteCount;
		};

		//Virtual
		struct GetRawValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectStringVariable* pThis;
			void* pData;
			::UINT Offset;
			::UINT ByteCount;
		};

		//Virtual
		struct GetString
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectStringVariable* pThis;
			::LPCSTR* ppString;
		};

		//Virtual
		struct GetStringArray
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectStringVariable* pThis;
			::LPCSTR* ppStrings;
			::UINT Offset;
			::UINT Count;
		};

	private:
		 virtual ~ID3D10EffectStringVariable() = 0;
	};

	class ID3D10EffectShaderResourceVariable : ID3D10EffectVariable
	{
	public:
		//Virtual
		struct IsValid
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 1;

			::ID3D10EffectShaderResourceVariable* pThis;
		};

		//Virtual
		struct GetType
		{
			using ReturnType_t = ::ID3D10EffectType*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectShaderResourceVariable* pThis;
		};

		//Virtual
		struct GetDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectShaderResourceVariable* pThis;
			::D3D10_EFFECT_VARIABLE_DESC* pDesc;
		};

		//Virtual
		struct GetAnnotationByIndex
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectShaderResourceVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetAnnotationByName
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectShaderResourceVariable* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetMemberByIndex
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectShaderResourceVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetMemberByName
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectShaderResourceVariable* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetMemberBySemantic
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectShaderResourceVariable* pThis;
			::LPCSTR Semantic;
		};

		//Virtual
		struct GetElement
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectShaderResourceVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetParentConstantBuffer
		{
			using ReturnType_t = ::ID3D10EffectConstantBuffer*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectShaderResourceVariable* pThis;
		};

		//Virtual
		struct AsScalar
		{
			using ReturnType_t = ::ID3D10EffectScalarVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectShaderResourceVariable* pThis;
		};

		//Virtual
		struct AsVector
		{
			using ReturnType_t = ::ID3D10EffectVectorVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectShaderResourceVariable* pThis;
		};

		//Virtual
		struct AsMatrix
		{
			using ReturnType_t = ::ID3D10EffectMatrixVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectShaderResourceVariable* pThis;
		};

		//Virtual
		struct AsString
		{
			using ReturnType_t = ::ID3D10EffectStringVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectShaderResourceVariable* pThis;
		};

		//Virtual
		struct AsShaderResource
		{
			using ReturnType_t = ::ID3D10EffectShaderResourceVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectShaderResourceVariable* pThis;
		};

		//Virtual
		struct AsRenderTargetView
		{
			using ReturnType_t = ::ID3D10EffectRenderTargetViewVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectShaderResourceVariable* pThis;
		};

		//Virtual
		struct AsDepthStencilView
		{
			using ReturnType_t = ::ID3D10EffectDepthStencilViewVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectShaderResourceVariable* pThis;
		};

		//Virtual
		struct AsConstantBuffer
		{
			using ReturnType_t = ::ID3D10EffectConstantBuffer*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectShaderResourceVariable* pThis;
		};

		//Virtual
		struct AsShader
		{
			using ReturnType_t = ::ID3D10EffectShaderVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectShaderResourceVariable* pThis;
		};

		//Virtual
		struct AsBlend
		{
			using ReturnType_t = ::ID3D10EffectBlendVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectShaderResourceVariable* pThis;
		};

		//Virtual
		struct AsDepthStencil
		{
			using ReturnType_t = ::ID3D10EffectDepthStencilVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectShaderResourceVariable* pThis;
		};

		//Virtual
		struct AsRasterizer
		{
			using ReturnType_t = ::ID3D10EffectRasterizerVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectShaderResourceVariable* pThis;
		};

		//Virtual
		struct AsSampler
		{
			using ReturnType_t = ::ID3D10EffectSamplerVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectShaderResourceVariable* pThis;
		};

		//Virtual
		struct SetRawValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectShaderResourceVariable* pThis;
			void* pData;
			::UINT Offset;
			::UINT ByteCount;
		};

		//Virtual
		struct GetRawValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectShaderResourceVariable* pThis;
			void* pData;
			::UINT Offset;
			::UINT ByteCount;
		};

		//Virtual
		struct SetResource
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectShaderResourceVariable* pThis;
			::ID3D10ShaderResourceView* pResource;
		};

		//Virtual
		struct GetResource
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectShaderResourceVariable* pThis;
			::ID3D10ShaderResourceView** ppResource;
		};

		//Virtual
		struct SetResourceArray
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectShaderResourceVariable* pThis;
			::ID3D10ShaderResourceView** ppResources;
			::UINT Offset;
			::UINT Count;
		};

		//Virtual
		struct GetResourceArray
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectShaderResourceVariable* pThis;
			::ID3D10ShaderResourceView** ppResources;
			::UINT Offset;
			::UINT Count;
		};

	private:
		 virtual ~ID3D10EffectShaderResourceVariable() = 0;
	};

	class ID3D10EffectRenderTargetViewVariable : ID3D10EffectVariable
	{
	public:
		//Virtual
		struct IsValid
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 1;

			::ID3D10EffectRenderTargetViewVariable* pThis;
		};

		//Virtual
		struct GetType
		{
			using ReturnType_t = ::ID3D10EffectType*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectRenderTargetViewVariable* pThis;
		};

		//Virtual
		struct GetDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectRenderTargetViewVariable* pThis;
			::D3D10_EFFECT_VARIABLE_DESC* pDesc;
		};

		//Virtual
		struct GetAnnotationByIndex
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectRenderTargetViewVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetAnnotationByName
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectRenderTargetViewVariable* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetMemberByIndex
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectRenderTargetViewVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetMemberByName
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectRenderTargetViewVariable* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetMemberBySemantic
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectRenderTargetViewVariable* pThis;
			::LPCSTR Semantic;
		};

		//Virtual
		struct GetElement
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectRenderTargetViewVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetParentConstantBuffer
		{
			using ReturnType_t = ::ID3D10EffectConstantBuffer*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectRenderTargetViewVariable* pThis;
		};

		//Virtual
		struct AsScalar
		{
			using ReturnType_t = ::ID3D10EffectScalarVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectRenderTargetViewVariable* pThis;
		};

		//Virtual
		struct AsVector
		{
			using ReturnType_t = ::ID3D10EffectVectorVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectRenderTargetViewVariable* pThis;
		};

		//Virtual
		struct AsMatrix
		{
			using ReturnType_t = ::ID3D10EffectMatrixVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectRenderTargetViewVariable* pThis;
		};

		//Virtual
		struct AsString
		{
			using ReturnType_t = ::ID3D10EffectStringVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectRenderTargetViewVariable* pThis;
		};

		//Virtual
		struct AsShaderResource
		{
			using ReturnType_t = ::ID3D10EffectShaderResourceVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectRenderTargetViewVariable* pThis;
		};

		//Virtual
		struct AsRenderTargetView
		{
			using ReturnType_t = ::ID3D10EffectRenderTargetViewVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectRenderTargetViewVariable* pThis;
		};

		//Virtual
		struct AsDepthStencilView
		{
			using ReturnType_t = ::ID3D10EffectDepthStencilViewVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectRenderTargetViewVariable* pThis;
		};

		//Virtual
		struct AsConstantBuffer
		{
			using ReturnType_t = ::ID3D10EffectConstantBuffer*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectRenderTargetViewVariable* pThis;
		};

		//Virtual
		struct AsShader
		{
			using ReturnType_t = ::ID3D10EffectShaderVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectRenderTargetViewVariable* pThis;
		};

		//Virtual
		struct AsBlend
		{
			using ReturnType_t = ::ID3D10EffectBlendVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectRenderTargetViewVariable* pThis;
		};

		//Virtual
		struct AsDepthStencil
		{
			using ReturnType_t = ::ID3D10EffectDepthStencilVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectRenderTargetViewVariable* pThis;
		};

		//Virtual
		struct AsRasterizer
		{
			using ReturnType_t = ::ID3D10EffectRasterizerVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectRenderTargetViewVariable* pThis;
		};

		//Virtual
		struct AsSampler
		{
			using ReturnType_t = ::ID3D10EffectSamplerVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectRenderTargetViewVariable* pThis;
		};

		//Virtual
		struct SetRawValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectRenderTargetViewVariable* pThis;
			void* pData;
			::UINT Offset;
			::UINT ByteCount;
		};

		//Virtual
		struct GetRawValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectRenderTargetViewVariable* pThis;
			void* pData;
			::UINT Offset;
			::UINT ByteCount;
		};

		//Virtual
		struct SetRenderTarget
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectRenderTargetViewVariable* pThis;
			::ID3D10RenderTargetView* pResource;
		};

		//Virtual
		struct GetRenderTarget
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectRenderTargetViewVariable* pThis;
			::ID3D10RenderTargetView** ppResource;
		};

		//Virtual
		struct SetRenderTargetArray
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectRenderTargetViewVariable* pThis;
			::ID3D10RenderTargetView** ppResources;
			::UINT Offset;
			::UINT Count;
		};

		//Virtual
		struct GetRenderTargetArray
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectRenderTargetViewVariable* pThis;
			::ID3D10RenderTargetView** ppResources;
			::UINT Offset;
			::UINT Count;
		};

	private:
		 virtual ~ID3D10EffectRenderTargetViewVariable() = 0;
	};

	class ID3D10EffectDepthStencilViewVariable : ID3D10EffectVariable
	{
	public:
		//Virtual
		struct IsValid
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 1;

			::ID3D10EffectDepthStencilViewVariable* pThis;
		};

		//Virtual
		struct GetType
		{
			using ReturnType_t = ::ID3D10EffectType*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectDepthStencilViewVariable* pThis;
		};

		//Virtual
		struct GetDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectDepthStencilViewVariable* pThis;
			::D3D10_EFFECT_VARIABLE_DESC* pDesc;
		};

		//Virtual
		struct GetAnnotationByIndex
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectDepthStencilViewVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetAnnotationByName
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectDepthStencilViewVariable* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetMemberByIndex
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectDepthStencilViewVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetMemberByName
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectDepthStencilViewVariable* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetMemberBySemantic
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectDepthStencilViewVariable* pThis;
			::LPCSTR Semantic;
		};

		//Virtual
		struct GetElement
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectDepthStencilViewVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetParentConstantBuffer
		{
			using ReturnType_t = ::ID3D10EffectConstantBuffer*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectDepthStencilViewVariable* pThis;
		};

		//Virtual
		struct AsScalar
		{
			using ReturnType_t = ::ID3D10EffectScalarVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectDepthStencilViewVariable* pThis;
		};

		//Virtual
		struct AsVector
		{
			using ReturnType_t = ::ID3D10EffectVectorVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectDepthStencilViewVariable* pThis;
		};

		//Virtual
		struct AsMatrix
		{
			using ReturnType_t = ::ID3D10EffectMatrixVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectDepthStencilViewVariable* pThis;
		};

		//Virtual
		struct AsString
		{
			using ReturnType_t = ::ID3D10EffectStringVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectDepthStencilViewVariable* pThis;
		};

		//Virtual
		struct AsShaderResource
		{
			using ReturnType_t = ::ID3D10EffectShaderResourceVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectDepthStencilViewVariable* pThis;
		};

		//Virtual
		struct AsRenderTargetView
		{
			using ReturnType_t = ::ID3D10EffectRenderTargetViewVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectDepthStencilViewVariable* pThis;
		};

		//Virtual
		struct AsDepthStencilView
		{
			using ReturnType_t = ::ID3D10EffectDepthStencilViewVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectDepthStencilViewVariable* pThis;
		};

		//Virtual
		struct AsConstantBuffer
		{
			using ReturnType_t = ::ID3D10EffectConstantBuffer*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectDepthStencilViewVariable* pThis;
		};

		//Virtual
		struct AsShader
		{
			using ReturnType_t = ::ID3D10EffectShaderVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectDepthStencilViewVariable* pThis;
		};

		//Virtual
		struct AsBlend
		{
			using ReturnType_t = ::ID3D10EffectBlendVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectDepthStencilViewVariable* pThis;
		};

		//Virtual
		struct AsDepthStencil
		{
			using ReturnType_t = ::ID3D10EffectDepthStencilVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectDepthStencilViewVariable* pThis;
		};

		//Virtual
		struct AsRasterizer
		{
			using ReturnType_t = ::ID3D10EffectRasterizerVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectDepthStencilViewVariable* pThis;
		};

		//Virtual
		struct AsSampler
		{
			using ReturnType_t = ::ID3D10EffectSamplerVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectDepthStencilViewVariable* pThis;
		};

		//Virtual
		struct SetRawValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectDepthStencilViewVariable* pThis;
			void* pData;
			::UINT Offset;
			::UINT ByteCount;
		};

		//Virtual
		struct GetRawValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectDepthStencilViewVariable* pThis;
			void* pData;
			::UINT Offset;
			::UINT ByteCount;
		};

		//Virtual
		struct SetDepthStencil
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectDepthStencilViewVariable* pThis;
			::ID3D10DepthStencilView* pResource;
		};

		//Virtual
		struct GetDepthStencil
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectDepthStencilViewVariable* pThis;
			::ID3D10DepthStencilView** ppResource;
		};

		//Virtual
		struct SetDepthStencilArray
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectDepthStencilViewVariable* pThis;
			::ID3D10DepthStencilView** ppResources;
			::UINT Offset;
			::UINT Count;
		};

		//Virtual
		struct GetDepthStencilArray
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectDepthStencilViewVariable* pThis;
			::ID3D10DepthStencilView** ppResources;
			::UINT Offset;
			::UINT Count;
		};

	private:
		 virtual ~ID3D10EffectDepthStencilViewVariable() = 0;
	};

	class ID3D10EffectConstantBuffer : ID3D10EffectVariable
	{
	public:
		//Virtual
		struct GetType
		{
			using ReturnType_t = ::ID3D10EffectType*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectConstantBuffer* pThis;
		};

		//Virtual
		struct GetDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectConstantBuffer* pThis;
			::D3D10_EFFECT_VARIABLE_DESC* pDesc;
		};

		//Virtual
		struct GetAnnotationByIndex
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectConstantBuffer* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetAnnotationByName
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectConstantBuffer* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetMemberByIndex
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectConstantBuffer* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetMemberByName
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectConstantBuffer* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetMemberBySemantic
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectConstantBuffer* pThis;
			::LPCSTR Semantic;
		};

		//Virtual
		struct GetElement
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectConstantBuffer* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetParentConstantBuffer
		{
			using ReturnType_t = ::ID3D10EffectConstantBuffer*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectConstantBuffer* pThis;
		};

		//Virtual
		struct AsScalar
		{
			using ReturnType_t = ::ID3D10EffectScalarVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectConstantBuffer* pThis;
		};

		//Virtual
		struct AsVector
		{
			using ReturnType_t = ::ID3D10EffectVectorVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectConstantBuffer* pThis;
		};

		//Virtual
		struct AsMatrix
		{
			using ReturnType_t = ::ID3D10EffectMatrixVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectConstantBuffer* pThis;
		};

		//Virtual
		struct AsString
		{
			using ReturnType_t = ::ID3D10EffectStringVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectConstantBuffer* pThis;
		};

		//Virtual
		struct AsShaderResource
		{
			using ReturnType_t = ::ID3D10EffectShaderResourceVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectConstantBuffer* pThis;
		};

		//Virtual
		struct AsRenderTargetView
		{
			using ReturnType_t = ::ID3D10EffectRenderTargetViewVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectConstantBuffer* pThis;
		};

		//Virtual
		struct AsDepthStencilView
		{
			using ReturnType_t = ::ID3D10EffectDepthStencilViewVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectConstantBuffer* pThis;
		};

		//Virtual
		struct AsConstantBuffer
		{
			using ReturnType_t = ::ID3D10EffectConstantBuffer*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectConstantBuffer* pThis;
		};

		//Virtual
		struct AsShader
		{
			using ReturnType_t = ::ID3D10EffectShaderVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectConstantBuffer* pThis;
		};

		//Virtual
		struct AsBlend
		{
			using ReturnType_t = ::ID3D10EffectBlendVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectConstantBuffer* pThis;
		};

		//Virtual
		struct AsDepthStencil
		{
			using ReturnType_t = ::ID3D10EffectDepthStencilVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectConstantBuffer* pThis;
		};

		//Virtual
		struct AsRasterizer
		{
			using ReturnType_t = ::ID3D10EffectRasterizerVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectConstantBuffer* pThis;
		};

		//Virtual
		struct AsSampler
		{
			using ReturnType_t = ::ID3D10EffectSamplerVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectConstantBuffer* pThis;
		};

		//Virtual
		struct SetRawValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectConstantBuffer* pThis;
			void* pData;
			::UINT Offset;
			::UINT ByteCount;
		};

		//Virtual
		struct GetRawValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectConstantBuffer* pThis;
			void* pData;
			::UINT Offset;
			::UINT ByteCount;
		};

		//Virtual
		struct SetConstantBuffer
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectConstantBuffer* pThis;
			::ID3D10Buffer* pConstantBuffer;
		};

		//Virtual
		struct GetConstantBuffer
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectConstantBuffer* pThis;
			::ID3D10Buffer** ppConstantBuffer;
		};

		//Virtual
		struct SetTextureBuffer
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectConstantBuffer* pThis;
			::ID3D10ShaderResourceView* pTextureBuffer;
		};

		//Virtual
		struct GetTextureBuffer
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectConstantBuffer* pThis;
			::ID3D10ShaderResourceView** ppTextureBuffer;
		};

	private:
		 virtual ~ID3D10EffectConstantBuffer() = 0;
	};

	class ID3D10EffectShaderVariable : ID3D10EffectVariable
	{
	public:
		//Virtual
		struct GetType
		{
			using ReturnType_t = ::ID3D10EffectType*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectShaderVariable* pThis;
		};

		//Virtual
		struct GetDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectShaderVariable* pThis;
			::D3D10_EFFECT_VARIABLE_DESC* pDesc;
		};

		//Virtual
		struct GetAnnotationByIndex
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectShaderVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetAnnotationByName
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectShaderVariable* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetMemberByIndex
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectShaderVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetMemberByName
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectShaderVariable* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetMemberBySemantic
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectShaderVariable* pThis;
			::LPCSTR Semantic;
		};

		//Virtual
		struct GetElement
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectShaderVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetParentConstantBuffer
		{
			using ReturnType_t = ::ID3D10EffectConstantBuffer*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectShaderVariable* pThis;
		};

		//Virtual
		struct AsScalar
		{
			using ReturnType_t = ::ID3D10EffectScalarVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectShaderVariable* pThis;
		};

		//Virtual
		struct AsVector
		{
			using ReturnType_t = ::ID3D10EffectVectorVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectShaderVariable* pThis;
		};

		//Virtual
		struct AsMatrix
		{
			using ReturnType_t = ::ID3D10EffectMatrixVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectShaderVariable* pThis;
		};

		//Virtual
		struct AsString
		{
			using ReturnType_t = ::ID3D10EffectStringVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectShaderVariable* pThis;
		};

		//Virtual
		struct AsShaderResource
		{
			using ReturnType_t = ::ID3D10EffectShaderResourceVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectShaderVariable* pThis;
		};

		//Virtual
		struct AsRenderTargetView
		{
			using ReturnType_t = ::ID3D10EffectRenderTargetViewVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectShaderVariable* pThis;
		};

		//Virtual
		struct AsDepthStencilView
		{
			using ReturnType_t = ::ID3D10EffectDepthStencilViewVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectShaderVariable* pThis;
		};

		//Virtual
		struct AsConstantBuffer
		{
			using ReturnType_t = ::ID3D10EffectConstantBuffer*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectShaderVariable* pThis;
		};

		//Virtual
		struct AsShader
		{
			using ReturnType_t = ::ID3D10EffectShaderVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectShaderVariable* pThis;
		};

		//Virtual
		struct AsBlend
		{
			using ReturnType_t = ::ID3D10EffectBlendVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectShaderVariable* pThis;
		};

		//Virtual
		struct AsDepthStencil
		{
			using ReturnType_t = ::ID3D10EffectDepthStencilVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectShaderVariable* pThis;
		};

		//Virtual
		struct AsRasterizer
		{
			using ReturnType_t = ::ID3D10EffectRasterizerVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectShaderVariable* pThis;
		};

		//Virtual
		struct AsSampler
		{
			using ReturnType_t = ::ID3D10EffectSamplerVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectShaderVariable* pThis;
		};

		//Virtual
		struct SetRawValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectShaderVariable* pThis;
			void* pData;
			::UINT Offset;
			::UINT ByteCount;
		};

		//Virtual
		struct GetRawValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectShaderVariable* pThis;
			void* pData;
			::UINT Offset;
			::UINT ByteCount;
		};

		//Virtual
		struct GetShaderDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10EffectShaderVariable* pThis;
			::UINT ShaderIndex;
			::D3D10_EFFECT_SHADER_DESC* pDesc;
		};

		//Virtual
		struct GetVertexShader
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10EffectShaderVariable* pThis;
			::UINT ShaderIndex;
			::ID3D10VertexShader** ppVS;
		};

		//Virtual
		struct GetGeometryShader
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10EffectShaderVariable* pThis;
			::UINT ShaderIndex;
			::ID3D10GeometryShader** ppGS;
		};

		//Virtual
		struct GetPixelShader
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10EffectShaderVariable* pThis;
			::UINT ShaderIndex;
			::ID3D10PixelShader** ppPS;
		};

		//Virtual
		struct GetInputSignatureElementDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectShaderVariable* pThis;
			::UINT ShaderIndex;
			::UINT Element;
			::D3D10_SIGNATURE_PARAMETER_DESC* pDesc;
		};

		//Virtual
		struct GetOutputSignatureElementDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectShaderVariable* pThis;
			::UINT ShaderIndex;
			::UINT Element;
			::D3D10_SIGNATURE_PARAMETER_DESC* pDesc;
		};

	private:
		 virtual ~ID3D10EffectShaderVariable() = 0;
	};

	class ID3D10EffectBlendVariable : ID3D10EffectVariable
	{
	public:
		//Virtual
		struct GetType
		{
			using ReturnType_t = ::ID3D10EffectType*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectBlendVariable* pThis;
		};

		//Virtual
		struct GetDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectBlendVariable* pThis;
			::D3D10_EFFECT_VARIABLE_DESC* pDesc;
		};

		//Virtual
		struct GetAnnotationByIndex
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectBlendVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetAnnotationByName
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectBlendVariable* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetMemberByIndex
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectBlendVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetMemberByName
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectBlendVariable* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetMemberBySemantic
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectBlendVariable* pThis;
			::LPCSTR Semantic;
		};

		//Virtual
		struct GetElement
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectBlendVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetParentConstantBuffer
		{
			using ReturnType_t = ::ID3D10EffectConstantBuffer*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectBlendVariable* pThis;
		};

		//Virtual
		struct AsScalar
		{
			using ReturnType_t = ::ID3D10EffectScalarVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectBlendVariable* pThis;
		};

		//Virtual
		struct AsVector
		{
			using ReturnType_t = ::ID3D10EffectVectorVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectBlendVariable* pThis;
		};

		//Virtual
		struct AsMatrix
		{
			using ReturnType_t = ::ID3D10EffectMatrixVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectBlendVariable* pThis;
		};

		//Virtual
		struct AsString
		{
			using ReturnType_t = ::ID3D10EffectStringVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectBlendVariable* pThis;
		};

		//Virtual
		struct AsShaderResource
		{
			using ReturnType_t = ::ID3D10EffectShaderResourceVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectBlendVariable* pThis;
		};

		//Virtual
		struct AsRenderTargetView
		{
			using ReturnType_t = ::ID3D10EffectRenderTargetViewVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectBlendVariable* pThis;
		};

		//Virtual
		struct AsDepthStencilView
		{
			using ReturnType_t = ::ID3D10EffectDepthStencilViewVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectBlendVariable* pThis;
		};

		//Virtual
		struct AsConstantBuffer
		{
			using ReturnType_t = ::ID3D10EffectConstantBuffer*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectBlendVariable* pThis;
		};

		//Virtual
		struct AsShader
		{
			using ReturnType_t = ::ID3D10EffectShaderVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectBlendVariable* pThis;
		};

		//Virtual
		struct AsBlend
		{
			using ReturnType_t = ::ID3D10EffectBlendVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectBlendVariable* pThis;
		};

		//Virtual
		struct AsDepthStencil
		{
			using ReturnType_t = ::ID3D10EffectDepthStencilVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectBlendVariable* pThis;
		};

		//Virtual
		struct AsRasterizer
		{
			using ReturnType_t = ::ID3D10EffectRasterizerVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectBlendVariable* pThis;
		};

		//Virtual
		struct AsSampler
		{
			using ReturnType_t = ::ID3D10EffectSamplerVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectBlendVariable* pThis;
		};

		//Virtual
		struct SetRawValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectBlendVariable* pThis;
			void* pData;
			::UINT Offset;
			::UINT ByteCount;
		};

		//Virtual
		struct GetRawValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectBlendVariable* pThis;
			void* pData;
			::UINT Offset;
			::UINT ByteCount;
		};

		//Virtual
		struct GetBlendState
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10EffectBlendVariable* pThis;
			::UINT Index;
			::ID3D10BlendState** ppBlendState;
		};

		//Virtual
		struct GetBackingStore
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10EffectBlendVariable* pThis;
			::UINT Index;
			::D3D10_BLEND_DESC* pBlendDesc;
		};

	private:
		 virtual ~ID3D10EffectBlendVariable() = 0;
	};

	class ID3D10EffectDepthStencilVariable : ID3D10EffectVariable
	{
	public:
		//Virtual
		struct GetType
		{
			using ReturnType_t = ::ID3D10EffectType*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectDepthStencilVariable* pThis;
		};

		//Virtual
		struct GetDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectDepthStencilVariable* pThis;
			::D3D10_EFFECT_VARIABLE_DESC* pDesc;
		};

		//Virtual
		struct GetAnnotationByIndex
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectDepthStencilVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetAnnotationByName
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectDepthStencilVariable* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetMemberByIndex
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectDepthStencilVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetMemberByName
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectDepthStencilVariable* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetMemberBySemantic
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectDepthStencilVariable* pThis;
			::LPCSTR Semantic;
		};

		//Virtual
		struct GetElement
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectDepthStencilVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetParentConstantBuffer
		{
			using ReturnType_t = ::ID3D10EffectConstantBuffer*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectDepthStencilVariable* pThis;
		};

		//Virtual
		struct AsScalar
		{
			using ReturnType_t = ::ID3D10EffectScalarVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectDepthStencilVariable* pThis;
		};

		//Virtual
		struct AsVector
		{
			using ReturnType_t = ::ID3D10EffectVectorVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectDepthStencilVariable* pThis;
		};

		//Virtual
		struct AsMatrix
		{
			using ReturnType_t = ::ID3D10EffectMatrixVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectDepthStencilVariable* pThis;
		};

		//Virtual
		struct AsString
		{
			using ReturnType_t = ::ID3D10EffectStringVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectDepthStencilVariable* pThis;
		};

		//Virtual
		struct AsShaderResource
		{
			using ReturnType_t = ::ID3D10EffectShaderResourceVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectDepthStencilVariable* pThis;
		};

		//Virtual
		struct AsRenderTargetView
		{
			using ReturnType_t = ::ID3D10EffectRenderTargetViewVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectDepthStencilVariable* pThis;
		};

		//Virtual
		struct AsDepthStencilView
		{
			using ReturnType_t = ::ID3D10EffectDepthStencilViewVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectDepthStencilVariable* pThis;
		};

		//Virtual
		struct AsConstantBuffer
		{
			using ReturnType_t = ::ID3D10EffectConstantBuffer*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectDepthStencilVariable* pThis;
		};

		//Virtual
		struct AsShader
		{
			using ReturnType_t = ::ID3D10EffectShaderVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectDepthStencilVariable* pThis;
		};

		//Virtual
		struct AsBlend
		{
			using ReturnType_t = ::ID3D10EffectBlendVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectDepthStencilVariable* pThis;
		};

		//Virtual
		struct AsDepthStencil
		{
			using ReturnType_t = ::ID3D10EffectDepthStencilVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectDepthStencilVariable* pThis;
		};

		//Virtual
		struct AsRasterizer
		{
			using ReturnType_t = ::ID3D10EffectRasterizerVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectDepthStencilVariable* pThis;
		};

		//Virtual
		struct AsSampler
		{
			using ReturnType_t = ::ID3D10EffectSamplerVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectDepthStencilVariable* pThis;
		};

		//Virtual
		struct SetRawValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectDepthStencilVariable* pThis;
			void* pData;
			::UINT Offset;
			::UINT ByteCount;
		};

		//Virtual
		struct GetRawValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectDepthStencilVariable* pThis;
			void* pData;
			::UINT Offset;
			::UINT ByteCount;
		};

		//Virtual
		struct GetDepthStencilState
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10EffectDepthStencilVariable* pThis;
			::UINT Index;
			::ID3D10DepthStencilState** ppDepthStencilState;
		};

		//Virtual
		struct GetBackingStore
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10EffectDepthStencilVariable* pThis;
			::UINT Index;
			::D3D10_DEPTH_STENCIL_DESC* pDepthStencilDesc;
		};

	private:
		 virtual ~ID3D10EffectDepthStencilVariable() = 0;
	};

	class ID3D10EffectRasterizerVariable : ID3D10EffectVariable
	{
	public:
		//Virtual
		struct GetType
		{
			using ReturnType_t = ::ID3D10EffectType*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectRasterizerVariable* pThis;
		};

		//Virtual
		struct GetDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectRasterizerVariable* pThis;
			::D3D10_EFFECT_VARIABLE_DESC* pDesc;
		};

		//Virtual
		struct GetAnnotationByIndex
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectRasterizerVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetAnnotationByName
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectRasterizerVariable* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetMemberByIndex
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectRasterizerVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetMemberByName
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectRasterizerVariable* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetMemberBySemantic
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectRasterizerVariable* pThis;
			::LPCSTR Semantic;
		};

		//Virtual
		struct GetElement
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectRasterizerVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetParentConstantBuffer
		{
			using ReturnType_t = ::ID3D10EffectConstantBuffer*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectRasterizerVariable* pThis;
		};

		//Virtual
		struct AsScalar
		{
			using ReturnType_t = ::ID3D10EffectScalarVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectRasterizerVariable* pThis;
		};

		//Virtual
		struct AsVector
		{
			using ReturnType_t = ::ID3D10EffectVectorVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectRasterizerVariable* pThis;
		};

		//Virtual
		struct AsMatrix
		{
			using ReturnType_t = ::ID3D10EffectMatrixVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectRasterizerVariable* pThis;
		};

		//Virtual
		struct AsString
		{
			using ReturnType_t = ::ID3D10EffectStringVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectRasterizerVariable* pThis;
		};

		//Virtual
		struct AsShaderResource
		{
			using ReturnType_t = ::ID3D10EffectShaderResourceVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectRasterizerVariable* pThis;
		};

		//Virtual
		struct AsRenderTargetView
		{
			using ReturnType_t = ::ID3D10EffectRenderTargetViewVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectRasterizerVariable* pThis;
		};

		//Virtual
		struct AsDepthStencilView
		{
			using ReturnType_t = ::ID3D10EffectDepthStencilViewVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectRasterizerVariable* pThis;
		};

		//Virtual
		struct AsConstantBuffer
		{
			using ReturnType_t = ::ID3D10EffectConstantBuffer*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectRasterizerVariable* pThis;
		};

		//Virtual
		struct AsShader
		{
			using ReturnType_t = ::ID3D10EffectShaderVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectRasterizerVariable* pThis;
		};

		//Virtual
		struct AsBlend
		{
			using ReturnType_t = ::ID3D10EffectBlendVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectRasterizerVariable* pThis;
		};

		//Virtual
		struct AsDepthStencil
		{
			using ReturnType_t = ::ID3D10EffectDepthStencilVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectRasterizerVariable* pThis;
		};

		//Virtual
		struct AsRasterizer
		{
			using ReturnType_t = ::ID3D10EffectRasterizerVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectRasterizerVariable* pThis;
		};

		//Virtual
		struct AsSampler
		{
			using ReturnType_t = ::ID3D10EffectSamplerVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectRasterizerVariable* pThis;
		};

		//Virtual
		struct SetRawValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectRasterizerVariable* pThis;
			void* pData;
			::UINT Offset;
			::UINT ByteCount;
		};

		//Virtual
		struct GetRawValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectRasterizerVariable* pThis;
			void* pData;
			::UINT Offset;
			::UINT ByteCount;
		};

		//Virtual
		struct GetRasterizerState
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10EffectRasterizerVariable* pThis;
			::UINT Index;
			::ID3D10RasterizerState** ppRasterizerState;
		};

		//Virtual
		struct GetBackingStore
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10EffectRasterizerVariable* pThis;
			::UINT Index;
			::D3D10_RASTERIZER_DESC* pRasterizerDesc;
		};

	private:
		 virtual ~ID3D10EffectRasterizerVariable() = 0;
	};

	class ID3D10EffectSamplerVariable : ID3D10EffectVariable
	{
	public:
		//Virtual
		struct GetType
		{
			using ReturnType_t = ::ID3D10EffectType*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectSamplerVariable* pThis;
		};

		//Virtual
		struct GetDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10EffectSamplerVariable* pThis;
			::D3D10_EFFECT_VARIABLE_DESC* pDesc;
		};

		//Virtual
		struct GetAnnotationByIndex
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectSamplerVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetAnnotationByName
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectSamplerVariable* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetMemberByIndex
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectSamplerVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetMemberByName
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectSamplerVariable* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetMemberBySemantic
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectSamplerVariable* pThis;
			::LPCSTR Semantic;
		};

		//Virtual
		struct GetElement
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10EffectSamplerVariable* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetParentConstantBuffer
		{
			using ReturnType_t = ::ID3D10EffectConstantBuffer*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectSamplerVariable* pThis;
		};

		//Virtual
		struct AsScalar
		{
			using ReturnType_t = ::ID3D10EffectScalarVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectSamplerVariable* pThis;
		};

		//Virtual
		struct AsVector
		{
			using ReturnType_t = ::ID3D10EffectVectorVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectSamplerVariable* pThis;
		};

		//Virtual
		struct AsMatrix
		{
			using ReturnType_t = ::ID3D10EffectMatrixVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectSamplerVariable* pThis;
		};

		//Virtual
		struct AsString
		{
			using ReturnType_t = ::ID3D10EffectStringVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectSamplerVariable* pThis;
		};

		//Virtual
		struct AsShaderResource
		{
			using ReturnType_t = ::ID3D10EffectShaderResourceVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectSamplerVariable* pThis;
		};

		//Virtual
		struct AsRenderTargetView
		{
			using ReturnType_t = ::ID3D10EffectRenderTargetViewVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectSamplerVariable* pThis;
		};

		//Virtual
		struct AsDepthStencilView
		{
			using ReturnType_t = ::ID3D10EffectDepthStencilViewVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectSamplerVariable* pThis;
		};

		//Virtual
		struct AsConstantBuffer
		{
			using ReturnType_t = ::ID3D10EffectConstantBuffer*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectSamplerVariable* pThis;
		};

		//Virtual
		struct AsShader
		{
			using ReturnType_t = ::ID3D10EffectShaderVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectSamplerVariable* pThis;
		};

		//Virtual
		struct AsBlend
		{
			using ReturnType_t = ::ID3D10EffectBlendVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectSamplerVariable* pThis;
		};

		//Virtual
		struct AsDepthStencil
		{
			using ReturnType_t = ::ID3D10EffectDepthStencilVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectSamplerVariable* pThis;
		};

		//Virtual
		struct AsRasterizer
		{
			using ReturnType_t = ::ID3D10EffectRasterizerVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectSamplerVariable* pThis;
		};

		//Virtual
		struct AsSampler
		{
			using ReturnType_t = ::ID3D10EffectSamplerVariable*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectSamplerVariable* pThis;
		};

		//Virtual
		struct SetRawValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectSamplerVariable* pThis;
			void* pData;
			::UINT Offset;
			::UINT ByteCount;
		};

		//Virtual
		struct GetRawValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10EffectSamplerVariable* pThis;
			void* pData;
			::UINT Offset;
			::UINT ByteCount;
		};

		//Virtual
		struct GetSampler
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10EffectSamplerVariable* pThis;
			::UINT Index;
			::ID3D10SamplerState** ppSampler;
		};

		//Virtual
		struct GetBackingStore
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10EffectSamplerVariable* pThis;
			::UINT Index;
			::D3D10_SAMPLER_DESC* pSamplerDesc;
		};

	private:
		 virtual ~ID3D10EffectSamplerVariable() = 0;
	};

	class ID3D10Effect : IUnknown
	{
	public:
		//Virtual
		struct QueryInterface
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10Effect* pThis;
			const ::IID& iid;
			::LPVOID* ppv;
		};

		//Virtual
		struct AddRef
		{
			using ReturnType_t = ::ULONG;
			static constexpr size_t Argc = 1;

			::ID3D10Effect* pThis;
		};

		//Virtual
		struct Release
		{
			using ReturnType_t = ::ULONG;
			static constexpr size_t Argc = 1;

			::ID3D10Effect* pThis;
		};

		//Virtual
		struct IsValid
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 1;

			::ID3D10Effect* pThis;
		};

		//Virtual
		struct IsPool
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 1;

			::ID3D10Effect* pThis;
		};

		//Virtual
		struct GetDevice
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10Effect* pThis;
			::ID3D10Device** ppDevice;
		};

		//Virtual
		struct GetDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10Effect* pThis;
			::D3D10_EFFECT_DESC* pDesc;
		};

		//Virtual
		struct GetConstantBufferByIndex
		{
			using ReturnType_t = ::ID3D10EffectConstantBuffer*;
			static constexpr size_t Argc = 2;

			::ID3D10Effect* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetConstantBufferByName
		{
			using ReturnType_t = ::ID3D10EffectConstantBuffer*;
			static constexpr size_t Argc = 2;

			::ID3D10Effect* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetVariableByIndex
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10Effect* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetVariableByName
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10Effect* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetVariableBySemantic
		{
			using ReturnType_t = ::ID3D10EffectVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10Effect* pThis;
			::LPCSTR Semantic;
		};

		//Virtual
		struct GetTechniqueByIndex
		{
			using ReturnType_t = ::ID3D10EffectTechnique*;
			static constexpr size_t Argc = 2;

			::ID3D10Effect* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetTechniqueByName
		{
			using ReturnType_t = ::ID3D10EffectTechnique*;
			static constexpr size_t Argc = 2;

			::ID3D10Effect* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct Optimize
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ID3D10Effect* pThis;
		};

		//Virtual
		struct IsOptimized
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 1;

			::ID3D10Effect* pThis;
		};

	private:
		 virtual ~ID3D10Effect() = 0;
	};

	class ID3D10EffectPool : IUnknown
	{
	public:
		//Virtual
		struct QueryInterface
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10EffectPool* pThis;
			const ::IID& iid;
			::LPVOID* ppv;
		};

		//Virtual
		struct AddRef
		{
			using ReturnType_t = ::ULONG;
			static constexpr size_t Argc = 1;

			::ID3D10EffectPool* pThis;
		};

		//Virtual
		struct Release
		{
			using ReturnType_t = ::ULONG;
			static constexpr size_t Argc = 1;

			::ID3D10EffectPool* pThis;
		};

		//Virtual
		struct AsEffect
		{
			using ReturnType_t = ::ID3D10Effect*;
			static constexpr size_t Argc = 1;

			::ID3D10EffectPool* pThis;
		};

	private:
		 virtual ~ID3D10EffectPool() = 0;
	};

	class ID3D10BlendState1 : ID3D10BlendState
	{
	public:
		//Virtual
		struct GetDesc1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10BlendState1* pThis;
			::D3D10_BLEND_DESC1* pDesc;
		};

	private:
		 virtual ~ID3D10BlendState1() = 0;
	};

	class ID3D10ShaderResourceView1 : ID3D10ShaderResourceView
	{
	public:
		//Virtual
		struct GetDesc1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D10ShaderResourceView1* pThis;
			::D3D10_SHADER_RESOURCE_VIEW_DESC1* pDesc;
		};

	private:
		 virtual ~ID3D10ShaderResourceView1() = 0;
	};

	class ID3D10Device1 : ID3D10Device
	{
	public:
		//Virtual
		struct CreateShaderResourceView1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D10Device1* pThis;
			::ID3D10Resource* pResource;
			const ::D3D10_SHADER_RESOURCE_VIEW_DESC1* pDesc;
			::ID3D10ShaderResourceView1** ppSRView;
		};

		//Virtual
		struct CreateBlendState1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10Device1* pThis;
			const ::D3D10_BLEND_DESC1* pBlendStateDesc;
			::ID3D10BlendState1** ppBlendState;
		};

		//Virtual
		struct GetFeatureLevel
		{
			using ReturnType_t = ::D3D10_FEATURE_LEVEL1;
			static constexpr size_t Argc = 1;

			::ID3D10Device1* pThis;
		};

	private:
		 virtual ~ID3D10Device1() = 0;
	};

	class ID3D10ShaderReflection1 : IUnknown
	{
	public:
		//Virtual
		struct QueryInterface
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10ShaderReflection1* pThis;
			const ::IID& iid;
			::LPVOID* ppv;
		};

		//Virtual
		struct AddRef
		{
			using ReturnType_t = ::ULONG;
			static constexpr size_t Argc = 1;

			::ID3D10ShaderReflection1* pThis;
		};

		//Virtual
		struct Release
		{
			using ReturnType_t = ::ULONG;
			static constexpr size_t Argc = 1;

			::ID3D10ShaderReflection1* pThis;
		};

		//Virtual
		struct GetDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10ShaderReflection1* pThis;
			::D3D10_SHADER_DESC* pDesc;
		};

		//Virtual
		struct GetConstantBufferByIndex
		{
			using ReturnType_t = ::ID3D10ShaderReflectionConstantBuffer*;
			static constexpr size_t Argc = 2;

			::ID3D10ShaderReflection1* pThis;
			::UINT Index;
		};

		//Virtual
		struct GetConstantBufferByName
		{
			using ReturnType_t = ::ID3D10ShaderReflectionConstantBuffer*;
			static constexpr size_t Argc = 2;

			::ID3D10ShaderReflection1* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetResourceBindingDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10ShaderReflection1* pThis;
			::UINT ResourceIndex;
			::D3D10_SHADER_INPUT_BIND_DESC* pDesc;
		};

		//Virtual
		struct GetInputParameterDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10ShaderReflection1* pThis;
			::UINT ParameterIndex;
			::D3D10_SIGNATURE_PARAMETER_DESC* pDesc;
		};

		//Virtual
		struct GetOutputParameterDesc
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10ShaderReflection1* pThis;
			::UINT ParameterIndex;
			::D3D10_SIGNATURE_PARAMETER_DESC* pDesc;
		};

		//Virtual
		struct GetVariableByName
		{
			using ReturnType_t = ::ID3D10ShaderReflectionVariable*;
			static constexpr size_t Argc = 2;

			::ID3D10ShaderReflection1* pThis;
			::LPCSTR Name;
		};

		//Virtual
		struct GetResourceBindingDescByName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D10ShaderReflection1* pThis;
			::LPCSTR Name;
			::D3D10_SHADER_INPUT_BIND_DESC* pDesc;
		};

		//Virtual
		struct GetMovInstructionCount
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10ShaderReflection1* pThis;
			::UINT* pCount;
		};

		//Virtual
		struct GetMovcInstructionCount
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10ShaderReflection1* pThis;
			::UINT* pCount;
		};

		//Virtual
		struct GetConversionInstructionCount
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10ShaderReflection1* pThis;
			::UINT* pCount;
		};

		//Virtual
		struct GetBitwiseInstructionCount
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10ShaderReflection1* pThis;
			::UINT* pCount;
		};

		//Virtual
		struct GetGSInputPrimitive
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10ShaderReflection1* pThis;
			::D3D10_PRIMITIVE* pPrim;
		};

		//Virtual
		struct IsLevel9Shader
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10ShaderReflection1* pThis;
			::BOOL* pbLevel9Shader;
		};

		//Virtual
		struct IsSampleFrequencyShader
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D10ShaderReflection1* pThis;
			::BOOL* pbSampleFrequency;
		};

	private:
		 virtual ~ID3D10ShaderReflection1() = 0;
	};

	class ID3D11BlendState1 : ID3D11BlendState
	{
	public:
		//Virtual
		struct GetDesc1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11BlendState1* pThis;
			::D3D11_BLEND_DESC1* pDesc;
		};

	private:
		 virtual ~ID3D11BlendState1() = 0;
	};

	class ID3D11RasterizerState1 : ID3D11RasterizerState
	{
	public:
		//Virtual
		struct GetDesc1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11RasterizerState1* pThis;
			::D3D11_RASTERIZER_DESC1* pDesc;
		};

	private:
		 virtual ~ID3D11RasterizerState1() = 0;
	};

	class ID3D11DeviceContext1 : ID3D11DeviceContext
	{
	public:
		//Virtual
		struct CopySubresourceRegion1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 10;

			::ID3D11DeviceContext1* pThis;
			::ID3D11Resource* pDstResource;
			::UINT DstSubresource;
			::UINT DstX;
			::UINT DstY;
			::UINT DstZ;
			::ID3D11Resource* pSrcResource;
			::UINT SrcSubresource;
			const ::D3D11_BOX* pSrcBox;
			::UINT CopyFlags;
		};

		//Virtual
		struct UpdateSubresource1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 8;

			::ID3D11DeviceContext1* pThis;
			::ID3D11Resource* pDstResource;
			::UINT DstSubresource;
			const ::D3D11_BOX* pDstBox;
			const void* pSrcData;
			::UINT SrcRowPitch;
			::UINT SrcDepthPitch;
			::UINT CopyFlags;
		};

		//Virtual
		struct DiscardResource
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11DeviceContext1* pThis;
			::ID3D11Resource* pResource;
		};

		//Virtual
		struct DiscardView
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11DeviceContext1* pThis;
			::ID3D11View* pResourceView;
		};

		//Virtual
		struct VSSetConstantBuffers1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D11DeviceContext1* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D11Buffer*const* ppConstantBuffers;
			const ::UINT* pFirstConstant;
			const ::UINT* pNumConstants;
		};

		//Virtual
		struct HSSetConstantBuffers1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D11DeviceContext1* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D11Buffer*const* ppConstantBuffers;
			const ::UINT* pFirstConstant;
			const ::UINT* pNumConstants;
		};

		//Virtual
		struct DSSetConstantBuffers1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D11DeviceContext1* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D11Buffer*const* ppConstantBuffers;
			const ::UINT* pFirstConstant;
			const ::UINT* pNumConstants;
		};

		//Virtual
		struct GSSetConstantBuffers1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D11DeviceContext1* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D11Buffer*const* ppConstantBuffers;
			const ::UINT* pFirstConstant;
			const ::UINT* pNumConstants;
		};

		//Virtual
		struct PSSetConstantBuffers1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D11DeviceContext1* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D11Buffer*const* ppConstantBuffers;
			const ::UINT* pFirstConstant;
			const ::UINT* pNumConstants;
		};

		//Virtual
		struct CSSetConstantBuffers1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D11DeviceContext1* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D11Buffer*const* ppConstantBuffers;
			const ::UINT* pFirstConstant;
			const ::UINT* pNumConstants;
		};

		//Virtual
		struct VSGetConstantBuffers1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D11DeviceContext1* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D11Buffer** ppConstantBuffers;
			::UINT* pFirstConstant;
			::UINT* pNumConstants;
		};

		//Virtual
		struct HSGetConstantBuffers1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D11DeviceContext1* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D11Buffer** ppConstantBuffers;
			::UINT* pFirstConstant;
			::UINT* pNumConstants;
		};

		//Virtual
		struct DSGetConstantBuffers1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D11DeviceContext1* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D11Buffer** ppConstantBuffers;
			::UINT* pFirstConstant;
			::UINT* pNumConstants;
		};

		//Virtual
		struct GSGetConstantBuffers1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D11DeviceContext1* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D11Buffer** ppConstantBuffers;
			::UINT* pFirstConstant;
			::UINT* pNumConstants;
		};

		//Virtual
		struct PSGetConstantBuffers1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D11DeviceContext1* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D11Buffer** ppConstantBuffers;
			::UINT* pFirstConstant;
			::UINT* pNumConstants;
		};

		//Virtual
		struct CSGetConstantBuffers1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D11DeviceContext1* pThis;
			::UINT StartSlot;
			::UINT NumBuffers;
			::ID3D11Buffer** ppConstantBuffers;
			::UINT* pFirstConstant;
			::UINT* pNumConstants;
		};

		//Virtual
		struct SwapDeviceContextState
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11DeviceContext1* pThis;
			::ID3DDeviceContextState* pState;
			::ID3DDeviceContextState** ppPreviousState;
		};

		//Virtual
		struct ClearView
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 5;

			::ID3D11DeviceContext1* pThis;
			::ID3D11View* pView;
			const ::FLOAT Color[4];
			const ::D3D11_RECT* pRect;
			::UINT NumRects;
		};

		//Virtual
		struct DiscardView1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11DeviceContext1* pThis;
			::ID3D11View* pResourceView;
			const ::D3D11_RECT* pRects;
			::UINT NumRects;
		};

	private:
		 virtual ~ID3D11DeviceContext1() = 0;
	};

	class ID3D11VideoContext1 : ID3D11VideoContext
	{
	public:
		//Virtual
		struct SubmitDecoderBuffers1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11VideoContext1* pThis;
			::ID3D11VideoDecoder* pDecoder;
			::UINT NumBuffers;
			const ::D3D11_VIDEO_DECODER_BUFFER_DESC1* pBufferDesc;
		};

		//Virtual
		struct GetDataForNewHardwareKey
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D11VideoContext1* pThis;
			::ID3D11CryptoSession* pCryptoSession;
			::UINT PrivateInputSize;
			const void* pPrivatInputData;
			::UINT64* pPrivateOutputData;
		};

		//Virtual
		struct CheckCryptoSessionStatus
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11VideoContext1* pThis;
			::ID3D11CryptoSession* pCryptoSession;
			::D3D11_CRYPTO_SESSION_STATUS* pStatus;
		};

		//Virtual
		struct DecoderEnableDownsampling
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D11VideoContext1* pThis;
			::ID3D11VideoDecoder* pDecoder;
			::DXGI_COLOR_SPACE_TYPE InputColorSpace;
			const ::D3D11_VIDEO_SAMPLE_DESC* pOutputDesc;
			::UINT ReferenceFrameCount;
		};

		//Virtual
		struct DecoderUpdateDownsampling
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11VideoContext1* pThis;
			::ID3D11VideoDecoder* pDecoder;
			const ::D3D11_VIDEO_SAMPLE_DESC* pOutputDesc;
		};

		//Virtual
		struct VideoProcessorSetOutputColorSpace1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11VideoContext1* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::DXGI_COLOR_SPACE_TYPE ColorSpace;
		};

		//Virtual
		struct VideoProcessorSetOutputShaderUsage
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11VideoContext1* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::BOOL ShaderUsage;
		};

		//Virtual
		struct VideoProcessorGetOutputColorSpace1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11VideoContext1* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::DXGI_COLOR_SPACE_TYPE* pColorSpace;
		};

		//Virtual
		struct VideoProcessorGetOutputShaderUsage
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11VideoContext1* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::BOOL* pShaderUsage;
		};

		//Virtual
		struct VideoProcessorSetStreamColorSpace1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11VideoContext1* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			::DXGI_COLOR_SPACE_TYPE ColorSpace;
		};

		//Virtual
		struct VideoProcessorSetStreamMirror
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D11VideoContext1* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			::BOOL Enable;
			::BOOL FlipHorizontal;
			::BOOL FlipVertical;
		};

		//Virtual
		struct VideoProcessorGetStreamColorSpace1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D11VideoContext1* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			::DXGI_COLOR_SPACE_TYPE* pColorSpace;
		};

		//Virtual
		struct VideoProcessorGetStreamMirror
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D11VideoContext1* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			::BOOL* pEnable;
			::BOOL* pFlipHorizontal;
			::BOOL* pFlipVertical;
		};

		//Virtual
		struct VideoProcessorGetBehaviorHints
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 8;

			::ID3D11VideoContext1* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT OutputWidth;
			::UINT OutputHeight;
			::DXGI_FORMAT OutputFormat;
			::UINT StreamCount;
			const ::D3D11_VIDEO_PROCESSOR_STREAM_BEHAVIOR_HINT* pStreams;
			::UINT* pBehaviorHints;
		};

	private:
		 virtual ~ID3D11VideoContext1() = 0;
	};

	class ID3D11VideoDevice1 : ID3D11VideoDevice
	{
	public:
		//Virtual
		struct GetCryptoSessionPrivateDataSize
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::ID3D11VideoDevice1* pThis;
			const ::GUID* pCryptoType;
			const ::GUID* pDecoderProfile;
			const ::GUID* pKeyExchangeType;
			::UINT* pPrivateInputSize;
			::UINT* pPrivateOutputSize;
		};

		//Virtual
		struct GetVideoDecoderCaps
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 8;

			::ID3D11VideoDevice1* pThis;
			const ::GUID* pDecoderProfile;
			::UINT SampleWidth;
			::UINT SampleHeight;
			const ::DXGI_RATIONAL* pFrameRate;
			::UINT BitRate;
			const ::GUID* pCryptoType;
			::UINT* pDecoderCaps;
		};

		//Virtual
		struct CheckVideoDecoderDownsampling
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 8;

			::ID3D11VideoDevice1* pThis;
			const ::D3D11_VIDEO_DECODER_DESC* pInputDesc;
			::DXGI_COLOR_SPACE_TYPE InputColorSpace;
			const ::D3D11_VIDEO_DECODER_CONFIG* pInputConfig;
			const ::DXGI_RATIONAL* pFrameRate;
			const ::D3D11_VIDEO_SAMPLE_DESC* pOutputDesc;
			::BOOL* pSupported;
			::BOOL* pRealTimeHint;
		};

		//Virtual
		struct RecommendVideoDecoderDownsampleParameters
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::ID3D11VideoDevice1* pThis;
			const ::D3D11_VIDEO_DECODER_DESC* pInputDesc;
			::DXGI_COLOR_SPACE_TYPE InputColorSpace;
			const ::D3D11_VIDEO_DECODER_CONFIG* pInputConfig;
			const ::DXGI_RATIONAL* pFrameRate;
			::D3D11_VIDEO_SAMPLE_DESC* pRecommendedOutputDesc;
		};

	private:
		 virtual ~ID3D11VideoDevice1() = 0;
	};

	class ID3D11VideoProcessorEnumerator1 : ID3D11VideoProcessorEnumerator
	{
	public:
		//Virtual
		struct CheckVideoProcessorFormatConversion
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::ID3D11VideoProcessorEnumerator1* pThis;
			::DXGI_FORMAT InputFormat;
			::DXGI_COLOR_SPACE_TYPE InputColorSpace;
			::DXGI_FORMAT OutputFormat;
			::DXGI_COLOR_SPACE_TYPE OutputColorSpace;
			::BOOL* pSupported;
		};

	private:
		 virtual ~ID3D11VideoProcessorEnumerator1() = 0;
	};

	class ID3D11Device1 : ID3D11Device
	{
	public:
		//Virtual
		struct GetImmediateContext1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11Device1* pThis;
			::ID3D11DeviceContext1** ppImmediateContext;
		};

		//Virtual
		struct CreateDeferredContext1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11Device1* pThis;
			::UINT ContextFlags;
			::ID3D11DeviceContext1** ppDeferredContext;
		};

		//Virtual
		struct CreateBlendState1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11Device1* pThis;
			const ::D3D11_BLEND_DESC1* pBlendStateDesc;
			::ID3D11BlendState1** ppBlendState;
		};

		//Virtual
		struct CreateRasterizerState1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11Device1* pThis;
			const ::D3D11_RASTERIZER_DESC1* pRasterizerDesc;
			::ID3D11RasterizerState1** ppRasterizerState;
		};

		//Virtual
		struct CreateDeviceContextState
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 8;

			::ID3D11Device1* pThis;
			::UINT Flags;
			const ::D3D_FEATURE_LEVEL* pFeatureLevels;
			::UINT FeatureLevels;
			::UINT SDKVersion;
			const ::IID& EmulatedInterface;
			::D3D_FEATURE_LEVEL* pChosenFeatureLevel;
			::ID3DDeviceContextState** ppContextState;
		};

		//Virtual
		struct OpenSharedResource1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11Device1* pThis;
			::HANDLE hResource;
			const ::IID& returnedInterface;
			void** ppResource;
		};

		//Virtual
		struct OpenSharedResourceByName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D11Device1* pThis;
			::LPCWSTR lpName;
			::DWORD dwDesiredAccess;
			const ::IID& returnedInterface;
			void** ppResource;
		};

	private:
		 virtual ~ID3D11Device1() = 0;
	};

	class ID3DUserDefinedAnnotation : IUnknown
	{
	public:
		//Virtual
		struct BeginEvent
		{
			using ReturnType_t = ::INT;
			static constexpr size_t Argc = 2;

			::ID3DUserDefinedAnnotation* pThis;
			::LPCWSTR Name;
		};

		//Virtual
		struct EndEvent
		{
			using ReturnType_t = ::INT;
			static constexpr size_t Argc = 1;

			::ID3DUserDefinedAnnotation* pThis;
		};

		//Virtual
		struct SetMarker
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3DUserDefinedAnnotation* pThis;
			::LPCWSTR Name;
		};

		//Virtual
		struct GetStatus
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 1;

			::ID3DUserDefinedAnnotation* pThis;
		};

	private:
		 virtual ~ID3DUserDefinedAnnotation() = 0;
	};

	class ID3D11DeviceContext2 : ID3D11DeviceContext1
	{
	public:
		//Virtual
		struct UpdateTileMappings
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 11;

			::ID3D11DeviceContext2* pThis;
			::ID3D11Resource* pTiledResource;
			::UINT NumTiledResourceRegions;
			const ::D3D11_TILED_RESOURCE_COORDINATE* pTiledResourceRegionStartCoordinates;
			const ::D3D11_TILE_REGION_SIZE* pTiledResourceRegionSizes;
			::ID3D11Buffer* pTilePool;
			::UINT NumRanges;
			const ::UINT* pRangeFlags;
			const ::UINT* pTilePoolStartOffsets;
			const ::UINT* pRangeTileCounts;
			::UINT Flags;
		};

		//Virtual
		struct CopyTileMappings
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 7;

			::ID3D11DeviceContext2* pThis;
			::ID3D11Resource* pDestTiledResource;
			const ::D3D11_TILED_RESOURCE_COORDINATE* pDestRegionStartCoordinate;
			::ID3D11Resource* pSourceTiledResource;
			const ::D3D11_TILED_RESOURCE_COORDINATE* pSourceRegionStartCoordinate;
			const ::D3D11_TILE_REGION_SIZE* pTileRegionSize;
			::UINT Flags;
		};

		//Virtual
		struct CopyTiles
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 7;

			::ID3D11DeviceContext2* pThis;
			::ID3D11Resource* pTiledResource;
			const ::D3D11_TILED_RESOURCE_COORDINATE* pTileRegionStartCoordinate;
			const ::D3D11_TILE_REGION_SIZE* pTileRegionSize;
			::ID3D11Buffer* pBuffer;
			::UINT64 BufferStartOffsetInBytes;
			::UINT Flags;
		};

		//Virtual
		struct UpdateTiles
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D11DeviceContext2* pThis;
			::ID3D11Resource* pDestTiledResource;
			const ::D3D11_TILED_RESOURCE_COORDINATE* pDestTileRegionStartCoordinate;
			const ::D3D11_TILE_REGION_SIZE* pDestTileRegionSize;
			const void* pSourceTileData;
			::UINT Flags;
		};

		//Virtual
		struct ResizeTilePool
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11DeviceContext2* pThis;
			::ID3D11Buffer* pTilePool;
			::UINT64 NewSizeInBytes;
		};

		//Virtual
		struct TiledResourceBarrier
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11DeviceContext2* pThis;
			::ID3D11DeviceChild* pTiledResourceOrViewAccessBeforeBarrier;
			::ID3D11DeviceChild* pTiledResourceOrViewAccessAfterBarrier;
		};

		//Virtual
		struct IsAnnotationEnabled
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 1;

			::ID3D11DeviceContext2* pThis;
		};

		//Virtual
		struct SetMarkerInt
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11DeviceContext2* pThis;
			::LPCWSTR pLabel;
			::INT Data;
		};

		//Virtual
		struct BeginEventInt
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11DeviceContext2* pThis;
			::LPCWSTR pLabel;
			::INT Data;
		};

		//Virtual
		struct EndEvent
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D11DeviceContext2* pThis;
		};

	private:
		 virtual ~ID3D11DeviceContext2() = 0;
	};

	class ID3D11Device2 : ID3D11Device1
	{
	public:
		//Virtual
		struct GetImmediateContext2
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11Device2* pThis;
			::ID3D11DeviceContext2** ppImmediateContext;
		};

		//Virtual
		struct CreateDeferredContext2
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11Device2* pThis;
			::UINT ContextFlags;
			::ID3D11DeviceContext2** ppDeferredContext;
		};

		//Virtual
		struct GetResourceTiling
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 8;

			::ID3D11Device2* pThis;
			::ID3D11Resource* pTiledResource;
			::UINT* pNumTilesForEntireResource;
			::D3D11_PACKED_MIP_DESC* pPackedMipDesc;
			::D3D11_TILE_SHAPE* pStandardTileShapeForNonPackedMips;
			::UINT* pNumSubresourceTilings;
			::UINT FirstSubresourceTilingToGet;
			::D3D11_SUBRESOURCE_TILING* pSubresourceTilingsForNonPackedMips;
		};

		//Virtual
		struct CheckMultisampleQualityLevels1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D11Device2* pThis;
			::DXGI_FORMAT Format;
			::UINT SampleCount;
			::UINT Flags;
			::UINT* pNumQualityLevels;
		};

	private:
		 virtual ~ID3D11Device2() = 0;
	};

	class ID3D11Texture2D1 : ID3D11Texture2D
	{
	public:
		//Virtual
		struct GetDesc1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11Texture2D1* pThis;
			::D3D11_TEXTURE2D_DESC1* pDesc;
		};

	private:
		 virtual ~ID3D11Texture2D1() = 0;
	};

	class ID3D11Texture3D1 : ID3D11Texture3D
	{
	public:
		//Virtual
		struct GetDesc1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11Texture3D1* pThis;
			::D3D11_TEXTURE3D_DESC1* pDesc;
		};

	private:
		 virtual ~ID3D11Texture3D1() = 0;
	};

	class ID3D11RasterizerState2 : ID3D11RasterizerState1
	{
	public:
		//Virtual
		struct GetDesc2
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11RasterizerState2* pThis;
			::D3D11_RASTERIZER_DESC2* pDesc;
		};

	private:
		 virtual ~ID3D11RasterizerState2() = 0;
	};

	class ID3D11ShaderResourceView1 : ID3D11ShaderResourceView
	{
	public:
		//Virtual
		struct GetDesc1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11ShaderResourceView1* pThis;
			::D3D11_SHADER_RESOURCE_VIEW_DESC1* pDesc1;
		};

	private:
		 virtual ~ID3D11ShaderResourceView1() = 0;
	};

	class ID3D11RenderTargetView1 : ID3D11RenderTargetView
	{
	public:
		//Virtual
		struct GetDesc1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11RenderTargetView1* pThis;
			::D3D11_RENDER_TARGET_VIEW_DESC1* pDesc1;
		};

	private:
		 virtual ~ID3D11RenderTargetView1() = 0;
	};

	class ID3D11UnorderedAccessView1 : ID3D11UnorderedAccessView
	{
	public:
		//Virtual
		struct GetDesc1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11UnorderedAccessView1* pThis;
			::D3D11_UNORDERED_ACCESS_VIEW_DESC1* pDesc1;
		};

	private:
		 virtual ~ID3D11UnorderedAccessView1() = 0;
	};

	class ID3D11Query1 : ID3D11Query
	{
	public:
		//Virtual
		struct GetDesc1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11Query1* pThis;
			::D3D11_QUERY_DESC1* pDesc1;
		};

	private:
		 virtual ~ID3D11Query1() = 0;
	};

	class ID3D11DeviceContext3 : ID3D11DeviceContext2
	{
	public:
		//Virtual
		struct Flush1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D11DeviceContext3* pThis;
			::D3D11_CONTEXT_TYPE ContextType;
			::HANDLE hEvent;
		};

		//Virtual
		struct SetHardwareProtectionState
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11DeviceContext3* pThis;
			::BOOL HwProtectionEnable;
		};

		//Virtual
		struct GetHardwareProtectionState
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11DeviceContext3* pThis;
			::BOOL* pHwProtectionEnable;
		};

	private:
		 virtual ~ID3D11DeviceContext3() = 0;
	};

	class ID3D11Fence : ID3D11DeviceChild
	{
	public:
		//Virtual
		struct CreateSharedHandle
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D11Fence* pThis;
			const ::SECURITY_ATTRIBUTES* pAttributes;
			::DWORD dwAccess;
			::LPCWSTR lpName;
			::HANDLE* pHandle;
		};

		//Virtual
		struct GetCompletedValue
		{
			using ReturnType_t = ::UINT64;
			static constexpr size_t Argc = 1;

			::ID3D11Fence* pThis;
		};

		//Virtual
		struct SetEventOnCompletion
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11Fence* pThis;
			::UINT64 Value;
			::HANDLE hEvent;
		};

	private:
		 virtual ~ID3D11Fence() = 0;
	};

	class ID3D11DeviceContext4 : ID3D11DeviceContext3
	{
	public:
		//Virtual
		struct Signal
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11DeviceContext4* pThis;
			::ID3D11Fence* pFence;
			::UINT64 Value;
		};

		//Virtual
		struct Wait
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11DeviceContext4* pThis;
			::ID3D11Fence* pFence;
			::UINT64 Value;
		};

	private:
		 virtual ~ID3D11DeviceContext4() = 0;
	};

	class ID3D11Device3 : ID3D11Device2
	{
	public:
		//Virtual
		struct CreateTexture2D1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11Device3* pThis;
			const ::D3D11_TEXTURE2D_DESC1* pDesc1;
			const ::D3D11_SUBRESOURCE_DATA* pInitialData;
			::ID3D11Texture2D1** ppTexture2D;
		};

		//Virtual
		struct CreateTexture3D1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11Device3* pThis;
			const ::D3D11_TEXTURE3D_DESC1* pDesc1;
			const ::D3D11_SUBRESOURCE_DATA* pInitialData;
			::ID3D11Texture3D1** ppTexture3D;
		};

		//Virtual
		struct CreateRasterizerState2
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11Device3* pThis;
			const ::D3D11_RASTERIZER_DESC2* pRasterizerDesc;
			::ID3D11RasterizerState2** ppRasterizerState;
		};

		//Virtual
		struct CreateShaderResourceView1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11Device3* pThis;
			::ID3D11Resource* pResource;
			const ::D3D11_SHADER_RESOURCE_VIEW_DESC1* pDesc1;
			::ID3D11ShaderResourceView1** ppSRView1;
		};

		//Virtual
		struct CreateUnorderedAccessView1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11Device3* pThis;
			::ID3D11Resource* pResource;
			const ::D3D11_UNORDERED_ACCESS_VIEW_DESC1* pDesc1;
			::ID3D11UnorderedAccessView1** ppUAView1;
		};

		//Virtual
		struct CreateRenderTargetView1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11Device3* pThis;
			::ID3D11Resource* pResource;
			const ::D3D11_RENDER_TARGET_VIEW_DESC1* pDesc1;
			::ID3D11RenderTargetView1** ppRTView1;
		};

		//Virtual
		struct CreateQuery1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11Device3* pThis;
			const ::D3D11_QUERY_DESC1* pQueryDesc1;
			::ID3D11Query1** ppQuery1;
		};

		//Virtual
		struct GetImmediateContext3
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11Device3* pThis;
			::ID3D11DeviceContext3** ppImmediateContext;
		};

		//Virtual
		struct CreateDeferredContext3
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11Device3* pThis;
			::UINT ContextFlags;
			::ID3D11DeviceContext3** ppDeferredContext;
		};

		//Virtual
		struct WriteToSubresource
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 7;

			::ID3D11Device3* pThis;
			::ID3D11Resource* pDstResource;
			::UINT DstSubresource;
			const ::D3D11_BOX* pDstBox;
			const void* pSrcData;
			::UINT SrcRowPitch;
			::UINT SrcDepthPitch;
		};

		//Virtual
		struct ReadFromSubresource
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 7;

			::ID3D11Device3* pThis;
			void* pDstData;
			::UINT DstRowPitch;
			::UINT DstDepthPitch;
			::ID3D11Resource* pSrcResource;
			::UINT SrcSubresource;
			const ::D3D11_BOX* pSrcBox;
		};

	private:
		 virtual ~ID3D11Device3() = 0;
	};

	class ID3D11Device4 : ID3D11Device3
	{
	public:
		//Virtual
		struct RegisterDeviceRemovedEvent
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D11Device4* pThis;
			::HANDLE hEvent;
			::DWORD* pdwCookie;
		};

		//Virtual
		struct UnregisterDeviceRemoved
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D11Device4* pThis;
			::DWORD dwCookie;
		};

	private:
		 virtual ~ID3D11Device4() = 0;
	};

	class ID3D11Device5 : ID3D11Device4
	{
	public:
		//Virtual
		struct OpenSharedFence
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11Device5* pThis;
			::HANDLE hFence;
			const ::IID& ReturnedInterface;
			void** ppFence;
		};

		//Virtual
		struct CreateFence
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D11Device5* pThis;
			::UINT64 InitialValue;
			::D3D11_FENCE_FLAG Flags;
			const ::IID& ReturnedInterface;
			void** ppFence;
		};

	private:
		 virtual ~ID3D11Device5() = 0;
	};

	class ID3D11Multithread : IUnknown
	{
	public:
		//Virtual
		struct Enter
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D11Multithread* pThis;
		};

		//Virtual
		struct Leave
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D11Multithread* pThis;
		};

		//Virtual
		struct SetMultithreadProtected
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 2;

			::ID3D11Multithread* pThis;
			::BOOL bMTProtect;
		};

		//Virtual
		struct GetMultithreadProtected
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 1;

			::ID3D11Multithread* pThis;
		};

	private:
		 virtual ~ID3D11Multithread() = 0;
	};

	class ID3D11VideoContext2 : ID3D11VideoContext1
	{
	public:
		//Virtual
		struct VideoProcessorSetOutputHDRMetaData
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 5;

			::ID3D11VideoContext2* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::DXGI_HDR_METADATA_TYPE Type;
			::UINT Size;
			const void* pHDRMetaData;
		};

		//Virtual
		struct VideoProcessorGetOutputHDRMetaData
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 5;

			::ID3D11VideoContext2* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::DXGI_HDR_METADATA_TYPE* pType;
			::UINT Size;
			void* pMetaData;
		};

		//Virtual
		struct VideoProcessorSetStreamHDRMetaData
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D11VideoContext2* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			::DXGI_HDR_METADATA_TYPE Type;
			::UINT Size;
			const void* pHDRMetaData;
		};

		//Virtual
		struct VideoProcessorGetStreamHDRMetaData
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D11VideoContext2* pThis;
			::ID3D11VideoProcessor* pVideoProcessor;
			::UINT StreamIndex;
			::DXGI_HDR_METADATA_TYPE* pType;
			::UINT Size;
			void* pMetaData;
		};

	private:
		 virtual ~ID3D11VideoContext2() = 0;
	};

	class ID3D11VideoDevice2 : ID3D11VideoDevice1
	{
	public:
		//Virtual
		struct CheckFeatureSupport
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11VideoDevice2* pThis;
			::D3D11_FEATURE_VIDEO Feature;
			void* pFeatureSupportData;
			::UINT FeatureSupportDataSize;
		};

		//Virtual
		struct NegotiateCryptoSessionKeyExchangeMT
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D11VideoDevice2* pThis;
			::ID3D11CryptoSession* pCryptoSession;
			::D3D11_CRYPTO_SESSION_KEY_EXCHANGE_FLAGS flags;
			::UINT DataSize;
			void* pData;
		};

	private:
		 virtual ~ID3D11VideoDevice2() = 0;
	};

	class ID3D11VideoContext3 : ID3D11VideoContext2
	{
	public:
		//Virtual
		struct DecoderBeginFrame1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 8;

			::ID3D11VideoContext3* pThis;
			::ID3D11VideoDecoder* pDecoder;
			::ID3D11VideoDecoderOutputView* pView;
			::UINT ContentKeySize;
			const void* pContentKey;
			::UINT NumComponentHistograms;
			const ::UINT* pHistogramOffsets;
			::ID3D11Buffer*const* ppHistogramBuffers;
		};

		//Virtual
		struct SubmitDecoderBuffers2
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D11VideoContext3* pThis;
			::ID3D11VideoDecoder* pDecoder;
			::UINT NumBuffers;
			const ::D3D11_VIDEO_DECODER_BUFFER_DESC2* pBufferDesc;
		};

	private:
		 virtual ~ID3D11VideoContext3() = 0;
	};

}

namespace D3D11MethodIndices
{
	enum class IUnknown : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		VTableSize,
	};

	enum class ID3DInclude : size_t
	{
		/* ID3DInclude */
		Open,
		Close,

		VTableSize,
	};

	enum class ID3D10EffectType : size_t
	{
		/* ID3D10EffectType */
		IsValid,
		GetDesc,
		GetMemberTypeByIndex,
		GetMemberTypeByName,
		GetMemberTypeBySemantic,
		GetMemberName,
		GetMemberSemantic,

		VTableSize,
	};

	enum class ID3D10EffectVariable : size_t
	{
		/* ID3D10EffectVariable */
		IsValid,
		GetType,
		GetDesc,
		GetAnnotationByIndex,
		GetAnnotationByName,
		GetMemberByIndex,
		GetMemberByName,
		GetMemberBySemantic,
		GetElement,
		GetParentConstantBuffer,
		AsScalar,
		AsVector,
		AsMatrix,
		AsString,
		AsShaderResource,
		AsRenderTargetView,
		AsDepthStencilView,
		AsConstantBuffer,
		AsShader,
		AsBlend,
		AsDepthStencil,
		AsRasterizer,
		AsSampler,
		SetRawValue,
		GetRawValue,

		VTableSize,
	};

	enum class ID3D10EffectPass : size_t
	{
		/* ID3D10EffectPass */
		IsValid,
		GetDesc,
		GetVertexShaderDesc,
		GetGeometryShaderDesc,
		GetPixelShaderDesc,
		GetAnnotationByIndex,
		GetAnnotationByName,
		Apply,
		ComputeStateBlockMask,

		VTableSize,
	};

	enum class ID3D10EffectTechnique : size_t
	{
		/* ID3D10EffectTechnique */
		IsValid,
		GetDesc,
		GetAnnotationByIndex,
		GetAnnotationByName,
		GetPassByIndex,
		GetPassByName,
		ComputeStateBlockMask,

		VTableSize,
	};

	enum class AsyncIUnknown : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* AsyncIUnknown */
		Begin_QueryInterface,
		Finish_QueryInterface,
		Begin_AddRef,
		Finish_AddRef,
		Begin_Release,
		Finish_Release,

		VTableSize,
	};

	enum class IClassFactory : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IClassFactory */
		CreateInstance,
		LockServer,

		VTableSize,
	};

	enum class IMarshal : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IMarshal */
		GetUnmarshalClass,
		GetMarshalSizeMax,
		MarshalInterface,
		UnmarshalInterface,
		ReleaseMarshalData,
		DisconnectObject,

		VTableSize,
	};

	enum class IActivationFilter : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IActivationFilter */
		HandleActivation,

		VTableSize,
	};

	enum class IMalloc : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IMalloc */
		Alloc,
		Realloc,
		Free,
		GetSize,
		DidAlloc,
		HeapMinimize,

		VTableSize,
	};

	enum class IStdMarshalInfo : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IStdMarshalInfo */
		GetClassForHandler,

		VTableSize,
	};

	enum class IExternalConnection : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IExternalConnection */
		AddConnection,
		ReleaseConnection,

		VTableSize,
	};

	enum class IMultiQI : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IMultiQI */
		QueryMultipleInterfaces,

		VTableSize,
	};

	enum class AsyncIMultiQI : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* AsyncIMultiQI */
		Begin_QueryMultipleInterfaces,
		Finish_QueryMultipleInterfaces,

		VTableSize,
	};

	enum class IInternalUnknown : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IInternalUnknown */
		QueryInternalInterface,

		VTableSize,
	};

	enum class IEnumUnknown : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IEnumUnknown */
		Next,
		Skip,
		Reset,
		Clone,

		VTableSize,
	};

	enum class IEnumString : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IEnumString */
		Next,
		Skip,
		Reset,
		Clone,

		VTableSize,
	};

	enum class ISequentialStream : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ISequentialStream */
		Read,
		Write,

		VTableSize,
	};

	enum class IStream : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ISequentialStream */
		Read,
		Write,

		/* IStream */
		Seek,
		SetSize,
		CopyTo,
		Commit,
		Revert,
		LockRegion,
		UnlockRegion,
		Stat,
		Clone,

		VTableSize,
	};

	enum class IRpcChannelBuffer : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IRpcChannelBuffer */
		GetBuffer,
		SendReceive,
		FreeBuffer,
		GetDestCtx,
		IsConnected,

		VTableSize,
	};

	enum class IRpcChannelBuffer2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IRpcChannelBuffer */
		GetBuffer,
		SendReceive,
		FreeBuffer,
		GetDestCtx,
		IsConnected,

		/* IRpcChannelBuffer2 */
		GetProtocolVersion,

		VTableSize,
	};

	enum class IAsyncRpcChannelBuffer : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IRpcChannelBuffer */
		GetBuffer,
		SendReceive,
		FreeBuffer,
		GetDestCtx,
		IsConnected,

		/* IRpcChannelBuffer2 */
		GetProtocolVersion,

		/* IAsyncRpcChannelBuffer */
		Send,
		Receive,
		GetDestCtxEx,

		VTableSize,
	};

	enum class IRpcChannelBuffer3 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IRpcChannelBuffer */
		GetBuffer,
		SendReceive,
		FreeBuffer,
		GetDestCtx,
		IsConnected,

		/* IRpcChannelBuffer2 */
		GetProtocolVersion,

		/* IRpcChannelBuffer3 */
		Send,
		Receive,
		Cancel,
		GetCallContext,
		GetDestCtxEx,
		GetState,
		RegisterAsync,

		VTableSize,
	};

	enum class IRpcSyntaxNegotiate : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IRpcSyntaxNegotiate */
		NegotiateSyntax,

		VTableSize,
	};

	enum class IRpcProxyBuffer : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IRpcProxyBuffer */
		Connect,
		Disconnect,

		VTableSize,
	};

	enum class IRpcStubBuffer : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IRpcStubBuffer */
		Connect,
		Disconnect,
		Invoke,
		IsIIDSupported,
		CountRefs,
		DebugServerQueryInterface,
		DebugServerRelease,

		VTableSize,
	};

	enum class IPSFactoryBuffer : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IPSFactoryBuffer */
		CreateProxy,
		CreateStub,

		VTableSize,
	};

	enum class IChannelHook : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IChannelHook */
		ClientGetSize,
		ClientFillBuffer,
		ClientNotify,
		ServerNotify,
		ServerGetSize,
		ServerFillBuffer,

		VTableSize,
	};

	enum class IClientSecurity : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IClientSecurity */
		QueryBlanket,
		SetBlanket,
		CopyProxy,

		VTableSize,
	};

	enum class IServerSecurity : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IServerSecurity */
		QueryBlanket,
		ImpersonateClient,
		RevertToSelf,
		IsImpersonating,

		VTableSize,
	};

	enum class IRpcOptions : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IRpcOptions */
		Set,
		Query,

		VTableSize,
	};

	enum class IGlobalOptions : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IGlobalOptions */
		Set,
		Query,

		VTableSize,
	};

	enum class ISurrogate : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ISurrogate */
		LoadDllServer,
		FreeSurrogate,

		VTableSize,
	};

	enum class IGlobalInterfaceTable : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IGlobalInterfaceTable */
		RegisterInterfaceInGlobal,
		RevokeInterfaceFromGlobal,
		GetInterfaceFromGlobal,

		VTableSize,
	};

	enum class ISynchronize : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ISynchronize */
		Wait,
		Signal,
		Reset,

		VTableSize,
	};

	enum class ISynchronizeHandle : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ISynchronizeHandle */
		GetHandle,

		VTableSize,
	};

	enum class ISynchronizeEvent : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ISynchronizeHandle */
		GetHandle,

		/* ISynchronizeEvent */
		SetEventHandle,

		VTableSize,
	};

	enum class ISynchronizeContainer : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ISynchronizeContainer */
		AddSynchronize,
		WaitMultiple,

		VTableSize,
	};

	enum class ISynchronizeMutex : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ISynchronize */
		Wait,
		Signal,
		Reset,

		/* ISynchronizeMutex */
		ReleaseMutex,

		VTableSize,
	};

	enum class ICancelMethodCalls : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ICancelMethodCalls */
		Cancel,
		TestCancel,

		VTableSize,
	};

	enum class IAsyncManager : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IAsyncManager */
		CompleteCall,
		GetCallContext,
		GetState,

		VTableSize,
	};

	enum class ICallFactory : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ICallFactory */
		CreateCall,

		VTableSize,
	};

	enum class IRpcHelper : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IRpcHelper */
		GetDCOMProtocolVersion,
		GetIIDFromOBJREF,

		VTableSize,
	};

	enum class IReleaseMarshalBuffers : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IReleaseMarshalBuffers */
		ReleaseMarshalBuffer,

		VTableSize,
	};

	enum class IWaitMultiple : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IWaitMultiple */
		WaitMultiple,
		AddSynchronize,

		VTableSize,
	};

	enum class IAddrTrackingControl : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IAddrTrackingControl */
		EnableCOMDynamicAddrTracking,
		DisableCOMDynamicAddrTracking,

		VTableSize,
	};

	enum class IAddrExclusionControl : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IAddrExclusionControl */
		GetCurrentAddrExclusionList,
		UpdateAddrExclusionList,

		VTableSize,
	};

	enum class IPipeByte : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IPipeByte */
		Pull,
		Push,

		VTableSize,
	};

	enum class AsyncIPipeByte : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* AsyncIPipeByte */
		Begin_Pull,
		Finish_Pull,
		Begin_Push,
		Finish_Push,

		VTableSize,
	};

	enum class IPipeLong : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IPipeLong */
		Pull,
		Push,

		VTableSize,
	};

	enum class AsyncIPipeLong : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* AsyncIPipeLong */
		Begin_Pull,
		Finish_Pull,
		Begin_Push,
		Finish_Push,

		VTableSize,
	};

	enum class IPipeDouble : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IPipeDouble */
		Pull,
		Push,

		VTableSize,
	};

	enum class AsyncIPipeDouble : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* AsyncIPipeDouble */
		Begin_Pull,
		Finish_Pull,
		Begin_Push,
		Finish_Push,

		VTableSize,
	};

	enum class IComThreadingInfo : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IComThreadingInfo */
		GetCurrentApartmentType,
		GetCurrentThreadType,
		GetCurrentLogicalThreadId,
		SetCurrentLogicalThreadId,

		VTableSize,
	};

	enum class IProcessInitControl : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IProcessInitControl */
		ResetInitializerTimeout,

		VTableSize,
	};

	enum class IMarshalingStream : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ISequentialStream */
		Read,
		Write,

		/* IStream */
		Seek,
		SetSize,
		CopyTo,
		Commit,
		Revert,
		LockRegion,
		UnlockRegion,
		Stat,
		Clone,

		/* IMarshalingStream */
		GetMarshalingContextAttribute,

		VTableSize,
	};

	enum class IAgileReference : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IAgileReference */
		Resolve,

		VTableSize,
	};

	enum class IMachineGlobalObjectTable : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IMachineGlobalObjectTable */
		RegisterObject,
		GetObjectA,
		RevokeObject,

		VTableSize,
	};

	enum class IMallocSpy : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IMallocSpy */
		PreAlloc,
		PostAlloc,
		PreFree,
		PostFree,
		PreRealloc,
		PostRealloc,
		PreGetSize,
		PostGetSize,
		PreDidAlloc,
		PostDidAlloc,
		PreHeapMinimize,
		PostHeapMinimize,

		VTableSize,
	};

	enum class IBindCtx : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IBindCtx */
		RegisterObjectBound,
		RevokeObjectBound,
		ReleaseBoundObjects,
		SetBindOptions,
		GetBindOptions,
		GetRunningObjectTable,
		RegisterObjectParam,
		GetObjectParam,
		EnumObjectParam,
		RevokeObjectParam,

		VTableSize,
	};

	enum class IEnumMoniker : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IEnumMoniker */
		Next,
		Skip,
		Reset,
		Clone,

		VTableSize,
	};

	enum class IRunnableObject : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IRunnableObject */
		GetRunningClass,
		Run,
		IsRunning,
		LockRunning,
		SetContainedObject,

		VTableSize,
	};

	enum class IRunningObjectTable : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IRunningObjectTable */
		Register,
		Revoke,
		IsRunning,
		GetObjectA,
		NoteChangeTime,
		GetTimeOfLastChange,
		EnumRunning,

		VTableSize,
	};

	enum class IPersist : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IPersist */
		GetClassID,

		VTableSize,
	};

	enum class IPersistStream : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IPersist */
		GetClassID,

		/* IPersistStream */
		IsDirty,
		Load,
		Save,
		GetSizeMax,

		VTableSize,
	};

	enum class IMoniker : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IPersist */
		GetClassID,

		/* IPersistStream */
		IsDirty,
		Load,
		Save,
		GetSizeMax,

		/* IMoniker */
		BindToObject,
		BindToStorage,
		Reduce,
		ComposeWith,
		Enum,
		IsEqual,
		Hash,
		IsRunning,
		GetTimeOfLastChange,
		Inverse,
		CommonPrefixWith,
		RelativePathTo,
		GetDisplayName,
		ParseDisplayName,
		IsSystemMoniker,

		VTableSize,
	};

	enum class IROTData : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IROTData */
		GetComparisonData,

		VTableSize,
	};

	enum class IEnumSTATSTG : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IEnumSTATSTG */
		Next,
		Skip,
		Reset,
		Clone,

		VTableSize,
	};

	enum class IStorage : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IStorage */
		CreateStream,
		OpenStream,
		CreateStorage,
		OpenStorage,
		CopyTo,
		MoveElementTo,
		Commit,
		Revert,
		EnumElements,
		DestroyElement,
		RenameElement,
		SetElementTimes,
		SetClass,
		SetStateBits,
		Stat,

		VTableSize,
	};

	enum class IPersistFile : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IPersist */
		GetClassID,

		/* IPersistFile */
		IsDirty,
		Load,
		Save,
		SaveCompleted,
		GetCurFile,

		VTableSize,
	};

	enum class IPersistStorage : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IPersist */
		GetClassID,

		/* IPersistStorage */
		IsDirty,
		InitNew,
		Load,
		Save,
		SaveCompleted,
		HandsOffStorage,

		VTableSize,
	};

	enum class ILockBytes : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ILockBytes */
		ReadAt,
		WriteAt,
		Flush,
		SetSize,
		LockRegion,
		UnlockRegion,
		Stat,

		VTableSize,
	};

	enum class IEnumFORMATETC : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IEnumFORMATETC */
		Next,
		Skip,
		Reset,
		Clone,

		VTableSize,
	};

	enum class IEnumSTATDATA : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IEnumSTATDATA */
		Next,
		Skip,
		Reset,
		Clone,

		VTableSize,
	};

	enum class IRootStorage : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IRootStorage */
		SwitchToFile,

		VTableSize,
	};

	enum class IAdviseSink : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IAdviseSink */
		OnDataChange,
		OnViewChange,
		OnRename,
		OnSave,
		OnClose,

		VTableSize,
	};

	enum class AsyncIAdviseSink : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* AsyncIAdviseSink */
		Begin_OnDataChange,
		Finish_OnDataChange,
		Begin_OnViewChange,
		Finish_OnViewChange,
		Begin_OnRename,
		Finish_OnRename,
		Begin_OnSave,
		Finish_OnSave,
		Begin_OnClose,
		Finish_OnClose,

		VTableSize,
	};

	enum class IAdviseSink2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IAdviseSink */
		OnDataChange,
		OnViewChange,
		OnRename,
		OnSave,
		OnClose,

		/* IAdviseSink2 */
		OnLinkSrcChange,

		VTableSize,
	};

	enum class AsyncIAdviseSink2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* AsyncIAdviseSink */
		Begin_OnDataChange,
		Finish_OnDataChange,
		Begin_OnViewChange,
		Finish_OnViewChange,
		Begin_OnRename,
		Finish_OnRename,
		Begin_OnSave,
		Finish_OnSave,
		Begin_OnClose,
		Finish_OnClose,

		/* AsyncIAdviseSink2 */
		Begin_OnLinkSrcChange,
		Finish_OnLinkSrcChange,

		VTableSize,
	};

	enum class IDataObject : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDataObject */
		GetData,
		GetDataHere,
		QueryGetData,
		GetCanonicalFormatEtc,
		SetData,
		EnumFormatEtc,
		DAdvise,
		DUnadvise,
		EnumDAdvise,

		VTableSize,
	};

	enum class IDataAdviseHolder : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDataAdviseHolder */
		Advise,
		Unadvise,
		EnumAdvise,
		SendOnDataChange,

		VTableSize,
	};

	enum class IMessageFilter : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IMessageFilter */
		HandleInComingCall,
		RetryRejectedCall,
		MessagePending,

		VTableSize,
	};

	enum class IClassActivator : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IClassActivator */
		GetClassObject,

		VTableSize,
	};

	enum class IFillLockBytes : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IFillLockBytes */
		FillAppend,
		FillAt,
		SetFillSize,
		Terminate,

		VTableSize,
	};

	enum class IProgressNotify : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IProgressNotify */
		OnProgress,

		VTableSize,
	};

	enum class ILayoutStorage : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ILayoutStorage */
		LayoutScript,
		BeginMonitor,
		EndMonitor,
		ReLayoutDocfile,
		ReLayoutDocfileOnILockBytes,

		VTableSize,
	};

	enum class IBlockingLock : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IBlockingLock */
		Lock,
		Unlock,

		VTableSize,
	};

	enum class ITimeAndNoticeControl : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ITimeAndNoticeControl */
		SuppressChanges,

		VTableSize,
	};

	enum class IOplockStorage : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IOplockStorage */
		CreateStorageEx,
		OpenStorageEx,

		VTableSize,
	};

	enum class IDirectWriterLock : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDirectWriterLock */
		WaitForWriteAccess,
		ReleaseWriteAccess,
		HaveWriteAccess,

		VTableSize,
	};

	enum class IUrlMon : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IUrlMon */
		AsyncGetClassBits,

		VTableSize,
	};

	enum class IForegroundTransfer : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IForegroundTransfer */
		AllowForegroundTransfer,

		VTableSize,
	};

	enum class IThumbnailExtractor : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IThumbnailExtractor */
		ExtractThumbnail,
		OnFileUpdated,

		VTableSize,
	};

	enum class IDummyHICONIncluder : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDummyHICONIncluder */
		Dummy,

		VTableSize,
	};

	enum class IProcessLock : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IProcessLock */
		AddRefOnProcess,
		ReleaseRefOnProcess,

		VTableSize,
	};

	enum class ISurrogateService : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ISurrogateService */
		Init,
		ApplicationLaunch,
		ApplicationFree,
		CatalogRefresh,
		ProcessShutdown,

		VTableSize,
	};

	enum class IInitializeSpy : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IInitializeSpy */
		PreInitialize,
		PostInitialize,
		PreUninitialize,
		PostUninitialize,

		VTableSize,
	};

	enum class IApartmentShutdown : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IApartmentShutdown */
		OnUninitialize,

		VTableSize,
	};

	enum class ICreateTypeInfo : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ICreateTypeInfo */
		SetGuid,
		SetTypeFlags,
		SetDocString,
		SetHelpContext,
		SetVersion,
		AddRefTypeInfo,
		AddFuncDesc,
		AddImplType,
		SetImplTypeFlags,
		SetAlignment,
		SetSchema,
		AddVarDesc,
		SetFuncAndParamNames,
		SetVarName,
		SetTypeDescAlias,
		DefineFuncAsDllEntry,
		SetFuncDocString,
		SetVarDocString,
		SetFuncHelpContext,
		SetVarHelpContext,
		SetMops,
		SetTypeIdldesc,
		LayOut,

		VTableSize,
	};

	enum class ICreateTypeInfo2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ICreateTypeInfo */
		SetGuid,
		SetTypeFlags,
		SetDocString,
		SetHelpContext,
		SetVersion,
		AddRefTypeInfo,
		AddFuncDesc,
		AddImplType,
		SetImplTypeFlags,
		SetAlignment,
		SetSchema,
		AddVarDesc,
		SetFuncAndParamNames,
		SetVarName,
		SetTypeDescAlias,
		DefineFuncAsDllEntry,
		SetFuncDocString,
		SetVarDocString,
		SetFuncHelpContext,
		SetVarHelpContext,
		SetMops,
		SetTypeIdldesc,
		LayOut,

		/* ICreateTypeInfo2 */
		DeleteFuncDesc,
		DeleteFuncDescByMemId,
		DeleteVarDesc,
		DeleteVarDescByMemId,
		DeleteImplType,
		SetCustData,
		SetFuncCustData,
		SetParamCustData,
		SetVarCustData,
		SetImplTypeCustData,
		SetHelpStringContext,
		SetFuncHelpStringContext,
		SetVarHelpStringContext,
		Invalidate,
		SetName,

		VTableSize,
	};

	enum class ICreateTypeLib : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ICreateTypeLib */
		CreateTypeInfo,
		SetName,
		SetVersion,
		SetGuid,
		SetDocString,
		SetHelpFileName,
		SetHelpContext,
		SetLcid,
		SetLibFlags,
		SaveAllChanges,

		VTableSize,
	};

	enum class ICreateTypeLib2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ICreateTypeLib */
		CreateTypeInfo,
		SetName,
		SetVersion,
		SetGuid,
		SetDocString,
		SetHelpFileName,
		SetHelpContext,
		SetLcid,
		SetLibFlags,
		SaveAllChanges,

		/* ICreateTypeLib2 */
		DeleteTypeInfo,
		SetCustData,
		SetHelpStringContext,
		SetHelpStringDll,

		VTableSize,
	};

	enum class IDispatch : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDispatch */
		GetTypeInfoCount,
		GetTypeInfo,
		GetIDsOfNames,
		Invoke,

		VTableSize,
	};

	enum class IEnumVARIANT : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IEnumVARIANT */
		Next,
		Skip,
		Reset,
		Clone,

		VTableSize,
	};

	enum class ITypeComp : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ITypeComp */
		Bind,
		BindType,

		VTableSize,
	};

	enum class ITypeInfo : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ITypeInfo */
		GetTypeAttr,
		GetTypeComp,
		GetFuncDesc,
		GetVarDesc,
		GetNames,
		GetRefTypeOfImplType,
		GetImplTypeFlags,
		GetIDsOfNames,
		Invoke,
		GetDocumentation,
		GetDllEntry,
		GetRefTypeInfo,
		AddressOfMember,
		CreateInstance,
		GetMops,
		GetContainingTypeLib,
		ReleaseTypeAttr,
		ReleaseFuncDesc,
		ReleaseVarDesc,

		VTableSize,
	};

	enum class ITypeInfo2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ITypeInfo */
		GetTypeAttr,
		GetTypeComp,
		GetFuncDesc,
		GetVarDesc,
		GetNames,
		GetRefTypeOfImplType,
		GetImplTypeFlags,
		GetIDsOfNames,
		Invoke,
		GetDocumentation,
		GetDllEntry,
		GetRefTypeInfo,
		AddressOfMember,
		CreateInstance,
		GetMops,
		GetContainingTypeLib,
		ReleaseTypeAttr,
		ReleaseFuncDesc,
		ReleaseVarDesc,

		/* ITypeInfo2 */
		GetTypeKind,
		GetTypeFlags,
		GetFuncIndexOfMemId,
		GetVarIndexOfMemId,
		GetCustData,
		GetFuncCustData,
		GetParamCustData,
		GetVarCustData,
		GetImplTypeCustData,
		GetDocumentation2,
		GetAllCustData,
		GetAllFuncCustData,
		GetAllParamCustData,
		GetAllVarCustData,
		GetAllImplTypeCustData,

		VTableSize,
	};

	enum class ITypeLib : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ITypeLib */
		GetTypeInfoCount,
		GetTypeInfo,
		GetTypeInfoType,
		GetTypeInfoOfGuid,
		GetLibAttr,
		GetTypeComp,
		GetDocumentation,
		IsName,
		FindName,
		ReleaseTLibAttr,

		VTableSize,
	};

	enum class ITypeLib2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ITypeLib */
		GetTypeInfoCount,
		GetTypeInfo,
		GetTypeInfoType,
		GetTypeInfoOfGuid,
		GetLibAttr,
		GetTypeComp,
		GetDocumentation,
		IsName,
		FindName,
		ReleaseTLibAttr,

		/* ITypeLib2 */
		GetCustData,
		GetLibStatistics,
		GetDocumentation2,
		GetAllCustData,

		VTableSize,
	};

	enum class ITypeChangeEvents : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ITypeChangeEvents */
		RequestTypeChange,
		AfterTypeChange,

		VTableSize,
	};

	enum class IErrorInfo : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IErrorInfo */
		GetGUID,
		GetSource,
		GetDescription,
		GetHelpFile,
		GetHelpContext,

		VTableSize,
	};

	enum class ICreateErrorInfo : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ICreateErrorInfo */
		SetGUID,
		SetSource,
		SetDescription,
		SetHelpFile,
		SetHelpContext,

		VTableSize,
	};

	enum class ISupportErrorInfo : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ISupportErrorInfo */
		InterfaceSupportsErrorInfo,

		VTableSize,
	};

	enum class ITypeFactory : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ITypeFactory */
		CreateFromTypeInfo,

		VTableSize,
	};

	enum class ITypeMarshal : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ITypeMarshal */
		Size,
		Marshal,
		Unmarshal,
		Free,

		VTableSize,
	};

	enum class IRecordInfo : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IRecordInfo */
		RecordInit,
		RecordClear,
		RecordCopy,
		GetGuid,
		GetName,
		GetSize,
		GetTypeInfo,
		GetField,
		GetFieldNoCopy,
		PutField,
		PutFieldNoCopy,
		GetFieldNames,
		IsMatchingType,
		RecordCreate,
		RecordCreateCopy,
		RecordDestroy,

		VTableSize,
	};

	enum class IErrorLog : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IErrorLog */
		AddError,

		VTableSize,
	};

	enum class IPropertyBag : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IPropertyBag */
		Read,
		Write,

		VTableSize,
	};

	enum class ITypeLibRegistrationReader : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ITypeLibRegistrationReader */
		EnumTypeLibRegistrations,

		VTableSize,
	};

	enum class ITypeLibRegistration : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ITypeLibRegistration */
		GetGuid,
		GetVersion,
		GetLcid,
		GetWin32Path,
		GetWin64Path,
		GetDisplayName,
		GetFlags,
		GetHelpDir,

		VTableSize,
	};

	enum class IPropertyStorage : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IPropertyStorage */
		ReadMultiple,
		WriteMultiple,
		DeleteMultiple,
		ReadPropertyNames,
		WritePropertyNames,
		DeletePropertyNames,
		Commit,
		Revert,
		Enum,
		SetTimes,
		SetClass,
		Stat,

		VTableSize,
	};

	enum class IPropertySetStorage : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IPropertySetStorage */
		Create,
		Open,
		Delete,
		Enum,

		VTableSize,
	};

	enum class IEnumSTATPROPSTG : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IEnumSTATPROPSTG */
		Next,
		Skip,
		Reset,
		Clone,

		VTableSize,
	};

	enum class IEnumSTATPROPSETSTG : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IEnumSTATPROPSETSTG */
		Next,
		Skip,
		Reset,
		Clone,

		VTableSize,
	};

	enum class IOleAdviseHolder : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IOleAdviseHolder */
		Advise,
		Unadvise,
		EnumAdvise,
		SendOnRename,
		SendOnSave,
		SendOnClose,

		VTableSize,
	};

	enum class IOleCache : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IOleCache */
		Cache,
		Uncache,
		EnumCache,
		InitCache,
		SetData,

		VTableSize,
	};

	enum class IOleCache2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IOleCache */
		Cache,
		Uncache,
		EnumCache,
		InitCache,
		SetData,

		/* IOleCache2 */
		UpdateCache,
		DiscardCache,

		VTableSize,
	};

	enum class IOleCacheControl : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IOleCacheControl */
		OnRun,
		OnStop,

		VTableSize,
	};

	enum class IParseDisplayName : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IParseDisplayName */
		ParseDisplayName,

		VTableSize,
	};

	enum class IOleContainer : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IParseDisplayName */
		ParseDisplayName,

		/* IOleContainer */
		EnumObjects,
		LockContainer,

		VTableSize,
	};

	enum class IOleClientSite : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IOleClientSite */
		SaveObject,
		GetMoniker,
		GetContainer,
		ShowObject,
		OnShowWindow,
		RequestNewObjectLayout,

		VTableSize,
	};

	enum class IOleObject : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IOleObject */
		SetClientSite,
		GetClientSite,
		SetHostNames,
		Close,
		SetMoniker,
		GetMoniker,
		InitFromData,
		GetClipboardData,
		DoVerb,
		EnumVerbs,
		Update,
		IsUpToDate,
		GetUserClassID,
		GetUserType,
		SetExtent,
		GetExtent,
		Advise,
		Unadvise,
		EnumAdvise,
		GetMiscStatus,
		SetColorScheme,

		VTableSize,
	};

	enum class IOleWindow : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IOleWindow */
		GetWindow,
		ContextSensitiveHelp,

		VTableSize,
	};

	enum class IOleLink : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IOleLink */
		SetUpdateOptions,
		GetUpdateOptions,
		SetSourceMoniker,
		GetSourceMoniker,
		SetSourceDisplayName,
		GetSourceDisplayName,
		BindToSource,
		BindIfRunning,
		GetBoundSource,
		UnbindSource,
		Update,

		VTableSize,
	};

	enum class IOleItemContainer : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IParseDisplayName */
		ParseDisplayName,

		/* IOleContainer */
		EnumObjects,
		LockContainer,

		/* IOleItemContainer */
		GetObjectA,
		GetObjectStorage,
		IsRunning,

		VTableSize,
	};

	enum class IOleInPlaceUIWindow : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IOleWindow */
		GetWindow,
		ContextSensitiveHelp,

		/* IOleInPlaceUIWindow */
		GetBorder,
		RequestBorderSpace,
		SetBorderSpace,
		SetActiveObject,

		VTableSize,
	};

	enum class IOleInPlaceActiveObject : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IOleWindow */
		GetWindow,
		ContextSensitiveHelp,

		/* IOleInPlaceActiveObject */
		TranslateAcceleratorA,
		OnFrameWindowActivate,
		OnDocWindowActivate,
		ResizeBorder,
		EnableModeless,

		VTableSize,
	};

	enum class IOleInPlaceFrame : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IOleWindow */
		GetWindow,
		ContextSensitiveHelp,

		/* IOleInPlaceUIWindow */
		GetBorder,
		RequestBorderSpace,
		SetBorderSpace,
		SetActiveObject,

		/* IOleInPlaceFrame */
		InsertMenus,
		SetMenu,
		RemoveMenus,
		SetStatusText,
		EnableModeless,
		TranslateAcceleratorA,

		VTableSize,
	};

	enum class IOleInPlaceObject : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IOleWindow */
		GetWindow,
		ContextSensitiveHelp,

		/* IOleInPlaceObject */
		InPlaceDeactivate,
		UIDeactivate,
		SetObjectRects,
		ReactivateAndUndo,

		VTableSize,
	};

	enum class IOleInPlaceSite : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IOleWindow */
		GetWindow,
		ContextSensitiveHelp,

		/* IOleInPlaceSite */
		CanInPlaceActivate,
		OnInPlaceActivate,
		OnUIActivate,
		GetWindowContext,
		Scroll,
		OnUIDeactivate,
		OnInPlaceDeactivate,
		DiscardUndoState,
		DeactivateAndUndo,
		OnPosRectChange,

		VTableSize,
	};

	enum class IContinue : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IContinue */
		FContinue,

		VTableSize,
	};

	enum class IViewObject : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IViewObject */
		Draw,
		GetColorSet,
		Freeze,
		Unfreeze,
		SetAdvise,
		GetAdvise,

		VTableSize,
	};

	enum class IViewObject2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IViewObject */
		Draw,
		GetColorSet,
		Freeze,
		Unfreeze,
		SetAdvise,
		GetAdvise,

		/* IViewObject2 */
		GetExtent,

		VTableSize,
	};

	enum class IDropSource : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDropSource */
		QueryContinueDrag,
		GiveFeedback,

		VTableSize,
	};

	enum class IDropTarget : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDropTarget */
		DragEnter,
		DragOver,
		DragLeave,
		Drop,

		VTableSize,
	};

	enum class IDropSourceNotify : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDropSourceNotify */
		DragEnterTarget,
		DragLeaveTarget,

		VTableSize,
	};

	enum class IEnterpriseDropTarget : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IEnterpriseDropTarget */
		SetDropSourceEnterpriseId,
		IsEvaluatingEdpPolicy,

		VTableSize,
	};

	enum class IEnumOLEVERB : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IEnumOLEVERB */
		Next,
		Skip,
		Reset,
		Clone,

		VTableSize,
	};

	enum class IServiceProvider : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IServiceProvider */
		QueryService,

		VTableSize,
	};

	enum class IXMLDOMImplementation : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDispatch */
		GetTypeInfoCount,
		GetTypeInfo,
		GetIDsOfNames,
		Invoke,

		/* IXMLDOMImplementation */
		hasFeature,

		VTableSize,
	};

	enum class IXMLDOMNode : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDispatch */
		GetTypeInfoCount,
		GetTypeInfo,
		GetIDsOfNames,
		Invoke,

		/* IXMLDOMNode */
		get_nodeName,
		get_nodeValue,
		put_nodeValue,
		get_nodeType,
		get_parentNode,
		get_childNodes,
		get_firstChild,
		get_lastChild,
		get_previousSibling,
		get_nextSibling,
		get_attributes,
		insertBefore,
		replaceChild,
		removeChild,
		appendChild,
		hasChildNodes,
		get_ownerDocument,
		cloneNode,
		get_nodeTypeString,
		get_text,
		put_text,
		get_specified,
		get_definition,
		get_nodeTypedValue,
		put_nodeTypedValue,
		get_dataType,
		put_dataType,
		get_xml,
		transformNode,
		selectNodes,
		selectSingleNode,
		get_parsed,
		get_namespaceURI,
		get_prefix,
		get_baseName,
		transformNodeToObject,

		VTableSize,
	};

	enum class IXMLDOMDocument : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDispatch */
		GetTypeInfoCount,
		GetTypeInfo,
		GetIDsOfNames,
		Invoke,

		/* IXMLDOMNode */
		get_nodeName,
		get_nodeValue,
		put_nodeValue,
		get_nodeType,
		get_parentNode,
		get_childNodes,
		get_firstChild,
		get_lastChild,
		get_previousSibling,
		get_nextSibling,
		get_attributes,
		insertBefore,
		replaceChild,
		removeChild,
		appendChild,
		hasChildNodes,
		get_ownerDocument,
		cloneNode,
		get_nodeTypeString,
		get_text,
		put_text,
		get_specified,
		get_definition,
		get_nodeTypedValue,
		put_nodeTypedValue,
		get_dataType,
		put_dataType,
		get_xml,
		transformNode,
		selectNodes,
		selectSingleNode,
		get_parsed,
		get_namespaceURI,
		get_prefix,
		get_baseName,
		transformNodeToObject,

		/* IXMLDOMDocument */
		get_doctype,
		get_implementation,
		get_documentElement,
		putref_documentElement,
		createElement,
		createDocumentFragment,
		createTextNode,
		createComment,
		createCDATASection,
		createProcessingInstruction,
		createAttribute,
		createEntityReference,
		getElementsByTagName,
		createNode,
		nodeFromID,
		load,
		get_readyState,
		get_parseError,
		get_url,
		get_async,
		put_async,
		abort,
		loadXML,
		save,
		get_validateOnParse,
		put_validateOnParse,
		get_resolveExternals,
		put_resolveExternals,
		get_preserveWhiteSpace,
		put_preserveWhiteSpace,
		put_onreadystatechange,
		put_ondataavailable,
		put_ontransformnode,

		VTableSize,
	};

	enum class IXMLDOMNodeList : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDispatch */
		GetTypeInfoCount,
		GetTypeInfo,
		GetIDsOfNames,
		Invoke,

		/* IXMLDOMNodeList */
		get_item,
		get_length,
		nextNode,
		reset,
		get__newEnum,

		VTableSize,
	};

	enum class IXMLDOMNamedNodeMap : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDispatch */
		GetTypeInfoCount,
		GetTypeInfo,
		GetIDsOfNames,
		Invoke,

		/* IXMLDOMNamedNodeMap */
		getNamedItem,
		setNamedItem,
		removeNamedItem,
		get_item,
		get_length,
		getQualifiedItem,
		removeQualifiedItem,
		nextNode,
		reset,
		get__newEnum,

		VTableSize,
	};

	enum class IXMLDOMCharacterData : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDispatch */
		GetTypeInfoCount,
		GetTypeInfo,
		GetIDsOfNames,
		Invoke,

		/* IXMLDOMNode */
		get_nodeName,
		get_nodeValue,
		put_nodeValue,
		get_nodeType,
		get_parentNode,
		get_childNodes,
		get_firstChild,
		get_lastChild,
		get_previousSibling,
		get_nextSibling,
		get_attributes,
		insertBefore,
		replaceChild,
		removeChild,
		appendChild,
		hasChildNodes,
		get_ownerDocument,
		cloneNode,
		get_nodeTypeString,
		get_text,
		put_text,
		get_specified,
		get_definition,
		get_nodeTypedValue,
		put_nodeTypedValue,
		get_dataType,
		put_dataType,
		get_xml,
		transformNode,
		selectNodes,
		selectSingleNode,
		get_parsed,
		get_namespaceURI,
		get_prefix,
		get_baseName,
		transformNodeToObject,

		/* IXMLDOMCharacterData */
		get_data,
		put_data,
		get_length,
		substringData,
		appendData,
		insertData,
		deleteData,
		replaceData,

		VTableSize,
	};

	enum class IXMLDOMAttribute : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDispatch */
		GetTypeInfoCount,
		GetTypeInfo,
		GetIDsOfNames,
		Invoke,

		/* IXMLDOMNode */
		get_nodeName,
		get_nodeValue,
		put_nodeValue,
		get_nodeType,
		get_parentNode,
		get_childNodes,
		get_firstChild,
		get_lastChild,
		get_previousSibling,
		get_nextSibling,
		get_attributes,
		insertBefore,
		replaceChild,
		removeChild,
		appendChild,
		hasChildNodes,
		get_ownerDocument,
		cloneNode,
		get_nodeTypeString,
		get_text,
		put_text,
		get_specified,
		get_definition,
		get_nodeTypedValue,
		put_nodeTypedValue,
		get_dataType,
		put_dataType,
		get_xml,
		transformNode,
		selectNodes,
		selectSingleNode,
		get_parsed,
		get_namespaceURI,
		get_prefix,
		get_baseName,
		transformNodeToObject,

		/* IXMLDOMAttribute */
		get_name,
		get_value,
		put_value,

		VTableSize,
	};

	enum class IXMLDOMElement : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDispatch */
		GetTypeInfoCount,
		GetTypeInfo,
		GetIDsOfNames,
		Invoke,

		/* IXMLDOMNode */
		get_nodeName,
		get_nodeValue,
		put_nodeValue,
		get_nodeType,
		get_parentNode,
		get_childNodes,
		get_firstChild,
		get_lastChild,
		get_previousSibling,
		get_nextSibling,
		get_attributes,
		insertBefore,
		replaceChild,
		removeChild,
		appendChild,
		hasChildNodes,
		get_ownerDocument,
		cloneNode,
		get_nodeTypeString,
		get_text,
		put_text,
		get_specified,
		get_definition,
		get_nodeTypedValue,
		put_nodeTypedValue,
		get_dataType,
		put_dataType,
		get_xml,
		transformNode,
		selectNodes,
		selectSingleNode,
		get_parsed,
		get_namespaceURI,
		get_prefix,
		get_baseName,
		transformNodeToObject,

		/* IXMLDOMElement */
		get_tagName,
		getAttribute,
		setAttribute,
		removeAttribute,
		getAttributeNode,
		setAttributeNode,
		removeAttributeNode,
		getElementsByTagName,
		normalize,

		VTableSize,
	};

	enum class IXMLDOMText : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDispatch */
		GetTypeInfoCount,
		GetTypeInfo,
		GetIDsOfNames,
		Invoke,

		/* IXMLDOMNode */
		get_nodeName,
		get_nodeValue,
		put_nodeValue,
		get_nodeType,
		get_parentNode,
		get_childNodes,
		get_firstChild,
		get_lastChild,
		get_previousSibling,
		get_nextSibling,
		get_attributes,
		insertBefore,
		replaceChild,
		removeChild,
		appendChild,
		hasChildNodes,
		get_ownerDocument,
		cloneNode,
		get_nodeTypeString,
		get_text,
		put_text,
		get_specified,
		get_definition,
		get_nodeTypedValue,
		put_nodeTypedValue,
		get_dataType,
		put_dataType,
		get_xml,
		transformNode,
		selectNodes,
		selectSingleNode,
		get_parsed,
		get_namespaceURI,
		get_prefix,
		get_baseName,
		transformNodeToObject,

		/* IXMLDOMCharacterData */
		get_data,
		put_data,
		get_length,
		substringData,
		appendData,
		insertData,
		deleteData,
		replaceData,

		/* IXMLDOMText */
		splitText,

		VTableSize,
	};

	enum class IXMLDOMProcessingInstruction : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDispatch */
		GetTypeInfoCount,
		GetTypeInfo,
		GetIDsOfNames,
		Invoke,

		/* IXMLDOMNode */
		get_nodeName,
		get_nodeValue,
		put_nodeValue,
		get_nodeType,
		get_parentNode,
		get_childNodes,
		get_firstChild,
		get_lastChild,
		get_previousSibling,
		get_nextSibling,
		get_attributes,
		insertBefore,
		replaceChild,
		removeChild,
		appendChild,
		hasChildNodes,
		get_ownerDocument,
		cloneNode,
		get_nodeTypeString,
		get_text,
		put_text,
		get_specified,
		get_definition,
		get_nodeTypedValue,
		put_nodeTypedValue,
		get_dataType,
		put_dataType,
		get_xml,
		transformNode,
		selectNodes,
		selectSingleNode,
		get_parsed,
		get_namespaceURI,
		get_prefix,
		get_baseName,
		transformNodeToObject,

		/* IXMLDOMProcessingInstruction */
		get_target,
		get_data,
		put_data,

		VTableSize,
	};

	enum class IXMLDOMDocumentType : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDispatch */
		GetTypeInfoCount,
		GetTypeInfo,
		GetIDsOfNames,
		Invoke,

		/* IXMLDOMNode */
		get_nodeName,
		get_nodeValue,
		put_nodeValue,
		get_nodeType,
		get_parentNode,
		get_childNodes,
		get_firstChild,
		get_lastChild,
		get_previousSibling,
		get_nextSibling,
		get_attributes,
		insertBefore,
		replaceChild,
		removeChild,
		appendChild,
		hasChildNodes,
		get_ownerDocument,
		cloneNode,
		get_nodeTypeString,
		get_text,
		put_text,
		get_specified,
		get_definition,
		get_nodeTypedValue,
		put_nodeTypedValue,
		get_dataType,
		put_dataType,
		get_xml,
		transformNode,
		selectNodes,
		selectSingleNode,
		get_parsed,
		get_namespaceURI,
		get_prefix,
		get_baseName,
		transformNodeToObject,

		/* IXMLDOMDocumentType */
		get_name,
		get_entities,
		get_notations,

		VTableSize,
	};

	enum class IXMLDOMNotation : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDispatch */
		GetTypeInfoCount,
		GetTypeInfo,
		GetIDsOfNames,
		Invoke,

		/* IXMLDOMNode */
		get_nodeName,
		get_nodeValue,
		put_nodeValue,
		get_nodeType,
		get_parentNode,
		get_childNodes,
		get_firstChild,
		get_lastChild,
		get_previousSibling,
		get_nextSibling,
		get_attributes,
		insertBefore,
		replaceChild,
		removeChild,
		appendChild,
		hasChildNodes,
		get_ownerDocument,
		cloneNode,
		get_nodeTypeString,
		get_text,
		put_text,
		get_specified,
		get_definition,
		get_nodeTypedValue,
		put_nodeTypedValue,
		get_dataType,
		put_dataType,
		get_xml,
		transformNode,
		selectNodes,
		selectSingleNode,
		get_parsed,
		get_namespaceURI,
		get_prefix,
		get_baseName,
		transformNodeToObject,

		/* IXMLDOMNotation */
		get_publicId,
		get_systemId,

		VTableSize,
	};

	enum class IXMLDOMEntity : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDispatch */
		GetTypeInfoCount,
		GetTypeInfo,
		GetIDsOfNames,
		Invoke,

		/* IXMLDOMNode */
		get_nodeName,
		get_nodeValue,
		put_nodeValue,
		get_nodeType,
		get_parentNode,
		get_childNodes,
		get_firstChild,
		get_lastChild,
		get_previousSibling,
		get_nextSibling,
		get_attributes,
		insertBefore,
		replaceChild,
		removeChild,
		appendChild,
		hasChildNodes,
		get_ownerDocument,
		cloneNode,
		get_nodeTypeString,
		get_text,
		put_text,
		get_specified,
		get_definition,
		get_nodeTypedValue,
		put_nodeTypedValue,
		get_dataType,
		put_dataType,
		get_xml,
		transformNode,
		selectNodes,
		selectSingleNode,
		get_parsed,
		get_namespaceURI,
		get_prefix,
		get_baseName,
		transformNodeToObject,

		/* IXMLDOMEntity */
		get_publicId,
		get_systemId,
		get_notationName,

		VTableSize,
	};

	enum class IXMLDOMParseError : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDispatch */
		GetTypeInfoCount,
		GetTypeInfo,
		GetIDsOfNames,
		Invoke,

		/* IXMLDOMParseError */
		get_errorCode,
		get_url,
		get_reason,
		get_srcText,
		get_line,
		get_linepos,
		get_filepos,

		VTableSize,
	};

	enum class IXTLRuntime : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDispatch */
		GetTypeInfoCount,
		GetTypeInfo,
		GetIDsOfNames,
		Invoke,

		/* IXMLDOMNode */
		get_nodeName,
		get_nodeValue,
		put_nodeValue,
		get_nodeType,
		get_parentNode,
		get_childNodes,
		get_firstChild,
		get_lastChild,
		get_previousSibling,
		get_nextSibling,
		get_attributes,
		insertBefore,
		replaceChild,
		removeChild,
		appendChild,
		hasChildNodes,
		get_ownerDocument,
		cloneNode,
		get_nodeTypeString,
		get_text,
		put_text,
		get_specified,
		get_definition,
		get_nodeTypedValue,
		put_nodeTypedValue,
		get_dataType,
		put_dataType,
		get_xml,
		transformNode,
		selectNodes,
		selectSingleNode,
		get_parsed,
		get_namespaceURI,
		get_prefix,
		get_baseName,
		transformNodeToObject,

		/* IXTLRuntime */
		uniqueID,
		depth,
		childNumber,
		ancestorChildNumber,
		absoluteChildNumber,
		formatIndex,
		formatNumber,
		formatDate,
		formatTime,

		VTableSize,
	};

	enum class IXMLHttpRequest : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDispatch */
		GetTypeInfoCount,
		GetTypeInfo,
		GetIDsOfNames,
		Invoke,

		/* IXMLHttpRequest */
		open,
		setRequestHeader,
		getResponseHeader,
		getAllResponseHeaders,
		send,
		abort,
		get_status,
		get_statusText,
		get_responseXML,
		get_responseText,
		get_responseBody,
		get_responseStream,
		get_readyState,
		put_onreadystatechange,

		VTableSize,
	};

	enum class IXMLDSOControl : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDispatch */
		GetTypeInfoCount,
		GetTypeInfo,
		GetIDsOfNames,
		Invoke,

		/* IXMLDSOControl */
		get_XMLDocument,
		put_XMLDocument,
		get_JavaDSOCompatible,
		put_JavaDSOCompatible,
		get_readyState,

		VTableSize,
	};

	enum class IXMLElementCollection : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDispatch */
		GetTypeInfoCount,
		GetTypeInfo,
		GetIDsOfNames,
		Invoke,

		/* IXMLElementCollection */
		put_length,
		get_length,
		get__newEnum,
		item,

		VTableSize,
	};

	enum class IXMLDocument : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDispatch */
		GetTypeInfoCount,
		GetTypeInfo,
		GetIDsOfNames,
		Invoke,

		/* IXMLDocument */
		get_root,
		get_fileSize,
		get_fileModifiedDate,
		get_fileUpdatedDate,
		get_URL,
		put_URL,
		get_mimeType,
		get_readyState,
		get_charset,
		put_charset,
		get_version,
		get_doctype,
		get_dtdURL,
		createElement,

		VTableSize,
	};

	enum class IXMLDocument2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDispatch */
		GetTypeInfoCount,
		GetTypeInfo,
		GetIDsOfNames,
		Invoke,

		/* IXMLDocument2 */
		get_root,
		get_fileSize,
		get_fileModifiedDate,
		get_fileUpdatedDate,
		get_URL,
		put_URL,
		get_mimeType,
		get_readyState,
		get_charset,
		put_charset,
		get_version,
		get_doctype,
		get_dtdURL,
		createElement,
		get_async,
		put_async,

		VTableSize,
	};

	enum class IXMLElement : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDispatch */
		GetTypeInfoCount,
		GetTypeInfo,
		GetIDsOfNames,
		Invoke,

		/* IXMLElement */
		get_tagName,
		put_tagName,
		get_parent,
		setAttribute,
		getAttribute,
		removeAttribute,
		get_children,
		get_type,
		get_text,
		put_text,
		addChild,
		removeChild,

		VTableSize,
	};

	enum class IXMLElement2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDispatch */
		GetTypeInfoCount,
		GetTypeInfo,
		GetIDsOfNames,
		Invoke,

		/* IXMLElement2 */
		get_tagName,
		put_tagName,
		get_parent,
		setAttribute,
		getAttribute,
		removeAttribute,
		get_children,
		get_type,
		get_text,
		put_text,
		addChild,
		removeChild,
		get_attributes,

		VTableSize,
	};

	enum class IXMLAttribute : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDispatch */
		GetTypeInfoCount,
		GetTypeInfo,
		GetIDsOfNames,
		Invoke,

		/* IXMLAttribute */
		get_name,
		get_value,

		VTableSize,
	};

	enum class IXMLError : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IXMLError */
		GetErrorInfo,

		VTableSize,
	};

	enum class IPersistMoniker : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IPersistMoniker */
		GetClassID,
		IsDirty,
		Load,
		Save,
		SaveCompleted,
		GetCurMoniker,

		VTableSize,
	};

	enum class IMonikerProp : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IMonikerProp */
		PutProperty,

		VTableSize,
	};

	enum class IBindProtocol : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IBindProtocol */
		CreateBinding,

		VTableSize,
	};

	enum class IBinding : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IBinding */
		Abort,
		Suspend,
		Resume,
		SetPriority,
		GetPriority,
		GetBindResult,

		VTableSize,
	};

	enum class IBindStatusCallback : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IBindStatusCallback */
		OnStartBinding,
		GetPriority,
		OnLowResource,
		OnProgress,
		OnStopBinding,
		GetBindInfo,
		OnDataAvailable,
		OnObjectAvailable,

		VTableSize,
	};

	enum class IBindStatusCallbackEx : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IBindStatusCallback */
		OnStartBinding,
		GetPriority,
		OnLowResource,
		OnProgress,
		OnStopBinding,
		GetBindInfo,
		OnDataAvailable,
		OnObjectAvailable,

		/* IBindStatusCallbackEx */
		GetBindInfoEx,

		VTableSize,
	};

	enum class IAuthenticate : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IAuthenticate */
		Authenticate,

		VTableSize,
	};

	enum class IAuthenticateEx : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IAuthenticate */
		Authenticate,

		/* IAuthenticateEx */
		AuthenticateEx,

		VTableSize,
	};

	enum class IHttpNegotiate : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IHttpNegotiate */
		BeginningTransaction,
		OnResponse,

		VTableSize,
	};

	enum class IHttpNegotiate2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IHttpNegotiate */
		BeginningTransaction,
		OnResponse,

		/* IHttpNegotiate2 */
		GetRootSecurityId,

		VTableSize,
	};

	enum class IHttpNegotiate3 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IHttpNegotiate */
		BeginningTransaction,
		OnResponse,

		/* IHttpNegotiate2 */
		GetRootSecurityId,

		/* IHttpNegotiate3 */
		GetSerializedClientCertContext,

		VTableSize,
	};

	enum class IWinInetFileStream : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IWinInetFileStream */
		SetHandleForUnlock,
		SetDeleteFile,

		VTableSize,
	};

	enum class IWindowForBindingUI : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IWindowForBindingUI */
		GetWindow,

		VTableSize,
	};

	enum class ICodeInstall : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IWindowForBindingUI */
		GetWindow,

		/* ICodeInstall */
		OnCodeInstallProblem,

		VTableSize,
	};

	enum class IUri : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IUri */
		GetPropertyBSTR,
		GetPropertyLength,
		GetPropertyDWORD,
		HasProperty,
		GetAbsoluteUri,
		GetAuthority,
		GetDisplayUri,
		GetDomain,
		GetExtension,
		GetFragment,
		GetHost,
		GetPassword,
		GetPath,
		GetPathAndQuery,
		GetQuery,
		GetRawUri,
		GetSchemeName,
		GetUserInfo,
		GetUserNameA,
		GetHostType,
		GetPort,
		GetScheme,
		GetZone,
		GetProperties,
		IsEqual,

		VTableSize,
	};

	enum class IUriContainer : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IUriContainer */
		GetIUri,

		VTableSize,
	};

	enum class IUriBuilder : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IUriBuilder */
		CreateUriSimple,
		CreateUri,
		CreateUriWithFlags,
		GetIUri,
		SetIUri,
		GetFragment,
		GetHost,
		GetPassword,
		GetPath,
		GetPort,
		GetQuery,
		GetSchemeName,
		GetUserNameA,
		SetFragment,
		SetHost,
		SetPassword,
		SetPath,
		SetPortA,
		SetQuery,
		SetSchemeName,
		SetUserName,
		RemoveProperties,
		HasBeenModified,

		VTableSize,
	};

	enum class IUriBuilderFactory : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IUriBuilderFactory */
		CreateIUriBuilder,
		CreateInitializedIUriBuilder,

		VTableSize,
	};

	enum class IWinInetInfo : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IWinInetInfo */
		QueryOption,

		VTableSize,
	};

	enum class IHttpSecurity : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IWindowForBindingUI */
		GetWindow,

		/* IHttpSecurity */
		OnSecurityProblem,

		VTableSize,
	};

	enum class IWinInetHttpInfo : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IWinInetInfo */
		QueryOption,

		/* IWinInetHttpInfo */
		QueryInfo,

		VTableSize,
	};

	enum class IWinInetHttpTimeouts : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IWinInetHttpTimeouts */
		GetRequestTimeouts,

		VTableSize,
	};

	enum class IWinInetCacheHints : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IWinInetCacheHints */
		SetCacheExtension,

		VTableSize,
	};

	enum class IWinInetCacheHints2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IWinInetCacheHints */
		SetCacheExtension,

		/* IWinInetCacheHints2 */
		SetCacheExtension2,

		VTableSize,
	};

	enum class IBindHost : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IBindHost */
		CreateMoniker,
		MonikerBindToStorage,
		MonikerBindToObject,

		VTableSize,
	};

	enum class IInternetBindInfo : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IInternetBindInfo */
		GetBindInfo,
		GetBindString,

		VTableSize,
	};

	enum class IInternetBindInfoEx : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IInternetBindInfo */
		GetBindInfo,
		GetBindString,

		/* IInternetBindInfoEx */
		GetBindInfoEx,

		VTableSize,
	};

	enum class IInternetProtocolRoot : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IInternetProtocolRoot */
		Start,
		Continue,
		Abort,
		Terminate,
		Suspend,
		Resume,

		VTableSize,
	};

	enum class IInternetProtocol : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IInternetProtocolRoot */
		Start,
		Continue,
		Abort,
		Terminate,
		Suspend,
		Resume,

		/* IInternetProtocol */
		Read,
		Seek,
		LockRequest,
		UnlockRequest,

		VTableSize,
	};

	enum class IInternetProtocolEx : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IInternetProtocolRoot */
		Start,
		Continue,
		Abort,
		Terminate,
		Suspend,
		Resume,

		/* IInternetProtocol */
		Read,
		Seek,
		LockRequest,
		UnlockRequest,

		/* IInternetProtocolEx */
		StartEx,

		VTableSize,
	};

	enum class IInternetProtocolSink : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IInternetProtocolSink */
		Switch,
		ReportProgress,
		ReportData,
		ReportResult,

		VTableSize,
	};

	enum class IInternetProtocolSinkStackable : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IInternetProtocolSinkStackable */
		SwitchSink,
		CommitSwitch,
		RollbackSwitch,

		VTableSize,
	};

	enum class IInternetSession : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IInternetSession */
		RegisterNameSpace,
		UnregisterNameSpace,
		RegisterMimeFilter,
		UnregisterMimeFilter,
		CreateBinding,
		SetSessionOption,
		GetSessionOption,

		VTableSize,
	};

	enum class IInternetThreadSwitch : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IInternetThreadSwitch */
		Prepare,
		Continue,

		VTableSize,
	};

	enum class IInternetPriority : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IInternetPriority */
		SetPriority,
		GetPriority,

		VTableSize,
	};

	enum class IInternetProtocolInfo : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IInternetProtocolInfo */
		ParseUrl,
		CombineUrl,
		CompareUrl,
		QueryInfo,

		VTableSize,
	};

	enum class IInternetSecurityMgrSite : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IInternetSecurityMgrSite */
		GetWindow,
		EnableModeless,

		VTableSize,
	};

	enum class IInternetSecurityManager : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IInternetSecurityManager */
		SetSecuritySite,
		GetSecuritySite,
		MapUrlToZone,
		GetSecurityId,
		ProcessUrlAction,
		QueryCustomPolicy,
		SetZoneMapping,
		GetZoneMappings,

		VTableSize,
	};

	enum class IInternetSecurityManagerEx : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IInternetSecurityManager */
		SetSecuritySite,
		GetSecuritySite,
		MapUrlToZone,
		GetSecurityId,
		ProcessUrlAction,
		QueryCustomPolicy,
		SetZoneMapping,
		GetZoneMappings,

		/* IInternetSecurityManagerEx */
		ProcessUrlActionEx,

		VTableSize,
	};

	enum class IInternetSecurityManagerEx2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IInternetSecurityManager */
		SetSecuritySite,
		GetSecuritySite,
		MapUrlToZone,
		GetSecurityId,
		ProcessUrlAction,
		QueryCustomPolicy,
		SetZoneMapping,
		GetZoneMappings,

		/* IInternetSecurityManagerEx */
		ProcessUrlActionEx,

		/* IInternetSecurityManagerEx2 */
		MapUrlToZoneEx2,
		ProcessUrlActionEx2,
		GetSecurityIdEx2,
		QueryCustomPolicyEx2,

		VTableSize,
	};

	enum class IZoneIdentifier : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IZoneIdentifier */
		GetId,
		SetId,
		Remove,

		VTableSize,
	};

	enum class IZoneIdentifier2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IZoneIdentifier */
		GetId,
		SetId,
		Remove,

		/* IZoneIdentifier2 */
		GetLastWriterPackageFamilyName,
		SetLastWriterPackageFamilyName,
		RemoveLastWriterPackageFamilyName,
		GetAppZoneId,
		SetAppZoneId,
		RemoveAppZoneId,

		VTableSize,
	};

	enum class IInternetHostSecurityManager : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IInternetHostSecurityManager */
		GetSecurityId,
		ProcessUrlAction,
		QueryCustomPolicy,

		VTableSize,
	};

	enum class IInternetZoneManager : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IInternetZoneManager */
		GetZoneAttributes,
		SetZoneAttributes,
		GetZoneCustomPolicy,
		SetZoneCustomPolicy,
		GetZoneActionPolicy,
		SetZoneActionPolicy,
		PromptAction,
		LogAction,
		CreateZoneEnumerator,
		GetZoneAt,
		DestroyZoneEnumerator,
		CopyTemplatePoliciesToZone,

		VTableSize,
	};

	enum class IInternetZoneManagerEx : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IInternetZoneManager */
		GetZoneAttributes,
		SetZoneAttributes,
		GetZoneCustomPolicy,
		SetZoneCustomPolicy,
		GetZoneActionPolicy,
		SetZoneActionPolicy,
		PromptAction,
		LogAction,
		CreateZoneEnumerator,
		GetZoneAt,
		DestroyZoneEnumerator,
		CopyTemplatePoliciesToZone,

		/* IInternetZoneManagerEx */
		GetZoneActionPolicyEx,
		SetZoneActionPolicyEx,

		VTableSize,
	};

	enum class IInternetZoneManagerEx2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IInternetZoneManager */
		GetZoneAttributes,
		SetZoneAttributes,
		GetZoneCustomPolicy,
		SetZoneCustomPolicy,
		GetZoneActionPolicy,
		SetZoneActionPolicy,
		PromptAction,
		LogAction,
		CreateZoneEnumerator,
		GetZoneAt,
		DestroyZoneEnumerator,
		CopyTemplatePoliciesToZone,

		/* IInternetZoneManagerEx */
		GetZoneActionPolicyEx,
		SetZoneActionPolicyEx,

		/* IInternetZoneManagerEx2 */
		GetZoneAttributesEx,
		GetZoneSecurityState,
		GetIESecurityState,
		FixUnsecureSettings,

		VTableSize,
	};

	enum class ISoftDistExt : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ISoftDistExt */
		ProcessSoftDist,
		GetFirstCodeBase,
		GetNextCodeBase,
		AsyncInstallDistributionUnit,

		VTableSize,
	};

	enum class ICatalogFileInfo : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ICatalogFileInfo */
		GetCatalogFile,
		GetJavaTrust,

		VTableSize,
	};

	enum class IDataFilter : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDataFilter */
		DoEncode,
		DoDecode,
		SetEncodingLevel,

		VTableSize,
	};

	enum class IEncodingFilterFactory : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IEncodingFilterFactory */
		FindBestFilter,
		GetDefaultFilter,

		VTableSize,
	};

	enum class IWrappedProtocol : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IWrappedProtocol */
		GetWrapperCode,

		VTableSize,
	};

	enum class IGetBindHandle : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IGetBindHandle */
		GetBindHandle,

		VTableSize,
	};

	enum class IBindCallbackRedirect : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IBindCallbackRedirect */
		Redirect,

		VTableSize,
	};

	enum class IBindHttpSecurity : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IBindHttpSecurity */
		GetIgnoreCertMask,

		VTableSize,
	};

	enum class IPrintDialogCallback : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IPrintDialogCallback */
		//QueryInterface,
		//AddRef,
		//Release,
		InitDone,
		SelectionChange,
		HandleMessage,

		VTableSize,
	};

	enum class IPrintDialogServices : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IPrintDialogServices */
		//QueryInterface,
		//AddRef,
		//Release,
		GetCurrentDevMode,
		GetCurrentPrinterName,
		GetCurrentPortName,

		VTableSize,
	};

	enum class IEnumConnections : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IEnumConnections */
		Next,
		Skip,
		Reset,
		Clone,

		VTableSize,
	};

	enum class IConnectionPoint : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IConnectionPoint */
		GetConnectionInterface,
		GetConnectionPointContainer,
		Advise,
		Unadvise,
		EnumConnections,

		VTableSize,
	};

	enum class IEnumConnectionPoints : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IEnumConnectionPoints */
		Next,
		Skip,
		Reset,
		Clone,

		VTableSize,
	};

	enum class IConnectionPointContainer : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IConnectionPointContainer */
		EnumConnectionPoints,
		FindConnectionPoint,

		VTableSize,
	};

	enum class IClassFactory2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IClassFactory */
		CreateInstance,
		LockServer,

		/* IClassFactory2 */
		GetLicInfo,
		RequestLicKey,
		CreateInstanceLic,

		VTableSize,
	};

	enum class IProvideClassInfo : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IProvideClassInfo */
		GetClassInfoA,

		VTableSize,
	};

	enum class IProvideClassInfo2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IProvideClassInfo */
		GetClassInfoA,

		/* IProvideClassInfo2 */
		GetGUID,

		VTableSize,
	};

	enum class IProvideMultipleClassInfo : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IProvideClassInfo */
		GetClassInfoA,

		/* IProvideClassInfo2 */
		GetGUID,

		/* IProvideMultipleClassInfo */
		GetMultiTypeInfoCount,
		GetInfoOfIndex,

		VTableSize,
	};

	enum class IOleControl : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IOleControl */
		GetControlInfo,
		OnMnemonic,
		OnAmbientPropertyChange,
		FreezeEvents,

		VTableSize,
	};

	enum class IOleControlSite : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IOleControlSite */
		OnControlInfoChanged,
		LockInPlaceActive,
		GetExtendedControl,
		TransformCoords,
		TranslateAcceleratorA,
		OnFocus,
		ShowPropertyFrame,

		VTableSize,
	};

	enum class IPropertyPage : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IPropertyPage */
		SetPageSite,
		Activate,
		Deactivate,
		GetPageInfo,
		SetObjects,
		Show,
		Move,
		IsPageDirty,
		Apply,
		Help,
		TranslateAcceleratorA,

		VTableSize,
	};

	enum class IPropertyPage2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IPropertyPage */
		SetPageSite,
		Activate,
		Deactivate,
		GetPageInfo,
		SetObjects,
		Show,
		Move,
		IsPageDirty,
		Apply,
		Help,
		TranslateAcceleratorA,

		/* IPropertyPage2 */
		EditProperty,

		VTableSize,
	};

	enum class IPropertyPageSite : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IPropertyPageSite */
		OnStatusChange,
		GetLocaleID,
		GetPageContainer,
		TranslateAcceleratorA,

		VTableSize,
	};

	enum class IPropertyNotifySink : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IPropertyNotifySink */
		OnChanged,
		OnRequestEdit,

		VTableSize,
	};

	enum class ISpecifyPropertyPages : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ISpecifyPropertyPages */
		GetPages,

		VTableSize,
	};

	enum class IPersistMemory : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IPersist */
		GetClassID,

		/* IPersistMemory */
		IsDirty,
		Load,
		Save,
		GetSizeMax,
		InitNew,

		VTableSize,
	};

	enum class IPersistStreamInit : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IPersist */
		GetClassID,

		/* IPersistStreamInit */
		IsDirty,
		Load,
		Save,
		GetSizeMax,
		InitNew,

		VTableSize,
	};

	enum class IPersistPropertyBag : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IPersist */
		GetClassID,

		/* IPersistPropertyBag */
		InitNew,
		Load,
		Save,

		VTableSize,
	};

	enum class ISimpleFrameSite : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ISimpleFrameSite */
		PreMessageFilter,
		PostMessageFilter,

		VTableSize,
	};

	enum class IFont : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IFont */
		get_Name,
		put_Name,
		get_Size,
		put_Size,
		get_Bold,
		put_Bold,
		get_Italic,
		put_Italic,
		get_Underline,
		put_Underline,
		get_Strikethrough,
		put_Strikethrough,
		get_Weight,
		put_Weight,
		get_Charset,
		put_Charset,
		get_hFont,
		Clone,
		IsEqual,
		SetRatio,
		QueryTextMetrics,
		AddRefHfont,
		ReleaseHfont,
		SetHdc,

		VTableSize,
	};

	enum class IPicture : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IPicture */
		get_Handle,
		get_hPal,
		get_Type,
		get_Width,
		get_Height,
		Render,
		set_hPal,
		get_CurDC,
		SelectPicture,
		get_KeepOriginalFormat,
		put_KeepOriginalFormat,
		PictureChanged,
		SaveAsFile,
		get_Attributes,

		VTableSize,
	};

	enum class IPicture2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IPicture2 */
		get_Handle,
		get_hPal,
		get_Type,
		get_Width,
		get_Height,
		Render,
		set_hPal,
		get_CurDC,
		SelectPicture,
		get_KeepOriginalFormat,
		put_KeepOriginalFormat,
		PictureChanged,
		SaveAsFile,
		get_Attributes,

		VTableSize,
	};

	enum class IOleInPlaceObjectWindowless : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IOleWindow */
		GetWindow,
		ContextSensitiveHelp,

		/* IOleInPlaceObject */
		InPlaceDeactivate,
		UIDeactivate,
		SetObjectRects,
		ReactivateAndUndo,

		/* IOleInPlaceObjectWindowless */
		OnWindowMessage,
		GetDropTarget,

		VTableSize,
	};

	enum class IOleInPlaceSiteEx : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IOleWindow */
		GetWindow,
		ContextSensitiveHelp,

		/* IOleInPlaceSite */
		CanInPlaceActivate,
		OnInPlaceActivate,
		OnUIActivate,
		GetWindowContext,
		Scroll,
		OnUIDeactivate,
		OnInPlaceDeactivate,
		DiscardUndoState,
		DeactivateAndUndo,
		OnPosRectChange,

		/* IOleInPlaceSiteEx */
		OnInPlaceActivateEx,
		OnInPlaceDeactivateEx,
		RequestUIActivate,

		VTableSize,
	};

	enum class IOleInPlaceSiteWindowless : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IOleWindow */
		GetWindow,
		ContextSensitiveHelp,

		/* IOleInPlaceSite */
		CanInPlaceActivate,
		OnInPlaceActivate,
		OnUIActivate,
		GetWindowContext,
		Scroll,
		OnUIDeactivate,
		OnInPlaceDeactivate,
		DiscardUndoState,
		DeactivateAndUndo,
		OnPosRectChange,

		/* IOleInPlaceSiteEx */
		OnInPlaceActivateEx,
		OnInPlaceDeactivateEx,
		RequestUIActivate,

		/* IOleInPlaceSiteWindowless */
		CanWindowlessActivate,
		GetCapture,
		SetCapture,
		GetFocus,
		SetFocus,
		GetDC,
		ReleaseDC,
		InvalidateRect,
		InvalidateRgn,
		ScrollRect,
		AdjustRect,
		OnDefWindowMessage,

		VTableSize,
	};

	enum class IViewObjectEx : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IViewObject */
		Draw,
		GetColorSet,
		Freeze,
		Unfreeze,
		SetAdvise,
		GetAdvise,

		/* IViewObject2 */
		GetExtent,

		/* IViewObjectEx */
		GetRect,
		GetViewStatus,
		QueryHitPoint,
		QueryHitRect,
		GetNaturalExtent,

		VTableSize,
	};

	enum class IOleUndoUnit : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IOleUndoUnit */
		Do,
		GetDescription,
		GetUnitType,
		OnNextAdd,

		VTableSize,
	};

	enum class IOleParentUndoUnit : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IOleUndoUnit */
		Do,
		GetDescription,
		GetUnitType,
		OnNextAdd,

		/* IOleParentUndoUnit */
		Open,
		Close,
		Add,
		FindUnit,
		GetParentState,

		VTableSize,
	};

	enum class IEnumOleUndoUnits : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IEnumOleUndoUnits */
		Next,
		Skip,
		Reset,
		Clone,

		VTableSize,
	};

	enum class IOleUndoManager : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IOleUndoManager */
		Open,
		Close,
		Add,
		GetOpenParentState,
		DiscardFrom,
		UndoTo,
		RedoTo,
		EnumUndoable,
		EnumRedoable,
		GetLastUndoDescription,
		GetLastRedoDescription,
		Enable,

		VTableSize,
	};

	enum class IPointerInactive : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IPointerInactive */
		GetActivationPolicy,
		OnInactiveMouseMove,
		OnInactiveSetCursor,

		VTableSize,
	};

	enum class IObjectWithSite : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IObjectWithSite */
		SetSite,
		GetSite,

		VTableSize,
	};

	enum class IPerPropertyBrowsing : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IPerPropertyBrowsing */
		GetDisplayString,
		MapPropertyToPage,
		GetPredefinedStrings,
		GetPredefinedValue,

		VTableSize,
	};

	enum class IPropertyBag2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IPropertyBag2 */
		Read,
		Write,
		CountProperties,
		GetPropertyInfo,
		LoadObject,

		VTableSize,
	};

	enum class IPersistPropertyBag2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IPersist */
		GetClassID,

		/* IPersistPropertyBag2 */
		InitNew,
		Load,
		Save,
		IsDirty,

		VTableSize,
	};

	enum class IAdviseSinkEx : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IAdviseSink */
		OnDataChange,
		OnViewChange,
		OnRename,
		OnSave,
		OnClose,

		/* IAdviseSinkEx */
		OnViewStatusChange,

		VTableSize,
	};

	enum class IQuickActivate : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IQuickActivate */
		QuickActivate,
		SetContentExtent,
		GetContentExtent,

		VTableSize,
	};

	enum class IDXGIObject : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		VTableSize,
	};

	enum class IDXGIDeviceSubObject : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIDeviceSubObject */
		GetDevice,

		VTableSize,
	};

	enum class IDXGIResource : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIDeviceSubObject */
		GetDevice,

		/* IDXGIResource */
		GetSharedHandle,
		GetUsage,
		SetEvictionPriority,
		GetEvictionPriority,

		VTableSize,
	};

	enum class IDXGIKeyedMutex : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIDeviceSubObject */
		GetDevice,

		/* IDXGIKeyedMutex */
		AcquireSync,
		ReleaseSync,

		VTableSize,
	};

	enum class IDXGISurface : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIDeviceSubObject */
		GetDevice,

		/* IDXGISurface */
		GetDesc,
		Map,
		Unmap,

		VTableSize,
	};

	enum class IDXGISurface1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIDeviceSubObject */
		GetDevice,

		/* IDXGISurface */
		GetDesc,
		Map,
		Unmap,

		/* IDXGISurface1 */
		GetDC,
		ReleaseDC,

		VTableSize,
	};

	enum class IDXGIAdapter : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIAdapter */
		EnumOutputs,
		GetDesc,
		CheckInterfaceSupport,

		VTableSize,
	};

	enum class IDXGIOutput : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIOutput */
		GetDesc,
		GetDisplayModeList,
		FindClosestMatchingMode,
		WaitForVBlank,
		TakeOwnership,
		ReleaseOwnership,
		GetGammaControlCapabilities,
		SetGammaControl,
		GetGammaControl,
		SetDisplaySurface,
		GetDisplaySurfaceData,
		GetFrameStatistics,

		VTableSize,
	};

	enum class IDXGISwapChain : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIDeviceSubObject */
		GetDevice,

		/* IDXGISwapChain */
		Present,
		GetBuffer,
		SetFullscreenState,
		GetFullscreenState,
		GetDesc,
		ResizeBuffers,
		ResizeTarget,
		GetContainingOutput,
		GetFrameStatistics,
		GetLastPresentCount,

		VTableSize,
	};

	enum class IDXGIFactory : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIFactory */
		EnumAdapters,
		MakeWindowAssociation,
		GetWindowAssociation,
		CreateSwapChain,
		CreateSoftwareAdapter,

		VTableSize,
	};

	enum class IDXGIDevice : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIDevice */
		GetAdapter,
		CreateSurface,
		QueryResourceResidency,
		SetGPUThreadPriority,
		GetGPUThreadPriority,

		VTableSize,
	};

	enum class IDXGIFactory1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIFactory */
		EnumAdapters,
		MakeWindowAssociation,
		GetWindowAssociation,
		CreateSwapChain,
		CreateSoftwareAdapter,

		/* IDXGIFactory1 */
		EnumAdapters1,
		IsCurrent,

		VTableSize,
	};

	enum class IDXGIAdapter1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIAdapter */
		EnumOutputs,
		GetDesc,
		CheckInterfaceSupport,

		/* IDXGIAdapter1 */
		GetDesc1,

		VTableSize,
	};

	enum class IDXGIDevice1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIDevice */
		GetAdapter,
		CreateSurface,
		QueryResourceResidency,
		SetGPUThreadPriority,
		GetGPUThreadPriority,

		/* IDXGIDevice1 */
		SetMaximumFrameLatency,
		GetMaximumFrameLatency,

		VTableSize,
	};

	enum class IDXGIDisplayControl : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIDisplayControl */
		IsStereoEnabled,
		SetStereoEnabled,

		VTableSize,
	};

	enum class IDXGIOutputDuplication : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIOutputDuplication */
		GetDesc,
		AcquireNextFrame,
		GetFrameDirtyRects,
		GetFrameMoveRects,
		GetFramePointerShape,
		MapDesktopSurface,
		UnMapDesktopSurface,
		ReleaseFrame,

		VTableSize,
	};

	enum class IDXGISurface2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIDeviceSubObject */
		GetDevice,

		/* IDXGISurface */
		GetDesc,
		Map,
		Unmap,

		/* IDXGISurface1 */
		GetDC,
		ReleaseDC,

		/* IDXGISurface2 */
		GetResource,

		VTableSize,
	};

	enum class IDXGIResource1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIDeviceSubObject */
		GetDevice,

		/* IDXGIResource */
		GetSharedHandle,
		GetUsage,
		SetEvictionPriority,
		GetEvictionPriority,

		/* IDXGIResource1 */
		CreateSubresourceSurface,
		CreateSharedHandle,

		VTableSize,
	};

	enum class IDXGIDevice2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIDevice */
		GetAdapter,
		CreateSurface,
		QueryResourceResidency,
		SetGPUThreadPriority,
		GetGPUThreadPriority,

		/* IDXGIDevice1 */
		SetMaximumFrameLatency,
		GetMaximumFrameLatency,

		/* IDXGIDevice2 */
		OfferResources,
		ReclaimResources,
		EnqueueSetEvent,

		VTableSize,
	};

	enum class IDXGISwapChain1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIDeviceSubObject */
		GetDevice,

		/* IDXGISwapChain */
		Present,
		GetBuffer,
		SetFullscreenState,
		GetFullscreenState,
		GetDesc,
		ResizeBuffers,
		ResizeTarget,
		GetContainingOutput,
		GetFrameStatistics,
		GetLastPresentCount,

		/* IDXGISwapChain1 */
		GetDesc1,
		GetFullscreenDesc,
		GetHwnd,
		GetCoreWindow,
		Present1,
		IsTemporaryMonoSupported,
		GetRestrictToOutput,
		SetBackgroundColor,
		GetBackgroundColor,
		SetRotation,
		GetRotation,

		VTableSize,
	};

	enum class IDXGIFactory2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIFactory */
		EnumAdapters,
		MakeWindowAssociation,
		GetWindowAssociation,
		CreateSwapChain,
		CreateSoftwareAdapter,

		/* IDXGIFactory1 */
		EnumAdapters1,
		IsCurrent,

		/* IDXGIFactory2 */
		IsWindowedStereoEnabled,
		CreateSwapChainForHwnd,
		CreateSwapChainForCoreWindow,
		GetSharedResourceAdapterLuid,
		RegisterStereoStatusWindow,
		RegisterStereoStatusEvent,
		UnregisterStereoStatus,
		RegisterOcclusionStatusWindow,
		RegisterOcclusionStatusEvent,
		UnregisterOcclusionStatus,
		CreateSwapChainForComposition,

		VTableSize,
	};

	enum class IDXGIAdapter2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIAdapter */
		EnumOutputs,
		GetDesc,
		CheckInterfaceSupport,

		/* IDXGIAdapter1 */
		GetDesc1,

		/* IDXGIAdapter2 */
		GetDesc2,

		VTableSize,
	};

	enum class IDXGIOutput1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIOutput */
		GetDesc,
		GetDisplayModeList,
		FindClosestMatchingMode,
		WaitForVBlank,
		TakeOwnership,
		ReleaseOwnership,
		GetGammaControlCapabilities,
		SetGammaControl,
		GetGammaControl,
		SetDisplaySurface,
		GetDisplaySurfaceData,
		GetFrameStatistics,

		/* IDXGIOutput1 */
		GetDisplayModeList1,
		FindClosestMatchingMode1,
		GetDisplaySurfaceData1,
		DuplicateOutput,

		VTableSize,
	};

	enum class IDXGIDevice3 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIDevice */
		GetAdapter,
		CreateSurface,
		QueryResourceResidency,
		SetGPUThreadPriority,
		GetGPUThreadPriority,

		/* IDXGIDevice1 */
		SetMaximumFrameLatency,
		GetMaximumFrameLatency,

		/* IDXGIDevice2 */
		OfferResources,
		ReclaimResources,
		EnqueueSetEvent,

		/* IDXGIDevice3 */
		Trim,

		VTableSize,
	};

	enum class IDXGISwapChain2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIDeviceSubObject */
		GetDevice,

		/* IDXGISwapChain */
		Present,
		GetBuffer,
		SetFullscreenState,
		GetFullscreenState,
		GetDesc,
		ResizeBuffers,
		ResizeTarget,
		GetContainingOutput,
		GetFrameStatistics,
		GetLastPresentCount,

		/* IDXGISwapChain1 */
		GetDesc1,
		GetFullscreenDesc,
		GetHwnd,
		GetCoreWindow,
		Present1,
		IsTemporaryMonoSupported,
		GetRestrictToOutput,
		SetBackgroundColor,
		GetBackgroundColor,
		SetRotation,
		GetRotation,

		/* IDXGISwapChain2 */
		SetSourceSize,
		GetSourceSize,
		SetMaximumFrameLatency,
		GetMaximumFrameLatency,
		GetFrameLatencyWaitableObject,
		SetMatrixTransform,
		GetMatrixTransform,

		VTableSize,
	};

	enum class IDXGIOutput2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIOutput */
		GetDesc,
		GetDisplayModeList,
		FindClosestMatchingMode,
		WaitForVBlank,
		TakeOwnership,
		ReleaseOwnership,
		GetGammaControlCapabilities,
		SetGammaControl,
		GetGammaControl,
		SetDisplaySurface,
		GetDisplaySurfaceData,
		GetFrameStatistics,

		/* IDXGIOutput1 */
		GetDisplayModeList1,
		FindClosestMatchingMode1,
		GetDisplaySurfaceData1,
		DuplicateOutput,

		/* IDXGIOutput2 */
		SupportsOverlays,

		VTableSize,
	};

	enum class IDXGIFactory3 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIFactory */
		EnumAdapters,
		MakeWindowAssociation,
		GetWindowAssociation,
		CreateSwapChain,
		CreateSoftwareAdapter,

		/* IDXGIFactory1 */
		EnumAdapters1,
		IsCurrent,

		/* IDXGIFactory2 */
		IsWindowedStereoEnabled,
		CreateSwapChainForHwnd,
		CreateSwapChainForCoreWindow,
		GetSharedResourceAdapterLuid,
		RegisterStereoStatusWindow,
		RegisterStereoStatusEvent,
		UnregisterStereoStatus,
		RegisterOcclusionStatusWindow,
		RegisterOcclusionStatusEvent,
		UnregisterOcclusionStatus,
		CreateSwapChainForComposition,

		/* IDXGIFactory3 */
		GetCreationFlags,

		VTableSize,
	};

	enum class IDXGIDecodeSwapChain : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIDecodeSwapChain */
		PresentBuffer,
		SetSourceRect,
		SetTargetRect,
		SetDestSize,
		GetSourceRect,
		GetTargetRect,
		GetDestSize,
		SetColorSpace,
		GetColorSpace,

		VTableSize,
	};

	enum class IDXGIFactoryMedia : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIFactoryMedia */
		CreateSwapChainForCompositionSurfaceHandle,
		CreateDecodeSwapChainForCompositionSurfaceHandle,

		VTableSize,
	};

	enum class IDXGISwapChainMedia : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGISwapChainMedia */
		GetFrameStatisticsMedia,
		SetPresentDuration,
		CheckPresentDurationSupport,

		VTableSize,
	};

	enum class IDXGIOutput3 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIOutput */
		GetDesc,
		GetDisplayModeList,
		FindClosestMatchingMode,
		WaitForVBlank,
		TakeOwnership,
		ReleaseOwnership,
		GetGammaControlCapabilities,
		SetGammaControl,
		GetGammaControl,
		SetDisplaySurface,
		GetDisplaySurfaceData,
		GetFrameStatistics,

		/* IDXGIOutput1 */
		GetDisplayModeList1,
		FindClosestMatchingMode1,
		GetDisplaySurfaceData1,
		DuplicateOutput,

		/* IDXGIOutput2 */
		SupportsOverlays,

		/* IDXGIOutput3 */
		CheckOverlaySupport,

		VTableSize,
	};

	enum class IDXGISwapChain3 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIDeviceSubObject */
		GetDevice,

		/* IDXGISwapChain */
		Present,
		GetBuffer,
		SetFullscreenState,
		GetFullscreenState,
		GetDesc,
		ResizeBuffers,
		ResizeTarget,
		GetContainingOutput,
		GetFrameStatistics,
		GetLastPresentCount,

		/* IDXGISwapChain1 */
		GetDesc1,
		GetFullscreenDesc,
		GetHwnd,
		GetCoreWindow,
		Present1,
		IsTemporaryMonoSupported,
		GetRestrictToOutput,
		SetBackgroundColor,
		GetBackgroundColor,
		SetRotation,
		GetRotation,

		/* IDXGISwapChain2 */
		SetSourceSize,
		GetSourceSize,
		SetMaximumFrameLatency,
		GetMaximumFrameLatency,
		GetFrameLatencyWaitableObject,
		SetMatrixTransform,
		GetMatrixTransform,

		/* IDXGISwapChain3 */
		GetCurrentBackBufferIndex,
		CheckColorSpaceSupport,
		SetColorSpace1,
		ResizeBuffers1,

		VTableSize,
	};

	enum class IDXGIOutput4 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIOutput */
		GetDesc,
		GetDisplayModeList,
		FindClosestMatchingMode,
		WaitForVBlank,
		TakeOwnership,
		ReleaseOwnership,
		GetGammaControlCapabilities,
		SetGammaControl,
		GetGammaControl,
		SetDisplaySurface,
		GetDisplaySurfaceData,
		GetFrameStatistics,

		/* IDXGIOutput1 */
		GetDisplayModeList1,
		FindClosestMatchingMode1,
		GetDisplaySurfaceData1,
		DuplicateOutput,

		/* IDXGIOutput2 */
		SupportsOverlays,

		/* IDXGIOutput3 */
		CheckOverlaySupport,

		/* IDXGIOutput4 */
		CheckOverlayColorSpaceSupport,

		VTableSize,
	};

	enum class IDXGIFactory4 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIFactory */
		EnumAdapters,
		MakeWindowAssociation,
		GetWindowAssociation,
		CreateSwapChain,
		CreateSoftwareAdapter,

		/* IDXGIFactory1 */
		EnumAdapters1,
		IsCurrent,

		/* IDXGIFactory2 */
		IsWindowedStereoEnabled,
		CreateSwapChainForHwnd,
		CreateSwapChainForCoreWindow,
		GetSharedResourceAdapterLuid,
		RegisterStereoStatusWindow,
		RegisterStereoStatusEvent,
		UnregisterStereoStatus,
		RegisterOcclusionStatusWindow,
		RegisterOcclusionStatusEvent,
		UnregisterOcclusionStatus,
		CreateSwapChainForComposition,

		/* IDXGIFactory3 */
		GetCreationFlags,

		/* IDXGIFactory4 */
		EnumAdapterByLuid,
		EnumWarpAdapter,

		VTableSize,
	};

	enum class IDXGIAdapter3 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIAdapter */
		EnumOutputs,
		GetDesc,
		CheckInterfaceSupport,

		/* IDXGIAdapter1 */
		GetDesc1,

		/* IDXGIAdapter2 */
		GetDesc2,

		/* IDXGIAdapter3 */
		RegisterHardwareContentProtectionTeardownStatusEvent,
		UnregisterHardwareContentProtectionTeardownStatus,
		QueryVideoMemoryInfo,
		SetVideoMemoryReservation,
		RegisterVideoMemoryBudgetChangeNotificationEvent,
		UnregisterVideoMemoryBudgetChangeNotification,

		VTableSize,
	};

	enum class IDXGIOutput5 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIOutput */
		GetDesc,
		GetDisplayModeList,
		FindClosestMatchingMode,
		WaitForVBlank,
		TakeOwnership,
		ReleaseOwnership,
		GetGammaControlCapabilities,
		SetGammaControl,
		GetGammaControl,
		SetDisplaySurface,
		GetDisplaySurfaceData,
		GetFrameStatistics,

		/* IDXGIOutput1 */
		GetDisplayModeList1,
		FindClosestMatchingMode1,
		GetDisplaySurfaceData1,
		DuplicateOutput,

		/* IDXGIOutput2 */
		SupportsOverlays,

		/* IDXGIOutput3 */
		CheckOverlaySupport,

		/* IDXGIOutput4 */
		CheckOverlayColorSpaceSupport,

		/* IDXGIOutput5 */
		DuplicateOutput1,

		VTableSize,
	};

	enum class IDXGISwapChain4 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIDeviceSubObject */
		GetDevice,

		/* IDXGISwapChain */
		Present,
		GetBuffer,
		SetFullscreenState,
		GetFullscreenState,
		GetDesc,
		ResizeBuffers,
		ResizeTarget,
		GetContainingOutput,
		GetFrameStatistics,
		GetLastPresentCount,

		/* IDXGISwapChain1 */
		GetDesc1,
		GetFullscreenDesc,
		GetHwnd,
		GetCoreWindow,
		Present1,
		IsTemporaryMonoSupported,
		GetRestrictToOutput,
		SetBackgroundColor,
		GetBackgroundColor,
		SetRotation,
		GetRotation,

		/* IDXGISwapChain2 */
		SetSourceSize,
		GetSourceSize,
		SetMaximumFrameLatency,
		GetMaximumFrameLatency,
		GetFrameLatencyWaitableObject,
		SetMatrixTransform,
		GetMatrixTransform,

		/* IDXGISwapChain3 */
		GetCurrentBackBufferIndex,
		CheckColorSpaceSupport,
		SetColorSpace1,
		ResizeBuffers1,

		/* IDXGISwapChain4 */
		SetHDRMetaData,

		VTableSize,
	};

	enum class IDXGIDevice4 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIDevice */
		GetAdapter,
		CreateSurface,
		QueryResourceResidency,
		SetGPUThreadPriority,
		GetGPUThreadPriority,

		/* IDXGIDevice1 */
		SetMaximumFrameLatency,
		GetMaximumFrameLatency,

		/* IDXGIDevice2 */
		OfferResources,
		ReclaimResources,
		EnqueueSetEvent,

		/* IDXGIDevice3 */
		Trim,

		/* IDXGIDevice4 */
		OfferResources1,
		ReclaimResources1,

		VTableSize,
	};

	enum class IDXGIFactory5 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* IDXGIObject */
		SetPrivateData,
		SetPrivateDataInterface,
		GetPrivateData,
		GetParent,

		/* IDXGIFactory */
		EnumAdapters,
		MakeWindowAssociation,
		GetWindowAssociation,
		CreateSwapChain,
		CreateSoftwareAdapter,

		/* IDXGIFactory1 */
		EnumAdapters1,
		IsCurrent,

		/* IDXGIFactory2 */
		IsWindowedStereoEnabled,
		CreateSwapChainForHwnd,
		CreateSwapChainForCoreWindow,
		GetSharedResourceAdapterLuid,
		RegisterStereoStatusWindow,
		RegisterStereoStatusEvent,
		UnregisterStereoStatus,
		RegisterOcclusionStatusWindow,
		RegisterOcclusionStatusEvent,
		UnregisterOcclusionStatus,
		CreateSwapChainForComposition,

		/* IDXGIFactory3 */
		GetCreationFlags,

		/* IDXGIFactory4 */
		EnumAdapterByLuid,
		EnumWarpAdapter,

		/* IDXGIFactory5 */
		CheckFeatureSupport,

		VTableSize,
	};

	enum class ID3D10Blob : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D10Blob */
		GetBufferPointer,
		GetBufferSize,

		VTableSize,
	};

	enum class ID3DDestructionNotifier : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3DDestructionNotifier */
		RegisterDestructionCallback,
		UnregisterDestructionCallback,

		VTableSize,
	};

	enum class ID3D11DeviceChild : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		VTableSize,
	};

	enum class ID3D11DepthStencilState : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11DepthStencilState */
		GetDesc,

		VTableSize,
	};

	enum class ID3D11BlendState : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11BlendState */
		GetDesc,

		VTableSize,
	};

	enum class ID3D11RasterizerState : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11RasterizerState */
		GetDesc,

		VTableSize,
	};

	enum class ID3D11Resource : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11Resource */
		GetType,
		SetEvictionPriority,
		GetEvictionPriority,

		VTableSize,
	};

	enum class ID3D11Buffer : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11Resource */
		GetType,
		SetEvictionPriority,
		GetEvictionPriority,

		/* ID3D11Buffer */
		GetDesc,

		VTableSize,
	};

	enum class ID3D11Texture1D : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11Resource */
		GetType,
		SetEvictionPriority,
		GetEvictionPriority,

		/* ID3D11Texture1D */
		GetDesc,

		VTableSize,
	};

	enum class ID3D11Texture2D : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11Resource */
		GetType,
		SetEvictionPriority,
		GetEvictionPriority,

		/* ID3D11Texture2D */
		GetDesc,

		VTableSize,
	};

	enum class ID3D11Texture3D : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11Resource */
		GetType,
		SetEvictionPriority,
		GetEvictionPriority,

		/* ID3D11Texture3D */
		GetDesc,

		VTableSize,
	};

	enum class ID3D11View : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11View */
		GetResource,

		VTableSize,
	};

	enum class ID3D11ShaderResourceView : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11View */
		GetResource,

		/* ID3D11ShaderResourceView */
		GetDesc,

		VTableSize,
	};

	enum class ID3D11RenderTargetView : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11View */
		GetResource,

		/* ID3D11RenderTargetView */
		GetDesc,

		VTableSize,
	};

	enum class ID3D11DepthStencilView : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11View */
		GetResource,

		/* ID3D11DepthStencilView */
		GetDesc,

		VTableSize,
	};

	enum class ID3D11UnorderedAccessView : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11View */
		GetResource,

		/* ID3D11UnorderedAccessView */
		GetDesc,

		VTableSize,
	};

	enum class ID3D11SamplerState : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11SamplerState */
		GetDesc,

		VTableSize,
	};

	enum class ID3D11Asynchronous : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11Asynchronous */
		GetDataSize,

		VTableSize,
	};

	enum class ID3D11Query : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11Asynchronous */
		GetDataSize,

		/* ID3D11Query */
		GetDesc,

		VTableSize,
	};

	enum class ID3D11Counter : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11Asynchronous */
		GetDataSize,

		/* ID3D11Counter */
		GetDesc,

		VTableSize,
	};

	enum class ID3D11ClassInstance : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11ClassInstance */
		GetClassLinkage,
		GetDesc,
		GetInstanceName,
		GetTypeName,

		VTableSize,
	};

	enum class ID3D11ClassLinkage : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11ClassLinkage */
		GetClassInstance,
		CreateClassInstance,

		VTableSize,
	};

	enum class ID3D11CommandList : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11CommandList */
		GetContextFlags,

		VTableSize,
	};

	enum class ID3D11DeviceContext : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11DeviceContext */
		VSSetConstantBuffers,
		PSSetShaderResources,
		PSSetShader,
		PSSetSamplers,
		VSSetShader,
		DrawIndexed,
		Draw,
		Map,
		Unmap,
		PSSetConstantBuffers,
		IASetInputLayout,
		IASetVertexBuffers,
		IASetIndexBuffer,
		DrawIndexedInstanced,
		DrawInstanced,
		GSSetConstantBuffers,
		GSSetShader,
		IASetPrimitiveTopology,
		VSSetShaderResources,
		VSSetSamplers,
		Begin,
		End,
		GetData,
		SetPredication,
		GSSetShaderResources,
		GSSetSamplers,
		OMSetRenderTargets,
		OMSetRenderTargetsAndUnorderedAccessViews,
		OMSetBlendState,
		OMSetDepthStencilState,
		SOSetTargets,
		DrawAuto,
		DrawIndexedInstancedIndirect,
		DrawInstancedIndirect,
		Dispatch,
		DispatchIndirect,
		RSSetState,
		RSSetViewports,
		RSSetScissorRects,
		CopySubresourceRegion,
		CopyResource,
		UpdateSubresource,
		CopyStructureCount,
		ClearRenderTargetView,
		ClearUnorderedAccessViewUint,
		ClearUnorderedAccessViewFloat,
		ClearDepthStencilView,
		GenerateMips,
		SetResourceMinLOD,
		GetResourceMinLOD,
		ResolveSubresource,
		ExecuteCommandList,
		HSSetShaderResources,
		HSSetShader,
		HSSetSamplers,
		HSSetConstantBuffers,
		DSSetShaderResources,
		DSSetShader,
		DSSetSamplers,
		DSSetConstantBuffers,
		CSSetShaderResources,
		CSSetUnorderedAccessViews,
		CSSetShader,
		CSSetSamplers,
		CSSetConstantBuffers,
		VSGetConstantBuffers,
		PSGetShaderResources,
		PSGetShader,
		PSGetSamplers,
		VSGetShader,
		PSGetConstantBuffers,
		IAGetInputLayout,
		IAGetVertexBuffers,
		IAGetIndexBuffer,
		GSGetConstantBuffers,
		GSGetShader,
		IAGetPrimitiveTopology,
		VSGetShaderResources,
		VSGetSamplers,
		GetPredication,
		GSGetShaderResources,
		GSGetSamplers,
		OMGetRenderTargets,
		OMGetRenderTargetsAndUnorderedAccessViews,
		OMGetBlendState,
		OMGetDepthStencilState,
		SOGetTargets,
		RSGetState,
		RSGetViewports,
		RSGetScissorRects,
		HSGetShaderResources,
		HSGetShader,
		HSGetSamplers,
		HSGetConstantBuffers,
		DSGetShaderResources,
		DSGetShader,
		DSGetSamplers,
		DSGetConstantBuffers,
		CSGetShaderResources,
		CSGetUnorderedAccessViews,
		CSGetShader,
		CSGetSamplers,
		CSGetConstantBuffers,
		ClearState,
		Flush,
		GetType,
		GetContextFlags,
		FinishCommandList,

		VTableSize,
	};

	enum class ID3D11VideoDecoder : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11VideoDecoder */
		GetCreationParameters,
		GetDriverHandle,

		VTableSize,
	};

	enum class ID3D11VideoProcessorEnumerator : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11VideoProcessorEnumerator */
		GetVideoProcessorContentDesc,
		CheckVideoProcessorFormat,
		GetVideoProcessorCaps,
		GetVideoProcessorRateConversionCaps,
		GetVideoProcessorCustomRate,
		GetVideoProcessorFilterRange,

		VTableSize,
	};

	enum class ID3D11VideoProcessor : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11VideoProcessor */
		GetContentDesc,
		GetRateConversionCaps,

		VTableSize,
	};

	enum class ID3D11AuthenticatedChannel : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11AuthenticatedChannel */
		GetCertificateSize,
		GetCertificate,
		GetChannelHandle,

		VTableSize,
	};

	enum class ID3D11CryptoSession : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11CryptoSession */
		GetCryptoType,
		GetDecoderProfile,
		GetCertificateSize,
		GetCertificate,
		GetCryptoSessionHandle,

		VTableSize,
	};

	enum class ID3D11VideoDecoderOutputView : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11View */
		GetResource,

		/* ID3D11VideoDecoderOutputView */
		GetDesc,

		VTableSize,
	};

	enum class ID3D11VideoProcessorInputView : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11View */
		GetResource,

		/* ID3D11VideoProcessorInputView */
		GetDesc,

		VTableSize,
	};

	enum class ID3D11VideoProcessorOutputView : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11View */
		GetResource,

		/* ID3D11VideoProcessorOutputView */
		GetDesc,

		VTableSize,
	};

	enum class ID3D11VideoContext : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11VideoContext */
		GetDecoderBuffer,
		ReleaseDecoderBuffer,
		DecoderBeginFrame,
		DecoderEndFrame,
		SubmitDecoderBuffers,
		DecoderExtension,
		VideoProcessorSetOutputTargetRect,
		VideoProcessorSetOutputBackgroundColor,
		VideoProcessorSetOutputColorSpace,
		VideoProcessorSetOutputAlphaFillMode,
		VideoProcessorSetOutputConstriction,
		VideoProcessorSetOutputStereoMode,
		VideoProcessorSetOutputExtension,
		VideoProcessorGetOutputTargetRect,
		VideoProcessorGetOutputBackgroundColor,
		VideoProcessorGetOutputColorSpace,
		VideoProcessorGetOutputAlphaFillMode,
		VideoProcessorGetOutputConstriction,
		VideoProcessorGetOutputStereoMode,
		VideoProcessorGetOutputExtension,
		VideoProcessorSetStreamFrameFormat,
		VideoProcessorSetStreamColorSpace,
		VideoProcessorSetStreamOutputRate,
		VideoProcessorSetStreamSourceRect,
		VideoProcessorSetStreamDestRect,
		VideoProcessorSetStreamAlpha,
		VideoProcessorSetStreamPalette,
		VideoProcessorSetStreamPixelAspectRatio,
		VideoProcessorSetStreamLumaKey,
		VideoProcessorSetStreamStereoFormat,
		VideoProcessorSetStreamAutoProcessingMode,
		VideoProcessorSetStreamFilter,
		VideoProcessorSetStreamExtension,
		VideoProcessorGetStreamFrameFormat,
		VideoProcessorGetStreamColorSpace,
		VideoProcessorGetStreamOutputRate,
		VideoProcessorGetStreamSourceRect,
		VideoProcessorGetStreamDestRect,
		VideoProcessorGetStreamAlpha,
		VideoProcessorGetStreamPalette,
		VideoProcessorGetStreamPixelAspectRatio,
		VideoProcessorGetStreamLumaKey,
		VideoProcessorGetStreamStereoFormat,
		VideoProcessorGetStreamAutoProcessingMode,
		VideoProcessorGetStreamFilter,
		VideoProcessorGetStreamExtension,
		VideoProcessorBlt,
		NegotiateCryptoSessionKeyExchange,
		EncryptionBlt,
		DecryptionBlt,
		StartSessionKeyRefresh,
		FinishSessionKeyRefresh,
		GetEncryptionBltKey,
		NegotiateAuthenticatedChannelKeyExchange,
		QueryAuthenticatedChannel,
		ConfigureAuthenticatedChannel,
		VideoProcessorSetStreamRotation,
		VideoProcessorGetStreamRotation,

		VTableSize,
	};

	enum class ID3D11VideoDevice : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11VideoDevice */
		CreateVideoDecoder,
		CreateVideoProcessor,
		CreateAuthenticatedChannel,
		CreateCryptoSession,
		CreateVideoDecoderOutputView,
		CreateVideoProcessorInputView,
		CreateVideoProcessorOutputView,
		CreateVideoProcessorEnumerator,
		GetVideoDecoderProfileCount,
		GetVideoDecoderProfile,
		CheckVideoDecoderFormat,
		GetVideoDecoderConfigCount,
		GetVideoDecoderConfig,
		GetContentProtectionCaps,
		CheckCryptoKeyExchange,
		SetPrivateData,
		SetPrivateDataInterface,

		VTableSize,
	};

	enum class ID3D11Device : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11Device */
		CreateBuffer,
		CreateTexture1D,
		CreateTexture2D,
		CreateTexture3D,
		CreateShaderResourceView,
		CreateUnorderedAccessView,
		CreateRenderTargetView,
		CreateDepthStencilView,
		CreateInputLayout,
		CreateVertexShader,
		CreateGeometryShader,
		CreateGeometryShaderWithStreamOutput,
		CreatePixelShader,
		CreateHullShader,
		CreateDomainShader,
		CreateComputeShader,
		CreateClassLinkage,
		CreateBlendState,
		CreateDepthStencilState,
		CreateRasterizerState,
		CreateSamplerState,
		CreateQuery,
		CreatePredicate,
		CreateCounter,
		CreateDeferredContext,
		OpenSharedResource,
		CheckFormatSupport,
		CheckMultisampleQualityLevels,
		CheckCounterInfo,
		CheckCounter,
		CheckFeatureSupport,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		GetFeatureLevel,
		GetCreationFlags,
		GetDeviceRemovedReason,
		GetImmediateContext,
		SetExceptionMode,
		GetExceptionMode,

		VTableSize,
	};

	enum class ID3D11Debug : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11Debug */
		SetFeatureMask,
		GetFeatureMask,
		SetPresentPerRenderOpDelay,
		GetPresentPerRenderOpDelay,
		SetSwapChain,
		GetSwapChain,
		ValidateContext,
		ReportLiveDeviceObjects,
		ValidateContextForDispatch,

		VTableSize,
	};

	enum class ID3D11SwitchToRef : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11SwitchToRef */
		SetUseRef,
		GetUseRef,

		VTableSize,
	};

	enum class ID3D11TracingDevice : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11TracingDevice */
		SetShaderTrackingOptionsByType,
		SetShaderTrackingOptions,

		VTableSize,
	};

	enum class ID3D11RefTrackingOptions : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11RefTrackingOptions */
		SetTrackingOptions,

		VTableSize,
	};

	enum class ID3D11RefDefaultTrackingOptions : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11RefDefaultTrackingOptions */
		SetTrackingOptions,

		VTableSize,
	};

	enum class ID3D11InfoQueue : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11InfoQueue */
		SetMessageCountLimit,
		ClearStoredMessages,
		GetMessageA,
		GetNumMessagesAllowedByStorageFilter,
		GetNumMessagesDeniedByStorageFilter,
		GetNumStoredMessages,
		GetNumStoredMessagesAllowedByRetrievalFilter,
		GetNumMessagesDiscardedByMessageCountLimit,
		GetMessageCountLimit,
		AddStorageFilterEntries,
		GetStorageFilter,
		ClearStorageFilter,
		PushEmptyStorageFilter,
		PushCopyOfStorageFilter,
		PushStorageFilter,
		PopStorageFilter,
		GetStorageFilterStackSize,
		AddRetrievalFilterEntries,
		GetRetrievalFilter,
		ClearRetrievalFilter,
		PushEmptyRetrievalFilter,
		PushCopyOfRetrievalFilter,
		PushRetrievalFilter,
		PopRetrievalFilter,
		GetRetrievalFilterStackSize,
		AddMessage,
		AddApplicationMessage,
		SetBreakOnCategory,
		SetBreakOnSeverity,
		SetBreakOnID,
		GetBreakOnCategory,
		GetBreakOnSeverity,
		GetBreakOnID,
		SetMuteDebugOutput,
		GetMuteDebugOutput,

		VTableSize,
	};

	enum class ID3D10DeviceChild : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D10DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		VTableSize,
	};

	enum class ID3D10DepthStencilState : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D10DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D10DepthStencilState */
		GetDesc,

		VTableSize,
	};

	enum class ID3D10BlendState : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D10DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D10BlendState */
		GetDesc,

		VTableSize,
	};

	enum class ID3D10RasterizerState : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D10DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D10RasterizerState */
		GetDesc,

		VTableSize,
	};

	enum class ID3D10Resource : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D10DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D10Resource */
		GetType,
		SetEvictionPriority,
		GetEvictionPriority,

		VTableSize,
	};

	enum class ID3D10Buffer : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D10DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D10Resource */
		GetType,
		SetEvictionPriority,
		GetEvictionPriority,

		/* ID3D10Buffer */
		Map,
		Unmap,
		GetDesc,

		VTableSize,
	};

	enum class ID3D10Texture1D : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D10DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D10Resource */
		GetType,
		SetEvictionPriority,
		GetEvictionPriority,

		/* ID3D10Texture1D */
		Map,
		Unmap,
		GetDesc,

		VTableSize,
	};

	enum class ID3D10Texture2D : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D10DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D10Resource */
		GetType,
		SetEvictionPriority,
		GetEvictionPriority,

		/* ID3D10Texture2D */
		Map,
		Unmap,
		GetDesc,

		VTableSize,
	};

	enum class ID3D10Texture3D : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D10DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D10Resource */
		GetType,
		SetEvictionPriority,
		GetEvictionPriority,

		/* ID3D10Texture3D */
		Map,
		Unmap,
		GetDesc,

		VTableSize,
	};

	enum class ID3D10View : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D10DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D10View */
		GetResource,

		VTableSize,
	};

	enum class ID3D10ShaderResourceView : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D10DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D10View */
		GetResource,

		/* ID3D10ShaderResourceView */
		GetDesc,

		VTableSize,
	};

	enum class ID3D10RenderTargetView : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D10DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D10View */
		GetResource,

		/* ID3D10RenderTargetView */
		GetDesc,

		VTableSize,
	};

	enum class ID3D10DepthStencilView : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D10DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D10View */
		GetResource,

		/* ID3D10DepthStencilView */
		GetDesc,

		VTableSize,
	};

	enum class ID3D10SamplerState : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D10DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D10SamplerState */
		GetDesc,

		VTableSize,
	};

	enum class ID3D10Asynchronous : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D10DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D10Asynchronous */
		Begin,
		End,
		GetData,
		GetDataSize,

		VTableSize,
	};

	enum class ID3D10Query : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D10DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D10Asynchronous */
		Begin,
		End,
		GetData,
		GetDataSize,

		/* ID3D10Query */
		GetDesc,

		VTableSize,
	};

	enum class ID3D10Counter : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D10DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D10Asynchronous */
		Begin,
		End,
		GetData,
		GetDataSize,

		/* ID3D10Counter */
		GetDesc,

		VTableSize,
	};

	enum class ID3D10Device : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D10Device */
		VSSetConstantBuffers,
		PSSetShaderResources,
		PSSetShader,
		PSSetSamplers,
		VSSetShader,
		DrawIndexed,
		Draw,
		PSSetConstantBuffers,
		IASetInputLayout,
		IASetVertexBuffers,
		IASetIndexBuffer,
		DrawIndexedInstanced,
		DrawInstanced,
		GSSetConstantBuffers,
		GSSetShader,
		IASetPrimitiveTopology,
		VSSetShaderResources,
		VSSetSamplers,
		SetPredication,
		GSSetShaderResources,
		GSSetSamplers,
		OMSetRenderTargets,
		OMSetBlendState,
		OMSetDepthStencilState,
		SOSetTargets,
		DrawAuto,
		RSSetState,
		RSSetViewports,
		RSSetScissorRects,
		CopySubresourceRegion,
		CopyResource,
		UpdateSubresource,
		ClearRenderTargetView,
		ClearDepthStencilView,
		GenerateMips,
		ResolveSubresource,
		VSGetConstantBuffers,
		PSGetShaderResources,
		PSGetShader,
		PSGetSamplers,
		VSGetShader,
		PSGetConstantBuffers,
		IAGetInputLayout,
		IAGetVertexBuffers,
		IAGetIndexBuffer,
		GSGetConstantBuffers,
		GSGetShader,
		IAGetPrimitiveTopology,
		VSGetShaderResources,
		VSGetSamplers,
		GetPredication,
		GSGetShaderResources,
		GSGetSamplers,
		OMGetRenderTargets,
		OMGetBlendState,
		OMGetDepthStencilState,
		SOGetTargets,
		RSGetState,
		RSGetViewports,
		RSGetScissorRects,
		GetDeviceRemovedReason,
		SetExceptionMode,
		GetExceptionMode,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		ClearState,
		Flush,
		CreateBuffer,
		CreateTexture1D,
		CreateTexture2D,
		CreateTexture3D,
		CreateShaderResourceView,
		CreateRenderTargetView,
		CreateDepthStencilView,
		CreateInputLayout,
		CreateVertexShader,
		CreateGeometryShader,
		CreateGeometryShaderWithStreamOutput,
		CreatePixelShader,
		CreateBlendState,
		CreateDepthStencilState,
		CreateRasterizerState,
		CreateSamplerState,
		CreateQuery,
		CreatePredicate,
		CreateCounter,
		CheckFormatSupport,
		CheckMultisampleQualityLevels,
		CheckCounterInfo,
		CheckCounter,
		GetCreationFlags,
		OpenSharedResource,
		SetTextFilterSize,
		GetTextFilterSize,

		VTableSize,
	};

	enum class ID3D10Multithread : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D10Multithread */
		Enter,
		Leave,
		SetMultithreadProtected,
		GetMultithreadProtected,

		VTableSize,
	};

	enum class ID3D10Debug : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D10Debug */
		SetFeatureMask,
		GetFeatureMask,
		SetPresentPerRenderOpDelay,
		GetPresentPerRenderOpDelay,
		SetSwapChain,
		GetSwapChain,
		Validate,

		VTableSize,
	};

	enum class ID3D10SwitchToRef : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D10SwitchToRef */
		SetUseRef,
		GetUseRef,

		VTableSize,
	};

	enum class ID3D10InfoQueue : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D10InfoQueue */
		SetMessageCountLimit,
		ClearStoredMessages,
		GetMessageA,
		GetNumMessagesAllowedByStorageFilter,
		GetNumMessagesDeniedByStorageFilter,
		GetNumStoredMessages,
		GetNumStoredMessagesAllowedByRetrievalFilter,
		GetNumMessagesDiscardedByMessageCountLimit,
		GetMessageCountLimit,
		AddStorageFilterEntries,
		GetStorageFilter,
		ClearStorageFilter,
		PushEmptyStorageFilter,
		PushCopyOfStorageFilter,
		PushStorageFilter,
		PopStorageFilter,
		GetStorageFilterStackSize,
		AddRetrievalFilterEntries,
		GetRetrievalFilter,
		ClearRetrievalFilter,
		PushEmptyRetrievalFilter,
		PushCopyOfRetrievalFilter,
		PushRetrievalFilter,
		PopRetrievalFilter,
		GetRetrievalFilterStackSize,
		AddMessage,
		AddApplicationMessage,
		SetBreakOnCategory,
		SetBreakOnSeverity,
		SetBreakOnID,
		GetBreakOnCategory,
		GetBreakOnSeverity,
		GetBreakOnID,
		SetMuteDebugOutput,
		GetMuteDebugOutput,

		VTableSize,
	};

	enum class ID3D10StateBlock : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D10StateBlock */
		//QueryInterface,
		//AddRef,
		//Release,
		Capture,
		Apply,
		ReleaseAllDeviceObjects,
		GetDevice,

		VTableSize,
	};

	enum class ID3D10EffectScalarVariable : size_t
	{
		/* ID3D10EffectVariable */
		IsValid,
		GetType,
		GetDesc,
		GetAnnotationByIndex,
		GetAnnotationByName,
		GetMemberByIndex,
		GetMemberByName,
		GetMemberBySemantic,
		GetElement,
		GetParentConstantBuffer,
		AsScalar,
		AsVector,
		AsMatrix,
		AsString,
		AsShaderResource,
		AsRenderTargetView,
		AsDepthStencilView,
		AsConstantBuffer,
		AsShader,
		AsBlend,
		AsDepthStencil,
		AsRasterizer,
		AsSampler,
		SetRawValue,
		GetRawValue,

		/* ID3D10EffectScalarVariable */
		//IsValid,
		//GetType,
		//GetDesc,
		//GetAnnotationByIndex,
		//GetAnnotationByName,
		//GetMemberByIndex,
		//GetMemberByName,
		//GetMemberBySemantic,
		//GetElement,
		//GetParentConstantBuffer,
		//AsScalar,
		//AsVector,
		//AsMatrix,
		//AsString,
		//AsShaderResource,
		//AsRenderTargetView,
		//AsDepthStencilView,
		//AsConstantBuffer,
		//AsShader,
		//AsBlend,
		//AsDepthStencil,
		//AsRasterizer,
		//AsSampler,
		//SetRawValue,
		//GetRawValue,
		SetFloat,
		GetFloat,
		SetFloatArray,
		GetFloatArray,
		SetInt,
		GetInt,
		SetIntArray,
		GetIntArray,
		SetBool,
		GetBool,
		SetBoolArray,
		GetBoolArray,

		VTableSize,
	};

	enum class ID3D10EffectVectorVariable : size_t
	{
		/* ID3D10EffectVariable */
		IsValid,
		GetType,
		GetDesc,
		GetAnnotationByIndex,
		GetAnnotationByName,
		GetMemberByIndex,
		GetMemberByName,
		GetMemberBySemantic,
		GetElement,
		GetParentConstantBuffer,
		AsScalar,
		AsVector,
		AsMatrix,
		AsString,
		AsShaderResource,
		AsRenderTargetView,
		AsDepthStencilView,
		AsConstantBuffer,
		AsShader,
		AsBlend,
		AsDepthStencil,
		AsRasterizer,
		AsSampler,
		SetRawValue,
		GetRawValue,

		/* ID3D10EffectVectorVariable */
		//IsValid,
		//GetType,
		//GetDesc,
		//GetAnnotationByIndex,
		//GetAnnotationByName,
		//GetMemberByIndex,
		//GetMemberByName,
		//GetMemberBySemantic,
		//GetElement,
		//GetParentConstantBuffer,
		//AsScalar,
		//AsVector,
		//AsMatrix,
		//AsString,
		//AsShaderResource,
		//AsRenderTargetView,
		//AsDepthStencilView,
		//AsConstantBuffer,
		//AsShader,
		//AsBlend,
		//AsDepthStencil,
		//AsRasterizer,
		//AsSampler,
		//SetRawValue,
		//GetRawValue,
		SetBoolVector,
		SetIntVector,
		SetFloatVector,
		GetBoolVector,
		GetIntVector,
		GetFloatVector,
		SetBoolVectorArray,
		SetIntVectorArray,
		SetFloatVectorArray,
		GetBoolVectorArray,
		GetIntVectorArray,
		GetFloatVectorArray,

		VTableSize,
	};

	enum class ID3D10EffectMatrixVariable : size_t
	{
		/* ID3D10EffectVariable */
		IsValid,
		GetType,
		GetDesc,
		GetAnnotationByIndex,
		GetAnnotationByName,
		GetMemberByIndex,
		GetMemberByName,
		GetMemberBySemantic,
		GetElement,
		GetParentConstantBuffer,
		AsScalar,
		AsVector,
		AsMatrix,
		AsString,
		AsShaderResource,
		AsRenderTargetView,
		AsDepthStencilView,
		AsConstantBuffer,
		AsShader,
		AsBlend,
		AsDepthStencil,
		AsRasterizer,
		AsSampler,
		SetRawValue,
		GetRawValue,

		/* ID3D10EffectMatrixVariable */
		//IsValid,
		//GetType,
		//GetDesc,
		//GetAnnotationByIndex,
		//GetAnnotationByName,
		//GetMemberByIndex,
		//GetMemberByName,
		//GetMemberBySemantic,
		//GetElement,
		//GetParentConstantBuffer,
		//AsScalar,
		//AsVector,
		//AsMatrix,
		//AsString,
		//AsShaderResource,
		//AsRenderTargetView,
		//AsDepthStencilView,
		//AsConstantBuffer,
		//AsShader,
		//AsBlend,
		//AsDepthStencil,
		//AsRasterizer,
		//AsSampler,
		//SetRawValue,
		//GetRawValue,
		SetMatrix,
		GetMatrix,
		SetMatrixArray,
		GetMatrixArray,
		SetMatrixTranspose,
		GetMatrixTranspose,
		SetMatrixTransposeArray,
		GetMatrixTransposeArray,

		VTableSize,
	};

	enum class ID3D10EffectStringVariable : size_t
	{
		/* ID3D10EffectVariable */
		IsValid,
		GetType,
		GetDesc,
		GetAnnotationByIndex,
		GetAnnotationByName,
		GetMemberByIndex,
		GetMemberByName,
		GetMemberBySemantic,
		GetElement,
		GetParentConstantBuffer,
		AsScalar,
		AsVector,
		AsMatrix,
		AsString,
		AsShaderResource,
		AsRenderTargetView,
		AsDepthStencilView,
		AsConstantBuffer,
		AsShader,
		AsBlend,
		AsDepthStencil,
		AsRasterizer,
		AsSampler,
		SetRawValue,
		GetRawValue,

		/* ID3D10EffectStringVariable */
		//IsValid,
		//GetType,
		//GetDesc,
		//GetAnnotationByIndex,
		//GetAnnotationByName,
		//GetMemberByIndex,
		//GetMemberByName,
		//GetMemberBySemantic,
		//GetElement,
		//GetParentConstantBuffer,
		//AsScalar,
		//AsVector,
		//AsMatrix,
		//AsString,
		//AsShaderResource,
		//AsRenderTargetView,
		//AsDepthStencilView,
		//AsConstantBuffer,
		//AsShader,
		//AsBlend,
		//AsDepthStencil,
		//AsRasterizer,
		//AsSampler,
		//SetRawValue,
		//GetRawValue,
		GetString,
		GetStringArray,

		VTableSize,
	};

	enum class ID3D10EffectShaderResourceVariable : size_t
	{
		/* ID3D10EffectVariable */
		IsValid,
		GetType,
		GetDesc,
		GetAnnotationByIndex,
		GetAnnotationByName,
		GetMemberByIndex,
		GetMemberByName,
		GetMemberBySemantic,
		GetElement,
		GetParentConstantBuffer,
		AsScalar,
		AsVector,
		AsMatrix,
		AsString,
		AsShaderResource,
		AsRenderTargetView,
		AsDepthStencilView,
		AsConstantBuffer,
		AsShader,
		AsBlend,
		AsDepthStencil,
		AsRasterizer,
		AsSampler,
		SetRawValue,
		GetRawValue,

		/* ID3D10EffectShaderResourceVariable */
		//IsValid,
		//GetType,
		//GetDesc,
		//GetAnnotationByIndex,
		//GetAnnotationByName,
		//GetMemberByIndex,
		//GetMemberByName,
		//GetMemberBySemantic,
		//GetElement,
		//GetParentConstantBuffer,
		//AsScalar,
		//AsVector,
		//AsMatrix,
		//AsString,
		//AsShaderResource,
		//AsRenderTargetView,
		//AsDepthStencilView,
		//AsConstantBuffer,
		//AsShader,
		//AsBlend,
		//AsDepthStencil,
		//AsRasterizer,
		//AsSampler,
		//SetRawValue,
		//GetRawValue,
		SetResource,
		GetResource,
		SetResourceArray,
		GetResourceArray,

		VTableSize,
	};

	enum class ID3D10EffectRenderTargetViewVariable : size_t
	{
		/* ID3D10EffectVariable */
		IsValid,
		GetType,
		GetDesc,
		GetAnnotationByIndex,
		GetAnnotationByName,
		GetMemberByIndex,
		GetMemberByName,
		GetMemberBySemantic,
		GetElement,
		GetParentConstantBuffer,
		AsScalar,
		AsVector,
		AsMatrix,
		AsString,
		AsShaderResource,
		AsRenderTargetView,
		AsDepthStencilView,
		AsConstantBuffer,
		AsShader,
		AsBlend,
		AsDepthStencil,
		AsRasterizer,
		AsSampler,
		SetRawValue,
		GetRawValue,

		/* ID3D10EffectRenderTargetViewVariable */
		//IsValid,
		//GetType,
		//GetDesc,
		//GetAnnotationByIndex,
		//GetAnnotationByName,
		//GetMemberByIndex,
		//GetMemberByName,
		//GetMemberBySemantic,
		//GetElement,
		//GetParentConstantBuffer,
		//AsScalar,
		//AsVector,
		//AsMatrix,
		//AsString,
		//AsShaderResource,
		//AsRenderTargetView,
		//AsDepthStencilView,
		//AsConstantBuffer,
		//AsShader,
		//AsBlend,
		//AsDepthStencil,
		//AsRasterizer,
		//AsSampler,
		//SetRawValue,
		//GetRawValue,
		SetRenderTarget,
		GetRenderTarget,
		SetRenderTargetArray,
		GetRenderTargetArray,

		VTableSize,
	};

	enum class ID3D10EffectDepthStencilViewVariable : size_t
	{
		/* ID3D10EffectVariable */
		IsValid,
		GetType,
		GetDesc,
		GetAnnotationByIndex,
		GetAnnotationByName,
		GetMemberByIndex,
		GetMemberByName,
		GetMemberBySemantic,
		GetElement,
		GetParentConstantBuffer,
		AsScalar,
		AsVector,
		AsMatrix,
		AsString,
		AsShaderResource,
		AsRenderTargetView,
		AsDepthStencilView,
		AsConstantBuffer,
		AsShader,
		AsBlend,
		AsDepthStencil,
		AsRasterizer,
		AsSampler,
		SetRawValue,
		GetRawValue,

		/* ID3D10EffectDepthStencilViewVariable */
		//IsValid,
		//GetType,
		//GetDesc,
		//GetAnnotationByIndex,
		//GetAnnotationByName,
		//GetMemberByIndex,
		//GetMemberByName,
		//GetMemberBySemantic,
		//GetElement,
		//GetParentConstantBuffer,
		//AsScalar,
		//AsVector,
		//AsMatrix,
		//AsString,
		//AsShaderResource,
		//AsRenderTargetView,
		//AsDepthStencilView,
		//AsConstantBuffer,
		//AsShader,
		//AsBlend,
		//AsDepthStencil,
		//AsRasterizer,
		//AsSampler,
		//SetRawValue,
		//GetRawValue,
		SetDepthStencil,
		GetDepthStencil,
		SetDepthStencilArray,
		GetDepthStencilArray,

		VTableSize,
	};

	enum class ID3D10EffectConstantBuffer : size_t
	{
		/* ID3D10EffectVariable */
		IsValid,
		GetType,
		GetDesc,
		GetAnnotationByIndex,
		GetAnnotationByName,
		GetMemberByIndex,
		GetMemberByName,
		GetMemberBySemantic,
		GetElement,
		GetParentConstantBuffer,
		AsScalar,
		AsVector,
		AsMatrix,
		AsString,
		AsShaderResource,
		AsRenderTargetView,
		AsDepthStencilView,
		AsConstantBuffer,
		AsShader,
		AsBlend,
		AsDepthStencil,
		AsRasterizer,
		AsSampler,
		SetRawValue,
		GetRawValue,

		/* ID3D10EffectConstantBuffer */
		//GetType,
		//GetDesc,
		//GetAnnotationByIndex,
		//GetAnnotationByName,
		//GetMemberByIndex,
		//GetMemberByName,
		//GetMemberBySemantic,
		//GetElement,
		//GetParentConstantBuffer,
		//AsScalar,
		//AsVector,
		//AsMatrix,
		//AsString,
		//AsShaderResource,
		//AsRenderTargetView,
		//AsDepthStencilView,
		//AsConstantBuffer,
		//AsShader,
		//AsBlend,
		//AsDepthStencil,
		//AsRasterizer,
		//AsSampler,
		//SetRawValue,
		//GetRawValue,
		SetConstantBuffer,
		GetConstantBuffer,
		SetTextureBuffer,
		GetTextureBuffer,

		VTableSize,
	};

	enum class ID3D10EffectShaderVariable : size_t
	{
		/* ID3D10EffectVariable */
		IsValid,
		GetType,
		GetDesc,
		GetAnnotationByIndex,
		GetAnnotationByName,
		GetMemberByIndex,
		GetMemberByName,
		GetMemberBySemantic,
		GetElement,
		GetParentConstantBuffer,
		AsScalar,
		AsVector,
		AsMatrix,
		AsString,
		AsShaderResource,
		AsRenderTargetView,
		AsDepthStencilView,
		AsConstantBuffer,
		AsShader,
		AsBlend,
		AsDepthStencil,
		AsRasterizer,
		AsSampler,
		SetRawValue,
		GetRawValue,

		/* ID3D10EffectShaderVariable */
		//GetType,
		//GetDesc,
		//GetAnnotationByIndex,
		//GetAnnotationByName,
		//GetMemberByIndex,
		//GetMemberByName,
		//GetMemberBySemantic,
		//GetElement,
		//GetParentConstantBuffer,
		//AsScalar,
		//AsVector,
		//AsMatrix,
		//AsString,
		//AsShaderResource,
		//AsRenderTargetView,
		//AsDepthStencilView,
		//AsConstantBuffer,
		//AsShader,
		//AsBlend,
		//AsDepthStencil,
		//AsRasterizer,
		//AsSampler,
		//SetRawValue,
		//GetRawValue,
		GetShaderDesc,
		GetVertexShader,
		GetGeometryShader,
		GetPixelShader,
		GetInputSignatureElementDesc,
		GetOutputSignatureElementDesc,

		VTableSize,
	};

	enum class ID3D10EffectBlendVariable : size_t
	{
		/* ID3D10EffectVariable */
		IsValid,
		GetType,
		GetDesc,
		GetAnnotationByIndex,
		GetAnnotationByName,
		GetMemberByIndex,
		GetMemberByName,
		GetMemberBySemantic,
		GetElement,
		GetParentConstantBuffer,
		AsScalar,
		AsVector,
		AsMatrix,
		AsString,
		AsShaderResource,
		AsRenderTargetView,
		AsDepthStencilView,
		AsConstantBuffer,
		AsShader,
		AsBlend,
		AsDepthStencil,
		AsRasterizer,
		AsSampler,
		SetRawValue,
		GetRawValue,

		/* ID3D10EffectBlendVariable */
		//GetType,
		//GetDesc,
		//GetAnnotationByIndex,
		//GetAnnotationByName,
		//GetMemberByIndex,
		//GetMemberByName,
		//GetMemberBySemantic,
		//GetElement,
		//GetParentConstantBuffer,
		//AsScalar,
		//AsVector,
		//AsMatrix,
		//AsString,
		//AsShaderResource,
		//AsRenderTargetView,
		//AsDepthStencilView,
		//AsConstantBuffer,
		//AsShader,
		//AsBlend,
		//AsDepthStencil,
		//AsRasterizer,
		//AsSampler,
		//SetRawValue,
		//GetRawValue,
		GetBlendState,
		GetBackingStore,

		VTableSize,
	};

	enum class ID3D10EffectDepthStencilVariable : size_t
	{
		/* ID3D10EffectVariable */
		IsValid,
		GetType,
		GetDesc,
		GetAnnotationByIndex,
		GetAnnotationByName,
		GetMemberByIndex,
		GetMemberByName,
		GetMemberBySemantic,
		GetElement,
		GetParentConstantBuffer,
		AsScalar,
		AsVector,
		AsMatrix,
		AsString,
		AsShaderResource,
		AsRenderTargetView,
		AsDepthStencilView,
		AsConstantBuffer,
		AsShader,
		AsBlend,
		AsDepthStencil,
		AsRasterizer,
		AsSampler,
		SetRawValue,
		GetRawValue,

		/* ID3D10EffectDepthStencilVariable */
		//GetType,
		//GetDesc,
		//GetAnnotationByIndex,
		//GetAnnotationByName,
		//GetMemberByIndex,
		//GetMemberByName,
		//GetMemberBySemantic,
		//GetElement,
		//GetParentConstantBuffer,
		//AsScalar,
		//AsVector,
		//AsMatrix,
		//AsString,
		//AsShaderResource,
		//AsRenderTargetView,
		//AsDepthStencilView,
		//AsConstantBuffer,
		//AsShader,
		//AsBlend,
		//AsDepthStencil,
		//AsRasterizer,
		//AsSampler,
		//SetRawValue,
		//GetRawValue,
		GetDepthStencilState,
		GetBackingStore,

		VTableSize,
	};

	enum class ID3D10EffectRasterizerVariable : size_t
	{
		/* ID3D10EffectVariable */
		IsValid,
		GetType,
		GetDesc,
		GetAnnotationByIndex,
		GetAnnotationByName,
		GetMemberByIndex,
		GetMemberByName,
		GetMemberBySemantic,
		GetElement,
		GetParentConstantBuffer,
		AsScalar,
		AsVector,
		AsMatrix,
		AsString,
		AsShaderResource,
		AsRenderTargetView,
		AsDepthStencilView,
		AsConstantBuffer,
		AsShader,
		AsBlend,
		AsDepthStencil,
		AsRasterizer,
		AsSampler,
		SetRawValue,
		GetRawValue,

		/* ID3D10EffectRasterizerVariable */
		//GetType,
		//GetDesc,
		//GetAnnotationByIndex,
		//GetAnnotationByName,
		//GetMemberByIndex,
		//GetMemberByName,
		//GetMemberBySemantic,
		//GetElement,
		//GetParentConstantBuffer,
		//AsScalar,
		//AsVector,
		//AsMatrix,
		//AsString,
		//AsShaderResource,
		//AsRenderTargetView,
		//AsDepthStencilView,
		//AsConstantBuffer,
		//AsShader,
		//AsBlend,
		//AsDepthStencil,
		//AsRasterizer,
		//AsSampler,
		//SetRawValue,
		//GetRawValue,
		GetRasterizerState,
		GetBackingStore,

		VTableSize,
	};

	enum class ID3D10EffectSamplerVariable : size_t
	{
		/* ID3D10EffectVariable */
		IsValid,
		GetType,
		GetDesc,
		GetAnnotationByIndex,
		GetAnnotationByName,
		GetMemberByIndex,
		GetMemberByName,
		GetMemberBySemantic,
		GetElement,
		GetParentConstantBuffer,
		AsScalar,
		AsVector,
		AsMatrix,
		AsString,
		AsShaderResource,
		AsRenderTargetView,
		AsDepthStencilView,
		AsConstantBuffer,
		AsShader,
		AsBlend,
		AsDepthStencil,
		AsRasterizer,
		AsSampler,
		SetRawValue,
		GetRawValue,

		/* ID3D10EffectSamplerVariable */
		//GetType,
		//GetDesc,
		//GetAnnotationByIndex,
		//GetAnnotationByName,
		//GetMemberByIndex,
		//GetMemberByName,
		//GetMemberBySemantic,
		//GetElement,
		//GetParentConstantBuffer,
		//AsScalar,
		//AsVector,
		//AsMatrix,
		//AsString,
		//AsShaderResource,
		//AsRenderTargetView,
		//AsDepthStencilView,
		//AsConstantBuffer,
		//AsShader,
		//AsBlend,
		//AsDepthStencil,
		//AsRasterizer,
		//AsSampler,
		//SetRawValue,
		//GetRawValue,
		GetSampler,
		GetBackingStore,

		VTableSize,
	};

	enum class ID3D10Effect : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D10Effect */
		//QueryInterface,
		//AddRef,
		//Release,
		IsValid,
		IsPool,
		GetDevice,
		GetDesc,
		GetConstantBufferByIndex,
		GetConstantBufferByName,
		GetVariableByIndex,
		GetVariableByName,
		GetVariableBySemantic,
		GetTechniqueByIndex,
		GetTechniqueByName,
		Optimize,
		IsOptimized,

		VTableSize,
	};

	enum class ID3D10EffectPool : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D10EffectPool */
		//QueryInterface,
		//AddRef,
		//Release,
		AsEffect,

		VTableSize,
	};

	enum class ID3D10BlendState1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D10DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D10BlendState */
		GetDesc,

		/* ID3D10BlendState1 */
		GetDesc1,

		VTableSize,
	};

	enum class ID3D10ShaderResourceView1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D10DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D10View */
		GetResource,

		/* ID3D10ShaderResourceView */
		GetDesc,

		/* ID3D10ShaderResourceView1 */
		GetDesc1,

		VTableSize,
	};

	enum class ID3D10Device1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D10Device */
		VSSetConstantBuffers,
		PSSetShaderResources,
		PSSetShader,
		PSSetSamplers,
		VSSetShader,
		DrawIndexed,
		Draw,
		PSSetConstantBuffers,
		IASetInputLayout,
		IASetVertexBuffers,
		IASetIndexBuffer,
		DrawIndexedInstanced,
		DrawInstanced,
		GSSetConstantBuffers,
		GSSetShader,
		IASetPrimitiveTopology,
		VSSetShaderResources,
		VSSetSamplers,
		SetPredication,
		GSSetShaderResources,
		GSSetSamplers,
		OMSetRenderTargets,
		OMSetBlendState,
		OMSetDepthStencilState,
		SOSetTargets,
		DrawAuto,
		RSSetState,
		RSSetViewports,
		RSSetScissorRects,
		CopySubresourceRegion,
		CopyResource,
		UpdateSubresource,
		ClearRenderTargetView,
		ClearDepthStencilView,
		GenerateMips,
		ResolveSubresource,
		VSGetConstantBuffers,
		PSGetShaderResources,
		PSGetShader,
		PSGetSamplers,
		VSGetShader,
		PSGetConstantBuffers,
		IAGetInputLayout,
		IAGetVertexBuffers,
		IAGetIndexBuffer,
		GSGetConstantBuffers,
		GSGetShader,
		IAGetPrimitiveTopology,
		VSGetShaderResources,
		VSGetSamplers,
		GetPredication,
		GSGetShaderResources,
		GSGetSamplers,
		OMGetRenderTargets,
		OMGetBlendState,
		OMGetDepthStencilState,
		SOGetTargets,
		RSGetState,
		RSGetViewports,
		RSGetScissorRects,
		GetDeviceRemovedReason,
		SetExceptionMode,
		GetExceptionMode,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		ClearState,
		Flush,
		CreateBuffer,
		CreateTexture1D,
		CreateTexture2D,
		CreateTexture3D,
		CreateShaderResourceView,
		CreateRenderTargetView,
		CreateDepthStencilView,
		CreateInputLayout,
		CreateVertexShader,
		CreateGeometryShader,
		CreateGeometryShaderWithStreamOutput,
		CreatePixelShader,
		CreateBlendState,
		CreateDepthStencilState,
		CreateRasterizerState,
		CreateSamplerState,
		CreateQuery,
		CreatePredicate,
		CreateCounter,
		CheckFormatSupport,
		CheckMultisampleQualityLevels,
		CheckCounterInfo,
		CheckCounter,
		GetCreationFlags,
		OpenSharedResource,
		SetTextFilterSize,
		GetTextFilterSize,

		/* ID3D10Device1 */
		CreateShaderResourceView1,
		CreateBlendState1,
		GetFeatureLevel,

		VTableSize,
	};

	enum class ID3D10ShaderReflection1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D10ShaderReflection1 */
		//QueryInterface,
		//AddRef,
		//Release,
		GetDesc,
		GetConstantBufferByIndex,
		GetConstantBufferByName,
		GetResourceBindingDesc,
		GetInputParameterDesc,
		GetOutputParameterDesc,
		GetVariableByName,
		GetResourceBindingDescByName,
		GetMovInstructionCount,
		GetMovcInstructionCount,
		GetConversionInstructionCount,
		GetBitwiseInstructionCount,
		GetGSInputPrimitive,
		IsLevel9Shader,
		IsSampleFrequencyShader,

		VTableSize,
	};

	enum class ID3D11BlendState1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11BlendState */
		GetDesc,

		/* ID3D11BlendState1 */
		GetDesc1,

		VTableSize,
	};

	enum class ID3D11RasterizerState1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11RasterizerState */
		GetDesc,

		/* ID3D11RasterizerState1 */
		GetDesc1,

		VTableSize,
	};

	enum class ID3D11DeviceContext1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11DeviceContext */
		VSSetConstantBuffers,
		PSSetShaderResources,
		PSSetShader,
		PSSetSamplers,
		VSSetShader,
		DrawIndexed,
		Draw,
		Map,
		Unmap,
		PSSetConstantBuffers,
		IASetInputLayout,
		IASetVertexBuffers,
		IASetIndexBuffer,
		DrawIndexedInstanced,
		DrawInstanced,
		GSSetConstantBuffers,
		GSSetShader,
		IASetPrimitiveTopology,
		VSSetShaderResources,
		VSSetSamplers,
		Begin,
		End,
		GetData,
		SetPredication,
		GSSetShaderResources,
		GSSetSamplers,
		OMSetRenderTargets,
		OMSetRenderTargetsAndUnorderedAccessViews,
		OMSetBlendState,
		OMSetDepthStencilState,
		SOSetTargets,
		DrawAuto,
		DrawIndexedInstancedIndirect,
		DrawInstancedIndirect,
		Dispatch,
		DispatchIndirect,
		RSSetState,
		RSSetViewports,
		RSSetScissorRects,
		CopySubresourceRegion,
		CopyResource,
		UpdateSubresource,
		CopyStructureCount,
		ClearRenderTargetView,
		ClearUnorderedAccessViewUint,
		ClearUnorderedAccessViewFloat,
		ClearDepthStencilView,
		GenerateMips,
		SetResourceMinLOD,
		GetResourceMinLOD,
		ResolveSubresource,
		ExecuteCommandList,
		HSSetShaderResources,
		HSSetShader,
		HSSetSamplers,
		HSSetConstantBuffers,
		DSSetShaderResources,
		DSSetShader,
		DSSetSamplers,
		DSSetConstantBuffers,
		CSSetShaderResources,
		CSSetUnorderedAccessViews,
		CSSetShader,
		CSSetSamplers,
		CSSetConstantBuffers,
		VSGetConstantBuffers,
		PSGetShaderResources,
		PSGetShader,
		PSGetSamplers,
		VSGetShader,
		PSGetConstantBuffers,
		IAGetInputLayout,
		IAGetVertexBuffers,
		IAGetIndexBuffer,
		GSGetConstantBuffers,
		GSGetShader,
		IAGetPrimitiveTopology,
		VSGetShaderResources,
		VSGetSamplers,
		GetPredication,
		GSGetShaderResources,
		GSGetSamplers,
		OMGetRenderTargets,
		OMGetRenderTargetsAndUnorderedAccessViews,
		OMGetBlendState,
		OMGetDepthStencilState,
		SOGetTargets,
		RSGetState,
		RSGetViewports,
		RSGetScissorRects,
		HSGetShaderResources,
		HSGetShader,
		HSGetSamplers,
		HSGetConstantBuffers,
		DSGetShaderResources,
		DSGetShader,
		DSGetSamplers,
		DSGetConstantBuffers,
		CSGetShaderResources,
		CSGetUnorderedAccessViews,
		CSGetShader,
		CSGetSamplers,
		CSGetConstantBuffers,
		ClearState,
		Flush,
		GetType,
		GetContextFlags,
		FinishCommandList,

		/* ID3D11DeviceContext1 */
		CopySubresourceRegion1,
		UpdateSubresource1,
		DiscardResource,
		DiscardView,
		VSSetConstantBuffers1,
		HSSetConstantBuffers1,
		DSSetConstantBuffers1,
		GSSetConstantBuffers1,
		PSSetConstantBuffers1,
		CSSetConstantBuffers1,
		VSGetConstantBuffers1,
		HSGetConstantBuffers1,
		DSGetConstantBuffers1,
		GSGetConstantBuffers1,
		PSGetConstantBuffers1,
		CSGetConstantBuffers1,
		SwapDeviceContextState,
		ClearView,
		DiscardView1,

		VTableSize,
	};

	enum class ID3D11VideoContext1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11VideoContext */
		GetDecoderBuffer,
		ReleaseDecoderBuffer,
		DecoderBeginFrame,
		DecoderEndFrame,
		SubmitDecoderBuffers,
		DecoderExtension,
		VideoProcessorSetOutputTargetRect,
		VideoProcessorSetOutputBackgroundColor,
		VideoProcessorSetOutputColorSpace,
		VideoProcessorSetOutputAlphaFillMode,
		VideoProcessorSetOutputConstriction,
		VideoProcessorSetOutputStereoMode,
		VideoProcessorSetOutputExtension,
		VideoProcessorGetOutputTargetRect,
		VideoProcessorGetOutputBackgroundColor,
		VideoProcessorGetOutputColorSpace,
		VideoProcessorGetOutputAlphaFillMode,
		VideoProcessorGetOutputConstriction,
		VideoProcessorGetOutputStereoMode,
		VideoProcessorGetOutputExtension,
		VideoProcessorSetStreamFrameFormat,
		VideoProcessorSetStreamColorSpace,
		VideoProcessorSetStreamOutputRate,
		VideoProcessorSetStreamSourceRect,
		VideoProcessorSetStreamDestRect,
		VideoProcessorSetStreamAlpha,
		VideoProcessorSetStreamPalette,
		VideoProcessorSetStreamPixelAspectRatio,
		VideoProcessorSetStreamLumaKey,
		VideoProcessorSetStreamStereoFormat,
		VideoProcessorSetStreamAutoProcessingMode,
		VideoProcessorSetStreamFilter,
		VideoProcessorSetStreamExtension,
		VideoProcessorGetStreamFrameFormat,
		VideoProcessorGetStreamColorSpace,
		VideoProcessorGetStreamOutputRate,
		VideoProcessorGetStreamSourceRect,
		VideoProcessorGetStreamDestRect,
		VideoProcessorGetStreamAlpha,
		VideoProcessorGetStreamPalette,
		VideoProcessorGetStreamPixelAspectRatio,
		VideoProcessorGetStreamLumaKey,
		VideoProcessorGetStreamStereoFormat,
		VideoProcessorGetStreamAutoProcessingMode,
		VideoProcessorGetStreamFilter,
		VideoProcessorGetStreamExtension,
		VideoProcessorBlt,
		NegotiateCryptoSessionKeyExchange,
		EncryptionBlt,
		DecryptionBlt,
		StartSessionKeyRefresh,
		FinishSessionKeyRefresh,
		GetEncryptionBltKey,
		NegotiateAuthenticatedChannelKeyExchange,
		QueryAuthenticatedChannel,
		ConfigureAuthenticatedChannel,
		VideoProcessorSetStreamRotation,
		VideoProcessorGetStreamRotation,

		/* ID3D11VideoContext1 */
		SubmitDecoderBuffers1,
		GetDataForNewHardwareKey,
		CheckCryptoSessionStatus,
		DecoderEnableDownsampling,
		DecoderUpdateDownsampling,
		VideoProcessorSetOutputColorSpace1,
		VideoProcessorSetOutputShaderUsage,
		VideoProcessorGetOutputColorSpace1,
		VideoProcessorGetOutputShaderUsage,
		VideoProcessorSetStreamColorSpace1,
		VideoProcessorSetStreamMirror,
		VideoProcessorGetStreamColorSpace1,
		VideoProcessorGetStreamMirror,
		VideoProcessorGetBehaviorHints,

		VTableSize,
	};

	enum class ID3D11VideoDevice1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11VideoDevice */
		CreateVideoDecoder,
		CreateVideoProcessor,
		CreateAuthenticatedChannel,
		CreateCryptoSession,
		CreateVideoDecoderOutputView,
		CreateVideoProcessorInputView,
		CreateVideoProcessorOutputView,
		CreateVideoProcessorEnumerator,
		GetVideoDecoderProfileCount,
		GetVideoDecoderProfile,
		CheckVideoDecoderFormat,
		GetVideoDecoderConfigCount,
		GetVideoDecoderConfig,
		GetContentProtectionCaps,
		CheckCryptoKeyExchange,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11VideoDevice1 */
		GetCryptoSessionPrivateDataSize,
		GetVideoDecoderCaps,
		CheckVideoDecoderDownsampling,
		RecommendVideoDecoderDownsampleParameters,

		VTableSize,
	};

	enum class ID3D11VideoProcessorEnumerator1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11VideoProcessorEnumerator */
		GetVideoProcessorContentDesc,
		CheckVideoProcessorFormat,
		GetVideoProcessorCaps,
		GetVideoProcessorRateConversionCaps,
		GetVideoProcessorCustomRate,
		GetVideoProcessorFilterRange,

		/* ID3D11VideoProcessorEnumerator1 */
		CheckVideoProcessorFormatConversion,

		VTableSize,
	};

	enum class ID3D11Device1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11Device */
		CreateBuffer,
		CreateTexture1D,
		CreateTexture2D,
		CreateTexture3D,
		CreateShaderResourceView,
		CreateUnorderedAccessView,
		CreateRenderTargetView,
		CreateDepthStencilView,
		CreateInputLayout,
		CreateVertexShader,
		CreateGeometryShader,
		CreateGeometryShaderWithStreamOutput,
		CreatePixelShader,
		CreateHullShader,
		CreateDomainShader,
		CreateComputeShader,
		CreateClassLinkage,
		CreateBlendState,
		CreateDepthStencilState,
		CreateRasterizerState,
		CreateSamplerState,
		CreateQuery,
		CreatePredicate,
		CreateCounter,
		CreateDeferredContext,
		OpenSharedResource,
		CheckFormatSupport,
		CheckMultisampleQualityLevels,
		CheckCounterInfo,
		CheckCounter,
		CheckFeatureSupport,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		GetFeatureLevel,
		GetCreationFlags,
		GetDeviceRemovedReason,
		GetImmediateContext,
		SetExceptionMode,
		GetExceptionMode,

		/* ID3D11Device1 */
		GetImmediateContext1,
		CreateDeferredContext1,
		CreateBlendState1,
		CreateRasterizerState1,
		CreateDeviceContextState,
		OpenSharedResource1,
		OpenSharedResourceByName,

		VTableSize,
	};

	enum class ID3DUserDefinedAnnotation : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3DUserDefinedAnnotation */
		BeginEvent,
		EndEvent,
		SetMarker,
		GetStatus,

		VTableSize,
	};

	enum class ID3D11DeviceContext2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11DeviceContext */
		VSSetConstantBuffers,
		PSSetShaderResources,
		PSSetShader,
		PSSetSamplers,
		VSSetShader,
		DrawIndexed,
		Draw,
		Map,
		Unmap,
		PSSetConstantBuffers,
		IASetInputLayout,
		IASetVertexBuffers,
		IASetIndexBuffer,
		DrawIndexedInstanced,
		DrawInstanced,
		GSSetConstantBuffers,
		GSSetShader,
		IASetPrimitiveTopology,
		VSSetShaderResources,
		VSSetSamplers,
		Begin,
		End,
		GetData,
		SetPredication,
		GSSetShaderResources,
		GSSetSamplers,
		OMSetRenderTargets,
		OMSetRenderTargetsAndUnorderedAccessViews,
		OMSetBlendState,
		OMSetDepthStencilState,
		SOSetTargets,
		DrawAuto,
		DrawIndexedInstancedIndirect,
		DrawInstancedIndirect,
		Dispatch,
		DispatchIndirect,
		RSSetState,
		RSSetViewports,
		RSSetScissorRects,
		CopySubresourceRegion,
		CopyResource,
		UpdateSubresource,
		CopyStructureCount,
		ClearRenderTargetView,
		ClearUnorderedAccessViewUint,
		ClearUnorderedAccessViewFloat,
		ClearDepthStencilView,
		GenerateMips,
		SetResourceMinLOD,
		GetResourceMinLOD,
		ResolveSubresource,
		ExecuteCommandList,
		HSSetShaderResources,
		HSSetShader,
		HSSetSamplers,
		HSSetConstantBuffers,
		DSSetShaderResources,
		DSSetShader,
		DSSetSamplers,
		DSSetConstantBuffers,
		CSSetShaderResources,
		CSSetUnorderedAccessViews,
		CSSetShader,
		CSSetSamplers,
		CSSetConstantBuffers,
		VSGetConstantBuffers,
		PSGetShaderResources,
		PSGetShader,
		PSGetSamplers,
		VSGetShader,
		PSGetConstantBuffers,
		IAGetInputLayout,
		IAGetVertexBuffers,
		IAGetIndexBuffer,
		GSGetConstantBuffers,
		GSGetShader,
		IAGetPrimitiveTopology,
		VSGetShaderResources,
		VSGetSamplers,
		GetPredication,
		GSGetShaderResources,
		GSGetSamplers,
		OMGetRenderTargets,
		OMGetRenderTargetsAndUnorderedAccessViews,
		OMGetBlendState,
		OMGetDepthStencilState,
		SOGetTargets,
		RSGetState,
		RSGetViewports,
		RSGetScissorRects,
		HSGetShaderResources,
		HSGetShader,
		HSGetSamplers,
		HSGetConstantBuffers,
		DSGetShaderResources,
		DSGetShader,
		DSGetSamplers,
		DSGetConstantBuffers,
		CSGetShaderResources,
		CSGetUnorderedAccessViews,
		CSGetShader,
		CSGetSamplers,
		CSGetConstantBuffers,
		ClearState,
		Flush,
		GetType,
		GetContextFlags,
		FinishCommandList,

		/* ID3D11DeviceContext1 */
		CopySubresourceRegion1,
		UpdateSubresource1,
		DiscardResource,
		DiscardView,
		VSSetConstantBuffers1,
		HSSetConstantBuffers1,
		DSSetConstantBuffers1,
		GSSetConstantBuffers1,
		PSSetConstantBuffers1,
		CSSetConstantBuffers1,
		VSGetConstantBuffers1,
		HSGetConstantBuffers1,
		DSGetConstantBuffers1,
		GSGetConstantBuffers1,
		PSGetConstantBuffers1,
		CSGetConstantBuffers1,
		SwapDeviceContextState,
		ClearView,
		DiscardView1,

		/* ID3D11DeviceContext2 */
		UpdateTileMappings,
		CopyTileMappings,
		CopyTiles,
		UpdateTiles,
		ResizeTilePool,
		TiledResourceBarrier,
		IsAnnotationEnabled,
		SetMarkerInt,
		BeginEventInt,
		EndEvent,

		VTableSize,
	};

	enum class ID3D11Device2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11Device */
		CreateBuffer,
		CreateTexture1D,
		CreateTexture2D,
		CreateTexture3D,
		CreateShaderResourceView,
		CreateUnorderedAccessView,
		CreateRenderTargetView,
		CreateDepthStencilView,
		CreateInputLayout,
		CreateVertexShader,
		CreateGeometryShader,
		CreateGeometryShaderWithStreamOutput,
		CreatePixelShader,
		CreateHullShader,
		CreateDomainShader,
		CreateComputeShader,
		CreateClassLinkage,
		CreateBlendState,
		CreateDepthStencilState,
		CreateRasterizerState,
		CreateSamplerState,
		CreateQuery,
		CreatePredicate,
		CreateCounter,
		CreateDeferredContext,
		OpenSharedResource,
		CheckFormatSupport,
		CheckMultisampleQualityLevels,
		CheckCounterInfo,
		CheckCounter,
		CheckFeatureSupport,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		GetFeatureLevel,
		GetCreationFlags,
		GetDeviceRemovedReason,
		GetImmediateContext,
		SetExceptionMode,
		GetExceptionMode,

		/* ID3D11Device1 */
		GetImmediateContext1,
		CreateDeferredContext1,
		CreateBlendState1,
		CreateRasterizerState1,
		CreateDeviceContextState,
		OpenSharedResource1,
		OpenSharedResourceByName,

		/* ID3D11Device2 */
		GetImmediateContext2,
		CreateDeferredContext2,
		GetResourceTiling,
		CheckMultisampleQualityLevels1,

		VTableSize,
	};

	enum class ID3D11Texture2D1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11Resource */
		GetType,
		SetEvictionPriority,
		GetEvictionPriority,

		/* ID3D11Texture2D */
		GetDesc,

		/* ID3D11Texture2D1 */
		GetDesc1,

		VTableSize,
	};

	enum class ID3D11Texture3D1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11Resource */
		GetType,
		SetEvictionPriority,
		GetEvictionPriority,

		/* ID3D11Texture3D */
		GetDesc,

		/* ID3D11Texture3D1 */
		GetDesc1,

		VTableSize,
	};

	enum class ID3D11RasterizerState2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11RasterizerState */
		GetDesc,

		/* ID3D11RasterizerState1 */
		GetDesc1,

		/* ID3D11RasterizerState2 */
		GetDesc2,

		VTableSize,
	};

	enum class ID3D11ShaderResourceView1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11View */
		GetResource,

		/* ID3D11ShaderResourceView */
		GetDesc,

		/* ID3D11ShaderResourceView1 */
		GetDesc1,

		VTableSize,
	};

	enum class ID3D11RenderTargetView1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11View */
		GetResource,

		/* ID3D11RenderTargetView */
		GetDesc,

		/* ID3D11RenderTargetView1 */
		GetDesc1,

		VTableSize,
	};

	enum class ID3D11UnorderedAccessView1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11View */
		GetResource,

		/* ID3D11UnorderedAccessView */
		GetDesc,

		/* ID3D11UnorderedAccessView1 */
		GetDesc1,

		VTableSize,
	};

	enum class ID3D11Query1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11Asynchronous */
		GetDataSize,

		/* ID3D11Query */
		GetDesc,

		/* ID3D11Query1 */
		GetDesc1,

		VTableSize,
	};

	enum class ID3D11DeviceContext3 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11DeviceContext */
		VSSetConstantBuffers,
		PSSetShaderResources,
		PSSetShader,
		PSSetSamplers,
		VSSetShader,
		DrawIndexed,
		Draw,
		Map,
		Unmap,
		PSSetConstantBuffers,
		IASetInputLayout,
		IASetVertexBuffers,
		IASetIndexBuffer,
		DrawIndexedInstanced,
		DrawInstanced,
		GSSetConstantBuffers,
		GSSetShader,
		IASetPrimitiveTopology,
		VSSetShaderResources,
		VSSetSamplers,
		Begin,
		End,
		GetData,
		SetPredication,
		GSSetShaderResources,
		GSSetSamplers,
		OMSetRenderTargets,
		OMSetRenderTargetsAndUnorderedAccessViews,
		OMSetBlendState,
		OMSetDepthStencilState,
		SOSetTargets,
		DrawAuto,
		DrawIndexedInstancedIndirect,
		DrawInstancedIndirect,
		Dispatch,
		DispatchIndirect,
		RSSetState,
		RSSetViewports,
		RSSetScissorRects,
		CopySubresourceRegion,
		CopyResource,
		UpdateSubresource,
		CopyStructureCount,
		ClearRenderTargetView,
		ClearUnorderedAccessViewUint,
		ClearUnorderedAccessViewFloat,
		ClearDepthStencilView,
		GenerateMips,
		SetResourceMinLOD,
		GetResourceMinLOD,
		ResolveSubresource,
		ExecuteCommandList,
		HSSetShaderResources,
		HSSetShader,
		HSSetSamplers,
		HSSetConstantBuffers,
		DSSetShaderResources,
		DSSetShader,
		DSSetSamplers,
		DSSetConstantBuffers,
		CSSetShaderResources,
		CSSetUnorderedAccessViews,
		CSSetShader,
		CSSetSamplers,
		CSSetConstantBuffers,
		VSGetConstantBuffers,
		PSGetShaderResources,
		PSGetShader,
		PSGetSamplers,
		VSGetShader,
		PSGetConstantBuffers,
		IAGetInputLayout,
		IAGetVertexBuffers,
		IAGetIndexBuffer,
		GSGetConstantBuffers,
		GSGetShader,
		IAGetPrimitiveTopology,
		VSGetShaderResources,
		VSGetSamplers,
		GetPredication,
		GSGetShaderResources,
		GSGetSamplers,
		OMGetRenderTargets,
		OMGetRenderTargetsAndUnorderedAccessViews,
		OMGetBlendState,
		OMGetDepthStencilState,
		SOGetTargets,
		RSGetState,
		RSGetViewports,
		RSGetScissorRects,
		HSGetShaderResources,
		HSGetShader,
		HSGetSamplers,
		HSGetConstantBuffers,
		DSGetShaderResources,
		DSGetShader,
		DSGetSamplers,
		DSGetConstantBuffers,
		CSGetShaderResources,
		CSGetUnorderedAccessViews,
		CSGetShader,
		CSGetSamplers,
		CSGetConstantBuffers,
		ClearState,
		Flush,
		GetType,
		GetContextFlags,
		FinishCommandList,

		/* ID3D11DeviceContext1 */
		CopySubresourceRegion1,
		UpdateSubresource1,
		DiscardResource,
		DiscardView,
		VSSetConstantBuffers1,
		HSSetConstantBuffers1,
		DSSetConstantBuffers1,
		GSSetConstantBuffers1,
		PSSetConstantBuffers1,
		CSSetConstantBuffers1,
		VSGetConstantBuffers1,
		HSGetConstantBuffers1,
		DSGetConstantBuffers1,
		GSGetConstantBuffers1,
		PSGetConstantBuffers1,
		CSGetConstantBuffers1,
		SwapDeviceContextState,
		ClearView,
		DiscardView1,

		/* ID3D11DeviceContext2 */
		UpdateTileMappings,
		CopyTileMappings,
		CopyTiles,
		UpdateTiles,
		ResizeTilePool,
		TiledResourceBarrier,
		IsAnnotationEnabled,
		SetMarkerInt,
		BeginEventInt,
		EndEvent,

		/* ID3D11DeviceContext3 */
		Flush1,
		SetHardwareProtectionState,
		GetHardwareProtectionState,

		VTableSize,
	};

	enum class ID3D11Fence : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11Fence */
		CreateSharedHandle,
		GetCompletedValue,
		SetEventOnCompletion,

		VTableSize,
	};

	enum class ID3D11DeviceContext4 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11DeviceContext */
		VSSetConstantBuffers,
		PSSetShaderResources,
		PSSetShader,
		PSSetSamplers,
		VSSetShader,
		DrawIndexed,
		Draw,
		Map,
		Unmap,
		PSSetConstantBuffers,
		IASetInputLayout,
		IASetVertexBuffers,
		IASetIndexBuffer,
		DrawIndexedInstanced,
		DrawInstanced,
		GSSetConstantBuffers,
		GSSetShader,
		IASetPrimitiveTopology,
		VSSetShaderResources,
		VSSetSamplers,
		Begin,
		End,
		GetData,
		SetPredication,
		GSSetShaderResources,
		GSSetSamplers,
		OMSetRenderTargets,
		OMSetRenderTargetsAndUnorderedAccessViews,
		OMSetBlendState,
		OMSetDepthStencilState,
		SOSetTargets,
		DrawAuto,
		DrawIndexedInstancedIndirect,
		DrawInstancedIndirect,
		Dispatch,
		DispatchIndirect,
		RSSetState,
		RSSetViewports,
		RSSetScissorRects,
		CopySubresourceRegion,
		CopyResource,
		UpdateSubresource,
		CopyStructureCount,
		ClearRenderTargetView,
		ClearUnorderedAccessViewUint,
		ClearUnorderedAccessViewFloat,
		ClearDepthStencilView,
		GenerateMips,
		SetResourceMinLOD,
		GetResourceMinLOD,
		ResolveSubresource,
		ExecuteCommandList,
		HSSetShaderResources,
		HSSetShader,
		HSSetSamplers,
		HSSetConstantBuffers,
		DSSetShaderResources,
		DSSetShader,
		DSSetSamplers,
		DSSetConstantBuffers,
		CSSetShaderResources,
		CSSetUnorderedAccessViews,
		CSSetShader,
		CSSetSamplers,
		CSSetConstantBuffers,
		VSGetConstantBuffers,
		PSGetShaderResources,
		PSGetShader,
		PSGetSamplers,
		VSGetShader,
		PSGetConstantBuffers,
		IAGetInputLayout,
		IAGetVertexBuffers,
		IAGetIndexBuffer,
		GSGetConstantBuffers,
		GSGetShader,
		IAGetPrimitiveTopology,
		VSGetShaderResources,
		VSGetSamplers,
		GetPredication,
		GSGetShaderResources,
		GSGetSamplers,
		OMGetRenderTargets,
		OMGetRenderTargetsAndUnorderedAccessViews,
		OMGetBlendState,
		OMGetDepthStencilState,
		SOGetTargets,
		RSGetState,
		RSGetViewports,
		RSGetScissorRects,
		HSGetShaderResources,
		HSGetShader,
		HSGetSamplers,
		HSGetConstantBuffers,
		DSGetShaderResources,
		DSGetShader,
		DSGetSamplers,
		DSGetConstantBuffers,
		CSGetShaderResources,
		CSGetUnorderedAccessViews,
		CSGetShader,
		CSGetSamplers,
		CSGetConstantBuffers,
		ClearState,
		Flush,
		GetType,
		GetContextFlags,
		FinishCommandList,

		/* ID3D11DeviceContext1 */
		CopySubresourceRegion1,
		UpdateSubresource1,
		DiscardResource,
		DiscardView,
		VSSetConstantBuffers1,
		HSSetConstantBuffers1,
		DSSetConstantBuffers1,
		GSSetConstantBuffers1,
		PSSetConstantBuffers1,
		CSSetConstantBuffers1,
		VSGetConstantBuffers1,
		HSGetConstantBuffers1,
		DSGetConstantBuffers1,
		GSGetConstantBuffers1,
		PSGetConstantBuffers1,
		CSGetConstantBuffers1,
		SwapDeviceContextState,
		ClearView,
		DiscardView1,

		/* ID3D11DeviceContext2 */
		UpdateTileMappings,
		CopyTileMappings,
		CopyTiles,
		UpdateTiles,
		ResizeTilePool,
		TiledResourceBarrier,
		IsAnnotationEnabled,
		SetMarkerInt,
		BeginEventInt,
		EndEvent,

		/* ID3D11DeviceContext3 */
		Flush1,
		SetHardwareProtectionState,
		GetHardwareProtectionState,

		/* ID3D11DeviceContext4 */
		Signal,
		Wait,

		VTableSize,
	};

	enum class ID3D11Device3 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11Device */
		CreateBuffer,
		CreateTexture1D,
		CreateTexture2D,
		CreateTexture3D,
		CreateShaderResourceView,
		CreateUnorderedAccessView,
		CreateRenderTargetView,
		CreateDepthStencilView,
		CreateInputLayout,
		CreateVertexShader,
		CreateGeometryShader,
		CreateGeometryShaderWithStreamOutput,
		CreatePixelShader,
		CreateHullShader,
		CreateDomainShader,
		CreateComputeShader,
		CreateClassLinkage,
		CreateBlendState,
		CreateDepthStencilState,
		CreateRasterizerState,
		CreateSamplerState,
		CreateQuery,
		CreatePredicate,
		CreateCounter,
		CreateDeferredContext,
		OpenSharedResource,
		CheckFormatSupport,
		CheckMultisampleQualityLevels,
		CheckCounterInfo,
		CheckCounter,
		CheckFeatureSupport,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		GetFeatureLevel,
		GetCreationFlags,
		GetDeviceRemovedReason,
		GetImmediateContext,
		SetExceptionMode,
		GetExceptionMode,

		/* ID3D11Device1 */
		GetImmediateContext1,
		CreateDeferredContext1,
		CreateBlendState1,
		CreateRasterizerState1,
		CreateDeviceContextState,
		OpenSharedResource1,
		OpenSharedResourceByName,

		/* ID3D11Device2 */
		GetImmediateContext2,
		CreateDeferredContext2,
		GetResourceTiling,
		CheckMultisampleQualityLevels1,

		/* ID3D11Device3 */
		CreateTexture2D1,
		CreateTexture3D1,
		CreateRasterizerState2,
		CreateShaderResourceView1,
		CreateUnorderedAccessView1,
		CreateRenderTargetView1,
		CreateQuery1,
		GetImmediateContext3,
		CreateDeferredContext3,
		WriteToSubresource,
		ReadFromSubresource,

		VTableSize,
	};

	enum class ID3D11Device4 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11Device */
		CreateBuffer,
		CreateTexture1D,
		CreateTexture2D,
		CreateTexture3D,
		CreateShaderResourceView,
		CreateUnorderedAccessView,
		CreateRenderTargetView,
		CreateDepthStencilView,
		CreateInputLayout,
		CreateVertexShader,
		CreateGeometryShader,
		CreateGeometryShaderWithStreamOutput,
		CreatePixelShader,
		CreateHullShader,
		CreateDomainShader,
		CreateComputeShader,
		CreateClassLinkage,
		CreateBlendState,
		CreateDepthStencilState,
		CreateRasterizerState,
		CreateSamplerState,
		CreateQuery,
		CreatePredicate,
		CreateCounter,
		CreateDeferredContext,
		OpenSharedResource,
		CheckFormatSupport,
		CheckMultisampleQualityLevels,
		CheckCounterInfo,
		CheckCounter,
		CheckFeatureSupport,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		GetFeatureLevel,
		GetCreationFlags,
		GetDeviceRemovedReason,
		GetImmediateContext,
		SetExceptionMode,
		GetExceptionMode,

		/* ID3D11Device1 */
		GetImmediateContext1,
		CreateDeferredContext1,
		CreateBlendState1,
		CreateRasterizerState1,
		CreateDeviceContextState,
		OpenSharedResource1,
		OpenSharedResourceByName,

		/* ID3D11Device2 */
		GetImmediateContext2,
		CreateDeferredContext2,
		GetResourceTiling,
		CheckMultisampleQualityLevels1,

		/* ID3D11Device3 */
		CreateTexture2D1,
		CreateTexture3D1,
		CreateRasterizerState2,
		CreateShaderResourceView1,
		CreateUnorderedAccessView1,
		CreateRenderTargetView1,
		CreateQuery1,
		GetImmediateContext3,
		CreateDeferredContext3,
		WriteToSubresource,
		ReadFromSubresource,

		/* ID3D11Device4 */
		RegisterDeviceRemovedEvent,
		UnregisterDeviceRemoved,

		VTableSize,
	};

	enum class ID3D11Device5 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11Device */
		CreateBuffer,
		CreateTexture1D,
		CreateTexture2D,
		CreateTexture3D,
		CreateShaderResourceView,
		CreateUnorderedAccessView,
		CreateRenderTargetView,
		CreateDepthStencilView,
		CreateInputLayout,
		CreateVertexShader,
		CreateGeometryShader,
		CreateGeometryShaderWithStreamOutput,
		CreatePixelShader,
		CreateHullShader,
		CreateDomainShader,
		CreateComputeShader,
		CreateClassLinkage,
		CreateBlendState,
		CreateDepthStencilState,
		CreateRasterizerState,
		CreateSamplerState,
		CreateQuery,
		CreatePredicate,
		CreateCounter,
		CreateDeferredContext,
		OpenSharedResource,
		CheckFormatSupport,
		CheckMultisampleQualityLevels,
		CheckCounterInfo,
		CheckCounter,
		CheckFeatureSupport,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		GetFeatureLevel,
		GetCreationFlags,
		GetDeviceRemovedReason,
		GetImmediateContext,
		SetExceptionMode,
		GetExceptionMode,

		/* ID3D11Device1 */
		GetImmediateContext1,
		CreateDeferredContext1,
		CreateBlendState1,
		CreateRasterizerState1,
		CreateDeviceContextState,
		OpenSharedResource1,
		OpenSharedResourceByName,

		/* ID3D11Device2 */
		GetImmediateContext2,
		CreateDeferredContext2,
		GetResourceTiling,
		CheckMultisampleQualityLevels1,

		/* ID3D11Device3 */
		CreateTexture2D1,
		CreateTexture3D1,
		CreateRasterizerState2,
		CreateShaderResourceView1,
		CreateUnorderedAccessView1,
		CreateRenderTargetView1,
		CreateQuery1,
		GetImmediateContext3,
		CreateDeferredContext3,
		WriteToSubresource,
		ReadFromSubresource,

		/* ID3D11Device4 */
		RegisterDeviceRemovedEvent,
		UnregisterDeviceRemoved,

		/* ID3D11Device5 */
		OpenSharedFence,
		CreateFence,

		VTableSize,
	};

	enum class ID3D11Multithread : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11Multithread */
		Enter,
		Leave,
		SetMultithreadProtected,
		GetMultithreadProtected,

		VTableSize,
	};

	enum class ID3D11VideoContext2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11VideoContext */
		GetDecoderBuffer,
		ReleaseDecoderBuffer,
		DecoderBeginFrame,
		DecoderEndFrame,
		SubmitDecoderBuffers,
		DecoderExtension,
		VideoProcessorSetOutputTargetRect,
		VideoProcessorSetOutputBackgroundColor,
		VideoProcessorSetOutputColorSpace,
		VideoProcessorSetOutputAlphaFillMode,
		VideoProcessorSetOutputConstriction,
		VideoProcessorSetOutputStereoMode,
		VideoProcessorSetOutputExtension,
		VideoProcessorGetOutputTargetRect,
		VideoProcessorGetOutputBackgroundColor,
		VideoProcessorGetOutputColorSpace,
		VideoProcessorGetOutputAlphaFillMode,
		VideoProcessorGetOutputConstriction,
		VideoProcessorGetOutputStereoMode,
		VideoProcessorGetOutputExtension,
		VideoProcessorSetStreamFrameFormat,
		VideoProcessorSetStreamColorSpace,
		VideoProcessorSetStreamOutputRate,
		VideoProcessorSetStreamSourceRect,
		VideoProcessorSetStreamDestRect,
		VideoProcessorSetStreamAlpha,
		VideoProcessorSetStreamPalette,
		VideoProcessorSetStreamPixelAspectRatio,
		VideoProcessorSetStreamLumaKey,
		VideoProcessorSetStreamStereoFormat,
		VideoProcessorSetStreamAutoProcessingMode,
		VideoProcessorSetStreamFilter,
		VideoProcessorSetStreamExtension,
		VideoProcessorGetStreamFrameFormat,
		VideoProcessorGetStreamColorSpace,
		VideoProcessorGetStreamOutputRate,
		VideoProcessorGetStreamSourceRect,
		VideoProcessorGetStreamDestRect,
		VideoProcessorGetStreamAlpha,
		VideoProcessorGetStreamPalette,
		VideoProcessorGetStreamPixelAspectRatio,
		VideoProcessorGetStreamLumaKey,
		VideoProcessorGetStreamStereoFormat,
		VideoProcessorGetStreamAutoProcessingMode,
		VideoProcessorGetStreamFilter,
		VideoProcessorGetStreamExtension,
		VideoProcessorBlt,
		NegotiateCryptoSessionKeyExchange,
		EncryptionBlt,
		DecryptionBlt,
		StartSessionKeyRefresh,
		FinishSessionKeyRefresh,
		GetEncryptionBltKey,
		NegotiateAuthenticatedChannelKeyExchange,
		QueryAuthenticatedChannel,
		ConfigureAuthenticatedChannel,
		VideoProcessorSetStreamRotation,
		VideoProcessorGetStreamRotation,

		/* ID3D11VideoContext1 */
		SubmitDecoderBuffers1,
		GetDataForNewHardwareKey,
		CheckCryptoSessionStatus,
		DecoderEnableDownsampling,
		DecoderUpdateDownsampling,
		VideoProcessorSetOutputColorSpace1,
		VideoProcessorSetOutputShaderUsage,
		VideoProcessorGetOutputColorSpace1,
		VideoProcessorGetOutputShaderUsage,
		VideoProcessorSetStreamColorSpace1,
		VideoProcessorSetStreamMirror,
		VideoProcessorGetStreamColorSpace1,
		VideoProcessorGetStreamMirror,
		VideoProcessorGetBehaviorHints,

		/* ID3D11VideoContext2 */
		VideoProcessorSetOutputHDRMetaData,
		VideoProcessorGetOutputHDRMetaData,
		VideoProcessorSetStreamHDRMetaData,
		VideoProcessorGetStreamHDRMetaData,

		VTableSize,
	};

	enum class ID3D11VideoDevice2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11VideoDevice */
		CreateVideoDecoder,
		CreateVideoProcessor,
		CreateAuthenticatedChannel,
		CreateCryptoSession,
		CreateVideoDecoderOutputView,
		CreateVideoProcessorInputView,
		CreateVideoProcessorOutputView,
		CreateVideoProcessorEnumerator,
		GetVideoDecoderProfileCount,
		GetVideoDecoderProfile,
		CheckVideoDecoderFormat,
		GetVideoDecoderConfigCount,
		GetVideoDecoderConfig,
		GetContentProtectionCaps,
		CheckCryptoKeyExchange,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11VideoDevice1 */
		GetCryptoSessionPrivateDataSize,
		GetVideoDecoderCaps,
		CheckVideoDecoderDownsampling,
		RecommendVideoDecoderDownsampleParameters,

		/* ID3D11VideoDevice2 */
		CheckFeatureSupport,
		NegotiateCryptoSessionKeyExchangeMT,

		VTableSize,
	};

	enum class ID3D11VideoContext3 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D11DeviceChild */
		GetDevice,
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,

		/* ID3D11VideoContext */
		GetDecoderBuffer,
		ReleaseDecoderBuffer,
		DecoderBeginFrame,
		DecoderEndFrame,
		SubmitDecoderBuffers,
		DecoderExtension,
		VideoProcessorSetOutputTargetRect,
		VideoProcessorSetOutputBackgroundColor,
		VideoProcessorSetOutputColorSpace,
		VideoProcessorSetOutputAlphaFillMode,
		VideoProcessorSetOutputConstriction,
		VideoProcessorSetOutputStereoMode,
		VideoProcessorSetOutputExtension,
		VideoProcessorGetOutputTargetRect,
		VideoProcessorGetOutputBackgroundColor,
		VideoProcessorGetOutputColorSpace,
		VideoProcessorGetOutputAlphaFillMode,
		VideoProcessorGetOutputConstriction,
		VideoProcessorGetOutputStereoMode,
		VideoProcessorGetOutputExtension,
		VideoProcessorSetStreamFrameFormat,
		VideoProcessorSetStreamColorSpace,
		VideoProcessorSetStreamOutputRate,
		VideoProcessorSetStreamSourceRect,
		VideoProcessorSetStreamDestRect,
		VideoProcessorSetStreamAlpha,
		VideoProcessorSetStreamPalette,
		VideoProcessorSetStreamPixelAspectRatio,
		VideoProcessorSetStreamLumaKey,
		VideoProcessorSetStreamStereoFormat,
		VideoProcessorSetStreamAutoProcessingMode,
		VideoProcessorSetStreamFilter,
		VideoProcessorSetStreamExtension,
		VideoProcessorGetStreamFrameFormat,
		VideoProcessorGetStreamColorSpace,
		VideoProcessorGetStreamOutputRate,
		VideoProcessorGetStreamSourceRect,
		VideoProcessorGetStreamDestRect,
		VideoProcessorGetStreamAlpha,
		VideoProcessorGetStreamPalette,
		VideoProcessorGetStreamPixelAspectRatio,
		VideoProcessorGetStreamLumaKey,
		VideoProcessorGetStreamStereoFormat,
		VideoProcessorGetStreamAutoProcessingMode,
		VideoProcessorGetStreamFilter,
		VideoProcessorGetStreamExtension,
		VideoProcessorBlt,
		NegotiateCryptoSessionKeyExchange,
		EncryptionBlt,
		DecryptionBlt,
		StartSessionKeyRefresh,
		FinishSessionKeyRefresh,
		GetEncryptionBltKey,
		NegotiateAuthenticatedChannelKeyExchange,
		QueryAuthenticatedChannel,
		ConfigureAuthenticatedChannel,
		VideoProcessorSetStreamRotation,
		VideoProcessorGetStreamRotation,

		/* ID3D11VideoContext1 */
		SubmitDecoderBuffers1,
		GetDataForNewHardwareKey,
		CheckCryptoSessionStatus,
		DecoderEnableDownsampling,
		DecoderUpdateDownsampling,
		VideoProcessorSetOutputColorSpace1,
		VideoProcessorSetOutputShaderUsage,
		VideoProcessorGetOutputColorSpace1,
		VideoProcessorGetOutputShaderUsage,
		VideoProcessorSetStreamColorSpace1,
		VideoProcessorSetStreamMirror,
		VideoProcessorGetStreamColorSpace1,
		VideoProcessorGetStreamMirror,
		VideoProcessorGetBehaviorHints,

		/* ID3D11VideoContext2 */
		VideoProcessorSetOutputHDRMetaData,
		VideoProcessorGetOutputHDRMetaData,
		VideoProcessorSetStreamHDRMetaData,
		VideoProcessorGetStreamHDRMetaData,

		/* ID3D11VideoContext3 */
		DecoderBeginFrame1,
		SubmitDecoderBuffers2,

		VTableSize,
	};

}
