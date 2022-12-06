/*
Este programa checa se o retangulo informado pelo usuario
colide ou nao com os outros retangulos tambem informados
pelo usuario.
*/

#include <stdio.h> // Biblioteca com operacoes de I/O

// Definicao da constante que
#define TAM 20

// Funcao com retorno que checa se houve colisao
int checaColisao(float x, float y, float altura, float comprimento, float x2, float y2, float altura_2, float comprimento_2)
{
    if ((x + comprimento > x2) && (y + altura > y2))
        if (x < x2 + comprimento_2 && y < y + altura_2)
            return 1; // Ha colisao, portanto retorna true

    return 0; // Nao ha colisao, portanto retorna false
}

// Funcao principal
int main()
{
    // Indice do loop
    int i;
    // Variavel tipo int do numero de retangulos a serem comparados com o primeiro
    int numero_retangulos;
    // Variaveis tipo float
    float x,y,altura,comprimento;
    // Vetores tipo float
    float vetor_x[TAM], vetor_y[TAM];
    float vetor_altura[TAM], vetor_comprimento[TAM];
    // Vetor auxiliar tipo int
    int vetor_auxiliar[TAM];

    // Impressao de mensagens e leitura das variaveis
    printf("Informe as coordenadas x1 e y1, nesta ordem, do retangulo 1: ");
    scanf("%f %f", &x, &y);

    printf("\nInforme a altura e o comprimento, nesta ordem, do retangulo 1: ");
    scanf("%f %f", &altura, &comprimento);

    printf("\nInforme o numero de retangulos a serem comparados: ");
    scanf("%d", &numero_retangulos);

    // Loop dos retangulos a serem comparados com o primeiro
    for(i = 0; i < numero_retangulos; i++)
    {
        printf("\n\nInforme as coordenadas x1 e y1, nesta ordem, do retangulo %d: ", i + 2);
        scanf("%f %f", &vetor_x[i], &vetor_y[i]);
        printf("\nInforme a altura e o comprimento, nesta ordem, do retangulo %d: ", i + 2);
        scanf("%f %f", &vetor_altura[i], &vetor_comprimento[i]);
        vetor_auxiliar[i] = checaColisao(x, y, altura, comprimento, vetor_x[i], vetor_y[i], vetor_altura[i], vetor_comprimento[i]);
    }

    // Imprime o resultado das colisoes
    for(i = 0; i < numero_retangulos; i++)
    {
        if(vetor_auxiliar[i] == 0) // Se nao houve colisao
            printf("\nO retangulo %d nao se sobrepoe ao retangulo 1\n", i + 2);
        else
            if(vetor_auxiliar[i] == 1) // Se houve colisao
            {
                printf("\n\nO retangulo %d se soprepoe ao retangulo 1\n", i + 2);
                printf("(x = %.1f , y = %.1f , dy = %.1f , dx = %.1f)", vetor_x[i], vetor_y[i], vetor_altura[i], vetor_comprimento[i]);
            }
    }

    printf("\n"); // Pula uma linha

    return 0; // Encerra o programa e retorna 0 ao Sist Op.
}

