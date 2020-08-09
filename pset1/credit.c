#include <stdio.h>
#include <cs50.h>

// FInds the sum of digits in given number
int dig_sum(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

int main()
{
    long card_no = get_long("Number: ");
    long card_number = card_no;
    char scard_no[17];

    // To calculate sum of non - underlined digits
    int sum1 = 0;
    // To calculate sum of underlined digits
    int sum2 = 0;

    int rem = 0;
    int size = 0;
    int arr[16] = {0};

    // Loop which calculate the sum
    while (card_no > 0)
    {
        // Un underlined digits
        rem = card_no % 10;
        sum1 += rem;
        card_no /= 10;
        size += 1;
        // For final digit check
        if (card_no > 0)
        {
            size += 1;
        }
        // Underlined digits
        rem = (card_no % 10) * 2;
        if (rem >= 10)
        {
            rem = dig_sum(rem);
        }
        sum2 += rem;
        card_no /= 10;
    }

    // Calculate the total sum
    int total = sum1 + sum2;

    // If the last digit is zero then the card number is vaild
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Convert the card number into string
    sprintf(scard_no, "%ld", card_number);

    if (size == 15 && scard_no[0] == '3' && (scard_no[1] == '4' || scard_no[1] == '7'))
    {
        printf("AMEX\n");
    }
    else if (size == 16 && scard_no[0] == '5' && (scard_no[1] == '1' || scard_no[1] == '2' || scard_no[1] == '3' || scard_no[1] == '4'
             || scard_no[1] == '5'))
    {
        printf("MASTERCARD\n");
    }
    else if ((size == 13 || size == 16) && scard_no[0] == '4')
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;

}
