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

arv_t* arv_constroi(pilha_t* p, op_t n);

arv_t* arv_constroi(pilha_t* p, op_t n){
    arv_t* raiz;
    if(n.tipo == OPERANDO){
        raiz = arv_cria(n);
        pilha_insere(p, raiz);

    }else{
        arv_t* tmp1 = pilha_remove(p);
        arv_t* tmp2 = pilha_remove(p);

        raiz = arv_cria(n);
        raiz = arv_insere_direita(raiz, tmp1);
        raiz = arv_insere_esquerda(raiz, tmp2);

        pilha_insere(p, raiz);
    }
    return raiz;
}


int main(int argc, char **argv){

	/* exemplo simples de árvore */
	arv_t *raiz, *arv_esq, *arv_dir;
	op_t soma, n1, n2;
	pilha_t* pilha;
    pilha = pilha_cria();

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

    raiz = arv_constroi(pilha, n1);
    raiz = arv_constroi(pilha, n2);
    raiz = arv_constroi(pilha, soma);

    arv_imprime_em_ordem(raiz);
    printf("\n\n");
    arv_imprime_pos_ordem(raiz);

	/* cria uma árvore */
	/*raiz = arv_cria( soma );
	arv_esq = arv_cria( n1 );
	arv_dir = arv_cria( n2 );
	raiz = arv_insere_esquerda( raiz, arv_esq );
	raiz = arv_insere_direita( raiz, arv_dir ); */


	//pilha_insere( pilha, raiz );
	pilha_destroi( pilha );

	/* destroi árvore */
	raiz = arv_destroi( raiz );
	//arv_destroi( arv_esq );
	//arv_destroi( arv_dir );

	return 0;
}
