#pragma once

#include <fmt/core.h>

#include <memory>
#include <winerror.h>
#include <comdef.h>
#include <functional>

namespace RHook {
	using LogCallBackFn_t = std::function<void(const std::string&)>;

	class Log {
	private:
		struct Logger {
			template<typename... Args>
			void Trace(fmt::v10::format_string<Args...> fmt, Args&&... args) {
				if (!FnTrace)
					return;

				const auto output = fmt::format(fmt, std::forward<Args>(args)...);
				FnTrace(output);
			}

			template<typename... Args>
			void Info(fmt::v10::format_string<Args...> fmt, Args&&... args) {
				if (!FnInfo)
					return;

				const auto output = fmt::format(fmt, std::forward<Args>(args)...);
				FnInfo(output);
			}

			template<typename... Args>
			void Warn(fmt::v10::format_string<Args...> fmt, Args&&... args) {
				if (!FnWarn)
					return;

				const auto output = fmt::format(fmt, std::forward<Args>(args)...);
				FnWarn(output);
			}

			template<typename... Args>
			void Error(fmt::v10::format_string<Args...> fmt, Args&&... args) {
				if (!FnError)
					return;

				const auto output = fmt::format(fmt, std::forward<Args>(args)...);
				FnError(output);
			}

			template<typename... Args>
			void Critical(fmt::v10::format_string<Args...> fmt, Args&&... args) {
				if (!FnCritical)
					return;

				const auto output = fmt::format(fmt, std::forward<Args>(args)...);
				FnCritical(output);
			}

			LogCallBackFn_t FnTrace{};
			LogCallBackFn_t FnInfo{};
			LogCallBackFn_t FnWarn{};
			LogCallBackFn_t FnError{};
			LogCallBackFn_t FnCritical{};
		};

	public:
		static void SetTrace(LogCallBackFn_t fnTrace) { GetLogger()->FnTrace = fnTrace; };
		static void SetInfo(LogCallBackFn_t fnInfo) { GetLogger()->FnInfo = fnInfo; };
		static void SetWarn(LogCallBackFn_t fnWarn) { GetLogger()->FnWarn = fnWarn; };
		static void SetError(LogCallBackFn_t fnError) { GetLogger()->FnError = fnError; };
		static void SetCritical(LogCallBackFn_t fnCritical) { GetLogger()->FnCritical = fnCritical; };

		static std::shared_ptr<Logger>& GetLogger();

	private:
		inline static std::shared_ptr<Logger> s_RHookLogger{};
	};
}


// Log macros
#define RHOOK_TRACE(...)		::RHook::Log::GetLogger()->Trace(__VA_ARGS__)
#define RHOOK_INFO(...)			::RHook::Log::GetLogger()->Info(__VA_ARGS__)
#define RHOOK_WARN(...)			::RHook::Log::GetLogger()->Warn(__VA_ARGS__)
#define RHOOK_ERROR(...)		::RHook::Log::GetLogger()->Error(__VA_ARGS__)
#define RHOOK_CRITICAL(...)		::RHook::Log::GetLogger()->Critical(__VA_ARGS__)

// COM Error Log macros
#define WINCOM_ERROR(X)			::_com_error(X).ErrorMessage()