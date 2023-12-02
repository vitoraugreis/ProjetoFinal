#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../../include/ControleClientes/ControleClientes.hpp"
#include "../../include/ControleClientes/ControleClientesExceptions.hpp"

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
    REQUIRE(cliente.fazerCadastro("Júlio", "01234567890") == true);
}

TEST_CASE("Teste cadastro Cliente cpf repetido"){
    ControleClientes cliente;
    cliente.fazerCadastro("Marcos", "01234567890");
    REQUIRE_THROWS_AS(cliente.fazerCadastro("Júlio", "01234567890"), clientes_excp::cpf_repetido);
}

TEST_CASE("Teste cadastro Cliente cpf curto"){
    ControleClientes cliente;
    REQUIRE_THROWS_AS(cliente.fazerCadastro("Júlio", "01234"), clientes_excp::cpf_curto);
}

TEST_CASE("Teste remoção cliente"){
    ControleClientes cliente;
    cliente.fazerCadastro("Marcos", "01234567890");
    cliente.fazerCadastro("Julio", "11234567890");
    cliente.fazerCadastro("Castro", "21234567890");
    cliente.fazerCadastro("Lindsay", "31234567890");

    SECTION("Remover cliente válido"){
        REQUIRE(cliente.removerCadastro("11234567890") == true);
    }

    SECTION("Remoçao de cliente inválido"){
        REQUIRE_THROWS_AS(cliente.removerCadastro("91234567899"), clientes_excp::cpf_inexistente);
    }
}

TEST_CASE("Gerar Relatório"){
    ControleClientes cliente;
    cliente.fazerCadastro("Marcos", "01234567890");
    cliente.fazerCadastro("Julio", "11234567890");
    cliente.fazerCadastro("Castro", "21234567890");
    cliente.fazerCadastro("Lindsay", "31234567890");

    SECTION("Teste ordem por cpf"){
        std::string expected_output = "01234567890 Marcos\n11234567890 Julio\n21234567890 Castro\n31234567890 Lindsay\n";
        std::string actual_output = capture_stdout(cliente, 'C');
        REQUIRE(actual_output == expected_output);
        REQUIRE(cliente.gerarRelatorio('C') == true);
    }

    SECTION("Teste ordem por nome"){
        std::string expected_output = "21234567890 Castro\n11234567890 Julio\n31234567890 Lindsay\n01234567890 Marcos\n";
        std::string actual_output = capture_stdout(cliente, 'N');
        REQUIRE(actual_output == expected_output);
        REQUIRE(cliente.gerarRelatorio('N') == true);
    }

    SECTION("Teste ordem inválida"){
        REQUIRE_THROWS_AS(cliente.gerarRelatorio('R'), clientes_excp::ordem_invalida);
    }
}
