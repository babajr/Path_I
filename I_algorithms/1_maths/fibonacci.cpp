/*
Given N, return nth fibonacci number.
Fibonacci Series: 0 1 1 2 3 5 8 13...

Input: n = 5
Output: 5 (0 based index)

*/

#include <iostream>
using namespace std;

/*
Iterative and Space Optimized
*/
int fib_iterative(int n)
{
    int curr;            // curr = last + second_last
    int last = 1;        // (i-1)th term
    int second_last = 0; //  (i-2)th term

    if (n == 0)
        return 0;

    for (int i = 2; i <= n; i++)
    {
        curr = last + second_last;
        second_last = last;
        last = curr;
    }

    return curr;
}

/*
Recursive.
*/
int fib_recursive(int n)
{
    if (n <= 1)
        return n;

    return (fib_recursive(n - 1) + fib_recursive(n - 2));
}

/*
Todo: Fibonacci Series using DP
*/

int main()
{
    int n = 5;

    cout << fib_iterative(n) << endl;
    cout << fib_recursive(n) << endl;

    return 0;
}