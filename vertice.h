#ifndef VERTICE_H
    #define VERTICE_H

    typedef struct vertice Vertice;

    Vertice* criaVertice(int, double);
    int retornaId(Vertice*);
    double retornaPeso(Vertice*);
    void imprimeVertice(Vertice*);
    void liberaVertice(Vertice*);
#endif