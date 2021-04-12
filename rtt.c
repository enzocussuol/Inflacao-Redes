#include <stdio.h>
#include <stdlib.h>
#include "rtt.h"

struct tipoRTT{
	int node1;
	int node2;
	double rtt_estrela;//todos valores passando por monitores
	double rtt_normal;
	double inflacao;
};

RTT* rtt_cria (int node1, int node2, double custo){
	RTT* novo = (RTT*) malloc (sizeof (RTT));
	novo->node1 = node1;
	novo->node2 = node2;
	novo->rtt_normal = custo;
	//novo->rtt_estrela = __INT_MAX__;

	return novo;
}


double rtt_retornaEstrela (RTT* x){
	return x->rtt_estrela;
}


double rtt_retornaNormal (RTT* x){
	return x->rtt_normal;
}


double rtt_retornaInflacao (RTT* x){
	return x->inflacao;
}

void rtt_insereNovoValor (RTT* x, double custo){
	x->rtt_estrela = custo;
}

int rtt_comparaNodes (RTT* x, int node1, int node2){
	if (x->node1 == node1 && x->node2 == node2){
		return 1;
	}else if (x->node1 == node2 && x->node2 == node1){
		return 1;
	}

	return 0;
}


int rtt_comparaValores (RTT* const* r1, RTT* const* r2){
	if((*r1)->inflacao > (*r2)->inflacao){
		return 1;
	}else if((*r1)->inflacao < (*r2)->inflacao){
		return -1;
	}else{
		if((*r1)->node1 > (*r2)->node1){
			return 1;
		}else if((*r1)->node1 < (*r2)->node1){
			return -1;
		}else{
			if((*r1)->node2 > (*r2)->node2){
				return 1;
			}else if((*r1)->node2 < (*r2)->node2){
				return -1;
			}
		}
	}
}


void rtt_imprime (RTT* x, FILE* f){
	fprintf (f, "%d %d %0.16lf\n", x->node1, x->node2, x->inflacao);
}

void rtt_calculaInflacao (RTT* x){
	x->inflacao = x->rtt_estrela/x->rtt_normal;
}

void rtt_libera (RTT* x){
	free (x);
}