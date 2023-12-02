/*public:
    double calculaAluguel(Midia &filme, double duracao);
    bool fazerLocacao(ControleClientes &cc, ControleMidia &cm, std::string cpf, std::vector<int> filmes);
    bool fazerDevolucao(ControleClientes &cc, ControleMidia &cm, std::string cpf);
};*/
#define DOCTEST_CONFIG_IMPLEMENT
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS
#include "../doctest.hpp"
#include "../../include/ControleLocacao/ControleLocacao.hpp"

TEST_CASE("Teste Cálculo Aluguel"){
    ControleLocacao Locacao;
    Dvd* novodvd=new Dvd(1,"Rocky",12,"Estoque");
    Fita* novafita=new Fita(2,"Django",3,TRUE);
    CHECK(Locacao.calculaAluguel(novodvd,20)==200);
    CHECK(Locacao.calculaAluguel(novafita,20)==5);

}

TEST_CASE("Teste fazer Locacao e devolucao"){
    ControleMidia estoque;
    ControleClientes clientes;
    ControleLocacao locacao;
    estoque.cadastrarMidia(1, 1,"Titanic",10, "Promocao");
    estoque.cadastrarMidia(2, 2,"Gladiator",32, "");
    estoque.cadastrarMidia(2, 3,"Django",10, "");
    estoque.cadastrarMidia(1, 4,"Jaws",6, "Promocao");
    cliente.fazerCadastro("Marcos","01234567890");
    cliente.fazerCadastro("Julio","11234567890");
    cliente.fazerCadastro("Castro","21234567890");
    cliente.fazerCadastro("Lindsay","31234567890");
     std::vector<int> filmesAlugados = {1, 2, 3};
    CHECK(locacao.fazerLocacao(clientes, estoque, "01234567890",filmesAlugados)==true);
    CHECK(controleLocacao.fazerDevolucao(clientes, estoque, "01234567890") == true);
}

