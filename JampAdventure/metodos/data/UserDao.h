#ifndef USER_DAO_H
#define USER_DAO_H

#include <iostream>

class UserDao {
public:
    void persist() { std::cout << "Usuario salvo no banco" << std::endl; }
};

#endif
