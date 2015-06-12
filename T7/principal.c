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
	arv_t *raiz;
	op_t n, k;
	pilha_t* pilha;
    pilha = pilha_cria();

    float valor;
    int t;
    char op;

	/* inicia expressão */

	printf("EXPRESSAO \n1: operando \n2: operador \n*encerrar expressao: 3\n\n");

	do{
        printf("\nTipo: ");
        scanf("%d", &t);
        if(t == 1){
            printf("Operando: ");
            n.tipo = OPERANDO;
            scanf("%f", &valor);
            n.u.operando = valor;
            raiz = arv_constroi(pilha, n);

        }else if(t == 2){
            printf("Operador: ");
            k.tipo = OPERADOR;
            scanf(" %c", &op);
            k.u.operador = op;
            raiz = arv_constroi(pilha, k);
        }
	}while(t == 1 || t == 2);

    printf("Em ordem: ");
    arv_imprime_em_ordem(raiz);
    printf("\n\nPos ordem: ");
    arv_imprime_pos_ordem(raiz);

    double resultado = arv_calcula(raiz);
    printf("\n\nResultado: %.2f",resultado);

	//pilha_insere( pilha, raiz );
	pilha_destroi( pilha );

	/* destroi árvore */
	arv_destroi( raiz );

    printf("\n\n");
	memo_relatorio();


	return 0;
}
