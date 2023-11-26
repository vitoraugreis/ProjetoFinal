#include "Midia.hpp"

Midia::Midia(int codigo,std :: string titulo,int unidadesDisponiveis){
    this->codigo = codigo;
    this->titulo = titulo;
    this->unidadesDisponiveis = unidadesDisponiveis;
    }

int Midia::getCodigo(){
    return codigo;
}

std :: string Midia::getTitulo(){
    return titulo;
}

int Midia::getUnidadesDisponiveis(){
    return unidadesDisponiveis;
}