#ifndef CONTROLE_MIDIA_H
#define CONTROLE_MIDIA_H

#include "Midia.hpp"
#include "Dvd.hpp"
#include "Fita.hpp"
#include <vector>

class ControleMidia {
    std :: vector<Midia*> estoque;

    public:
    ControleMidia();
    ~ControleMidia();  
    bool cadastrarDvd(int codigo, std :: string titulo,int unidadesDisponiveis, std:: string categoria);
    bool cadastrarFita(int codigo, std :: string titulo,int unidadesDisponiveis, bool rebobinada);
    bool lerArquivoCadastro(std :: string arquivo);
    std::vector<Midia *>::iterator pesquisarMidia(int codigo);
    bool removerMidia(int codigo);
    void imprimirMidias();

};



#endif
