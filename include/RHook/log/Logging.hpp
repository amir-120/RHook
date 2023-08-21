#pragma once

#include <string>

namespace RHook {
	namespace Logging {
		using LogCallBackFn_t = std::function<void(const std::string&)>;

		void SetTrace(LogCallBackFn_t fnTrace);
		void SetInfo(LogCallBackFn_t fnInfo);
		void SetWarn(LogCallBackFn_t fnWarn);
		void SetError(LogCallBackFn_t fnError);
		void SetCritical(LogCallBackFn_t fnCritical);
	}
}

// Setting the log call backs for different levels of log messages
#define RHOOK_LOGGER_SET_TRACE(X)		::RHook::Logging::SetTrace(X)
#define RHOOK_LOGGER_SET_INFO(X)		::RHook::Logging::SetInfo(X)
#define RHOOK_LOGGER_SET_WARN(X)		::RHook::Logging::SetWarn(X)
#define RHOOK_LOGGER_SET_ERROR(X)		::RHook::Logging::SetError(X)
#define RHOOK_LOGGER_SET_CRITICAL(X)	::RHook::Logging::SetCritical(X)