
#include <iostream>
#include <pthread.h>
using namespace std;

void *fn_cb(void *)
{
    for (int i = 0; i < 10; ++i)
        cout << "In thread1" << endl;

    pthread_exit(nullptr);
    return nullptr;
}

int main()
{
    pthread_t thread1;
    int ret = 0;

    /*
    int pthread_create(pthread_t *restrict thread,
                          const pthread_attr_t *restrict attr,
                          void *(*start_routine)(void *),
                          void *restrict arg);
    -- create a new thread
    -- On success, pthread_create() returns 0; on error, it returns an
       error number, and the contents of *thread are undefined.
    */

    ret = pthread_create(&thread1, nullptr, &fn_cb, nullptr);

    if (ret != 0)
    {
        cout << "Thread Creation Failed" << endl;
        exit(0);
    }

    for (int i = 0; i < 10; ++i)
        cout << "In main thread" << endl;

    ret = pthread_join(thread1, nullptr);

    if (ret != 0)
    {
        cout << "Thread Join Failed" << endl;
        exit(0);
    }

    cout << endl;

    return 0;
}