#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "arv.h"
#include "pilha.h"

arv_t* arv_cria(op_t op){
    arv_t* p =(arv_t*)malloc(sizeof(arv_t));
    p->dado = op;
    p->esq = NULL;
    p->dir = NULL;
    return p;
}


/* insere um novo dado na árvore a esquerda */
arv_t* arv_insere_esquerda(arv_t* arv, arv_t* filho){
    arv->esq = filho;
    return arv;
}

/* insere um novo dado na árvore a direita */
arv_t* arv_insere_direita(arv_t* arv, arv_t* filho){
    arv->dir = filho;
    return arv;
}

/*arv_constroi(arv_t* raiz, pilha_t* p, op_t n){
    if(n.tipo == OPERANDO){
        raiz = arv_cria(n);
        pilha_insere(p, raiz);

    }else{
        arv_t* tmp1 = pilha_remove(p);
        arv_t* tmp2 = pilha_remove(p);

        raiz = arv_cria(n);
        raiz = arv_insere_esquerda(raiz, tmp1);
        raiz = arv_insere_esquerda(raiz, tmp2);

        pilha_insere(p, raiz);
    }
}


/* imprime a árvore em pré-ordem: raiz, esquerda, e direita */
void arv_imprime_pre_ordem(arv_t* arv){
    if (arv != NULL){
        printf("(");
        if(arv->dado.tipo == OPERANDO) printf(" %f", arv->dado.u.operando);
        else printf("%c", arv->dado.u.operador);
        arv_imprime_pre_ordem(arv->esq);
        arv_imprime_pre_ordem(arv->dir);
        printf(")");
    }
}

/* imprime a árvore em ordem: esquerda, raiz, e direita */
void arv_imprime_em_ordem(arv_t* arv){
    if (arv != NULL){
        printf("(");
        arv_imprime_em_ordem(arv->esq);
        if(arv->dado.tipo == OPERANDO) printf(" %f", arv->dado.u.operando);
        else printf("%c", arv->dado.u.operador);
        arv_imprime_em_ordem(arv->dir);
        printf(")");
    }
}

/* imprime a árvore em pós-ordem: esquerda, direita, e raiz */
void arv_imprime_pos_ordem(arv_t* arv){
    if (arv != NULL){
        printf("(");
        arv_imprime_pos_ordem(arv->esq);
        arv_imprime_pos_ordem(arv->dir);
        if(arv->dado.tipo == OPERANDO) printf(" %f", arv->dado.u.operando);
        else printf("%c", arv->dado.u.operador);
        printf(")");
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

