#ifndef SECAO_HPP
#define SECAO_HPP

#include "componenteCadastro.hpp"
#include <vector>
#include <memory>
#include <string>

using namespace std;

class Secao : public componenteCadastro{
    protected:
        string m_nome; //nome
        vector<unique_ptr<componenteCadastro>> m_filhos; //lista de filhos, cada filho pode ser uma secao ou um campo

    public:
        explicit Secao(string nome);
        virtual ~Secao() = default;

        Secao& add(unique_ptr<componenteCadastro> filho);

        template<typename T, typename... Args>
        Secao& addNew(Args&&... args){
            m_filhos.push_back(std::make_unique<T>(std::forward<Args>(args)...));
            return *this;
        }

        //interface
        const string& nome() const override;
        void adicionar(unique_ptr<componenteCadastro> filho) override;
        bool removerPorNome(const string& nome) override;
    
    protected:
        void exibirInterno(ostringstream& oss, int indent) const override;
};

#endif // SECAO_HPP