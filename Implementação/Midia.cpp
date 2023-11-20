#include "../Cabeçalhos/Midia.hpp"

Midia::Midia(int codigo,std :: string titulo,int unidadesDisponiveis){
    this->codigo = codigo;
    this->titulo = titulo;
    this->unidadesDisponiveis = unidadesDisponiveis;
    }

int Midia::getCodigo(){
    return this->codigo;
}

std :: string Midia::getTitulo(){
    return this->titulo;
}

int Midia::getUnidadesDisponiveis(){
    return this->unidadesDisponiveis;
}