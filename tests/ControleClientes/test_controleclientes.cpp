#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS
#include "../doctest.hpp"
#include "../include/ControleClientes/ControleClientes.hpp"
#include "../include/ControleClientes/ControleClientesExceptions.hpp"

std::string capture_stdout(ControleClientes& clientes, char ordem) {
    std::ostringstream oss;
    std::streambuf* coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    clientes.gerarRelatorio(ordem);  

    std::cout.rdbuf(coutbuf);  
    return oss.str();
}

TEST_CASE("Teste cadastro Cliente correto"){
    ControleClientes cliente;
    CHECK(cliente.fazerCadastro("Júlio","01234567890")==true) ;
}

TEST_CASE("Teste cadastro Cliente cpf repetido"){
    ControleClientes cliente;
    cliente.fazerCadastro("Marcos","01234567890");
    CHECK_THROWS_AS(cliente.fazerCadastro("Júlio","01234567890"),clientes_excp::cpf_repetido);

}

TEST_CASE("Teste cadastro Cliente cpf curto"){
    ControleClientes cliente;
    CHECK_THROWS_AS(cliente.fazerCadastro("Júlio","01234"),clientes_excp::cpf_curto);
}

TEST_CASE("Teste remoção cliente"){
    
    ControleClientes cliente;
    cliente.fazerCadastro("Marcos","01234567890");
    cliente.fazerCadastro("Julio","11234567890");
    cliente.fazerCadastro("Castro","21234567890");
    cliente.fazerCadastro("Lindsay","31234567890");

    SUBCASE("Remover cliente válido"){
        CHECK(cliente.removerCadastro("11234567890")==true);
    }

    SUBCASE("Remoçao de cliente inválido"){
        CHECK_THROWS_AS(cliente.removerCadastro("91234567899"),clientes_excp::cpf_inexistente);
    }
}  

TEST_CASE("Gerar Relatório"){
    ControleClientes cliente;
    cliente.fazerCadastro("Marcos","01234567890");
    cliente.fazerCadastro("Julio","11234567890");
    cliente.fazerCadastro("Castro","21234567890");
    cliente.fazerCadastro("Lindsay","31234567890");

    SUBCASE("Teste ordem por cpf"){
        std::string expected_output = "01234567890 Marcos\n11234567890 Julio\n21234567890 Castro\n31234567890 Lindsay\n";
        std::string actual_output = capture_stdout(cliente, 'C');
        CHECK(actual_output == expected_output);
        CHECK(cliente.gerarRelatorio('C')==true);
    }
    
     SUBCASE("Teste ordem por nome"){
        std::string expected_output = "21234567890 Castro\n11234567890 Julio\n31234567890 Lindsay\n01234567890 Marcos\n";
        std::string actual_output = capture_stdout(cliente, 'N');
        CHECK(actual_output == expected_output);
        CHECK(cliente.gerarRelatorio('N')==true);
    }
    
    SUBCASE("Teste ordem inválida"){
        CHECK_THROWS_AS(cliente.gerarRelatorio('R'), clientes_excp::ordem_invalida);
    }

}


