/*
Este programa determina o tipo de triangulo digitado pelo usuario,
caso ele seja um triangulo.
*/

#include <stdio.h> // Biblioteca com operacoes de I/O.

int main()
{
    // Entradas tipo double
    double a,b,c;

    printf("Informe o tamanho do lado A: ");
    scanf("%lf", &a);
    printf("Informe o tamanho do lado B: ");
    scanf("%lf", &b);
    printf("Informe o tamanho do lado C: ");
    scanf("%lf", &c);
    printf("\n");

    if((a>=b+c)) // Se "a" for maior do que a soma de "b" com "c".
    {
        printf("NAO FORMA TRIANGULO\n");
    }
    else
    {
        if((a*a==b*b+c*c) && (b==c)) // Se o Teorema de Pitagoras for valido e se "b" for igual a "c".
        {
            printf("TRIANGULO RETANGULO\n");
            printf("TRIANGULO ISOSCELES\n");
        }
        else
        {
            if((a*a==b*b+c*c) && (b!=c)) // Se o Teorema de Pitagoras for valido e se "b" for diferente de "c".
            {
                printf("TRIANGULO RETANGULO\n");
            }
            else
            {
                if((a*a>b*b+c*c) && (a==b)) // Se a condicao para que um triangulo seja obtusangulo for valida e se "a" for igual a "b".
                {
                    printf("TRIANGULO OBTUSANGULO\n");
                    printf("TRIANGULO ISOSCELES\n");
                }
                else
                {
                    if((a*a>b*b+c*c) && (b==c)) // Se a condicao para que um triangulo seja obtusangulo for valida e se "b" for igual a "c".
                    {
                        printf("TRIANGULO OBTUSANGULO\n");
                        printf("TRIANGULO ISOSCELES\n");
                    }
                    else
                    {
                        if((a*a>b*b+c*c) && (b!=c)) // Se a condicao para que um triangulo seja obtusangulo for valida e se "b" for diferente de "c".
                        {
                            printf("TRIANGULO OBTUSANGULO\n");
                        }
                        else
                        {
                            if((a*a<b*b+c*c) && (a==b) && (b!=c)) // Se a condicao para que um triangulo seja acutangulo for valida e se "a" for igual a "b" e se "b" for diferente de "c".
                            {
                                printf("TRIANGULO ACUTANGULO\n");
                                printf("TRIANGULO ISOSCELES\n");
                            }
                            else
                            {
                                if((a*a<b*b+c*c) && (a!=b) && (b==c)) // Se a condicao para que um triangulo seja acutangulo for valida e se "a" for diferente de "b" e se "b" for igual a "c".
                                {
                                    printf("TRIANGULO ACUTANGULO\n");
                                    printf("TRIANGULO ISOSCELES\n");
                                }
                                else
                                {
                                    if((a*a<b*b+c*c) && (a!=b) && (b!=c)) // // Se a condicao para que um triangulo seja acutangulo for valida e se "a" for diferente de "b" e se "b" for diferente de "c".
                                    {
                                        printf("TRIANGULO ACUTANGULO\n");
                                    }
                                    else
                                    {
                                        if((a==b) && (b==c)) // Se "a" for igual a "b" e se "b" for igual a "c".
                                        {
                                            printf("TRIANGULO ACUTANGULO\n");
                                            printf("TRIANGULO EQUILATERO\n");
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0; // Encerra o programa e retorna 0 ao Sist Op.
}
