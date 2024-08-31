/****************************************************************************
File name: own_strtok.cpp

Author: babajr
*****************************************************************************/

/*
Implement our own strtok() function.

SYNTAX:
char *strtok(char * restrict s1, const char * restrict s2);

PARAMETERS:
s1— The s1 string is modified and broken into smaller strings (tokens).
s2— The s2 string contains the delimiter characters. These may vary from one call
to another.

RETURN:
The strtok function returns a pointer to the first character of a token or a null pointer
if there is no token.
*/

#include <bits/stdc++.h>
using namespace std;

char *own_strtok(char *str, char del)
{
    static char *temp_s = NULL;
    int i;

    // Have the copy of original string
    if (str != NULL)
        temp_s = str;

    // Case for last token, we need to return NULL.
    if (temp_s == NULL)
        return NULL;

    // As we have to return starting addr of token, create char array in heap.
    char *res = (char *)malloc(sizeof(char) * (strlen(temp_s) + 1));

    // Traverse the string
    for (i = 0; temp_s[i] != '\0'; i++)
    {
        // If current char != del, add it to res[]
        if (temp_s[i] != del)
        {
            res[i] = temp_s[i];
        }
        else // Store the string formed and return.
        {
            res[i] = '\0';
            temp_s = temp_s + i + 1;
            return res;
        }
    }

    // Case when loop ends
    res[i] = '\0';
    temp_s = NULL;

    return res;
}

int main(void)
{
    // char str[100] = "My name is Don.";
    char str[100] = "10.20.100.10";

    char *token = own_strtok(str, '.');

    while (token != NULL)
    {
        printf("%s\n", token);
        token = own_strtok(NULL, '.');
    }

    return 0;
}