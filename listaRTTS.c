#include <stdio.h>
#include <stdlib.h>
#include "listaRTTS.h"


struct tCelula{
	RTT* par;
	Cel* prox;
};


struct tListaR{
	Cel* prim;
	Cel* ult;
};


ListaR* listaR_cria (){
	ListaR* nova = (ListaR*) malloc (sizeof (ListaR));
	nova->prim = nova->ult = NULL;

	return nova;
}

int listaR_vazia (ListaR* l){
	if (l->prim == NULL && l->ult == NULL)
		return 1;
	return 0;
}

void listaR_insere (ListaR* l, RTT* rtt){
	Cel* nova = (Cel*) malloc (sizeof(Cel));
	nova->prox = NULL;
	nova->par = rtt;

	if (listaR_vazia (l)){
		l->prim = l->ult = nova;
	}else{
		l->ult = l->ult->prox = nova;
	}
}

double listaR_busca (ListaR* l, int id1, int id2){

	Cel* p = l->prim;

	while (p != NULL){
		if (rtt_comparaNodes (p->par, id1, id2))
			return rtt_retornaNormal (p->par);
		p = p->prox;
	}
	return -1;

}


void listaR_imprime (ListaR* l, FILE* f){
	Cel* p = l->prim;

	while (p){
		rtt_imprime (p->par, f);
		p = p->prox;
	}
}


void listaR_libera (ListaR* l){
	Cel* p = l->prim;
	Cel* q;
	while (p){
		q = p->prox;
		rtt_libera (p->par);
		free (p);
		p = q;
	}

	free (l);
}