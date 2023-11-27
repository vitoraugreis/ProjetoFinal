#include "ControleMidia.hpp"
#include "ControleMidiaExceptions.hpp"
#include "Cliente.hpp"
#include "ControleClientes.hpp"
#include "ControleClientesExceptions.hpp"
#include "Dvd.hpp"
#include "Fita.hpp"
#include "Midia.hpp"

#include <iostream>
#include <sstream>

int main(){
    std::string nome_arquivo_cadastro;
    std::string titulo;
    std::string categoria;
    std::string input;
    std::string comando;
    std::string nome;
    std::string cpf;
    int tipo_midia;
    int quantidade;
    int codigo;
    int aux = 0;

    ControleMidia estoque;
    ControleClientes clientes;

    while (true) {
        std::getline(std::cin, input);

        if (input.empty()) {
            if (aux == 0){
            aux = 1;
            continue;
            } else{
                break;
            }
        }

        std::istringstream stream(input);
        stream >> comando;

        try {
        if (comando == "LA"){ // Ler Arquivo de Cadastro
            stream >> nome_arquivo_cadastro;
            
            estoque.lerArquivoCadastro(nome_arquivo_cadastro);

        } else if (comando == "CF"){ // Cadastrar Filme
            stream >> tipo_midia >> quantidade >> codigo >> titulo >> categoria;

            std::cout << tipo_midia << quantidade << codigo << titulo << categoria;
            
            estoque.cadastrarMidia(tipo_midia, codigo, titulo, quantidade, categoria);

        } else if (comando == "RF"){ // Remover Filme
            stream >> codigo;

            estoque.removerMidia(codigo);

        } else if (comando == "LF"){ // Listar Filmes ordenados por Código ou Título
            char ordem;
            stream >> ordem;

            estoque.imprimirMidias(ordem);

        } else if (comando == "CC"){ // Cadastrar Cliente
            stream >> cpf >> nome;

            // clientes.fazerCadastro(nome, cpf, true);

        } else if (comando == "RC"){ // Remover Cliente
            stream >> cpf;

            //clientes.removerCadastro(cpf);

        } else if (comando == "LC"){ // Listar //clientes ordenados por Código ou Nome
            char ordem;
            stream >> ordem;

            //clientes.gerarRelatorio(ordem);

        } else if (comando == "AF"){ // Aluguel Filme
            char ordem;
            stream >> ordem;

            //clientes.gerarRelatorio(ordem);

        } else if (comando == "AF"){ // Aluguel Filme (INCOMPLETO)
            char ordem;
            stream >> ordem;


        } else if (comando == "DV"){ // Devolução Filme (INCOMPLETO)
            char ordem;
            stream >> ordem;


        } else if (comando == "FS"){ // Finalizar Sistema
            break;

        }
        } catch (midia_excp::ordem_invalida &e){
            std::cerr << e.what() << std::endl;
        } catch (midia_excp::codigo_repetido &e) {
            std::cerr << e.what() << std::endl;
        } catch (midia_excp::codigo_inexistente &e) {
            std::cerr << e.what() << std::endl;
        } catch (midia_excp::tipo_desconhecido &e) {
            std::cerr << e.what() << ": " << e.get_tipo() << std::endl;
        } catch (midia_excp::erro_de_abertura &e) {
            std::cerr << e.what() << ": " << e.get_arquivo() << std::endl;
        } catch (clientes_excp::ordem_invalida &e){
            std::cerr << e.what() << std::endl;
        } catch (clientes_excp::cpf_curto &e) {
            std::cerr << e.what() << std::endl;
        } catch (clientes_excp::cpf_repetido &e) {
            std::cerr << e.what() << std::endl;
        } catch (clientes_excp::cpf_inexistente &e) {
            std::cerr << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }

    return 0;
}


    

   