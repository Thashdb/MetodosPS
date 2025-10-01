#include "../../include/documentos/rg.hpp"
#include "../../include/core/campo.hpp"

RG::RG(string numero, string orgao) : Secao("RG") {
    addNew<Campo>("Numero", move(numero));
    addNew<Campo>("Orgao Emissor", move(orgao));
}