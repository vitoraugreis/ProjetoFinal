#ifndef CONTROLE_CLIENTES_H
#define CONTROLE_CLIENTES_H

#include "Cliente.hpp"
#include "ControleClientesExceptions.hpp"
#include <string>
#include <vector>

class ControleClientes {
    std::vector<Cliente*> clientes;
    
public:
    ControleClientes();
    bool fazerCadastro(std::string nome, std::string cpf, bool msg = true);
    bool removerCadastro(std::string cpf);
    Cliente* pesquisarCliente(std::string cpf);
    bool gerarRelatorio(char ordem);
    void limparDatabase();
    ~ControleClientes();
};

#endif
