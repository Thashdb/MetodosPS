#ifndef USER_CONTROLLER_H
#define USER_CONTROLLER_H

#include <vector>
#include <string>
#include "../../data/IUserRepository.h"
#include "../model/User.h"

class UserController {
public:
    explicit UserController(IUserRepository& repo);

    // Lab2
    bool addUser(std::string username, std::string password); // legado, se quiser manter
    const std::vector<User>& listAll() const;

    //(Lab3)
    bool registerUser(std::string username, std::string password, UserRole role); // cadastro com role
        // retorna ponteiro para o usuário autenticado (ou nullptr se falhar)
    const User* login(const std::string& username, const std::string& password) const;

private:
    IUserRepository& repo_;
};

#endif