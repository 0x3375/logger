#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <stdarg.h>

#if defined _DEBUG
#define ENABLE_LOG
#endif

#ifdef ENABLE_LOG 
#define LOG(...) Logger::instance()->log((strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__), __LINE__, (strrchr(__FUNCTION__, '::') ? strrchr(__FUNCTION__, '::') + 1 : __FUNCTION__), __VA_ARGS__)
#else
#define LOG
#endif

class Logger {
public:
	static Logger* instance();
	void log(const char* file, int line, const char* func, const char* str, ...);
private:
	Logger();
	static Logger* _instance;
};
#endif