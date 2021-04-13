#include <stdio.h>
#include <stdlib.h>
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
        atualizaDistancia(grafo->vertices[i], __INT_MAX__);
    }

    atualizaDistancia(grafo->vertices[inicio], 0);
}

void dijkstra(Grafo* grafo, int inicio){
    inicializaDijkstra(grafo, inicio);

    double distancia = 0;
    int j = 0;
    
    Vertice* u;
    Vertice* v;
    Aresta* aresta;

    Fila* fp = fp_cria(grafo->numVertices);

    for(int i = 0; i < grafo->numVertices; i++){
        fp_insere(fp, grafo->vertices[i]);
    }

    while(!fp_vazia(fp)){
        u = fp_delMin(fp);

        aresta = lista_retornaAresta(retornaListaAdj(u), j);
        while(aresta != NULL){
            v = grafo->vertices[retornaDestino(aresta)];
            distancia = retornaDistancia(u) + retornaPeso(aresta);

            if(retornaDistancia(v) > distancia){
                fp_atualizaChave(fp, retornaId(v), distancia);
            }

            j++;
            aresta = lista_retornaAresta(retornaListaAdj(u), j);
        }

        j = 0;
    }

    fp_libera(fp);
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
                fprintf(f, "%d -> %d[label=\"%lf\"];\n", i, retornaDestino(aresta), retornaPeso(aresta));
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

    free(grafo->clientes);
    free(grafo->servidores);
    free(grafo->monitores);
    free(grafo->vertices);
    free(grafo);
}