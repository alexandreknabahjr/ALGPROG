/*
Este programa mostra o resultado de um produto a partir de dois valores digitados pelo usuario
*/

#include <stdio.h> // Biblioteca com operacoes de I/O.

int main()
{
    float primeiro_valor,segundo_valor; // Declaracao tipo das variaveis informadas float.
    double mult; // Declaracao tipo da variavel resultante em double.

    printf("Digite o primeiro numero: "); // Mensagem impressa na tela do usuario.
    scanf("%f", &primeiro_valor); // Leitura da informacao digitada pelo usuario.

    printf("Digite o segundo numero: ");
    scanf("%f", &segundo_valor);

    mult = primeiro_valor * segundo_valor; // Armazena resultado em multiplicacao.

    printf("Resultado da multiplicacao: %.3lf\n", mult); // Revela para o usuario o resultado da operacao matematica com precisao de tres casas decimais.

    return(0); // Encerra o programa e retorna 0 ao Sist Op.

}
