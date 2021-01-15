#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int calculate_points(char *word)
{
    int i, j, k, player_points = 0;

    for (i = 0; i < strlen(word); i++)
    {
        for (j = 0; j < strlen(alphabet); j++)
        {
            if (word[i] == alphabet[j])
            {
                player_points += points[j];
                break;
            }
        }
    }

    return player_points;
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

    int player_one = 0,
        player_two = 0, 
        i = 0, j = 0;


    char player_one_word[] = "qi", player_two_word[] = "code", up_case_word_one[10], up_case_word_two[10];

    // Loop
    while (player_one_word[i])
    {
        up_case_word_one[i] = toupper(player_one_word[i]);
        i++;
    }

    j = 0;
    while (player_two_word[j])
    {
        up_case_word_two[j] = toupper(player_two_word[j]);
        j++;
    }

    player_one = calculate_points(up_case_word_one);

    player_two = calculate_points(up_case_word_two);

    printf("Player One's word: '%s'is worth %i\n", player_one_word, player_one);
    printf("Player Two's word: '%s'is worth %i\n", player_two_word, player_two);

    get_winner(player_one, player_two);

    return 0;
}
