#include "ControleClientes.hpp"
#include "ControleClientesExceptions.hpp"
#include "../Funcoes/FuncoesClientes.cpp"
#include <iostream>
#include <fstream>
#include <algorithm>

ControleClientes::ControleClientes(){
    std::ifstream Database("database/dbClientes.txt");
    if (Database){
        std::string cpf;
        std::string nome;
        std::string verify;
        getline(Database, verify);  // Verifica se o banco de dados está vazio.
        if (!verify.size()){
            this->clientes.clear();
        } else{
            Database.seekg(0);
            while (!Database.eof()){    // Leitura do banco de dados.
                Database >> cpf;
                int pos = Database.tellg(); pos++;
                Database.seekg(pos);
                getline(Database, nome);
                this->fazerCadastro(nome, cpf, false);
            }
            Database.close();
        }
    } else{
        std::cout << "FFFF";
    }
}

bool ControleClientes::fazerCadastro(std::string nome, std::string cpf, bool msg){
    if (cpf.length() != 11){
        throw clientes_excp::cpf_curto(cpf);
        return false;
    } else if(this->pesquisarCliente(cpf)){
        throw clientes_excp::cpf_repetido(cpf);
        return false;
    }
    Cliente* aux = new Cliente(nome, cpf);
    this->clientes.push_back(aux);
    if (msg){ 
        std::cout << "Cliente " << cpf <<  " cadastrado com sucesso" << std::endl;
    }
    return true;
}

bool ControleClientes::removerCadastro(std::string cpf){
    Cliente* cliente = this->pesquisarCliente(cpf);
    if(!cliente){
        throw clientes_excp::cpf_inexistente(cpf);
        return false;
    }
    for (auto it = this->clientes.begin(); it != this->clientes.end(); it++){
        if (*it == cliente){
            this->clientes.erase(it);
            break;
        }
    }
    delete cliente;
    std::cout << "Cliente " << cpf << " removido com sucesso" << std::endl;
    return true;
}

Cliente* ControleClientes::pesquisarCliente(std::string cpf){
    for (int i = 0; i<this->clientes.size(); i++){
        if (cpf == this->clientes[i]->getCPF()){
            //std::cout << "Cliente " << cpf << " existe" << std::endl;
            return this->clientes[i];
        }
    }
    throw clientes_excp::cpf_inexistente(cpf);
    return 0;
}

bool ControleClientes::gerarRelatorio(char ordem){
    if (this->clientes.empty()){
        std::cout << "Não há clientes registrados." << std::endl;
        return false;
    }
    if (ordem != 'C' and ordem != 'N'){
        throw clientes_excp::ordem_invalida(ordem);
        return false;
    }
    if(ordem == 'C'){
        std::sort(this->clientes.begin(), this->clientes.end(), compCPF);
    } else {
        std::sort(this->clientes.begin(), this->clientes.end(), compNome);
    }
    for(auto it = this->clientes.begin(); it != this->clientes.end(); it++){
        std::cout << (*it)->getCPF() << " " << (*it)->getNome() << std::endl;
    }
    return true;
}

void ControleClientes::limparDatabase(){
    while(!this->clientes.empty()){
        delete *this->clientes.begin();
        this->clientes.erase(this->clientes.begin());
    }
}

ControleClientes::~ControleClientes(){
    std::ofstream Database("database/dbClientes.txt");
    std::sort(this->clientes.begin(), this->clientes.end(), compCPF);
    for(auto it = this->clientes.begin(); it != this->clientes.end(); it++){
        if (it == this->clientes.begin()){
            Database << (*it)->getCPF() << " " << (*it)->getNome();
        } else{
            Database << "\n" << (*it)->getCPF() << " " << (*it)->getNome();
        }
        delete (*it);
    }
    Database.close();
}