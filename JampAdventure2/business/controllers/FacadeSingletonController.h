#ifndef FACADE_SINGLETON_CONTROLLER_H
#define FACADE_SINGLETON_CONTROLLER_H

#include "UserController.h"
#include "ActivityController.h"
#include "../report/ReportFormat.h"
#include "../observer/NotificationCenter.h"
#include "../observer/UserNotificationObserver.h"
#include "../observer/LoggerNotificationObserver.h"
#include "../../data/IUserRepository.h"
#include "../../data/ActivityRepository.h"
#include <memory>
#include <string>
#include <vector>

class ICommand;
class ILogger;

// Singleton + Facade: expõe uma "porta" única para os gerentes
class FacadeSingletonController {
public:
    static FacadeSingletonController& instance();

    // Injeta os repos e constrói os controllers (chamar uma vez no início)
    void wire(IUserRepository* userRepo, ActivityRepository* activityRepo);
    void setLogger(ILogger* logger);

    bool execute(ICommand& command);

    std::string generateActivityReport(ReportFormat format);

    NotificationCenter& notifications();
    std::vector<std::string> consumeNotifications(const std::string& username);

    // Acesso aos controllers
    UserController& user();
    ActivityController& activity();

    // Total de ENTIDADES (usuários + atividades)
    size_t countEntities() const;

private:
    FacadeSingletonController() = default;
    FacadeSingletonController(const FacadeSingletonController&) = delete;
    FacadeSingletonController& operator=(const FacadeSingletonController&) = delete;

    IUserRepository* userRepo_{nullptr};
    ActivityRepository* activityRepo_{nullptr};

    // alocados após wire()
    std::unique_ptr<UserController> userCtl_;
    std::unique_ptr<ActivityController> activityCtl_;

    ILogger* logger_{nullptr};

    NotificationCenter notificationCenter_;
    std::unique_ptr<UserNotificationObserver> userNotificationObserver_;
    std::unique_ptr<LoggerNotificationObserver> loggerNotificationObserver_;
};

#endif