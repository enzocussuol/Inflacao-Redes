#ifndef _SAIDA_
	#define _SAIDA_
	#include "grafo.h"
	typedef struct tSaida Saida;

	Saida* saida_cria (int, int);

	/*Preenche rtts*/
	void saida_preenche (Saida*, Grafo*);

	void saida_imprime (Saida*);

	void saida_ordena (Saida* );

	void saida_libera (Saida*);

#endif