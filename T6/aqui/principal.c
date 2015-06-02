/*
 * principal.c
 * Implementação de árvore de expressões aritméticas.
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#include "arv.h"
#include "pilha.h"
#include "memo.h"

int main(int argc, char **argv){
	/* exemplo simples de árvore */
	arv_t* raiz;
	op_t soma, n1, n2;
	pilha_t* pilha;

	/* inicia expressão */
	/* operador + */
	soma.tipo = OPERADOR;
	soma.u.operador = '+';
	/* primeiro operando */
	n1.tipo = OPERANDO;
	n1.u.operando = 1.0;
	/* segundo operando */
	n2.tipo = OPERANDO;
	n2.u.operando = 2.0;

	/* cria uma árvore */
	raiz = arv_cria( soma );
	raiz = arv_insere_esquerda( raiz, n1 );
	raiz = arv_insere_direita( raiz, n2 );

	/* simples uso da pilha */
	pilha = pilha_cria();
	pilha_insere( pilha, raiz );
	pilha_destroi( pilha );

	/* destroi árvore */
	arv_destroi( raiz );

	return 0;
}
