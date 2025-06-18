#ifndef ABSURD_LOG_H
#define ABSURD_LOG_H

/**
 * @brief Enum representing log levels with Hungarian notation.
 */
typedef enum _elLogLevel {
    _elLog_DEBUG,   /**< Debug level */
    _elLog_INFO,    /**< Informational level */
    _elLog_WARN,    /**< Warning level */
    _elLog_ERROR,   /**< Error level */
    _elLog_FATAL    /**< Fatal error level */
} _elLogLevel;

// Compile-time check to ensure enum count matches array size
_Static_assert(sizeof(_apszLogLevelNames) / sizeof(_apszLogLevelNames[0]) == _elLog_COUNT,
               "_apszLogLevelNames must match _elLogLevel enum count");

/**
 * @brief Logs a message with the given log level.
 *
 * @param _elvlLevel Log level of the message.
 * @param _pszMessage Null-terminated string message to log.
 */
void _AbsurdLog_LogMessage(_elLogLevel _elvlLevel, const char* _pszMessage);

#endif // ABSURD_LOG_H