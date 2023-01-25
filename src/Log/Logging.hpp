#pragma once

// Getting rid of the annoying warnings in spdlog and fmt
#pragma warning(push, 0)
#include "../../dependencies/spdlog/include/spdlog/spdlog.h"
#include "../../dependencies/spdlog/include/spdlog/fmt/ostr.h"
#pragma warning(pop)

#include <winerror.h>
#include <comdef.h>

namespace RHook {

	class Log
	{
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetRHookLogger() { return s_RHookLogger; }
		static std::shared_ptr<spdlog::logger>& GetUserLogger() { return s_UserLogger; }
	
	private:
		static std::shared_ptr<spdlog::logger> s_RHookLogger;
		static std::shared_ptr<spdlog::logger> s_UserLogger;
	};

}


// Core log macros
#define RH_RHOOK_TRACE(...)		::RHook::Log::GetRHookLogger()->trace(__VA_ARGS__)
#define RH_RHOOK_INFO(...)		::RHook::Log::GetRHookLogger()->info(__VA_ARGS__)
#define RH_RHOOK_WARN(...)		::RHook::Log::GetRHookLogger()->warn(__VA_ARGS__)
#define RH_RHOOK_ERROR(...)		::RHook::Log::GetRHookLogger()->error(__VA_ARGS__)
#define RH_RHOOK_CRITICAL(...)	::RHook::Log::GetRHookLogger()->critical(__VA_ARGS__)

// Log macros
#define RH_TRACE(...)			::RHook::Log::GetUserLogger()->trace(__VA_ARGS__)
#define RH_INFO(...)			::RHook::Log::GetUserLogger()->info(__VA_ARGS__)
#define RH_WARN(...)			::RHook::Log::GetUserLogger()->warn(__VA_ARGS__)
#define RH_ERROR(...)			::RHook::Log::GetUserLogger()->error(__VA_ARGS__)
#define RH_CRITICAL(...)		::RHook::Log::GetUserLogger()->critical(__VA_ARGS__)

// COM Error Log macros
#define WINCOM_ERROR(X)			::_com_error(X).ErrorMessage()