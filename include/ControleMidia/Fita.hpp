#ifndef FITA_H
#define FITA_H

#include "Midia.hpp"

class Fita : public Midia{
        bool rebobinada;

    public:
        Fita(int codigo, std :: string titulo,int unidadesDisponiveis,bool rebobinada);
        bool getRebobinada() ;
        void imprimirInformacoes();

};

#endif