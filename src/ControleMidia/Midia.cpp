#include "Midia.hpp"
#include "ControleMidiaExceptions.hpp"

#include "iostream"

Midia::Midia(int codigo, std :: string titulo, int unidadesDisponiveis, std :: string categoria){
    this->codigo = codigo;
    this->titulo = titulo;
    this->unidadesDisponiveis = unidadesDisponiveis;
    this->categoriasValidas = {"Lancamento","Estoque", "Promocao", "FITA"};

    if (categoriasValidas.find(categoria) != categoriasValidas.end()) {
        this->categoria = categoria;
    } else {
        throw midia_excp::categoria_invalida(categoria);
            std::cout << "As categorias válidas são: " << std::endl;
        for (const auto& categoriaValida : categoriasValidas) {
            std::cout << categoriaValida << std::endl;
        }
    }
}

int Midia::getCodigo(){
    return codigo;
}

std:: string Midia::getCategoria(){
    return categoria;
}

std :: string Midia::getTitulo(){
    return titulo;
}

int Midia::getUnidadesDisponiveis(){
    return unidadesDisponiveis;
}

void Midia::diminuirUnidadesDisponiveis(){
    this->unidadesDisponiveis--;
}

void Midia::aumentarUnidadesDisponiveis(){
    this->unidadesDisponiveis++;
}