#include "ActivityController.h"
#include "../memento/ActivityMemento.h"

#include <utility>

ActivityController::ActivityController(ActivityRepository& repo) : repo_(repo) {}

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
    return repo_.add(a);
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
    }
    return ok;
}

bool ActivityController::erase(int id, std::string instructorUsername) {
    // (Opcional: checar se id pertence ao instrutor)
    (void)instructorUsername;
    return repo_.remove(id);
}

const std::vector<Activity>& ActivityController::listAll() const {
    return repo_.listAll();
}

size_t ActivityController::count() const {
    return repo_.count();
}

bool ActivityController::enrollUser(int activityId, std::string username, UserRole role) {
    if (role != UserRole::Common) return false; // somente usuários comuns se inscrevem
    if (username.empty()) return false;
    return repo_.enroll(activityId, username);
}

bool ActivityController::undoLastUpdate() {
    if (!caretaker_.hasSnapshot()) return false;
    const ActivityMemento* snapshot = caretaker_.peek();
    if (!snapshot) return false;
    const bool restored = repo_.restore(snapshot->state());
    if (restored) caretaker_.clear();
    return restored;
}
