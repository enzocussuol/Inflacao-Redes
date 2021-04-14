//Fila de Prioridade //Heap binaria
#ifndef FILA_H 
    #define FILA_H

    #include "vertice.h"
    
    #define item(A) (A)
    #define maior(A, B) (item(A) > item(B))
    #define exch(A, B) { Vertice* t = A; A = B; B = t; }

    typedef struct fila Fila;
    
    Fila* fp_cria(int); //cria fila vazia
    void fp_insere(Fila*,Vertice*); //insere na fila prioridade
    Vertice* fp_delMin(Fila*); // remove e retorna o menor valor
    int fp_vazia(Fila*); //verifica se fila esta vazia
    void fp_libera(Fila*); //limpa fila
    void fix_up(Fila*,int);
    void fix_down(Fila*,int,int);
    void fp_atualizaChave(Fila*, int, double);
#endif