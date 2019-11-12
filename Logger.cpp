#include "Logger.h"

#pragma warning(disable:4996)

#define LOG_PATH "C:/myUnity/timelog/LFDebugLog.txt"

Logger* Logger::_instance;
Logger::Logger() {
	fclose(stdout);
	freopen(LOG_PATH, "a", stdout);
}

Logger* Logger::instance() {
	if (!_instance) {
		_instance = new Logger();
	}
	return _instance;
}

void Logger::log(const char* file, int line, const char* func, const char* str, ...) {
	va_list args;
	fprintf(stdout, "[%s:%d-%s] ", file, line, func);
	va_start(args, str);
	vprintf(str, args);
	va_end(args);
	fflush(stdout);
}