#ifndef CONTROLE_CLIENTES_H
#define CONTROLE_CLIENTES_H

#include <string>
#include <map>

class Cliente {
public:
    std::string nome;
    int cpf;

    Cliente(std::string nome, int cpf){
        this->nome = nome;
        this->cpf = cpf;
    }
};

class ControleClientes {
    std::map<int, Cliente*> clientes;
    
public:
    bool fazerCadastro(std::string nome, int cpf);
    bool removerCadastro(int cpf);
    bool pesquisarCliente(int cpf);
    bool gerarRelatorio();
};

#endif