/*
Este programa le a o codigo de um produto, assim como a quantidade desejada desse mesmo produto.
A partir dos dados lidos, o programa calcula o total a ser pago pelo cliente.
*/

#include <stdio.h> // Biblioteca com operacoes de I/O.

// Definicao das constantes impressas na tabela
#define PAO 1
#define LEITE 2
#define BISCOITO 3

int main()
{

    // Entradas tipo int
    int produto,quantidade;
    // Saida tipo float
    float a_pagar=0;

    printf("Codigo do Produto\tDescricao do Produto\t\tValor Unitario\n"); // Inicio da impressao da tabela
    printf("\t%d\t\tPao Fatiado\t\t\tR$ 1.50\n", PAO);
    printf("\t%d\t\tLeite (1 litro)\t\t\tR$ 4.65\n", LEITE);
    printf("\t%d\t\tBiscoito (pacote 300 gramas)\tR$ 6.93\n", BISCOITO);

    printf("\nDigite o codigo do produto desejado: "); // Impressao das orientacoes ao usuario.
    scanf("%d", &produto); // Leitura da informacao.
    printf("Digite a quantidade desejada do produto: ");
    scanf("%d", &quantidade);

    if(produto==1) // Caso o codigo seja igual a 1.
        a_pagar = quantidade * 1.50; // Quantidade de produtos multiplicada pelo preco do produto escolhido.

    if(produto==2) // Caso o codigo seja igual a 2.
        a_pagar = quantidade * 4.65;

    if(produto==3) // Caso o codigo seja igual a 3.
        a_pagar = quantidade * 6.93;

    printf("Total a pagar: %.2f\n", a_pagar); // Impressao do total a ser pago pelo cliente.

    return 0; // Encerra o programa e retorna 0 ao Sist Op.

}
