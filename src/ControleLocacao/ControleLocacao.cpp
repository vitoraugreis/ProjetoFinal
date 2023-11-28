#include "ControleLocacao.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

#define DIA_EM_SEGUNDOS 86400
#define FORMATO_DATA "%d/%m/%Y"

double ControleLocacao::calculaAluguel(Midia &filme, double duracao){
    double preco_fita = 5.0;
    double preco_lancamento = 20.0;
    double preco_estoque = 10.0;
    double preco_promocao = 10.0;
    double multa = 2.0;

    if (filme.getCategoria() == "FITA"){
        Fita* fita = dynamic_cast<Fita*>(&filme);
        if (fita->getRebobinada()){return preco_fita;}
        return preco_fita + multa;
    } else {
        if (filme.getCategoria() == "Lançamento"){return duracao*preco_lancamento;}
        if (filme.getCategoria() == "Estoque"){return duracao*preco_estoque;}
        if (filme.getCategoria() == "Promocao"){return preco_promocao;}
    }
    return 0.0;
}

bool ControleLocacao::fazerLocacao(ControleClientes &cc, ControleMidia &cm, std::string cpf, std::vector<int> filmes){
    Cliente* cliente = cc.pesquisarCliente(cpf);
    std::time_t momento_de_locacao = std::time(0);
    
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
                (*cliente).fazerLocacao((*verify)->getCodigo(), momento_de_locacao);
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

bool ControleLocacao::fazerDevolucao(ControleClientes &cc, ControleMidia &cm, std::string cpf){
    Cliente* cliente = cc.pesquisarCliente(cpf);
    std::time_t momento_de_devolucao = std::time(0);
    double total_a_pagar = 0.0;

    if (cliente){
        std::vector<Midia*> filmes; filmes.clear();
        filmes = locacoes[cliente];
        locacoes.erase(cliente);
        
        std::cout << "Cliente " << cliente->getCPF() << " " << cliente->getNome() << "devolveu os filmes: " << std::endl;

        for (auto it = filmes.begin(); it != filmes.end(); it++){
            double valor_a_pagar = 0.0;
            double duracao = (cliente->getDataLocacao((**it).getCodigo()) - momento_de_devolucao)/DIA_EM_SEGUNDOS;
            valor_a_pagar = calculaAluguel(**it, duracao);
            total_a_pagar += valor_a_pagar;

            std::cout << (**it).getCodigo() << " " << valor_a_pagar << std::endl;
        }
    } else{
        std::cout << "ERRO: CPF inexistente." << std::endl;
        return false;
    }
    return true;
}