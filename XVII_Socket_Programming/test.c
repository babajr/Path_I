#include <stdio.h>
#include <arpa/inet.h>

int main(void)
{
    printf("%d\n", inet_addr("10.10.10.10"));

    return 0;
}