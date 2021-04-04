#include <stdio.h>
#include <stdlib.h>
#include "vertice.h"
#include "lista.h"
#include "grafo.h"
#include "fila.h"

Grafo* entrada(char* arquivo){
    FILE* arq = fopen(arquivo,"r");
    if(!arq){
        printf("Erro ao abrir arquivo!");
        exit(1);
    }
    int nVert,nArestas,nServ,nCli,nMonit;
    int *servidores,*clientes,*monitores;
    //Leitura das quantidades
    fscanf(arq,"%d%d",&nVert,&nArestas);        //Quant vertices e arestas
    fscanf(arq,"%d%d%d",&nServ,&nCli,&nMonit);   //Quant servidores,clientes e monitores
    //Alocando memória
    servidores = malloc(sizeof(int) * nServ);
    clientes = malloc(sizeof(int) * nCli);
    monitores = malloc(sizeof(int) * nMonit);
    //Leitura dos nós
    for(int i = 0 ; i < nServ; i++)//Leitura dos nós que indicam servidores
        fscanf(arq,"%d",&servidores[i]);
    for(int i = 0; i < nCli; i++)//Leitura dos nós que indicam clientes
        fscanf(arq,"%d",&clientes[i]);
    for(int i = 0; i < nMonit; i++)//Leitura dos nós que indicam monitores
        fscanf(arq,"%d",&monitores[i]);
    //criacao do grafo
    Grafo* rede = criaGrafo(nVert,nArestas,servidores,clientes,monitores,nServ,nCli,nMonit);
    //Leitura das arestas
    int origem, destino; double peso;
    for(int i = 0 ; i < nArestas; i++){
        fscanf(arq,"%d%d%lf",&origem,&destino,&peso);
        Vertice* v = criaVertice(destino,peso); //cria vertice destino
        insereAresta(rede,origem,v);           //insere vertice destino na lista do vertice de origem
    }
    return rede;
}

int main(int argc, char* argv[]){
    Grafo* rede = entrada(argv[1]);
    //Teste heap
    Fila* heap = fp_cria(retornaNumArestas(rede));
    Lista** vertices = retornaListaAdj(rede);
    for(int i = 0; i < retornaNumVertices(rede); i++){
        for(Celula* v = retornaCelulaPrim(vertices[i]); v != NULL; v = retornaCelulaProx(v)){
            fp_insere(heap,retornaVerticeDaCelula(v));
        }
    }
    fp_imprime(heap);
    //
    liberaGrafo(rede);
    return 0;
}