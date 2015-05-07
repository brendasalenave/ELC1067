/*
 * lista.h
 * Funções de TAD lista duplamente encadeada.
*/

#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdlib.h>
#include "memo.h"

typedef struct _lista {
    char* info;
    struct _lista* ant;
    struct _lista* prox;
} lista_t;

/* implementa aqui sua estrutura lista_t duplamente encadeada */

#endif /* _LISTA_H_ */
