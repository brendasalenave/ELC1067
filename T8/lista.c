#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "lista.h"
#include "memo.h"

lista_t* lista_inicializa(){
    return NULL;
}

/* insere no inicio da lista: retorna lista atualizada*/
lista_t* insereLista(lista_t *l, struct vertice_t* vertice){
    lista_t* novo = (lista_t*)memo_aloca(sizeof(lista_t));
    novo->vert = vertice;
    novo->prox = l;
    return novo;
}

int lista_vazia(lista_t* l){
    return (l==NULL);
}

/*
void imprimeLista(lista_t* lista){
    lista_t* p = lista;
    if(p == NULL)
        printf("lista vazia");
    while(p != NULL){
        printf("%s\n", p->str);
        p = p->prox;
    }
}
*/

void liberaLista(lista_t* l){
    if(!lista_vazia(l)){
        liberaLista(l->prox);
        memo_libera(l);
    }
}
