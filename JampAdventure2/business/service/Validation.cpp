#include <algorithm>
#include <cctype>
#include <regex>

#include "Validation.h"
#include "../../infra/error/ExceptionLogin.h"
#include "../../infra/error/ExceptionPassword.h"

static bool hasUpper(const std::string& s){ return std::any_of(s.begin(),s.end(),::isupper); }
static bool hasLower(const std::string& s){ return std::any_of(s.begin(),s.end(),::islower); }
static bool hasDigit(const std::string& s){ return std::any_of(s.begin(),s.end(),::isdigit); }
static bool hasSymbol(const std::string& s){
    return std::any_of(s.begin(),s.end(), [](unsigned char c){ return !std::isalnum(c); });
}

void validateLogin(const std::string& login) {
    if (login.empty()) throw ExceptionLogin("Login vazio");
    if (login.size() > 12) throw ExceptionLogin("Login deve ter no maximo 12 caracteres");
    if (hasDigit(login)) throw ExceptionLogin("Login nao pode conter numeros");
}

void validatePassword(const std::string& pwd, const std::string& username) {
    if (pwd.size() < 8 || pwd.size() > 128)
        throw ExceptionPassword("Senha deve ter entre 8 e 128 caracteres");
    int classes = hasUpper(pwd) + hasLower(pwd) + hasDigit(pwd) + hasSymbol(pwd);
    if (classes < 3)
        throw ExceptionPassword("Senha precisa conter 3 de 4 tipos: maiuscula, minuscula, digito, simbolo");
    if (!username.empty()) {
        // regra opcional: evitar senha igual ao login (boa prática)
        if (std::equal(pwd.begin(), pwd.end(), username.begin(), username.end(),
                        [](char a,char b){ return std::tolower(a)==std::tolower(b); }))
            throw ExceptionPassword("Senha nao pode ser igual ao login");
    }
}