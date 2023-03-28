#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// This is a program that calculate the approximate grade level need to comprehend some text.

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int compute_index(int letters, int words, int sentences);

int main(void)
{
    //An user input scentences
    string text = get_string("Text: ");

    //Count the numbers of letters and words
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    //Print the index
    int index = compute_index(letters, words, sentences);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

//The function of counting the number of letters
int count_letters(string text)
{
    int n = strlen(text); //count the length of text letters
    int letters = 0;

    for (int i = 0; i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

//The function of counting the number of words
int count_words(string text)
{
    int n = strlen(text); //count the length of text letters
    int words = 1;

    for (int i = 0; i < n; i ++)
    {
        int flag = 0;
        if (isspace(text[i]) && flag == 0)
        {
            words++;
            flag++;
        }
        else if (isspace(text[i]) && flag != 0)
        {
            flag++;
        }
        else
        {
            flag = 0;
        }
    }
    return words;
}

//The function of counting sentences
int count_sentences(string text)
{
    int n = strlen(text); //count the length of text letters
    int sentences = 0;

    //Count a sequence of characters that ends with ., !, or ?
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        if ((text[i] == '.' || text[i] == '!' || text[i] == '?') && flag == 0)
        {
            sentences++;
            flag++;
        }
        else if ((text[i] == '.' || text[i] == '!' || text[i] == '?') && flag != 0)
        {
            flag++;
        }
        else
        {
            flag = 0;
        }
    }
    return sentences;
}

//Compute Coleman-Liau index(index = 0.0588 * L - 0.296 * S - 15.8)
int compute_index(int letters, int words, int sentences)
{
    float L, S;
    float index;

    //Calculate the index
    L = (float) letters / (float) words * 100;
    S = (float) sentences / (float) words * 100;
    index = (0.0588 * L) - (0.296 * S) - 15.8;

    //Round the resulting index number
    int roundedIndex = round(index);

    return roundedIndex;
}