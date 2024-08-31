#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

/*
pthread_mutex_lock():
A call to mutex_lock() locks the mutex object referenced by mutex.
If the mutex is already locked, the calling thread blocks until
the mutex is freed;
This will return with the mutex object referenced by mutex in the
locked state with the calling thread as its owner.
If the current owner of a mutex tries to relock the mutex,
it will result in deadlock.

pthread_mutex_trylock(): On success, it returns 0.
The mutex_trylock() function is the same as mutex_lock (),
respectively, except that if the mutex object referenced by mutex
is locked (by any thread, including the current thread),
the call returns immediately with an error.
*/

pthread_mutex_t mutex;

// Routine having mutex_lock() mechanism for critical section.
void *routine_lock(void *arg)
{
    pthread_mutex_lock(&mutex);
    printf("Got lock\n");
    sleep(1);
    pthread_mutex_unlock(&mutex);
}

// Routine having mutex_trylock() mechanism for critical section.
void *routine_trylock(void *arg)
{
    if (pthread_mutex_trylock(&mutex) == 0)
    {
        printf("Got lock\n");
        sleep(1);
        pthread_mutex_unlock(&mutex);
    }
    else
    {
        printf("Didn't get lock\n");
    }
}

int main(int argc, char *argv[])
{
    pthread_t threads[4];
    int size = sizeof(threads) / sizeof(threads[0]);
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < size; i++)
    {
        // if (pthread_create(&threads[i], NULL, &routine_lock, NULL) != 0)
        if (pthread_create(&threads[i], NULL, &routine_trylock, NULL) != 0)
        {
            perror("Error at creating thread");
            exit(0);
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            perror("Error at joining thread");
            exit(0);
        }
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}

/*
Output with mutex_lock():
Got lock
Got lock
Got lock
Got lock

Output with mutex_trylock():
Got lock
Didn't get lock
Didn't get lock
Didn't get lock
*/
