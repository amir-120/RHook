#include "./Logging.hpp"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace RHook {

	std::shared_ptr<spdlog::logger> Log::s_RHookLogger{};
	std::shared_ptr<spdlog::logger> Log::s_UserLogger{};

	void Log::Init()
	{
		std::vector<spdlog::sink_ptr> logSinks;
		logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("RHook.log", true));

		// Output pattern
		logSinks[0]->set_pattern("%^[%T] %n: %v%$");
		logSinks[1]->set_pattern("[%T] [%l] %n: %v");

		s_RHookLogger = std::make_shared<spdlog::logger>("RHook", begin(logSinks), end(logSinks));
		spdlog::register_logger(s_RHookLogger);
		s_RHookLogger->set_level(spdlog::level::trace);
		s_RHookLogger->flush_on(spdlog::level::trace);

		s_UserLogger = std::make_shared<spdlog::logger>("APP", begin(logSinks), end(logSinks));
		spdlog::register_logger(s_UserLogger);
		s_UserLogger->set_level(spdlog::level::trace);
		s_UserLogger->flush_on(spdlog::level::trace);
	}

}