#include <stdio.h>
#include <stdlib.h>
#include "vertice.h"
#include "lista.h"
#include "grafo.h"
#include "fila.h"
#include "listaRTTS.h"
#include "saida.h"

Grafo* entrada(char* arquivo){
    FILE* arq = fopen(arquivo,"r");
    if(!arq){
        printf("Erro ao abrir arquivo!\n");
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
        insereAresta(rede, criaAresta(origem, destino, peso));
    }

    return rede;
}

int main(int argc, char* argv[]){
    Grafo* rede = entrada(argv[1]);

    // Teste para o algoritmo de Dijkstra
	int tam = retornaQtdMonitores(rede)*retornaQtdServidores(rede);

	Saida* s = saida_cria (retornaNumVertices (rede), tam);
	//printf ("%d\n\n", retornaNumVertices (rede));
	//saida_preenche (s, rede);
	//saida_ordena (s);
	//saida_imprime (s);

	/*RTT* r1 = rtt_cria (1, 2, 1.3);
	RTT* r2 = rtt_cria (1, 3, 3.5);
	RTT* r3 = rtt_cria (1, 4, 8.1);
	RTT* r4 = rtt_cria (1, 5, 2.9);

	ListaR* l = listaR_cria();
	listaR_insere (l , r1);
	listaR_insere (l , r2);
	listaR_insere (l , r3);
	listaR_insere (l , r4);

	listaR_imprime (l);

	if (listaR_busca (l, 1, 5)){
		printf ("Ok\n");
	}*/

    
    imprimeGrafo(rede);
    liberaGrafo(rede);
    return 0;
}