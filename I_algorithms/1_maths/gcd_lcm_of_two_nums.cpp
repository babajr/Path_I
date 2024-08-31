/****************************************************************************
File name: gcd_lcm_of_two_nums.cpp

Author: babajr
*****************************************************************************/

/*
Program to get the GCD and LCM of two numbers

GCD / HCF : Greatest Common Divisor / Highest Common Factor == highest factor dividing a and b.
LCM : Least Common Multiple == minimum number divisible by a and b.
Ex:
a = 18, b = 9 ==>
factors(a) = 2 * 3 * 3
factors(b) = 3 * 3

GCD = 9
LCM = 18

*/

#include <iostream>
#include <algorithm>

using namespace std;

/*
Brute Force.
*/
int gcd_bf(int n1, int n2)
{
    // Initialize gcd to 1
    int gcd = 1;

    // Iterate from 1 up to
    // the minimum of n1 and n2
    for (int i = 1; i <= min(n1, n2); i++)
    {
        // Check if i is a common factor of both n1 and n2
        if (n1 % i == 0 && n2 % i == 0)
        {
            // Update gcd to the current common factor i
            gcd = i;
        }
    }

    // Return the greatest common divisor (gcd)
    return gcd;
}

/*
Better Approach.
*/
int gcd_better(int n1, int n2)
{
    // Iterate from the minimum of n1 and n2 down to 1
    // Start from the minimum of n1 and n2 because the GCD cannot
    // exceed the smaller number

    for (int i = min(n1, n2); i > 0; i--)
    {
        // Check if i is a common factor of both n1 and n2
        if (n1 % i == 0 && n2 % i == 0)
        {
            // If i is a common factor, return it as the GCD
            return i;
        }
    }
    // If no common factors are found, return 1 (as 1 is always a
    // divisor of any number)
    return 1;
}

/*
Optimal:
The Euclidean Algorithm is a method for finding the greatest common divisor
of two numbers.
It operates on the principle that the GCD of two numbers remains the same
even if the smaller number is subtracted from the larger number.
*/
int gcd_recursion(int a, int b)
{
    if (a == 0)
        return b;

    return gcd_recursion(b % a, a);
}

int gcd_iterative(int a, int b)
{
    // Continue loop as long as both a and b are greater than 0
    while (a > 0 && b > 0)
    {
        // If a is greater than b, subtract b from a and update a
        if (a > b)
        {
            // Update a to the remainder of a divided by b
            a = a % b;
        }
        // If b is greater than or equal to a, subtract a from b
        // and update b
        else
        {
            // Update b to the remainder of b divided by a
            b = b % a;
        }
    }

    // Check if a becomes 0, if so, return b as the GCD
    if (a == 0)
    {
        return b;
    }
    // If a is not 0, return a as the GCD
    return a;
}

/*
API to get the LCM of two numbers.
*/
int lcm(int a, int b)
{
    return ((a * b) / gcd_recursion(a, b));
}

int main(void)
{
    int a = 25, b = 25;

    printf("GCD BF: %d\n", gcd_bf(a, b));
    printf("GCD Better: %d\n", gcd_better(a, b));
    printf("GCD Optimal Recursive: %d\n", gcd_recursion(a, b));
    printf("GCD Optimal Iterative: %d\n", gcd_iterative(a, b));
    printf("lcm: %d\n", lcm(a, b));

    return 0;
}
