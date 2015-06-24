#include <stdio.h>
#include <string.h>

#include "grafo.h"
#include "lista.h"
#include "memo.h"

/* cria um grafo vazio */
grafo_t* grafo_cria(void){
    grafo_t* g = (grafo_t*)memo_aloca(sizeof(grafo_t));
    g->nvertices = 0;
    g->vertices = lista_inicializa();

    return g;
}

/* insere um vértice no grafo */
bool grafo_insere_vertice(grafo_t* g, vertice_t* v){
    printf("\nentra na funcao\n");
    g->vertices = insereLista(g->vertices, v);
    printf("insere na lista");
    g->nvertices ++;
    return true;
}

vertice_t* grafo_busca_vertice(grafo_t* g, char* chave){
	  lista_t* p = g->vertices; //lista auxiliar para percorrer a lista de vertices
	  vertice_t* v;
	  while (p != NULL){
		  v = p->vert;
		  if (strcmp(v->chave,chave) == 0) return p->vert;
		  else p = p->prox;
	  }
	  return NULL;
}

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
    lista_t* p = g->vertices; //lista auxiliar para percorrer a lista de vertices
    vertice_t* v;
	  while (p != NULL){
		  v = p->vert;
		  memo_libera(v);
		  p = p->prox;
	  }
    memo_libera(g);
}

/*
// A utility function to print the adjacenncy list representation of graph
void printGraph(struct Graph* graph){
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
*/
