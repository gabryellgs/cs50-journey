#include <stdio.h>
#include <cs50.h>

int main()
{
    long numero = get_long("Digite o numero do cartão: ");
    long n = numero;
    int contador = 0;
    int somaTotal = 0;
    int posicao = 0;

    // Aplica o algoritmo de Luhn
    while (n > 0)
    {
        int digito = n % 10;    // pega o ultimo digito
        n = n / 10;             // remove o último dígito
        contador++;             // conta quantos dígitos o cartao tem

        if (posicao % 2 == 1)
        {
            digito *= 2;
            if (digito > 9)
            {
                digito = (digito / 10) + (digito % 10);
            }
        }

        somaTotal += digito;
        posicao++;
    }

    // Só agora verificamos a validade
    if (somaTotal % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Agora pegamos os dois primeiros e o primeiro dígito
    long doisDigitos = numero;
    while (doisDigitos >= 100)
    {
        doisDigitos /= 10;
    }

    long primeiroDigito = numero;
    while (primeiroDigito >= 10)
    {
        primeiroDigito /= 10;
    }

    // Verifica as bandeiras
    if ((doisDigitos == 34 || doisDigitos == 37) && contador == 15)
    {
        printf("AMEX\n");
    }
    else if (doisDigitos >= 51 && doisDigitos <= 55 && contador == 16)
    {
        printf("MASTERCARD\n");
    }
    else if (primeiroDigito == 4 && (contador == 13 || contador == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

