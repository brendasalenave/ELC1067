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
        int i, k;

        while(feof(f) == 0){
            //fflush(stdin);
            if(fscanf(f,"%d %d", &nVertices, &nArestas) < 0)
                break;
            fflush(stdin);

            printf("\nNUMERO DE VERTICES: %d", nVertices);
            printf("\nNUMERO DE ARESTAS: %d\n\n", nArestas);
            //break;

            for(k = 0; k < nVertices; k++){
                i = 0;
                c = fgetc(f);
                while(c != '\n'){  //avança até nova linha
                    c = fgetc(f);
                    fflush(stdin);
                }

                do{
                    c = fgetc(f);
                    fflush(stdin);
                    chave[i] = c;
                    i++;
                }while(c != ' ');
                    chave[i] = '\0';

                //while(c == ' '){ //avança até a proxima palavra
                //    c = fgetc(f);
                //}
                i = 0;
                while(c != '\n'){
                    nome[i] = c;
                    c = fgetc(f);
                    fflush(stdin);
                    i++;
                }
                nome[i] = '\0';

                printf("\n%s %s\n", chave, nome);
            }
            break;
        }
        grafo_destroi(g);
        memo_libera(nome);
        memo_libera(chave);
    }


    memo_relatorio();
    return 0;
}
