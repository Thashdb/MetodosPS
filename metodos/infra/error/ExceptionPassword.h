#ifndef EXCEPTION_PASSWORD_H
#define EXCEPTION_PASSWORD_H

#include <stdexcept>

class ExceptionPassword : public std::runtime_error {
public:
    ExceptionPassword() : std::runtime_error("Senha incorreta!") {}
};

#endif
