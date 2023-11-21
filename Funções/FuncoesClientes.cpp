//#include "FuncoesClientes.hpp"
#include "../Cabeçalhos/Cliente.hpp"
#include <string>

// Comparação de CPF
static bool compCPF (Cliente* a, Cliente* b){
    return a->getCPF() < b->getCPF();
}

// Comparação de nome
static bool compNome(Cliente* a, Cliente* b){
    return a->getNome() < b->getNome();
}