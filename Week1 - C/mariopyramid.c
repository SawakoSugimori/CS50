#include <cs50.h>
#include <stdio.h>

// A program to create pyramids like below.
//    # #
//   ## ##
//  ### ###

int get_height(void);
void get_pyramids(int n);

int main(void)
{
    //Input height
    int height = get_height();

    //Make pyramids
    get_pyramids(height);
}

int get_height(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    return height;
}

//pyramids function
void get_pyramids(int n)
{
    for (int i = 0; i < n; i++)
    {
        //left side
        for (int j = 1; j < n - i; j++)
        {
            printf(" ");
        }
        for (int p = 0; p <= i; p++)
        {
            printf("#");
        }
        //space between walls
        printf("  ");

        //right side
        for (int q = 0; q <= i; q++)
        {
            printf("#");
        }
        printf("\n");
    }
}