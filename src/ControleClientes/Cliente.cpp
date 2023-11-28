#include "Cliente.hpp"

Cliente::Cliente(std::string nome, std::string cpf){
    this->nome = nome;
    this->cpf = cpf;
}

std::string Cliente::getNome(){
    return this->nome;
}

std::string Cliente::getCPF(){
    return this->cpf;
}

int Cliente::fazerLocacao(int codigo, std::time_t momento_de_locacao){
    this->historico.insert({codigo, momento_de_locacao}); 
    return 0;
}

std::time_t Cliente::getDataLocacao(int codigo){
    return this->historico[codigo]; 
}