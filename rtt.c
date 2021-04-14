#include <stdio.h>
#include <stdlib.h>
#include "rtt.h"

struct rtt{
    int origem, destino;
    double rttNormal;
    double rttEstrela;
    double inflacao;
};

RTT* criaRTT(int origem, int destino){
    RTT* novoRTT = (RTT*) malloc(sizeof(RTT));

    novoRTT->origem = origem;
    novoRTT->destino = destino;

    return novoRTT;
}

void preencheRTT(RTT* rtt, Matriz* matriz, int* monitores, int qtdMonitores){
    //S = Servidor   //M = Monitor  //C = Cliente
    //RTT equivale a soma das distancias entre S->C e C->S
    rtt->rttNormal = retornaElemento(matriz, rtt->origem, rtt->destino) + retornaElemento(matriz, rtt->destino, rtt->origem);

    double rttEstrelaAux;
    double rttEstrelaMin = __INT_MAX__;

    for(int i = 0; i < qtdMonitores; i++){
        //RTT* equivale a soma das distancias S->M e M->S e M->C e C->M
        rttEstrelaAux = retornaElemento(matriz, rtt->origem, monitores[i]) + retornaElemento(matriz, monitores[i], rtt->origem);
        rttEstrelaAux += retornaElemento(matriz, rtt->destino, monitores[i]) + retornaElemento(matriz, monitores[i], rtt->destino);

        if(rttEstrelaAux < rttEstrelaMin) rttEstrelaMin = rttEstrelaAux; //Atualiza sempre para o menor RTT*
    }

    rtt->rttEstrela = rttEstrelaMin;
    calculaInflacao(rtt);
}

void calculaInflacao(RTT* rtt){
    rtt->inflacao = rtt->rttEstrela/rtt->rttNormal;
}

int rtt_comparaValores (RTT* const* r1, RTT* const* r2){
    //comparacao por inflacao (menor tem prioridade)
    //desempate pelo numero do vertice servidor e cliente (menor tem prioridade)
	if((*r1)->inflacao > (*r2)->inflacao){
		return 1;
	}else if((*r1)->inflacao < (*r2)->inflacao){
		return -1;
	}else{
		if((*r1)->origem > (*r2)->origem){
			return 1;
		}else if((*r1)->origem < (*r2)->origem){
			return -1;
		}else{
			if((*r1)->destino > (*r2)->destino){
				return 1;
			}else if((*r1)->destino < (*r2)->destino){
				return -1;
			}
		}
	}
}

void imprimeRTT(RTT* rtt, FILE* f){
    fprintf(f, "%d %d %.15lf\n", rtt->origem, rtt->destino, rtt->inflacao);
}

void liberaRTT(RTT* rtt){
    free(rtt);
}