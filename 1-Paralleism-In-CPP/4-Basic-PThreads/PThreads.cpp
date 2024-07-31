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

int main(){

    //Creating an array of 10 threads
    pthread_t threads[NUM_THREADS];
    Args per_thread_args[NUM_THREADS];

    //Creating 10 threads
    for(int i = 0; i<NUM_THREADS; i++){
        per_thread_args[i].tid = i;
        per_thread_args[i].data = i*i;

        /*
        Now we are launching the threads

        Arguments:
            1) Pointer to the pthread_t
            2) Attributes for the thread(NULL means default)
            3) Entry routine
            4) Arguments
        */
        pthread_create(&threads[i], NULL, boring_thread_function, (void*)&per_thread_args[i]);
    }

    
}

