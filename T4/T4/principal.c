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

/*abrir uma carta do monte sobre o descarte*/
void move_monte_descarte(jogo solit){
    carta c = pilha_remove_carta(jogo_monte(solit));
    carta_abre(c);
    pilha_insere_carta(jogo_descartes(solit), c);
}

/* Mover carta do descarte para pilha */
void move_descarte_pilha(jogo solit){
    int n;
    printf ("\nInforme pilha: \n");
    scanf ("%d",&n);
    if (n > 7 || n < 1){
        printf ("Valor invalido!\n");
        return;
    }
    if (!pilha_vazia(jogo_descartes(solit))){
        carta c = pilha_remove_carta(jogo_descartes(solit));
        pilha_insere_carta(jogo_pilha(solit, n),c);
    }
    else
        printf ("Descarte vazio\n");
}

/* virar todas as cartas do descarte no monte vazio */
void vira_carta_descartes(jogo solit){
    if(!pilha_vazia(jogo_monte(solit))){
        printf("Monte nao vazio !");
        return;
    }
    while(!pilha_vazia(jogo_descartes(solit))){
        carta c = pilha_remove_carta(jogo_descartes(solit));
        carta_abre(c);
        pilha_insere_carta(jogo_monte(solit), c);
    }
    return;
}

void movePilha(jogo solit){
    int p1, p2;
    printf("Mover da pilha ");
    scanf("%d", &p1);
    printf(" para pilha: ");
    scanf("%d", &p2);
    if (p1 > 7 || p1 < 1 || p2 > 7 || p2 < 1){
        printf ("Valor invalido!\n");
        return;
    }

    //enquanto carta aberta, remove carta de p1 e insere em p2
    while(!pilha_vazia(jogo_pilha(solit, p1))){
        carta c = pilha_remove_carta(jogo_pilha(solit, p1));

        if(!carta_aberta(c)) return;

        pilha_insere_carta(jogo_pilha(solit, p2),c);
    }

    return;
}


int main(int argc, char **argv){
    char c;
	jogo solit;
	solit = jogo_cria();

    inicia_jogo(solit);

    do {
        jogo_desenha(solit);

        printw(" * Abrir monte: \n");
        printw(" * Mover carta do descarte para pilha: d\n"); /* Feito */
        printw(" * Abrir uma carta do monte sobre o descarte: o\n"); /* Feito */
        printw(" * Virar todas as cartas do descarte no monte vazio: v\n"); /* Feito */
        printw(" * Mover todas as cartas abertas de uma das 7 pilhas para outra: m\n"); /* Feito */
        printw(" * Encerrar jogo: x \n");
        printw("\n");
        printw("\n** Jogada: **\n\n");

        c = (char)tela_le(jogo_tela(solit));
        printw("%c\n", c);

        if(c == 'o' || c == 'O') move_monte_descarte(solit);
        if(c == 'd' || c == 'D') move_descarte_pilha(solit);
        if(c == 'v' || c == 'V') vira_carta_descartes(solit);
        if(c == 'm' || c == 'M') movePilha(solit);

	}while(c!='x'&& c!='X');

	jogo_destroi(solit);

	/* relatório de memória */
	memo_relatorio();
	return 0;
}
