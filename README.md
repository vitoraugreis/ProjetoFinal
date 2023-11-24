# Projeto Final
**Descrever problema**

___

## Clientes
**Colocar breve descrição**
<details>
  <summary><i>Clique para mostrar o cabeçalho (Colocar no fim do projeto)</i></summary>
</details>

### <ins>Construtor</ins>
<details>
  <summary><i>Clique para mostrar o código (Colocar no fim do projeto)</i></summary>
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
**Colocar descrição breve**
<details>
  <summary><i>Clique para mostrar o cabeçalho (Colocar no fim do projeto)</i></summary>
</details>

### <ins>Construtor</ins>
- Lê o arquivo em que os clientes são armazenados `../database/dbClientes.txt` e coloca todos em um vetor.
  <details>
    <summary><i>Clique para mostrar o código (Colocar no fim do projeto)</i></summary>
    
  </details>

### <ins>fazerCadastro</ins>
- Cria um cliente, antes conferindo se não há outro de mesmo cpf e se o cpf é válido, depois o adiciona ao vetor de clientes.
  <details>
    <summary><i>Clique para mostrar o código (Colocar no fim do projeto)</i></summary>
    
  </details>

### <ins>removerCadastro</ins>
- Deleta os dados de um cliente, conferindo antes se o cliente existe.
  <details>
    <summary><i>Clique para mostrar o código (Colocar no fim do projeto)</i></summary>
    
  </details>

### <ins>pesquisarCliente</ins>
  - Confere se, entre os clientes existentes, existe um cliente com o cpf dado, caso exista, retorna o cliente.
  <details>
    <summary><i>Clique para mostrar o código (Colocar no fim do projeto)</i></summary>
    
  </details>

### <ins>gerarRelatorio</ins>
  - Gera uma lista dos clientes existentes, ordenando eles por CPF ou por nome, de acordo com o usuário
  <details>
    <summary><i>Clique para mostrar o código (Colocar no fim do projeto)</i></summary>
    
  </details>

### <ins>limparDatabase</ins>
  - Apaga os dados de todos os clientes cadastrados.
  <details>
    <summary><i>Clique para mostrar o código (Colocar no fim do projeto)</i></summary>
    
  </details>

### <ins>Destrutor</ins>
  - Serve para apagar o que é feito pelo construtor, fecha a leitura e escrita do arquivo `../database/dbClientes.txt` , mas antes apaga os dados dos clientes dentro do arquivo.
  <details>
    <summary><i>Clique para mostrar o código (Colocar no fim do projeto)</i></summary>
    
  </details>
