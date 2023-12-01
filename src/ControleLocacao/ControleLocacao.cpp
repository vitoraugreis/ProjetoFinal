#include "ControleLocacao.hpp"
#include "ControleMidiaExceptions.hpp"
#include "ControleClientesExceptions.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
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
        if (filme.getCategoria() == "Lancamento"){return duracao*preco_lancamento;}
        if (filme.getCategoria() == "Estoque"){return duracao*preco_estoque;}
        if (filme.getCategoria() == "Promocao"){return preco_promocao;}
    }
    throw midia_excp::categoria_invalida(filme.getCategoria());
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
            if (verify != cm.getEstoqueEnd()){
                if ((*verify)->getUnidadesDisponiveis() == 0){
                    std::cout << "ERRO: Filme " << (*verify)->getCodigo() << " não possui mais unidades disponiveis" << std::endl;
                    return false;
                }
                (*ind).second.push_back(*verify);
            } else{
                throw midia_excp::codigo_inexistente(*it);
                return false;
            }
        }
        std::cout << "Cliente " << cliente->getCPF() << " " << cliente->getNome() << " " << "alugou os filmes:" << std::endl;
        for (auto it = (*ind).second.begin(); it != (*ind).second.end(); it++){
            (*cliente).fazerLocacao((*it)->getCodigo(), momento_de_locacao);
            (*it)->imprimirInformacoes(false);
            (*it)->diminuirUnidadesDisponiveis();
        }
    } else{
        throw clientes_excp::cpf_inexistente(cpf);
        return false;
    }
    return true;
}

bool ControleLocacao::fazerDevolucao(ControleClientes &cc, ControleMidia &cm, std::string cpf){
    Cliente* cliente = cc.pesquisarCliente(cpf);
    // std::time_t momento_de_devolucao = std::time(0);
    // std::tm tm_devolucao = *std::localtime(&momento_de_devolucao);
    std::tm tm_devolucao = {};
    std::istringstream date_stream("28/12/2023"); 
    date_stream >> std::get_time(&tm_devolucao, FORMATO_DATA); 
    std::time_t momento_de_devolucao = mktime(&tm_devolucao);

    double total_a_pagar = 0.0;

    if (cliente){
        std::vector<Midia*> filmes; filmes.clear();
        filmes = locacoes[cliente];
        locacoes.erase(cliente);
        
        std::cout << "Cliente " << cliente->getCPF() << " " << cliente->getNome() << " devolveu os filmes: " << std::endl;

        std::cout << std::left << std::setw(12) << "Código" << std::setw(15)<< "Alocação" << std::setw(16)  << "Devolução" << std::setw(15)  << "Valor a Pagar" << std::endl;

        for (auto it = filmes.begin(); it != filmes.end(); it++){
            std::time_t momento_de_alocacao = cliente->getDataLocacao((**it).getCodigo());
            double valor_a_pagar = 0.0;
            double duracao = (momento_de_devolucao - momento_de_alocacao)/DIA_EM_SEGUNDOS;

            valor_a_pagar = calculaAluguel(**it, duracao);
            total_a_pagar += valor_a_pagar;

            std::tm tm_alocacao = *std::localtime(&momento_de_alocacao);

            std::cout << " " << (**it).getCodigo() << "      " << std::put_time(&tm_alocacao, FORMATO_DATA) << "    " <<  std::put_time(&tm_devolucao, FORMATO_DATA) << "      " << valor_a_pagar << std::endl;
        
            (*it)->aumentarUnidadesDisponiveis();
        }

        std::cout << "Total a pagar: " << total_a_pagar << std::endl;

    } else{
        throw clientes_excp::cpf_inexistente(cpf);
        return false;
    }
    return true;
}