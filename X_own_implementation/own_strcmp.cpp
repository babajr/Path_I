#include <stdio.h>
#include <string.h>

int own_strcmp(char *str1, char *str2)
{
    while (*str1 == *str2)
    {
        if (*str1 == '\0')
            return 0;

        str1++;
        str2++;
    }

    return (*str1 - *str2);
}

int main(void)
{
    char str1[] = "ABC";
    char str2[] = "ABCA";

    printf("%d\n", own_strcmp(str1, str2));
    printf("%d\n", strcmp(str1, str2));

    return 0;
}