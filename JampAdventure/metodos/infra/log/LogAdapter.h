#ifndef LOGADAPTER_H
#define LOGADAPTER_H
#include "Logger.h"
#include <spdlog/spdlog.h>

class LogAdapter : public Logger {
public:
    void logInfo(const std::string& message) override {
        spdlog::info(message);
    }
    void logError(const std::string& message) override {
        spdlog::error(message);
    }
};

#endif