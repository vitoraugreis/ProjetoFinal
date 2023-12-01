#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include <vector> 

#define FORMATO_DATA "%d/%m/%Y"

struct Alocacao {
    int _codigo;
    std::tm _momento_de_locacao;
    std::tm _momento_de_devolucao = {};
    bool _devolvido;

    Alocacao(int codigo, std::tm  momento_de_locacao):
    _codigo(codigo),
    _momento_de_locacao(momento_de_locacao),
    _devolvido(false) {}

    void devolver(std::tm momento_de_devolucao){
        _momento_de_devolucao = momento_de_devolucao;
        _devolvido = true;
    }

    int getCodigo() {return _codigo;}

    bool getDevolvido() {return _devolvido;}

    std::tm getAlocacao(){return _momento_de_locacao;}

    void printInformacao(){
        if (_devolvido){
            std::cout << _codigo << " " << 
            std::put_time(&_momento_de_locacao, FORMATO_DATA) << " " << 
            std::put_time(&_momento_de_devolucao, FORMATO_DATA) << std::endl;
        } else {
            std::cout << _codigo << " " << 
            std::put_time(&_momento_de_locacao, FORMATO_DATA) << " " << 
            "--/--/----" << std::endl;
        }
    }
};

class Cliente {
    std::vector<Alocacao*> historico;
    std::string nome;
    std::string cpf;

public:
    Cliente(std::string nome, std::string cpf);
    std::string getNome();
    std::string getCPF();
    int fazerLocacao(int codigo, std::tm momento_de_locacao);
    int fazerDevolucao(int codigo, std::tm momento_de_devolucao);
    std::tm getDataLocacao(int codigo);
    bool printHistorico();
    bool isHistoricoVazio();
};

#endif