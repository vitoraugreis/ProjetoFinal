#include "Dvd.hpp"
#include <iostream>

Dvd::Dvd(int codigo, std :: string titulo,int unidadesDisponiveis, std:: string categoria)
    :Midia(codigo, titulo,unidadesDisponiveis)

{
    this->categoria = categoria;
}

std:: string Dvd::getCategoria(){
    return categoria;
}

void Dvd:: imprimirInformacoes(){
    
    std:: cout<<getCodigo()<< " " << getTitulo() <<" " << getUnidadesDisponiveis() << " " << "DVD"<< std:: endl; 
}
