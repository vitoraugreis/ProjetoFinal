#include "Dvd.hpp"
#include <iostream>

Dvd::Dvd(int codigo, std :: string titulo,int unidadesDisponiveis, std:: string categoria)
    :Midia(codigo, titulo,unidadesDisponiveis)

{
    this->categoria = categoria;
}

std:: string Dvd::getCategoria(){
    return this->categoria;
}

void Dvd:: imprimirInformacoes(){
    
    std:: cout<<this->getCodigo()<< " " << this->getTitulo() <<" " << this->getUnidadesDisponiveis() << " " << "DVD"<< std:: endl; 
}
