/*
Este e um programa de criptografia. Dada uma mensagem, o programa
troca os caracteres da string original por caracteres 4 posicoes a direita
na primeira passada. Na segunda passada, o programa inverte as posicoes
dos caracteres da string. Na ultima passada, ele substitui os caracteres
a partir da metade da string por caracteres 2 posicoes a esquerda.
*/

#include <stdio.h>  // Biblioteca com operacoes de I/O.
#include <string.h>  // Biblioteca com funcoes de manipulacao de strings.

#define TAM 1000 // Constante que se refere ao tamanho maximo do vetor

int main()
{
    // Indice do loop
    int i;
    // Entrada e saida da primeira passada
    char mensagem[TAM];
    // Saida das segunda e terceira passadas
    char mensagem_auxiliar[TAM + 1];

    printf("Digite uma frase: ");
    fgets(mensagem, TAM + 1, stdin); // Leitura da frase com a funcao fgets().

    mensagem[strlen(mensagem) - 1] = '\0'; // Elimina o '\n' lido pelo fgets()

    printf("\n\nMensagem original: %s\n", mensagem);

    for(i = 0; i < strlen(mensagem); i++)
    {
        if(mensagem[i] >= 'A' && mensagem[i] <= 'z')
        {
            mensagem[i] = mensagem[i] + 4; // Substitui os caracteres originais por caracteres 4 posicoes para a direita
        }
    }

    printf("Primeira passada: %s\n", mensagem);

    for(i = 0; i < strlen(mensagem); i++)
        mensagem_auxiliar[i] = mensagem[strlen(mensagem) - i - 1]; // Inverte as posicoes dos caracteres da mensagem original

    mensagem_auxiliar[strlen(mensagem)] = '\0';

    printf("Segunda passada: %s\n", mensagem_auxiliar);

    for(i = 0; i < (strlen(mensagem_auxiliar) / 2); i++)
        mensagem_auxiliar[i + (strlen(mensagem_auxiliar) / 2)] = mensagem_auxiliar[i + (strlen(mensagem_auxiliar) / 2)] - 2;
        // Substitui os caracteres da metade da string em diante por caracteres 2 posicoes para a esquerda

    printf("Terceira passada: %s\n\n", mensagem_auxiliar);

    return 0; // Encerra o programa e retorna 0 ao Sist Op.
}
