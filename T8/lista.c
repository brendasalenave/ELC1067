#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "lista.h"
#include "memo.h"

/*Lista* inicializa(){
    return NULL;
}*/

lista_t* insereLista(lista_t *l, struct vertice_t* vertice){
    lista_t* novo = (lista_t*)memo_aloca(sizeof(lista_t));
    novo->vert = vertice;
    novo->prox = l;
    return novo;
}

int lista_vazia(lista_t* l){
    return (l==NULL);
}


lista_t* lista_busca (lista_t* l, char* chave) {
    lista_t* p;
    int r;
    for (p=l; p!=NULL; p=p->prox){
        if(strcmp(p->vert->chave, chave) == 0)
            return p;
    }
    return NULL; // não achou o elemento
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
