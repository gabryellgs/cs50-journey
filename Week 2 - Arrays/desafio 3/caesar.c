#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // 1. Verifica se foi passado apenas 1 argumento
    if (argc != 2)
    {
        printf("Use: ./caesar key\n");
        return 1;
    }

    // 2. Verifica se o argumento é composto apenas de dígitos
    int n = strlen(argv[1]);
    for (int i = 0; i < n; i++)
    {
        if (!isdigit((unsigned char) argv[1][i]))
        {
            printf("Use: ./caesar key\n");
            return 1;
        }
    }

    // 3. Converte argumento para número e aplica módulo 26
    long k_long = strtol(argv[1], NULL, 10);
    int k = (int)(k_long % 26);

    // 4. Pede texto simples ao usuário
    string plaintext = get_string("plaintext: ");

    // 5. Imprime o texto cifrado
    printf("ciphertext: ");
    int length = strlen(plaintext);
    for (int i = 0; i < length; i++)
    {
        char c = plaintext[i];
        if (isupper((unsigned char)c))
        {
            char cipher_char = (char)(((c - 'A' + k) % 26) + 'A');
            putchar(cipher_char);
        }
        else if (islower((unsigned char)c))
        {
            char cipher_char = (char)(((c - 'a' + k) % 26) + 'a');
            putchar(cipher_char);
        }
        else
        {
            putchar(c); // mantém os caracteres que não são letras
        }
    }
    printf("\n");

    return 0;
}
