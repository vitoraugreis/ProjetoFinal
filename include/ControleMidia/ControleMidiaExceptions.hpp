#ifndef CONTROLE_MIDIA_EXCEPTIONS_HPP
#define CONTROLE_MIDIA_EXCEPTIONS_HPP

#include <stdexcept>

namespace midia_excp {

class codigo_repetido : public std::exception {
public:
    codigo_repetido(int codigo);

    const char* what() const throw() { return "ERRO: código repetido"; }

    int get_codigo() { return _codigo; };

private:
    int _codigo;
};

class codigo_inexistente : public std::exception {
public:
    codigo_inexistente(int codigo);

    const char* what() const throw() { return "ERRO: código inexistente"; }

    int get_codigo() { return _codigo; };

private:
    int _codigo;
};

class tipo_desconhecido : public std::exception {
public:
    tipo_desconhecido(int tipoMidia);

    const char* what() const throw() { return "ERRO: tipo de mídia desconhecido"; }

    int get_tipo() { return _tipoMidia; };

private:
    int _tipoMidia;
};

class erro_de_abertura : public std::exception {
public:
    erro_de_abertura(std::string arquivo);

    const char* what() const throw() { return "ERRO: arquivo inexistente"; }

    std::string get_arquivo() { return _arquivo; };

private:
    std::string _arquivo;
};

class ordem_invalida : public std::exception {
public:
    ordem_invalida(char ordem);

    const char* what() const throw() { return "ERRO: as opções de ordenação são Código (C) ou Título (T)"; }

    char get_ordem() { return _ordem; };

private:
    char _ordem;
};

class categoria_invalida : public std::exception {
public:
    categoria_invalida(std::string categoria);

    const char* what() const throw() { return "ERRO: a categoria de cadastro é inválida"; }

    std::string  get_categoria() { return _categoria; };

private:
    std::string  _categoria;
};

} 

#endif
