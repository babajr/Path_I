/*
Print below Pattern for input n.
1. n = 3

1    1
12  21
123321

*/

#include <iostream>
using namespace std;

/*
Aproach for Pattern related problems:
There are 4 general rules for solving a pattern-based question:

1. We always use nested loops for printing the patterns.
   For the outer loop, we count the number of lines/rows and loop for them.
2. Next, for the inner loop, we focus on the number of columns and somehow connect them to the rows
   by forming a logic such that for each row we get the required number of columns to be printed.
3. We print the ‘*’ inside the inner loop.
4. Observe symmetry in the pattern or check if a pattern is a combination of two or more similar patterns.

*/

void print_pattern(int N)
{
    // initial no. of spaces in row 1.
    int spaces = 2 * (N - 1);

    // Outer loop for the number of rows.
    for (int i = 1; i <= N; i++)
    {

        // for printing numbers in each row
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }

        // for printing spaces in each row
        for (int j = 1; j <= spaces; j++)
        {
            cout << " ";
        }

        // for printing numbers in each row
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }

        // As soon as the numbers for each iteration are printed, we move to the
        // next row and give a line break otherwise all numbers
        // would get printed in 1 line.
        cout << endl;

        // After each iteration nos. increase by 2, thus
        // spaces will decrement by 2.
        spaces -= 2;
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    print_pattern(n);
    return 0;
}