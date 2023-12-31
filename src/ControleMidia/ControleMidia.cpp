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

std::vector<Midia*> ControleMidia::getEstoque(){
    
    return estoque;
}

std::vector<Midia*>::iterator ControleMidia::getEstoqueEnd(){
        
        return estoque.end();

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
        case 2: {  //Fita
            bool rebobinada = 1;
            cadastrarFita(codigo, titulo, unidadesDisponiveis, rebobinada);
            break;}
        default:
            throw midia_excp::tipo_desconhecido(tipoMidia);
            break;
        }
    return false;

}

bool ControleMidia::lerArquivoCadastro(std::string arquivo) {
    std::ifstream infile(arquivo);

    if (!infile) {
        throw midia_excp::erro_de_abertura(arquivo);
        return false;
    }

    int tipoMidia; 
    std::string categoria;

    while (infile >> tipoMidia) {
        int codigo;
        std::string titulo;
        int unidadesDisponiveis;

        // lê a primeira coluna do dbMidia e procura o tipo midia

        try {
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
                throw midia_excp::tipo_desconhecido(tipoMidia);
                break;
        }} catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
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

    } else {
        throw midia_excp::ordem_invalida(ordem);
    }

    for(auto it = this->estoque.begin(); it != this->estoque.end(); it++){
        (*it)->imprimirInformacoes();
    }
    if (estoque.size() == 0 ){
        std::cout << "Nenhuma mídia armazenada" << std::endl;
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
