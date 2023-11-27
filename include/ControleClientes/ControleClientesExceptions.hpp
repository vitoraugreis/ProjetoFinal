#ifndef CONTROLE_CLIENTES_EXCEPTIONS_HPP
#define CONTROLE_CLIENTES_EXCEPTIONS_HPP

#include <stdexcept>

namespace clientes_excp {

class cpf_curto : public std::exception {
public:
    cpf_curto(std::string cpf);

    const char* what() const throw() { return "ERRO: CPF deve conter 11 digitos"; }

    std::string get_cpf() { return _cpf; };

private:
    std::string _cpf;
};

class cpf_repetido : public std::exception {
public:
    cpf_repetido(std::string cpf);

    const char* what() const throw() { return "ERRO: CPF repetido"; }

    std::string get_cpf() { return _cpf; };

private:
    std::string _cpf;
};

class cpf_inexistente : public std::exception {
public:
    cpf_inexistente(std::string cpf);

    const char* what() const throw() { return "ERRO: CPF inexistente"; }

    std::string get_cpf() { return _cpf; };

private:
    std::string _cpf;
};

class ordem_invalida : public std::exception {
public:
    ordem_invalida(char ordem);

    const char* what() const throw() { return "Erro: as opções de ordenação são Código (C) ou Nome (N)"; }

    char get_ordem() { return _ordem; };

private:
    char _ordem;
};

}

#endif