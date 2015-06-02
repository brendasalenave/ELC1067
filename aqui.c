#include <stdlib.h>
#include <stdio.h>

typedef struct elem{
    int valor;
    struct elem * ant;
}Elem;

typedef struct pilha{
    Elem * topo;
}Pilha;

Pilha * criaPilha()
{
    Pilha * p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void push(Pilha * p, int valor)
{
    Elem * e = (Elem*) malloc(sizeof(Elem));
    e->valor = valor;
    e->ant = p->topo;
    p->topo = e;
}

int pop(Pilha * p)
{
    if (p->topo==NULL)
    {
        return -1;
    }

    Elem * ant = p->topo->ant;

    int valor = p->topo->valor;
    free(p->topo);

    p->topo = ant;

    return valor;
}

int vazio(Pilha * p)
{
    return (p->topo==NULL);
}

int peek(Pilha * p)
{
    if (p->topo==NULL)
    {
        return -1;
    }
return p->topo->valor;

}


void push1(Pilha * p, int valor)
{
    if (vazio(p))
        push(p, valor);
    else if (peek(p)<=valor)
    {
        push(p, valor);
    }
}


int main()
{
    Pilha * p = criaPilha();
    push1(p, 10);
    push1(p, 20);
    push1(p, 30);
    push1(p, 15);
    push1(p, 4);
    push1(p, 40);
    push1(p, 33);

    while(!vazio(p))
    {
        int valor = pop(p);
        printf("%d ", valor);
    }

    return 0;
}