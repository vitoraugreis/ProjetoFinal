#ifndef MIDIA_H
#define MIDIA_H

#include <string>

class Midia{
    
        int codigo;
        std :: string titulo;
        int unidadesDisponiveis;

    public:

<<<<<<< HEAD
        Midia(int codigo, std :: string titulo,int unidadesDisponiveis);
        virtual ~Midia() = default;
        int  getCodigo() ;
        std :: string getTitulo() ;
        int getUnidadesDisponiveis() ;
        virtual void imprimirInformacoes()=0;
=======
    Midia(int codigo, std :: string titulo,int unidadesDisponiveis);
    virtual ~Midia() = default;
    int  getCodigo() ;
    std :: string getTitulo() ;
    int getUnidadesDisponiveis() ;
    virtual void imprimirInformacoes(bool unidades = true) = 0;
    void diminuirUnidadesDisponiveis();
>>>>>>> bb1009676437935ee415a3256fe01e2d580bb18a
};





#endif