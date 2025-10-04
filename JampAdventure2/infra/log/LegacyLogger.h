#ifndef LEGACY_LOGGER_H
#define LEGACY_LOGGER_H

#include <string>
#include <fstream>
#include <chrono>
#include <iomanip>

// Simula uma biblioteca de log preexistente com interface própria
class LegacyLogger {
public:
    explicit LegacyLogger(const std::string& filePath);
    void writeLog(const std::string& severity, const std::string& message);

private:
    std::string filePath_;
};

#endif
