/*
Este programa compara dois vetores informados pelo usuario
e guarda, em um terceiro vetor, os elementos que fazem parte
da interseccao dos vetores.
*/

#include <stdio.h> // Biblioteca com operacoes de I/O

// Definicao da constante que se refere ao tamanho maximo do vetor
#define TAMMAX 1000

// Assinatura da funcao auxiliar
int interseccao(int vetor_i[], int vetor_j[], int vetor_k[], int n);

int main()
{
    // Vetores tipo int
    int vetor_i[TAMMAX], vetor_j[TAMMAX], vetor_k[TAMMAX];
    // Variaveis tipo int dos loops
    int i, j, k;
    // Variavel tipo int do tamanho dos vetores
    int n;
    // Declaracao e inicializacao da variavel tipo int tamanho
    int tamanho = 0;

    printf("Digite o numero de elementos dos vetores i e j: ");
    scanf("%d", &n);

    printf("\nDigite os elementos do vetor i: ");
    // Preenchimento do vetor i
    for(i = 0; i < n; i++)
        scanf("%d", &vetor_i[i]);

    printf("\nDigite os elementos do vetor j: ");
    // Preenchimento do vetor j
    for(j = 0; j < n; j++)
        scanf("%d", &vetor_j[j]);

    tamanho = interseccao(vetor_i, vetor_j, vetor_k, n); // tamanho recebe o retorno da funcao auxiliar

    printf("\nInterseccao: ");
    for (k = 0; k < tamanho; k++)
        printf("%d ", vetor_k[k]);

    // Pula uma linha
    printf("\n");

    return 0; // Encerra o programa e retorna 0 ao Sist Op.
}

// Funcao tipo int com retorno
int interseccao(int vetor_i[], int vetor_j[], int vetor_k[], int n)
{
    // Indice tipo int dos loops
    int i, j;
    // Variavel tipo int que conta os elementos de vetor_k[]
    int k = 0;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(vetor_i[i] == vetor_j[j]) // Se o elemento dos dois vetores forem iguais
            {
                vetor_k[k] = vetor_i[i]; // vetor_k[] recebe o elemento de vetor_i[] da posicao i
                k++; // Contador do tamanho do vetor_k[]
            }
        }
    }

    return k; // Retorna k
}
