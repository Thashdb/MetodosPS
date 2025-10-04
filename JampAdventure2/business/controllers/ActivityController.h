#ifndef ACTIVITY_CONTROLLER_H
#define ACTIVITY_CONTROLLER_H

#include "../../data/ActivityRepository.h"
#include "../model/Activity.h"
#include "../model/User.h"
#include "../memento/ActivityCaretaker.h"

#include <vector>
#include <string>

class NotificationCenter;
class IActivityFilterStrategy;

class ActivityController {
    public:
    explicit ActivityController(ActivityRepository& repo, NotificationCenter* notifier = nullptr);

    void setNotificationCenter(NotificationCenter* notifier);

        // CRUD da atividade (instrutor)
        bool create(std::string name, std::string date, std::string time,
                    std::string category, std::string instructorUsername);
        bool update(int id, std::string name, std::string date, std::string time,
                    std::string category, std::string instructorUsername);
        bool erase(int id, std::string instructorUsername);

        // Leitura
        const std::vector<Activity>& listAll() const;
    std::vector<Activity> filter(const IActivityFilterStrategy& strategy) const;
        size_t count() const;

        // Inscrição (usuário comum)
        bool enrollUser(int activityId, std::string username, UserRole role);

        // Memento - desfaz a última atualização
        bool undoLastUpdate();

    private:
        ActivityRepository& repo_;
        ActivityCaretaker caretaker_;
        NotificationCenter* notifier_{};

        void notifyUser(const std::string& username, const std::string& message) const;
        void notifyParticipants(const std::vector<std::string>& participants, const std::string& message) const;
};
#endif