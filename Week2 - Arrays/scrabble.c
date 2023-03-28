#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// This is a program to determine which of two Scrabble words is worth more.
// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    //Convert lower case to upper case
    string s = word;
    int length1 = strlen(word);

    for (int i = 0; i < length1; i++)
    {
        if (islower(word[i]))
        {
            s[i] = toupper(word[i]);
        }
        else
        {
            s[i] = word[i];
        }
    }

    //Compute sum
    int sum = 0;
    int length2 = strlen(s);
    for (int j = 0; j < length2; j++)
    {
        if (s[j] >= 'A' && s[j] <= 'Z')
        {
            sum += POINTS[s[j] - 65];
        }
    }
    return sum;
}
