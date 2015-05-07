/*
 * lista.h
 * Funções de TAD lista duplamente encadeada.
 */

#include <stdlib.h>
#include "lista.h"
#include "memo.h"

/* implementa aqui sua estrutura lista_t duplamente encadeada */

lista_t* lista_insere_inicio(lista_t* l,char* str){
    lista_t* novo = (lista_t*) malloc(sizeof(lista_t));
    novo->info = str;
    novo->prox = l;
    novo->ant = NULL;
    /* verifica se lista não vazia */
    if(l != NULL) l->ant = novo;

    return novo;
}

lista_t* lista_insere_meio(){
    lista_t* novo = (lista_t*) malloc(sizeof(lista_t));
    novo->info = str;

}

lista_t* lista_busca(lista_t* l, char* str){
    lista_t* p;
    for(p=l; p!=NULL; p=p->prox){
        if(p->info == str)
            return p;
    }
    return NULL; /* elemento não encontrado */
}

lista_t* lista_remove(lista_t* l, char* str){
    lista_t* p = lista_busca(l, str);

    if(p==NULL) return l; /* elemento não encontrado */

    if(l==p) l=p->prox;
    else p->ant->prox = p->prox;

    if(p->prox != NULL) p->prox->ant = p->ant;

    free(p);

    return l;
}

int lista_tamanho(lista_t*
