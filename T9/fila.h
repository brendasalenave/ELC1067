#ifndef _FILA_H_
#define _FILA_H_

#include "vertice.h"

typedef struct no{
    vertice_t* vertice;
    struct no* prox;
}no_t;

typedef struct fila{
    no_t* ini;
    no_t* fim;
}fila_t;

fila_t* fila_cria(void);
no_t* ins_fim(no_t* fim, vertice_t* v);
no_t* ret_ini(no_t* ini);
void fila_insere(fila_t* f, vertice_t* v);
//vertice_t* fila_remove(fila_t* f);
int fila_vazia(fila_t* f);
void fila_libera(fila_t* f);
void fila_imprime(fila_t* f);

#endif // _FILA_H_
