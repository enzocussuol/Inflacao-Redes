#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct matriz{
    double** distancias;
    int qtdLinhas, qtdColunas;
};

Matriz* criaMatriz(Grafo* grafo){
    Matriz* novaMatriz = (Matriz*) malloc(sizeof(Matriz));

    novaMatriz->qtdLinhas = retornaNumVertices(grafo);
    novaMatriz->qtdColunas = retornaNumVertices(grafo);

    novaMatriz->distancias = (double**) malloc(sizeof(double*)*novaMatriz->qtdLinhas);

    for(int i = 0; i < novaMatriz->qtdLinhas; i++){
        novaMatriz->distancias[i] = NULL;
    }

    return novaMatriz;
}

static void preencheLinha(Matriz* matriz, Vertice** vertices, int linha){
    matriz->distancias[linha] = (double*) malloc(sizeof(double)*matriz->qtdColunas);

    for(int i = 0; i < matriz->qtdColunas; i++){
        matriz->distancias[linha][i] = retornaDistancia(vertices[i]);
    }
}

static void percorreGrupo(Matriz* matriz, Grafo* grafo, int* grupo, int qtdGrupo){
    Vertice** vertices;

    for(int i = 0; i < qtdGrupo; i++){
        dijkstra(grafo, grupo[i]);
        vertices = retornaVertices(grafo);

        preencheLinha(matriz, vertices, grupo[i]);
    }
}

void preencheMatriz(Matriz* matriz, Grafo* grafo){
    int* servidores = retornaServidores(grafo);
    int* clientes = retornaClientes(grafo);
    int* monitores = retornaMonitores(grafo);

    int qtdServidores = retornaQtdServidores(grafo);
    int qtdClientes = retornaQtdClientes(grafo);
    int qtdMonitores = retornaQtdMonitores(grafo);

    percorreGrupo(matriz, grafo, servidores, qtdServidores);
    percorreGrupo(matriz, grafo, clientes, qtdClientes);
    percorreGrupo(matriz, grafo, monitores, qtdMonitores);
}

double retornaElemento(Matriz* matriz, int i, int j){
    return matriz->distancias[i][j];
}

void imprimeMatriz(Matriz* matriz){
    for(int i = 0; i < matriz->qtdLinhas; i++){
        if(matriz->distancias[i] != NULL){
            for(int j = 0; j < matriz->qtdColunas; j++){
                printf("%lf ", matriz->distancias[i][j]);
            }
            printf("\n");
        }
    }
}

void liberaMatriz(Matriz* matriz){
    for(int i = 0; i < matriz->qtdLinhas; i++){
        if(matriz->distancias[i] != NULL) free(matriz->distancias[i]);
    }

    free(matriz->distancias);
    free(matriz);
}