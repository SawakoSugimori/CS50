#include <cs50.h>
#include <stdio.h>

// A program to determine how long it takes for a population to reach a particular size.
int main(void)
{
    // TODO: Prompt for start size
    int total;
    do
    {
        total = get_int("Starting population: ");
    }
    while (total < 9);

    // TODO: Prompt for end size
    int end;
    do
    {
        end = get_int("Ending population: ");
    }
    while (end < total);

    // TODO: Calculate number of years until we reach threshold

    int born;
    int die;
    int n = 0;

    if (end == total)
    {
        printf("Years: %i\n", n);
    }
    else
    {
        do
        {
            born = total / 3;
            die = total / 4;
            total = total + born - die;
            n++;
        }
        while (total < end);
        // TODO: Print number of years
        printf("Years: %i\n", n);
    }
}
