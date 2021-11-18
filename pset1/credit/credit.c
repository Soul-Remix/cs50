#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt for credit card number
    long number = get_long("Number: ");

    // credit card num count
    long temp_n = number;
    int count = 2;
    while (temp_n > 100)
    {
        temp_n = temp_n / 10;
        count++;
    }

    long temp_n2 = number;
    int sum = 0;

    for (int i = 1; i <= count; i++)
    {
        // get the last digit
        int digit = temp_n2 % 10;
        if (i % 2 == 0)
        {
            if (digit * 2 > 9)
            {
                sum += (digit * 2) - 9;
            }
            else
            {
                sum += digit * 2;
            }
        }
        else
        {
            sum += digit;
        }
        temp_n2 /= 10;
    }

    // return if the number is valid
    if (count == 15 && (temp_n == 34 || temp_n == 37) && sum % 10 == 0)
    {
        printf("AMEX\n");
        return 0;
    }
    else if (count == 16 && (temp_n > 50 && temp_n < 56) && sum % 10 == 0)
    {
        printf("MASTERCARD\n");
        return 0;
    }
    else if ((count == 13 || count == 16) && (temp_n / 10 == 4) && sum % 10 == 0)
    {
        printf("VISA\n");
        return 0;
    }
    else
    {
        printf("INVALID\n");
        return 1;
    }
}