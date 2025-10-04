#ifndef VALIDATION_H
#define VALIDATION_H

#include <stdexcept>

void validateLogin(const std::string& login);     // lança ExceptionLogin
void validatePassword(const std::string& pwd,
                      const std::string& username = ""); // lança ExceptionPassword

#endif