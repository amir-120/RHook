#pragma once

#include <d3d12.h>

namespace D3D12MethodParameters
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

	class ID3D12Object : IUnknown
	{
	public:
		//Virtual
		struct GetPrivateData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D12Object* pThis;
			const ::GUID& guid;
			::UINT* pDataSize;
			void* pData;
		};

		//Virtual
		struct SetPrivateData
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D12Object* pThis;
			const ::GUID& guid;
			::UINT DataSize;
			const void* pData;
		};

		//Virtual
		struct SetPrivateDataInterface
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D12Object* pThis;
			const ::GUID& guid;
			const ::IUnknown* pData;
		};

		//Virtual
		struct SetName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D12Object* pThis;
			::LPCWSTR Name;
		};

	private:
		 virtual ~ID3D12Object() = 0;
	};

	class ID3D12DeviceChild : ID3D12Object
	{
	public:
		//Virtual
		struct GetDevice
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D12DeviceChild* pThis;
			const ::IID& riid;
			void** ppvDevice;
		};

	private:
		 virtual ~ID3D12DeviceChild() = 0;
	};

	class ID3D12RootSignatureDeserializer : IUnknown
	{
	public:
		//Virtual
		struct GetRootSignatureDesc
		{
			using ReturnType_t = const ::D3D12_ROOT_SIGNATURE_DESC*;
			static constexpr size_t Argc = 1;

			::ID3D12RootSignatureDeserializer* pThis;
		};

	private:
		 virtual ~ID3D12RootSignatureDeserializer() = 0;
	};

	class ID3D12VersionedRootSignatureDeserializer : IUnknown
	{
	public:
		//Virtual
		struct GetRootSignatureDescAtVersion
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D12VersionedRootSignatureDeserializer* pThis;
			::D3D_ROOT_SIGNATURE_VERSION convertToVersion;
			const ::D3D12_VERSIONED_ROOT_SIGNATURE_DESC** ppDesc;
		};

		//Virtual
		struct GetUnconvertedRootSignatureDesc
		{
			using ReturnType_t = const ::D3D12_VERSIONED_ROOT_SIGNATURE_DESC*;
			static constexpr size_t Argc = 1;

			::ID3D12VersionedRootSignatureDeserializer* pThis;
		};

	private:
		 virtual ~ID3D12VersionedRootSignatureDeserializer() = 0;
	};

	class ID3D12Pageable : ID3D12DeviceChild
	{
	public:
	private:
		 virtual ~ID3D12Pageable() = 0;
	};

	class ID3D12Heap : ID3D12Pageable
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = ::D3D12_HEAP_DESC;
			static constexpr size_t Argc = 1;

			::ID3D12Heap* pThis;
		};

	private:
		 virtual ~ID3D12Heap() = 0;
	};

	class ID3D12Resource : ID3D12Pageable
	{
	public:
		//Virtual
		struct Map
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D12Resource* pThis;
			::UINT Subresource;
			const ::D3D12_RANGE* pReadRange;
			void** ppData;
		};

		//Virtual
		struct Unmap
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D12Resource* pThis;
			::UINT Subresource;
			const ::D3D12_RANGE* pWrittenRange;
		};

		//Virtual
		struct GetDesc
		{
			using ReturnType_t = ::D3D12_RESOURCE_DESC;
			static constexpr size_t Argc = 1;

			::ID3D12Resource* pThis;
		};

		//Virtual
		struct GetGPUVirtualAddress
		{
			using ReturnType_t = ::D3D12_GPU_VIRTUAL_ADDRESS;
			static constexpr size_t Argc = 1;

			::ID3D12Resource* pThis;
		};

		//Virtual
		struct WriteToSubresource
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::ID3D12Resource* pThis;
			::UINT DstSubresource;
			const ::D3D12_BOX* pDstBox;
			const void* pSrcData;
			::UINT SrcRowPitch;
			::UINT SrcDepthPitch;
		};

		//Virtual
		struct ReadFromSubresource
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::ID3D12Resource* pThis;
			void* pDstData;
			::UINT DstRowPitch;
			::UINT DstDepthPitch;
			::UINT SrcSubresource;
			const ::D3D12_BOX* pSrcBox;
		};

		//Virtual
		struct GetHeapProperties
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D12Resource* pThis;
			::D3D12_HEAP_PROPERTIES* pHeapProperties;
			::D3D12_HEAP_FLAGS* pHeapFlags;
		};

	private:
		 virtual ~ID3D12Resource() = 0;
	};

	class ID3D12CommandAllocator : ID3D12Pageable
	{
	public:
		//Virtual
		struct Reset
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ID3D12CommandAllocator* pThis;
		};

	private:
		 virtual ~ID3D12CommandAllocator() = 0;
	};

	class ID3D12Fence : ID3D12Pageable
	{
	public:
		//Virtual
		struct GetCompletedValue
		{
			using ReturnType_t = ::UINT64;
			static constexpr size_t Argc = 1;

			::ID3D12Fence* pThis;
		};

		//Virtual
		struct SetEventOnCompletion
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D12Fence* pThis;
			::UINT64 Value;
			::HANDLE hEvent;
		};

		//Virtual
		struct Signal
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D12Fence* pThis;
			::UINT64 Value;
		};

	private:
		 virtual ~ID3D12Fence() = 0;
	};

	class ID3D12Fence1 : ID3D12Fence
	{
	public:
		//Virtual
		struct GetCreationFlags
		{
			using ReturnType_t = ::D3D12_FENCE_FLAGS;
			static constexpr size_t Argc = 1;

			::ID3D12Fence1* pThis;
		};

	private:
		 virtual ~ID3D12Fence1() = 0;
	};

	class ID3D12PipelineState : ID3D12Pageable
	{
	public:
		//Virtual
		struct GetCachedBlob
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D12PipelineState* pThis;
			::ID3DBlob** ppBlob;
		};

	private:
		 virtual ~ID3D12PipelineState() = 0;
	};

	class ID3D12DescriptorHeap : ID3D12Pageable
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = ::D3D12_DESCRIPTOR_HEAP_DESC;
			static constexpr size_t Argc = 1;

			::ID3D12DescriptorHeap* pThis;
		};

		//Virtual
		struct GetCPUDescriptorHandleForHeapStart
		{
			using ReturnType_t = ::D3D12_CPU_DESCRIPTOR_HANDLE;
			static constexpr size_t Argc = 1;

			::ID3D12DescriptorHeap* pThis;
		};

		//Virtual
		struct GetGPUDescriptorHandleForHeapStart
		{
			using ReturnType_t = ::D3D12_GPU_DESCRIPTOR_HANDLE;
			static constexpr size_t Argc = 1;

			::ID3D12DescriptorHeap* pThis;
		};

	private:
		 virtual ~ID3D12DescriptorHeap() = 0;
	};

	class ID3D12CommandList : ID3D12DeviceChild
	{
	public:
		//Virtual
		struct GetType
		{
			using ReturnType_t = ::D3D12_COMMAND_LIST_TYPE;
			static constexpr size_t Argc = 1;

			::ID3D12CommandList* pThis;
		};

	private:
		 virtual ~ID3D12CommandList() = 0;
	};

	class ID3D12GraphicsCommandList : ID3D12CommandList
	{
	public:
		//Virtual
		struct Close
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ID3D12GraphicsCommandList* pThis;
		};

		//Virtual
		struct Reset
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D12GraphicsCommandList* pThis;
			::ID3D12CommandAllocator* pAllocator;
			::ID3D12PipelineState* pInitialState;
		};

		//Virtual
		struct ClearState
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D12GraphicsCommandList* pThis;
			::ID3D12PipelineState* pPipelineState;
		};

		//Virtual
		struct DrawInstanced
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 5;

			::ID3D12GraphicsCommandList* pThis;
			::UINT VertexCountPerInstance;
			::UINT InstanceCount;
			::UINT StartVertexLocation;
			::UINT StartInstanceLocation;
		};

		//Virtual
		struct DrawIndexedInstanced
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D12GraphicsCommandList* pThis;
			::UINT IndexCountPerInstance;
			::UINT InstanceCount;
			::UINT StartIndexLocation;
			::INT BaseVertexLocation;
			::UINT StartInstanceLocation;
		};

		//Virtual
		struct Dispatch
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D12GraphicsCommandList* pThis;
			::UINT ThreadGroupCountX;
			::UINT ThreadGroupCountY;
			::UINT ThreadGroupCountZ;
		};

		//Virtual
		struct CopyBufferRegion
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D12GraphicsCommandList* pThis;
			::ID3D12Resource* pDstBuffer;
			::UINT64 DstOffset;
			::ID3D12Resource* pSrcBuffer;
			::UINT64 SrcOffset;
			::UINT64 NumBytes;
		};

		//Virtual
		struct CopyTextureRegion
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 7;

			::ID3D12GraphicsCommandList* pThis;
			const ::D3D12_TEXTURE_COPY_LOCATION* pDst;
			::UINT DstX;
			::UINT DstY;
			::UINT DstZ;
			const ::D3D12_TEXTURE_COPY_LOCATION* pSrc;
			const ::D3D12_BOX* pSrcBox;
		};

		//Virtual
		struct CopyResource
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D12GraphicsCommandList* pThis;
			::ID3D12Resource* pDstResource;
			::ID3D12Resource* pSrcResource;
		};

		//Virtual
		struct CopyTiles
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 7;

			::ID3D12GraphicsCommandList* pThis;
			::ID3D12Resource* pTiledResource;
			const ::D3D12_TILED_RESOURCE_COORDINATE* pTileRegionStartCoordinate;
			const ::D3D12_TILE_REGION_SIZE* pTileRegionSize;
			::ID3D12Resource* pBuffer;
			::UINT64 BufferStartOffsetInBytes;
			::D3D12_TILE_COPY_FLAGS Flags;
		};

		//Virtual
		struct ResolveSubresource
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 6;

			::ID3D12GraphicsCommandList* pThis;
			::ID3D12Resource* pDstResource;
			::UINT DstSubresource;
			::ID3D12Resource* pSrcResource;
			::UINT SrcSubresource;
			::DXGI_FORMAT Format;
		};

		//Virtual
		struct IASetPrimitiveTopology
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D12GraphicsCommandList* pThis;
			::D3D12_PRIMITIVE_TOPOLOGY PrimitiveTopology;
		};

		//Virtual
		struct RSSetViewports
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D12GraphicsCommandList* pThis;
			::UINT NumViewports;
			const ::D3D12_VIEWPORT* pViewports;
		};

		//Virtual
		struct RSSetScissorRects
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D12GraphicsCommandList* pThis;
			::UINT NumRects;
			const ::D3D12_RECT* pRects;
		};

		//Virtual
		struct OMSetBlendFactor
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D12GraphicsCommandList* pThis;
			const ::FLOAT BlendFactor[4];
		};

		//Virtual
		struct OMSetStencilRef
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D12GraphicsCommandList* pThis;
			::UINT StencilRef;
		};

		//Virtual
		struct SetPipelineState
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D12GraphicsCommandList* pThis;
			::ID3D12PipelineState* pPipelineState;
		};

		//Virtual
		struct ResourceBarrier
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D12GraphicsCommandList* pThis;
			::UINT NumBarriers;
			const ::D3D12_RESOURCE_BARRIER* pBarriers;
		};

		//Virtual
		struct ExecuteBundle
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D12GraphicsCommandList* pThis;
			::ID3D12GraphicsCommandList* pCommandList;
		};

		//Virtual
		struct SetDescriptorHeaps
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D12GraphicsCommandList* pThis;
			::UINT NumDescriptorHeaps;
			::ID3D12DescriptorHeap*const* ppDescriptorHeaps;
		};

		//Virtual
		struct SetComputeRootSignature
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D12GraphicsCommandList* pThis;
			::ID3D12RootSignature* pRootSignature;
		};

		//Virtual
		struct SetGraphicsRootSignature
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D12GraphicsCommandList* pThis;
			::ID3D12RootSignature* pRootSignature;
		};

		//Virtual
		struct SetComputeRootDescriptorTable
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D12GraphicsCommandList* pThis;
			::UINT RootParameterIndex;
			::D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor;
		};

		//Virtual
		struct SetGraphicsRootDescriptorTable
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D12GraphicsCommandList* pThis;
			::UINT RootParameterIndex;
			::D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor;
		};

		//Virtual
		struct SetComputeRoot32BitConstant
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D12GraphicsCommandList* pThis;
			::UINT RootParameterIndex;
			::UINT SrcData;
			::UINT DestOffsetIn32BitValues;
		};

		//Virtual
		struct SetGraphicsRoot32BitConstant
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D12GraphicsCommandList* pThis;
			::UINT RootParameterIndex;
			::UINT SrcData;
			::UINT DestOffsetIn32BitValues;
		};

		//Virtual
		struct SetComputeRoot32BitConstants
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 5;

			::ID3D12GraphicsCommandList* pThis;
			::UINT RootParameterIndex;
			::UINT Num32BitValuesToSet;
			const void* pSrcData;
			::UINT DestOffsetIn32BitValues;
		};

		//Virtual
		struct SetGraphicsRoot32BitConstants
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 5;

			::ID3D12GraphicsCommandList* pThis;
			::UINT RootParameterIndex;
			::UINT Num32BitValuesToSet;
			const void* pSrcData;
			::UINT DestOffsetIn32BitValues;
		};

		//Virtual
		struct SetComputeRootConstantBufferView
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D12GraphicsCommandList* pThis;
			::UINT RootParameterIndex;
			::D3D12_GPU_VIRTUAL_ADDRESS BufferLocation;
		};

		//Virtual
		struct SetGraphicsRootConstantBufferView
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D12GraphicsCommandList* pThis;
			::UINT RootParameterIndex;
			::D3D12_GPU_VIRTUAL_ADDRESS BufferLocation;
		};

		//Virtual
		struct SetComputeRootShaderResourceView
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D12GraphicsCommandList* pThis;
			::UINT RootParameterIndex;
			::D3D12_GPU_VIRTUAL_ADDRESS BufferLocation;
		};

		//Virtual
		struct SetGraphicsRootShaderResourceView
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D12GraphicsCommandList* pThis;
			::UINT RootParameterIndex;
			::D3D12_GPU_VIRTUAL_ADDRESS BufferLocation;
		};

		//Virtual
		struct SetComputeRootUnorderedAccessView
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D12GraphicsCommandList* pThis;
			::UINT RootParameterIndex;
			::D3D12_GPU_VIRTUAL_ADDRESS BufferLocation;
		};

		//Virtual
		struct SetGraphicsRootUnorderedAccessView
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D12GraphicsCommandList* pThis;
			::UINT RootParameterIndex;
			::D3D12_GPU_VIRTUAL_ADDRESS BufferLocation;
		};

		//Virtual
		struct IASetIndexBuffer
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D12GraphicsCommandList* pThis;
			const ::D3D12_INDEX_BUFFER_VIEW* pView;
		};

		//Virtual
		struct IASetVertexBuffers
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D12GraphicsCommandList* pThis;
			::UINT StartSlot;
			::UINT NumViews;
			const ::D3D12_VERTEX_BUFFER_VIEW* pViews;
		};

		//Virtual
		struct SOSetTargets
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D12GraphicsCommandList* pThis;
			::UINT StartSlot;
			::UINT NumViews;
			const ::D3D12_STREAM_OUTPUT_BUFFER_VIEW* pViews;
		};

		//Virtual
		struct OMSetRenderTargets
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 5;

			::ID3D12GraphicsCommandList* pThis;
			::UINT NumRenderTargetDescriptors;
			const ::D3D12_CPU_DESCRIPTOR_HANDLE* pRenderTargetDescriptors;
			::BOOL RTsSingleHandleToDescriptorRange;
			const ::D3D12_CPU_DESCRIPTOR_HANDLE* pDepthStencilDescriptor;
		};

		//Virtual
		struct ClearDepthStencilView
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 7;

			::ID3D12GraphicsCommandList* pThis;
			::D3D12_CPU_DESCRIPTOR_HANDLE DepthStencilView;
			::D3D12_CLEAR_FLAGS ClearFlags;
			::FLOAT Depth;
			::UINT8 Stencil;
			::UINT NumRects;
			const ::D3D12_RECT* pRects;
		};

		//Virtual
		struct ClearRenderTargetView
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 5;

			::ID3D12GraphicsCommandList* pThis;
			::D3D12_CPU_DESCRIPTOR_HANDLE RenderTargetView;
			const ::FLOAT ColorRGBA[4];
			::UINT NumRects;
			const ::D3D12_RECT* pRects;
		};

		//Virtual
		struct ClearUnorderedAccessViewUint
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 7;

			::ID3D12GraphicsCommandList* pThis;
			::D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap;
			::D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle;
			::ID3D12Resource* pResource;
			const ::UINT Values[4];
			::UINT NumRects;
			const ::D3D12_RECT* pRects;
		};

		//Virtual
		struct ClearUnorderedAccessViewFloat
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 7;

			::ID3D12GraphicsCommandList* pThis;
			::D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap;
			::D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle;
			::ID3D12Resource* pResource;
			const ::FLOAT Values[4];
			::UINT NumRects;
			const ::D3D12_RECT* pRects;
		};

		//Virtual
		struct DiscardResource
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D12GraphicsCommandList* pThis;
			::ID3D12Resource* pResource;
			const ::D3D12_DISCARD_REGION* pRegion;
		};

		//Virtual
		struct BeginQuery
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D12GraphicsCommandList* pThis;
			::ID3D12QueryHeap* pQueryHeap;
			::D3D12_QUERY_TYPE Type;
			::UINT Index;
		};

		//Virtual
		struct EndQuery
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D12GraphicsCommandList* pThis;
			::ID3D12QueryHeap* pQueryHeap;
			::D3D12_QUERY_TYPE Type;
			::UINT Index;
		};

		//Virtual
		struct ResolveQueryData
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 7;

			::ID3D12GraphicsCommandList* pThis;
			::ID3D12QueryHeap* pQueryHeap;
			::D3D12_QUERY_TYPE Type;
			::UINT StartIndex;
			::UINT NumQueries;
			::ID3D12Resource* pDestinationBuffer;
			::UINT64 AlignedDestinationBufferOffset;
		};

		//Virtual
		struct SetPredication
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D12GraphicsCommandList* pThis;
			::ID3D12Resource* pBuffer;
			::UINT64 AlignedBufferOffset;
			::D3D12_PREDICATION_OP Operation;
		};

		//Virtual
		struct SetMarker
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D12GraphicsCommandList* pThis;
			::UINT Metadata;
			const void* pData;
			::UINT Size;
		};

		//Virtual
		struct BeginEvent
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D12GraphicsCommandList* pThis;
			::UINT Metadata;
			const void* pData;
			::UINT Size;
		};

		//Virtual
		struct EndEvent
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D12GraphicsCommandList* pThis;
		};

		//Virtual
		struct ExecuteIndirect
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 7;

			::ID3D12GraphicsCommandList* pThis;
			::ID3D12CommandSignature* pCommandSignature;
			::UINT MaxCommandCount;
			::ID3D12Resource* pArgumentBuffer;
			::UINT64 ArgumentBufferOffset;
			::ID3D12Resource* pCountBuffer;
			::UINT64 CountBufferOffset;
		};

	private:
		 virtual ~ID3D12GraphicsCommandList() = 0;
	};

	class ID3D12GraphicsCommandList1 : ID3D12GraphicsCommandList
	{
	public:
		//Virtual
		struct AtomicCopyBufferUINT
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 8;

			::ID3D12GraphicsCommandList1* pThis;
			::ID3D12Resource* pDstBuffer;
			::UINT64 DstOffset;
			::ID3D12Resource* pSrcBuffer;
			::UINT64 SrcOffset;
			::UINT Dependencies;
			::ID3D12Resource*const* ppDependentResources;
			const ::D3D12_SUBRESOURCE_RANGE_UINT64* pDependentSubresourceRanges;
		};

		//Virtual
		struct AtomicCopyBufferUINT64
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 8;

			::ID3D12GraphicsCommandList1* pThis;
			::ID3D12Resource* pDstBuffer;
			::UINT64 DstOffset;
			::ID3D12Resource* pSrcBuffer;
			::UINT64 SrcOffset;
			::UINT Dependencies;
			::ID3D12Resource*const* ppDependentResources;
			const ::D3D12_SUBRESOURCE_RANGE_UINT64* pDependentSubresourceRanges;
		};

		//Virtual
		struct OMSetDepthBounds
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D12GraphicsCommandList1* pThis;
			::FLOAT Min;
			::FLOAT Max;
		};

		//Virtual
		struct SetSamplePositions
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D12GraphicsCommandList1* pThis;
			::UINT NumSamplesPerPixel;
			::UINT NumPixels;
			::D3D12_SAMPLE_POSITION* pSamplePositions;
		};

		//Virtual
		struct ResolveSubresourceRegion
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 10;

			::ID3D12GraphicsCommandList1* pThis;
			::ID3D12Resource* pDstResource;
			::UINT DstSubresource;
			::UINT DstX;
			::UINT DstY;
			::ID3D12Resource* pSrcResource;
			::UINT SrcSubresource;
			::D3D12_RECT* pSrcRect;
			::DXGI_FORMAT Format;
			::D3D12_RESOLVE_MODE ResolveMode;
		};

		//Virtual
		struct SetViewInstanceMask
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D12GraphicsCommandList1* pThis;
			::UINT Mask;
		};

	private:
		 virtual ~ID3D12GraphicsCommandList1() = 0;
	};

	class ID3D12GraphicsCommandList2 : ID3D12GraphicsCommandList1
	{
	public:
		//Virtual
		struct WriteBufferImmediate
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D12GraphicsCommandList2* pThis;
			::UINT Count;
			const ::D3D12_WRITEBUFFERIMMEDIATE_PARAMETER* pParams;
			const ::D3D12_WRITEBUFFERIMMEDIATE_MODE* pModes;
		};

	private:
		 virtual ~ID3D12GraphicsCommandList2() = 0;
	};

	class ID3D12CommandQueue : ID3D12Pageable
	{
	public:
		//Virtual
		struct UpdateTileMappings
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 11;

			::ID3D12CommandQueue* pThis;
			::ID3D12Resource* pResource;
			::UINT NumResourceRegions;
			const ::D3D12_TILED_RESOURCE_COORDINATE* pResourceRegionStartCoordinates;
			const ::D3D12_TILE_REGION_SIZE* pResourceRegionSizes;
			::ID3D12Heap* pHeap;
			::UINT NumRanges;
			const ::D3D12_TILE_RANGE_FLAGS* pRangeFlags;
			const ::UINT* pHeapRangeStartOffsets;
			const ::UINT* pRangeTileCounts;
			::D3D12_TILE_MAPPING_FLAGS Flags;
		};

		//Virtual
		struct CopyTileMappings
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 7;

			::ID3D12CommandQueue* pThis;
			::ID3D12Resource* pDstResource;
			const ::D3D12_TILED_RESOURCE_COORDINATE* pDstRegionStartCoordinate;
			::ID3D12Resource* pSrcResource;
			const ::D3D12_TILED_RESOURCE_COORDINATE* pSrcRegionStartCoordinate;
			const ::D3D12_TILE_REGION_SIZE* pRegionSize;
			::D3D12_TILE_MAPPING_FLAGS Flags;
		};

		//Virtual
		struct ExecuteCommandLists
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D12CommandQueue* pThis;
			::UINT NumCommandLists;
			::ID3D12CommandList*const* ppCommandLists;
		};

		//Virtual
		struct SetMarker
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D12CommandQueue* pThis;
			::UINT Metadata;
			const void* pData;
			::UINT Size;
		};

		//Virtual
		struct BeginEvent
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D12CommandQueue* pThis;
			::UINT Metadata;
			const void* pData;
			::UINT Size;
		};

		//Virtual
		struct EndEvent
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D12CommandQueue* pThis;
		};

		//Virtual
		struct Signal
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D12CommandQueue* pThis;
			::ID3D12Fence* pFence;
			::UINT64 Value;
		};

		//Virtual
		struct Wait
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D12CommandQueue* pThis;
			::ID3D12Fence* pFence;
			::UINT64 Value;
		};

		//Virtual
		struct GetTimestampFrequency
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D12CommandQueue* pThis;
			::UINT64* pFrequency;
		};

		//Virtual
		struct GetClockCalibration
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D12CommandQueue* pThis;
			::UINT64* pGpuTimestamp;
			::UINT64* pCpuTimestamp;
		};

		//Virtual
		struct GetDesc
		{
			using ReturnType_t = ::D3D12_COMMAND_QUEUE_DESC;
			static constexpr size_t Argc = 1;

			::ID3D12CommandQueue* pThis;
		};

	private:
		 virtual ~ID3D12CommandQueue() = 0;
	};

	class ID3D12Device : ID3D12Object
	{
	public:
		//Virtual
		struct GetNodeCount
		{
			using ReturnType_t = ::UINT;
			static constexpr size_t Argc = 1;

			::ID3D12Device* pThis;
		};

		//Virtual
		struct CreateCommandQueue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D12Device* pThis;
			const ::D3D12_COMMAND_QUEUE_DESC* pDesc;
			const ::IID& riid;
			void** ppCommandQueue;
		};

		//Virtual
		struct CreateCommandAllocator
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D12Device* pThis;
			::D3D12_COMMAND_LIST_TYPE type;
			const ::IID& riid;
			void** ppCommandAllocator;
		};

		//Virtual
		struct CreateGraphicsPipelineState
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D12Device* pThis;
			const ::D3D12_GRAPHICS_PIPELINE_STATE_DESC* pDesc;
			const ::IID& riid;
			void** ppPipelineState;
		};

		//Virtual
		struct CreateComputePipelineState
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D12Device* pThis;
			const ::D3D12_COMPUTE_PIPELINE_STATE_DESC* pDesc;
			const ::IID& riid;
			void** ppPipelineState;
		};

		//Virtual
		struct CreateCommandList
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 7;

			::ID3D12Device* pThis;
			::UINT nodeMask;
			::D3D12_COMMAND_LIST_TYPE type;
			::ID3D12CommandAllocator* pCommandAllocator;
			::ID3D12PipelineState* pInitialState;
			const ::IID& riid;
			void** ppCommandList;
		};

		//Virtual
		struct CheckFeatureSupport
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D12Device* pThis;
			::D3D12_FEATURE Feature;
			void* pFeatureSupportData;
			::UINT FeatureSupportDataSize;
		};

		//Virtual
		struct CreateDescriptorHeap
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D12Device* pThis;
			const ::D3D12_DESCRIPTOR_HEAP_DESC* pDescriptorHeapDesc;
			const ::IID& riid;
			void** ppvHeap;
		};

		//Virtual
		struct GetDescriptorHandleIncrementSize
		{
			using ReturnType_t = ::UINT;
			static constexpr size_t Argc = 2;

			::ID3D12Device* pThis;
			::D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapType;
		};

		//Virtual
		struct CreateRootSignature
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::ID3D12Device* pThis;
			::UINT nodeMask;
			const void* pBlobWithRootSignature;
			::SIZE_T blobLengthInBytes;
			const ::IID& riid;
			void** ppvRootSignature;
		};

		//Virtual
		struct CreateConstantBufferView
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D12Device* pThis;
			const ::D3D12_CONSTANT_BUFFER_VIEW_DESC* pDesc;
			::D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor;
		};

		//Virtual
		struct CreateShaderResourceView
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D12Device* pThis;
			::ID3D12Resource* pResource;
			const ::D3D12_SHADER_RESOURCE_VIEW_DESC* pDesc;
			::D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor;
		};

		//Virtual
		struct CreateUnorderedAccessView
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 5;

			::ID3D12Device* pThis;
			::ID3D12Resource* pResource;
			::ID3D12Resource* pCounterResource;
			const ::D3D12_UNORDERED_ACCESS_VIEW_DESC* pDesc;
			::D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor;
		};

		//Virtual
		struct CreateRenderTargetView
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D12Device* pThis;
			::ID3D12Resource* pResource;
			const ::D3D12_RENDER_TARGET_VIEW_DESC* pDesc;
			::D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor;
		};

		//Virtual
		struct CreateDepthStencilView
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D12Device* pThis;
			::ID3D12Resource* pResource;
			const ::D3D12_DEPTH_STENCIL_VIEW_DESC* pDesc;
			::D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor;
		};

		//Virtual
		struct CreateSampler
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D12Device* pThis;
			const ::D3D12_SAMPLER_DESC* pDesc;
			::D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor;
		};

		//Virtual
		struct CopyDescriptors
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 8;

			::ID3D12Device* pThis;
			::UINT NumDestDescriptorRanges;
			const ::D3D12_CPU_DESCRIPTOR_HANDLE* pDestDescriptorRangeStarts;
			const ::UINT* pDestDescriptorRangeSizes;
			::UINT NumSrcDescriptorRanges;
			const ::D3D12_CPU_DESCRIPTOR_HANDLE* pSrcDescriptorRangeStarts;
			const ::UINT* pSrcDescriptorRangeSizes;
			::D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType;
		};

		//Virtual
		struct CopyDescriptorsSimple
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 5;

			::ID3D12Device* pThis;
			::UINT NumDescriptors;
			::D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptorRangeStart;
			::D3D12_CPU_DESCRIPTOR_HANDLE SrcDescriptorRangeStart;
			::D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType;
		};

		//Virtual
		struct GetResourceAllocationInfo
		{
			using ReturnType_t = ::D3D12_RESOURCE_ALLOCATION_INFO;
			static constexpr size_t Argc = 4;

			::ID3D12Device* pThis;
			::UINT visibleMask;
			::UINT numResourceDescs;
			const ::D3D12_RESOURCE_DESC* pResourceDescs;
		};

		//Virtual
		struct GetCustomHeapProperties
		{
			using ReturnType_t = ::D3D12_HEAP_PROPERTIES;
			static constexpr size_t Argc = 3;

			::ID3D12Device* pThis;
			::UINT nodeMask;
			::D3D12_HEAP_TYPE heapType;
		};

		//Virtual
		struct CreateCommittedResource
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 8;

			::ID3D12Device* pThis;
			const ::D3D12_HEAP_PROPERTIES* pHeapProperties;
			::D3D12_HEAP_FLAGS HeapFlags;
			const ::D3D12_RESOURCE_DESC* pDesc;
			::D3D12_RESOURCE_STATES InitialResourceState;
			const ::D3D12_CLEAR_VALUE* pOptimizedClearValue;
			const ::IID& riidResource;
			void** ppvResource;
		};

		//Virtual
		struct CreateHeap
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D12Device* pThis;
			const ::D3D12_HEAP_DESC* pDesc;
			const ::IID& riid;
			void** ppvHeap;
		};

		//Virtual
		struct CreatePlacedResource
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 8;

			::ID3D12Device* pThis;
			::ID3D12Heap* pHeap;
			::UINT64 HeapOffset;
			const ::D3D12_RESOURCE_DESC* pDesc;
			::D3D12_RESOURCE_STATES InitialState;
			const ::D3D12_CLEAR_VALUE* pOptimizedClearValue;
			const ::IID& riid;
			void** ppvResource;
		};

		//Virtual
		struct CreateReservedResource
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::ID3D12Device* pThis;
			const ::D3D12_RESOURCE_DESC* pDesc;
			::D3D12_RESOURCE_STATES InitialState;
			const ::D3D12_CLEAR_VALUE* pOptimizedClearValue;
			const ::IID& riid;
			void** ppvResource;
		};

		//Virtual
		struct CreateSharedHandle
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::ID3D12Device* pThis;
			::ID3D12DeviceChild* pObject;
			const ::SECURITY_ATTRIBUTES* pAttributes;
			::DWORD Access;
			::LPCWSTR Name;
			::HANDLE* pHandle;
		};

		//Virtual
		struct OpenSharedHandle
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D12Device* pThis;
			::HANDLE NTHandle;
			const ::IID& riid;
			void** ppvObj;
		};

		//Virtual
		struct OpenSharedHandleByName
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D12Device* pThis;
			::LPCWSTR Name;
			::DWORD Access;
			::HANDLE* pNTHandle;
		};

		//Virtual
		struct MakeResident
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D12Device* pThis;
			::UINT NumObjects;
			::ID3D12Pageable*const* ppObjects;
		};

		//Virtual
		struct Evict
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D12Device* pThis;
			::UINT NumObjects;
			::ID3D12Pageable*const* ppObjects;
		};

		//Virtual
		struct CreateFence
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D12Device* pThis;
			::UINT64 InitialValue;
			::D3D12_FENCE_FLAGS Flags;
			const ::IID& riid;
			void** ppFence;
		};

		//Virtual
		struct GetDeviceRemovedReason
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ID3D12Device* pThis;
		};

		//Virtual
		struct GetCopyableFootprints
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 9;

			::ID3D12Device* pThis;
			const ::D3D12_RESOURCE_DESC* pResourceDesc;
			::UINT FirstSubresource;
			::UINT NumSubresources;
			::UINT64 BaseOffset;
			::D3D12_PLACED_SUBRESOURCE_FOOTPRINT* pLayouts;
			::UINT* pNumRows;
			::UINT64* pRowSizeInBytes;
			::UINT64* pTotalBytes;
		};

		//Virtual
		struct CreateQueryHeap
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D12Device* pThis;
			const ::D3D12_QUERY_HEAP_DESC* pDesc;
			const ::IID& riid;
			void** ppvHeap;
		};

		//Virtual
		struct SetStablePowerState
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D12Device* pThis;
			::BOOL Enable;
		};

		//Virtual
		struct CreateCommandSignature
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D12Device* pThis;
			const ::D3D12_COMMAND_SIGNATURE_DESC* pDesc;
			::ID3D12RootSignature* pRootSignature;
			const ::IID& riid;
			void** ppvCommandSignature;
		};

		//Virtual
		struct GetResourceTiling
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 8;

			::ID3D12Device* pThis;
			::ID3D12Resource* pTiledResource;
			::UINT* pNumTilesForEntireResource;
			::D3D12_PACKED_MIP_INFO* pPackedMipDesc;
			::D3D12_TILE_SHAPE* pStandardTileShapeForNonPackedMips;
			::UINT* pNumSubresourceTilings;
			::UINT FirstSubresourceTilingToGet;
			::D3D12_SUBRESOURCE_TILING* pSubresourceTilingsForNonPackedMips;
		};

		//Virtual
		struct GetAdapterLuid
		{
			using ReturnType_t = ::LUID;
			static constexpr size_t Argc = 1;

			::ID3D12Device* pThis;
		};

	private:
		 virtual ~ID3D12Device() = 0;
	};

	class ID3D12PipelineLibrary : ID3D12DeviceChild
	{
	public:
		//Virtual
		struct StorePipeline
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D12PipelineLibrary* pThis;
			::LPCWSTR pName;
			::ID3D12PipelineState* pPipeline;
		};

		//Virtual
		struct LoadGraphicsPipeline
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D12PipelineLibrary* pThis;
			::LPCWSTR pName;
			const ::D3D12_GRAPHICS_PIPELINE_STATE_DESC* pDesc;
			const ::IID& riid;
			void** ppPipelineState;
		};

		//Virtual
		struct LoadComputePipeline
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D12PipelineLibrary* pThis;
			::LPCWSTR pName;
			const ::D3D12_COMPUTE_PIPELINE_STATE_DESC* pDesc;
			const ::IID& riid;
			void** ppPipelineState;
		};

		//Virtual
		struct GetSerializedSize
		{
			using ReturnType_t = ::SIZE_T;
			static constexpr size_t Argc = 1;

			::ID3D12PipelineLibrary* pThis;
		};

		//Virtual
		struct Serialize
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D12PipelineLibrary* pThis;
			void* pData;
			::SIZE_T DataSizeInBytes;
		};

	private:
		 virtual ~ID3D12PipelineLibrary() = 0;
	};

	class ID3D12PipelineLibrary1 : ID3D12PipelineLibrary
	{
	public:
		//Virtual
		struct LoadPipeline
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D12PipelineLibrary1* pThis;
			::LPCWSTR pName;
			const ::D3D12_PIPELINE_STATE_STREAM_DESC* pDesc;
			const ::IID& riid;
			void** ppPipelineState;
		};

	private:
		 virtual ~ID3D12PipelineLibrary1() = 0;
	};

	class ID3D12Device1 : ID3D12Device
	{
	public:
		//Virtual
		struct CreatePipelineLibrary
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D12Device1* pThis;
			const void* pLibraryBlob;
			::SIZE_T BlobLength;
			const ::IID& riid;
			void** ppPipelineLibrary;
		};

		//Virtual
		struct SetEventOnMultipleFenceCompletion
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::ID3D12Device1* pThis;
			::ID3D12Fence*const* ppFences;
			const ::UINT64* pFenceValues;
			::UINT NumFences;
			::D3D12_MULTIPLE_FENCE_WAIT_FLAGS Flags;
			::HANDLE hEvent;
		};

		//Virtual
		struct SetResidencyPriority
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D12Device1* pThis;
			::UINT NumObjects;
			::ID3D12Pageable*const* ppObjects;
			const ::D3D12_RESIDENCY_PRIORITY* pPriorities;
		};

	private:
		 virtual ~ID3D12Device1() = 0;
	};

	class ID3D12Device2 : ID3D12Device1
	{
	public:
		//Virtual
		struct CreatePipelineState
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D12Device2* pThis;
			const ::D3D12_PIPELINE_STATE_STREAM_DESC* pDesc;
			const ::IID& riid;
			void** ppPipelineState;
		};

	private:
		 virtual ~ID3D12Device2() = 0;
	};

	class ID3D12Device3 : ID3D12Device2
	{
	public:
		//Virtual
		struct OpenExistingHeapFromAddress
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D12Device3* pThis;
			const void* pAddress;
			const ::IID& riid;
			void** ppvHeap;
		};

		//Virtual
		struct OpenExistingHeapFromFileMapping
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D12Device3* pThis;
			::HANDLE hFileMapping;
			const ::IID& riid;
			void** ppvHeap;
		};

		//Virtual
		struct EnqueueMakeResident
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::ID3D12Device3* pThis;
			::D3D12_RESIDENCY_FLAGS Flags;
			::UINT NumObjects;
			::ID3D12Pageable*const* ppObjects;
			::ID3D12Fence* pFenceToSignal;
			::UINT64 FenceValueToSignal;
		};

	private:
		 virtual ~ID3D12Device3() = 0;
	};

	class ID3D12ProtectedSession : ID3D12DeviceChild
	{
	public:
		//Virtual
		struct GetStatusFence
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D12ProtectedSession* pThis;
			const ::IID& riid;
			void** ppFence;
		};

		//Virtual
		struct GetSessionStatus
		{
			using ReturnType_t = ::D3D12_PROTECTED_SESSION_STATUS;
			static constexpr size_t Argc = 1;

			::ID3D12ProtectedSession* pThis;
		};

	private:
		 virtual ~ID3D12ProtectedSession() = 0;
	};

	class ID3D12ProtectedResourceSession : ID3D12ProtectedSession
	{
	public:
		//Virtual
		struct GetDesc
		{
			using ReturnType_t = ::D3D12_PROTECTED_RESOURCE_SESSION_DESC;
			static constexpr size_t Argc = 1;

			::ID3D12ProtectedResourceSession* pThis;
		};

	private:
		 virtual ~ID3D12ProtectedResourceSession() = 0;
	};

	class ID3D12Device4 : ID3D12Device3
	{
	public:
		//Virtual
		struct CreateCommandList1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::ID3D12Device4* pThis;
			::UINT nodeMask;
			::D3D12_COMMAND_LIST_TYPE type;
			::D3D12_COMMAND_LIST_FLAGS flags;
			const ::IID& riid;
			void** ppCommandList;
		};

		//Virtual
		struct CreateProtectedResourceSession
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D12Device4* pThis;
			const ::D3D12_PROTECTED_RESOURCE_SESSION_DESC* pDesc;
			const ::IID& riid;
			void** ppSession;
		};

		//Virtual
		struct CreateCommittedResource1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 9;

			::ID3D12Device4* pThis;
			const ::D3D12_HEAP_PROPERTIES* pHeapProperties;
			::D3D12_HEAP_FLAGS HeapFlags;
			const ::D3D12_RESOURCE_DESC* pDesc;
			::D3D12_RESOURCE_STATES InitialResourceState;
			const ::D3D12_CLEAR_VALUE* pOptimizedClearValue;
			::ID3D12ProtectedResourceSession* pProtectedSession;
			const ::IID& riidResource;
			void** ppvResource;
		};

		//Virtual
		struct CreateHeap1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D12Device4* pThis;
			const ::D3D12_HEAP_DESC* pDesc;
			::ID3D12ProtectedResourceSession* pProtectedSession;
			const ::IID& riid;
			void** ppvHeap;
		};

		//Virtual
		struct CreateReservedResource1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 7;

			::ID3D12Device4* pThis;
			const ::D3D12_RESOURCE_DESC* pDesc;
			::D3D12_RESOURCE_STATES InitialState;
			const ::D3D12_CLEAR_VALUE* pOptimizedClearValue;
			::ID3D12ProtectedResourceSession* pProtectedSession;
			const ::IID& riid;
			void** ppvResource;
		};

		//Virtual
		struct GetResourceAllocationInfo1
		{
			using ReturnType_t = ::D3D12_RESOURCE_ALLOCATION_INFO;
			static constexpr size_t Argc = 5;

			::ID3D12Device4* pThis;
			::UINT visibleMask;
			::UINT numResourceDescs;
			const ::D3D12_RESOURCE_DESC* pResourceDescs;
			::D3D12_RESOURCE_ALLOCATION_INFO1* pResourceAllocationInfo1;
		};

	private:
		 virtual ~ID3D12Device4() = 0;
	};

	class ID3D12LifetimeOwner : IUnknown
	{
	public:
		//Virtual
		struct LifetimeStateUpdated
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D12LifetimeOwner* pThis;
			::D3D12_LIFETIME_STATE NewState;
		};

	private:
		 virtual ~ID3D12LifetimeOwner() = 0;
	};

	class ID3D12SwapChainAssistant : IUnknown
	{
	public:
		//Virtual
		struct GetLUID
		{
			using ReturnType_t = ::LUID;
			static constexpr size_t Argc = 1;

			::ID3D12SwapChainAssistant* pThis;
		};

		//Virtual
		struct GetSwapChainObject
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D12SwapChainAssistant* pThis;
			const ::IID& riid;
			void** ppv;
		};

		//Virtual
		struct GetCurrentResourceAndCommandQueue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D12SwapChainAssistant* pThis;
			const ::IID& riidResource;
			void** ppvResource;
			const ::IID& riidQueue;
			void** ppvQueue;
		};

		//Virtual
		struct InsertImplicitSync
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ID3D12SwapChainAssistant* pThis;
		};

	private:
		 virtual ~ID3D12SwapChainAssistant() = 0;
	};

	class ID3D12LifetimeTracker : ID3D12DeviceChild
	{
	public:
		//Virtual
		struct DestroyOwnedObject
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D12LifetimeTracker* pThis;
			::ID3D12DeviceChild* pObject;
		};

	private:
		 virtual ~ID3D12LifetimeTracker() = 0;
	};

	class ID3D12StateObjectProperties : IUnknown
	{
	public:
		//Virtual
		struct GetShaderIdentifier
		{
			using ReturnType_t = void*;
			static constexpr size_t Argc = 2;

			::ID3D12StateObjectProperties* pThis;
			::LPCWSTR pExportName;
		};

		//Virtual
		struct GetShaderStackSize
		{
			using ReturnType_t = ::UINT64;
			static constexpr size_t Argc = 2;

			::ID3D12StateObjectProperties* pThis;
			::LPCWSTR pExportName;
		};

		//Virtual
		struct GetPipelineStackSize
		{
			using ReturnType_t = ::UINT64;
			static constexpr size_t Argc = 1;

			::ID3D12StateObjectProperties* pThis;
		};

		//Virtual
		struct SetPipelineStackSize
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D12StateObjectProperties* pThis;
			::UINT64 PipelineStackSizeInBytes;
		};

	private:
		 virtual ~ID3D12StateObjectProperties() = 0;
	};

	class ID3D12Device5 : ID3D12Device4
	{
	public:
		//Virtual
		struct CreateLifetimeTracker
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D12Device5* pThis;
			::ID3D12LifetimeOwner* pOwner;
			const ::IID& riid;
			void** ppvTracker;
		};

		//Virtual
		struct RemoveDevice
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D12Device5* pThis;
		};

		//Virtual
		struct EnumerateMetaCommands
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D12Device5* pThis;
			::UINT* pNumMetaCommands;
			::D3D12_META_COMMAND_DESC* pDescs;
		};

		//Virtual
		struct EnumerateMetaCommandParameters
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 6;

			::ID3D12Device5* pThis;
			const ::GUID& CommandId;
			::D3D12_META_COMMAND_PARAMETER_STAGE Stage;
			::UINT* pTotalStructureSizeInBytes;
			::UINT* pParameterCount;
			::D3D12_META_COMMAND_PARAMETER_DESC* pParameterDescs;
		};

		//Virtual
		struct CreateMetaCommand
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 7;

			::ID3D12Device5* pThis;
			const ::GUID& CommandId;
			::UINT NodeMask;
			const void* pCreationParametersData;
			::SIZE_T CreationParametersDataSizeInBytes;
			const ::IID& riid;
			void** ppMetaCommand;
		};

		//Virtual
		struct CreateStateObject
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D12Device5* pThis;
			const ::D3D12_STATE_OBJECT_DESC* pDesc;
			const ::IID& riid;
			void** ppStateObject;
		};

		//Virtual
		struct GetRaytracingAccelerationStructurePrebuildInfo
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D12Device5* pThis;
			const ::D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS* pDesc;
			::D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO* pInfo;
		};

		//Virtual
		struct CheckDriverMatchingIdentifier
		{
			using ReturnType_t = ::D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS;
			static constexpr size_t Argc = 3;

			::ID3D12Device5* pThis;
			::D3D12_SERIALIZED_DATA_TYPE SerializedDataType;
			const ::D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER* pIdentifierToCheck;
		};

	private:
		 virtual ~ID3D12Device5() = 0;
	};

	class ID3D12DeviceRemovedExtendedDataSettings : IUnknown
	{
	public:
		//Virtual
		struct SetAutoBreadcrumbsEnablement
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D12DeviceRemovedExtendedDataSettings* pThis;
			::D3D12_DRED_ENABLEMENT Enablement;
		};

		//Virtual
		struct SetPageFaultEnablement
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D12DeviceRemovedExtendedDataSettings* pThis;
			::D3D12_DRED_ENABLEMENT Enablement;
		};

		//Virtual
		struct SetWatsonDumpEnablement
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D12DeviceRemovedExtendedDataSettings* pThis;
			::D3D12_DRED_ENABLEMENT Enablement;
		};

	private:
		 virtual ~ID3D12DeviceRemovedExtendedDataSettings() = 0;
	};

	class ID3D12DeviceRemovedExtendedDataSettings1 : ID3D12DeviceRemovedExtendedDataSettings
	{
	public:
		//Virtual
		struct SetBreadcrumbContextEnablement
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D12DeviceRemovedExtendedDataSettings1* pThis;
			::D3D12_DRED_ENABLEMENT Enablement;
		};

	private:
		 virtual ~ID3D12DeviceRemovedExtendedDataSettings1() = 0;
	};

	class ID3D12DeviceRemovedExtendedData : IUnknown
	{
	public:
		//Virtual
		struct GetAutoBreadcrumbsOutput
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D12DeviceRemovedExtendedData* pThis;
			::D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT* pOutput;
		};

		//Virtual
		struct GetPageFaultAllocationOutput
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D12DeviceRemovedExtendedData* pThis;
			::D3D12_DRED_PAGE_FAULT_OUTPUT* pOutput;
		};

	private:
		 virtual ~ID3D12DeviceRemovedExtendedData() = 0;
	};

	class ID3D12DeviceRemovedExtendedData1 : ID3D12DeviceRemovedExtendedData
	{
	public:
		//Virtual
		struct GetAutoBreadcrumbsOutput1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D12DeviceRemovedExtendedData1* pThis;
			::D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1* pOutput;
		};

		//Virtual
		struct GetPageFaultAllocationOutput1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D12DeviceRemovedExtendedData1* pThis;
			::D3D12_DRED_PAGE_FAULT_OUTPUT1* pOutput;
		};

	private:
		 virtual ~ID3D12DeviceRemovedExtendedData1() = 0;
	};

	class ID3D12DeviceRemovedExtendedData2 : ID3D12DeviceRemovedExtendedData1
	{
	public:
		//Virtual
		struct GetPageFaultAllocationOutput2
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D12DeviceRemovedExtendedData2* pThis;
			::D3D12_DRED_PAGE_FAULT_OUTPUT2* pOutput;
		};

		//Virtual
		struct GetDeviceState
		{
			using ReturnType_t = ::D3D12_DRED_DEVICE_STATE;
			static constexpr size_t Argc = 1;

			::ID3D12DeviceRemovedExtendedData2* pThis;
		};

	private:
		 virtual ~ID3D12DeviceRemovedExtendedData2() = 0;
	};

	class ID3D12Device6 : ID3D12Device5
	{
	public:
		//Virtual
		struct SetBackgroundProcessingMode
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D12Device6* pThis;
			::D3D12_BACKGROUND_PROCESSING_MODE Mode;
			::D3D12_MEASUREMENTS_ACTION MeasurementsAction;
			::HANDLE hEventToSignalUponCompletion;
			::BOOL* pbFurtherMeasurementsDesired;
		};

	private:
		 virtual ~ID3D12Device6() = 0;
	};

	class ID3D12ProtectedResourceSession1 : ID3D12ProtectedResourceSession
	{
	public:
		//Virtual
		struct GetDesc1
		{
			using ReturnType_t = ::D3D12_PROTECTED_RESOURCE_SESSION_DESC1;
			static constexpr size_t Argc = 1;

			::ID3D12ProtectedResourceSession1* pThis;
		};

	private:
		 virtual ~ID3D12ProtectedResourceSession1() = 0;
	};

	class ID3D12Device7 : ID3D12Device6
	{
	public:
		//Virtual
		struct AddToStateObject
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D12Device7* pThis;
			const ::D3D12_STATE_OBJECT_DESC* pAddition;
			::ID3D12StateObject* pStateObjectToGrowFrom;
			const ::IID& riid;
			void** ppNewStateObject;
		};

		//Virtual
		struct CreateProtectedResourceSession1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D12Device7* pThis;
			const ::D3D12_PROTECTED_RESOURCE_SESSION_DESC1* pDesc;
			const ::IID& riid;
			void** ppSession;
		};

	private:
		 virtual ~ID3D12Device7() = 0;
	};

	class ID3D12Device8 : ID3D12Device7
	{
	public:
		//Virtual
		struct GetResourceAllocationInfo2
		{
			using ReturnType_t = ::D3D12_RESOURCE_ALLOCATION_INFO;
			static constexpr size_t Argc = 5;

			::ID3D12Device8* pThis;
			::UINT visibleMask;
			::UINT numResourceDescs;
			const ::D3D12_RESOURCE_DESC1* pResourceDescs;
			::D3D12_RESOURCE_ALLOCATION_INFO1* pResourceAllocationInfo1;
		};

		//Virtual
		struct CreateCommittedResource2
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 9;

			::ID3D12Device8* pThis;
			const ::D3D12_HEAP_PROPERTIES* pHeapProperties;
			::D3D12_HEAP_FLAGS HeapFlags;
			const ::D3D12_RESOURCE_DESC1* pDesc;
			::D3D12_RESOURCE_STATES InitialResourceState;
			const ::D3D12_CLEAR_VALUE* pOptimizedClearValue;
			::ID3D12ProtectedResourceSession* pProtectedSession;
			const ::IID& riidResource;
			void** ppvResource;
		};

		//Virtual
		struct CreatePlacedResource1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 8;

			::ID3D12Device8* pThis;
			::ID3D12Heap* pHeap;
			::UINT64 HeapOffset;
			const ::D3D12_RESOURCE_DESC1* pDesc;
			::D3D12_RESOURCE_STATES InitialState;
			const ::D3D12_CLEAR_VALUE* pOptimizedClearValue;
			const ::IID& riid;
			void** ppvResource;
		};

		//Virtual
		struct CreateSamplerFeedbackUnorderedAccessView
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D12Device8* pThis;
			::ID3D12Resource* pTargetedResource;
			::ID3D12Resource* pFeedbackResource;
			::D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor;
		};

		//Virtual
		struct GetCopyableFootprints1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 9;

			::ID3D12Device8* pThis;
			const ::D3D12_RESOURCE_DESC1* pResourceDesc;
			::UINT FirstSubresource;
			::UINT NumSubresources;
			::UINT64 BaseOffset;
			::D3D12_PLACED_SUBRESOURCE_FOOTPRINT* pLayouts;
			::UINT* pNumRows;
			::UINT64* pRowSizeInBytes;
			::UINT64* pTotalBytes;
		};

	private:
		 virtual ~ID3D12Device8() = 0;
	};

	class ID3D12Resource1 : ID3D12Resource
	{
	public:
		//Virtual
		struct GetProtectedResourceSession
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D12Resource1* pThis;
			const ::IID& riid;
			void** ppProtectedSession;
		};

	private:
		 virtual ~ID3D12Resource1() = 0;
	};

	class ID3D12Resource2 : ID3D12Resource1
	{
	public:
		//Virtual
		struct GetDesc1
		{
			using ReturnType_t = ::D3D12_RESOURCE_DESC1;
			static constexpr size_t Argc = 1;

			::ID3D12Resource2* pThis;
		};

	private:
		 virtual ~ID3D12Resource2() = 0;
	};

	class ID3D12Heap1 : ID3D12Heap
	{
	public:
		//Virtual
		struct GetProtectedResourceSession
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D12Heap1* pThis;
			const ::IID& riid;
			void** ppProtectedSession;
		};

	private:
		 virtual ~ID3D12Heap1() = 0;
	};

	class ID3D12GraphicsCommandList3 : ID3D12GraphicsCommandList2
	{
	public:
		//Virtual
		struct SetProtectedResourceSession
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D12GraphicsCommandList3* pThis;
			::ID3D12ProtectedResourceSession* pProtectedResourceSession;
		};

	private:
		 virtual ~ID3D12GraphicsCommandList3() = 0;
	};

	class ID3D12MetaCommand : ID3D12Pageable
	{
	public:
		//Virtual
		struct GetRequiredParameterResourceSize
		{
			using ReturnType_t = ::UINT64;
			static constexpr size_t Argc = 3;

			::ID3D12MetaCommand* pThis;
			::D3D12_META_COMMAND_PARAMETER_STAGE Stage;
			::UINT ParameterIndex;
		};

	private:
		 virtual ~ID3D12MetaCommand() = 0;
	};

	class ID3D12GraphicsCommandList4 : ID3D12GraphicsCommandList3
	{
	public:
		//Virtual
		struct BeginRenderPass
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 5;

			::ID3D12GraphicsCommandList4* pThis;
			::UINT NumRenderTargets;
			const ::D3D12_RENDER_PASS_RENDER_TARGET_DESC* pRenderTargets;
			const ::D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* pDepthStencil;
			::D3D12_RENDER_PASS_FLAGS Flags;
		};

		//Virtual
		struct EndRenderPass
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D12GraphicsCommandList4* pThis;
		};

		//Virtual
		struct InitializeMetaCommand
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D12GraphicsCommandList4* pThis;
			::ID3D12MetaCommand* pMetaCommand;
			const void* pInitializationParametersData;
			::SIZE_T InitializationParametersDataSizeInBytes;
		};

		//Virtual
		struct ExecuteMetaCommand
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D12GraphicsCommandList4* pThis;
			::ID3D12MetaCommand* pMetaCommand;
			const void* pExecutionParametersData;
			::SIZE_T ExecutionParametersDataSizeInBytes;
		};

		//Virtual
		struct BuildRaytracingAccelerationStructure
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D12GraphicsCommandList4* pThis;
			const ::D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC* pDesc;
			::UINT NumPostbuildInfoDescs;
			const ::D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* pPostbuildInfoDescs;
		};

		//Virtual
		struct EmitRaytracingAccelerationStructurePostbuildInfo
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D12GraphicsCommandList4* pThis;
			const ::D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* pDesc;
			::UINT NumSourceAccelerationStructures;
			const ::D3D12_GPU_VIRTUAL_ADDRESS* pSourceAccelerationStructureData;
		};

		//Virtual
		struct CopyRaytracingAccelerationStructure
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D12GraphicsCommandList4* pThis;
			::D3D12_GPU_VIRTUAL_ADDRESS DestAccelerationStructureData;
			::D3D12_GPU_VIRTUAL_ADDRESS SourceAccelerationStructureData;
			::D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE Mode;
		};

		//Virtual
		struct SetPipelineState1
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D12GraphicsCommandList4* pThis;
			::ID3D12StateObject* pStateObject;
		};

		//Virtual
		struct DispatchRays
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D12GraphicsCommandList4* pThis;
			const ::D3D12_DISPATCH_RAYS_DESC* pDesc;
		};

	private:
		 virtual ~ID3D12GraphicsCommandList4() = 0;
	};

	class ID3D12ShaderCacheSession : ID3D12DeviceChild
	{
	public:
		//Virtual
		struct FindValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D12ShaderCacheSession* pThis;
			const void* pKey;
			::UINT KeySize;
			void* pValue;
			::UINT* pValueSize;
		};

		//Virtual
		struct StoreValue
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D12ShaderCacheSession* pThis;
			const void* pKey;
			::UINT KeySize;
			const void* pValue;
			::UINT ValueSize;
		};

		//Virtual
		struct SetDeleteOnDestroy
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D12ShaderCacheSession* pThis;
		};

		//Virtual
		struct GetDesc
		{
			using ReturnType_t = ::D3D12_SHADER_CACHE_SESSION_DESC;
			static constexpr size_t Argc = 1;

			::ID3D12ShaderCacheSession* pThis;
		};

	private:
		 virtual ~ID3D12ShaderCacheSession() = 0;
	};

	class ID3D12Device9 : ID3D12Device8
	{
	public:
		//Virtual
		struct CreateShaderCacheSession
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D12Device9* pThis;
			const ::D3D12_SHADER_CACHE_SESSION_DESC* pDesc;
			const ::IID& riid;
			void** ppvSession;
		};

		//Virtual
		struct ShaderCacheControl
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D12Device9* pThis;
			::D3D12_SHADER_CACHE_KIND_FLAGS Kinds;
			::D3D12_SHADER_CACHE_CONTROL_FLAGS Control;
		};

		//Virtual
		struct CreateCommandQueue1
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D12Device9* pThis;
			const ::D3D12_COMMAND_QUEUE_DESC* pDesc;
			const ::IID& CreatorID;
			const ::IID& riid;
			void** ppCommandQueue;
		};

	private:
		 virtual ~ID3D12Device9() = 0;
	};

	class ID3D12Tools : IUnknown
	{
	public:
		//Virtual
		struct EnableShaderInstrumentation
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D12Tools* pThis;
			::BOOL bEnable;
		};

		//Virtual
		struct ShaderInstrumentationEnabled
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 1;

			::ID3D12Tools* pThis;
		};

	private:
		 virtual ~ID3D12Tools() = 0;
	};

	class ID3D12Debug : IUnknown
	{
	public:
		//Virtual
		struct EnableDebugLayer
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D12Debug* pThis;
		};

	private:
		 virtual ~ID3D12Debug() = 0;
	};

	class ID3D12Debug1 : IUnknown
	{
	public:
		//Virtual
		struct EnableDebugLayer
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D12Debug1* pThis;
		};

		//Virtual
		struct SetEnableGPUBasedValidation
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D12Debug1* pThis;
			::BOOL Enable;
		};

		//Virtual
		struct SetEnableSynchronizedCommandQueueValidation
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D12Debug1* pThis;
			::BOOL Enable;
		};

	private:
		 virtual ~ID3D12Debug1() = 0;
	};

	class ID3D12Debug2 : IUnknown
	{
	public:
		//Virtual
		struct SetGPUBasedValidationFlags
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D12Debug2* pThis;
			::D3D12_GPU_BASED_VALIDATION_FLAGS Flags;
		};

	private:
		 virtual ~ID3D12Debug2() = 0;
	};

	class ID3D12Debug3 : ID3D12Debug
	{
	public:
		//Virtual
		struct SetEnableGPUBasedValidation
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D12Debug3* pThis;
			::BOOL Enable;
		};

		//Virtual
		struct SetEnableSynchronizedCommandQueueValidation
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D12Debug3* pThis;
			::BOOL Enable;
		};

		//Virtual
		struct SetGPUBasedValidationFlags
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D12Debug3* pThis;
			::D3D12_GPU_BASED_VALIDATION_FLAGS Flags;
		};

	private:
		 virtual ~ID3D12Debug3() = 0;
	};

	class ID3D12Debug4 : ID3D12Debug3
	{
	public:
		//Virtual
		struct DisableDebugLayer
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D12Debug4* pThis;
		};

	private:
		 virtual ~ID3D12Debug4() = 0;
	};

	class ID3D12Debug5 : ID3D12Debug4
	{
	public:
		//Virtual
		struct SetEnableAutoName
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D12Debug5* pThis;
			::BOOL Enable;
		};

	private:
		 virtual ~ID3D12Debug5() = 0;
	};

	class ID3D12DebugDevice1 : IUnknown
	{
	public:
		//Virtual
		struct SetDebugParameter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D12DebugDevice1* pThis;
			::D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type;
			const void* pData;
			::UINT DataSize;
		};

		//Virtual
		struct GetDebugParameter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D12DebugDevice1* pThis;
			::D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type;
			void* pData;
			::UINT DataSize;
		};

		//Virtual
		struct ReportLiveDeviceObjects
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D12DebugDevice1* pThis;
			::D3D12_RLDO_FLAGS Flags;
		};

	private:
		 virtual ~ID3D12DebugDevice1() = 0;
	};

	class ID3D12DebugDevice : IUnknown
	{
	public:
		//Virtual
		struct SetFeatureMask
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D12DebugDevice* pThis;
			::D3D12_DEBUG_FEATURE Mask;
		};

		//Virtual
		struct GetFeatureMask
		{
			using ReturnType_t = ::D3D12_DEBUG_FEATURE;
			static constexpr size_t Argc = 1;

			::ID3D12DebugDevice* pThis;
		};

		//Virtual
		struct ReportLiveDeviceObjects
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D12DebugDevice* pThis;
			::D3D12_RLDO_FLAGS Flags;
		};

	private:
		 virtual ~ID3D12DebugDevice() = 0;
	};

	class ID3D12DebugDevice2 : ID3D12DebugDevice
	{
	public:
		//Virtual
		struct SetDebugParameter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D12DebugDevice2* pThis;
			::D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type;
			const void* pData;
			::UINT DataSize;
		};

		//Virtual
		struct GetDebugParameter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D12DebugDevice2* pThis;
			::D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type;
			void* pData;
			::UINT DataSize;
		};

	private:
		 virtual ~ID3D12DebugDevice2() = 0;
	};

	class ID3D12DebugCommandQueue : IUnknown
	{
	public:
		//Virtual
		struct AssertResourceState
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 4;

			::ID3D12DebugCommandQueue* pThis;
			::ID3D12Resource* pResource;
			::UINT Subresource;
			::UINT State;
		};

	private:
		 virtual ~ID3D12DebugCommandQueue() = 0;
	};

	class ID3D12DebugCommandList1 : IUnknown
	{
	public:
		//Virtual
		struct AssertResourceState
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 4;

			::ID3D12DebugCommandList1* pThis;
			::ID3D12Resource* pResource;
			::UINT Subresource;
			::UINT State;
		};

		//Virtual
		struct SetDebugParameter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D12DebugCommandList1* pThis;
			::D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type;
			const void* pData;
			::UINT DataSize;
		};

		//Virtual
		struct GetDebugParameter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D12DebugCommandList1* pThis;
			::D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type;
			void* pData;
			::UINT DataSize;
		};

	private:
		 virtual ~ID3D12DebugCommandList1() = 0;
	};

	class ID3D12DebugCommandList : IUnknown
	{
	public:
		//Virtual
		struct AssertResourceState
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 4;

			::ID3D12DebugCommandList* pThis;
			::ID3D12Resource* pResource;
			::UINT Subresource;
			::UINT State;
		};

		//Virtual
		struct SetFeatureMask
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D12DebugCommandList* pThis;
			::D3D12_DEBUG_FEATURE Mask;
		};

		//Virtual
		struct GetFeatureMask
		{
			using ReturnType_t = ::D3D12_DEBUG_FEATURE;
			static constexpr size_t Argc = 1;

			::ID3D12DebugCommandList* pThis;
		};

	private:
		 virtual ~ID3D12DebugCommandList() = 0;
	};

	class ID3D12DebugCommandList2 : ID3D12DebugCommandList
	{
	public:
		//Virtual
		struct SetDebugParameter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D12DebugCommandList2* pThis;
			::D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type;
			const void* pData;
			::UINT DataSize;
		};

		//Virtual
		struct GetDebugParameter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D12DebugCommandList2* pThis;
			::D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type;
			void* pData;
			::UINT DataSize;
		};

	private:
		 virtual ~ID3D12DebugCommandList2() = 0;
	};

	class ID3D12SharingContract : IUnknown
	{
	public:
		//Virtual
		struct Present
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D12SharingContract* pThis;
			::ID3D12Resource* pResource;
			::UINT Subresource;
			::HWND window;
		};

		//Virtual
		struct SharedFenceSignal
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D12SharingContract* pThis;
			::ID3D12Fence* pFence;
			::UINT64 FenceValue;
		};

		//Virtual
		struct BeginCapturableWork
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D12SharingContract* pThis;
			const ::GUID& guid;
		};

		//Virtual
		struct EndCapturableWork
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D12SharingContract* pThis;
			const ::GUID& guid;
		};

	private:
		 virtual ~ID3D12SharingContract() = 0;
	};

	class ID3D12InfoQueue : IUnknown
	{
	public:
		//Virtual
		struct SetMessageCountLimit
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D12InfoQueue* pThis;
			::UINT64 MessageCountLimit;
		};

		//Virtual
		struct ClearStoredMessages
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D12InfoQueue* pThis;
		};

		//Virtual
		struct GetMessageA
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 4;

			::ID3D12InfoQueue* pThis;
			::UINT64 MessageIndex;
			::D3D12_MESSAGE* pMessage;
			::SIZE_T* pMessageByteLength;
		};

		//Virtual
		struct GetNumMessagesAllowedByStorageFilter
		{
			using ReturnType_t = ::UINT64;
			static constexpr size_t Argc = 1;

			::ID3D12InfoQueue* pThis;
		};

		//Virtual
		struct GetNumMessagesDeniedByStorageFilter
		{
			using ReturnType_t = ::UINT64;
			static constexpr size_t Argc = 1;

			::ID3D12InfoQueue* pThis;
		};

		//Virtual
		struct GetNumStoredMessages
		{
			using ReturnType_t = ::UINT64;
			static constexpr size_t Argc = 1;

			::ID3D12InfoQueue* pThis;
		};

		//Virtual
		struct GetNumStoredMessagesAllowedByRetrievalFilter
		{
			using ReturnType_t = ::UINT64;
			static constexpr size_t Argc = 1;

			::ID3D12InfoQueue* pThis;
		};

		//Virtual
		struct GetNumMessagesDiscardedByMessageCountLimit
		{
			using ReturnType_t = ::UINT64;
			static constexpr size_t Argc = 1;

			::ID3D12InfoQueue* pThis;
		};

		//Virtual
		struct GetMessageCountLimit
		{
			using ReturnType_t = ::UINT64;
			static constexpr size_t Argc = 1;

			::ID3D12InfoQueue* pThis;
		};

		//Virtual
		struct AddStorageFilterEntries
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D12InfoQueue* pThis;
			::D3D12_INFO_QUEUE_FILTER* pFilter;
		};

		//Virtual
		struct GetStorageFilter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D12InfoQueue* pThis;
			::D3D12_INFO_QUEUE_FILTER* pFilter;
			::SIZE_T* pFilterByteLength;
		};

		//Virtual
		struct ClearStorageFilter
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D12InfoQueue* pThis;
		};

		//Virtual
		struct PushEmptyStorageFilter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ID3D12InfoQueue* pThis;
		};

		//Virtual
		struct PushCopyOfStorageFilter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ID3D12InfoQueue* pThis;
		};

		//Virtual
		struct PushStorageFilter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D12InfoQueue* pThis;
			::D3D12_INFO_QUEUE_FILTER* pFilter;
		};

		//Virtual
		struct PopStorageFilter
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D12InfoQueue* pThis;
		};

		//Virtual
		struct GetStorageFilterStackSize
		{
			using ReturnType_t = ::UINT;
			static constexpr size_t Argc = 1;

			::ID3D12InfoQueue* pThis;
		};

		//Virtual
		struct AddRetrievalFilterEntries
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D12InfoQueue* pThis;
			::D3D12_INFO_QUEUE_FILTER* pFilter;
		};

		//Virtual
		struct GetRetrievalFilter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D12InfoQueue* pThis;
			::D3D12_INFO_QUEUE_FILTER* pFilter;
			::SIZE_T* pFilterByteLength;
		};

		//Virtual
		struct ClearRetrievalFilter
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D12InfoQueue* pThis;
		};

		//Virtual
		struct PushEmptyRetrievalFilter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ID3D12InfoQueue* pThis;
		};

		//Virtual
		struct PushCopyOfRetrievalFilter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 1;

			::ID3D12InfoQueue* pThis;
		};

		//Virtual
		struct PushRetrievalFilter
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D12InfoQueue* pThis;
			::D3D12_INFO_QUEUE_FILTER* pFilter;
		};

		//Virtual
		struct PopRetrievalFilter
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 1;

			::ID3D12InfoQueue* pThis;
		};

		//Virtual
		struct GetRetrievalFilterStackSize
		{
			using ReturnType_t = ::UINT;
			static constexpr size_t Argc = 1;

			::ID3D12InfoQueue* pThis;
		};

		//Virtual
		struct AddMessage
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D12InfoQueue* pThis;
			::D3D12_MESSAGE_CATEGORY Category;
			::D3D12_MESSAGE_SEVERITY Severity;
			::D3D12_MESSAGE_ID ID;
			::LPCSTR pDescription;
		};

		//Virtual
		struct AddApplicationMessage
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D12InfoQueue* pThis;
			::D3D12_MESSAGE_SEVERITY Severity;
			::LPCSTR pDescription;
		};

		//Virtual
		struct SetBreakOnCategory
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D12InfoQueue* pThis;
			::D3D12_MESSAGE_CATEGORY Category;
			::BOOL bEnable;
		};

		//Virtual
		struct SetBreakOnSeverity
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D12InfoQueue* pThis;
			::D3D12_MESSAGE_SEVERITY Severity;
			::BOOL bEnable;
		};

		//Virtual
		struct SetBreakOnID
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D12InfoQueue* pThis;
			::D3D12_MESSAGE_ID ID;
			::BOOL bEnable;
		};

		//Virtual
		struct GetBreakOnCategory
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 2;

			::ID3D12InfoQueue* pThis;
			::D3D12_MESSAGE_CATEGORY Category;
		};

		//Virtual
		struct GetBreakOnSeverity
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 2;

			::ID3D12InfoQueue* pThis;
			::D3D12_MESSAGE_SEVERITY Severity;
		};

		//Virtual
		struct GetBreakOnID
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 2;

			::ID3D12InfoQueue* pThis;
			::D3D12_MESSAGE_ID ID;
		};

		//Virtual
		struct SetMuteDebugOutput
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D12InfoQueue* pThis;
			::BOOL bMute;
		};

		//Virtual
		struct GetMuteDebugOutput
		{
			using ReturnType_t = ::BOOL;
			static constexpr size_t Argc = 1;

			::ID3D12InfoQueue* pThis;
		};

	private:
		 virtual ~ID3D12InfoQueue() = 0;
	};

	class ID3D12InfoQueue1 : ID3D12InfoQueue
	{
	public:
		//Virtual
		struct RegisterMessageCallback
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 5;

			::ID3D12InfoQueue1* pThis;
			::D3D12MessageFunc CallbackFunc;
			::D3D12_MESSAGE_CALLBACK_FLAGS CallbackFilterFlags;
			void* pContext;
			::DWORD* pCallbackCookie;
		};

		//Virtual
		struct UnregisterMessageCallback
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 2;

			::ID3D12InfoQueue1* pThis;
			::DWORD CallbackCookie;
		};

	private:
		 virtual ~ID3D12InfoQueue1() = 0;
	};

	class ID3D12SDKConfiguration : IUnknown
	{
	public:
		//Virtual
		struct SetSDKVersion
		{
			using ReturnType_t = ::HRESULT;
			static constexpr size_t Argc = 3;

			::ID3D12SDKConfiguration* pThis;
			::UINT SDKVersion;
			::LPCSTR SDKPath;
		};

	private:
		 virtual ~ID3D12SDKConfiguration() = 0;
	};

	class ID3D12GraphicsCommandList5 : ID3D12GraphicsCommandList4
	{
	public:
		//Virtual
		struct RSSetShadingRate
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 3;

			::ID3D12GraphicsCommandList5* pThis;
			::D3D12_SHADING_RATE baseShadingRate;
			const ::D3D12_SHADING_RATE_COMBINER* combiners;
		};

		//Virtual
		struct RSSetShadingRateImage
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 2;

			::ID3D12GraphicsCommandList5* pThis;
			::ID3D12Resource* shadingRateImage;
		};

	private:
		 virtual ~ID3D12GraphicsCommandList5() = 0;
	};

	class ID3D12GraphicsCommandList6 : ID3D12GraphicsCommandList5
	{
	public:
		//Virtual
		struct DispatchMesh
		{
			using ReturnType_t = void;
			static constexpr size_t Argc = 4;

			::ID3D12GraphicsCommandList6* pThis;
			::UINT ThreadGroupCountX;
			::UINT ThreadGroupCountY;
			::UINT ThreadGroupCountZ;
		};

	private:
		 virtual ~ID3D12GraphicsCommandList6() = 0;
	};

}

