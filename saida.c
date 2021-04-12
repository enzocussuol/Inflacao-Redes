#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "saida.h"
#include "listaRTTS.h"

struct tSaida{
	ListaR** valores;//Vertices
	RTT** rtts; // [S,C] inflação
	int qtdValores;
	int qtdRTTS;//Tamanhos dos pares S,C
};

/* n = |S|+|C|+|M| (total vértices)*/
Saida* saida_cria (int vertices, int qtdRTTS){
	Saida* nova = (Saida*) malloc (sizeof (Saida));

	nova->qtdRTTS = qtdRTTS;
	nova->qtdValores = vertices;
	nova->valores = (ListaR**) malloc (sizeof (ListaR*)*vertices);
	nova->rtts = (RTT**) malloc (sizeof (RTT*)*nova->qtdRTTS);

	for (int i = 0; i < vertices; i++){
		nova->valores[i] = listaR_cria();
	}

	return nova;
}

/* Procura na lista de pares de RTT se o valor já foi calculado, se não foi retorna < 0, e cria a lista*/
double busca (Saida* s, int node1, int node2){
	
	if (!listaR_vazia(s->valores[node1])){
		return listaR_busca (s->valores[node1], node1, node2);
	}else{
		return -1;
	}

}


/*Libera apenas a lista*/
static void libera_auxiliar (Saida* s){

	for (int i = 0; i < s->qtdValores; i++){
		listaR_libera (s->valores[i]);
	}
	free(s->valores);

}

void saida_preenche (Saida* saida, Grafo* rede){
    int* S = retornaServidores(rede);
    int* C = retornaClientes(rede);
	int* M = retornaMonitores (rede);

	int qtdS = retornaQtdServidores (rede);
	int qtdM = retornaQtdMonitores (rede);
	int qtdC = retornaQtdClientes (rede);

	int i = 0;
	double aux;
	double rtt_parcial = INT_MAX;
	double custo1, custo2;
	RTT* rtt_aux;
	RTT* rtt_normal;
	double normal;
	for (int j = 0; j < qtdS; j++){//Percorrer o vetor de Servidores
		for (int k = 0; k < qtdC; k++){// Percorrer o vetor de Clientes
			for (int m = 0; m < qtdM; m++){//Percorrer o vetor de Monitores
				aux = busca (saida, S[j], M[m]);
				if (aux >= 0){//Já foi calculado
					custo1 = aux;
				}else{//Não foi calculado
					custo1 = dijkstra (rede, S[j], M[m]);// Calcula
					custo1 += dijkstra (rede, M[m], S[j]);//
					RTT* aux = rtt_cria (S[j], M[m], custo1);//Cria o RTT
					listaR_insere (saida->valores[S[j]], aux);//Insere na lista
				}

				aux = busca (saida, C[k], M[m]);
				if (aux >= 0){//Já foi calculado
					custo2 = aux;
				}else{//Não foi calculado
					custo2 = dijkstra (rede, M[m], C[k]);// Calcula
					custo2 += dijkstra (rede, C[k], M[m]);//
					RTT* aux = rtt_cria (M[m], C[k], custo2);//Cria o RTT
					listaR_insere (saida->valores[C[k]], aux);//Insere na lista
				}

				//Compara os valores do novo RTT calculado com antigo
				if (rtt_parcial > custo1+custo2){
					rtt_parcial = custo1 + custo2;
				}
			}

			normal = dijkstra (rede, S[j], C[k]);
			normal +=  dijkstra (rede, C[k], S[j]);
			rtt_normal = rtt_cria (S[j], C[k], normal);
			rtt_insereNovoValor (rtt_normal, rtt_parcial);
			rtt_calculaInflacao (rtt_normal);
			saida->rtts[i] = rtt_normal;
			i++;
			rtt_parcial = INT_MAX;
		}
	}

	libera_auxiliar (saida);
}

int compara (const void* r1, const void* r2){
	RTT* const* aux1 = r1;
	RTT* const* aux2 = r2;
	
	return rtt_comparaValores (aux1, aux2);
}

void saida_ordena (Saida* s){

	qsort (s->rtts, s->qtdRTTS, sizeof(s->rtts[0]), compara);

}

void saida_imprime (Saida* s){
	FILE* f = fopen("saida.txt", "w");

	for (int i= 0; i < s->qtdRTTS; i++){
		rtt_imprime (s->rtts[i], f);
	}

	fclose(f);
}

void saida_libera (Saida* s){
	for(int i = 0; i < s->qtdRTTS; i++){
		rtt_libera(s->rtts[i]);
	}

	free(s->rtts);
	free(s);
}