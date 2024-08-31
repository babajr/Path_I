#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

void *routine()
{
    int value = (rand() % 6) + 1;
    int *res = malloc(sizeof(int));
    *res = value;
    // printf("%d\n", value);
    printf("Thread result: %p\n", res);

    return (void *)res;
}

int main(int argc, char *argv[])
{
    int *res;
    srand(time(NULL));
    pthread_t th;

    /*
    int pthread_create(pthread_t *restrict thread,
                        const pthread_attr_t *restrict attr,
                        void *(*start_routine)(void *),
                        void *restrict arg)
    */
    if (pthread_create(&th, NULL, &routine, NULL) != 0)
    {
        printf("Failed to create thread\n");
        exit(0);
    }

    /*
    int pthread_join(pthread_t thread, void **retval);
    retval --> will have returned value.
    */
    if (pthread_join(th, (void **)&res) != 0)
    {
        printf("Failed to join thread\n");
        exit(0);
    }

    printf("Main res: %p\n", res);
    printf("Result: %d\n", *res);
    free(res);

    return 0;
}

/*
Output:

Thread result: 0x13bf04080
Main res: 0x13bf04080
Result: 6 (random number)
*/