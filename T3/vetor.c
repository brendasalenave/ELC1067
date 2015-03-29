/*
 * vetor.c
 * TAD que implementa um vetor dinamico.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "vetor.h"
#include "carta.h"
#include "memo.h"

struct vetor {
	carta* baralho;   /* baralho - vetor de cartas */
	int n;		/* número de cartas */
}; //vetor_t

vetor_t* vetor_cria(void){
    int i;
	struct vetor *vet = (struct vetor*)memo_aloca(sizeof(struct vetor));
	vet->n = 0;
	vet->baralho = (carta*)memo_aloca(50*sizeof(carta));
	for(i=0; i<50; i++){
        vet->baralho[i] = NULL; //inicializa baralho com NULL
	}
	return vet;
}

void vetor_destroi(vetor_t* vet){ //Ok
	memo_libera(vet->baralho);
	memo_libera(vet);
}

/* retorna o número de elementos no vetor vet. */
int vetor_numelem(vetor_t *vet){ // Ok
    int i=0;
	while(vet->baralho[i] != NULL){
        vet->n++;
        i++;
	}
	return vet->n;
}

/* insere uma carta no vetor vet, na posição indice.
 * se a carta já existe nessa posição, as cartas subsequentes avançam uma
 * posição.
 * se o vetor não tem mais espaço (cheio), utiliza realloc.
 */
void vetor_insere_carta(vetor_t *vet, int indice, carta c){
    if(vet->baralho[indice] == NULL)
        vet->baralho[indice] = c;
    else

	/* TODO aqui */
	vet->n++;
}

/* remove uma carta que estava na posição indice.
 * As cartas depois de indice recuam 1 posição à frente.
 * Retorna a carta original que estava na posição indice do vetor vet.
 */
carta vetor_remove_carta(vetor_t *vet, int indice){
    int i;

	carta* c = (struct carta*)memo_aloca(sizeof(carta));
    c = vet->baralho[indice];
	for(i=vet->n; i > indice; i--){
        vet->baralho[i] = vet->baralho[i-1];
	}

	return c;

	//vet->n--;
	//return NULL;
}

/* retorna o dado na posição indice do vetor vet */
carta vetor_acessa_carta(vetor_t *vet, int indice){
    //struct _carta* c = (struct _carta*)memo_aloca(sizeof(struct _carta));

	/* TODO aqui */
	return NULL;
}

/* retorna true se o vetor vet for válido */
bool vetor_valido(vetor_t *vet){
	if(vet != NULL)
        return true;
    else
        return false;
}
