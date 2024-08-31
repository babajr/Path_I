/*
Create threads with No arguments and don't return any value from them.
Race condition demonstration using global variable count.
Race Condition occurs when two or more tries to access the same
code.
*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int count = 0;

void *routine()
{
    for (int i = 0; i < 1000000; i++)
    {
        count++;
        // read mails
        // increment
        // write mails
    }
}

int main(int argc, char *argv[])
{
    pthread_t threads[2];
    int size = sizeof(threads) / sizeof(threads[0]);
    int i;

    // Create thread
    for (i = 0; i < size; i++)
    {
        /*
        int pthread_create(pthread_t *restrict thread,
                          const pthread_attr_t *restrict attr,
                          void *(*start_routine)(void *),
                          void *restrict arg)
        */
        if (pthread_create(&threads[i], NULL, &routine, NULL) != 0)
        {
            perror("Failed to create thread");
            exit(0);
        }
        printf("Thread %d has started\n", i);
    }

    // Join the thread
    for (i = 0; i < size; i++)
    {
        /*
        int pthread_join(pthread_t thread, void **retval);
        */
        if (pthread_join(threads[i], NULL) != 0)
        {
            exit(0);
        }
        printf("Thread %d has finished execution\n", i);
    }

    printf("Number of mails: %d\n", count);
    return 0;
}

/*
Expected Output:
    Number of mails: 2000000

Actual Output:
    Number of mails: 1097798
                    (Some random value < 2000000)
                    Because of the Race Condition
*/