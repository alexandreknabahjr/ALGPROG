/*
Este programa possibilita a realizacao de 3 operacoes bancarias.
Entre elas, temos: deposito, saque e transferencia.

*/

#include <stdio.h> // Biblioteca com operacoes de I/O.

int main()
{
    // Entradas tipo int
    int codigo,conta;
    // Entradas tipo double
    double saldo, valor;

    printf("\n\t\t\tSistema Bancario 1.0\n\n"); // Inicio da impressao da tabela
    printf("\t\t\t%-15d%-15s%\n", 1, "Deposito");
    printf("\t\t\t%-15d%-15s%\n", 2, "Saque");
    printf("\t\t\t%-15d%-15s%\n\n", 3, "Transferencia");

    printf("\nDigite o saldo da sua conta: R$ ");
    scanf("%lf", &saldo);
    printf("Digite a operacao desejada: ");
    scanf("%d", &codigo);
    printf("Digite o valor da operacao: R$ ");
    scanf("%lf", &valor);
    printf("\n");

    switch(codigo)
    {
    case 1:
        saldo += valor; // Incremento do valor a ser operado ao saldo.
        break;
    case 2:
        if(saldo<valor) // Se o saldo for menor do que o valor a ser operado.
        {
            printf("Saldo insuficiente!\n");
        }
        else
        {
            saldo -= valor; // Decremento do valor a ser operado ao saldo.
        }
        break;
    case 3:
        if(saldo<valor) // Se o saldo for menor do que o valor a ser operado.
        {
            printf("Saldo insuficiente!\n");
        }
        else
        {
            printf("Digite o numero da conta para a qual voce deseja transferir: ");
            scanf("%d", &conta);
            saldo -= valor;
        }
        break;
    default:
        printf("Operacao invalida! Tente novamente!"); // Caso o codigo lido seja diferente de 1, 2 ou 3.
        break;
    }

    printf("\nSaldo final: R$ %.2lf\n", saldo); // Impressao do saldo final da conta do cliente

    return 0; // Encerra o programa e retorna 0 ao Sist Op.
}
