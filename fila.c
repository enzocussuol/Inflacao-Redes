#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct fila{
    int fim;
    int* mapa;
    Vertice** vert;
};
    
Fila* fp_cria(int N){
    Fila* nova = (Fila*) malloc (sizeof(Fila));
    nova->fim = 0;
    nova->vert = (Vertice**) malloc (sizeof(Vertice*) * (N+1)); // +1 porque os indices comecam em 1 e nao 0
    nova->mapa = (int*) malloc (sizeof(int) * (N + 1));
    return nova;
}

static void troca(Fila* fp, int i, int j){
    exch(fp->vert[i], fp->vert[j]);
    fp->mapa[retornaId(fp->vert[i])] = i;
    fp->mapa[retornaId(fp->vert[j])] = j;
}

void fp_insere(Fila* fp,Vertice* v){
    fp->vert[++fp->fim] = v;
    fp->mapa[retornaId(v)] = fp->fim;
    fix_up(fp,fp->fim);
}

Vertice* fp_delMin(Fila* fp){
    Vertice* min = fp->vert[1];
    troca(fp, 1,fp->fim);
    fp->fim--;
    fix_down(fp,fp->fim,1);
    fp->vert[fp->fim + 1] = NULL;
    return min;
}

Vertice* fp_min(Fila* fp){
    return fp->vert[1];
}

int fp_vazia(Fila* fp){
    return fp->fim == 0;
}

int fp_tam(Fila* fp){
    return fp->fim;
}

void fp_libera(Fila* fp){
    free(fp->vert);
    free(fp);
}

Vertice* fp_retornaVertice(Fila* fila, int id){
    int pos = fila->mapa[id];
    imprimeVertice(fila->vert[pos]);
    return fila->vert[pos];
}

void fix_down(Fila* fp, int sz, int k){
    while (2*k <= sz) {
        int j = 2*k;
        if (j < sz && maior(retornaDistancia(fp->vert[j]), retornaDistancia(fp->vert[j+1])))   
            j++;
        if (!maior(retornaDistancia(fp->vert[k]), retornaDistancia(fp->vert[j])))  
            break;
        troca(fp, k, j);
        k = j;
    }
}

void fix_up(Fila* fp, int k) {
    while (k > 1 && maior(retornaDistancia(fp->vert[k/2]), retornaDistancia(fp->vert[k]))) {
        troca(fp, k, k/2);
        k = k/2;
    }
}

void fp_atualizaChave(Fila* fp, int id, int distancia){
    int pos = fp->mapa[id];
    atualizaDistancia(fp->vert[pos], distancia);
    fix_up(fp, pos);
}

void fp_imprime(Fila* fp){
    for(int i = 1; i <= fp->fim ;i++){
        Vertice* vertice = fp->vert[i];
        printf("%d - %d - %.01lf\n", i, retornaId(vertice), retornaDistancia(vertice));
    }
}