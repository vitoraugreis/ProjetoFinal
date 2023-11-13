#ifndef CADASTRO_MIDIA_H
#define CADASTRO_MIDIA_H

#include <string>
#include <vector>


class Midia{
    int codigo;
    std :: string titulo;
    int unidadesDisponiveis;

    public:

    Midia(int codigo, std :: string titulo,int unidadesDisponiveis);
    void getCodigo();
    std :: string getTitulo();
    int getUnidadesDisponiveis();
};

class Dvd : public Midia{
    std :: string categoria;

    public:
    Dvd(int codigo, std :: string titulo,int unidadesDisponiveis, std:: string categoria); 
    void getCategoria();

};

class Fita : public Midia{
    bool rebobinada;

    public:
    Fita(int codigo, std :: string titulo,int unidadesDisponiveis,bool rebobinada);
    bool getRebobinada();
};


class ControleMidia {
    
    std :: vector<Midia*> midias;

    public:
    ControleMidia();
    bool cadastrarMidia( Midia* novaMidia);
    bool lerArquivoCadastro(std :: string arquivo);
    bool pesquisarMidia(int codigo);
    bool removerMidia(int codigo);
    bool imprimirMidias();

};


#endif
