#include <stdio.h>
#include <stdlib.h>
#include "vertice.h"

struct vertice{
    int id;
    double distancia;
    Lista* listaAdj;
};

Vertice* criaVertice(int id){
    Vertice* novoVertice = (Vertice*) malloc(sizeof(Vertice));

    novoVertice->id = id;
    novoVertice->distancia = __INT_MAX__;
    novoVertice->listaAdj = lista_cria();

    return novoVertice;
}

void atualizaDistancia(Vertice* vertice, double distancia){
    vertice->distancia = distancia;
}

int retornaId(Vertice* vertice){
    return vertice->id;
}

double retornaDistancia(Vertice* vertice){
    return vertice->distancia;
}

Lista* retornaListaAdj(Vertice* vertice){
    return vertice->listaAdj;
}

void liberaVertice(Vertice* vertice){
    lista_libera(vertice->listaAdj);
    free(vertice);
}