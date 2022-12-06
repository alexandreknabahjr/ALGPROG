/*
Este programa faz a leitura das notas obtidas por um estudante. A partir delas,
e possivel calcular a media ponderada do aluno, bem como e possivel informar
ao usuario se o aluno foi aprovado ou nao.
*/

#include <stdio.h> // Biblioteca com operacoes de I/O.

int main()
{
    // Entradas tipo float
    float n1,n2,n3;
    // Saida tipo float
    float media;

    printf("Digite a primeira nota: "); // Impressao das orientacoes ao usuario.
    scanf("%f", &n1);
    printf("Digite a segunda nota: ");
    scanf("%f", &n2);
    printf("Digite a terceira nota: ");
    scanf("%f", &n3);

    media = ((n1 * 2) + (n2 * 2) + (n3 * 3))/7; // Media calculada a partir dos pesos dados pelo exercicio.

    printf("\nMedia: %.1f", media); // Impressao da media final.

    if(media>6.0) // Se a media for maior do que 6
        printf("\nAluno aprovado.\n");

    if(media<6.0) // Se a media for menor do que 6
        printf("\nAluno reprovado.\n");

    return 0; // Encerra o programa e retorna 0 ao Sist Op.

}
