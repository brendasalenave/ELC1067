#include <stdio.h>

#include "grafo.h"
#include "memo.h"

/* cria um grafo vazio */
grafo_t* grafo_cria(void){
    grafo_t* g = (grafo_t*)memo_aloca(sizeof(grafo_t));
    g->nvertices = 0;
    g->vertices = NULL;

    return g;
}

/* insere um vértice no grafo */
bool grafo_insere_vertice(grafo_t* g, vertice_t* v){
    g->vertices = insereLista(g->vertices, v);
    g->nvertices ++;
    return true;
}

/* retorna um vértice associado a uma chave (usar strcmp) */
vertice_t* grafo_busca_vertice(grafo_t* g, char* chave){

    return NULL;
}

/*
 * Insere uma aresta entre os vértices v1 e v2. Como o grafo
 * é não-direcionado, a função deve procurar os dois vértices
 * (função anterior) e inserir um ao outro em sua lista de
 * adjacência (v1 na lista de v2, e v2 na lista de v1).
 */
bool grafo_insere_aresta(grafo_t* g, char* v1, char* v2){
    vertice_t* v01, v02;
    v01 = grafo_busca_vertice(g, v1);
    v02 = grafo_busca_vertice(g, v2);

    v01->adjacentes = insereLista(v01->adjacentes, v02);
    v02->adjacentes = insereLista(v02->adjacentes, v01);

    return true;
}

/* função que imprime vértices e arestas conforme formato */
void grafo_imprime(grafo_t* g){

}

/* destroi e libera memória de um grafo */
void grafo_destroi(grafo_t* g){
    int i;

    for(i = 0; i < g->nvertices; i++)
        //libera vertice a vertice
    memo_libera(g);

}
