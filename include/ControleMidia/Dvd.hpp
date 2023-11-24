#ifndef DVD_H
#define DVD_H

#include "Midia.hpp"

class Dvd : public Midia{
std :: string categoria;

public:
Dvd(int codigo, std :: string titulo,int unidadesDisponiveis, std:: string categoria); 
std::string getCategoria() ;
void imprimirInformacoes();


};

#endif