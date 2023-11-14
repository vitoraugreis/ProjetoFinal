#include "controleClientes.hpp"

int main(){
    ControleClientes sla;
    sla.fazerCadastro("a", 1);
    sla.fazerCadastro("b", 2);
    sla.fazerCadastro("c",34);
    sla.pesquisarCliente(34);
    sla.removerCadastro(34);
    sla.gerarRelatorio();
    return 0;
}