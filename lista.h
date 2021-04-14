/*Lista de nós com sentinela*/
#ifndef _LISTA_
	#define _LISTA_

	#include "aresta.h"

	typedef struct lista Lista;
	typedef struct celula Celula;

	Lista* lista_cria ();
	int lista_vazia (Lista*);
	void lista_insere (Lista*, Aresta*);
	Aresta* lista_retornaAresta (Lista*, int);
	void lista_libera (Lista*);
#endif