/*
Create threads with No arguments and don't return any value from them.
Race condition demonstration using global variable count.
Use Mutex to lock and unlock the critical section and resolve
race condition.

Mutex:
-- They are thread synchronization construct which provide mutual exclisivity while
   accessing the Critacal Section by multiple concurrent threads.
-- Its goal is to grant access to Critical Section to only one thread at a time.

-- Mutex Locking Rules:
   - If thread T1 locks a Mutex M, only T1 can unlock it
   - T1 can not unlock an already unlocked mutex --> Undefined Behavior
   - If T1 attempts to double lock the Mutex M, it will self deadlocked.
   - Mutexes must be unlocked in LIFO order.

-- Mutex Locking:
   - Code Locking (Static):
     - If you need to protect a code snippet against concurrent thread unsafe access,
       go for Code Locking.
     - In Code Locking, mutex are defined at source file level.

   - Object Locking (Data Locking) (Run-time):
     - If you need to protect the Object against concurrent thread unsafe assess,
       go for object locking.
     - Data structure locking. Every data structure is associated with its own mutex.

*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int count = 0;
pthread_mutex_t mutex;

void *routine()
{
    for (int i = 0; i < 1000000; i++)
    {
        pthread_mutex_lock(&mutex);
        count++;
        // read mails
        // increment
        // write mails
        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char *argv[])
{
    pthread_t threads[2];
    int size = sizeof(threads) / sizeof(threads[0]);
    int i;

    /*
    int pthread_mutex_init(pthread_mutex_t *restrict mutex,
           const pthread_mutexattr_t *restrict attr);
    */
    pthread_mutex_init(&mutex, NULL);

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

    pthread_mutex_destroy(&mutex);
    printf("Number of mails: %d\n", count);
    return 0;
}

/*
Expected Output:
    Number of mails: 2000000

Actual Output:
    Number of mails: 2000000
*/