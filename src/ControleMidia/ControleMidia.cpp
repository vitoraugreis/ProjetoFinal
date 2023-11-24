#include "ControleMidia.hpp"
#include <fstream>
#include <iostream>

ControleMidia:: ControleMidia(): estoque(){}

ControleMidia:: ~ControleMidia(){
    
    for(auto it = this->estoque.begin(); it != this->estoque.end(); it++){
        
        delete (*it);
    }
}

bool ControleMidia::cadastrarDvd(int codigo, std::string titulo, int unidadesDisponiveis, std::string categoria) {
    
    auto it = this->pesquisarMidia(codigo);

    
    if(it == this->estoque.end()){
        Dvd* novoDvd = new Dvd(codigo, titulo, unidadesDisponiveis, categoria);

        estoque.push_back(novoDvd);
        std:: cout << "Filme "<< codigo << " cadastrado com sucesso" << std:: endl;
        return true;
    }

    
    std:: cout << "ERRO:codigo repetido" << std:: endl;
    return false;

}

bool ControleMidia::cadastrarFita(int codigo, std::string titulo, int unidadesDisponiveis, bool rebobinada) {

    auto it = this->pesquisarMidia(codigo);

    
    if(it == this->estoque.end()){
        Fita* novaFita = new Fita(codigo, titulo, unidadesDisponiveis, rebobinada);
        //true rebobinada, false nao rebobinada
        estoque.push_back(novaFita);
        std:: cout << "Filme "<< codigo << " cadastrado com sucesso" << std:: endl;
        return true;
    }

    std:: cout << "ERRO:codigo repetido" << std:: endl;
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
    
    for(auto it = this->estoque.begin(); it != this->estoque.end(); it++){
        if(codigo == (*it)->getCodigo()){
            
            return it;
        }
    }

    return this->estoque.end();
}


void ControleMidia::imprimirMidias() {
    for(auto it = this->estoque.begin(); it != this->estoque.end(); it++){
        (*it)->imprimirInformacoes();
    }
}




bool ControleMidia:: removerMidia(int codigo){
    
    auto it = this->pesquisarMidia(codigo);
    if(it != this->estoque.end()){
        delete *it;
        this->estoque.erase(it);
        std:: cout << "Filme "<< codigo << " removido com sucesso" << std:: endl;
        return true;
    }

    std::cout << "ERRO:codigo inexistente" << std::endl;
    return false; 
}
