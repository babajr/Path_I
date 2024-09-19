/*
Dynamic Programming:
-- Is storing answers to various sub-problems to be used later whenever
   required to solve the main problem.
-- two common dynamic programming approaches are:
   -- Tabulation (bottom-up):
      - In this approach, usually the problem is solved in the direction of solving the
        base cases to the main problem.
   -- Memoization (top-down):
      - In this approach, usually the problem is solved in the direction of the main
        problem to the base cases.


Problem Statement:
Given N, return nth fibonacci number.
Fibonacci Series: 0 1 1 2 3 5 8 13...

Input: n = 5
Output: 5 (0 based index)

Idea:
f(num) = f(num-1) + f(num-2)
*/

#include <iostream>
#include <vector>
using namespace std;

/*
1. Basic Recursive Solution
TC = O(2 ^ n) --> Exponential
*/
int fib_recursive(int n)
{
    if (n <= 1)
        return n;

    return (fib_recursive(n - 1) + fib_recursive(n - 2));
}

/*
2. Memoizaton: TC = O(n), SC = O(n) + O(n) = O(n)
Any recursive solution to a problem can be memoized using these three steps:

- Create a dp[n+1] array initialized to -1.
- Whenever we want to find the answer of a particular value (say n),
  we first check whether the answer is already calculated using the dp array(i.e dp[n]!= -1 ).
  If yes, simply return the value from the dp array.
- If not, then we are finding the answer for the given value for the first time,
  we will use the recursive relation as usual but before returning from the function,
  we will set dp[n] to the solution we get.
*/
int fib_dp_memoization(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;

    // check if answer is already calculated.
    // If yes, return the value from dp array
    if (dp[n] != -1)
        return dp[n];

    // If not, calculate using recursive calls.
    return dp[n] = (fib_dp_memoization(n - 1, dp) +
                    fib_dp_memoization(n - 2, dp));
}

/*
3. Tabulation: TC = O(n), SC = O(n)
Steps to convert Recursive Solution to Tabulation one.

-- Declare a dp[] array of size n+1.
-- First initialize the base condition values, i.e i=0 and i=1 of the dp array
   as 0 and 1 respectively.
-- Set an iterative loop that traverses the array( from index 2 to n) and for every
   index set its value as dp[i-1] + dp[i-2].
*/
int fib_dp_tabulation(int n, vector<int> &dp)
{
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

/*
3.1. Tabulation with Space Optimization: TC = O(n), SC = O(1)
-- By observation,
    dp[i] =  dp[i-1] + dp[i-2]
Logic:
-- Assume, prev = dp[i-1] and prev2 = dp[i-2]
-- At each iteration
   cur_i = prev + prev2
   prev2 = prev
   prev = curr_i
-- After the iterative loop has ended we can simply return prev as our answer.
*/
int fib_dp_tabulation_space_opt(int n)
{
    int prev = 1;
    int prev_2 = 0;

    for (int i = 2; i <= n; i++)
    {
        int curr_i = prev + prev_2;
        prev_2 = prev;
        prev = curr_i;
    }

    return prev;
}

int main()
{
    int n = 5;
    vector<int> dp(n + 1, -1);

    cout << fib_recursive(n) << endl;
    cout << fib_dp_memoization(n, dp) << endl;
    cout << fib_dp_tabulation(n, dp) << endl;
    cout << fib_dp_tabulation_space_opt(n) << endl;

    return 0;
}