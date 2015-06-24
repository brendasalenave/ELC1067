#include <string.h>

#include "vertice.h"
#include "memo.h"

vertice_t* vertice_cria(char* nome, char* chave){
    vertice_t* v = (vertice_t*)memo_aloca(sizeof(vertice_t));
    strcpy(v->nome,nome);
    strcpy(v->chave,chave);
    v->adjacentes = NULL;

    return v;
}

