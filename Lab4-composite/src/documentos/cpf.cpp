#include "../../include/documentos/cpf.hpp"
#include "../../include/core/campo.hpp"

CPF::CPF(std::string numero) : Secao("CPF"){
    addNew<Campo>("Numero", move(numero));
}