#pragma once

#include <iostream>

namespace Helio
{
	enum class Severity
	{
		E_Trace = 0,
		E_Info,
		E_Warn,
		E_Error
	};

	class Log
	{
	public:
		static Severity severityLevel;
		
		static void SetSeverityLevel(Severity level)
		{
			severityLevel = level;
		}

		template <typename T>
		static void Trace(T mess)
		{
			if (Severity::E_Trace >= severityLevel)
				std::cout << "[TRACE]: " << mess << "\n";
		}

		template <typename T>
		static void Info(T mess)
		{
			if (Severity::E_Info >= severityLevel)
				std::cout << "[INFO]: " << mess << "\n";
		}

		template <typename T>
		static void Warn(T mess)
		{
			if (Severity::E_Warn >= severityLevel)
				std::cout << "[WARN]: " << mess << "\n";
		}

		template <typename T>
		static void Error(T mess)
		{
			if (Severity::E_Error >= severityLevel)
				std::cout << "[ERROR]: " << mess << "\n";
		}
	};
	Severity Log::severityLevel = Severity::E_Trace;
};

#define __DEBUG__ 1

#if __DEBUG__

#define LOG_TRACE(x)	Helio::Log::Trace(x)
#define LOG_INFO(x)		Helio::Log::Info(x)
#define LOG_WARN(x)		Helio::Log::Warn(x)
#define LOG_ERROR(x)	Helio::Log::Error(x)

#else

#define LOG_TRACE(x) 
#define LOG_INFO(x) 
#define LOG_WARN(x) 
#define LOG_ERROR(x) 

#endif