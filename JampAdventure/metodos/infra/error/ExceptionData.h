#ifndef EXCEPTION_DATA_H
#define EXCEPTION_DATA_H

#include <stdexcept>

class ExceptionData : public std::runtime_error {
public:
    ExceptionData() : std::runtime_error("Erro de Dados!") {}
};

#endif
