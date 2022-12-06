/*
Este programa armazena uma serie de informacoes
fornecidas pelo usuario em 2 matrizes e em 1 vetor.
O usuario deve preencher uma matriz com os nomes de
4 pacotes de viagens, deve informar o codigo
de cada funcionario da agencia de turismo, assim como
deve informar a quantidade de vendas de cada pacote.
Ao final do programa, uma tabela com essas informacoes
e impressa.
*/

#include <stdio.h> // Biblioteca com operacoes de I/O

// Definicao das constantes
#define NRFUNCIONARIOS 3
#define NRVENDAS 4
#define TAMANHO 20

int main()
{
    // Matriz 3 x 4 que guarda as vendas dos funcionarios
    int vendas[NRFUNCIONARIOS][NRVENDAS];
    // Nomes dos pacotes (ate 20 caracteres)
    char pacote[NRVENDAS][TAMANHO];
    // Codigo dos funcionarios
    int numero[NRFUNCIONARIOS];
    // Indices do loop
    int f, v;

    // Preenchimento da matriz referente aos pacotes de viagens
    for(v = 0; v < NRVENDAS; v++)
    {
        printf("Digite o nome do pacote %d: ", v + 1);
        gets(pacote[v]);
        printf("\n");
    }

    for(f = 0; f < NRFUNCIONARIOS; f++)
    {
        // Preenchimento do vetor referente aos codigos dos funcionarios
        printf("\nCodigo do vendedor %d: ", f + 1);
        scanf("%d", &numero[f]);
        // Preenchimento da matriz referente as vendas dos funcionarios
        for(v = 0; v < NRVENDAS; v++)
        {
            printf("\n\tVenda do pacote %d: ", v + 1);
            scanf("%d", &vendas[f][v]);
        }
        printf("\n");
    }

    // Impressao da tabela de vendas
    printf("\n\n\t%-20s%-20s%-20s\n\n", "PACOTE", "ID VENDEDOR", "QUANTIDADE");
    for(f = 0; f < NRFUNCIONARIOS; f++)
    {
        for(v = 0; v < NRVENDAS; v++)
        {
            printf("\t%-20s%-20d%-20d\n", pacote[v], numero[f], vendas[f][v]);
        }
        printf("\n");
    }

    return 0; // Encerra o programa e retorna 0 ao Sist Op.
}
