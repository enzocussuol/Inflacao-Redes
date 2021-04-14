#include <stdio.h>
#include <stdlib.h>
#include "saida.h"

struct saida{
    RTT** RTTs;
    int qtdRTTs;
};

Saida* criaSaida(int qtdRTTs){
    Saida* novaSaida = (Saida*) malloc(sizeof(Saida));

    novaSaida->qtdRTTs = qtdRTTs;
    novaSaida->RTTs = (RTT**) malloc(sizeof(RTT*)*qtdRTTs);

    return novaSaida;
}

void preencheSaida(Saida* saida, Grafo* grafo, Matriz* matriz){
    int* servidores = retornaServidores(grafo);
    int* clientes = retornaClientes(grafo);
    int* monitores = retornaMonitores(grafo);

    int qtdServidores = retornaQtdServidores(grafo);
    int qtdClientes = retornaQtdClientes(grafo);
    int qtdMonitores = retornaQtdMonitores(grafo);

    int i = 0;
    for(int j = 0; j < qtdServidores; j++){
        for(int k = 0; k < qtdClientes; k++){
            /*Preenche o RTT para cada par Servidor/Cliente*/
            saida->RTTs[i] = criaRTT(servidores[j], clientes[k]);
            preencheRTT(saida->RTTs[i++], matriz, monitores, qtdMonitores);
        }
    }
}

int compara (const void* r1, const void* r2){
    RTT* const* aux1 = r1;
	RTT* const* aux2 = r2;
	return rtt_comparaValores (aux1, aux2);
}

void saida_ordena (Saida* s){

	qsort (s->RTTs, s->qtdRTTs, sizeof(s->RTTs[0]), compara);

}

void imprimeSaida(Saida* saida, char* arq){
    FILE* f = fopen(arq, "w");
    if(!f){
        printf("Nao foi possivel abrir o arquivo");
        exit(1);
    }

    for(int i = 0; i < saida->qtdRTTs; i++){
        imprimeRTT(saida->RTTs[i], f);
    }

    fclose(f);
}

void liberaSaida(Saida* saida){
    for(int i = 0; i < saida->qtdRTTs; i++){
        free(saida->RTTs[i]);
    }

    free(saida->RTTs);
    free(saida);
}