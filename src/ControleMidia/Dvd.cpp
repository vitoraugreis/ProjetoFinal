#include "Dvd.hpp"
#include <iostream>

Dvd::Dvd(int codigo, std :: string titulo,int unidadesDisponiveis, std:: string categoria)
    :Midia(codigo, titulo,unidadesDisponiveis, categoria)

{}

void Dvd:: imprimirInformacoes(bool unidades){
    if (unidades){
        std:: cout<<getCodigo()<< " " << getTitulo() <<" " << this->getUnidadesDisponiveis() << " " << "DVD"<< std:: endl; 
    } else{
        std:: cout<<getCodigo()<< " " << getTitulo() << " " << "DVD"<< std:: endl; // Para o relatório de locações
    }
}
