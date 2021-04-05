#include <stdio.h>
#include <stdlib.h>
#include "aresta.h"

struct aresta{
    int origem, destino;
    double peso;
};

Aresta* criaAresta(int origem, int destino, double peso){
    Aresta* novaAresta = (Aresta*) malloc(sizeof(Aresta));

    novaAresta->origem = origem;
    novaAresta->destino = destino;
    novaAresta->peso = peso;

    return novaAresta;
}

int retornaOrigem(Aresta* aresta){
    return aresta->origem;
}

int retornaDestino(Aresta* aresta){
    return aresta->destino;
}

double retornaPeso(Aresta* aresta){
    return aresta->peso;
}

void imprimeAresta(Aresta* aresta){
    printf("Origem: %d, Destino: %d, Peso: %.02lf\n", aresta->origem, aresta->destino, aresta->peso);
}

void liberaAresta(Aresta* aresta){
    free(aresta);
}