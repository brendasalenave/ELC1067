
#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

/* insere um novo dado na árvore a esquerda */
arv_t* arv_insere_esquerda(arv_t* arv, op_t op){
    if(arv->esq == NULL){
        arv = (arv_t*)malloc(sizeof(arv_t));
        arv->esq = NULL;
        arv->dir = NULL;
        arv->dado = op;
     }else
        return arv_insere_esquerda(arv->esq, op);

    return arv;
}

/* insere um novo dado na árvore a direita */
arv_t* arv_insere_direita(arv_t* arv, op_t op){
    if(arv->dir == NULL){
        arv = (arv_t*)malloc(sizeof(arv_t));
        arv->esq = NULL;
        arv->dir = NULL;
        arv->dado = op;
     }else
        return arv_insere_direita(arv->dir, op);

    return arv;
}

/* imprime a árvore em pré-ordem: raiz, esquerda, e direita */
void arv_imprime_pre_ordem(arv_t* arv){
    if (arv != NULL)      {
        if(arv->dado.tipo == OPERANDO) printf(" %f", arv->dado.u.operando);
        else printf("%c", arv->dado.u.operador);
        arv_imprime_pre_ordem(arv->esq);
        arv_imprime_pre_ordem(arv->dir);
    }
}

/* imprime a árvore em ordem: esquerda, raiz, e direita */
void arv_imprime_em_ordem(arv_t* arv){
    if (arv != NULL)      {
        arv_imprime_em_ordem(arv->esq);
        if(arv->dado.tipo == OPERANDO) printf(" %f", arv->dado.u.operando);
        else printf("%c", arv->dado.u.operador);
        arv_imprime_em_ordem(arv->dir);
    }
}

/* imprime a árvore em pós-ordem: esquerda, direita, e raiz */
void arv_imprime_pos_ordem(arv_t* arv){
    if (arv != NULL)      {
        arv_imprime_pos_ordem(arv->esq);
        arv_imprime_pos_ordem(arv->dir);
        if(arv->dado.tipo == OPERANDO) printf(" %f", arv->dado.u.operando);
        else printf("%c", arv->dado.u.operador);
    }
}

/*  destroi toda a árvore */
arv_t* arv_destroi(arv_t* arv){
    if (arv != NULL){
        arv_destroi(arv->esq);
        arv_destroi(arv->dir);
        free(arv);
    }
    return NULL;
}
