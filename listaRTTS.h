#ifndef _LISTA_RTT_
	#define _LISTA_RTT_
	#include "rtt.h"

	typedef struct tListaR ListaR;
	typedef struct tCelula Cel;

	ListaR* listaR_cria ();
	void listaR_insere (ListaR*, RTT*);
	/* Retorna o valor do RTT do par de nodes, se o RTT não existe retorna < 0*/
	double listaR_busca (ListaR*, int, int);
	void listaR_imprime (ListaR*);
	void listaR_libera (ListaR*);

#endif