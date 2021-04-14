#ifndef VERTICE_H
    #define VERTICE_H

    #include "lista.h"

    typedef struct vertice Vertice;

    Vertice* criaVertice(int);
    void atualizaDistancia(Vertice*, double);
    int retornaId(Vertice*);
    double retornaDistancia(Vertice*);
    Lista* retornaListaAdj(Vertice*);
    void liberaVertice(Vertice*);
#endif