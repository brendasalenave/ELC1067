#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int leAlunos(int* matriculas, char** nomes,char* aluno, int* n);
void leNotas(int matricula, float* nota1, float* nota2);
void buscaAluno(int matricula, char *nome);
int countLine();

void leNotas(int matricula, float* nota1, float* nota2){
    float n1, n2;
    int mat;
    FILE *f;

    f = fopen("notas.txt","r");
    if(f == NULL){
        printf("Não foi possível abrir arquivo. \n");
        return;
    }

    while(feof(f) == 0){
        if(fscanf(f,"%d", &mat) < 0)
            break;

        fscanf(f,"%f %f", &n1, &n2);

        if(mat == matricula){
            *nota1 = n1;
            *nota2 = n2;
            return;
        }

    }
        fclose(f);
        return;
}


 int leAlunos(int* matriculas, char** nomes, char* aluno, int* n){
    int mat, i;
    int j = 0;
    int linha = 0;
    int k = 1;
    int* vetMatriculas;
    char* vetNomes;
    char c;
    char* nome;

    int p = countLine();

    vetMatriculas = (int*)malloc(p*sizeof(int));
    vetNomes = (char*)malloc(p*sizeof(char));
    nome = (char*)malloc(50*sizeof(char));

    FILE *f;
    f = fopen("alunos.txt","r");
    if(f == NULL){
        printf("Não foi possível abrir arquivo. \n");
        return;
    }

    while(feof(f) == 0){

        if(fscanf(f,"%d", &mat) < 0)
            break;
        c = fgetc(f);

        while(c == ' '){
            c = fgetc(f);
        }

        i = 0;

        while(c != '\n'){
            nome[i] = c;
            c = fgetc(f);
            i++;
        }

        nome[i] = '\0';

        if(strstr(nome,aluno) != NULL){
            k = 0;
            buscaAluno(mat, nome);
        }

        matriculas[linha] = mat;
        strcpy(nomes[linha], nome);
        linha++;
    }
    *n = linha;

    fclose(f);

    free(vetMatriculas);
    free(vetNomes);
    free(nome);

    if(k == 1)
        return 1;
    else
        return 0;
}

void buscaAluno(int matricula, char* nome){
    float n1, n2, media;

   leNotas(matricula, &n1, &n2);
   media = (n1+n2)/2;
   printf("\n%.2f %s\n", media, nome);

    return;
}

int countLine(){
    int c;
    int n = 0;

    FILE *arq = fopen ("alunos.txt","r");

    if(arq == NULL){
        printf("Não foi possível abrir arquivo. \n");
        return 0;
    }
    while((c = fgetc(arq)) != EOF){
        if(c == '\n')
            n++;
    }
    fclose(arq);
    printf("Numero de linhas: %d\n\n", n);

    return n;
}

int main(int argc, char** argv){
    int* matricula;
    char** nomes;
    //char aluno[50];
    int n, i;
    int p = countLine();

    char* aluno;
    aluno = (char *) malloc (p * sizeof(char)); //alocando a string aluno */

    nomes = (char**)malloc(p * sizeof(char*));
    for ( i = 0; i < p; i++ ){
        nomes[i] = (char*) malloc (50 * sizeof(char)); //aqui tu vai estar alocando as strings
    }

    matricula = (int*)malloc(50 *sizeof(int));

    printf("Nome do aluno: ");
    scanf("%s", aluno);

    int k = leAlunos(matricula, nomes, aluno, &n);
    if(k == 1){
        printf("\nALUNO NAO ENCONTRADO !\n");
    }

    free(matricula);
    free(nomes);

    return 0;

}
