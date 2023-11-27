#include "Fita.hpp"
#include <iostream>

Fita::Fita(int codigo, std :: string titulo,int unidadesDisponiveis,bool rebobinada)
    :Midia(codigo, titulo,unidadesDisponiveis), rebobinada(true)
    {}

bool Fita::getRebobinada(){
    return rebobinada;
}

void Fita:: imprimirInformacoes(bool unidades){
    if (unidades){
        std:: cout<<getCodigo()<< " " << getTitulo() <<" " << this->getUnidadesDisponiveis() << " " << "FITA"<< std:: endl; 
    } else{
        std:: cout<<getCodigo()<< " " << getTitulo() << " " << "FITA"<< std:: endl; // Para o relatório de locações
    }
}
