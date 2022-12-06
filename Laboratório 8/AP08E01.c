/*
Este programa move um caracter a partir das setas do teclado.
Se o usuario pressionar a tecla ESC, o programa sera finalizado.
*/

#include <stdio.h> // Biblioteca com operacoes de I/O
#include <stdlib.h> // Biblioteca com funcoes de manipulacao de alocacao de memoria, controle de processos e conversoes
#include <conio2.h> // Biblioteca com funcoes de manipulacao de caracteres
#include <math.h> // Biblioteca com funcoes matematicas


// Definicao das constantes referentes as teclas
#define ESPECIAL -32
#define SETA_ESQ 75
#define SETA_DIR 77
#define SETA_CIMA 72
#define SETA_BAIXO 80
#define ESPACO 32
#define ENTER 13
#define ESC 27
#define X_MAX 80
#define Y_MAX 25

int main()
{
    // Variavel tipo char setada para '0'
    char tecla = '0';
    // Posicoes iniciais de x e y:
    int x = rand() % X_MAX, y = rand() % Y_MAX;

    do
    {
        fflush(stdin); // Limpa o buffer
        if(kbhit())
        {
            tecla = getch(); // Le a tecla do usuario
            textcolor(LIGHTRED); // Muda a cor do texto
            clrscr(); // Limpa a tela
            gotoxy(x, y); // Posiciona o cprintf na tela
            cprintf(" C "); // Caracter a ser movimentado
            gotoxy(X_MAX - 35, Y_MAX); // Posicionamento da mensagem referente a tecla ESC
            cprintf("Pressione ESC para sair do programa!"); // Mensagem de aviso impressa na tela
            // Caso a tecla pressionada seja a do tipo ESPECIAL:
            if(tecla == ESPECIAL)
            {
                tecla = getch();
                switch(tecla)
                {
                case SETA_CIMA:
                    y--; // Decremento de y: o caracter desce
                    if(y < 1)
                        y = Y_MAX;
                    break;
                case SETA_BAIXO:
                    y++; // Incremento de y: o caracter sobe
                    if(y > Y_MAX)
                        y = 1;
                    break;
                case SETA_ESQ:
                    x--; // Decremento de x: o caracter vai para a esquerda
                    if(x < 1)
                        x = X_MAX;
                    break;
                case SETA_DIR:
                    x++; // Incremento de x: o caracter vai para a direita
                    if(x > X_MAX)
                        x = 1;
                    break;
                case ESC:
                    tecla = ESC;
                    break;
                }
            }
        }
    }
    while(tecla != ESC); // Enquanto a tecla ESC nao for pressionada

    return 0; // Encerra o programa e retorna 0 ao Sist Op.
}
