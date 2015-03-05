#include <stdio.h>

/*
- Lê: 1. Matricula (número)
      2. Nome: (string)
- Escreve: saida.txt
*/

void main (){
    int matricula;
    char nome[100];
    FILE *f;

    printf("Matricula: ");
    scanf("%d", &matricula);
    printf("Nome: ");
    scanf("%s", nome);

    f = fopen("saida.txt", "w");
    fprintf(f,"%d %s \n", matricula, nome);
    //fprintf(stdout, "ola \n");
    fclose(f);

}
