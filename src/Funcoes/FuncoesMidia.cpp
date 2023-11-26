#include "Midia.hpp"

static bool compCodigo (Midia* a, Midia* b){
    return a->getCodigo() < b->getCodigo();
}

// Comparação de nome
static bool compTitulo(Midia* a, Midia* b){
    return a->getTitulo() < b->getTitulo();
}