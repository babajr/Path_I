#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void *routine(void *arg)
{
    int index = *(int *)arg;
    printf("%d\n", arr[index]);
    free(arg);
}

int main(int argc, char *argv[])
{
    pthread_t threads[10];
    int size = sizeof(threads) / sizeof(threads[0]);
    int i;

    for (i = 0; i < size; i++)
    {
        int *arg = malloc(sizeof(int));
        *arg = i;
        // arg is passed to the thread
        if (pthread_create(&threads[i], NULL, &routine, arg) != 0)
        {
            perror("Failed to created thread");
            exit(0);
        }
    }

    for (i = 0; i < size; i++)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            perror("Failed to join thread");
            exit(0);
        }
    }

    return 0;
}