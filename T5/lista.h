#ifndef _LISTA_H_
#define _LISTA_H_

/*struct conteudo{
    char* info;
};

typedef struct Elem* lista_t;*/

typedef struct lista {
    char* info;
    struct lista* ant;
    struct lista* prox;
}lista_t;

//lista_t* cria_lista();

lista_t* insere_inicio(lista_t* l, char* str);
lista_t* insere_final(lista_t* li, char* str);
void libera_lista(lista_t* li);
int consulta_lista_pos(lista_t* li, int pos, char *str);
lista_t* buscar(lista_t* inicio, char* str);
//lista_t* remove_lista(lista_t* inicio);
lista_t* remove_lista_inicio(lista_t* li);
//int remove_lista(lista_t* li, char* str);
//int remove_lista_fim(lista_t* li);
int tamanho_lista(lista_t* li);
int vazia(lista_t* l);
void imprime_lista(lista_t* li);
lista_t* insere (lista_t* l, char* str);

#endif
