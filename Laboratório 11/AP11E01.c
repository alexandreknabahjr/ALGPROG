/*
Este programa plota um cenario, que inclui as bordas do mapa
e um carro cujas coordenadas sao informadas pelo usuario.
Alem disso, esse carro se move pelo eixo y ate que encontre os limites do mapa.
*/

#include <stdio.h> // Biblioteca com operacoes de I/O
#include <conio2.h> // Biblioteca com funcoes de manipulacao grafica
#include <stdlib.h> // Biblioteca com funcoes de alocacao de memoria, controle de processos e conversoes

// Importar a função de "dormir" apropriada dependente do sistema operational
#ifdef _WIN32
#include <Windows.h>  // No Windows, função Sleep da biblioteca Windows.h
#else
#include <unistd.h>  // No Linux/macOS, função usleep da biblioteca unistd.h
#endif

// Definicao das constantes utilizadas no programa
#define INTERVALO 500  // milissegundos
#define LINHAS_CENARIO 20
#define COLUNAS_CENARIO 20

typedef struct {
    int x;
    int y;
} T_COORDENADA;

typedef struct {
    int largura;
    int comprimento;
    T_COORDENADA coordenada;
} T_CARRO;

void imprime_cenario(int linhas_cenario, int colunas_cenario, T_CARRO carro) {
    // Indices dos loops
    int i, j;

    // Declaracao de uma matriz tipo char ja inicializada
    char moldura[LINHAS_CENARIO][COLUNAS_CENARIO] = {{' ','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-',' '},
                                                    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                                                    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                                                    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                                                    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                                                    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                                                    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                                                    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                                                    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                                                    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                                                    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                                                    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                                                    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                                                    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                                                    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                                                    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                                                    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                                                    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                                                    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                                                    {' ','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-',' '}};


    // Impressao da moldura
    for(i = 0; i < LINHAS_CENARIO; i++)
    {
        for(j = 0; j < COLUNAS_CENARIO; j++)
            printf("%c ", moldura[i][j]);
        printf("\n");
    }

    // Impressao do carro com o caracter @
    for(i = 0; i < carro.largura; i++)
    {
        for(j = 0; j < carro.comprimento; j++)
        {
            // Posicionamento da matriz na tela
            gotoxy(carro.coordenada.x + i, carro.coordenada.y + j);
            printf("@");
        }
        printf("\n");
    }

}

int testa_carro(int linhas_cenario, int colunas_cenario, T_CARRO carro) {
    if(carro.coordenada.x + carro.largura >= colunas_cenario || carro.coordenada.y + carro.comprimento >= linhas_cenario)
        return 0; // Caso falso
    else
        return 1; // Caso verdadeiro
}

int main() {
    // Declaracao tipo T_CARRO
    T_CARRO carro;

    // Ler as informações do carro.
    printf("Digite a coordenada x (coluna) do carro: ");
    scanf("%d", &carro.coordenada.x);
    printf("Digite a coordenada y (linha) do carro: ");
    scanf("%d", &carro.coordenada.y);
    printf("Digite a largura (numero de colunas) do carro: ");
    scanf("%d", &carro.largura);
    printf("Digite o comprimento (numero de linhas) do carro: ");
    scanf("%d", &carro.comprimento);

    // Se o carro já inicia fora do cenário, apenas exibir mensagem de erro.
    if(testa_carro(LINHAS_CENARIO, COLUNAS_CENARIO, carro) == 0) {
        printf("Carro colide com a borda ou esta fora do cenario!\n");
    } else {  // Senão
        // Enquanto o carro estiver totalmente dentro do cenário
        while(testa_carro(LINHAS_CENARIO, COLUNAS_CENARIO, carro)) {
            // Limpar a tela ...
            #ifdef _WIN32
            system("cls");  // no Windows
            #else
            system("clear");  // no Linux/macOS
            #endif

            imprime_cenario(LINHAS_CENARIO, COLUNAS_CENARIO, carro); // Chamada da funcao auxiliar imprime_cenario

            // Dormir por alguns instantes para "animar" o carro.
            #ifdef _WIN32
            Sleep(INTERVALO);
            #else
            usleep(INTERVALO*1000);  // usleep recebe parâmetro em microsegundos
            #endif

            if(testa_carro(LINHAS_CENARIO, COLUNAS_CENARIO, carro)) // Se a condicao permanece verdadeira, isto e, se o carro permanece no mapa
                carro.coordenada.y++; // Incremento da coordenada y
        }
    }

    return 0; // Encerra o programa e retorna 0 ao Sist Op.
}
