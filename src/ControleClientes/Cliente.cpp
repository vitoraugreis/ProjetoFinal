#include "Cliente.hpp"
#include <algorithm>

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

int Cliente::fazerLocacao(int codigo, std::tm momento_de_locacao){
    Alocacao * alocacao = new Alocacao(codigo, momento_de_locacao);
    historico.push_back(alocacao); 
    return 0;
}

int Cliente::fazerDevolucao(int codigo, std::tm momento_de_devolucao){
    for (auto & it : historico){
        if (it->getCodigo() == codigo) {
            it->devolver(momento_de_devolucao);
        }
    }
    return 0;
}

std::tm Cliente::getDataLocacao(int codigo){
    for (auto & it : historico){
        if (it->getCodigo() == codigo) {
            return it->getAlocacao(); 
        }
    }
}

bool Cliente::printHistorico(){
    if (historico.empty()) {
        return false;
    }

    std::sort(historico.begin(), historico.end(),
              [](Alocacao *a, Alocacao *b) {
                  return std::mktime(&a->_momento_de_locacao) < std::mktime(&b->_momento_de_locacao);
              });

    std::cout << "COD" << "   " <<
                 "Alugado" << "   " <<
                 "Devolvido" << std::endl;

    for (auto &alocacaoPtr : historico) {
        alocacaoPtr->printInformacao();
    }

    return true;
}

bool Cliente::isHistoricoVazio(){return historico.empty();}