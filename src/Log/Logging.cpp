#include "Logging.hpp"
#include <RHook/log/Logging.hpp>

namespace RHook {
	namespace Logging {
		void SetTrace(LogCallBackFn_t fnTrace) { 
			Log::SetTrace(fnTrace); 
		};

		void SetInfo(LogCallBackFn_t fnInfo) {
			Log::SetInfo(fnInfo);
		};

		void SetWarn(LogCallBackFn_t fnWarn) {
			Log::SetWarn(fnWarn);
		};

		void SetError(LogCallBackFn_t fnError) {
			Log::SetError(fnError);
		};

		void SetCritical(LogCallBackFn_t fnCritical) {
			Log::SetCritical(fnCritical);;
		};
	}

	std::shared_ptr<RHook::Log::Logger>& Log::GetLogger()
	{
		if (!s_RHookLogger) {
			s_RHookLogger = std::make_unique<Logger>();
		}

		return s_RHookLogger;
	}

}