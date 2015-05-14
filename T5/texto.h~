/*
 * texto.h
 * Funções para implementação de editor de texto.
 */
#ifndef _TEXTO_H_
#define _TEXTO_H_

#include "tela.h"
#include "lista.h"

typedef struct {
	char *nome;     /* nome do arquivo sendo editado */
	lista_t* linhas; /* lista de linhas do arquivo */
	int nlin;       /* numero de linhas no texto (numero de elementos atualmente em linhas) */
	int lincur;     /* linha onde esta o cursor (comeca em 0) */
	int colcur;     /* coluna onde esta o cursoe na linha acima */
	int lin1;       /* linha do texto mostrada na primeira linha da tela */
	int col1;       /* coluna do texto mostrada na primeira coluna da tela */

	tela_t tela;    /* tela do editor */
} texto_t;


texto_t* texto_inicia(void);
void texto_destroi(texto_t* txt);

/* retorna a estrutura tela_t */
tela_t* texto_tela(texto_t* txt);

/* apenas desenha o que tiver que desenhar na tela */
void texto_desenha_tela(texto_t *txt);

/* desenha e atualiza a tela */
void texto_atualiza_tela(texto_t *txt);

/* processa os comandos do usuário */
bool texto_processa_comandos(texto_t* txt);

void texto_le_arquivo(texto_t *txt, char *nome);

void texto_move_esq(texto_t *txt);
void texto_move_dir(texto_t *txt);
void texto_move_baixo(texto_t *txt);
void texto_move_cima(texto_t *txt);

void texto_insere_char(texto_t *txt, char c);

void texto_remove_char(texto_t *txt);
void texto_ajeita_tela(texto_t *txt);
void texto_gruda_linha(texto_t *txt);
void texto_quebra_linha(texto_t *txt);


#endif /* _TEXTO_H_ */
