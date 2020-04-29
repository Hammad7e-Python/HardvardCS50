#include <stdio.h>
#include <cs50.h>
#include <math.h>


//Luhn’s Algorithm
//So what’s the secret formula? Well, most cards use an algorithm invented by Hans Peter Luhn of IBM. According to Luhn’s algorithm, you can determine if a credit card number is (syntactically) valid as follows:

//1-Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
//2-Add the sum to the sum of the digits that weren’t multiplied by 2.
//3-If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

//That’s kind of confusing, so let’s try an example with David’s Visa: 4003600000000014.

//1-For the sake of discussion, let’s first underline every other digit, starting with the number’s second-to-last digit:

//4003600000000014

//Okay, let’s multiply each of the underlined digits by 2:

//1•2 + 0•2 + 0•2 + 0•2 + 0•2 + 6•2 + 0•2 + 4•2

//That gives us:

//2 + 0 + 0 + 0 + 0 + 12 + 0 + 8

//Now let’s add those products’ digits (i.e., not the products themselves) together:

//2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13

//2-Now let’s add that sum (13) to the sum of the digits that weren’t multiplied by 2 (starting from the end):

//13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 20

//3-Yup, the last digit in that sum (20) is a 0, so David’s card is legit!

//So, validating credit card numbers isn’t hard, but it does get a bit tedious by hand. Let’s write a program.



int main(void)
{

    long long CC_Number;

    //Prompts user for input and validates it as non-negative
    do
    {
        CC_Number = get_long_long("Enter your credit card number? ");
    }
    while (CC_Number <= 0);

    //Declare variables to store CC number's length
    int countDigits = 0;
    long long validation = CC_Number;

    //Counts number of digits
    while (validation > 0)
    {
        validation = validation / 10;
        countDigits++;
    }

    //Prints INVALID if length is shorter than 13 or longer than 16
    if (countDigits != 13 && countDigits != 15 && countDigits != 16)
    {
        printf("INVALID CREDIT CARD\n");
    }

    //Finds out first checksum digits and multiply them by 2
    int Fst_digit  = (((CC_Number % 100) / 10) * 2);
    int Snd_digit  = (((CC_Number % 10000) / 1000) * 2);
    int Trd_digit  = (((CC_Number % 1000000) / 100000) * 2);
    int Fourth_digit  = (((CC_Number % 100000000) / 10000000) * 2);
    int Fifth_digit  = (((CC_Number % 10000000000) / 1000000000) * 2);
    int Sixth_digit  = (((CC_Number % 1000000000000) / 100000000000) * 2);
    int Svnth_digit  = (((CC_Number % 100000000000000) / 10000000000000) * 2);
    int Eighth_digit  = (((CC_Number % 10000000000000000) / 1000000000000000) * 2);

    //digits of first checksum
    int check1  = ((Fst_digit % 10) + ((Fst_digit % 100) / 10));
    check1      = (check1 + ((Snd_digit % 10) + ((Snd_digit % 100) / 10)));
    check1      = (check1 + ((Trd_digit % 10) + ((Trd_digit % 100) / 10)));
    check1      = (check1 + ((Fourth_digit % 10) + ((Fourth_digit % 100) / 10)));
    check1      = (check1 + ((Fifth_digit % 10) + ((Fifth_digit % 100) / 10)));
    check1      = (check1 + ((Sixth_digit % 10) + ((Sixth_digit % 100) / 10)));
    check1      = (check1 + ((Svnth_digit % 10) + ((Svnth_digit % 100) / 10)));
    check1      = (check1 + ((Eighth_digit % 10) + ((Eighth_digit % 100) / 10)));

    //second checksum digits
    int Ninth_digit      = (CC_Number % 10);
    int Tenth_digit     = ((CC_Number % 1000) / 100);
    int Elvnth_digit     = ((CC_Number % 100000) / 10000);
    int Twlvth_digit     = ((CC_Number % 10000000) / 1000000);
    int Thrtenth_digit     = ((CC_Number % 1000000000) / 100000000);
    int Fourteenth_digit     = ((CC_Number % 100000000000) / 10000000000);
    int Fifteenth_digit     = ((CC_Number % 10000000000000) / 1000000000000);
    int Sixteenth_digit     = ((CC_Number % 1000000000000000) / 100000000000000);

    //Adds checksums
    check1      = (check1 + ((Ninth_digit % 10) + ((Ninth_digit % 100) / 10)));
    check1      = (check1 + ((Tenth_digit % 10) + ((Tenth_digit % 100) / 10)));
    check1      = (check1 + ((Elvnth_digit % 10) + ((Elvnth_digit % 100) / 10)));
    check1      = (check1 + ((Twlvth_digit % 10) + ((Twlvth_digit % 100) / 10)));
    check1      = (check1 + ((Thrtenth_digit % 10) + ((Thrtenth_digit % 100) / 10)));
    check1      = (check1 + ((Fourteenth_digit % 10) + ((Fourteenth_digit % 100) / 10)));
    check1      = (check1 + ((Fifteenth_digit % 10) + ((Fifteenth_digit % 100) / 10)));
    check1      = (check1 + ((Sixteenth_digit % 10) + ((Sixteenth_digit % 100) / 10)));

    //If checksum doesn't end in 0
    if (check1 % 10 != 0)
    {
        printf("INVALID\n");
    }

    //Validation for AMEX
    long long amex = (CC_Number / 10000000000000);

    if (countDigits == 15)
    {
        if (amex != 34 && amex != 37)
        {
            printf("INVALID\n");
        }
        else
        {
            printf("AMEX\n");
        }

    }

    //First validation for VISA
    if (countDigits == 13)
    {
        printf("VISA\n");
    }

    //Validation for CC numbers of 16 digits
    if (countDigits == 16)
    {
        //Second validation for VISA
        if ((Eighth_digit / 2) == 4)
        {
            printf("VISA\n");
        }
        else
        {
            //Validation for MASTERCARD
            long long mastercard = (CC_Number / 100000000000000);

            if (mastercard != 51 && mastercard != 52 && mastercard != 53 && mastercard != 54
                && mastercard != 55)
            {
                printf("INVALID\n");
            }
            else
            {
                printf("MASTERCARD\n");
            }
        }
    }
}