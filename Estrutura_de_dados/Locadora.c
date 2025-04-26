#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILMES 100
#define TAM_NOME_FILME 30
#define TAM_NOME_CATEGORIA 12

typedef struct
{
    char nome[TAM_NOME_FILME];
    char categoria[TAM_NOME_CATEGORIA];
    float nota;
    int duracao;
} Filme;

int charToAscii(char c)
{
    return (int)c;
}

int recuperarConteudoExcel(Filme filmes[])
{

    // Abre arquivo csv
    FILE *arquivo = fopen("dados.csv", "r");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return 0;
    }

    char linha[256];
    int i = 0;

    // Ignora a primeira linha (cabeçalho)
    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo))
    {
        char *token;

        // Lê nome do filme
        token = strtok(linha, ",");
        strncpy(filmes[i].nome, token, TAM_NOME_FILME);

        // Lê categoria
        token = strtok(NULL, ",");
        strncpy(filmes[i].categoria, token, TAM_NOME_CATEGORIA);

        // Lê nota
        token = strtok(NULL, ",");
        if (token)
            filmes[i].nota = atof(token);

        // Lê duração
        token = strtok(NULL, ",");
        if (token)
            filmes[i].duracao = atoi(token);

        i++;
    }

    fclose(arquivo);

    return i;
}

void mostrarDadosOrdenados(Filme filmes[], int qtd)
{
    // Mostra os dados lidos
    printf("Filmes lidos:\n");
    for (int j = 0; j < qtd; j++)
    {
        printf("Filme: %-22s | Categoria: %-15s | Nota: %-4.1f | Duracao: %dh%dmin\n",
               filmes[j].nome, filmes[j].categoria, filmes[j].nota, filmes[j].duracao / 60, filmes[j].duracao % 60);
    }
}

