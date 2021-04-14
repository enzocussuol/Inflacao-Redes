#ifndef SAIDA_H
    #define SAIDA_H

    #include "rtt.h"

    typedef struct saida Saida;

    Saida* criaSaida(int);
    void preencheSaida(Saida*, Grafo*, Matriz*);
    int compara(const void*, const void*);
    void saida_ordena(Saida*);
    void imprimeSaida(Saida*,char*);
    void liberaSaida(Saida*);
#endif