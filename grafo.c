#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "grafo.h"

struct grafo{
    int numVertices, numArestas;
    int* servidores;
    int* clientes;
    int* monitores;
    int qtdServidores, qtdClientes, qtdMonitores;
    Vertice** vertices;
};

Grafo* criaGrafo(int numVertices, int numArestas, int servidores[], int clientes[], int monitores[], int qtdServidores, int qtdClientes, int qtdMonitores){
    Grafo* novoGrafo = (Grafo*) malloc(sizeof(Grafo));

    novoGrafo->numVertices = numVertices;
    novoGrafo->numArestas = numArestas;

    novoGrafo->servidores = servidores;
    novoGrafo->clientes = clientes;
    novoGrafo->monitores = monitores;

    novoGrafo->qtdServidores = qtdServidores;
    novoGrafo->qtdClientes = qtdClientes;
    novoGrafo->qtdMonitores = qtdMonitores;

    novoGrafo->vertices = (Vertice**) malloc(sizeof(Vertice*)*novoGrafo->numVertices);

    for(int i = 0; i < novoGrafo->numVertices; i++){
        novoGrafo->vertices[i] = criaVertice(i);
    }

    return novoGrafo;
}

const void inicializaDijkstra(Grafo* grafo, int inicio){
    for(int i = 0; i < grafo->numVertices; i++){
        atualizaDistancia(grafo->vertices[i], INT_MAX);
    }

    atualizaDistancia(grafo->vertices[inicio], 0);
}

double dijkstra(Grafo* grafo, int inicio, int fim){
    /*
    inicializaDijkstra(grafo, inicio);

    double custo = 0;
    int j = 0;
    
    Vertice* u;
    Vertice* v;
    Aresta* aresta;

    Fila* fp = fp_cria(grafo->numVertices);

    for(int i = 0; i < grafo->numVertices; i++){
        fp_insere(fp, grafo->vertices[i]);
    }

    while(!fp_vazia){
        u = fp_delMin(fp);
        if(retornaId(u) == fim) break;

        aresta = lista_retornaAresta(retornaListaAdj(u), j);
        while(aresta != NULL){
            v = grafo->vertices[retornaDestino(aresta)];
            if(retornaDistancia(v) > retornaDistancia(u) + retornaPeso(aresta)){
                // Atualiza a distancia de v
                // Troca ele de posicao na fila (vai ter uma prioridade maior)
            }

            j++;
            aresta = lista_retornaAresta(retornaListaAdj(u), j);
        }

        j = 0;
    }

    return custo;
    */
}

void insereAresta(Grafo* grafo, Aresta* aresta){
    lista_insere(retornaListaAdj(grafo->vertices[retornaOrigem(aresta)]), aresta);
}

int retornaNumVertices(Grafo* grafo){
    return grafo->numVertices;
}

int retornaNumArestas(Grafo* grafo){
    return grafo->numArestas;
}

int* retornaServidores(Grafo* grafo){
    return grafo->servidores;
}

int* retornaClientes(Grafo* grafo){
    return grafo->clientes;
}

int* retornaMonitores(Grafo* grafo){
    return grafo->monitores;
}

int retornaQtdServidores(Grafo* grafo){
    return grafo->qtdServidores;
}

int retornaQtdClientes(Grafo* grafo){
    return grafo->qtdClientes;
}

int retornaQtdMonitores(Grafo* grafo){
    return grafo->qtdMonitores;
}

Vertice** retornaVertices(Grafo* grafo){
    return grafo->vertices;
}

void imprimeGrafo(Grafo* grafo){
    FILE* f = fopen("grafo.dot", "w");

    fprintf(f, "digraph{\n");

    Vertice* vertice;
    Aresta* aresta;
    int j = 0;

    for(int i = 0; i < grafo->numVertices; i++){
        vertice = grafo->vertices[i];

        if(lista_vazia(retornaListaAdj(vertice))){
            fprintf(f, "%d;\n", i);
        }else{
            aresta = lista_retornaAresta(retornaListaAdj(vertice), j);
            while(aresta != NULL){
                fprintf(f, "%d -> %d[label=\"%.01lf\"];\n", i, retornaDestino(aresta), retornaPeso(aresta));
                j++;
                aresta = lista_retornaAresta(retornaListaAdj(vertice), j);
            }
        }

        j = 0;
    }

    fprintf(f, "}\n");
    fclose(f);
}

void liberaGrafo(Grafo* grafo){
    for(int i = 0; i < grafo->numVertices; i++){
        liberaVertice(grafo->vertices[i]);
    }

    free(grafo->vertices);
    free(grafo);
}