#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int altura = 0;

    // Pede para o usuário digitar um número entre 1 e 8
    do
    {
        altura = get_int("Altura: digite de 1 a 8 \n");
    }
    // Repete enquanto o valor estiver fora do intervalo permitido
    while (altura < 1 || altura > 8);

    // Constrói a pirâmide linha por linha
    for(int linha = 1; linha <= altura; linha++)
    {
        // Cria os espaços à esquerda de cada linha
        for(int espaco = 0; espaco < altura - linha; espaco++)
        {
            printf(" ");
        }

        // Cria os blocos '#' da pirâmide
        for(int bloco = 0; bloco < linha; bloco++)
        {
            printf("#");
        }

        // Quebra a linha para a próxima linha da pirâmide
        printf("\n");
    }
}
