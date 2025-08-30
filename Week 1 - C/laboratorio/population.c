#include <stdio.h>
#include <cs50.h>

int main()
{
    // Declara variável para a população inicial
    int populacaoInicial;

    // Solicita repetidamente a população inicial até que seja pelo menos 9
    do
    {
        populacaoInicial = get_int("Start size: "); // pede input do usuário
    } while(populacaoInicial < 9); // repete se for menor que 9

    // Declara variável para a população final
    int populacaoFinal;

    // Solicita repetidamente a população final até que seja maior ou igual à inicial
    do
    {
        populacaoFinal = get_int("End size: "); // pede input do usuário
    } while(populacaoFinal < populacaoInicial); // repete se for menor que a inicial

    // Inicializa contador de anos
    int ano = 0;

    // Inicializa a população atual com a população inicial
    int populacaoAtual = populacaoInicial;

    // Enquanto a população atual for menor que a final, simula o crescimento ano a ano
    while(populacaoAtual < populacaoFinal)
    {
        // Atualiza a população atual:
        // - 1/3 nascem
        // - 1/4 morrem
        populacaoAtual = populacaoAtual + (populacaoAtual / 3) - (populacaoAtual / 4);

        // Incrementa o número de anos que se passaram
        ano++;
    }

    // Imprime o número total de anos necessários para atingir a população final
    printf("Years: %i\n", ano);
}
