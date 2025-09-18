#ifndef LOGGER_H
#define LOGGER_H
#include <string>

class Logger {
public:
    virtual ~Logger() = default;
    virtual void logInfo(const std::string& message) = 0;
    virtual void logError(const std::string& message) = 0;
};
#endif