#include <stdio.h>

#include "grafo.h"


int main(){
    FILE *f;

    f = fopen("cidades.txt","r");
    if(f == NULL){
        printf("Nao foi possivel abrir arquivo. \n");
        return -1;

    }else{
        grafo_t* g = grafo_cria();

        char c;
        char* nome = (char*)memo_aloca(30*sizeof(char));
        char* chave = (char*)memo_aloca(4*sizeof(char));

        int nVertices = 0;
        int nArestas = 0;
        int i = 0;

        while(feof(f) == 0){
            if(fscanf(f,"%d %d", &nVertices, &nArestas) < 0)
                break;

            printf("\nNUMERO DE VERTICES: %d", nVertices);
            printf("\nNUMERO DE ARESTAS: %d", nArestas);
            //break;

            c = fgetc(f);
            while(c != '\n'){  //avança até nova linha
                c = fgetc(f);
            }

            do{
                c = fgetc(f);
                chave[i] = c;
                i++;
            }while(c != ' ');

            //while(c == ' '){ //avança até a proxima palavra
            //    c = fgetc(f);
            //}
            i = 0;
            do{
                c = fgetc(f);
                nome[i] = c;
                i++;
            }while(c != ' ');


            //fscanf(f,"%s", &chave);

            printf("\n%s  %s", chave, nome);
            break;

        }
        grafo_destroi(g);
        memo_libera(nome);
        memo_libera(chave);
    }


    memo_relatorio();
    return 0;
}
