#include "Dvd.hpp"

Dvd::Dvd(int codigo, std :: string titulo,int unidadesDisponiveis, std:: string categoria)
    :Midia(codigo, titulo,unidadesDisponiveis)

{
    this->categoria = categoria;
}

std:: string Dvd::getCategoria(){
    return this->categoria;
}