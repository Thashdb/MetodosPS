#include <iostream>
#include <memory>

//core
#include "include/core/campo.hpp"
#include "include/core/secao.hpp"
#include "include/core/componenteCadastro.hpp"

//colaborador
#include "include/colaborador/colaborador.hpp"

//pessoais
#include "include/dadosPessoais/dadosPessoais.hpp"
#include "include/dadosPessoais/contatos.hpp"
#include "include/dadosPessoais/dependentes.hpp"

//admissionais
#include "include/admissional/dodosAdmissionais.hpp"

//endereco
#include "include/endereco/endereco.hpp"
#include "include/endereco/residencial.hpp"
#include "include/endereco/comercial.hpp"

//documentos
#include "include/documentos/documentos.hpp"
#include "include/documentos/cpf.hpp"
#include "include/documentos/rg.hpp"

int main(){
        auto cadastro = make_unique<Colaborador>("Jose Bezerra");

        // Dados Pessoais

        auto dadosPessoais = make_unique<DadosPessoais>();

        auto contatos = make_unique<Contatos>();
        contatos->addNew<Campo>("E-mail", "jose.bzr@example.com")
                .addNew<Campo>("Telefone", "(83) 99999-9999");

        //dependentes
        auto dependentes = make_unique<Dependentes>();

        auto dep1 = make_unique<Secao>("Dependente: Rapunzel");
        dep1->addNew<Campo>("Parentesco", "Esposa")
                .addNew<Campo>("Data de Nascimento", "05-06-1993");

        auto dep2 = make_unique<Secao>("Dependente: Ana");
        dep2->addNew<Campo>("Parentesco", "Filha")
                .addNew<Campo>("Data de Nascimento", "01-08-2019");

        dependentes->add(move(dep1))
                .add(move(dep2));

        dadosPessoais->add(move(contatos))
                .add(move(dependentes));

        //admissionais
        auto dadosAdm = make_unique<DadosAdmissionais>();
        dadosAdm->addNew<Campo>("Cargo", "Desenvolvedor Pleno")
                .addNew<Campo>("Data de Admissao", "01-08-2024")
                .addNew<Campo>("Salario", "R$ 8.000,00");

        // Endereço
        auto endereco = make_unique<Endereco>();
        auto residencial = make_unique<Residencial>();
        residencial->addNew<Campo>("Logradouro", "Rua X, 123")
                        .addNew<Campo>("Cidade", "Joao Pessoa")
                        .addNew<Campo>("UF", "PB");
        auto comercial = make_unique<Comercial>();
        comercial->addNew<Campo>("Logradouro", "Av. Y, 999")
                .addNew<Campo>("Cidade", "Joao Pessoa")
                .addNew<Campo>("UF", "PB");
        endereco->add(move(residencial)).add(move(comercial));

        // Documentos
        auto documentos = make_unique<Documentos>();
        documentos->add(make_unique<RG>("12.345.678-9", "SSP-PB"))
                        .add(make_unique<CPF>("123.456.789-00"));

        // Monta cadastro
        cadastro->add(std::move(dadosPessoais))
                .add(std::move(dadosAdm))
                .add(std::move(endereco))
                .add(std::move(documentos));

        cout << "\n--- Cadastro inicial ---\n" << cadastro->exibir();

        cout << "\n--- Fim ---\n";
        return 0;
}