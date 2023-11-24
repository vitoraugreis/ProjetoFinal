#include "Fita.hpp"
#include <iostream>

Fita::Fita(int codigo, std :: string titulo,int unidadesDisponiveis,bool rebobinada)
    :Midia(codigo, titulo,unidadesDisponiveis), rebobinada(true)
    {}

bool Fita::getRebobinada(){
    return this->rebobinada;
}

void Fita:: imprimirInformacoes(){
    
    std:: cout<<this->getCodigo()<< " " << this->getTitulo() <<" " << this->getUnidadesDisponiveis() << " " << "FITA"<< std:: endl; 
}
