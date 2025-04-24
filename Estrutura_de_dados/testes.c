#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_LIN 100

int main(){
    FILE *arquivo = fopen("dados.csv", "r");

    if(arquivo == NULL){
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    char linha[TAM_LIN];
    char *coluna1, *coluna2, *coluna3, *coluna4;

    // Lê o cabeçalho
    fgets(linha, TAM_LIN, arquivo);
    linha[strcspn(linha, "\n")] = '\0';

    coluna1 = strtok(linha, ",");
    coluna2 = strtok(NULL, ",");
    coluna3 = strtok(NULL, ",");
    coluna4 = strtok(NULL, ",");

    printf("%-25s | %-10s | %-10s | %-10s\n", coluna1, coluna2, coluna3, coluna4);
    printf("---------------------------------------------------------------\n");

    while (fgets(linha, TAM_LIN, arquivo) != NULL){
        linha[strcspn(linha, "\n")] = '\0';

        coluna1 = strtok(linha, ",");
        coluna2 = strtok(NULL, ",");
        coluna3 = strtok(NULL, ",");
        coluna4 = strtok(NULL, ",");

        printf("%-22s | %-10s | %-5s | %-5s\n", coluna1, coluna2, coluna3, coluna4);
    }

    fclose(arquivo);
    return 0;
}
