/* Debug version */
// #define NDEBUG
#include <cassert>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
    int i = 0;
    assert(++i == 0); // Assert 0 here
    printf(" i is %d \n", i);
    return 0;
}

/* When run - Asserts */
void _assert(int test, char const *test_image, char const *file, int line)
{
    if (!test)
    {
        printf("assertion failed: %s , file %s , line %d\n",
               test_image, file, line);
        abort();
    }
}

/*
#define NDEBUG is Enabled: On assert, program is not aborted
----> Used for RELEASE Build
Output:
i is 0

#define NDEBUG is Commented: On assert, program is aborted with error details.
----> Used for DEBUG build
Assertion failed: (++i == 0), function main, file assert_in_c.cpp,
line 11.
[1]    5143 abort      ./a.out
*/