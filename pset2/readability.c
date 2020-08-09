#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string input_str = get_string("Text: ");
    float nwords = 0;
    float nletters = 0;
    float nsentences = 0;
    float L, S;
    char c;

    for (int i = 0, n = strlen(input_str); i <= n; ++i)
    {
        c = input_str[i];
        // For sentences
        if (c == '!' || c == '.' || c == '?')
        {
            nsentences += 1;
        }
        // For words
        else if (c == ' ')
        {
            nwords += 1;
        }
        // For Letters (Upper & Lower case)
        else if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        {
            nletters += 1;
        }
    }

    nwords += 1;

    //printf("No of Letters: %.2f\n", nletters);
    //printf("No of sentences: %.2f\n", nsentences);
    //printf("No of words: %.2f\n", nwords);

    L = (nletters / nwords) * 100;
    S = (nsentences / nwords) * 100;

    //printf("L: %f ", L);
    //printf("S: %f\n", S);

    // Coleman-Liau index
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Printing grade as per index
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 1 && index <= 16)
    {
        printf("Grade %d\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }


    return 0;

}
