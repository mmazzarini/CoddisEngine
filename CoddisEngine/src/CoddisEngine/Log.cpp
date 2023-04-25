#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace CoddisEngine {

	std::shared_ptr<spdlog::logger> Log::CoreLogger;
	std::shared_ptr<spdlog::logger> Log::ClientLogger;

	void Log::Init()
	{
		//This is important to set pattern for writing log
		spdlog::set_pattern("%^[%T] %n: %v%$");
		CoreLogger = spdlog::stdout_color_mt("CODDIS");
		CoreLogger->set_level(spdlog::level::trace);
		ClientLogger = spdlog::stdout_color_mt("APP");
		ClientLogger->set_level(spdlog::level::trace);
	}

}