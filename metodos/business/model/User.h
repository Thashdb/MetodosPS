#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string username;
    std::string password;
public:
    User(std::string u = "", std::string p = "") : username(u), password(p) {}

    std::string getUsername() const { return username; }
    std::string getPassword() const { return password; }
};

#endif
