#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"


void insere_arvore(Arv* a, int n){
     if(a == NULL){
        a = (Arv*)malloc(sizeof(Arv));
        a->esq = NULL;
        a->dir = NULL;
        a->info = n;
     }else{
         if(n < a->info)
              insere_arvore(a->esq, n);
         else
              insere_arvore(a->dir, n);
     }
}

int arv_vazia(Arv* a){
    return(a==NULL);
}

//Imprime em ordem
void em_ordem(Arv *a){
      if (a != NULL)      {
            em_ordem(a->esq);
            printf("%d",a->info);
            em_ordem(a->dir);
      }
}

//Imprime em Pós-ordem
void pos_ordem(Arv *a){
      if (a != NULL)      {
            pos_ordem(a->esq);
            pos_ordem(a->dir);
            printf("%d",a->info);
      }
}

//Pré-ordem
void pre_ordem(Arv *a){
      if (a != NULL)      {
            printf("%d",a->info);
            pre_ordem(a->esq);
            pre_ordem(a->dir);
      }
}

Arv* libera(Arv* a){
    if (!arv_vazia(a)){
        libera(a->esq);
        /* libera sae */
        libera(a->dir);
        /* libera sad */
        free(a);
        /* libera raiz */
    }
    return NULL;
}
