//Here we are showing multithreading basics using pthreads

#include <iostream>
#include <pthread.h> //header file for POSIX threads 

using namespace std;

// Preprocessor directive that defines a constant named NUM_THREADS with a value of 10.
// Here it indicates that we will create 10 threads
#define NUM_THREADS 10

//Global pthread implementation of mutex lock
// Declaring  mutex variable mtx which will be used to ensure that only one thread can execute a critical section of code at a time
pthread_mutex_t mtx;

//Here we are creating Args named struct
// Args will be casted as void* for or thread function
struct Args {
    int tid;//thread id
    int data;//data

};

// pthread function must have return type void*, with a void* arg
// This function  will be executed by each thread
void *boring_thread_function(void *args){
    /*
    This line is performing a type cast and assignment.
    1) Args *local_args: This declares a pointer named local_args to an Args structure.
    2) (Args*)args: This is a C-style cast. It's taking the args parameter (which is of type void*) and casting it to a pointer to an Args structure.
    */
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
    //This declares an array of Args structures to hold the arguments for each thread.
    Args per_thread_args[NUM_THREADS];

    //Creating 10 threads
    for(int i = 0; i<NUM_THREADS; i++){
        per_thread_args[i].tid = i;//sets thread id
        per_thread_args[i].data = i*i;// This sets the data value to the square of the thread ID.

        /*
        Now we are launching the threads

        Arguments:
            1) Pointer to the pthread_t
            2) Attributes for the thread(NULL means default)
            3) Entry routine
            4) Arguments
        */
       //This creates a new thread, passing the corresponding Args structure as an argument.
        pthread_create(&threads[i], NULL, boring_thread_function, (void*)&per_thread_args[i]);
    }

    //returning code for the thread
    void *ret;
    //Waiting for all threads to finish before exiting the program
    for(int i = 0; i<NUM_THREADS; i++){
        //Here we wait for the thread threads[i] to finish and retrieves its return value.
        pthread_join(threads[i], &ret);
    }
}

