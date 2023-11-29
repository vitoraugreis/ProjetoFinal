#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 
#include "doctest.h"
#include "ControleMidia.hpp"
#include "ControleMidiaExceptions.hpp"


TEST_CASE("Teste cadastro Midia/DVD correto"){
    ControleMidia estoque;
    CHECK(estoque.cadastrarMidia(1, 1,"Titanic",10, "Promocao")==true) ;
}

TEST_CASE("Teste cadastro Midia/DVD codigo repetido"){
    ControleMidia estoque;
    estoque.cadastrarMidia(1, 1,"Kill Bill",10, "Lancamento");
    CHECK_THROWS_AS(estoque.cadastrarMidia(1, 1,"Titanic",4, "Promocao"),midia_excp::codigo_repetido) ;

}

TEST_CASE("Teste cadastro Midia/Fita correto"){
    ControleMidia estoque;
    CHECK(estoque.cadastrarMidia(2, 10,"Senhor dos Anéis",32, "Estoque")==true) ;
}

TEST_CASE("Teste cadastro Midia/Fita codigo repetido"){
    ControleMidia estoque;
    estoque.cadastrarMidia(2, 20,"Kill Bill",10, "Lancamento");
    CHECK_THROWS_AS(estoque.cadastrarMidia(2, 10,"Django",9, "Promocao"),midia_excp::codigo_repetido) ;

}

TEST_CASE("Teste cadastro tipo desconhecido de midia"){
    ControleMidia estoque;
    CHECK_THROWS_AS(estoque.cadastrarMidia(4, 3,"Mad Max",6, "Promocao"),midia_excp::tipo_desconhecido) ;

}

TEST_CASE("Teste remover mídia"){
    ControleMidia estoque;
    estoque.cadastrarMidia(201, "Casablanca", 30, true);
    estoque.cadastrarMidia(103, "Matrix", 18, "Ficção Científica");
    estoque.cadastrarMidia(105, "Gladiador", 14, "Ação");
    estoque.cadastrarMidia(205, "Cidadão Kane", 31, true);

}



