#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int altura = 0;
    // faz o usuario digitar um numero de 1 a 8
    do
    {
        altura = get_int("Altura: digite um numero de 1 a 8 ");
    }
    // o usuario não pode digitar um numero diferente de 1 a 8
    while(altura <1 || altura > 8);

    //constroi a pirâmide
    for(int linha= 1; linha <= altura; linha++){
        // cria os espaços
        for(int espaco = 0; espaco < altura - linha; espaco++){
            printf(" ");
        }
        // cria os blocos da esquerda
        for(int bloco = 0; bloco < linha; bloco++){
            printf("#");
        }
        // cria um espaço fixo no meio dividindo
        printf("  ");
        // cria os blocos da direita
        for(int bloco = 0; bloco < linha; bloco++ ){
            printf("#");
        }
        //quebra a linha
        printf("\n");
    }
}
