#include <stdio.h>
#include <string.h>

/*
input:
str = "Hello world"

Output:
str = "dlrow olleH"
*/

void reverse_str(char str[])
{
    int start = 0;
    int end = strlen(str) - 1;

    while(start < end)
    {
        char temp = str[start];
        str[start++] = str[end];
        str[end--] = temp;
    }
}

int main(void)
{
    char str[] = "Hello World";
    
    printf("ORIGINAL String: %s\n", str);

    reverse_str(str);
    printf("REVERSED String: %s\n", str);

    return 0;
}