#ifndef VERTICE_H
    #define VERTICE_H

    #include "lista.h"

    typedef struct vertice Vertice;

    Vertice* criaVertice(int);
    void atualizaDistancia(Vertice*, int);
    int retornaId(Vertice*);
    double retornaDistancia(Vertice*);
    Lista* retornaListaAdj(Vertice*);
    void imprimeVertice(Vertice*);
    void liberaVertice(Vertice*);
#endif