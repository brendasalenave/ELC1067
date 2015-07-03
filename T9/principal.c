#include <stdio.h>

#include "grafo.h"
#include "vertice.h"
#include "memo.h"


int main(){
    FILE *f;

    f = fopen("cidades.txt","r");
    if(f == NULL){
        printf("Nao foi possivel abrir arquivo. \n");
        return -1;

    }else{
        grafo_t* g = grafo_cria();
        //vertice_t* v = vertice_cria();

        char c;
        char* nome = (char*)memo_aloca(30*sizeof(char));
        char* chave = (char*)memo_aloca(5*sizeof(char));
        char* chave2 = (char*)memo_aloca(5*sizeof(char));


        int nVertices = 0;
        int nArestas = 0;
        int i, k;

        while(feof(f) == 0){
            bool tmp;
            if(fscanf(f,"%d %d", &nVertices, &nArestas) < 0)
                break;

            printf("\nVertices: %d", nVertices);
            printf("\nArestas: %d\n", nArestas);

            while(c != '\n'){  //avança até nova linha
                    c = fgetc(f);
            }

            for(k = 0; k < nVertices; k++){
                fflush(stdin);

                i = 0;
                c =  fgetc(f);
                while(c != ' '){
                    chave[i] = c;
                    i++;
                    c = fgetc(f);
                }
                chave[i] = '\0';

                i = 0;
                c = fgetc(f);
                while(c != '\n'){
                    nome[i] = c;
                    c = fgetc(f);
                    i++;
                }
                nome[i] = '\0';

                //c = fgetc(f);

                printf("'%s' - '%s'\n", chave, nome);
                vertice_t* v = vertice_cria();
                v = vertice_insere(v, nome, chave);
                tmp = grafo_insere_vertice(g, v);
                //vertice_libera(v);
                //memo_libera(v->nome);
                //memo_libera(v->chave);
            }

            for(k = 0; k < nArestas; k++){
                fflush(stdin);

                i = 0;
                c = fgetc(f);
                while(c != ' '){
                    chave[i] = c;
                    i++;
                    c = fgetc(f);
                }
                chave[i] = '\0';

                i = 0;
                c = fgetc(f);
                while(c != '\n'){
                    if(c!=' ')chave2[i] = c;
                    else chave2[i] = '\0';
                    c = fgetc(f);
                    if((k == (nArestas - 1))) break;
                    i++;
                }
                printf("'%s' '%s'  \n", chave, chave2);
                tmp = grafo_insere_aresta(g, chave, chave2);
            }
        }

        grafo_imprime(g);
        grafo_caminho_curto(g,"SMA","CH1");
        grafo_destroi(g);
        //vertice_libera(v);
        memo_libera(nome);
        memo_libera(chave);
        memo_libera(chave2);

    }

    printf("\n");
    memo_relatorio();

    return 0;
}
