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
    carta c;

    for(i=0; i<=3; i++){
        for(j=1; j<=13; j++){
            vetor_insere_carta(cartas, (i*13)+j-1, carta_cria(j,i));
        }
    }

    for(i=0; i < 52; i++){
        do{
            j = ((int)rand()%vetor_numelem(cartas));
            c = vetor_remove_carta(cartas, j);
        }while(c==NULL);
        vetor_insere_carta(fora_ordem, i, c);
    }

    for(i=0; i<7; i++){ //pilhas
        for(j=0; j<=i; j++){//cartas
            c = vetor_remove_carta(fora_ordem, 0);
            //c = vetor_remove_carta(cartas, 0);
            pilha_insere_carta(jogo_pilha(solit, i),c);
        }
        carta_abre(c); // esta no topo
    }

    for (i=0; i<24;i++){
        c = vetor_remove_carta(fora_ordem,0);
        pilha_insere_carta(jogo_monte(solit),c);
    }
    vetor_destroi(cartas);
    vetor_destroi(fora_ordem);
}

void abreMonte(jogo solit){
    carta c = pilha_remove_carta(jogo_monte(solit));
    carta_abre(c);
    pilha_insere_carta(jogo_descartes(solit), c);
}

/* Mover carta do descarte para pilha */
void moveDescarte(jogo solit){
    int n;
    printf ("\ninforme pilha: \n");
    scanf ("%d",&n);
    if (n > 7 || n < 1){
        printf ("valor invalido!\n");
        return;
    }
    if (!pilha_vazia(jogo_descartes(solit))){
        carta c = pilha_remove_carta(jogo_descartes(solit));
        pilha_insere_carta(jogo_pilha(solit, n),c);
    }
    else
        printf ("descarte vazio\n");
}

void movePilha(){

}

void encerraJogo(jogo solit){
    jogo_destroi(solit);
    memo_relatorio();
    exit(0);
}

void verificaJogada(char c, jogo solit){
    /*
    printf("\n** SELECIONE UMA OPCAO **\n");
	printf(" \n* Abrir monte: o \n");
	printf(" * Mover carta do descarte para pilha: d\n");
	printf(" * Abrir uma carta do monte sobre o descarte\n");
	printf(" * Mover todas as cartas abertas de uma das 7 pilhas para outra: m \n");
	printf(" * Encerrar jogo: x \n");
	printf("\n");
    */
    printw("\n\nJogada: ");
    scanf("%c", &c);


    if(c == 'x' || c == 'X') encerraJogo(solit);
    if(c == 'o' || c == 'O') abreMonte(solit);
    if(c == 'd' || c == 'D') moveDescarte(solit);
    if(c == 'm' || c == 'M') movePilha();
    return;
}

int main(int argc, char **argv){
    char c;
	jogo solit;
	solit = jogo_cria();

    inicia_jogo(solit);
 //   verificaJogada(c, solit);

    do {
        jogo_desenha(solit);

        //verificaJogada(c, solit);
        printw("\n** SELECIONE UMA OPCAO **\n");
        printw("\n* Abrir monte: o \n");
        printw(" * Mover carta do descarte para pilha: d\n");
        printw(" * Abrir uma carta do monte sobre o descarte\n");
        printw(" * Mover todas as cartas abertas de uma das 7 pilhas para outra: m \n");
        printw(" * Encerrar jogo: x \n");
        printw("\n");

        c = (char)tela_le(jogo_tela(solit));
        printw("%c\n", c);

        //if(c == 'x' || c == 'X') encerraJogo(solit);

        if(c == 'o' || c == 'O') abreMonte(solit);
        if(c == 'd' || c == 'D') moveDescarte(solit);
        if(c == 'm' || c == 'M') movePilha();

        //tela_escreve_direitado(jogo_tela(solit),"\n\nNNNANSDANA\n", 60);

        //tela_le(jogo_tela(solit));

	}while(c!='x'&& c!='X');

	jogo_destroi(solit);
	//if(c == 'n')
     //   printf("NNNANSDANA\n");

	/* relatório de memória */
	memo_relatorio();
	return 0;
}
