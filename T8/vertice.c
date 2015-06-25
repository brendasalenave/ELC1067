#include <string.h>

#include "vertice.h"
#include "memo.h"

vertice_t* vertice_cria(){
    vertice_t* v = (vertice_t*)memo_aloca(sizeof(vertice_t));

    v->nome = (char*)memo_aloca(30*sizeof(char));
    v->chave = (char*)memo_aloca(5*sizeof(char));

    //strcpy(v->nome,nome);
    //strcpy(v->chave,chave);
    //v->adjacentes = NULL;

    return v;
}

vertice_t* vertice_insere(vertice_t* v ,char* nome, char* chave){
    strcpy(v->nome,nome);
    strcpy(v->chave,chave);
    v->adjacentes = NULL;

    return v;
}

void vertice_libera(vertice_t* vertice){
    memo_libera(vertice->chave);
    memo_libera(vertice->nome);

    memo_libera(vertice);
}
