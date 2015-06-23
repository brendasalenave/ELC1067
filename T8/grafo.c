#include <stdio.h>
#include <string.h>

#include "grafo.h"
#include "lista.h"
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
    lista_t* p_l;
    grafo_t* g_l;
    int i;

    for(g_l = g; g_l != NULL; g_l = g_l->vertices->prox){
        for(p_l = g->vertices->vert; p_l != NULL; p_l = p_l->prox){
            if((strcmp(p_l->vert->chave, chave)) == 0){
                return g->vertices->vert;
            }
        }
    }
    return NULL;
}

/*lista_t* busca (lista_t* l, int v) {
    lista_t* p;
    for (p=l; p!=NULL; p=p->prox)
    if (p->info == v)
        return p;
    return NULL; // não achou o elemento
 }*/

/*
 * Insere uma aresta entre os vértices v1 e v2. Como o grafo
 * é não-direcionado, a função deve procurar os dois vértices
 * (função anterior) e inserir um ao outro em sua lista de
 * adjacência (v1 na lista de v2, e v2 na lista de v1).
 */
bool grafo_insere_aresta(grafo_t* g, char* v1, char* v2){
    vertice_t* v01 = grafo_busca_vertice(g, v1);
    vertice_t* v02 = grafo_busca_vertice(g, v2);

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

#ifdef 0
// A utility function to print the adjacenncy list representation of graph
void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}
#endif
