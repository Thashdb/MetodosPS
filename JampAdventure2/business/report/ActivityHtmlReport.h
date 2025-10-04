#ifndef ACTIVITY_HTML_REPORT_H
#define ACTIVITY_HTML_REPORT_H

#include "ActivityReportTemplate.h"

class ActivityHtmlReport : public ActivityReportTemplate {
protected:
    std::string renderHeader(const UsageStats& stats) const override;
    std::string renderActivity(const Activity& activity, std::size_t index) const override;
    std::string renderFooter(const UsageStats& stats) const override;
    std::string separator() const override;
};

#endif
