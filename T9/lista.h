#ifndef _LISTA_H_
#define _LISTA_H_

/* Coloque aqui suas funções de lista para vértices */

struct vertice;

typedef struct lista{
  struct vertice* vert;   //vertice
  struct lista *prox;       // referência para próximo elemento da lista
}lista_t;

lista_t* lista_inicializa();
int lista_vazia(lista_t* l);
lista_t* lista_insere(lista_t *l, struct vertice* vertice);
lista_t* lista_busca(lista_t* l, char* chave);
void lista_imprime(lista_t* lista);
void lista_libera(lista_t *l);

#endif // _LISTA_H_
