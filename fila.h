/*
//Fila de Prioridade //Heap binaria
#ifndef FILA_H 
    #define FILA_H

    #include "vertice.h"
    
    #define item(A) (A)
    #define maior(A, B) (item(A) > item(B))
    #define troca(A, B) { Vertice* t = A; A = B; B = t; }

    typedef struct fila Fila;
    
    Fila* fp_cria(int); //cria fila vazia
    void fp_insere(Fila*,Vertice*); //insere na fila prioridade
    Vertice* fp_delMin(Fila*); // remove e retorna o menor valor
    Vertice* fp_min(Fila*); //retorna o menor valor.
    int fp_vazia(Fila*); //verifica se fila esta vazia
    int fp_tam(Fila*); //numero de valores na fila
    void fp_libera(Fila*); //limpa fila
    void fix_up(Vertice**,int);
    void fix_down(Vertice**,int,int);
    void fp_imprime(Fila*);
#endif
*/