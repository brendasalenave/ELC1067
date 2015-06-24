#include <stdio.h>

#include "grafo.h"
#include "vertice.h"


int main(){
    FILE *f;

    f = fopen("cidades.txt","r");
    if(f == NULL){
        printf("Nao foi possivel abrir arquivo. \n");
        return -1;

    }else{
        grafo_t* g = grafo_cria();
        vertice_t* v = NULL;

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

            printf("\nNUMERO DE VERTICES: %d", nVertices);
            printf("\nNUMERO DE ARESTAS: %d\n\n", nArestas);
            //break;

            for(k = 0; k < nVertices; k++){
                fflush(stdin);

                i = 0;
                c = fgetc(f);
                while(c != '\n'){  //avança até nova linha
                    c = fgetc(f);
                }

                do{
                    c = fgetc(f);
                    chave[i] = c;
                    i++;
                }while(c != ' ');
                    chave[i] = '\0';

                i = 0;
                while(c != '\n'){
                    nome[i] = c;
                    c = fgetc(f);
                    i++;
                }
                nome[i] = '\0';

                printf("%s %s\n", chave, nome);
                //v = vertice_cria(nome, chave);
                //printf("CHEGA AQUI");
                //bool tmp = grafo_insere_vertice(g, v);
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
