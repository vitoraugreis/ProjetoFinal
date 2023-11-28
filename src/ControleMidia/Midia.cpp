#include "Midia.hpp"

Midia::Midia(int codigo, std :: string titulo, int unidadesDisponiveis, std :: string categoria){
    this->codigo = codigo;
    this->titulo = titulo;
    this->unidadesDisponiveis = unidadesDisponiveis;
    this->categoria = categoria;
    }

int Midia::getCodigo(){
    return codigo;
}

std:: string Midia::getCategoria(){
    return categoria;
}

std :: string Midia::getTitulo(){
    return titulo;
}

int Midia::getUnidadesDisponiveis(){
    return unidadesDisponiveis;
}

void Midia::diminuirUnidadesDisponiveis(){
    this->unidadesDisponiveis--;
}