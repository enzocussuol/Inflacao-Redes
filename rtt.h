#ifndef RTT_H
    #define RTT_H

    #include "matriz.h"

    typedef struct rtt RTT;

    RTT* criaRTT(int, int);
    void preencheRTT(RTT*, Matriz*, int*, int);
    void calculaInflacao(RTT*);
    int rtt_comparaValores(RTT* const*, RTT* const*);
    void imprimeRTT(RTT*, FILE*);
    void liberaRTT(RTT*);
#endif