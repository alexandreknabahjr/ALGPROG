/*
Este programa imprime os numeros entre aqueles digitados
pelo usuario. Alem disso, este programa imprime a soma
desses numeros.
*/

#include <stdio.h> // Biblioteca com operacoes de I/O.

int main()
{
    // Entradas tipo int
    int n1,n2,aux = 0;
    // Variavel do contador
    int cont = 0;
    // Saida tipo int (alem dos numeros entre n1 e n2)
    int soma = 0;

    printf("Digite o primeiro numero: \n");
    scanf("%d", &n1);
    printf("Digite o segundo numero: \n");
    scanf("%d", &n2);
    printf("\n");

    // Se o primeiro numero for maior do que o segundo:
    if(n1>n2)
    {
        aux = n1; // Variavel auxiliar recebe n1.
        n1 = n2; // n1 recebe n2.
        n2 = aux; // n2 recebe n1.
    }

    printf("Numeros:\n");
    for(cont = n1 + 1; cont<n2; cont++)
    {
        if((cont % 5 == 2) || (cont % 5 == 3)) // Se o resto da divisao por 5 for igual a 2 ou 3.
        {
            printf("%d\n", cont); // Impressao dos numeros compreendidos entre (n1,n2)
            soma += cont; // soma recebe soma + cont
        }
    }

    printf("Soma dos Numeros:\n%.1d\n", soma); // Impressao da soma.

    return 0; // Encerra o programa e retorna 0 ao Sist Op.
}
