#ifndef USER_NOTIFICATION_OBSERVER_H
#define USER_NOTIFICATION_OBSERVER_H

#include "NotificationCenter.h"
#include <string>
#include <unordered_map>
#include <vector>

class UserNotificationObserver : public INotificationObserver {
public:
    void update(const NotificationEvent& event) override {
        if (event.username.empty()) return;
        inbox_[event.username].push_back(event.message);
    }

    std::vector<std::string> consume(const std::string& username) {
        auto it = inbox_.find(username);
        if (it == inbox_.end()) {
            return {};
        }
        auto messages = std::move(it->second);
        inbox_.erase(it);
        return messages;
    }

    bool empty() const noexcept { return inbox_.empty(); }

private:
    std::unordered_map<std::string, std::vector<std::string>> inbox_;
};

#endif
