/*
Semaphore:
int sem_init(sem_t *sem, int pshared, unsigned int value);
-- It initializes the unnamed semaphore at the address pointed to by sem.
-- The value argument specifies the initial value for the semaphore.
-- If pshared has the value 0, then the semaphore is shared between
   the threads of a process, and should be located at some address
   that is visible to all threads
-- If pshared is nonzero, then the semaphore is shared between
   processes, and should be located in a region of shared memory.
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>

#define THREAD_NUM 4

sem_t semaphore;

void *routine(void *args)
{
    sem_wait(&semaphore);
    sleep(1);
    printf("Hello from thread %d\n", *(int *)args);
    sem_post(&semaphore);

    free(args);
}

int main(int argc, char *argv[])
{
    pthread_t th[THREAD_NUM];

    sem_init(&semaphore, 0, 3); // 1, 2, 3, 4
    int i;

    for (i = 0; i < THREAD_NUM; i++)
    {
        int *arg = (int *)malloc(sizeof(int));
        *arg = i;
        if (pthread_create(&th[i], NULL, &routine, arg) != 0)
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

    sem_destroy(&semaphore);

    return 0;
}