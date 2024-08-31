#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void *routine(void *arg)
{
    int index = *(int *)arg;
    int sum = 0;

    for (int i = 0; i < 5; i++)
    {
        sum += arr[index + i];
    }

    printf("Local sum: %d\n", sum);
    *(int *)arg = sum;

    return arg;
}

int main(int argc, char *argv[])
{
    pthread_t th[2];
    int i;

    for (i = 0; i < 2; i++)
    {
        int *arg = malloc(sizeof(int));

        // thread1 sum from index 0 to 4 --> arg = 0
        // thread2 sum from index 5 to 9 --> arg = 5
        *arg = i * 5;

        if (pthread_create(&th[i], NULL, &routine, arg) != 0)
        {
            perror("Failed to create thread");
            exit(0);
        }
    }

    int globalSum = 0;
    for (i = 0; i < 2; i++)
    {
        int *res;

        if (pthread_join(th[i], (void **)&res) != 0)
        {
            perror("Failed to join thread");
        }

        globalSum += *res;
        free(res);
    }

    printf("Global sum: %d\n", globalSum);

    return 0;
}