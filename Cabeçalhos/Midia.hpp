#ifndef MIDIA_H
#define MIDIA_H

#include <string>

class Midia{
    
    int codigo;
    std :: string titulo;
    int unidadesDisponiveis;

    public:

    Midia(int codigo, std :: string titulo,int unidadesDisponiveis);
    int getCodigo();
    std :: string getTitulo();
    int getUnidadesDisponiveis();
};





#endif