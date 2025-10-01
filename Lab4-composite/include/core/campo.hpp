#ifndef CAMPO_HPP
#define CAMPO_HPP

#include "componenteCadastro.hpp"
#include <string>

//Campo é a folha (leaf): guarda um par nome: valor e não tem filhos.
class Campo : public componenteCadastro{
    string m_nome;
    string m_valor;

    public:
        Campo(string nome, string valor) : 
        m_nome(move(nome)), m_valor(move(valor)) {}
        
        const string& nome() const override{
            return m_nome;
        }

    protected:
        void exibirInterno (ostringstream& oss, int indent) const override {
            identar (oss, indent);
            oss << "- " << m_nome << ": " << m_valor << "\n";
        }

};


#endif // CAMPO_HPP