/*
Neste programa, o usuario decide o tamanho do vetor
e os elementos contidos nele. Alem disso, este programa
mostra a media dos elementos do vetor, o(s) menor(es)
elemento(s) do vetor, assim como o(s) maior(es) elemento(s)
do vetor.
*/

#include <stdio.h> // Biblioteca com operacoes de I/O.

#define TAMMAX 20 // Constante que se refere ao tamanho maximo do vetor

int main()
{
    // Indice do loop
    int i;
    // Entrada do tamanho do vetor
    int elementos;
    // Saida
    double media;
    // Variavel intermediaria e variavel de armazenamento
    double soma , vetor[TAMMAX];

    soma = 0; // Inicia a soma com zero

    printf("Digite o numero de elementos a serem lidos:  ");
    scanf("%d", &elementos);
    printf("\n\n");

    for(i = 0; i < elementos; i++)
    {
        printf("Informe o valor da posicao %d: ", i + 1);
        scanf("%lf", &vetor[i]);
        soma = soma + vetor[i]; // Guarda o soma dos elementos do vetor
    }

    printf("\n\n");

    // Impressao dos elementos do vetor
    printf("Valores no vetor: ");
    for(i = 0; i < elementos; i++)
        printf("%.2lf  ", vetor[i]);

    printf("\n\n");

    media = soma/elementos; // Equacao matematica que calcula a media dos elementos do vetor

    printf("Media dos valores: %.2lf\n\n", media);

    printf("Menores que a media: ");
    for(i = 0; i < elementos; i++)
    {
        if(vetor[i] < media) // Se os elementos do vetor forem menores do que a media de todos os elementos do vetor
            printf("%.2lf  ", vetor[i]);
    }

    printf("\n\nMaiores que a media: ");
    for(i = 0; i < elementos; i++)
    {
        if(vetor[i] > media) // Se os elementos do vetor forem maiores do que a media de todos os elementos do vetor
            printf("%.2lf  ", vetor[i]);
    }

    printf("\n\n");

    return 0; // Encerra o programa e retorna 0 ao Sist Op.

}
