#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int leAlunos(int* matriculas, char** nomes,char* aluno, int* n);
//void leNotas(int matricula, float* nota1, float* nota2);
float* buscaAluno(int* vetMatricula, char *vetNome);
int countLine();


 int leAlunos(int* matriculas, char** nomes, char* aluno, int* n){
    int mat, i;
    int linha = 0;
    int k = 1;
    int j = 0;
    int* vetMatriculas;
    char* vetNomes;
    char c;

    int nlinha = countLine();
    vetMatriculas = (int*) malloc (nlinha * sizeof(int));
    vetNomes = (char*) malloc (nlinha* sizeof(char));

    char* nome;
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
            vetNomes[j] = *nome;
            vetMatriculas[j] = mat;
            j++;

        }

        matriculas[linha] = mat;
        strcpy(nomes[linha], nome);
        linha++;
    }
    *n = linha;

    fclose(f);

    float* p = (float*) malloc (nlinha * sizeof(float));
    p =  buscaAluno(vetMatriculas, vetNomes);
    for(i=0; i< nlinha; i++){
        printf("%s %f", vetNomes[i], p[i]);
    }

    free(nome);
    free(vetMatriculas);
    free(vetNomes);

    if(k == 1)
        return 1;
    else
        return 0;
}

float* buscaAluno(int* vetMatricula, char* vetNome){

    float n1, n2;
    float* vetMedias;
    int mat, i;
    int linha = countLine();
    FILE *f;

    f = fopen("notas.txt","r");
    if(f == NULL){
        printf("Não foi possível abrir arquivo. \n");
        return;
    }

    vetMedias = (float*) malloc (linha * sizeof(float));

    while(feof(f) == 0){
        if(fscanf(f,"%d", &mat) < 0)
            break;

        fscanf(f,"%f %f", &n1, &n2);

        for(i=0; i<linha; i++){
            if(mat == vetMatricula[i])
                vetMatricula[i] = ((n1+n2)/2);
        }
    }

        fclose(f);
        return vetMedias;
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
    //printf("Numero de linhas: %d\n\n", n);

    return n;
}

int main(int argc, char** argv){
    int* matricula;
    char** nomes;
    int n, i;
    int p = countLine();

    char* aluno;
    aluno = (char *) malloc (50 * sizeof(char)); //alocando a string aluno */

    nomes = (char**)malloc(p * sizeof(char*));
    for ( i = 0; i < p; i++ ){
        nomes[i] = (char*) malloc (50 * sizeof(char)); //aqui tu vai estar alocando as strings
    }

    matricula = (int*)malloc(50*sizeof(int));

    //printf("Nome do aluno: ");
    scanf("%s", aluno);

    int k = leAlunos(matricula, nomes, aluno, &n);
    if(k == 1){
        printf("\nALUNO NAO ENCONTRADO !\n");
    }

    free(matricula);
    free(nomes);

    return 0;

}
