#ifndef ARESTA_H
    #define ARESTA_H

    typedef struct aresta Aresta;

    Aresta* criaAresta(int, int, double);
    int retornaOrigem(Aresta*);
    int retornaDestino(Aresta*);
    double retornaPeso(Aresta*);
    void imprimeAresta(Aresta*);
    void liberaAresta(Aresta*);
#endif