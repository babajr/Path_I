/*
An Amrstrong number is a number that is equal to the sum of its own digits
each raised to the power of the number of digits.
*/

#include <iostream>
using namespace std;

bool is_armstrong(int n)
{
    int sum = 0;
    int temp = n;

    // Get the number of digits
    int no_of_digits = to_string(n).length();

    while (temp > 0)
    {
        int last_digit = temp % 10;
        // Add the digit raised to the power of k to the sum
        sum += pow(last_digit, no_of_digits);

        temp = temp / 10;
    }

    return (sum == n) ? true : false;
}

int main()
{
    int n = 1532;
    cout << is_armstrong(n) << endl; // true: armstrong, false: not armstrong
    return 0;
}
