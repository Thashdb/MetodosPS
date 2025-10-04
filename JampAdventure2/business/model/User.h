#ifndef USER_H
#define USER_H

#include <string>

enum class UserRole { Common, Instructor };

struct User {
    int id{};       //sequencial
    std::string username;
    std::string password;

    UserRole role{UserRole::Common};
};


#endif