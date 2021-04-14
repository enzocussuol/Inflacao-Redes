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
    inicializaDijkstra(grafo, inicio); //Seta distancia de todos os vertices nao iniciais como MAX_INT

    double distancia = 0;
    int j = 0;
    
    Vertice* u; //Vertice sendo utilizado para calcular as distancias
    Vertice* v; //Vertice adjacente ao vertice u
    Aresta* aresta;

    Fila* fp = fp_cria(grafo->numVertices); //cria fila de prioridade (heap binaria)

    for(int i = 0; i < grafo->numVertices; i++){
        fp_insere(fp, grafo->vertices[i]); //preenche a fila
    }

    while(!fp_vazia(fp)){ //enquanto a fila nao esta vazia
        u = fp_delMin(fp);//retorna vertice com menor distancia (primeiro da fila)

        aresta = lista_retornaAresta(retornaListaAdj(u), j); //Lista de arestas do vertice u
        while(aresta != NULL){ //enquanto vertice possui arestas
            v = grafo->vertices[retornaDestino(aresta)]; //vertice final da aresta
            distancia = retornaDistancia(u) + retornaPeso(aresta); 

            if(retornaDistancia(v) > distancia){ //Se a distancia e menor, atualiza a chave
                fp_atualizaChave(fp, retornaId(v), distancia);
            }

            j++;
            aresta = lista_retornaAresta(retornaListaAdj(u), j); //pega a proxima aresta da lista
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