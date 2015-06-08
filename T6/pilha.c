#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"
#include "arv.h"

pilha_t *pilha_cria(void){
    pilha_t* p = (pilha_t*) malloc(sizeof(pilha_t));
    p->topo = NULL;
    return p;
}

/* destrói a pilha p, que deverá estar vazia. */
void pilha_destroi(pilha_t* p){
    arv_t* no;
    while(!pilha_vazia(p)){
        no = pilha_remove(p);
    }
}

/* retorna true se a pilha p estiver vazia. */
bool pilha_vazia(pilha_t* p){
    return (p->topo==NULL);
}

/* insere o dado arv do tipo arv_t na pilha p */
void pilha_insere(pilha_t* p, arv_t* arv){
    Elem* e = (Elem*) malloc(sizeof(Elem));
    e->nodo = arv;
    e->ant = p->topo;
    p->topo = e;
}

/* remove e retorna o nó operador/operando no topo da pilha */
arv_t* pilha_remove(pilha_t* p){
    if (p->topo==NULL){
        return NULL;
    }

    Elem *ant = p->topo->ant;

    arv_t* no = p->topo->nodo;
    free(p->topo);
    p->topo = ant;
    return no;
}

/* retorna true se p for uma pilha válida */
bool pilha_valida(pilha_t* p){
    if(!pilha_vazia(p)) return true;
    else return false;
}
