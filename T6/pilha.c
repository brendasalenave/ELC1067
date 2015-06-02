#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"
#include "arvore.h"

Pilha * criaPilha(){
    Pilha * p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

/* empilha elementos */
void push(Pilha * p, Arv* no){
    Elem* e = (Elem*) malloc(sizeof(Elem));
    e->nodo_arv = no;
    e->ant = p->topo;
    p->topo = e;
}

/* desempilha elementos*/
int pop(Pilha * p){
    if (p->topo==NULL){
        return -1;
    }

    Elem * ant = p->topo->ant;

    int no = p->topo->nodo_arv;
    free(p->topo);

    p->topo = ant;

    return no;
}

int pilha_vazia(Pilha * p){
    return (p->topo==NULL);
}

int peek(Pilha * p){
    if (p->topo==NULL)    {
        return -1;
    }
    return p->topo->valor;

}


void push1(Pilha * p,Arv* no){
    if (pilha_vazia(p))
        push(p, no);
    else if (peek(p)<=no->info){
        push(p, no);
    }
}
