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

    for(int i = 0; i < 10; i++){
        t[i].join();
    }

    return 0;
}