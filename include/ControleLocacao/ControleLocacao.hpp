#ifndef CONTROLE_LOCACAO_H
#define CONTROLE_LOCACAO_H

#include "ControleClientes.hpp"
#include "ControleMidia.hpp"
#include <string>
#include <vector>
#include <unordered_map> 

class ControleLocacao{

    std::unordered_map<Cliente*, std::vector<Midia*>> locacoes;

public:
    bool fazerLocacao(ControleClientes &cc, ControleMidia &cm, std::string cpf, std::vector<int> filmes);
};

#endif