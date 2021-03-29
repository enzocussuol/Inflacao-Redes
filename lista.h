/*Lista de nós com sentinela*/
#ifndef _LISTA_
	#define _LISTA_

	typedef struct tLista Lista;

	Lista* lista_cria ();

	/*Talvez fazer uma insere diferente, para inserir struct*/
	void lista_insere (Lista* l, int noDestino, double peso);
	void lista_imprime (Lista* l);
	void lista_libera (Lista* l);

#endif