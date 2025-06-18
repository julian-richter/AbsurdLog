#include "absurdLog.h"

int main(void) {
    // Log a debug message
    _AbsurdLog_LogMessage(_elLog_DEBUG, "This is a debug message.");

    // Log an info message
    _AbsurdLog_LogMessage(_elLog_INFO, "This is an info message.");

    // Log a warning message
    _AbsurdLog_LogMessage(_elLog_WARN, "This is a warning message.");

    // Log an error message
    _AbsurdLog_LogMessage(_elLog_ERROR, "This is an error message.");

    // Log a fatal error message
    _AbsurdLog_LogMessage(_elLog_FATAL, "This is a fatal error message.");

    return 0;
}