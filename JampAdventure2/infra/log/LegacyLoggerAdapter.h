#ifndef LEGACY_LOGGER_ADAPTER_H
#define LEGACY_LOGGER_ADAPTER_H

#include "ILogger.h"
#include "LegacyLogger.h"

class LegacyLoggerAdapter : public ILogger {
public:
    explicit LegacyLoggerAdapter(LegacyLogger& legacy) : legacy_(legacy) {}

    void info(const std::string& message) override {
        legacy_.writeLog("INFO", message);
    }

    void warn(const std::string& message) override {
        legacy_.writeLog("WARN", message);
    }

    void error(const std::string& message) override {
        legacy_.writeLog("ERROR", message);
    }

private:
    LegacyLogger& legacy_;
};

#endif
