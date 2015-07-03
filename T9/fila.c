#include <stdio.h>

#include "fila.h"
#include "memo.h"

fila_t* fila_cria(void){
    fila_t* f = (fila_t*)memo_aloca(sizeof(fila_t));
    f->ini = f->fim = NULL;

    return f;
}

/* função auxiliar: insere no fim */
no_t* ins_fim(no_t* fim, vertice_t* v) {
    no_t* p = (no_t*)memo_aloca(sizeof(no_t));
    p->vertice = v;
    p->prox = NULL;

    if (fim != NULL)  /* verifica se lista não estava vazia */
        fim->prox = p;
    return p;
}
/* função auxiliar: retira do início */
no_t* ret_ini(no_t* ini) {
    no_t* p = ini->prox;
    memo_libera(ini);
    return p;
}

void fila_insere(fila_t* f, vertice_t* v) {
    f->fim = ins_fim(f->fim,v);
    if (fila_vazia(f))  /* fila antes vazia? */
        f->ini = f->fim;
}

/*vertice_t* fila_remove(fila_t* f) {
    vertice_t* v;
    if (fila_vazia(f)) {
        printf("fila vazia.\n");
        exit(1);
    }
    v = f->ini->vertice;
    f->ini = ret_ini(f->ini);
    if (f->ini == NULL)
        f->fim = NULL;
    return v;
}
*/

int fila_vazia(fila_t* f) {
    return (f->ini==NULL);
}

void fila_libera(fila_t* f){
    no_t* q = f->ini;
    while(q != NULL){
        no_t* t = q->prox;
        memo_libera(q);
        q = t;
    }
    memo_libera((f));
}


void fila_imprime(fila_t* f){
    no_t* q;

    for(q = f->ini; q != NULL; q = q->prox){
        printf("%s ", q->vertice->nome);
    }
}
