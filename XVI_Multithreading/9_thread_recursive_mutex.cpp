/*
A recursive type mutex permits a (same) thread to lock many times.
That is, a thread attempting to relock this mutex without
first unlocking will succeed.

This type of mutex must be unlocked the same number of times
it is locked before the mutex will be returned to an unlocked
state. If locked, an error is returned.
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define THREAD_NUM 8

pthread_mutex_t mutexFuel;
int fuel = 50;

void *routine(void *args)
{
    pthread_mutex_lock(&mutexFuel);
    pthread_mutex_lock(&mutexFuel);
    pthread_mutex_lock(&mutexFuel);
    pthread_mutex_lock(&mutexFuel);
    pthread_mutex_lock(&mutexFuel);
    fuel += 50;
    printf("Incremented fuel to %d\n", fuel);
    pthread_mutex_unlock(&mutexFuel);
    pthread_mutex_unlock(&mutexFuel);
    pthread_mutex_unlock(&mutexFuel);
    pthread_mutex_unlock(&mutexFuel);
    pthread_mutex_unlock(&mutexFuel);
}

int main(int argc, char *argv[])
{
    int i;
    pthread_t th[THREAD_NUM];

    // Set, Init Mutex Recursive Attribute
    pthread_mutexattr_t recursiveMutexAttributes;
    pthread_mutexattr_init(&recursiveMutexAttributes);
    pthread_mutexattr_settype(&recursiveMutexAttributes, PTHREAD_MUTEX_RECURSIVE);

    pthread_mutex_init(&mutexFuel, &recursiveMutexAttributes);

    for (i = 0; i < THREAD_NUM; i++)
    {
        if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
        {
            perror("Failed to create thread");
        }
    }

    for (i = 0; i < THREAD_NUM; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            perror("Failed to join thread");
        }
    }

    printf("Fuel: %d\n", fuel);

    pthread_mutexattr_destroy(&recursiveMutexAttributes);
    pthread_mutex_destroy(&mutexFuel);

    return 0;
}