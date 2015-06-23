#ifndef _VERTICE_H_
#define _VERTICE_H_

/*
 * vertice.h
 * Definição da estrutura de dados vertice_t de grafo.
 */

#include <stdlib.h>
#include "lista.h"

/* tipo vértice inserido na lista */
typedef struct vertice {
	char* chave;         /* chave identificador */
	char* nome;          /* nome do vértice */
	lista_t* adjacentes; /* lista com os vértices adjacentes (vizinhos) */
} vertice_t;

#endif /* _VERTICE_H_ */
