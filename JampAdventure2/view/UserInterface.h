#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "../business/controllers/UserController.h"

#include <iostream>

class UserInterface {
public:
    explicit UserInterface(UserController& ctl);
    void menu();

private:
    static void limpaEntrada();
    void criarUsuario();
    void listarUsuarios() const;

    UserController& ctl_;
};

#endif
