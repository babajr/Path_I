/*
Print below Pattern for input n.
1. n = 3

*
**
***
**
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

void print_pattern(int N)
{
    // Outer loop for number of rows.
    for (int i = 1; i <= (2 * N - 1); i++)
    {
        // stars would be equal to the row no. uptill first half
        int stars = i;

        // for the second half of the rotated triangle.
        if (i > N)
            stars = (2 * N - i);

        // for printing the stars in each row.
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
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

    print_pattern(n);
    return 0;
}