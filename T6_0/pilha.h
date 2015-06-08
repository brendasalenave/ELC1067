#include "arvore.h"

typedef struct elem{
    Arv* nodo_arv;
    struct elem * ant;
}Elem;

typedef struct pilha{
    Elem* topo;
}Pilha;

Pilha * criaPilha();
void push(Pilha * p, Arv* no);
int pop(Pilha* p);
int vazio(Pilha * p);
int peek(Pilha * p);
void push1(Pilha * p, Arv* no);
