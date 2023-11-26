#include "Fita.hpp"
#include <iostream>

Fita::Fita(int codigo, std :: string titulo,int unidadesDisponiveis,bool rebobinada)
    :Midia(codigo, titulo,unidadesDisponiveis), rebobinada(true)
    {}

bool Fita::getRebobinada(){
    return rebobinada;
}

void Fita:: imprimirInformacoes(){
    
    std:: cout<<getCodigo()<< " " << getTitulo() <<" " << this->getUnidadesDisponiveis() << " " << "FITA"<< std:: endl; 
}