namespace D3D12MethodIndices
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

	enum class ID3D12Object : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		VTableSize,
	};

	enum class ID3D12DeviceChild : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12DeviceChild */
		GetDevice,

		VTableSize,
	};

	enum class ID3D12RootSignatureDeserializer : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12RootSignatureDeserializer */
		GetRootSignatureDesc,

		VTableSize,
	};

	enum class ID3D12VersionedRootSignatureDeserializer : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12VersionedRootSignatureDeserializer */
		GetRootSignatureDescAtVersion,
		GetUnconvertedRootSignatureDesc,

		VTableSize,
	};

	enum class ID3D12Pageable : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12DeviceChild */
		GetDevice,

		/* ID3D12Pageable */

		VTableSize,
	};

	enum class ID3D12Heap : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12DeviceChild */
		GetDevice,

		/* ID3D12Pageable */

		/* ID3D12Heap */
		GetDesc,

		VTableSize,
	};

	enum class ID3D12Resource : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12DeviceChild */
		GetDevice,

		/* ID3D12Pageable */

		/* ID3D12Resource */
		Map,
		Unmap,
		GetDesc,
		GetGPUVirtualAddress,
		WriteToSubresource,
		ReadFromSubresource,
		GetHeapProperties,

		VTableSize,
	};

	enum class ID3D12CommandAllocator : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12DeviceChild */
		GetDevice,

		/* ID3D12Pageable */

		/* ID3D12CommandAllocator */
		Reset,

		VTableSize,
	};

	enum class ID3D12Fence : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12DeviceChild */
		GetDevice,

		/* ID3D12Pageable */

		/* ID3D12Fence */
		GetCompletedValue,
		SetEventOnCompletion,
		Signal,

		VTableSize,
	};

	enum class ID3D12Fence1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12DeviceChild */
		GetDevice,

		/* ID3D12Pageable */

		/* ID3D12Fence */
		GetCompletedValue,
		SetEventOnCompletion,
		Signal,

		/* ID3D12Fence1 */
		GetCreationFlags,

		VTableSize,
	};

	enum class ID3D12PipelineState : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12DeviceChild */
		GetDevice,

		/* ID3D12Pageable */

		/* ID3D12PipelineState */
		GetCachedBlob,

		VTableSize,
	};

	enum class ID3D12DescriptorHeap : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12DeviceChild */
		GetDevice,

		/* ID3D12Pageable */

		/* ID3D12DescriptorHeap */
		GetDesc,
		GetCPUDescriptorHandleForHeapStart,
		GetGPUDescriptorHandleForHeapStart,

		VTableSize,
	};

	enum class ID3D12CommandList : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12DeviceChild */
		GetDevice,

		/* ID3D12CommandList */
		GetType,

		VTableSize,
	};

	enum class ID3D12GraphicsCommandList : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12DeviceChild */
		GetDevice,

		/* ID3D12CommandList */
		GetType,

		/* ID3D12GraphicsCommandList */
		Close,
		Reset,
		ClearState,
		DrawInstanced,
		DrawIndexedInstanced,
		Dispatch,
		CopyBufferRegion,
		CopyTextureRegion,
		CopyResource,
		CopyTiles,
		ResolveSubresource,
		IASetPrimitiveTopology,
		RSSetViewports,
		RSSetScissorRects,
		OMSetBlendFactor,
		OMSetStencilRef,
		SetPipelineState,
		ResourceBarrier,
		ExecuteBundle,
		SetDescriptorHeaps,
		SetComputeRootSignature,
		SetGraphicsRootSignature,
		SetComputeRootDescriptorTable,
		SetGraphicsRootDescriptorTable,
		SetComputeRoot32BitConstant,
		SetGraphicsRoot32BitConstant,
		SetComputeRoot32BitConstants,
		SetGraphicsRoot32BitConstants,
		SetComputeRootConstantBufferView,
		SetGraphicsRootConstantBufferView,
		SetComputeRootShaderResourceView,
		SetGraphicsRootShaderResourceView,
		SetComputeRootUnorderedAccessView,
		SetGraphicsRootUnorderedAccessView,
		IASetIndexBuffer,
		IASetVertexBuffers,
		SOSetTargets,
		OMSetRenderTargets,
		ClearDepthStencilView,
		ClearRenderTargetView,
		ClearUnorderedAccessViewUint,
		ClearUnorderedAccessViewFloat,
		DiscardResource,
		BeginQuery,
		EndQuery,
		ResolveQueryData,
		SetPredication,
		SetMarker,
		BeginEvent,
		EndEvent,
		ExecuteIndirect,

		VTableSize,
	};

	enum class ID3D12GraphicsCommandList1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12DeviceChild */
		GetDevice,

		/* ID3D12CommandList */
		GetType,

		/* ID3D12GraphicsCommandList */
		Close,
		Reset,
		ClearState,
		DrawInstanced,
		DrawIndexedInstanced,
		Dispatch,
		CopyBufferRegion,
		CopyTextureRegion,
		CopyResource,
		CopyTiles,
		ResolveSubresource,
		IASetPrimitiveTopology,
		RSSetViewports,
		RSSetScissorRects,
		OMSetBlendFactor,
		OMSetStencilRef,
		SetPipelineState,
		ResourceBarrier,
		ExecuteBundle,
		SetDescriptorHeaps,
		SetComputeRootSignature,
		SetGraphicsRootSignature,
		SetComputeRootDescriptorTable,
		SetGraphicsRootDescriptorTable,
		SetComputeRoot32BitConstant,
		SetGraphicsRoot32BitConstant,
		SetComputeRoot32BitConstants,
		SetGraphicsRoot32BitConstants,
		SetComputeRootConstantBufferView,
		SetGraphicsRootConstantBufferView,
		SetComputeRootShaderResourceView,
		SetGraphicsRootShaderResourceView,
		SetComputeRootUnorderedAccessView,
		SetGraphicsRootUnorderedAccessView,
		IASetIndexBuffer,
		IASetVertexBuffers,
		SOSetTargets,
		OMSetRenderTargets,
		ClearDepthStencilView,
		ClearRenderTargetView,
		ClearUnorderedAccessViewUint,
		ClearUnorderedAccessViewFloat,
		DiscardResource,
		BeginQuery,
		EndQuery,
		ResolveQueryData,
		SetPredication,
		SetMarker,
		BeginEvent,
		EndEvent,
		ExecuteIndirect,

		/* ID3D12GraphicsCommandList1 */
		AtomicCopyBufferUINT,
		AtomicCopyBufferUINT64,
		OMSetDepthBounds,
		SetSamplePositions,
		ResolveSubresourceRegion,
		SetViewInstanceMask,

		VTableSize,
	};

	enum class ID3D12GraphicsCommandList2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12DeviceChild */
		GetDevice,

		/* ID3D12CommandList */
		GetType,

		/* ID3D12GraphicsCommandList */
		Close,
		Reset,
		ClearState,
		DrawInstanced,
		DrawIndexedInstanced,
		Dispatch,
		CopyBufferRegion,
		CopyTextureRegion,
		CopyResource,
		CopyTiles,
		ResolveSubresource,
		IASetPrimitiveTopology,
		RSSetViewports,
		RSSetScissorRects,
		OMSetBlendFactor,
		OMSetStencilRef,
		SetPipelineState,
		ResourceBarrier,
		ExecuteBundle,
		SetDescriptorHeaps,
		SetComputeRootSignature,
		SetGraphicsRootSignature,
		SetComputeRootDescriptorTable,
		SetGraphicsRootDescriptorTable,
		SetComputeRoot32BitConstant,
		SetGraphicsRoot32BitConstant,
		SetComputeRoot32BitConstants,
		SetGraphicsRoot32BitConstants,
		SetComputeRootConstantBufferView,
		SetGraphicsRootConstantBufferView,
		SetComputeRootShaderResourceView,
		SetGraphicsRootShaderResourceView,
		SetComputeRootUnorderedAccessView,
		SetGraphicsRootUnorderedAccessView,
		IASetIndexBuffer,
		IASetVertexBuffers,
		SOSetTargets,
		OMSetRenderTargets,
		ClearDepthStencilView,
		ClearRenderTargetView,
		ClearUnorderedAccessViewUint,
		ClearUnorderedAccessViewFloat,
		DiscardResource,
		BeginQuery,
		EndQuery,
		ResolveQueryData,
		SetPredication,
		SetMarker,
		BeginEvent,
		EndEvent,
		ExecuteIndirect,

		/* ID3D12GraphicsCommandList1 */
		AtomicCopyBufferUINT,
		AtomicCopyBufferUINT64,
		OMSetDepthBounds,
		SetSamplePositions,
		ResolveSubresourceRegion,
		SetViewInstanceMask,

		/* ID3D12GraphicsCommandList2 */
		WriteBufferImmediate,

		VTableSize,
	};

	enum class ID3D12CommandQueue : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12DeviceChild */
		GetDevice,

		/* ID3D12Pageable */

		/* ID3D12CommandQueue */
		UpdateTileMappings,
		CopyTileMappings,
		ExecuteCommandLists,
		SetMarker,
		BeginEvent,
		EndEvent,
		Signal,
		Wait,
		GetTimestampFrequency,
		GetClockCalibration,
		GetDesc,

		VTableSize,
	};

	enum class ID3D12Device : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12Device */
		GetNodeCount,
		CreateCommandQueue,
		CreateCommandAllocator,
		CreateGraphicsPipelineState,
		CreateComputePipelineState,
		CreateCommandList,
		CheckFeatureSupport,
		CreateDescriptorHeap,
		GetDescriptorHandleIncrementSize,
		CreateRootSignature,
		CreateConstantBufferView,
		CreateShaderResourceView,
		CreateUnorderedAccessView,
		CreateRenderTargetView,
		CreateDepthStencilView,
		CreateSampler,
		CopyDescriptors,
		CopyDescriptorsSimple,
		GetResourceAllocationInfo,
		GetCustomHeapProperties,
		CreateCommittedResource,
		CreateHeap,
		CreatePlacedResource,
		CreateReservedResource,
		CreateSharedHandle,
		OpenSharedHandle,
		OpenSharedHandleByName,
		MakeResident,
		Evict,
		CreateFence,
		GetDeviceRemovedReason,
		GetCopyableFootprints,
		CreateQueryHeap,
		SetStablePowerState,
		CreateCommandSignature,
		GetResourceTiling,
		GetAdapterLuid,

		VTableSize,
	};

	enum class ID3D12PipelineLibrary : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12DeviceChild */
		GetDevice,

		/* ID3D12PipelineLibrary */
		StorePipeline,
		LoadGraphicsPipeline,
		LoadComputePipeline,
		GetSerializedSize,
		Serialize,

		VTableSize,
	};

	enum class ID3D12PipelineLibrary1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12DeviceChild */
		GetDevice,

		/* ID3D12PipelineLibrary */
		StorePipeline,
		LoadGraphicsPipeline,
		LoadComputePipeline,
		GetSerializedSize,
		Serialize,

		/* ID3D12PipelineLibrary1 */
		LoadPipeline,

		VTableSize,
	};

	enum class ID3D12Device1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12Device */
		GetNodeCount,
		CreateCommandQueue,
		CreateCommandAllocator,
		CreateGraphicsPipelineState,
		CreateComputePipelineState,
		CreateCommandList,
		CheckFeatureSupport,
		CreateDescriptorHeap,
		GetDescriptorHandleIncrementSize,
		CreateRootSignature,
		CreateConstantBufferView,
		CreateShaderResourceView,
		CreateUnorderedAccessView,
		CreateRenderTargetView,
		CreateDepthStencilView,
		CreateSampler,
		CopyDescriptors,
		CopyDescriptorsSimple,
		GetResourceAllocationInfo,
		GetCustomHeapProperties,
		CreateCommittedResource,
		CreateHeap,
		CreatePlacedResource,
		CreateReservedResource,
		CreateSharedHandle,
		OpenSharedHandle,
		OpenSharedHandleByName,
		MakeResident,
		Evict,
		CreateFence,
		GetDeviceRemovedReason,
		GetCopyableFootprints,
		CreateQueryHeap,
		SetStablePowerState,
		CreateCommandSignature,
		GetResourceTiling,
		GetAdapterLuid,

		/* ID3D12Device1 */
		CreatePipelineLibrary,
		SetEventOnMultipleFenceCompletion,
		SetResidencyPriority,

		VTableSize,
	};

	enum class ID3D12Device2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12Device */
		GetNodeCount,
		CreateCommandQueue,
		CreateCommandAllocator,
		CreateGraphicsPipelineState,
		CreateComputePipelineState,
		CreateCommandList,
		CheckFeatureSupport,
		CreateDescriptorHeap,
		GetDescriptorHandleIncrementSize,
		CreateRootSignature,
		CreateConstantBufferView,
		CreateShaderResourceView,
		CreateUnorderedAccessView,
		CreateRenderTargetView,
		CreateDepthStencilView,
		CreateSampler,
		CopyDescriptors,
		CopyDescriptorsSimple,
		GetResourceAllocationInfo,
		GetCustomHeapProperties,
		CreateCommittedResource,
		CreateHeap,
		CreatePlacedResource,
		CreateReservedResource,
		CreateSharedHandle,
		OpenSharedHandle,
		OpenSharedHandleByName,
		MakeResident,
		Evict,
		CreateFence,
		GetDeviceRemovedReason,
		GetCopyableFootprints,
		CreateQueryHeap,
		SetStablePowerState,
		CreateCommandSignature,
		GetResourceTiling,
		GetAdapterLuid,

		/* ID3D12Device1 */
		CreatePipelineLibrary,
		SetEventOnMultipleFenceCompletion,
		SetResidencyPriority,

		/* ID3D12Device2 */
		CreatePipelineState,

		VTableSize,
	};

	enum class ID3D12Device3 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12Device */
		GetNodeCount,
		CreateCommandQueue,
		CreateCommandAllocator,
		CreateGraphicsPipelineState,
		CreateComputePipelineState,
		CreateCommandList,
		CheckFeatureSupport,
		CreateDescriptorHeap,
		GetDescriptorHandleIncrementSize,
		CreateRootSignature,
		CreateConstantBufferView,
		CreateShaderResourceView,
		CreateUnorderedAccessView,
		CreateRenderTargetView,
		CreateDepthStencilView,
		CreateSampler,
		CopyDescriptors,
		CopyDescriptorsSimple,
		GetResourceAllocationInfo,
		GetCustomHeapProperties,
		CreateCommittedResource,
		CreateHeap,
		CreatePlacedResource,
		CreateReservedResource,
		CreateSharedHandle,
		OpenSharedHandle,
		OpenSharedHandleByName,
		MakeResident,
		Evict,
		CreateFence,
		GetDeviceRemovedReason,
		GetCopyableFootprints,
		CreateQueryHeap,
		SetStablePowerState,
		CreateCommandSignature,
		GetResourceTiling,
		GetAdapterLuid,

		/* ID3D12Device1 */
		CreatePipelineLibrary,
		SetEventOnMultipleFenceCompletion,
		SetResidencyPriority,

		/* ID3D12Device2 */
		CreatePipelineState,

		/* ID3D12Device3 */
		OpenExistingHeapFromAddress,
		OpenExistingHeapFromFileMapping,
		EnqueueMakeResident,

		VTableSize,
	};

	enum class ID3D12ProtectedSession : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12DeviceChild */
		GetDevice,

		/* ID3D12ProtectedSession */
		GetStatusFence,
		GetSessionStatus,

		VTableSize,
	};

	enum class ID3D12ProtectedResourceSession : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12DeviceChild */
		GetDevice,

		/* ID3D12ProtectedSession */
		GetStatusFence,
		GetSessionStatus,

		/* ID3D12ProtectedResourceSession */
		GetDesc,

		VTableSize,
	};

	enum class ID3D12Device4 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12Device */
		GetNodeCount,
		CreateCommandQueue,
		CreateCommandAllocator,
		CreateGraphicsPipelineState,
		CreateComputePipelineState,
		CreateCommandList,
		CheckFeatureSupport,
		CreateDescriptorHeap,
		GetDescriptorHandleIncrementSize,
		CreateRootSignature,
		CreateConstantBufferView,
		CreateShaderResourceView,
		CreateUnorderedAccessView,
		CreateRenderTargetView,
		CreateDepthStencilView,
		CreateSampler,
		CopyDescriptors,
		CopyDescriptorsSimple,
		GetResourceAllocationInfo,
		GetCustomHeapProperties,
		CreateCommittedResource,
		CreateHeap,
		CreatePlacedResource,
		CreateReservedResource,
		CreateSharedHandle,
		OpenSharedHandle,
		OpenSharedHandleByName,
		MakeResident,
		Evict,
		CreateFence,
		GetDeviceRemovedReason,
		GetCopyableFootprints,
		CreateQueryHeap,
		SetStablePowerState,
		CreateCommandSignature,
		GetResourceTiling,
		GetAdapterLuid,

		/* ID3D12Device1 */
		CreatePipelineLibrary,
		SetEventOnMultipleFenceCompletion,
		SetResidencyPriority,

		/* ID3D12Device2 */
		CreatePipelineState,

		/* ID3D12Device3 */
		OpenExistingHeapFromAddress,
		OpenExistingHeapFromFileMapping,
		EnqueueMakeResident,

		/* ID3D12Device4 */
		CreateCommandList1,
		CreateProtectedResourceSession,
		CreateCommittedResource1,
		CreateHeap1,
		CreateReservedResource1,
		GetResourceAllocationInfo1,

		VTableSize,
	};

	enum class ID3D12LifetimeOwner : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12LifetimeOwner */
		LifetimeStateUpdated,

		VTableSize,
	};

	enum class ID3D12SwapChainAssistant : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12SwapChainAssistant */
		GetLUID,
		GetSwapChainObject,
		GetCurrentResourceAndCommandQueue,
		InsertImplicitSync,

		VTableSize,
	};

	enum class ID3D12LifetimeTracker : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12DeviceChild */
		GetDevice,

		/* ID3D12LifetimeTracker */
		DestroyOwnedObject,

		VTableSize,
	};

	enum class ID3D12StateObjectProperties : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12StateObjectProperties */
		GetShaderIdentifier,
		GetShaderStackSize,
		GetPipelineStackSize,
		SetPipelineStackSize,

		VTableSize,
	};

	enum class ID3D12Device5 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12Device */
		GetNodeCount,
		CreateCommandQueue,
		CreateCommandAllocator,
		CreateGraphicsPipelineState,
		CreateComputePipelineState,
		CreateCommandList,
		CheckFeatureSupport,
		CreateDescriptorHeap,
		GetDescriptorHandleIncrementSize,
		CreateRootSignature,
		CreateConstantBufferView,
		CreateShaderResourceView,
		CreateUnorderedAccessView,
		CreateRenderTargetView,
		CreateDepthStencilView,
		CreateSampler,
		CopyDescriptors,
		CopyDescriptorsSimple,
		GetResourceAllocationInfo,
		GetCustomHeapProperties,
		CreateCommittedResource,
		CreateHeap,
		CreatePlacedResource,
		CreateReservedResource,
		CreateSharedHandle,
		OpenSharedHandle,
		OpenSharedHandleByName,
		MakeResident,
		Evict,
		CreateFence,
		GetDeviceRemovedReason,
		GetCopyableFootprints,
		CreateQueryHeap,
		SetStablePowerState,
		CreateCommandSignature,
		GetResourceTiling,
		GetAdapterLuid,

		/* ID3D12Device1 */
		CreatePipelineLibrary,
		SetEventOnMultipleFenceCompletion,
		SetResidencyPriority,

		/* ID3D12Device2 */
		CreatePipelineState,

		/* ID3D12Device3 */
		OpenExistingHeapFromAddress,
		OpenExistingHeapFromFileMapping,
		EnqueueMakeResident,

		/* ID3D12Device4 */
		CreateCommandList1,
		CreateProtectedResourceSession,
		CreateCommittedResource1,
		CreateHeap1,
		CreateReservedResource1,
		GetResourceAllocationInfo1,

		/* ID3D12Device5 */
		CreateLifetimeTracker,
		RemoveDevice,
		EnumerateMetaCommands,
		EnumerateMetaCommandParameters,
		CreateMetaCommand,
		CreateStateObject,
		GetRaytracingAccelerationStructurePrebuildInfo,
		CheckDriverMatchingIdentifier,

		VTableSize,
	};

	enum class ID3D12DeviceRemovedExtendedDataSettings : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12DeviceRemovedExtendedDataSettings */
		SetAutoBreadcrumbsEnablement,
		SetPageFaultEnablement,
		SetWatsonDumpEnablement,

		VTableSize,
	};

	enum class ID3D12DeviceRemovedExtendedDataSettings1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12DeviceRemovedExtendedDataSettings */
		SetAutoBreadcrumbsEnablement,
		SetPageFaultEnablement,
		SetWatsonDumpEnablement,

		/* ID3D12DeviceRemovedExtendedDataSettings1 */
		SetBreadcrumbContextEnablement,

		VTableSize,
	};

	enum class ID3D12DeviceRemovedExtendedData : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12DeviceRemovedExtendedData */
		GetAutoBreadcrumbsOutput,
		GetPageFaultAllocationOutput,

		VTableSize,
	};

	enum class ID3D12DeviceRemovedExtendedData1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12DeviceRemovedExtendedData */
		GetAutoBreadcrumbsOutput,
		GetPageFaultAllocationOutput,

		/* ID3D12DeviceRemovedExtendedData1 */
		GetAutoBreadcrumbsOutput1,
		GetPageFaultAllocationOutput1,

		VTableSize,
	};

	enum class ID3D12DeviceRemovedExtendedData2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12DeviceRemovedExtendedData */
		GetAutoBreadcrumbsOutput,
		GetPageFaultAllocationOutput,

		/* ID3D12DeviceRemovedExtendedData1 */
		GetAutoBreadcrumbsOutput1,
		GetPageFaultAllocationOutput1,

		/* ID3D12DeviceRemovedExtendedData2 */
		GetPageFaultAllocationOutput2,
		GetDeviceState,

		VTableSize,
	};

	enum class ID3D12Device6 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12Device */
		GetNodeCount,
		CreateCommandQueue,
		CreateCommandAllocator,
		CreateGraphicsPipelineState,
		CreateComputePipelineState,
		CreateCommandList,
		CheckFeatureSupport,
		CreateDescriptorHeap,
		GetDescriptorHandleIncrementSize,
		CreateRootSignature,
		CreateConstantBufferView,
		CreateShaderResourceView,
		CreateUnorderedAccessView,
		CreateRenderTargetView,
		CreateDepthStencilView,
		CreateSampler,
		CopyDescriptors,
		CopyDescriptorsSimple,
		GetResourceAllocationInfo,
		GetCustomHeapProperties,
		CreateCommittedResource,
		CreateHeap,
		CreatePlacedResource,
		CreateReservedResource,
		CreateSharedHandle,
		OpenSharedHandle,
		OpenSharedHandleByName,
		MakeResident,
		Evict,
		CreateFence,
		GetDeviceRemovedReason,
		GetCopyableFootprints,
		CreateQueryHeap,
		SetStablePowerState,
		CreateCommandSignature,
		GetResourceTiling,
		GetAdapterLuid,

		/* ID3D12Device1 */
		CreatePipelineLibrary,
		SetEventOnMultipleFenceCompletion,
		SetResidencyPriority,

		/* ID3D12Device2 */
		CreatePipelineState,

		/* ID3D12Device3 */
		OpenExistingHeapFromAddress,
		OpenExistingHeapFromFileMapping,
		EnqueueMakeResident,

		/* ID3D12Device4 */
		CreateCommandList1,
		CreateProtectedResourceSession,
		CreateCommittedResource1,
		CreateHeap1,
		CreateReservedResource1,
		GetResourceAllocationInfo1,

		/* ID3D12Device5 */
		CreateLifetimeTracker,
		RemoveDevice,
		EnumerateMetaCommands,
		EnumerateMetaCommandParameters,
		CreateMetaCommand,
		CreateStateObject,
		GetRaytracingAccelerationStructurePrebuildInfo,
		CheckDriverMatchingIdentifier,

		/* ID3D12Device6 */
		SetBackgroundProcessingMode,

		VTableSize,
	};

	enum class ID3D12ProtectedResourceSession1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12DeviceChild */
		GetDevice,

		/* ID3D12ProtectedSession */
		GetStatusFence,
		GetSessionStatus,

		/* ID3D12ProtectedResourceSession */
		GetDesc,

		/* ID3D12ProtectedResourceSession1 */
		GetDesc1,

		VTableSize,
	};

	enum class ID3D12Device7 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12Device */
		GetNodeCount,
		CreateCommandQueue,
		CreateCommandAllocator,
		CreateGraphicsPipelineState,
		CreateComputePipelineState,
		CreateCommandList,
		CheckFeatureSupport,
		CreateDescriptorHeap,
		GetDescriptorHandleIncrementSize,
		CreateRootSignature,
		CreateConstantBufferView,
		CreateShaderResourceView,
		CreateUnorderedAccessView,
		CreateRenderTargetView,
		CreateDepthStencilView,
		CreateSampler,
		CopyDescriptors,
		CopyDescriptorsSimple,
		GetResourceAllocationInfo,
		GetCustomHeapProperties,
		CreateCommittedResource,
		CreateHeap,
		CreatePlacedResource,
		CreateReservedResource,
		CreateSharedHandle,
		OpenSharedHandle,
		OpenSharedHandleByName,
		MakeResident,
		Evict,
		CreateFence,
		GetDeviceRemovedReason,
		GetCopyableFootprints,
		CreateQueryHeap,
		SetStablePowerState,
		CreateCommandSignature,
		GetResourceTiling,
		GetAdapterLuid,

		/* ID3D12Device1 */
		CreatePipelineLibrary,
		SetEventOnMultipleFenceCompletion,
		SetResidencyPriority,

		/* ID3D12Device2 */
		CreatePipelineState,

		/* ID3D12Device3 */
		OpenExistingHeapFromAddress,
		OpenExistingHeapFromFileMapping,
		EnqueueMakeResident,

		/* ID3D12Device4 */
		CreateCommandList1,
		CreateProtectedResourceSession,
		CreateCommittedResource1,
		CreateHeap1,
		CreateReservedResource1,
		GetResourceAllocationInfo1,

		/* ID3D12Device5 */
		CreateLifetimeTracker,
		RemoveDevice,
		EnumerateMetaCommands,
		EnumerateMetaCommandParameters,
		CreateMetaCommand,
		CreateStateObject,
		GetRaytracingAccelerationStructurePrebuildInfo,
		CheckDriverMatchingIdentifier,

		/* ID3D12Device6 */
		SetBackgroundProcessingMode,

		/* ID3D12Device7 */
		AddToStateObject,
		CreateProtectedResourceSession1,

		VTableSize,
	};

	enum class ID3D12Device8 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12Device */
		GetNodeCount,
		CreateCommandQueue,
		CreateCommandAllocator,
		CreateGraphicsPipelineState,
		CreateComputePipelineState,
		CreateCommandList,
		CheckFeatureSupport,
		CreateDescriptorHeap,
		GetDescriptorHandleIncrementSize,
		CreateRootSignature,
		CreateConstantBufferView,
		CreateShaderResourceView,
		CreateUnorderedAccessView,
		CreateRenderTargetView,
		CreateDepthStencilView,
		CreateSampler,
		CopyDescriptors,
		CopyDescriptorsSimple,
		GetResourceAllocationInfo,
		GetCustomHeapProperties,
		CreateCommittedResource,
		CreateHeap,
		CreatePlacedResource,
		CreateReservedResource,
		CreateSharedHandle,
		OpenSharedHandle,
		OpenSharedHandleByName,
		MakeResident,
		Evict,
		CreateFence,
		GetDeviceRemovedReason,
		GetCopyableFootprints,
		CreateQueryHeap,
		SetStablePowerState,
		CreateCommandSignature,
		GetResourceTiling,
		GetAdapterLuid,

		/* ID3D12Device1 */
		CreatePipelineLibrary,
		SetEventOnMultipleFenceCompletion,
		SetResidencyPriority,

		/* ID3D12Device2 */
		CreatePipelineState,

		/* ID3D12Device3 */
		OpenExistingHeapFromAddress,
		OpenExistingHeapFromFileMapping,
		EnqueueMakeResident,

		/* ID3D12Device4 */
		CreateCommandList1,
		CreateProtectedResourceSession,
		CreateCommittedResource1,
		CreateHeap1,
		CreateReservedResource1,
		GetResourceAllocationInfo1,

		/* ID3D12Device5 */
		CreateLifetimeTracker,
		RemoveDevice,
		EnumerateMetaCommands,
		EnumerateMetaCommandParameters,
		CreateMetaCommand,
		CreateStateObject,
		GetRaytracingAccelerationStructurePrebuildInfo,
		CheckDriverMatchingIdentifier,

		/* ID3D12Device6 */
		SetBackgroundProcessingMode,

		/* ID3D12Device7 */
		AddToStateObject,
		CreateProtectedResourceSession1,

		/* ID3D12Device8 */
		GetResourceAllocationInfo2,
		CreateCommittedResource2,
		CreatePlacedResource1,
		CreateSamplerFeedbackUnorderedAccessView,
		GetCopyableFootprints1,

		VTableSize,
	};

	enum class ID3D12Resource1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12DeviceChild */
		GetDevice,

		/* ID3D12Pageable */

		/* ID3D12Resource */
		Map,
		Unmap,
		GetDesc,
		GetGPUVirtualAddress,
		WriteToSubresource,
		ReadFromSubresource,
		GetHeapProperties,

		/* ID3D12Resource1 */
		GetProtectedResourceSession,

		VTableSize,
	};

	enum class ID3D12Resource2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12DeviceChild */
		GetDevice,

		/* ID3D12Pageable */

		/* ID3D12Resource */
		Map,
		Unmap,
		GetDesc,
		GetGPUVirtualAddress,
		WriteToSubresource,
		ReadFromSubresource,
		GetHeapProperties,

		/* ID3D12Resource1 */
		GetProtectedResourceSession,

		/* ID3D12Resource2 */
		GetDesc1,

		VTableSize,
	};

	enum class ID3D12Heap1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12DeviceChild */
		GetDevice,

		/* ID3D12Pageable */

		/* ID3D12Heap */
		GetDesc,

		/* ID3D12Heap1 */
		GetProtectedResourceSession,

		VTableSize,
	};

	enum class ID3D12GraphicsCommandList3 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12DeviceChild */
		GetDevice,

		/* ID3D12CommandList */
		GetType,

		/* ID3D12GraphicsCommandList */
		Close,
		Reset,
		ClearState,
		DrawInstanced,
		DrawIndexedInstanced,
		Dispatch,
		CopyBufferRegion,
		CopyTextureRegion,
		CopyResource,
		CopyTiles,
		ResolveSubresource,
		IASetPrimitiveTopology,
		RSSetViewports,
		RSSetScissorRects,
		OMSetBlendFactor,
		OMSetStencilRef,
		SetPipelineState,
		ResourceBarrier,
		ExecuteBundle,
		SetDescriptorHeaps,
		SetComputeRootSignature,
		SetGraphicsRootSignature,
		SetComputeRootDescriptorTable,
		SetGraphicsRootDescriptorTable,
		SetComputeRoot32BitConstant,
		SetGraphicsRoot32BitConstant,
		SetComputeRoot32BitConstants,
		SetGraphicsRoot32BitConstants,
		SetComputeRootConstantBufferView,
		SetGraphicsRootConstantBufferView,
		SetComputeRootShaderResourceView,
		SetGraphicsRootShaderResourceView,
		SetComputeRootUnorderedAccessView,
		SetGraphicsRootUnorderedAccessView,
		IASetIndexBuffer,
		IASetVertexBuffers,
		SOSetTargets,
		OMSetRenderTargets,
		ClearDepthStencilView,
		ClearRenderTargetView,
		ClearUnorderedAccessViewUint,
		ClearUnorderedAccessViewFloat,
		DiscardResource,
		BeginQuery,
		EndQuery,
		ResolveQueryData,
		SetPredication,
		SetMarker,
		BeginEvent,
		EndEvent,
		ExecuteIndirect,

		/* ID3D12GraphicsCommandList1 */
		AtomicCopyBufferUINT,
		AtomicCopyBufferUINT64,
		OMSetDepthBounds,
		SetSamplePositions,
		ResolveSubresourceRegion,
		SetViewInstanceMask,

		/* ID3D12GraphicsCommandList2 */
		WriteBufferImmediate,

		/* ID3D12GraphicsCommandList3 */
		SetProtectedResourceSession,

		VTableSize,
	};

	enum class ID3D12MetaCommand : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12DeviceChild */
		GetDevice,

		/* ID3D12Pageable */

		/* ID3D12MetaCommand */
		GetRequiredParameterResourceSize,

		VTableSize,
	};

	enum class ID3D12GraphicsCommandList4 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12DeviceChild */
		GetDevice,

		/* ID3D12CommandList */
		GetType,

		/* ID3D12GraphicsCommandList */
		Close,
		Reset,
		ClearState,
		DrawInstanced,
		DrawIndexedInstanced,
		Dispatch,
		CopyBufferRegion,
		CopyTextureRegion,
		CopyResource,
		CopyTiles,
		ResolveSubresource,
		IASetPrimitiveTopology,
		RSSetViewports,
		RSSetScissorRects,
		OMSetBlendFactor,
		OMSetStencilRef,
		SetPipelineState,
		ResourceBarrier,
		ExecuteBundle,
		SetDescriptorHeaps,
		SetComputeRootSignature,
		SetGraphicsRootSignature,
		SetComputeRootDescriptorTable,
		SetGraphicsRootDescriptorTable,
		SetComputeRoot32BitConstant,
		SetGraphicsRoot32BitConstant,
		SetComputeRoot32BitConstants,
		SetGraphicsRoot32BitConstants,
		SetComputeRootConstantBufferView,
		SetGraphicsRootConstantBufferView,
		SetComputeRootShaderResourceView,
		SetGraphicsRootShaderResourceView,
		SetComputeRootUnorderedAccessView,
		SetGraphicsRootUnorderedAccessView,
		IASetIndexBuffer,
		IASetVertexBuffers,
		SOSetTargets,
		OMSetRenderTargets,
		ClearDepthStencilView,
		ClearRenderTargetView,
		ClearUnorderedAccessViewUint,
		ClearUnorderedAccessViewFloat,
		DiscardResource,
		BeginQuery,
		EndQuery,
		ResolveQueryData,
		SetPredication,
		SetMarker,
		BeginEvent,
		EndEvent,
		ExecuteIndirect,

		/* ID3D12GraphicsCommandList1 */
		AtomicCopyBufferUINT,
		AtomicCopyBufferUINT64,
		OMSetDepthBounds,
		SetSamplePositions,
		ResolveSubresourceRegion,
		SetViewInstanceMask,

		/* ID3D12GraphicsCommandList2 */
		WriteBufferImmediate,

		/* ID3D12GraphicsCommandList3 */
		SetProtectedResourceSession,

		/* ID3D12GraphicsCommandList4 */
		BeginRenderPass,
		EndRenderPass,
		InitializeMetaCommand,
		ExecuteMetaCommand,
		BuildRaytracingAccelerationStructure,
		EmitRaytracingAccelerationStructurePostbuildInfo,
		CopyRaytracingAccelerationStructure,
		SetPipelineState1,
		DispatchRays,

		VTableSize,
	};

	enum class ID3D12ShaderCacheSession : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12DeviceChild */
		GetDevice,

		/* ID3D12ShaderCacheSession */
		FindValue,
		StoreValue,
		SetDeleteOnDestroy,
		GetDesc,

		VTableSize,
	};

	enum class ID3D12Device9 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12Device */
		GetNodeCount,
		CreateCommandQueue,
		CreateCommandAllocator,
		CreateGraphicsPipelineState,
		CreateComputePipelineState,
		CreateCommandList,
		CheckFeatureSupport,
		CreateDescriptorHeap,
		GetDescriptorHandleIncrementSize,
		CreateRootSignature,
		CreateConstantBufferView,
		CreateShaderResourceView,
		CreateUnorderedAccessView,
		CreateRenderTargetView,
		CreateDepthStencilView,
		CreateSampler,
		CopyDescriptors,
		CopyDescriptorsSimple,
		GetResourceAllocationInfo,
		GetCustomHeapProperties,
		CreateCommittedResource,
		CreateHeap,
		CreatePlacedResource,
		CreateReservedResource,
		CreateSharedHandle,
		OpenSharedHandle,
		OpenSharedHandleByName,
		MakeResident,
		Evict,
		CreateFence,
		GetDeviceRemovedReason,
		GetCopyableFootprints,
		CreateQueryHeap,
		SetStablePowerState,
		CreateCommandSignature,
		GetResourceTiling,
		GetAdapterLuid,

		/* ID3D12Device1 */
		CreatePipelineLibrary,
		SetEventOnMultipleFenceCompletion,
		SetResidencyPriority,

		/* ID3D12Device2 */
		CreatePipelineState,

		/* ID3D12Device3 */
		OpenExistingHeapFromAddress,
		OpenExistingHeapFromFileMapping,
		EnqueueMakeResident,

		/* ID3D12Device4 */
		CreateCommandList1,
		CreateProtectedResourceSession,
		CreateCommittedResource1,
		CreateHeap1,
		CreateReservedResource1,
		GetResourceAllocationInfo1,

		/* ID3D12Device5 */
		CreateLifetimeTracker,
		RemoveDevice,
		EnumerateMetaCommands,
		EnumerateMetaCommandParameters,
		CreateMetaCommand,
		CreateStateObject,
		GetRaytracingAccelerationStructurePrebuildInfo,
		CheckDriverMatchingIdentifier,

		/* ID3D12Device6 */
		SetBackgroundProcessingMode,

		/* ID3D12Device7 */
		AddToStateObject,
		CreateProtectedResourceSession1,

		/* ID3D12Device8 */
		GetResourceAllocationInfo2,
		CreateCommittedResource2,
		CreatePlacedResource1,
		CreateSamplerFeedbackUnorderedAccessView,
		GetCopyableFootprints1,

		/* ID3D12Device9 */
		CreateShaderCacheSession,
		ShaderCacheControl,
		CreateCommandQueue1,

		VTableSize,
	};

	enum class ID3D12Tools : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Tools */
		EnableShaderInstrumentation,
		ShaderInstrumentationEnabled,

		VTableSize,
	};

	enum class ID3D12Debug : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Debug */
		EnableDebugLayer,

		VTableSize,
	};

	enum class ID3D12Debug1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Debug1 */
		EnableDebugLayer,
		SetEnableGPUBasedValidation,
		SetEnableSynchronizedCommandQueueValidation,

		VTableSize,
	};

	enum class ID3D12Debug2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Debug2 */
		SetGPUBasedValidationFlags,

		VTableSize,
	};

	enum class ID3D12Debug3 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Debug */
		EnableDebugLayer,

		/* ID3D12Debug3 */
		SetEnableGPUBasedValidation,
		SetEnableSynchronizedCommandQueueValidation,
		SetGPUBasedValidationFlags,

		VTableSize,
	};

	enum class ID3D12Debug4 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Debug */
		EnableDebugLayer,

		/* ID3D12Debug3 */
		SetEnableGPUBasedValidation,
		SetEnableSynchronizedCommandQueueValidation,
		SetGPUBasedValidationFlags,

		/* ID3D12Debug4 */
		DisableDebugLayer,

		VTableSize,
	};

	enum class ID3D12Debug5 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Debug */
		EnableDebugLayer,

		/* ID3D12Debug3 */
		SetEnableGPUBasedValidation,
		SetEnableSynchronizedCommandQueueValidation,
		SetGPUBasedValidationFlags,

		/* ID3D12Debug4 */
		DisableDebugLayer,

		/* ID3D12Debug5 */
		SetEnableAutoName,

		VTableSize,
	};

	enum class ID3D12DebugDevice1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12DebugDevice1 */
		SetDebugParameter,
		GetDebugParameter,
		ReportLiveDeviceObjects,

		VTableSize,
	};

	enum class ID3D12DebugDevice : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12DebugDevice */
		SetFeatureMask,
		GetFeatureMask,
		ReportLiveDeviceObjects,

		VTableSize,
	};

	enum class ID3D12DebugDevice2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12DebugDevice */
		SetFeatureMask,
		GetFeatureMask,
		ReportLiveDeviceObjects,

		/* ID3D12DebugDevice2 */
		SetDebugParameter,
		GetDebugParameter,

		VTableSize,
	};

	enum class ID3D12DebugCommandQueue : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12DebugCommandQueue */
		AssertResourceState,

		VTableSize,
	};

	enum class ID3D12DebugCommandList1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12DebugCommandList1 */
		AssertResourceState,
		SetDebugParameter,
		GetDebugParameter,

		VTableSize,
	};

	enum class ID3D12DebugCommandList : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12DebugCommandList */
		AssertResourceState,
		SetFeatureMask,
		GetFeatureMask,

		VTableSize,
	};

	enum class ID3D12DebugCommandList2 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12DebugCommandList */
		AssertResourceState,
		SetFeatureMask,
		GetFeatureMask,

		/* ID3D12DebugCommandList2 */
		SetDebugParameter,
		GetDebugParameter,

		VTableSize,
	};

	enum class ID3D12SharingContract : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12SharingContract */
		Present,
		SharedFenceSignal,
		BeginCapturableWork,
		EndCapturableWork,

		VTableSize,
	};

	enum class ID3D12InfoQueue : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12InfoQueue */
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

	enum class ID3D12InfoQueue1 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12InfoQueue */
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

		/* ID3D12InfoQueue1 */
		RegisterMessageCallback,
		UnregisterMessageCallback,

		VTableSize,
	};

	enum class ID3D12SDKConfiguration : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12SDKConfiguration */
		SetSDKVersion,

		VTableSize,
	};

	enum class ID3D12GraphicsCommandList5 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12DeviceChild */
		GetDevice,

		/* ID3D12CommandList */
		GetType,

		/* ID3D12GraphicsCommandList */
		Close,
		Reset,
		ClearState,
		DrawInstanced,
		DrawIndexedInstanced,
		Dispatch,
		CopyBufferRegion,
		CopyTextureRegion,
		CopyResource,
		CopyTiles,
		ResolveSubresource,
		IASetPrimitiveTopology,
		RSSetViewports,
		RSSetScissorRects,
		OMSetBlendFactor,
		OMSetStencilRef,
		SetPipelineState,
		ResourceBarrier,
		ExecuteBundle,
		SetDescriptorHeaps,
		SetComputeRootSignature,
		SetGraphicsRootSignature,
		SetComputeRootDescriptorTable,
		SetGraphicsRootDescriptorTable,
		SetComputeRoot32BitConstant,
		SetGraphicsRoot32BitConstant,
		SetComputeRoot32BitConstants,
		SetGraphicsRoot32BitConstants,
		SetComputeRootConstantBufferView,
		SetGraphicsRootConstantBufferView,
		SetComputeRootShaderResourceView,
		SetGraphicsRootShaderResourceView,
		SetComputeRootUnorderedAccessView,
		SetGraphicsRootUnorderedAccessView,
		IASetIndexBuffer,
		IASetVertexBuffers,
		SOSetTargets,
		OMSetRenderTargets,
		ClearDepthStencilView,
		ClearRenderTargetView,
		ClearUnorderedAccessViewUint,
		ClearUnorderedAccessViewFloat,
		DiscardResource,
		BeginQuery,
		EndQuery,
		ResolveQueryData,
		SetPredication,
		SetMarker,
		BeginEvent,
		EndEvent,
		ExecuteIndirect,

		/* ID3D12GraphicsCommandList1 */
		AtomicCopyBufferUINT,
		AtomicCopyBufferUINT64,
		OMSetDepthBounds,
		SetSamplePositions,
		ResolveSubresourceRegion,
		SetViewInstanceMask,

		/* ID3D12GraphicsCommandList2 */
		WriteBufferImmediate,

		/* ID3D12GraphicsCommandList3 */
		SetProtectedResourceSession,

		/* ID3D12GraphicsCommandList4 */
		BeginRenderPass,
		EndRenderPass,
		InitializeMetaCommand,
		ExecuteMetaCommand,
		BuildRaytracingAccelerationStructure,
		EmitRaytracingAccelerationStructurePostbuildInfo,
		CopyRaytracingAccelerationStructure,
		SetPipelineState1,
		DispatchRays,

		/* ID3D12GraphicsCommandList5 */
		RSSetShadingRate,
		RSSetShadingRateImage,

		VTableSize,
	};

	enum class ID3D12GraphicsCommandList6 : size_t
	{
		/* IUnknown */
		QueryInterface,
		AddRef,
		Release,

		/* ID3D12Object */
		GetPrivateData,
		SetPrivateData,
		SetPrivateDataInterface,
		SetName,

		/* ID3D12DeviceChild */
		GetDevice,

		/* ID3D12CommandList */
		GetType,

		/* ID3D12GraphicsCommandList */
		Close,
		Reset,
		ClearState,
		DrawInstanced,
		DrawIndexedInstanced,
		Dispatch,
		CopyBufferRegion,
		CopyTextureRegion,
		CopyResource,
		CopyTiles,
		ResolveSubresource,
		IASetPrimitiveTopology,
		RSSetViewports,
		RSSetScissorRects,
		OMSetBlendFactor,
		OMSetStencilRef,
		SetPipelineState,
		ResourceBarrier,
		ExecuteBundle,
		SetDescriptorHeaps,
		SetComputeRootSignature,
		SetGraphicsRootSignature,
		SetComputeRootDescriptorTable,
		SetGraphicsRootDescriptorTable,
		SetComputeRoot32BitConstant,
		SetGraphicsRoot32BitConstant,
		SetComputeRoot32BitConstants,
		SetGraphicsRoot32BitConstants,
		SetComputeRootConstantBufferView,
		SetGraphicsRootConstantBufferView,
		SetComputeRootShaderResourceView,
		SetGraphicsRootShaderResourceView,
		SetComputeRootUnorderedAccessView,
		SetGraphicsRootUnorderedAccessView,
		IASetIndexBuffer,
		IASetVertexBuffers,
		SOSetTargets,
		OMSetRenderTargets,
		ClearDepthStencilView,
		ClearRenderTargetView,
		ClearUnorderedAccessViewUint,
		ClearUnorderedAccessViewFloat,
		DiscardResource,
		BeginQuery,
		EndQuery,
		ResolveQueryData,
		SetPredication,
		SetMarker,
		BeginEvent,
		EndEvent,
		ExecuteIndirect,

		/* ID3D12GraphicsCommandList1 */
		AtomicCopyBufferUINT,
		AtomicCopyBufferUINT64,
		OMSetDepthBounds,
		SetSamplePositions,
		ResolveSubresourceRegion,
		SetViewInstanceMask,

		/* ID3D12GraphicsCommandList2 */
		WriteBufferImmediate,

		/* ID3D12GraphicsCommandList3 */
		SetProtectedResourceSession,

		/* ID3D12GraphicsCommandList4 */
		BeginRenderPass,
		EndRenderPass,
		InitializeMetaCommand,
		ExecuteMetaCommand,
		BuildRaytracingAccelerationStructure,
		EmitRaytracingAccelerationStructurePostbuildInfo,
		CopyRaytracingAccelerationStructure,
		SetPipelineState1,
		DispatchRays,

		/* ID3D12GraphicsCommandList5 */
		RSSetShadingRate,
		RSSetShadingRateImage,

		/* ID3D12GraphicsCommandList6 */
		DispatchMesh,

		VTableSize,
	};

}
