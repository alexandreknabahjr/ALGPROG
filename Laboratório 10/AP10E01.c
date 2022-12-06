/*
Este programa acha, por meio de uma funcao auxiliar,
o valor maximo de um dado vetor, assim como o valor
minimo desse mesmo vetor.
*/
#include <stdio.h> // Biblioteca com operacoes de I/O

// Definicao da constante que se refere ao tamanho maximo do vetor
#define TAMMAX 20

// Assinatura da funcao auxiliar
void min_e_max(double vetor[], int tamanho, double *menor, double *maior);

int main()
{
    // Indice tipo int do loop
    int i;
    // Variavel tipo int do tamanho do vetor
    int tamanho;
    // Vetor tipo double
    double vetor[TAMMAX];
    // Variaveis tipo double
    double menor, maior;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    printf("Digite os elementos do vetor de tamanho %d: ", tamanho);

    // Preenchimento do vetor
    for(i = 0; i < tamanho; i++)
        scanf("%lf", &vetor[i]);

    // Chamada da funcao auxiliar
    min_e_max(vetor, tamanho, &menor, &maior);

    // Impressao dos resultados
    printf("\nElemento maximo: %.1lf", maior);
    printf("\nElemento minimo: %.1lf", menor);

    // Salta duas linhas
    printf("\n\n");

    return 0; // Encerra o programa e retorna 0 ao Sist Op.
}

// Funcao auxiliar sem retorno
void min_e_max(double vetor[], int tamanho, double *menor, double *maior)
{
    // Indice tipo int do loop
    int i;

    // Inicializacao de *maior e *menor na primeira posicao do vetor
    *maior = vetor[0];
    *menor = vetor[0];

    for(i = 0; i < tamanho; i++)
    {
        if(vetor[i]> *maior)
            *maior = vetor[i]; // *maior recebe o maior valor do vetor na posicao i
        else
            if(vetor[i] < *menor)
                *menor = vetor[i]; // *menor recebe o menor valor do vetor na posicao i
    }
}
