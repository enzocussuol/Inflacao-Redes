#include <stdio.h>
#include <stdlib.h>
#include "vertice.h"

struct vertice{
    int id;
    double peso;
};

Vertice* criaVertice(int id, double peso){
    Vertice* novoVertice = (Vertice*) malloc(sizeof(Vertice));

    novoVertice->id = id;
    novoVertice->peso = peso;

    return novoVertice;
}

int retornaId(Vertice* vertice){
    return vertice->id;
}

double retornaPeso(Vertice* vertice){
    return vertice->peso;
}

void imprimeVertice(Vertice* vertice){
    printf("%d %0.1lf\n", vertice->id, vertice->peso);
}

void liberaVertice(Vertice* vertice){
    free(vertice);
}