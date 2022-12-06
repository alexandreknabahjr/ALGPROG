/*
Este programa informa quantos caracteres do tipo
minusculo, maiusculo, digito e especial existem
em um texto informado pelo usuario.
*/

#include <stdio.h> // Biblioteca com operacoes de I/O
#include <string.h> // Biblioteca com funcoes de manipulacao de string

// Definicao do tamanho maximo do vetor
#define TAMANHO 1000

// Funcao auxiliar sem retorno
void contadorAuxiliar(char *texto)
{
    // Indice do loop for
	int i;
	// Definicao dos contadores do tipo int
	int espacos = 0;
	int minusculas = 0;
	int maiusculas = 0;
	int digitos = 0;
	int caracteres_especiais = 0;

	for(i=0; texto[i]; i++)
    {
        if((texto[i] >= 65 && texto[i] <= 90)) // Caso o caracter seja minusculo
          maiusculas++;
        else
            if(texto[i] >= 97 && texto[i] <= 122) // Caso o caracter seja maiusculo
                minusculas++;
            else
                if(texto[i] >= 48 && texto[i] <= 57) // Caso o caracter seja um digito
                    digitos++;
                else
                    if(texto[i] == 32) // Caso o caracter seja um espaco
                        espacos++;
                    else // Caso o caracter seja um do tipo especial
                        caracteres_especiais++;
 	}

 	// Impressao dos resultados
 	printf("\n\nEspacos: %d\n", espacos);
    printf("Letras Minusculas: %d\n", minusculas);
    printf("Letras Maiusculas: %d\n", maiusculas);
    printf("Digitos Numericos: %d\n", digitos);
    printf("Caracteres Especiais: %d\n", caracteres_especiais);

}

// Funcao principal
int main()
{
    // Vetor do tipo char
    char texto[TAMANHO];

    printf("Digite um texto:\n\n");
    gets(texto); // Leitura do texto

    contadorAuxiliar(texto); // Chamada da funcao auxiliar

    return 0; // Encerra o programa e retorna 0 ao Sist Op.
}
