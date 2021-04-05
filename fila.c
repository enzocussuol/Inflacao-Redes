/*
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct fila{
    int ini,fim;
    Vertice** vert;
};
    
Fila* fp_cria(int N){
    Fila* nova = (Fila*) malloc (sizeof(Fila));
    nova->ini = nova->fim = 0;
    nova->vert = (Vertice**) malloc (sizeof(Vertice*) * (N+1)); // +1 porque os indices comecam em 1 e nao 0
    return nova;
}

void fp_insere(Fila* fp,Vertice* v){
    fp->vert[++fp->fim] = v;
    fix_up(fp->vert,fp->fim);
}

Vertice* fp_delMin(Fila* fp){
    Vertice* min = fp->vert[1];
    troca(fp->vert[1],fp->vert[fp->fim]);
    fp->fim--;
    fix_down(fp->vert,fp->fim,1);
    fp->vert[fp->fim + 1] = NULL;
    return min;
}

Vertice* fp_min(Fila* fp){
    return fp->vert[1];
}

int fp_vazia(Fila* fp){
    return fp->ini == fp->fim;
}

int fp_tam(Fila* fp){
    return fp->fim;
}

void fp_libera(Fila* fp){
    free(fp->vert);
    free(fp);
}

void fix_down(Vertice** a, int sz, int k){
    while (2*k <= sz) {
        int j = 2*k;
        if (j < sz && maior(retornaPeso(a[j]), retornaPeso(a[j+1])))   
            j++;
        if (!maior(retornaPeso(a[k]), retornaPeso(a[j])))  
            break;
        troca(a[k], a[j]);
        k = j;
    }
}

void fix_up(Vertice** a, int k) {
    while (k > 1 && maior(retornaPeso(a[k/2]), retornaPeso(a[k]))) {
        troca(a[k], a[k/2]);
        k = k/2;
    }
}

void fp_imprime(Fila* fp){
    for(int i = fp->ini + 1; i <= fp->fim ;i++){
        Vertice* vertice = fp->vert[i];
        printf("%d - %d - %.01lf\n", i, retornaId(vertice), retornaPeso(vertice));
    }
}
*/