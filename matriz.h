#ifndef MATRIZ_H
    #define MATRIZ_H

    #include "grafo.h"

    typedef struct matriz Matriz;

    Matriz* criaMatriz(Grafo*);
    void preencheMatriz(Matriz*, Grafo*);
    double retornaElemento(Matriz*, int, int);
    void liberaMatriz(Matriz*);
#endif