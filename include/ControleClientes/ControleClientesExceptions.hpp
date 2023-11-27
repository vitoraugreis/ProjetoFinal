#ifndef CONTROLE_CLIENTES_EXCEPTIONS_HPP
#define CONTROLE_CLIENTES_EXCEPTIONS_HPP

#include <stdexcept>

namespace clientes_excp {

class cpf_curto : public std::exception {
    public:
        cpf_curto(std::string cpf) : _cpf(cpf) {};

        const char* what() const throw() {return "ERRO: CPF deve conter 11 digitos";}

        std::string get_cpf() {return _cpf;};
    
    private:
        std::string _cpf;
};


class cpf_repetido : public std::exception {
    public:
        cpf_repetido(std::string cpf) : _cpf(cpf) {};

        const char* what() const throw() {return "ERRO: CPF repetido";}

        std::string get_cpf() {return _cpf;};
    
    private:
        std::string _cpf;
};

class cpf_inexistente : public std::exception {
    public:
        cpf_inexistente(std::string cpf) : _cpf(cpf) {};

        const char* what() const throw() {return "ERRO: CPF inexistente";}

        std::string get_cpf() {return _cpf;};
    
    private:
        std::string _cpf;

};

}

#endif 
