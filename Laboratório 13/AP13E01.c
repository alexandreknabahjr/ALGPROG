/*
Este programa compara duas matrizes que estao
em dois arquivos de tipo txt. Se houver colisao,
o programa imprimira as linhas e colunas onde houve
as colisoes.
*/

#include <stdio.h> // Biblioteca com operacoes de I/O
#include <stdlib.h> // Biblioteca com funcoes de alocacao de memoria, controle de processos e conversoes
#include <conio2.h> // Biblioteca com funcoes de manipulacao grafica

// Definicao das constantes
#define TAM 6
#define TXT 13

typedef struct
{
    int x, y;
} COORDENADAS;

// Protoipo da funcao menu()
void menu();

int main()
{
    menu(); // Chamada da funcao menu()
    return 0; // Encerra o programa e retorna 0 ao Sist Op.
}

void menu()
{
    // Declaracao dos ponteiros dos arquivos
    FILE *arquivo_1, *arquivo_2;
    // Variaveis tipo char que recebem os nomes dos arquivos a serem lidos
    char nome_arquivo1[TXT], nome_arquivo2[TXT];
    // Variaveis tipo char das matrizes
    char matriz_1[TAM][TAM], matriz_2[TAM][TAM], matriz_3[TAM][TAM];
    // Variavel tipo char que recebe a coordenada x
    char coord_x_arquivo[TAM + 2];
    // Variavel tipo COORDENADAS, que e um dado estruturado
    COORDENADAS coordenadas[2 * TAM];
    // Variavel tipo int que conta as colisoes
    int colisoes = 0;
    // Declaracao dos indices dos loops
    int i, j = 0, k = 0;

    printf("Digite o nome do primeiro arquivo: ");
    scanf("%s", nome_arquivo1);

    printf("Digite o nome do segundo arquivo: ");
    scanf("%s", nome_arquivo2);

    // Pula uma linha
    printf("\n");

    // Abertura e leitura dos arquivos
    arquivo_1 = fopen(nome_arquivo1, "r");
    arquivo_2 = fopen(nome_arquivo2, "r");

    // Se houver algum erro na abertura dos arquivos
    if (arquivo_1 == NULL || arquivo_2 == NULL)
    {
        printf("Erro na abertura dos arquivos. Tente novamente!\n");
    }
    else
    {

        // Abertura do primeiro arquivo. Aqui, fazemos a copia para matriz_1[TAM][TAM]
        while(!feof(arquivo_1))
        {
            if(fgets(coord_x_arquivo, TAM + 2, arquivo_1))
            {
                for(i = 0; i< TAM; i++)
                {
                    matriz_1[j][i] = coord_x_arquivo[i];
                }
                j++;
            }
        }

        // Abertura do segundo arquivo. Aqui, fazemos a copia para matriz_2[TAM][TAM]
        while(!feof(arquivo_2))
        {
            if(fgets(coord_x_arquivo, TAM + 2, arquivo_2))
            {
                for(i = 0; i< TAM; i++)
                {
                    matriz_2[k][i] = coord_x_arquivo[i];
                }
                k++;
            }
        }

        // Fechamento dos arquivos
        fclose(arquivo_1);
        fclose(arquivo_2);

        // Loop que percorre as matrizes
        for (i = 0; i < TAM; i++)
        {
            for (j = 0; j < TAM; j++)
            {
                // Teste de colisao
                if (matriz_1[i][j] == matriz_2[i][j])
                {
                    // Se as matrizes tiverem '@' sobrepostos
                    if (matriz_1[i][j] == '@')
                    {
                        // Preenche com 'X'
                        matriz_3[i][j] = 'X';
                        colisoes++;
                        // Salva as coordenadas
                        coordenadas[colisoes].x = i;
                        coordenadas[colisoes].y = j;
                    }
                    else
                    {
                        // Se as matrizes tiverem '-' sobrepostos
                        matriz_3[i][j] = '-';
                    }
                    // Caso contrario
                }
                else
                {
                    matriz_3[i][j] = '@';
                }
            }
        }

        printf(" ");
        // Loop que escreve as colunas
        for(i = 0; i < TAM; i++)
        {
            printf("%d", i );
        }
        printf("\n");

        // A matriz_3 e mostrada
        for(i = 0; i < TAM; i++)
        {
            printf("%d", i );
            for(j = 0; j< TAM; j++)
            {
                printf("%c", matriz_3[i][j]);
            }
            printf("\n");
        }

        printf("\nColisoes\n");

        // Loop que percorre o vetor que contem as posicoes das colisoes
        for (i = 1; i <= colisoes; i++)
        {
            printf("Linha %d, Coluna %d\n", coordenadas[i].x, coordenadas[i].y);
        }
    }

}
