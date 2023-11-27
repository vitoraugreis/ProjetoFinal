#include "ControleLocacao.hpp"
#include <iostream>

bool ControleLocacao::fazerLocacao(ControleClientes &cc, ControleMidia &cm, std::string cpf, std::vector<int> filmes){
    Cliente* cliente = cc.pesquisarCliente(cpf);
    if (cliente){
        std::vector<Midia*> aux; aux.clear();
        this->locacoes.insert({cliente, aux}); 
        auto ind = this->locacoes.find(cliente);

        for (auto it = filmes.begin(); it != filmes.end(); it++){
            auto verify = cm.pesquisarMidia(*it);
            if (verify != cm.estoque.end()){
                if ((*verify)->getUnidadesDisponiveis() == 0){
                    std::cout << "ERRO: Filme " << (*verify)->getCodigo() << " não possui mais unidades disponiveis" << std::endl;
                    return false;
                }
                (*ind).second.push_back(*verify);
            } else{
                std::cout << "ERRO: Filme " << *it << " inexistente" << std::endl;
                return false;
            }
        }
        std::cout << "Cliente " << cliente->getCPF() << " " << cliente->getNome() << " " << "alugou os filmes:" << std::endl;
        for (auto it = (*ind).second.begin(); it != (*ind).second.end(); it++){
            (*it)->imprimirInformacoes(false);
            (*it)->diminuirUnidadesDisponiveis();
        }
    } else{
        std::cout << "ERRO: CPF inexistente." << std::endl;
        return false;
    }
    return true;
}