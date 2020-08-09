#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool is_numeric(string s)
{
    for (int i = 0; i < strlen(s); ++i)
    {
        if (isdigit(s[i]) == false)
        {
            return false;
        }
    }
    return true;
}

int main(int argc, string argv[])
{

    // check if correct no of arguments are given
    if (argc > 2 || argc == 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    // check if the given string is numeric
    // check if the given number is non-negative
    if (!is_numeric(argv[1]) || key < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Take input string
    string input_str = get_string("plaintext: ");

    char c;
    printf("ciphertext: ");
    for (int i = 0; i < strlen(input_str); ++i)
    {
        c = input_str[i];
        // Check if the character is Upper case
        if (c >= 65 && c <= 90)
        {
            printf("%c", 65 + ((c - 65 + key) % 26));
        }
        // Check if the character is Lower case
        else if (c >= 97 && c <= 122)
        {
            printf("%c", 97 + ((c - 97 + key) % 26));
        }
        // If it not a Letter then dont change
        else
        {
            printf("%c", c);
        }

    }
    printf("\n");
}
