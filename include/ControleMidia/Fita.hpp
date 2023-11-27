#ifndef FITA_H
#define FITA_H

#include "Midia.hpp"

class Fita : public Midia{
        bool rebobinada;

    public:
<<<<<<< HEAD
        Fita(int codigo, std :: string titulo,int unidadesDisponiveis,bool rebobinada);
        bool getRebobinada() ;
        void imprimirInformacoes();
=======
    Fita(int codigo, std :: string titulo,int unidadesDisponiveis,bool rebobinada);
    bool getRebobinada() ;
    void imprimirInformacoes(bool unidades = true);
>>>>>>> bb1009676437935ee415a3256fe01e2d580bb18a

};

#endif