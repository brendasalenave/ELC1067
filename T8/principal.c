#include <stdio.h>

#include "grafo.h"


int main(){
    FILE *f;

    f = fopen("cidades.txt","r");
    if(f == NULL){
        printf("Nao foi possivel abrir arquivo. \n");
        return;

    }else{
        grafo_t* g = grafo_cria();
        grafo_destroi(g);


    }


    memo_relatorio();
    return 0;
}
