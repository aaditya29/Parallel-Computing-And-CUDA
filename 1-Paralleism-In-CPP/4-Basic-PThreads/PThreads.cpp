//Here we are showing multithreading basics using pthreads

#include <iostream>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 10

//Global pthread implementation of mutex lock
pthread_mutex_t mtx;

//Here we are creating Args named struct
// Args will be casted as void* for or thread function
struct Args {
    int tid;
    int data;

};

// pthread function must have return type void*, with a void* arg
void *boring_thread_function(void *args){
    Args *local_args = (Args*)args;
    //Getting the lock before entering the critical section
    pthread_mutex_lock(&mtx);
    //Entering critical section
    cout<<"Printing from the thread "<<local_args->tid<<endl;
    cout<<"Value of the data is "<<local_args->data<<endl;
    pthread_mutex_unlock(&mtx);
}



