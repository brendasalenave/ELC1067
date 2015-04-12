/*
 * principal.c Esse programa testa as TADs implementadas para um jogo
 * solitário.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "memo.h"
#include "jogo.h"
#include "vetor.h"

void inicia_jogo(jogo solit){
    vetor_t* cartas = vetor_cria();
    vetor_t* fora_ordem = vetor_cria();
    srand( (unsigned)time(NULL) );

    int i, j;

    for(i=0; i<=3; i++){
        for(j=1; j<=13; j++){
            vetor_insere_carta(cartas, (i*13)+j-1, carta_cria(j,i));
        }
    }
    /*
    for(i=0; i < 52; i++){
        carta c;
        do{
            j = ((int)rand()%vetor_numelem(cartas));
            c = vetor_remove_carta(cartas, j);
        }while(c==NULL);
        vetor_insere_carta(fora_ordem, i, c);
    }*/

    for(i=0; i<7; i++){ //pilhas
        carta c;
        for(j=0; j<=i; j++){//cartas
            //c = vetor_remove_carta(fora_ordem, 0);
            c = vetor_remove_carta(cartas, 0);
            pilha_insere_carta(jogo_pilha(solit, i),c);
        }
        carta_abre(c); // esta no topo
    }
    vetor_destroi(cartas);
    vetor_destroi(fora_ordem);

}

void abreMonte(){

}

/* Mover carta do descarte para pilha */
void moveDescarte(){

}

void movePilha(){

}

void encerraJogo(jogo solit){
    jogo_destroi(solit);
    memo_relatorio();
    exit(0);
}

void verificaJogada(char c, jogo solit){
    /*printf("\n** SELECIONE UMA OPCAO **\n");
	printf(" \n* Abrir monte: o \n");
	printf(" * Mover carta do descarte para pilha: d\n");
	printf(" * Abrir uma carta do monte sobre o descarte\n");
	printf(" * Mover todas as cartas abertas de uma das 7 pilhas para outra: m \n");
	printf(" * Encerrar jogo: x \n");
	printf("\n");*/

    printf("C: ");
    scanf("%c", &c);


    if(c == 'x' || c == 'X') encerraJogo(solit);
    if(c == 'o' || c == 'O') abreMonte();
    if(c == 'd' || c == 'd') moveDescarte();
    if(c == 'm' || c == 'M') movePilha();
}

int main(int argc, char **argv){
    char c;
	jogo solit;
	solit = jogo_cria();

    inicia_jogo(solit);
    //verificaJogada(c, solit);
/*
	pilha_insere_carta(jogo_monte(solit), carta_cria(AS, OUROS));
	pilha_insere_carta(jogo_monte(solit), carta_cria(REI, PAUS));
	pilha_insere_carta(jogo_monte(solit), carta_cria(DAMA, COPAS));
	pilha_insere_carta(jogo_monte(solit), carta_cria(2, PAUS));
	pilha_insere_carta(jogo_monte(solit), carta_cria(10, ESPADAS));
*/
	jogo_desenha(solit);
	/*while (!pilha_vazia(jogo_monte(solit))) {
		carta		c;
		tela_le(jogo_tela(solit));

		c = pilha_remove_carta(jogo_monte(solit));
		carta_abre(c);
		pilha_insere_carta(jogo_pilha(solit, 3), c);

		jogo_desenha(solit);
	}*/
	tela_le(jogo_tela(solit));
	jogo_destroi(solit);

	/* relatório de memória */
	memo_relatorio();
	return 0;
}
