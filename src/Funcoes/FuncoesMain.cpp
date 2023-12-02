#include <iostream>

using namespace std;

void menu(){
    cout << endl;
    cout << "----------------------------------------   MENU   ----------------------------------------" << endl << endl;
    cout << "LA + Nome_Arquivo                                 | Lê o arquivo de cadastro de mídia" << endl;
    cout << "CF + Tipo + Qntd + Código + Título + Categoria    | Cadastra um filme" << endl;
    cout << "RF + Código                                       | Remove um filme" << endl;
    cout << "LF + C || T                                       | Lista os filmes" << endl;
    cout << "CC + CPF + Nome                                   | Cadastra um cliente" << endl;
    cout << "RC + CPF                                          | Remove um cliente" << endl;
    cout << "LC + C || N                                       | Lista os clientes" << endl;
    cout << "LH + CPF                                          | Lista o histórico do cliente" << endl;
    cout << "AF + CPF + CódigoFilmes                           | Alugar Filme" << endl;
    cout << "DV + CPF                                          | Devolução de filmes" << endl;
    cout << "FS                                                | Finalizar sistema" << endl << endl; 
    cout <<  "------------------------------------------------------------------------------------------" << endl;
    cout << "Insira o comando desejada : ";
}