#ifndef EXCEPTION_LOGIN_H
#define EXCEPTION_LOGIN_H

#include <stdexcept>

struct ExceptionLogin : std::runtime_error {
    using std::runtime_error::runtime_error;
};

#endif
