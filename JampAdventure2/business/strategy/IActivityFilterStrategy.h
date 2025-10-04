#ifndef I_ACTIVITY_FILTER_STRATEGY_H
#define I_ACTIVITY_FILTER_STRATEGY_H

#include <string>
#include <vector>
#include "../model/Activity.h"

class IActivityFilterStrategy {
public:
    virtual ~IActivityFilterStrategy() = default;
    virtual std::vector<Activity> filter(const std::vector<Activity>& activities) const = 0;
    virtual std::string description() const = 0;
};

#endif
