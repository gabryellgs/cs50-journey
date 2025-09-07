#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // 1. Verifica se tem exatamente 1 argumento
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    // 2. Verifica se a chave tem 26 caracteres
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // 3. Array para marcar letras já vistas
    int seen[26] = {0};

    // 4. Valida se todos são letras e não há repetidas
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha((unsigned char) key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }

        int idx = tolower((unsigned char) key[i]) - 'a';
        if (seen[idx])
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
        seen[idx] = 1;
    }

    // 5. Cria mapas de substituição (A-Z, a-z)
    char map_upper[26];
    char map_lower[26];
    for (int i = 0; i < 26; i++)
    {
        map_upper[i] = toupper((unsigned char) key[i]); // versão maiúscula
        map_lower[i] = tolower((unsigned char) key[i]); // versão minúscula
    }

    // 6. Pede plaintext ao usuário
    string plaintext = get_string("plaintext: ");

    // 7. Gera ciphertext
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];

        if (isupper((unsigned char) c))
        {
            // Se for maiúscula → usa mapa maiúsculo
            putchar(map_upper[c - 'A']);
        }
        else if (islower((unsigned char) c))
        {
            // Se for minúscula → usa mapa minúsculo
            putchar(map_lower[c - 'a']);
        }
        else
        {
            // Se não for letra → imprime igual
            putchar(c);
        }
    }
    printf("\n");

    return 0;
}
