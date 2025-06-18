#include <stdio.h>
#include <unistd.h> // For isatty()
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
 * @brief Array of ANSI color codes for each log level.
 */
static const char* _apszLogLevelColors[] = {
    "\x1b[95m", // DEBUG (Bright Magenta for "neon pink")
    "\x1b[34m", // INFO (Blue)
    "\x1b[33m", // WARN (Yellow)
    "\x1b[31m", // ERROR (Red)
    "\x1b[4;31m"// FATAL (Underlined Red)
};

// Compile-time check to ensure enum count matches array size
_Static_assert(sizeof(_apszLogLevelNames) / sizeof(_apszLogLevelNames[0]) == _elLog_COUNT,
               "_apszLogLevelNames must match _elLogLevel enum count");
_Static_assert(sizeof(_apszLogLevelColors) / sizeof(_apszLogLevelColors[0]) == _elLog_COUNT,
               "_apszLogLevelColors must match _elLogLevel enum count");

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

    if (_elvlLevel < _elLog_DEBUG || _elvlLevel >= _elLog_COUNT) {
        // Invalid log level, fallback to INFO
        _elvlLevel = _elLog_INFO;
    }

    FILE* output = (_elvlLevel >= _elLog_WARN) ? stderr : stdout;

    // Only use color codes if the output is a terminal
    if (isatty(fileno(output))) {
        fprintf(output, "%s[AbsurdLog::%s] %s\x1b[0m\n", _apszLogLevelColors[_elvlLevel], _apszLogLevelNames[_elvlLevel], _pszMessage);
    } else {
        fprintf(output, "[AbsurdLog::%s] %s\n", _apszLogLevelNames[_elvlLevel], _pszMessage);
    }
}