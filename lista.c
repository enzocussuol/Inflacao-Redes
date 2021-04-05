#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct celula{
	Celula* prox;
	Aresta* aresta;
};

struct lista{
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
void lista_insere (Lista* l , Aresta* aresta){
	Celula* nova = (Celula*) malloc (sizeof (Celula));
	nova->prox = NULL;
	nova->aresta = aresta;

	if (lista_vazia (l)){
		l->prim = l->ult = nova;
	}else{
		l->ult = l->ult->prox = nova;
	}
}

Aresta* lista_retornaAresta (Lista* l, int pos){
	Celula* celAux = l->prim;

	for(int i = 0; i < pos; i++){
		celAux = celAux->prox;
	}

	if(celAux != NULL){
		return celAux->aresta;
	}else{
		return NULL;
	}
}

void lista_imprime (Lista* l){
	Celula* p = l->prim;

	while (p){
		imprimeAresta(p->aresta);
		p = p->prox;
	}
}

void lista_libera (Lista* l){
	Celula* p = l->prim;
	Celula* q;

	while (p){
		q = p->prox;
		liberaAresta(p->aresta);
		free (p);
		p = q;
	}
	
	free (l);
}