#ifndef DATE_FILTER_STRATEGY_H
#define DATE_FILTER_STRATEGY_H

#include "IActivityFilterStrategy.h"
#include <algorithm>
#include <cctype>

class DateFilterStrategy : public IActivityFilterStrategy {
public:
    explicit DateFilterStrategy(std::string date)
        : date_(std::move(date)) {}

    std::vector<Activity> filter(const std::vector<Activity>& activities) const override {
        std::vector<Activity> result;
        const auto needle = toLower(date_);
        for (const auto& activity : activities) {
            if (toLower(activity.date).find(needle) != std::string::npos) {
                result.push_back(activity);
            }
        }
        return result;
    }

    std::string description() const override {
        return "data";
    }

private:
    std::string date_;

    static std::string toLower(std::string value) {
        std::transform(value.begin(), value.end(), value.begin(), [](unsigned char c) {
            return static_cast<char>(std::tolower(c));
        });
        return value;
    }
};

#endif
