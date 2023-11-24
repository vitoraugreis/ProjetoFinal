#include "Fita.hpp"

Fita::Fita(int codigo, std :: string titulo,int unidadesDisponiveis,bool rebobinada)
    :Midia(codigo, titulo,unidadesDisponiveis), rebobinada(true)
    {}

bool Fita::getRebobinada(){
    return this->rebobinada;
}