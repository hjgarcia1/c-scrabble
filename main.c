#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int letter_value[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int calculate_points(char *word)
{
    int i, j, k, points = 0;

    for (i = 0; i < strlen(word); i++)
    {
        for (j = 0; j < strlen(alphabet); j++)
        {
            if (word[i] == alphabet[j])
            {
                points += letter_value[j];
                break;
            }
        }
    }

    return points;
}

void get_winner(int player_one, int player_two)
{
    if (player_one == player_two)
    {
        printf("Tied Game.\n");
    }
    else if (player_one > player_two)
    {
        printf("Player One Wins Game.\n");
    }
    else
    {
        printf("Player Two Wins Game.\n");
    }
}

int main(int argc, char *argv[])
{
    //A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q   R  S  T  U  V  W  X  Y  Z
    //1  3  3  2  1  4  2  4  1  8  5  1  3  1  1  3  10  1  1  1  1  4  4  8  4  10

    int p1 = 0,
        p2 = 0,
        i = 0, j = 0;

    char p1_word[32], p2_word[32];

    printf("Player One's word: ");
    scanf("%s", &p1_word);
    printf("Player Two's word: ");
    scanf("%s", &p2_word);

    while (p1_word[i])
    {
        p1_word[i] = toupper(p1_word[i]);
        i++;
    }

    while (p2_word[j])
    {
        p2_word[j] = toupper(p2_word[j]);
        j++;
    }

    p1 = calculate_points(p1_word);

    p2 = calculate_points(p2_word);

    printf("Player One's word: '%s' is worth %i\n", p1_word, p1);
    printf("Player Two's word: '%s' is worth %i\n", p2_word, p2);

    get_winner(p1, p2);

    return 0;
}
