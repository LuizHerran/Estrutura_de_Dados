#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Definindo o tamanho da linha.
#define TAM_LIN 100

int main(){
        FILE *arquivo = fopen("dados.csv", "r");
        //caso de erro ao abrir o arquivo.
        if(arquivo == NULL){
            perror("Erro ao abrir o arquivo");
            return 1;
        }
        //Declarando a variavel como tamanho da linha.
        char linha[TAM_LIN];

        //Declarando colunas.
        char *coluna1, *coluna2, *coluna3, *coluna4;

        //Lê o cabeçalho
        fgets(linha, TAM_LIN, arquivo);
        linha[strcspn(linha, "\n")] = '\0';

        //Definindo as colunas.
        coluna1 = strtok(linha, ",");
        coluna2 = strtok(NULL, ",");
        coluna3 = strtok(NULL, ",");
        coluna4 = strtok(NULL, ",");

        printf("%-25s | %-10s | %-10s | %-10s |\n", coluna1, coluna2, coluna3, coluna4);
        printf("--------------------------------------------------------------\n");

        //Leitura do arquivo.
        while (fgets(linha, TAM_LIN, arquivo) != NULL){

            //Substituindo \n por \0 no final da linha.
            linha[strcspn(linha, "\n")] = '\0';

            //Dados das tabelas.
            coluna1 = strtok(linha, ",");
            coluna2 = strtok(NULL, ",");
            coluna3 = strtok(NULL, ",");
            coluna4 = strtok(NULL, ",");
            

            printf("%-22s | %-10s | %-5s | %-5s\n", coluna1, coluna2, coluna3, coluna4);
        }
        //Fecha o arquivo.
        fclose(arquivo);
        return 0;
}