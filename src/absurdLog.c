#include <stdio.h>
#include "absurdLog.h"

/**
 * @brief Array of string names for each log level.
 */
static const char* _apszLogLevelNames[] = {
    "DEBUG",
    "INFO",
    "WARN",
    "ERROR",
    "FATAL"
};

/**
 * @brief Logs a message with a level prefix.
 *
 * @param _elvlLevel Log level enum value.
 * @param _pszMessage Null-terminated message string.
 */
void _AbsurdLog_LogMessage(_elLogLevel _elvlLevel, const char* _pszMessage) {
    if (_pszMessage == NULL) {
        _pszMessage = "(null)";
    }

    if (_elvlLevel < _elLog_DEBUG || _elvlLevel > _elLog_FATAL) {
        // Invalid log level, fallback to INFO
        _elvlLevel = _elLog_INFO;
    }

    FILE* output = (_elvlLevel >= _elLog_WARN) ? stderr : stdout;
    fprintf(output, "[AbsurdLog::%s] %s\n", _apszLogLevelNames[_elvlLevel], _pszMessage);
}