#pragma once

#include "Base.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Lightning {
	class LN_API Log {
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return clientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};
}

#define LN_CORE_FATAL(...) ::Lightning::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define LN_CORE_ERROR(...) ::Lightning::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LN_CORE_WARN(...) ::Lightning::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LN_CORE_INFO(...) ::Lightning::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LN_CORE_TRACE(...) ::Lightning::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define LN_FATAL(...) ::Lightning::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define LN_ERROR(...) ::Lightning::Log::GetClientLogger()->error(__VA_ARGS__)
#define LN_WARN(...) ::Lightning::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LN_INFO(...) ::Lightning::Log::GetClientLogger()->info(__VA_ARGS__)
#define LN_TRACE(...) ::Lightning::Log::GetClientLogger()->trace(__VA_ARGS__)