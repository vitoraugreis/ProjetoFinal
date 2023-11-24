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