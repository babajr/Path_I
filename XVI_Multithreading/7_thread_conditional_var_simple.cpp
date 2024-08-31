#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <errno.h>

using namespace std;

int done = 1;
pthread_mutex_t lock_;
pthread_cond_t cond_;

void *routine(void *arg)
{
    pthread_mutex_lock(&lock_);

    if (done == 1)
    {
        done = 2;
        cout << "Waiting on condition variable cond_\n";
        pthread_cond_wait(&cond_, &lock_);
    }
    else
    {
        cout << "Signallong condition variable cond_\n";
        pthread_cond_signal(&cond_);
    }

    pthread_mutex_unlock(&lock_);

    cout << "Returning thread\n";
}

int main(void)
{
    pthread_t thread1, thread2;

    pthread_mutex_init(&lock_, NULL);
    pthread_cond_init(&cond_, NULL);

    if (pthread_create(&thread1, NULL, &routine, NULL) != 0)
    {
        perror("Failed to creat thread\n");
        exit(0);
    }

    // sleep for 1 sec so that thread 1 would get a chance to run first
    sleep(1);

    if (pthread_create(&thread2, NULL, &routine, NULL) != 0)
    {
        perror("Failed to creat thread\n");
        exit(0);
    }

    // wait for the completion of thread 2
    if (pthread_join(thread2, NULL) != 0)
    {
        perror("Failed to join thread");
        exit(0);
    }

    pthread_mutex_destroy(&lock_);
    pthread_cond_destroy(&cond_);

    return 0;
}