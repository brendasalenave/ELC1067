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
    g->vertices = lista_insere(g->vertices, v);
    if(g->vertices == NULL) return false;
    g->nvertices ++;
    return true;
}
/*
vertice_t* grafo_busca_vertice(grafo_t* g, char* chave){
    lista_t* p = g->vertices; //lista auxiliar para percorrer a lista de vertices
	vertice_t* v;
	while (p != NULL){
        v = p->vert;
		if (strcmp(v->chave,chave) == 0)
            return p->vert;
        else p = p->prox;
    }
	return NULL;
}*/

vertice_t* grafo_busca_vertice(grafo_t* g, char* chave){
	  lista_t* l = g->vertices;
	  vertice_t* v;
	  while (l != NULL){
		  v = l->vert;
		  //printf("'%s' -> '%s'\n", v->chave, chave);
		  if (strcmp(v->chave,chave) == 0){
			 return l->vert;
		  }
		  else
			 l = l->prox;
	  }
	  return NULL;
}

/*vertice_t* grafo_busca_vertice(grafo_t* g, char* chave){
    lista_t* p;
    vertice_t* v;
    for(p = g->vertices; p != NULL; p = p->prox){
            v = p->vert;
            if((strcmp(v->chave, chave)) == 0){
                return p->vert;
        }
    }
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

    if((v01 == NULL) || (v02 == NULL)){
      printf("erro ao buscar vertices");
      return false;
    }

    v01->adjacentes = lista_insere(v01->adjacentes, v02);
    v02->adjacentes = lista_insere(v02->adjacentes, v01);

    return true;
}

/* função que imprime vértices e arestas conforme formato */
void grafo_imprime(grafo_t* g){
    int i;
    lista_t* p = g->vertices;
    printf("\n\n");
    for(i = 0; i < g->nvertices; i++){
        printf("\n%s ->",p->vert->chave);
        imprimeLista(p->vert->adjacentes);
        p = p->prox;
    }
}

/* destroi e libera memória de um grafo */
void grafo_destroi(grafo_t* g){
    lista_t* p = g->vertices; //lista auxiliar para percorrer a lista de vertices
    vertice_t* v;
	  while (p != NULL){
		  v = p->vert;
		  lista_libera(v->adjacentes);
		  vertice_libera(v);
		  p = p->prox;
	  }
	  lista_libera(g->vertices);
    memo_libera(g);
}
