#include <stdio.h>
#include <stdlib.h>

void leAlunos(int* matriculas, char** nomes, int* n){
    FILE *f = fopen("alunos.txt","r");
    int mat, i;
    int linha = 0;
    char c;
    char nome[50];

    while(FEOF(f) != 0){
        fscanf(f,"%d", &mat);
        c = fgetc(f);

        while(c == ' '){
            c = fgetc(f);
        }

        while(c != '\n'){
            nome[i] = c;
            c = fgetc(f);
            i++;
        }
        nome[i] = '\0';
        matriculas[linha] = mat;
        strcpy(nomes[linha], nome);
        linha++;
    }
    n = linha;
    fclose(f);
}

int main(int argc, char** argv){
    int matricula[50];
    char nomes[50][50];
    int n;

    leAlunos(matricula, nomes, &n);

}

