#include <stdio.h>
#include <string.h>

/*
input:
str = "Hello world"

Output:
str = "olleH dlrow"
*/

void reverse(char *start, char *end)
{
    char temp; 
    while(start < end)
    {
        temp = *start;
        *start++ = *end;
        *end-- = temp;        
    }
}


/*
APPROACH 1: Do not work for the case where strings starts with spaces.
*/
void reverse_words(char str[])
{
    char *temp = str;
    char *word_begin = str;

    while(*temp)
    {
        temp++;

        if(*temp == '\0')
        {
            reverse(word_begin, temp-1);
        }
        else if(*temp == ' ')
        {
            reverse(word_begin, temp-1);
            word_begin = temp + 1;
        }        
    }

    // reverse(str, temp-1); // World Hello
}

/*
APPROACH 2: Works in all the cases
*/
void reverse_words_2(char *str)
{
    char *temp = str;
    char *word_begin = NULL;

    while(*temp)
    {
        if((word_begin == NULL) && (*temp != ' '))
        {
            word_begin = temp;
        }

        if(word_begin && (*(temp + 1) == ' ') || (*(temp + 1) == '\0'))
        {
            reverse(word_begin, temp);
            word_begin = NULL;
        }

        temp++;
    }

    //reverse(str, (temp-1)); // OUTPUT: World Hello
}

int main(void)
{
    char str[] = "Hello World";
    
    printf("ORIGINAL String: %s\n", str);

    reverse_words(str);
    printf("REVERSED String: %s\n", str);

    return 0;
}