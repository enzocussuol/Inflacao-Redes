#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct matriz{
    double** distancias; /*Matriz de distancias na qual a posicao de cada linha e coluna corresponde
    a um vertice do grafo*/
    int qtdLinhas, qtdColunas;
};

Matriz* criaMatriz(Grafo* grafo){
    Matriz* novaMatriz = (Matriz*) malloc(sizeof(Matriz));

    novaMatriz->qtdLinhas = retornaNumVertices(grafo);
    novaMatriz->qtdColunas = retornaNumVertices(grafo);

    /*Aloca espaço para nVertices linhas*/
    novaMatriz->distancias = (double**) malloc(sizeof(double*)*novaMatriz->qtdLinhas);

    /*Preenche as colunas com null*/
    for(int i = 0; i < novaMatriz->qtdLinhas; i++){
        novaMatriz->distancias[i] = NULL;
    }

    return novaMatriz;
}

static void preencheLinha(Matriz* matriz, Vertice** vertices, int linha){
    matriz->distancias[linha] = (double*) malloc(sizeof(double)*matriz->qtdColunas);
    /*Preenche cada coluna referente a uma linha com a distancia do vertice 
    entre o numero da linha e o numero da coluna*/
    for(int i = 0; i < matriz->qtdColunas; i++){
        matriz->distancias[linha][i] = retornaDistancia(vertices[i]);
    }
}

static void percorreGrupo(Matriz* matriz, Grafo* grafo, int* grupo, int qtdGrupo){
    Vertice** vertices;
    /*Preenche as linhas nas posicoes correspondentes ao numero dos vertices referentes
    ao vetor de servidor, clientes e monitores*/
    /*Linhas que nao correspondem a nenhum dos grupos a cima nao serao preenchidas*/
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

    /*Preencher as linhas das matrizes nas posicoes dos grupos servidores/clientes/monitores*/
    percorreGrupo(matriz, grafo, servidores, qtdServidores);
    percorreGrupo(matriz, grafo, clientes, qtdClientes);
    percorreGrupo(matriz, grafo, monitores, qtdMonitores);
}

double retornaElemento(Matriz* matriz, int i, int j){
    return matriz->distancias[i][j];
}

void liberaMatriz(Matriz* matriz){
    for(int i = 0; i < matriz->qtdLinhas; i++){
        if(matriz->distancias[i] != NULL) free(matriz->distancias[i]);
    }

    free(matriz->distancias);
    free(matriz);
}