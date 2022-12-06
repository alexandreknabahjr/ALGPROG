/*
Este programa simula uma serie de entrevistas.
O programa pergunta a idade do entrevistado,
o salario que recebe e o seu sexo. Ao final,
o programa revela a quantidade de entrevistados
de cada sexo, a media de idade entre os entrevistados
e o maior salario entre os entrevistados.
*/

#include <stdio.h> // Biblioteca com operacoes de I/O.

int main()
{
    // Entradas tipo int
    int entrevistadas,idade;
    // Variavel do contador
    int contador;
    // Entrada tipo char
    char sexo;
    // Entrada tipo float
    float salario = 0;
    // Saidas tipo int
    int nhomens = 0, nmulheres = 0;
    int idhomens = 0, idmulheres = 0;
    // Saida tipo double
    double media = 0;
    // Saida tipo float
    float salariomax = 0;

    printf("Digite o numero de pessoas entrevistadas: ");
    scanf("%d", &entrevistadas);
    printf("\n");

    for(contador = 1; contador <= entrevistadas; contador++)
    {
        printf("Informe a sua idade: ");
        scanf("%d", &idade);
        printf("Informe o seu salario: ");
        scanf("%f", &salario);
        printf("Informe o seu sexo: ");
        scanf(" %c", &sexo);
        printf("\n");

        switch(sexo) // Casos possiveis
        {
        case 'm':
        case 'M':
            nhomens += 1;
            idhomens = idhomens + idade;
            break;
        case 'f':
        case 'F':
            nmulheres += 1;
            idmulheres = idmulheres + idade;
            break;
        }

        if(salario>salariomax) // Se o salario for maior do que o salario maximo.
            salariomax = salario;
    }

    if((nhomens>0) && (nmulheres>0)) // Se o numero de homens e de mulheres for maior do que zero.
    {
        media = (double)(idhomens+idmulheres)/(nhomens+nmulheres);
    }
    else
    {
        if((nhomens>0) && (nmulheres == 0)) // Se o numero de homens for maior do que zero e o numero de mulheres for igual a zero.
        {
            media = (double)(idhomens)/(nhomens);
        }
        else
        {
            if((nhomens == 0) && (nmulheres>0)) // Se o numero de homens for igual a zero e o numero de mulheres for maior do que zero.
            {
                media = (double)(idmulheres)/(nmulheres);
            }
            else
            {
                if((nhomens == 0) && (nmulheres == 0)) // Se o numero de homens e mulheres for igual a zero.
                {
                    printf("Nao ha entrevistados homens ou mulheres!\n");
                }
            }
        }
    }

    // Inicio da impressao do resultado das entrevistas
    printf("\nMedia de idades: %.1lf\n", media);
    printf("Salario maximo: R$ %.2lf\n", salariomax);
    printf("Numero de mulheres: %d\n", nmulheres);
    printf("Numero de homens: %d\n", nhomens);

    return 0; // Encerra o programa e retorna 0 ao Sist Op.
}
