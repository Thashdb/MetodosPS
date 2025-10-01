#include "../../include/core/secao.hpp"
#include <algorithm>

Secao::Secao(string nome) : m_nome(move(nome)){}

Secao& Secao::add(unique_ptr<componenteCadastro> filho){
    m_filhos.push_back(move(filho));
    return *this;
}

const string& Secao::nome() const{
    return m_nome;
}

void Secao::adicionar(unique_ptr<componenteCadastro> filho){
    add(move(filho));
}

bool Secao::removerPorNome(const string& nome){
    auto oldSize = m_filhos.size();
    m_filhos.erase(remove_if(m_filhos.begin(), m_filhos.end(),
        [&](const unique_ptr<componenteCadastro>& p){
            return p->nome() == nome;
        }), m_filhos.end());
    return m_filhos.size() != oldSize;
}

void Secao::exibirInterno(ostringstream& oss, int indent) const {
    // escreve o nome desta seção com indent
    for (int i = 0; i < indent; ++i) oss << ' ';
    oss << m_nome << "\n";

    for (const auto& f : m_filhos) {
        string s = f->exibir();               
        istringstream iss(s);
        string line;
        while (getline(iss, line)) {
            // se a linha estiver vazia (p.ex. no final), pula
            if (line.empty()) continue;
            for (int i = 0; i < indent + 2; ++i) oss << ' ';
            oss << line << "\n";
        }
    }
}