#ifndef CONTROLE_CLIENTES_H
#define CONTROLE_CLIENTES_H

#include <string>
#include <map>

class Cliente {
    std::string nome;
    int cpf;
public:
    Cliente(std::string nome, int cpf);
    std::string getNome();
    int getCPF();
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