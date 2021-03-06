#ifndef _PILHA_H_
#define _PILHA_H_
/*
 * pilha.h
 * TAD que implementa uma fila de elementos do tipo pilha.
 */

#include <stdbool.h>

#include "arv.h"
#include "memo.h"

typedef struct elem{
    arv_t* nodo;
    struct elem * ant;
}Elem;

typedef struct pilha{
    Elem* topo;
}pilha_t;

/* funções que permitem realizar operações sobre uma pilha */

/* retorna uma nova pilha, vazia */
pilha_t *pilha_cria(void);

/* destrói a pilha p, que deverá estar vazia. */
void pilha_destroi(pilha_t* p);

/* retorna true se a pilha p estiver vazia. */
bool pilha_vazia(pilha_t* p);

/* insere o dado arv do tipo arv_t na pilha p */
void pilha_insere(pilha_t* p, arv_t* arv);

/* remove e retorna o nó operador/operando no topo da pilha */
arv_t* pilha_remove(pilha_t* p);

/* retorna true se p for uma pilha válida */
bool pilha_valida(pilha_t* p);

#endif
