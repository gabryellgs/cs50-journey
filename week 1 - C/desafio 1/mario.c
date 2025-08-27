#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int altura = 0;
    // faz o usuario digitar um numero de 1 a 8
    do
    {
        altura = get_int("Altura: digite de 1 a  8 \n");
    }
    // da uma condiçao de não digitar um numero diferente
    while (altura < 1 || altura > 8);

    // constrói a pirâmide
    for(int linha = 1; linha <= altura; linha++){
        // cria os espaços
        for(int espaco = 0; espaco < altura - linha; espaco++)
        {
            printf(" ");
        }
        // cria os blocos
        for(int bloco = 0; bloco < linha; bloco++)
        {
            printf("#");
        }
        // quebra a linha
        printf("\n");
    }
}
