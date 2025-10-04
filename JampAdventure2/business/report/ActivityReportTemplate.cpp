#include "ActivityReportTemplate.h"

#include <numeric>
#include <sstream>

std::string ActivityReportTemplate::generate(const std::vector<User>& users,
                                             const std::vector<Activity>& activities) const {
    const auto stats = buildStats(users, activities);
    std::ostringstream out;
    out << renderHeader(stats);
    if (!activities.empty()) {
        out << separator();
        for (std::size_t i = 0; i < activities.size(); ++i) {
            out << renderActivity(activities[i], i);
            if (i + 1 < activities.size()) {
                out << separator();
            }
        }
        out << separator();
    }
    out << renderFooter(stats);
    return out.str();
}

ActivityReportTemplate::UsageStats ActivityReportTemplate::buildStats(
    const std::vector<User>& users,
    const std::vector<Activity>& activities) const {

    UsageStats stats;
    stats.totalUsers = users.size();
    for (const auto& user : users) {
        if (user.role == UserRole::Instructor) ++stats.totalInstructors;
        else ++stats.totalStudents;
    }

    stats.totalActivities = activities.size();
    stats.totalEnrollments = std::accumulate(activities.begin(), activities.end(), std::size_t{0},
        [](std::size_t acc, const Activity& activity) {
            return acc + activity.participants.size();
        });

    return stats;
}
