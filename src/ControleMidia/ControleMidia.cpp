#include "ControleMidia.hpp"
#include "ControleMidiaExceptions.hpp"
#include "../Funcoes/FuncoesMidia.cpp"
#include <fstream>
#include <iostream>
#include <algorithm>


ControleMidia:: ControleMidia(): estoque(){}

ControleMidia:: ~ControleMidia(){
    
    for(auto it = estoque.begin(); it != estoque.end(); it++){
        
        if (*it != nullptr) {
            delete (*it);
    }
    }
}

bool ControleMidia::cadastrarDvd(int codigo, std::string titulo, int unidadesDisponiveis, std::string categoria) {
    
    auto it = pesquisarMidia(codigo);
    
    if(it == estoque.end()){
        Dvd* novoDvd = new Dvd(codigo, titulo, unidadesDisponiveis, categoria);

        estoque.push_back(novoDvd);
        std:: cout << "Filme "<< codigo << " cadastrado com sucesso" << std:: endl;
        return true;
    }
    
    throw midia_excp::codigo_repetido(codigo);
    return false;

}

bool ControleMidia::cadastrarFita(int codigo, std::string titulo, int unidadesDisponiveis, bool rebobinada) {

    auto it = pesquisarMidia(codigo);

    
    if(it == estoque.end()){
        Fita* novaFita = new Fita(codigo, titulo, unidadesDisponiveis, rebobinada);
        //true rebobinada, false nao rebobinada
        estoque.push_back(novaFita);
        std:: cout << "Filme "<< codigo << " cadastrado com sucesso" << std:: endl;
        return true;
    }

    throw midia_excp::codigo_repetido(codigo);
    return false;
}


bool ControleMidia::cadastrarMidia(int tipoMidia, int codigo, std::string titulo, int unidadesDisponiveis, std::string categoria) {

    switch (tipoMidia) {
        case 1: //Dvd
            cadastrarDvd(codigo, titulo, unidadesDisponiveis, categoria);
            break;
        case 2:  //Fita
            bool rebobinada = 1;
            cadastrarFita(codigo, titulo, unidadesDisponiveis, rebobinada);
            break;
        default:
            std::cerr << "Tipo de mídia desconhecido: " << tipoMidia << std::endl;
            break;
        }
    return false;

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

std::vector<Midia *>::iterator ControleMidia:: pesquisarMidia(int codigo){
    
    for(auto it = estoque.begin(); it != estoque.end(); it++){
        if(codigo == (*it)->getCodigo()){
                    
            return it;

        }
    }

    return estoque.end();
}

void ControleMidia::imprimirMidias(char ordem) {
    
    if(ordem == 'C'){
        
        std::sort(this->estoque.begin(), this->estoque.end(),compCodigo);

    }else if(ordem == 'T'){
        
        std::sort(this->estoque.begin(), this->estoque.end(),compTitulo);

    }

    for(auto it = this->estoque.begin(); it != this->estoque.end(); it++){
        (*it)->imprimirInformacoes();
    }
}

bool ControleMidia:: removerMidia(int codigo){
    
    auto it = pesquisarMidia(codigo);
    if(it != estoque.end()){
        delete *it;
        estoque.erase(it);
        std:: cout << "Filme "<< codigo << " removido com sucesso" << std:: endl;
        return true;
    }

    throw midia_excp::codigo_inexistente(codigo);

    return false; 
}
