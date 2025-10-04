#include "UserController.h"
#include "../service/Validation.h"

UserController::UserController(IUserRepository& repo) : repo_(repo) {}

bool UserController::addUser(std::string username, std::string password) {
    validateLogin(username);
    validatePassword(password, username);
    User u{ repo_.nextId(), std::move(username), std::move(password), UserRole::Common };
    return repo_.addUser(u);
}

const std::vector<User>& UserController::listAll() const {
    return repo_.listAll();
}

bool UserController::registerUser(std::string username, std::string password, UserRole role) {
    validateLogin(username);
    validatePassword(password, username);
    // opcional: checar duplicidade de username
    if (repo_.findByUsername(username) != nullptr) return false;
    User u{ repo_.nextId(), std::move(username), std::move(password), role };
    return repo_.addUser(u);
}

const User* UserController::login(const std::string& username, const std::string& password) const {
    const User* u = repo_.findByUsername(username);
    if (!u) return nullptr;
    return (u->password == password) ? u : nullptr;
}