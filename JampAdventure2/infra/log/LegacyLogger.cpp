#include "LegacyLogger.h"

#include <ctime>

LegacyLogger::LegacyLogger(const std::string& filePath) : filePath_(filePath) {}

void LegacyLogger::writeLog(const std::string& severity, const std::string& message) {
    std::ofstream out(filePath_, std::ios::app);
    if (!out) return;

    auto now = std::chrono::system_clock::now();
    const std::time_t nowC = std::chrono::system_clock::to_time_t(now);
    std::tm tm{};
#ifdef _WIN32
    localtime_s(&tm, &nowC);
#else
    localtime_r(&nowC, &tm);
#endif

    out << std::put_time(&tm, "%Y-%m-%d %H:%M:%S")
        << " [" << severity << "] " << message << '\n';
}
