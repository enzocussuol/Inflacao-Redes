# Trabalho-2-de-ED2

- [x] Entender o trabalho.
- [X] Definir as estruturas.
- [ ] Dividir os trabalhos.
- [ ] Testar.
- [ ] trabalho pronto.

---

## Estruturas

1.  Struct Grafo { Vetor de Adjacências, int[] servidores, int [] clientes, int[] monitores, int nNertices, tamanhosDosVetores, int nArestas}
2.  VetorDeAdjacência (vetor de lista)
3.  Lista de nós (Com sentinela) {Célula (int noDestino, Double peso)}
4.  struct saida (int servidor, int cliente, double Inflação);
5.  saida[] saidas;

---

## Tads (Arquivos)
1. heap
2. grafo. Funções (Djisktra)
3. saida  (RTT, RRT*, double inflação)
4. lista
5. main

## Para fins de testes

A funcao imprimeGrafo() gera um arquivo grafo.dot. Para transformar esse arquivo em .png, basta rodar o comando no terminal (depois de ter executado o programa):

dot grafo.dot -Tpng -o nome.png

Esse arquivo .png estara na mesma pasta e ira fornecer uma visao grafica do grafo.