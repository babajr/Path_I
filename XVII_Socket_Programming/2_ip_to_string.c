#include <arpa/inet.h>
#include <stdio.h>

int main(void)
{
    struct sockaddr_in sa;
    char str[32];

    // store this IP address in sa:
    inet_pton(AF_INET, "192.0.2.33", &(sa.sin_addr));
    /*
    int inet_pton(int af, const char *restrict src,
                  void *restrict dst);
    af: AF_INET or AF_INET6
    -- convert IPv4 and IPv6 addresses from text to binary form
    -- converts the character string src into a network
       address structure in the af address family,
       then copies the network address structure to dst.
    -- returns 1 on success
    */

    // now get it back and print it
    inet_ntop(AF_INET, &(sa.sin_addr), str, 32);
    /*
    const char *inet_ntop(int af, const void *restrict src,
                          char dst[restrict .size], socklen_t size);
    -- convert IPv4 and IPv6 addresses from binary to text form.
    -- converts the network address structure src in the
       af address family into a character string.  The resulting string
       is copied to the buffer pointed to by dst, which must be a non-
       null pointer.
    -- On success, inet_ntop() returns a non-null pointer to dst.
    -- NULL is returned if there was an error
    */

    printf("%s\n", str); // prints "192.0.2.33"

    return 0;
}