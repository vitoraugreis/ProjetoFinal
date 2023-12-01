#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "ControleMidia.hpp"
#include "ControleMidiaExceptions.hpp"

std::string capture_stdout(ControleMidia& estoque, char ordem) {
    std::ostringstream oss;
    std::streambuf* coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    estoque.imprimirMidias(ordem);  

    std::cout.rdbuf(coutbuf);  
    return oss.str();
}

TEST_CASE("Teste cadastro Midia/DVD correto"){
    ControleMidia estoque;
    CHECK(estoque.cadastrarMidia(1, 1,"Titanic",10, "Promocao")==true) ;
}

TEST_CASE("Teste cadastro Midia/DVD codigo repetido"){
    ControleMidia estoque;
    estoque.cadastrarMidia(1, 1,"Matrix",10, "Lancamento");
    CHECK_THROWS_AS(estoque.cadastrarMidia(1, 1,"Titanic",4, "Promocao"),midia_excp::codigo_repetido) ;

}

TEST_CASE("Teste cadastro Midia/Fita correto"){
    ControleMidia estoque;
    CHECK(estoque.cadastrarMidia(2, 10,"Gladiator",32, "")==true) ;
}

TEST_CASE("Teste cadastro Midia/Fita codigo repetido"){
    ControleMidia estoque;
    estoque.cadastrarMidia(2, 20,"Django",10, "");
    CHECK_THROWS_AS(estoque.cadastrarMidia(2, 10,"Django",9, ""),midia_excp::codigo_repetido) ;

}

TEST_CASE("Teste cadastro tipo desconhecido de midia"){
    ControleMidia estoque;
    CHECK_THROWS_AS(estoque.cadastrarMidia(4, 3,"Jaws",6, "Promocao"),midia_excp::tipo_desconhecido) ;

}

TEST_CASE("Teste pesquisa de midia"){
    
    ControleMidia estoque;
    estoque.cadastrarMidia(1, 1,"Titanic",10, "Promocao");
    estoque.cadastrarMidia(2, 2,"Gladiator",32, "");
    estoque.cadastrarMidia(2, 3,"Django",10, "");
    estoque.cadastrarMidia(1, 4,"Jaws",6, "Promocao");

    SUBCASE("Pesquisa de código válido"){
        CHECK(estoque.pesquisarMidia(2)!= estoque.getEstoqueEnd());
    }

    SUBCASE("Pesquisa de código inválido"){
        CHECK(estoque.pesquisarMidia(10)== estoque.getEstoqueEnd());
    }
}   

TEST_CASE("Teste remover midia"){
    
    ControleMidia estoque;
    estoque.cadastrarMidia(1, 1,"Titanic",10, "Promocao");
    estoque.cadastrarMidia(2, 2,"Gladiator",32, "");
    estoque.cadastrarMidia(2, 3,"Django",10, "");
    estoque.cadastrarMidia(1, 4,"Jaws",6, "Promocao");

    SUBCASE("Remover mídia válida"){
        CHECK(estoque.removerMidia(2)==true);
    }

    SUBCASE("Remoçao de código inválido"){
        CHECK_THROWS_AS(estoque.removerMidia(10),midia_excp::codigo_inexistente);
    }
}   

TEST_CASE("Teste imprimir mídias"){
    
    ControleMidia estoque;
    estoque.cadastrarMidia(1, 1,"Titanic",10, "Promocao");
    estoque.cadastrarMidia(2, 2,"Gladiator",32, "");
    estoque.cadastrarMidia(2, 3,"Django",10, "");
    estoque.cadastrarMidia(1, 4,"Jaws",6, "Promocao");
    
    SUBCASE("Teste ordem por código"){
        std::string expected_output = "1 Titanic 10 DVD\n2 Gladiador 32 FITA\n3 Django 10 FITA\n4 Jaws 6 DVD\n";
        std::string actual_output = capture_stdout(estoque, 'C');
        CHECK(actual_output == expected_output);
    }
    
     SUBCASE("Teste ordem por título"){
        std::string expected_output = "3 Django 10 FITA\n2 Gladiador 32 FITA\n4 Jaws 6 DVD\n1 Titanic 10 DVD\n";
        std::string actual_output = capture_stdout(estoque, 'T');
        CHECK(actual_output == expected_output);
    }
    
    SUBCASE("Teste ordem inválida"){
        CHECK_THROWS_AS(estoque.imprimirMidias('R'), midia_excp::ordem_invalida);
    }
    
}


TEST_CASE("Teste de leitura bem-sucedida do arquivo de cadastro") {
    ControleMidia estoque;


    CHECK_NOTHROW(estoque.lerArquivoCadastro("dbMidia.txt"));

    std:: vector<Midia*> vetor = estoque.getEstoque();
    REQUIRE(vetor.size()== 3);

    REQUIRE(vetor[0]->getCodigo() == 101);
    REQUIRE(vetor[0]->getTitulo() == "Filme1");
    REQUIRE(vetor[0]->getUnidadesDisponiveis() == 20);
    REQUIRE(dynamic_cast<Dvd*>(vetor[0])->getCategoria() == "Lancamento");

    REQUIRE(vetor[0]->getCodigo() == 102);
    REQUIRE(vetor[0]->getTitulo() == "Fita1");
    REQUIRE(vetor[0]->getUnidadesDisponiveis() == 15);

    REQUIRE(vetor[0]->getCodigo() == 103);
    REQUIRE(vetor[0]->getTitulo() == "Filme2");
    REQUIRE(vetor[0]->getUnidadesDisponiveis() == 30);
    REQUIRE(dynamic_cast<Dvd*>(vetor[0])->getCategoria() == "Estoque");

    
}

TEST_CASE("Teste de erro de abertura de arquivo") {
    ControleMidia estoque;

    std::string arquivoInexistente = "arquivo_inexistente.txt";

    CHECK_THROWS_AS(estoque.lerArquivoCadastro(arquivoInexistente), midia_excp::erro_de_abertura);
}

