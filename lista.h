/*Lista de nós com sentinela*/
#ifndef _LISTA_
	#define _LISTA_

	#include "vertice.h"

	typedef struct lista Lista;
	typedef struct celula Celula;

	Lista* lista_cria ();

	/*Talvez fazer uma insere diferente, para inserir struct*/
	int lista_vazia (Lista* l);
	void lista_insere (Lista* l, Vertice* vertice);
	Vertice* lista_retornaVertice (Lista* l, int pos);
	void lista_imprime (Lista* l);
	void lista_libera (Lista* l);
	Celula* retornaCelulaPrim(Lista* l);
	Celula* retornaCelulaProx(Celula* c);
	Vertice* retornaVerticeDaCelula(Celula* c);


#endif