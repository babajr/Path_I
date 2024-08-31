/*
Print below Pattern for input n.
1. n = 4
*
* *
* * *
* * * *

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

void print_pattern(int n)
{
    for (int i = 0; i < n; i++) // Outer loop to iterate over the rows
    {
        for (int j = 0; j <= i; j++) // Inner loop to iterate for columns or values in each row.
        {
            printf("* ");
        }

        printf("\n");
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    print_pattern(n);

    return 0;
}