#include <stdio.h>
#include <string.h>

char *own_strcpy(char *dst, char *src)
{
    int i = 0;

    while (src[i] != '\0')
    {
        dst[i] = src[i];
        i++;
    }

    dst[i] = '\0';
    return dst;
}

int main(void)
{
    char src[] = "Hello World";
    char dst[] = "";

    printf("Original String:%s\n", src);

    printf("Copied String: %s\n", own_strcpy(dst, src));

    return 0;
}