#ifndef DVD_H
#define DVD_H

#include "Midia.hpp"

class Dvd : public Midia{

    public:
        Dvd(int codigo, std :: string titulo,int unidadesDisponiveis, std:: string categoria); 
        void imprimirInformacoes(bool unidades = true);

};

#endif