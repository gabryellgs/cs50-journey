#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int altura = 0;

    // Pede para o usuário digitar um número entre 1 e 8
    do
    {
        altura = get_int("Altura: digite um numero de 1 a 8 ");
    }
    // Continua pedindo enquanto o valor for menor que 1 ou maior que 8
    while(altura < 1 || altura > 8);

    // Constrói a pirâmide linha por linha
    for(int linha = 1; linha <= altura; linha++)
    {
        // Cria os espaços à esquerda
        for(int espaco = 0; espaco < altura - linha; espaco++)
        {
            printf(" ");
        }

        // Cria os blocos da esquerda (#)
        for(int bloco = 0; bloco < linha; bloco++)
        {
            printf("#");
        }

        // Cria o espaço fixo no meio da pirâmide
        printf("  ");

        // Cria os blocos da direita (#)
        for(int bloco = 0; bloco < linha; bloco++)
        {
            printf("#");
        }

        // Quebra a linha para a próxima linha da pirâmide
        printf("\n");
    }
}
