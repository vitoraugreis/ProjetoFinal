# Projeto Final PDS2
1. [Problema](https://github.com/vitoraugreis/ProjetoFinal#problema)
2. [Clientes](https://github.com/vitoraugreis/ProjetoFinal#clientes)
3. [ControleClientes](https://github.com/vitoraugreis/ProjetoFinal#controleclientes)
4. [Mídia](https://github.com/vitoraugreis/ProjetoFinal#mídia)
5. [Fita](https://github.com/vitoraugreis/ProjetoFinal#fita)
6. [Dvd](https://github.com/vitoraugreis/ProjetoFinal#dvd)
7. [ControleMidia](https://github.com/vitoraugreis/ProjetoFinal#controlemidia)
___
## Problema
${\color{yellow}Descrever \ problema}$

___

## Clientes
[Voltar ao início da documentação](https://github.com/vitoraugreis/ProjetoFinal#projeto-final-pds2) <br>
- TAD para representar o cliente da locadora de filmes.
- Possui como atríbutos o seu nome e CPF.
  <details>
    <summary><i>${\color{red}Clique \ para \ mostrar \ o \ código \ (Colocar \ no \ fim \ do \ projeto)}$</i></summary>
    
  </details>

### <ins>Construtor</ins>
- Constrói o Cliente de acordo com o nome e o CPF submetidos pelo usuário.
  <details>
    <summary><i>${\color{red}Clique \ para \ mostrar \ o \ código \ (Colocar \ no \ fim \ do \ projeto)}$</i></summary>
    
  </details>

### <ins>getNome</ins>
- Retorna o nome do cliente desejado.
  <details>
    <summary><i>Clique para mostrar o código</i></summary>
    
    ``` c++
    std::string Cliente::getNome(){
      return this->nome;
    }
    ```
  </details>

### <ins>getCPF</ins>
- Retorna o CPF do cliente desejado.
  <details>
    <summary><i>Clique para mostrar o código</i></summary>
  
    ``` c++
    std::string Cliente::getCPF(){
      return this->cpf;
    }
    ```
  </details>
  
___

## ControleClientes
[Voltar ao início da documentação](https://github.com/vitoraugreis/ProjetoFinal#projeto-final-pds2) <br>
- TAD que representa o sistema responsável por operações relacionadas aos clientes da locadora.
- Controla o banco de dados de clientes fazendo cadastros, remoções, relatórios e outras operações.
  <details>
    <summary><i>${\color{red}Clique \ para \ mostrar \ o \ código \ (Colocar \ no \ fim \ do \ projeto)}$</i></summary>
    
  </details>

### <ins>Construtor</ins>
- Lê o arquivo em que os clientes são armazenados `database/dbClientes.txt` e coloca todos em um vetor.
  <details>
    <summary><i>${\color{red}Clique \ para \ mostrar \ o \ código \ (Colocar \ no \ fim \ do \ projeto)}$</i></summary>
    
  </details>

### <ins>fazerCadastro</ins>
- Cria um cliente, antes conferindo se não há outro de mesmo cpf e se o cpf é válido, depois o adiciona ao vetor de clientes.
  <details>
    <summary><i>${\color{red}Clique \ para \ mostrar \ o \ código \ (Colocar \ no \ fim \ do \ projeto)}$</i></summary>
    
  </details>

### <ins>removerCadastro</ins>
- Deleta os dados de um cliente, conferindo antes se o cliente existe.
  <details>
    <summary><i>${\color{red}Clique \ para \ mostrar \ o \ código \ (Colocar \ no \ fim \ do \ projeto)}$</i></summary>
    
  </details>

### <ins>pesquisarCliente</ins>
- Confere se, entre os clientes existentes, existe um cliente com o cpf dado, caso exista, retorna o cliente.
  <details>
    <summary><i>${\color{red}Clique \ para \ mostrar \ o \ código \ (Colocar \ no \ fim \ do \ projeto)}$</i></summary>
    
  </details>

### <ins>gerarRelatorio</ins>
- Gera uma lista dos clientes existentes, ordenando eles por CPF ou por nome, de acordo com o usuário
  <details>
    <summary><i>${\color{red}Clique \ para \ mostrar \ o \ código \ (Colocar \ no \ fim \ do \ projeto)}$</i></summary>
    
  </details>

### <ins>limparDatabase</ins>
- Apaga os dados de todos os clientes cadastrados.
  <details>
    <summary><i>${\color{red}Clique \ para \ mostrar \ o \ código \ (Colocar \ no \ fim \ do \ projeto)}$</i></summary>
    
  </details>

### <ins>Destrutor</ins>
- Atualiza o banco de dados, encontrado no diretório `database/dbClientes.txt`, após todas as operações feitas pelo usuário do programa.
  <details>
    <summary><i>${\color{red}Clique \ para \ mostrar \ o \ código \ (Colocar \ no \ fim \ do \ projeto)}$</i></summary>
    
  </details>

___

## Mídia
[Voltar ao início da documentação](https://github.com/vitoraugreis/ProjetoFinal#projeto-final-pds2) <br>

___

## Fita
[Voltar ao início da documentação](https://github.com/vitoraugreis/ProjetoFinal#projeto-final-pds2) <br>

___

## DVD
[Voltar ao início da documentação](https://github.com/vitoraugreis/ProjetoFinal#projeto-final-pds2) <br>

___

## ControleMidia
[Voltar ao início da documentação](https://github.com/vitoraugreis/ProjetoFinal#projeto-final-pds2) <br>

___
