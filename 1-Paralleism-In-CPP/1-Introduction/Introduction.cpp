#include <iostream>
#include<thread> //library for the thread
using namespace std;

//making initial function for the each thread
void call_from(int tid){
    cout<<"Launched by the thread: "<<tid<<endl;
}

int main(){
    //Creating an array of 10 thread objects
    thread t[10];

    //Launching 10 threads from the initial function "call_from"
    //threads need a function to initialise them
    for(int i = 0; i < 10; i++){
        t[i] = thread(call_from, i);//Calling constructor for thread with passing the thread i

    }

    //Printing from the main function
    cout<<"Launched the threads from the main() "<<endl;

    //Waiting for all the threads to finish
    /*
    Here another  loop runs from 0 to 9, calling join() on each thread.
    join() makes the main thread wait until the corresponding thread t[i] has finished execution.
    This ensures that the main function doesn't terminate before all the threads have completed their tasks.
    */
    for(int i = 0; i < 10; i++){
        t[i].join();
    }

    return 0;

}