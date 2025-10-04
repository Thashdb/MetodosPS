#ifndef EXCEPTION_PASSWORD_H
#define EXCEPTION_PASSWORD_H

#include <stdexcept>

struct ExceptionPassword : std::runtime_error {
    using std::runtime_error::runtime_error;
};

#endif