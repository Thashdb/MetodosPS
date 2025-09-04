#ifndef EXCEPTION_LOGIN_H
#define EXCEPTION_LOGIN_H

#include <stdexcept>

class ExceptionLogin : public std::runtime_error {
public:
    ExceptionLogin() : std::runtime_error("Erro de Login!") {}
};

#endif
