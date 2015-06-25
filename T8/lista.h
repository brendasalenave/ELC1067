#ifndef _LISTA_H_
#define _LISTA_H_

/* Coloque aqui suas funções de lista para vértices */

typedef struct vertice_t vertice;

typedef struct lista{
    struct vertice_t* vert;   //vertice
    struct lista *prox;       // referência para próximo elemento da lista
}lista_t;

lista_t* lista_inicializa();
int lista_vazia(lista_t* l);
lista_t* insereLista(lista_t *l, struct vertice_t* vertice);
lista_t* lista_busca(lista_t* l, char* chave);
void imprimeLista(lista_t* lista);
void liberaLista(lista_t *l);

#endif // _LISTA_H_
