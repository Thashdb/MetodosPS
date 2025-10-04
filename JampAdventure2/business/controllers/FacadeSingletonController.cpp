#include "FacadeSingletonController.h"
#include "../command/ICommand.h"
#include "../report/ActivityHtmlReport.h"
#include "../report/ActivityTextReport.h"
#include "../../infra/log/ILogger.h"
#include <sstream>
#include <stdexcept>

FacadeSingletonController& FacadeSingletonController::instance() {
    static FacadeSingletonController inst;
    return inst;
}

void FacadeSingletonController::wire(IUserRepository* userRepo, ActivityRepository* activityRepo) {
    if (!userRepo || !activityRepo) throw std::invalid_argument("Repositorios nulos");
    userRepo_ = userRepo;
    activityRepo_ = activityRepo;

    userCtl_     = std::make_unique<UserController>(*userRepo_);
    activityCtl_ = std::make_unique<ActivityController>(*activityRepo_);
}

void FacadeSingletonController::setLogger(ILogger* logger) {
    logger_ = logger;
}

bool FacadeSingletonController::execute(ICommand& command) {
    if (!userCtl_ || !activityCtl_) throw std::runtime_error("Facade nao inicializada");
    const bool result = command.execute(*this);
    if (logger_) {
        std::ostringstream oss;
        oss << command.name() << (result ? " executado com sucesso" : " falhou");
        (result ? logger_->info(oss.str()) : logger_->warn(oss.str()));
    }
    return result;
}

std::string FacadeSingletonController::generateActivityReport(ReportFormat format) {
    if (!userCtl_ || !activityCtl_) throw std::runtime_error("Facade nao inicializada");

    std::unique_ptr<ActivityReportTemplate> report;
    switch (format) {
        case ReportFormat::Html:
            report = std::make_unique<ActivityHtmlReport>();
            break;
        case ReportFormat::Text:
            report = std::make_unique<ActivityTextReport>();
            break;
        default:
            throw std::invalid_argument("Formato de relatorio nao suportado");
    }

    const auto& users = userCtl_->listAll();
    const auto& activities = activityCtl_->listAll();
    const std::string output = report->generate(users, activities);

    if (logger_) {
        logger_->info("Relatorio de atividades gerado");
    }

    return output;
}

UserController& FacadeSingletonController::user() {
    if (!userCtl_) throw std::runtime_error("Facade nao inicializada");
    return *userCtl_;
}

ActivityController& FacadeSingletonController::activity() {
    if (!activityCtl_) throw std::runtime_error("Facade nao inicializada");
    return *activityCtl_;
}

size_t FacadeSingletonController::countEntities() const {
    if (!userCtl_ || !activityCtl_) throw std::runtime_error("Facade nao inicializada");
    const auto& users = userCtl_->listAll();
    const auto& acts  = activityCtl_->listAll();
    return users.size() + acts.size();
}
