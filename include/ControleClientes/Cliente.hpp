#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <iomanip>
#include <unordered_map> 

class Cliente {
    std::unordered_map<int, std::time_t> historico;
    std::string nome;
    std::string cpf;

public:
    Cliente(std::string nome, std::string cpf);
    std::string getNome();
    std::string getCPF();
    int fazerLocacao(int codigo, std::time_t momento_de_locacao);
    std::time_t getDataLocacao(int codigo);
};

#endif