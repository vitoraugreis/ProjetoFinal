#include "controleClientes.hpp"
#include <iostream>
#include <string>
#include <map>
#include <fstream>

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

ControleClientes::ControleClientes(){
    std::ifstream Database("Database/dbClientes.txt");
    if (Database){
        std::string cpf;
        std::string nome;
        while (!Database.eof()){
            Database >> cpf;
            int pos = Database.tellg(); pos++;
            Database.seekg(pos);
            getline(Database, nome);
            Cliente* aux = new Cliente(nome, cpf);
            this->clientes.insert({cpf, aux});
        }
        Database.close();
    }
}

bool ControleClientes::fazerCadastro(std::string nome, std::string cpf){
    if(this->pesquisarCliente(cpf)){
        std::cout << "ERRO: CPF repetido" << std::endl;
        return false;
    }
    Cliente* aux = new Cliente(nome, cpf);
    this->clientes.insert({cpf, aux});
    std::cout << "Cliente " << cpf <<  " cadastrado com sucesso" << std::endl;
    return true;
}

bool ControleClientes::removerCadastro(std::string cpf){
    if(!this->pesquisarCliente(cpf)){
        std::cout << "ERRO: CPF inexistente" << std::endl;
        return false;
    }
    delete this->clientes.find(cpf)->second;
    this->clientes.erase(this->clientes.find(cpf));
    std::cout << "Cliente " << cpf << " removido com sucesso" << std::endl;
    return true;
}

bool ControleClientes::pesquisarCliente(std::string cpf){
    if (this->clientes.find(cpf) == this->clientes.end()){
       //std::cout << "ERRO: CPF inexistente" << std::endl;
        return false;
    }
    //std::cout << "Cliente " << cpf << " existe" << std::endl;
    return true;
}

bool ControleClientes::gerarRelatorio(){
    if (this->clientes.empty()){
        std::cout << "Não há clientes registrados." << std::endl;
        return false;
    }
    for (auto it = this->clientes.begin(); it !=  this->clientes.end(); it++){
        std::cout << it->first << "\t" << it->second->getNome() << std::endl;
    }
    return true;
}

ControleClientes::~ControleClientes(){
    std::ofstream Database("Database/dbClientes.txt");
    for(auto it = this->clientes.begin(); it != this->clientes.end(); it++){
        if (it == this->clientes.begin()){
            Database << it->first << " " << it->second->getNome();
        } else{
            Database << "\n" << it->first << " " << it->second->getNome();
        }
    }
    Database.close();
}