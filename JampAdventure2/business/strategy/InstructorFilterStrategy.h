#ifndef INSTRUCTOR_FILTER_STRATEGY_H
#define INSTRUCTOR_FILTER_STRATEGY_H

#include "IActivityFilterStrategy.h"
#include <algorithm>
#include <cctype>

class InstructorFilterStrategy : public IActivityFilterStrategy {
public:
    explicit InstructorFilterStrategy(std::string instructor)
        : instructor_(std::move(instructor)) {}

    std::vector<Activity> filter(const std::vector<Activity>& activities) const override {
        std::vector<Activity> result;
        const auto needle = toLower(instructor_);
        for (const auto& activity : activities) {
            if (toLower(activity.instructorUsername).find(needle) != std::string::npos) {
                result.push_back(activity);
            }
        }
        return result;
    }

    std::string description() const override {
        return "instrutor";
    }

private:
    std::string instructor_;

    static std::string toLower(std::string value) {
        std::transform(value.begin(), value.end(), value.begin(), [](unsigned char c) {
            return static_cast<char>(std::tolower(c));
        });
        return value;
    }
};

#endif
