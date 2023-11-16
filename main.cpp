#include "controleClientes.hpp"

int main(){
    ControleClientes sla;
    /*sla.fazerCadastro("Glaucus Silva", "123456787");
    sla.fazerCadastro("Artur Silva", "123456787"); */
    sla.removerCadastro("123456781");
    sla.removerCadastro("1234");
    sla.gerarRelatorio();
    return 0;
}