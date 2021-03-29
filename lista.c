#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


typedef struct tCelula Celula;

struct tCelula{
	Celula* prox;
	int noDestino;
	double peso;
};


struct tLista{
	Celula* prim;
	Celula* ult;
};


Lista* lista_cria (){
	Lista* nova = (Lista*) malloc (sizeof (Lista));
	nova->prim = nova->ult = NULL;

	return nova;
}


int lista_vazia (Lista* l){
	if (!l->prim && !l->ult){
		return 1;
	}
	return 0;
}

//Insere no final
void lista_insere (Lista* l , int noDestino, double peso){

	Celula* nova = (Celula*) malloc (sizeof (Celula));
	nova->prox = NULL;
	nova->peso = peso;
	nova->noDestino = noDestino;

	if (lista_vazia (l)){
		l->prim = l->ult = nova;
	}else{
		l->ult = l->ult->prox = nova;
	}

}


void lista_imprime (Lista* l){

	Celula* p = l->prim;

	while (p){
		printf ("Node: %d, Peso: %f\n", p->noDestino, p->peso);
		p = p->prox;
	}

}


void lista_libera (Lista* l){

	Celula* p = l->prim;
	Celula* q;

	while (p){
		q = p->prox;
		free (p);
		p = q;
	}
	
	free (l);
}