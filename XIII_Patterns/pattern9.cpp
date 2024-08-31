/*
Print below Pattern for input n.
1. n = 3

  *
 ***
*****
*****
 ***
  *

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

void erect_pyramid(int N)
{
    // This is the outer loop which will loop for the rows.
    for (int i = 0; i < N; i++)
    {
        // For printing the spaces before stars in each row
        for (int j = 0; j < N - i - 1; j++)
        {
            cout << " ";
        }

        // For printing the stars in each row
        for (int j = 0; j < 2 * i + 1; j++)
        {

            cout << "*";
        }

        // For printing the spaces after the stars in each row
        for (int j = 0; j < N - i - 1; j++)
        {
            cout << " ";
        }

        // As soon as the stars for each iteration are printed, we move to the
        // next row and give a line break otherwise all stars
        // would get printed in 1 line.
        cout << endl;
    }
}

void inverted_pyramid(int N)
{
    // This is the outer loop which will loop for the rows.
    for (int i = 0; i < N; i++)
    {
        // For printing the spaces before stars in each row
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        // For printing the stars in each row
        for (int j = 0; j < 2 * N - (2 * i + 1); j++)
        {

            cout << "*";
        }

        // For printing the spaces after the stars in each row
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        // As soon as the stars for each iteration are printed, we move to the
        // next row and give a line break otherwise all stars
        // would get printed in 1 line.
        cout << endl;
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    erect_pyramid(n);
    inverted_pyramid(n);

    return 0;
}