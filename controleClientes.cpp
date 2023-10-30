#include "controleClientes.hpp"
#include <iostream>
#include <string>
#include <map>

bool ControleClientes::fazerCadastro(std::string nome, int cpf){
    if(this->pesquisarCliente(cpf)){
        std::cout << "ERRO: CPF repetido" << std::endl;
        return false;
    }
    Cliente* aux = new Cliente(nome, cpf);
    this->clientes.insert({cpf, aux});
    std::cout << "Cliente " << cpf <<  " cadastrado com sucesso" << std::endl;
    return true;
}

bool ControleClientes::removerCadastro(int cpf){
    if(!this->pesquisarCliente(cpf)){
        std::cout << "ERRO: CPF inexistente" << std::endl;
        return false;
    }
    this->clientes.erase(this->clientes.find(cpf));
    std::cout << "Cliente " << cpf << " removido com sucesso" << std::endl;
    return true;
}

bool ControleClientes::pesquisarCliente(int cpf){
    if (this->clientes.find(cpf) == this->clientes.end()){
        return false;
    }
    return true;
}

bool ControleClientes::gerarRelatorio(){
    if (this->clientes.empty()){
        std::cout << "Não há clientes registrados." << std::endl;
        return false;
    }
    for (auto it = this->clientes.begin(); it != this->clientes.end(); it++){
        std::cout << it->first << "\t" << it->second->nome << std::endl;
    }
    return true;
}