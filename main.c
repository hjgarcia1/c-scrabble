#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, char *argv[])
{
    //A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q   R  S  T  U  V  W  X  Y  Z
    //1  3  3  2  1  4  2  4  1  8  5  1  3  1  1  3  10  1  1  1  1  4  4  8  4  10

    int player_one_points = 0,
        player_two_points = 0,
        i, j;

    char *player_one_word, *player_two_word;

    //set the words
    player_one_word = "CODE";

    //get points for player one
    for (i = 0; i < strlen(player_one_word); i++)
    {
        for (j = 0; j < strlen(alphabet); j++)
        {
            if (player_one_word[i] == alphabet[j])
            {
                player_one_points += points[j];
                break;
            }
        }
    }

    //get points for player two
    player_two_word = "BEE";

    for (i = 0; i < strlen(player_two_word); i++)
    {
        for (j = 0; j < strlen(alphabet); j++)
        {
            if (player_two_word[i] == alphabet[j])
            {
                player_two_points += points[j];
                break;
            }
        }
    }

    printf("Player one's word: '%s'is worth %i\n", player_one_word, player_one_points);
    printf("Player two's word: '%s'is worth %i\n", player_two_word, player_two_points);

    if (player_one_points == player_two_points)
    {
        printf("Tied Game.\n");
    }
    else if (player_one_points > player_two_points)
    {
        printf("Player One Wins Game.\n");
    }
    else
    {
        printf("Player Two Wins Game.\n");
    }

    return 0;
}
