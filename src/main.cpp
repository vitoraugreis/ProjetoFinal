#include "ControleMidia.hpp"
#include "Cliente.hpp"
#include "ControleClientes.hpp"
#include "Dvd.hpp"
#include "Fita.hpp"
#include "Midia.hpp"
#include <iostream>


int main(){
    // ControleClientes sla;
    // //sla.fazerCadastro("Bernardo Costa", "99999999999");
    // //sla.gerarRelatorio('N');
    // sla.removerCadastro("99999999999");
    // sla.gerarRelatorio('N');

    ControleMidia estoque;

    estoque.cadastrarDvd(101, "O Senhor dos Anéis", 20, "Fantasia");
    estoque.cadastrarDvd(102, "Pulp Fiction", 15, "Crime");
    estoque.cadastrarFita(201, "Casablanca", 30, true);
    estoque.cadastrarFita(202, "E o Vento Levou", 25, false);
    estoque.cadastrarDvd(103, "Matrix", 18, "Ficção Científica");
    estoque.cadastrarFita(203, "O Poderoso Chefão", 22, true);
    estoque.cadastrarDvd(104, "Interestelar", 12, "Ficção Científica");
    estoque.cadastrarFita(204, "O Silêncio dos Inocentes", 27, false);
    estoque.cadastrarDvd(105, "Gladiador", 14, "Ação");
    estoque.cadastrarFita(205, "Cidadão Kane", 31, true);
    estoque.cadastrarFita(205, "Cidadão Kane", 31, true);
    estoque.cadastrarDvd(103, "Matrix", 18, "Ficção Científica");
    estoque.pesquisarMidia(205);
    estoque.pesquisarMidia(19);
    estoque.imprimirMidias();
    estoque.removerMidia(205);
    estoque.removerMidia(19);
    estoque.imprimirMidias();


    return 0;
}