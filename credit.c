#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    //Get card number
    int digits = 0;
    long card_number;

    do
    {
        card_number = get_long("Card Number: ");
    }
    while (card_number < 0);

    long check = card_number;

    int digit1, digit2, digit3, digit4, digit5, digit6, digit7, digit8, digit9, digit10,
        digit11, digit12, digit13, digit14, digit15, digit16;

    digit1  = (card_number % 10000000000000000 / 1000000000000000) * 2; //16
    digit2  = card_number % 1000000000000000 / 100000000000000; //15
    digit3  = (card_number % 100000000000000 / 10000000000000) * 2; //14
    digit4  = card_number % 10000000000000 / 1000000000000; //13
    digit5  = (card_number % 1000000000000 / 100000000000) * 2; //12
    digit6  = card_number % 100000000000 / 10000000000; //11
    digit7  = (card_number % 10000000000 / 1000000000) * 2; //10
    digit8  = card_number % 1000000000 / 100000000; //9
    digit9  = (card_number % 100000000 / 10000000) * 2; //8
    digit10 = card_number % 10000000 / 1000000;
    digit11 = (card_number % 1000000 / 100000) * 2;
    digit12 = card_number % 100000 / 10000;
    digit13 = (card_number % 10000 / 1000) * 2;
    digit14 = card_number % 1000 / 100;
    digit15 = (card_number % 100 / 10) * 2;
    digit16 = card_number % 10;

    digit15 = (digit15 % 100 / 10) + (digit15 % 10);
    digit13 = (digit13 % 100 / 10) + (digit13 % 10);
    digit11 = (digit11 % 100 / 10) + (digit11 % 10);
    digit9  = (digit9  % 100 / 10) + (digit9  % 10);
    digit7  = (digit7  % 100 / 10) + (digit7  % 10);
    digit5  = (digit5  % 100 / 10) + (digit5  % 10);
    digit3  = (digit3  % 100 / 10) + (digit3  % 10);
    digit1  = (digit1  % 100 / 10) + (digit1  % 10);

    int check_sum = digit1 + digit2 + digit3 + digit4 + digit5 + digit6 + digit7 + digit8 +
                    digit9 + digit10 + digit11 + digit12 + digit13 + digit14 + digit15 + digit16;


    check_sum %= 10;

    if (check_sum != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    while (check > 0)
    {
        check /= 10;
        digits++;
    }

    int amex = card_number / 10000000000000;
    int mastercard = card_number / 100000000000000;
    int visa;

    if (digits == 16)
    {
        visa = card_number / 1000000000000000;
    }
    else if (digits == 13)
    {
        visa = card_number / 1000000000000;
    }

    if (amex == 34 || amex == 37)
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }

    if (digits == 16)
    {
        if (mastercard == 51 || mastercard == 52 || mastercard == 53 || mastercard == 54 || mastercard == 55)
        {
            printf("MASTERCARD\n");
        }
        else if (visa == 4)
        {
            printf("VISA\n");
        }
        else
        {
            return 0;
        }
    }

    if (digits == 13)
    {
        if (visa == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}
