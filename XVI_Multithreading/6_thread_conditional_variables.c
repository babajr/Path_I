/*
Condition Variables (CVs):
-- When you want to sleep a thread, condition variable can be used.
-- In C under Linux, there is a function pthread_cond_wait() to wait or sleep.
-- On the other hand, there is a function pthread_cond_signal() to wake up sleeping or waiting thread.
-- Threads can wait on a condition variable.

-- CVs allow us to have finer control over taking the decision on when and which
   competing thread to block and or resume.
-- CVs allows threads to get itself blocked / wake up when certain condition is
   met.
-- CVs allows threads to inspect the resource state and decide if it wants to wait
   for favourable resource state.
-- They are not used for Mutual Exclusion, they are used for Coordination (Signalling).

-- Using CV, a thread can block himself
pthread_cond_wait(&condFuel, &mutexFuel);

-- A thread can signal already blocked thread (blocked by CV) to resume.
   Shall unblock at least one of the threads that are blocked on the specified
   condition variable cond (if any threads are blocked on cond)
pthread_cond_signal(&condFuel);

-- Shall unblock all threads currently blocked on the specified
   condition variable cond.
int pthread_cond_broadcast(pthread_cond_t *cond);

*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

pthread_mutex_t mutexFuel;
pthread_cond_t condFuel;
int fuel = 0;

void *fuel_filling(void *arg)
{
    for (int i = 0; i < 5; i++)
    {
        pthread_mutex_lock(&mutexFuel);

        // Critical Section
        fuel += 15;

        printf("Filled fuel... %d\n", fuel);
        pthread_mutex_unlock(&mutexFuel);
        pthread_cond_signal(&condFuel);
        sleep(1);
    }
}

void *car(void *arg)
{
    pthread_mutex_lock(&mutexFuel);

    // Critical Section
    while (fuel < 40)
    {
        printf("No fuel. Waiting...\n");
        pthread_cond_wait(&condFuel, &mutexFuel);
        // Equivalent to:
        // pthread_mutex_unlock(&mutexFuel);
        // wait for signal on condFuel
        // pthread_mutex_lock(&mutexFuel);
    }
    fuel -= 40;

    printf("Got fuel. Now left: %d\n", fuel);
    pthread_mutex_unlock(&mutexFuel);
}

int main(int argc, char *argv[])
{
    pthread_t threads[2];
    int size = sizeof(threads) / sizeof(threads[0]);

    // Init Mutex and Conditional Variable
    pthread_mutex_init(&mutexFuel, NULL);
    pthread_cond_init(&condFuel, NULL);

    for (int i = 0; i < size; i++)
    {
        if (i == 1)
        {
            if (pthread_create(&threads[i], NULL, &fuel_filling, NULL) != 0)
            {
                perror("Failed to create thread");
                exit(0);
            }
        }
        else
        {
            if (pthread_create(&threads[i], NULL, &car, NULL) != 0)
            {
                perror("Failed to create thread");
                exit(0);
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            perror("Failed to join thread");
            exit(0);
        }
    }

    pthread_mutex_destroy(&mutexFuel);
    pthread_cond_destroy(&condFuel);

    return 0;
}