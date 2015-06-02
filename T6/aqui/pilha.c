#include "pilha.h"
#include "memo.h"

pilha_t *pilha_cria(void){
    pilha_t* p = (pilha_t*)memo_aloca(pilha_t);
    p->no_topo = NULL;
    return p;
}

void pilha_destroi(pilha_t* p){

}

bool pilha_vazia(pilha_t* p){
    return(p->no_topo == NULL);
}


void pilha_insere(pilha_t* p, arv_t* arv){
    p->no_topo = arv;
}

arv_t* pilha_remove(pilha_t p){

}

bool pilha_valida(pilha_t p){
    return (p == NULL);
}
