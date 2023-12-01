/*public:
    double calculaAluguel(Midia &filme, double duracao);
    bool fazerLocacao(ControleClientes &cc, ControleMidia &cm, std::string cpf, std::vector<int> filmes);
    bool fazerDevolucao(ControleClientes &cc, ControleMidia &cm, std::string cpf);
};*/
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS
#include "../doctest.hpp"
#include "../include/ControleLocacao/ControleLocacao.hpp"

TEST_CASE("Teste Cálculo Aluguel"){
    ControleLocacao Locacao;
    Dvd* novodvd=new Dvd(1,"Rocky",12,"Estoque");
    Fita* novafita=new Fita(2,"Django",3,TRUE);
    CHECK(Locacao.calculaAluguel(novodvd,20)==200);
    CHECK(Locacao.calculaAluguel(novafita,20)==5);

}

TEST_CASE("Teste fazer Locacao"){
    ControleMidia estoque;
    estoque.cadastrarMidia(1, 1,"Titanic",10, "Promocao");
    estoque.cadastrarMidia(2, 2,"Gladiator",32, "");
    estoque.cadastrarMidia(2, 3,"Django",10, "");
    estoque.cadastrarMidia(1, 4,"Jaws",6, "Promocao");

}

TEST_CASE("Teste Fazer Devolução"){

}
