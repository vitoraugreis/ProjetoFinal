#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente {
    std::string nome;
    std::string cpf;

public:
    Cliente(std::string nome, std::string cpf);
    std::string getNome();
    std::string getCPF();
};

#endif