void ordenarFilmesPorNome(Filme filmes[], int qtd)
{

    char aux[TAM_NOME_FILME];
    int i, j;
    float apoio = 0;
    for (i = 0; i < qtd - 1; i++) {

        for (j = 0; j < qtd - i - 1; j++) {

            for (int k = 0; k < TAM_NOME_FILME; k++)
            {
                if (charToAscii(filmes[j].nome[k]) > charToAscii(filmes[j + 1].nome[k]) || filmes[j + 1].nome[k] == '\n')
                {
                    strcpy(aux, filmes[j + 1].nome);
                    strcpy(filmes[j + 1].nome, filmes[j].nome);
                    strcpy(filmes[j].nome, aux);

                    strcpy(aux, filmes[j + 1].categoria);
                    strcpy(filmes[j + 1].categoria, filmes[j].categoria);
                    strcpy(filmes[j].categoria, aux);

                    apoio = filmes[j + 1].nota;
                    filmes[j + 1].nota = filmes[j].nota;
                    filmes[j].nota = apoio;

                    apoio = filmes[j + 1].duracao;
                    filmes[j + 1].duracao = filmes[j].duracao;
                    filmes[j].duracao = apoio;
                    break;
                }
                else if (filmes[j].nome[k] == '\n')
                {
                    break;
                }
                else if (charToAscii(filmes[j].nome[k]) == charToAscii(filmes[j + 1].nome[k]))
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
        }
    }
    mostrarDadosOrdenados(filmes, qtd);
}

void ordenarFilmesPorAvaliacao(Filme filmes[], int qtd)
{
    char aux[TAM_NOME_FILME];
    int i, j;
    float apoio = 0;
    for (i = 0; i < qtd - 1; i++) {
        printf("\n[%d] ", i);

        for (j = 0; j < qtd - i - 1; j++) {
            printf("%d, ", j);

            if ((filmes[j].nota) > (filmes[j + 1].nota))
            {
                strcpy(aux, filmes[j + 1].nome);
                strcpy(filmes[j + 1].nome, filmes[j].nome);
                strcpy(filmes[j].nome, aux);

                strcpy(aux, filmes[j + 1].categoria);
                strcpy(filmes[j + 1].categoria, filmes[j].categoria);
                strcpy(filmes[j].categoria, aux);

                apoio = filmes[j + 1].nota;
                filmes[j + 1].nota = filmes[j].nota;
                filmes[j].nota = apoio;

                apoio = filmes[j + 1].duracao;
                filmes[j + 1].duracao = filmes[j].duracao;
                filmes[j].duracao = apoio;
            }
        }
    }
    mostrarDadosOrdenados(filmes, qtd);
}

void ordenarFilmesPorDuracao(Filme filmes[], int qtd)
{
    char aux[TAM_NOME_FILME];
    int i, j;
    float apoio = 0;
    for (i = 0; i < qtd - 1; i++) {
        printf("\n[%d] ", i);

        for (j = 0; j < qtd - i - 1; j++) {
            printf("%d, ", j);

            if ((filmes[j].duracao) > (filmes[j + 1].duracao))
            {
                strcpy(aux, filmes[j + 1].nome);
                strcpy(filmes[j + 1].nome, filmes[j].nome);
                strcpy(filmes[j].nome, aux);

                strcpy(aux, filmes[j + 1].categoria);
                strcpy(filmes[j + 1].categoria, filmes[j].categoria);
                strcpy(filmes[j].categoria, aux);

                apoio = filmes[j + 1].nota;
                filmes[j + 1].nota = filmes[j].nota;
                filmes[j].nota = apoio;

                apoio = filmes[j + 1].duracao;
                filmes[j + 1].duracao = filmes[j].duracao;
                filmes[j].duracao = apoio;
            }
        }
    }
    mostrarDadosOrdenados(filmes, qtd);
}

void ordenarFilmesPorCategoria(Filme filmes[], int qtd)
{
    char aux[TAM_NOME_FILME];
    int i, j;
    float apoio = 0;
    for (i = 0; i < qtd - 1; i++) {
        printf("\n[%d] ", i);

        for (j = 0; j < qtd - i - 1; j++) {
            printf("%d, ", j);

            for (int k = 0; k < TAM_NOME_CATEGORIA; k++)
            {
                if (charToAscii(filmes[j].categoria[k]) > charToAscii(filmes[j + 1].categoria[k]) || filmes[j + 1].categoria[k] == '\n')
                {
                    strcpy(aux, filmes[j + 1].nome);
                    strcpy(filmes[j + 1].nome, filmes[j].nome);
                    strcpy(filmes[j].nome, aux);

                    strcpy(aux, filmes[j + 1].categoria);
                    strcpy(filmes[j + 1].categoria, filmes[j].categoria);
                    strcpy(filmes[j].categoria, aux);

                    apoio = filmes[j + 1].nota;
                    filmes[j + 1].nota = filmes[j].nota;
                    filmes[j].nota = apoio;

                    apoio = filmes[j + 1].duracao;
                    filmes[j + 1].duracao = filmes[j].duracao;
                    filmes[j].duracao = apoio;
                    break;
                }
                else if (filmes[j].categoria[k] == '\n')
                {
                    break;
                }
                else if (charToAscii(filmes[j].categoria[k]) == charToAscii(filmes[j + 1].categoria[k]))
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
        }
    }
    mostrarDadosOrdenados(filmes, qtd);
}

void gerarExcel(Filme filmes[], int qtd)
{
    // Escrever um novo Excel
    FILE *arquivo = fopen("novo_arquivo.csv", "w"); // Abre em modo escrita (sobrescreve), o 'w' serve para fazer a escrita no documento
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return; // está retornando, sem valor
    }
    // Escrever o cabeçalho do CSV
    fprintf(arquivo, "Nome, Categoria, Avaliação, Duração\n");

    // Escrever cada filme no arquivo CSV
    for (int i = 0; i < qtd; i++) {
        fprintf(arquivo, "%s,%s,%.1f,%dh%dmin\n", 
                filmes[i].nome, 
                filmes[i].categoria, 
                filmes[i].nota, 
                filmes[i].duracao / 60, filmes[i].duracao % 60);
        }
        fclose(arquivo);
}

int main()
{


    int op = 0;
    int qtd = 0;

    // Struct para armazenar os dados
    Filme filmes[MAX_FILMES];
    qtd = recuperarConteudoExcel(filmes);

    do
    {
        printf("\n//=============================================\\\\\n");
        printf("||\tEscolha uma opcao:\n");
        printf("||\t01 - Ordenar pelo nome do filme\n");
        printf("||\t02 - Ordenar pelo filme mais avaliado:\n");
        printf("||\t03 - Ordenar pelo tempo de duracao\n");
        printf("||\t04 - Ordenar pela categoria do filme\n");
        printf("||\t05 - Gerar o novo Excel\n");
        printf("||\t06 - Sair\n");
        printf("\\\\==============================================//");
        scanf("%d", &op);

        printf("\n");
        switch (op)
        {
        case 1:
            ordenarFilmesPorNome(filmes, qtd);
            break;

        case 2:
            ordenarFilmesPorAvaliacao(filmes, qtd);
            break;

        case 3:
            ordenarFilmesPorDuracao(filmes, qtd);
            break;

        case 4:
            ordenarFilmesPorCategoria(filmes, qtd);
            break;
        
        case 5:
            gerarExcel(filmes, qtd);
             break;

        case 6:
            printf("Saindo...\n");
            break;
        }

    } while (op != 6);
}