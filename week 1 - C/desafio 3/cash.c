#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Declara a variável para armazenar o valor digitado pelo usuário
    float valor = 0;

    // Loop para garantir que o usuário digite um valor não negativo
    do
    {
        valor = get_float("Digite o valor:");  // Solicita ao usuário o valor do troco
    }
    while(valor < 0);  // Repete enquanto o valor for negativo

    // Converte o valor digitado em centavos (int) usando round para evitar problemas com ponto flutuante
    int centavo = round(valor * 100);

    // Inicializa a variável que vai contar o número de moedas usadas
    int moeda = 0;

    // Enquanto houver centavos suficientes para usar uma moeda de 25 centavos
    while(centavo >= 25)
    {
        centavo = centavo - 25;  // Subtrai o valor da moeda do total
        moeda++;                  // Incrementa o contador de moedas
    }

    // Enquanto houver centavos suficientes para usar uma moeda de 10 centavos
    while(centavo >= 10)
    {
        centavo = centavo - 10;   // Subtrai o valor da moeda do total
        moeda++;                  // Incrementa o contador de moedas
    }

    // Enquanto houver centavos suficientes para usar uma moeda de 5 centavos
    while(centavo >= 5)
    {
        centavo = centavo - 5;    // Subtrai o valor da moeda do total
        moeda++;                  // Incrementa o contador de moedas
    }

    // Enquanto houver centavos suficientes para usar uma moeda de 1 centavo
    while(centavo >= 1)
    {
        centavo = centavo - 1;    // Subtrai o valor da moeda do total
        moeda++;                  // Incrementa o contador de moedas
    }

    // Imprime o número mínimo de moedas necessárias
    printf("%d\n", moeda);
}
