#ifndef GRAFO_H
    #define GRAFO_h

    #include "lista.h"

    typedef struct grafo Grafo;

    Grafo* criaGrafo(int, int[], int[], int[], int, int, int);
    void insereAresta(Grafo*, int, Vertice*);
    void dijkstra(Grafo*);
    int retornaNumVertices(Grafo*);
    int retornaNumArestas(Grafo*);
    int* retornaServidores(Grafo*);
    int* retornaClientes(Grafo*);
    int* retornaMonitores(Grafo*);
    int retornaQtdServidores(Grafo*);
    int retornaQtdClientes(Grafo*);
    int retornaQtdMonitores(Grafo*);
    Lista** retornaListaAdj(Grafo*);
    void imprimeGrafo(Grafo*);
    void liberaGrafo(Grafo*);
#endif