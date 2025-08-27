#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int altura = 0;

    do
    {
        altura = get_int("Altura: digite de 1 a  8 \n");
    }
    while (altura < 1 || altura > 8);


    for(int linha = 1; linha <= altura; linha++){
        for(int espaco = 0; espaco < altura - linha; espaco++)
        {
            printf(" ");
        }
        for(int bloco = 0; bloco < linha; bloco++)
        {
            printf("#");
        }
        printf("\n");
    }
}
