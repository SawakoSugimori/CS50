// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool validation = false;
    int lower = 0, upper = 0, number = 0, symbol = 0;

    //Find lower case letters, upper case letters, numbers, or symbols
    for (int i = 0, n = strlen(password); i < n; i++)
    {
        if (islower(password[i]))
        {
            lower++;
        }
        else if (isupper(password[i]))
        {
            upper++;
        }
        else if (isdigit(password[i]))
        {
            number++;
        }
        else if (isgraph(password[i]))
        {
            symbol++;
        }

        //Check valid or not
        if (lower == 0 || upper == 0 || number == 0 || symbol == 0)
        {
            validation = false;
        }
        else
        {
            validation = true;
        }
    }
    return validation;
}
