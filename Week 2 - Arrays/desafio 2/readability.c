#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // Pede o texto ao usuário
    string text = get_string("Text: ");

    // Inicializa contadores
    int letters = 0;
    int words = 0;
    int sentences = 0;
    bool in_word = false;

    // Percorre cada caractere do texto
    for (int i = 0; text[i] != '\0'; i++)
    {
        char c = text[i];

        // Conta letras (A-Z ou a-z)
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            letters++;
        }

        // Conta palavras
        if (c != ' ')
        {
            if (!in_word)
            {
                words++;
                in_word = true;
            }
        }
        else
        {
            in_word = false;
        }

        // Conta frases
        if (c == '.' || c == '!' || c == '?')
        {
            sentences++;
        }
    }

    // Calcula L e S (por 100 palavras)
    double L = ((double) letters / words) * 100;
    double S = ((double) sentences / words) * 100;

    // Calcula o índice Coleman-Liau
    double index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = (int) round(index);

    // Imprime o resultado
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
