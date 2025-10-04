#ifndef NOTIFICATION_CENTER_H
#define NOTIFICATION_CENTER_H

#include <algorithm>
#include <string>
#include <vector>

struct NotificationEvent {
    std::string username;
    std::string message;
};

class INotificationObserver {
public:
    virtual ~INotificationObserver() = default;
    virtual void update(const NotificationEvent& event) = 0;
};

class NotificationCenter {
public:
    void attach(INotificationObserver* observer) {
        if (!observer) return;
        if (std::find(observers_.begin(), observers_.end(), observer) == observers_.end()) {
            observers_.push_back(observer);
        }
    }

    void detach(INotificationObserver* observer) {
        observers_.erase(std::remove(observers_.begin(), observers_.end(), observer), observers_.end());
    }

    void notify(const NotificationEvent& event) const {
        for (auto* observer : observers_) {
            if (observer) {
                observer->update(event);
            }
        }
    }

private:
    std::vector<INotificationObserver*> observers_;
};

#endif
