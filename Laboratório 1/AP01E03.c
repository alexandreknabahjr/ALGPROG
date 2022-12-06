/*
Este programa calcula o peso final de uma carga de produtos,
a qual e composta por celulares e webcams. Celulares pesam 290 gramas
e webcams pesam 125 gramas.
*/

int main()
{
    int celulares,webcams; // Declaracao tipo das variaveis informadas int. Elas se referem ao numero de celulares e ao numero de webcams.
    float equacao; // Declaracao tipo da variavel resultante.
    float embalagemCelular,embalagemWebcam; // Declaracao tipo das variaveis informadas float. Elas se referem aos pesos das embalagens que devem ser informadas pelo usuario.
    const float pesoCelular = 290.0; // Declaracao tipo constante. Um celular pesa 290g, logo optei por relacionar a palavra PesoCelular com o seu valor numerico.
    const float pesoWebcam = 125.0; // Declaracao tipo constante. Uma webcam pesa 125g, logo optei por relacionar a palavra PesoWebcam com o seu valor numerico.

    printf("Digite o numero de celulares: "); // Mensagem impressa na tela do usuario.
    scanf("%d", &celulares); // Leitura da informacao digitada pelo usuario.

    printf("Digite o peso da embalagem de cada celular: ");
    scanf("%f", &embalagemCelular);

    printf("Digite o numero de webcams: ");
    scanf("%d", &webcams);

    printf("Digite o peso da embalage de uma webcam: ");
    scanf("%f", &embalagemWebcam);

    equacao = celulares * pesoCelular + webcams * pesoWebcam + embalagemCelular * celulares + embalagemWebcam * webcams; // Armazena resultado em uma equacao que envolve a soma das mulitplicacoes.

    printf("O peso total da carga e: %.2f gramas\n", equacao); // Revela para o usuario o resultado da operacao matematica com precisao de duas casas decimais.

    return(0); // Encerra o programa e retorna 0 ao Sist Op.
}
