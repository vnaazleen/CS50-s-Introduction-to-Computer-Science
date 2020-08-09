#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


bool only_alphabets(string s);
bool are_repetitions(string s);
char to_upper(char c);
char to_lower(char c);

int main(int argc, string argv[])
{
    // check if correct no of arguments are given
    if (argc > 2 || argc == 1)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
    string KEY = argv[1];
    // check if length of key is 26
    // Check whether all characters in string are alphabets
    if (strlen(KEY) != 26 || !only_alphabets(KEY))
    {
        printf("KEY should be of 26 characters long and contain only alphabets\n");
        return 1;
    }

    // Check whether there are any repititons of characters in KEY
    if (are_repetitions(KEY))
    {
        printf("The characters in the string should not be repeated!\n");
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
        if (isupper(c))
        {
            printf("%c", to_upper(KEY[(c - 65) % 26]));
        }
        // Check if the character is Lower case
        else if (islower(c))
        {
            printf("%c", to_lower(KEY[(c - 97) % 26]));
        }
        // If it not a Letter then dont change
        else
        {
            printf("%c", c);
        }

    }
    printf("\n");

    return 0;
}

// Checks whether string consists of only alphabets or not
bool only_alphabets(string s)
{
    char c;
    for (int i = 0, n = strlen(s); i <= n; ++i)
    {
        c = s[i];
        if (isdigit(c))
        {
            return false;
        }
    }
    return true;
}

// Checks if there are any repitions in the string
bool are_repetitions(string s)
{
    int count[26] = {0};
    int j;
    char ch;
    for (int i = 0, n = strlen(s); i < n; ++i)
    {
        ch = s[i];
        // if the character is upper case -- repitition check
        if (ch >= 'A' && ch <= 'Z')
        {
            j = ch - 65;
            if (count[j] == 1)
            {
                return true;
            }
            else
            {
                count[j] = 1;
            }
        }

        // If the character is lower case - repitition check
        if (ch >= 'a' && ch <= 'z')
        {
            j = ch - 97;
            if (count[j] == 1)
            {
                return true;
            }
            else
            {
                count[j] = 1;
            }
        }
    }
    return false;
}

// Converts lower case into uppercase
char to_upper(char c)
{
    if isupper(c)
    {
        return c;
    }
    else
    {
        return c - 32;
    }
}

// converts uppercase into lowercase
char to_lower(char c)
{
    if islower(c)
    {
        return c;
    }
    else
    {
        return c + 32;
    }
}
