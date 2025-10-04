#include "ActivityController.h"
#include "../memento/ActivityMemento.h"
#include "../observer/NotificationCenter.h"
#include "../strategy/IActivityFilterStrategy.h"

#include <sstream>
#include <utility>

ActivityController::ActivityController(ActivityRepository& repo, NotificationCenter* notifier)
    : repo_(repo), notifier_(notifier) {}

void ActivityController::setNotificationCenter(NotificationCenter* notifier) {
    notifier_ = notifier;
}

bool ActivityController::create(std::string name, std::string date, std::string time,
                                std::string category, std::string instructorUsername) {
    // Simples checagens mínimas (Lab 3 foca no CRUD/fluxo)
    if (name.empty() || date.empty() || time.empty() || category.empty() || instructorUsername.empty())
        return false;
    Activity a;
    a.id = repo_.nextId();
    a.name = std::move(name);
    a.date = std::move(date);
    a.time = std::move(time);
    a.category = std::move(category);
    a.instructorUsername = std::move(instructorUsername);
    const bool created = repo_.add(a);
    if (created) {
        std::ostringstream oss;
        oss << "Atividade '" << a.name << "' criada com sucesso.";
        notifyUser(a.instructorUsername, oss.str());
    }
    return created;
}

bool ActivityController::update(int id, std::string name, std::string date, std::string time,
                                std::string category, std::string instructorUsername) {
    const Activity* current = repo_.findById(id);
    if (!current) return false;

    Activity previous = *current; // snapshot antes da atualização
    Activity updated = previous;
    updated.name = std::move(name);
    updated.date = std::move(date);
    updated.time = std::move(time);
    updated.category = std::move(category);
    updated.instructorUsername = std::move(instructorUsername);

    const bool ok = repo_.update(id, updated);
    if (ok) {
        caretaker_.save(ActivityMemento(std::move(previous)));
        std::ostringstream oss;
        oss << "Atividade '" << updated.name << "' foi atualizada.";
        notifyParticipants(updated.participants, oss.str());
        notifyUser(updated.instructorUsername, oss.str());
    }
    return ok;
}

bool ActivityController::erase(int id, std::string instructorUsername) {
    const Activity* existing = repo_.findById(id);
    if (!existing) return false;

    Activity snapshot = *existing;
    (void)instructorUsername; // poderia validar se pertence ao instrutor

    const bool removed = repo_.remove(id);
    if (removed) {
        std::ostringstream oss;
        oss << "Atividade '" << snapshot.name << "' foi cancelada.";
        notifyParticipants(snapshot.participants, oss.str());
        notifyUser(snapshot.instructorUsername, "Atividade removida com sucesso.");
    }
    return removed;
}

const std::vector<Activity>& ActivityController::listAll() const {
    return repo_.listAll();
}

std::vector<Activity> ActivityController::filter(const IActivityFilterStrategy& strategy) const {
    return strategy.filter(repo_.listAll());
}

size_t ActivityController::count() const {
    return repo_.count();
}

bool ActivityController::enrollUser(int activityId, std::string username, UserRole role) {
    if (role != UserRole::Common) return false; // somente usuários comuns se inscrevem
    if (username.empty()) return false;
    const bool enrolled = repo_.enroll(activityId, username);
    if (enrolled) {
        const Activity* activity = repo_.findById(activityId);
        if (activity) {
            std::ostringstream oss;
            oss << "Sua inscricao na atividade '" << activity->name << "' foi confirmada.";
            notifyUser(username, oss.str());
            notifyUser(activity->instructorUsername, "Novo participante inscrito: " + username + ".");
        } else {
            notifyUser(username, "Inscricao realizada.");
        }
    }
    return enrolled;
}

bool ActivityController::undoLastUpdate() {
    if (!caretaker_.hasSnapshot()) return false;
    const ActivityMemento* snapshot = caretaker_.peek();
    if (!snapshot) return false;
    Activity restoredState = snapshot->state();
    const bool restored = repo_.restore(restoredState);
    if (restored) {
        caretaker_.clear();
        std::ostringstream oss;
        oss << "Alteracoes na atividade '" << restoredState.name << "' foram revertidas.";
        notifyParticipants(restoredState.participants, oss.str());
        notifyUser(restoredState.instructorUsername, oss.str());
    }
    return restored;
}

void ActivityController::notifyUser(const std::string& username, const std::string& message) const {
    if (!notifier_ || username.empty() || message.empty()) return;
    notifier_->notify(NotificationEvent{username, message});
}

void ActivityController::notifyParticipants(const std::vector<std::string>& participants,
                                            const std::string& message) const {
    if (!notifier_ || message.empty()) return;
    for (const auto& participant : participants) {
        if (!participant.empty()) {
            notifier_->notify(NotificationEvent{participant, message});
        }
    }
}
