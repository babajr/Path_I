/*
void pthread_exit(void *retval); -->terminate calling thread

The pthread_exit() function terminates the calling thread and
returns a value via retval that (if the thread is joinable) is
available to another thread in the same process that calls
pthread_join(3).
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

using namespace std;

void *roll_dice(void *arg)
{
    int value = (rand() % 6) + 1;
    int *result = (int *)malloc(sizeof(int));
    *result = value;
    sleep(2);
    cout << "Thread result:" << value << endl;
    pthread_exit((void *)result);
}

int main(int argc, char *argv[])
{
    int *res;
    srand(time(NULL));
    pthread_t th;

    if (pthread_create(&th, NULL, &roll_dice, NULL) != 0)
    {
        perror("Failed to creat thread\n");
        exit(0);
    }
    // pthread_exit(0);

    if (pthread_join(th, (void **)&res) != 0)
    {
        perror("Failed to creat thread\n");
        exit(0);
    }

    printf("Result: %d\n", *res);
    free(res);

    return 0;
}