#ifndef CONTROLE_MIDIA_EXCEPTIONS_HPP
#define CONTROLE_MIDIA_EXCEPTIONS_HPP

#include <stdexcept>

namespace midia_excp {

class codigo_repetido : public std::exception {
    public:
        codigo_repetido(int codigo) : _codigo(codigo) {};

        const char* what() const throw() {return "ERRO:codigo repetido";}

        int get_codigo() {return _codigo;};
    
    private:
        int _codigo;
};

class codigo_inexistente : public std::exception {
    public:
        codigo_inexistente(int codigo) : _codigo(codigo) {};

        const char* what() const throw() {return "ERRO:codigo inexistente";}

        int get_codigo() {return _codigo;};
    
    private:
        int _codigo;
};


class tipo_desconhecido : public std::exception {
    public:
        tipo_desconhecido(int tipoMidia) : _tipoMidia(tipoMidia) {};

        const char* what() const throw() {return "Tipo de mídia desconhecido";}

        int get_tipo() {return _tipoMidia;};
    
    private:
        int _tipoMidia;
};


class erro_de_abertura : public std::exception {
    public:
        erro_de_abertura(std::string arquivo) : _arquivo(arquivo) {};

        const char* what() const throw() {return "Erro ao abrir o arquivo de cadastro";}

        std::string get_arquivo() {return _arquivo;};
    
    private:
        std::string _arquivo;
};


}

#endif 
