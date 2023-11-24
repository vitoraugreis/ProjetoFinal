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
