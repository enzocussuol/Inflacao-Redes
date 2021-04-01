#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

struct grafo{
    int numVertices, numArestas;
    int* servidores;
    int* clientes;
    int* monitores;
    int qtdServidores, qtdClientes, qtdMonitores;
    Lista** listaAdj;
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

    novoGrafo->listaAdj = (Lista**) malloc(sizeof(Lista*)*novoGrafo->numVertices);

    for(int i = 0; i < novoGrafo->numVertices; i++){
        novoGrafo->listaAdj[i] = lista_cria();
    }

    return novoGrafo;
}

void insereAresta(Grafo* grafo, int origem, Vertice* destino){
    lista_insere(grafo->listaAdj[origem], destino);
}

void dijkstra(Grafo* grafo){
    // A fazer
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

Lista** retornaListaAdj(Grafo* grafo){
    return grafo->listaAdj;
}

void imprimeGrafo(Grafo* grafo){
    FILE* f = fopen("grafo.dot", "w");

    fprintf(f, "digraph{\n");

    Vertice* vertice;
    int j = 0;

    for(int i = 0; i < grafo->numVertices; i++){
        if(!lista_vazia(grafo->listaAdj[i])){
            vertice = lista_retornaVertice(grafo->listaAdj[i], j);
            while(vertice != NULL){
                fprintf(f, "%d -> %d[label=\"%.01lf\"];\n", i, retornaId(vertice), retornaPeso(vertice));
                j++;
                vertice = lista_retornaVertice(grafo->listaAdj[i], j);
            }
        }else{
            fprintf(f, "%d;\n", i);
        }
        j = 0;
    }

    fprintf(f, "}\n");

    fclose(f);
}

void liberaGrafo(Grafo* grafo){
    for(int i = 0; i < grafo->numVertices; i++){
        lista_libera(grafo->listaAdj[i]);
    }

    free(grafo->listaAdj);
    free(grafo);
}