#ifndef MIDIA_H
#define MIDIA_H

#include <string>

class Midia{
    int codigo;
    std :: string titulo;
    std :: string categoria;
    int unidadesDisponiveis;

    public:
        Midia(int codigo, std :: string titulo, int unidadesDisponiveis, std::string categoria);
        virtual ~Midia() = default;
        int  getCodigo();
        std::string getCategoria();
        std :: string getTitulo();
        int getUnidadesDisponiveis();
        virtual void imprimirInformacoes(bool unidades = true) = 0;
        void diminuirUnidadesDisponiveis();
};


#endif