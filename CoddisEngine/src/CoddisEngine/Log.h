#pragma once

#include <memory>
#include "Core.h"  
#include "spdlog/spdlog.h"

namespace CoddisEngine {

	//The idea is to have 2 loggers, one for client one for engine, so there will be 2 consoles for output.
	class CODDIS_API Log
	{
	
	public:
		//static initialization function for Log
		static void Init();
		//getters for logvars, related to core and client logger
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return ClientLogger; }
	
	private:
		static std::shared_ptr<spdlog::logger> CoreLogger;
		static std::shared_ptr<spdlog::logger> ClientLogger;
	};

} 

//Core log macros
#define CODDIS_CORE_TRACE(...)  ::CoddisEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CODDIS_CORE_INFO(...)	::CoddisEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CODDIS_CORE_WARN(...)	::CoddisEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CODDIS_CORE_ERROR(...)	::CoddisEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CODDIS_CORE_FATAL(...)	::CoddisEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define APP_CLIENT_TRACE(...)	::CoddisEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define APP_CLIENT_INFO(...)	::CoddisEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define APP_CLIENT_WARN(...)	::CoddisEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define APP_CLIENT_ERROR(...)	::CoddisEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define APP_CLIENT_FATAL(...)	::CoddisEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)
