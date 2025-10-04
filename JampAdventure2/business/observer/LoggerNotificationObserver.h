#ifndef LOGGER_NOTIFICATION_OBSERVER_H
#define LOGGER_NOTIFICATION_OBSERVER_H

#include "NotificationCenter.h"
#include "../../infra/log/ILogger.h"

class LoggerNotificationObserver : public INotificationObserver {
public:
    explicit LoggerNotificationObserver(ILogger* logger = nullptr) : logger_(logger) {}

    void setLogger(ILogger* logger) { logger_ = logger; }

    void update(const NotificationEvent& event) override {
        if (!logger_) return;
        logger_->info("Notificacao para " + event.username + ": " + event.message);
    }

private:
    ILogger* logger_;
};

#endif
