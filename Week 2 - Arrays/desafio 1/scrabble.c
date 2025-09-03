#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Tabela de pontos
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Declaração da função
int compute_score(string word);

int main(void)
{
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    int score1 = compute_score(player1);
    int score2 = compute_score(player2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Função para calcular pontuação
int compute_score(string word)
{
    int score = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        if (isalpha(word[i])) // Só conta letras
        {
            int letter_index = toupper(word[i]) - 'A'; // Converte para índice 0-25
            score += POINTS[letter_index];
        }
    }

    return score;
}
