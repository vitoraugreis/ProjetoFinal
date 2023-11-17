#ifndef CONTROLE_CLIENTES_H
#define CONTROLE_CLIENTES_H

#include <string>
#include <map>

class Cliente {
    std::string nome;
    std::string cpf;

public:
    Cliente(std::string nome, std::string cpf);
    std::string getNome();
    std::string getCPF();
};

class ControleClientes {
    std::map<std::string, Cliente*> clientes;
    
public:
    ControleClientes();
    bool fazerCadastro(std::string nome, std::string cpf);
    bool removerCadastro(std::string cpf);
    bool pesquisarCliente(std::string cpf);
    bool gerarRelatorio();
    void limparDatabase();
    ~ControleClientes();
};

#endif
