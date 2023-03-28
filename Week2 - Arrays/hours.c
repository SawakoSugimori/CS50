// This is a program that calculates a total number of hours or average number of hoursacross a given number of days.
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// the calc_hours function
float calc_hours(int hours[], int weeks, char output)
{
    float sum = 0.0;
    float result = 0.0;

    //sum hours that user input
    for (int j = 0; j < weeks; j++)
    {
        sum += hours[j];
    }

    //if T, output the sum. if A, output the average.
    if (output == 'T')
    {
        result = sum;
    }
    else if (output == 'A')
    {
        result = sum / weeks;
    }

    return result;
}