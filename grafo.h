#ifndef GRAFO_H
    #define GRAFO_h

    #include "vertice.h"
    #include "fila.h"

    typedef struct grafo Grafo;

    Grafo* criaGrafo(int, int, int[], int[], int[], int, int, int);
    void dijkstra(Grafo*, int);
    void insereAresta(Grafo*, Aresta*);
    int retornaNumVertices(Grafo*);
    int retornaNumArestas(Grafo*);
    int* retornaServidores(Grafo*);
    int* retornaClientes(Grafo*);
    int* retornaMonitores(Grafo*);
    int retornaQtdServidores(Grafo*);
    int retornaQtdClientes(Grafo*);
    int retornaQtdMonitores(Grafo*);
    Vertice** retornaVertices(Grafo*);
    void imprimeGrafo(Grafo*);
    void liberaGrafo(Grafo*);
#endif