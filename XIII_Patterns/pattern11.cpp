/*
Print below Pattern for input n.
1. n = 3

1
01
101

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

// void print_pattern(int n)
// {
//     // Outer loop for number of rows.
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             if ((i + j) % 2 == 0)
//                 printf("1");
//             else
//                 printf("0");
//         }

//         cout << endl;
//     }
// }

void print_pattern(int N)
{
    // First row starts by printing a single 1.
    int start = 1;

    // Outer loop for the no. of rows
    for (int i = 0; i < N; i++)
    {
        // if the row index is even then 1 is printed first
        // in that row.
        if (i % 2 == 0)
            start = 1;

        // if odd, then the first 0 will be printed in that row.
        else
            start = 0;

        // We alternatively print 1's and 0's in each row by using
        // the inner for loop.
        for (int j = 0; j <= i; j++)
        {
            cout << start;
            start = 1 - start;
        }

        // As soon as the numbers for each iteration are printed, we move to the
        // next row and give a line break otherwise all numbers
        // would get printed in 1 line.
        cout << endl;
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    print_pattern(n);
    return 0;
}