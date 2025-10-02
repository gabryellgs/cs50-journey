#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string candidato[3] = {"alice", "bob", "charlie"};
    int votos[3] = {0, 0, 0};

    int eleitores = get_int("Qual é o número de eleitores? ");

    for (int i = 0; i < eleitores; i++)
    {
        string escolha = get_string("Vote no candidato: ");

        bool encontrado = false;

        // Verifica se o voto corresponde a algum candidato
        for (int j = 0; j < 3; j++)
        {
            if (strcmp(escolha, candidato[j]) == 0)
            {
                votos[j]++;
                encontrado = true;
                break;
            }
        }

        if (!encontrado)
        {
            printf("Voto inválido!\n");
        }
    }

    printf("\nResultado da eleição:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%s recebeu %i votos\n", candidato[i], votos[i]);
    }
}
