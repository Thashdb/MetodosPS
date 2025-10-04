#ifndef ACTIVITY_REPORT_TEMPLATE_H
#define ACTIVITY_REPORT_TEMPLATE_H

#include "../model/User.h"
#include "../model/Activity.h"

#include <cstddef>
#include <string>
#include <vector>

class ActivityReportTemplate {
public:
    virtual ~ActivityReportTemplate() = default;

    std::string generate(const std::vector<User>& users,
                         const std::vector<Activity>& activities) const;

protected:
    struct UsageStats {
        std::size_t totalUsers{};
        std::size_t totalInstructors{};
        std::size_t totalStudents{};
        std::size_t totalActivities{};
        std::size_t totalEnrollments{};
    };

    UsageStats buildStats(const std::vector<User>& users,
                          const std::vector<Activity>& activities) const;

    virtual std::string renderHeader(const UsageStats& stats) const = 0;
    virtual std::string renderActivity(const Activity& activity, std::size_t index) const = 0;
    virtual std::string renderFooter(const UsageStats& stats) const = 0;
    virtual std::string separator() const = 0;
};

#endif
