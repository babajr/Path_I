/*
PROTOTYPE:
int atoi(const char *str);
It converts a string characters to an integer value.
*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

/*
APPROACH 1:
This implementation handles the negative numbers.
If the first character is ‘-‘ then store the sign as negative and then convert the rest
of the string to number using the previous approach while multiplying sign with it.
*/

// A simple atoi() function
int my_atoi_1(char *str)
{
    // Initialize result
    int res = 0;

    // Initialize sign as positive
    int sign = 1;

    // Initialize index of first digit
    int i = 0;

    // If number is negative,
    // then update sign
    if (str[0] == '-')
    {
        sign = -1;

        // Also update index of first digit
        i++;
    }

    // Iterate through all digits
    // and update the result
    for (; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return -1;
        res = res * 10 + str[i] - '0';
    }
    // Return result with sign
    return sign * res;
}

/*
APPROACH 2: Considering all the corner cases

Four corner cases needs to be handled:
- Discards all leading whitespaces
- Sign of the number
- Overflow
- Invalid input

To remove the leading whitespaces run a loop until a character of the digit is reached.
If the number is greater than or equal to INT_MAX/10.
Then return INT_MAX if the sign is positive and return INT_MIN if the sign is negative.
The other cases are handled in previous approaches.
*/

int my_atoi(const char *str)
{
    int sign = 1, res = 0, i = 0;
    int len = strlen(str);

    // Ignore the whitespaces
    while (i < len && str[i] == ' ')
        i++;

    // Ignore leading zeros.
    while (i < len && str[i] == '0')
        i++;

    // Check for sign of the number
    if (i < len && str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (i < len && str[i] == '+')
    {
        i++;
    }

    // Ignore leading zeros after sign. example "-00753"
    while (i < len && str[i] == '0')
        i++;

    // checking for valid input
    while (i < len)
    {
        // Return -1 if the character is not a valid digit
        if (str[i] < '0' || str[i] > '9')
            return -1;

        // handling overflow test case
        if (res > INT_MAX / 10 ||
            ((res == INT_MAX / 10) &&
             ((str[i] - '0') > 7)))
        {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        res = 10 * res + (str[i++] - '0');
    }

    return res * sign;
}

int my_atoi_bit_man(char *p)
{
    int k = 0;
    int sign = 1;
    while (*p)
    {
        if (*p == ' ' || *p == '0')
        {
            p++;
        }

        if (*p == '-')
        {
            sign = -1;
            p++;
        }

        if (*p > '9' || *p < '0')
        {
            return -1;
        }

        k = (k << 3) + (k << 1) + (*p) - '0';
        p++;
    }

    return (k * sign);
}

int main(void)
{
    // char str[20] = "12a34";
    char str[20] = "-12";

    // printf("%d\n", my_atoi_1(str));
    printf("%d\n", my_atoi(str));
    printf("%d\n", atoi(str));
    printf("%d\n", my_atoi_bit_man(str));

    return 0;
}
