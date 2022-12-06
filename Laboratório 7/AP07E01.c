/*
Este programa faz uma serie de operacoes com uma matriz 6 x 4.
Primeiramente, o programa preenche uma matriz 6 x 4 com numeros
inteiros aleatorios. Em segundo lugar, troca de posicao os 4 elementos
da primeira linha com os 4 primeiros elementos da primeira coluna.
Depois disso, o maior elemento dessa matriz e encontrado. Por ultimo,
um vetor armazena o produto de cada coluna da matriz modificada.
*/

#include <stdio.h> // Biblioteca com operacoes de I/O
#include <stdlib.h> // Biblioteca com funcoes de manipulacao de alocacao de memoria, controle de processos e conversoes
#include <math.h> // Biblioteca com funcoes matematicas
#include <time.h> // Biblioteca com funcoes de manipulacao de datas e horarios

// Definicao das constantes
#define LINHAS 6
#define COLUNAS 4
#define INICIO 0
#define FIM 20

int main()
{
    // Declaracao de uma matriz de tipo int
    int matriz[LINHAS][COLUNAS];
    // Declaracao de um vetor auxiliar do tipo int
    int vetor_auxiliar[COLUNAS - 1];
    // Declaracao de um vetor produto do tipo int
    int vetor_produto[COLUNAS];
    // Declaracao de variaveis do tipo int
    int maior, produto;
    // Indices e variaveis de controle do looop
    int l, c, maiorL, maiorC;

    srand(time(NULL)); // Geracao de uma semente temporal

    // Preenchimento da matriz 6 x 4 com numeros aleatorios entre [0,20]
    for(l = 0; l < LINHAS; l++)
    {
        for(c = 0; c < COLUNAS; c++)
        {
            matriz[l][c] = round(INICIO + ((float)rand() / RAND_MAX ) * (FIM - INICIO));
        }
    }

    // Impressao da matriz 6 x 4 randomizada
    printf("Matriz 6 x 4 randomizada:\n\n");
    for(l = 0; l < LINHAS; l++)
    {
        for(c = 0; c < COLUNAS; c++)
        {
            printf("%2d\t", matriz[l][c]);
        }
        printf("\n\n");
    }

    printf("\n\n\n");

    // Troca dos elementos de uma matriz 6 x 4
    for(l = 0; l < COLUNAS - 1; l++)
    {
        for(c = 0; c < COLUNAS - 1; c++)
        {
            vetor_auxiliar[c] = matriz[0][c + 1];
            matriz[0][c + 1] = matriz[l + 1][0];
            matriz[l + 1][0] = vetor_auxiliar[c];
        }
    }

    // Impressao da matriz 6 x 4 randomizada com elementos trocados
    printf("Matriz 6 x 4 com elementos trocados:\n\n");
    for(l = 0; l < LINHAS; l++)
    {
        for(c = 0; c < COLUNAS; c++)
        {
            printf("%2d\t", matriz[l][c]);
        }
        printf("\n\n");
    }

    printf("\n\n");

    // Inicializacao das variaveis fora do loop while
    c = 0;
    maior = matriz[0][c];
    maiorL = 0;
    maiorC = 0;
    // Loop while que procura o maior elemento da matriz 6 x 4
    while(c < COLUNAS)
    {
        l = 1;
        while(l < LINHAS)
        {
            if(maior < matriz[l][c])
            {
                maior = matriz[l][c];
                maiorL = l; // Contador de linhas
                maiorC = c; // Contador de colunas
            }
            l++;
        }
        c++;
    }

    // Impressao da linha e coluna do maior elemento
    printf("O maior elemento, %2d, esta localizado na linha %1d e na coluna %1d.\n\n\n", maior, maiorL, maiorC);

    // Preenchimento de um vetor com o produto de cada coluna
    for (c = 0; c < COLUNAS; c++)
    {
        produto = 1;
        for (l = 0; l < LINHAS; l++)
        {
            produto *= matriz[l][c];
        }
        vetor_produto[c] = produto;
    }

    // Impressao do vetor preenchido com o produto de cada coluna
    printf("Vetor preenchido com o produto de cada coluna:\n\n");
    for(c = 0; c < COLUNAS; c++)
        printf("%9d\t", vetor_produto[c]);

    printf("\n\n\n");

    return 0; // Encerra o programa e retorna 0 ao Sist Op.
}
