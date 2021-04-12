#ifndef _RTT_
#define _RTT_

typedef struct tipoRTT RTT;

/* Recebe o par [S,C] (servidor cliente) e o RTT comum entre os dois*/
RTT* rtt_cria (int, int, double);

/* Retorna o mínimo dos RTT* */
double rtt_retornaEstrela (RTT*);

/* Retorna o RTT comum */
double rtt_retornaNormal (RTT*);

/* Retorna a inflação do RTT */
double rtt_retornaInflacao (RTT*);

/* Insere um novo valor de RTT* */
void rtt_insereNovoValor (RTT*, double);

/* Retorna 1 se par do rtt está no rtt passado na entrada*/
int rtt_comparaNodes (RTT*, int, int);

int rtt_comparaValores (RTT* const*, RTT* const*);

/* Imprime o par [S,C] com o valor da inflação*/
void rtt_imprime (RTT*, FILE*);


void rtt_calculaInflacao (RTT*);

/*Libera a memória*/
void rtt_libera (RTT*);

#endif