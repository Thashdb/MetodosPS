#ifndef COMPONENTE_CADASTRO_HPP
#define COMPONENTE_CADASTRO_HPP

#include <string>
#include <sstream>
#include <stdexcept>
#include <memory>

using namespace std;

class componenteCadastro{
    private:
        /* data */
    public:
        virtual ~componenteCadastro() = default;

        // exibe as informacoes de forma recursiva
        string exibir() const{
            ostringstream oss;
            exibirInterno(oss, 0);
            return oss.str();
        }
        
        virtual void adicionar(unique_ptr<componenteCadastro> filho){
            (void)filho;
            throw logic_error("Componente não aceita filhos");
        }
        virtual bool removerPorNome (const string& nome){
            (void)nome;
            throw logic_error("Componente não aceita filhos");
        }
        virtual const string& nome() const = 0;
    
    protected:
        virtual void exibirInterno(ostringstream& oss, int ident) const=0;

        static void identar (ostringstream& oss, int n){
            for (int i = 0; i < n; ++i) oss << ' ';
        }
};

#endif //COMPONENTE_CADASTRO_HPP
