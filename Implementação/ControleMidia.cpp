#include "../Cabeçalhos/ControleMidia.hpp"
#include <fstream>
#include <iostream>

ControleMidia:: ControleMidia(): estoque(){}

bool ControleMidia::cadastrarDvd(int codigo, std::string titulo, int unidadesDisponiveis, std::string categoria) {
    
    Dvd* novoDvd = new Dvd(codigo, titulo, unidadesDisponiveis, categoria);

    estoque.push_back(novoDvd);

    return true;
}

bool ControleMidia::cadastrarFita(int codigo, std::string titulo, int unidadesDisponiveis, bool rebobinada) {

    Fita* novaFita = new Fita(codigo, titulo, unidadesDisponiveis, rebobinada);
    //true rebobinada, false nao rebobinada
    estoque.push_back(novaFita);

    return true;
}

bool ControleMidia::lerArquivoCadastro(std::string arquivo) {
    std::ifstream infile(arquivo);

    if (!infile) {
        std::cerr << "Erro ao abrir o arquivo de cadastro: " << arquivo << std::endl;
        return false;
    }

    int tipoMidia; 
    std::string categoria;

    while (infile >> tipoMidia) {
        int codigo;
        std::string titulo;
        int unidadesDisponiveis;

        // lê a primeira coluna do dbMidia e procura o tipo midia
        switch (tipoMidia) {
            case 1: //Dvd
                categoria.clear();
                infile >> codigo >> titulo >> unidadesDisponiveis >> categoria;
                cadastrarDvd(codigo, titulo, unidadesDisponiveis, categoria);
                break;
            case 2:  //Fita
                bool rebobinada;
                infile >> codigo >> titulo >> unidadesDisponiveis >> rebobinada;
                cadastrarFita(codigo, titulo, unidadesDisponiveis, rebobinada);
                break;
            default:
                std::cerr << "Tipo de mídia desconhecido: " << tipoMidia << std::endl;
                break;
        }
    }

    infile.close();
    return true;
}
