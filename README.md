# Projeto Final PDS2

## Documentação
A documentação do projeto está localizada em docs/html. Deve ser acessada diretamento pelo arquivo index.html.

Isso abrirá a documentação em seu navegador padrão, permitindo que você explore e entenda melhor o projeto.

## Problema

Uma vídeo-locadora entrou em contato com nosso grupo pedindo a criação de um sistema que possibilite um melhor controle de toda a loja. Este sistema deveria ser capaz de :
- Gerenciar o estoque de filmes;
- Gerenciar os clientes da vídeo-locadora;
- Gerenciar os aluguéis de filmes;
- Calcular automáticamente o quanto o cliente deve pagar na devolução dos filmes.

## Solução

Após reuniões, discussões e criação de CRCs, o grupo definiu como o projeto seria feito e suas características:
- O sistema será programado em linguagem C++;
- Teremos um módulo do sistema responsável apenas pelo Controle de Clientes;
- Teremos um módulo responsável somente pelo Controle das Mídias da locadora;
- E um módulo responsável pela locação, devolução e cálculo de pagamento.

### Controle dos Clientes

- O módulo de controle de clientes é responsável por controlar o banco de dados de clientes da loja, assim como gerar relatórios.
- Cada cliente possui como característica única o seu CPF, que é armazenado junto de seu nome.
- Estes clientes são armazenados em um vetor, onde é possível fazer remoções, adições (cadastros), e outras operações.

### Controle das Mídias

- O módulo de controle de mídias é responsável por todo o gerenciamento do estoque da vídeo-locadora.
- Através dele é possível adicionar, remover, atualizar quantidades disponíveis, gerar relatórios, e outras funções.
- A video-locadora possui dois tipos de mídias, cada um com suas categorias e valor:
  - Dvd → Lançamento: 20R$ p/dia || Estoque: 10R$ p/dia || Promoção: 10R$ fixo
  - Fita → Rebobinada: 5R$ fixo || Não rebobinada: 5R$ fixo + Multa de 2R$
- As mídias são todas armazenadas em um vetor, onde é possível fazer todas as operações necessárias.

### Controle das locações

- O módulo de controle de locações é responsável por fazer as locações das mídias e calcular o preço final do aluguel para o cliente.
- No ato da locação, o sistema atualiza a quantidade disponível da mídia no banco de dados.
- Na devolução, o sistema calcula automaticamente o preço final, de acordo com o preço de cada mídia, e retorna ao cliente.
  - Também é feita a atualização da quantidade da mídia no estoque.
- O sistema foi implementado usando a estutura de dados "unordered_map"
  - Através dela é possível fazer a relação cliente → mídias.
  - A chave da estrutura é o cliente, já o valor é um vetor de mídias, que se refere as mídias alugadas pelo cliente.
  - Não é necessária a ordenação da estrutura, por isso optamos pela "unordered_map" ao invés do "map". Isso faz com que o sistema use menos memória.

## Dificuldades no desenvolvimento

O desenvolvimento do código em si foi tranquilo, porém encontramos uma grande dificuldade na hora de fazer os testes do programa.
