#ifndef CATEGORY_FILTER_STRATEGY_H
#define CATEGORY_FILTER_STRATEGY_H

#include "IActivityFilterStrategy.h"
#include <algorithm>
#include <cctype>

class CategoryFilterStrategy : public IActivityFilterStrategy {
public:
    explicit CategoryFilterStrategy(std::string category)
        : category_(std::move(category)) {}

    std::vector<Activity> filter(const std::vector<Activity>& activities) const override {
        std::vector<Activity> result;
        const auto needle = toLower(category_);
        for (const auto& activity : activities) {
            if (toLower(activity.category).find(needle) != std::string::npos) {
                result.push_back(activity);
            }
        }
        return result;
    }

    std::string description() const override {
        return "categoria";
    }

private:
    std::string category_;

    static std::string toLower(std::string value) {
        std::transform(value.begin(), value.end(), value.begin(), [](unsigned char c) {
            return static_cast<char>(std::tolower(c));
        });
        return value;
    }
};

#endif
