#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

//Adding global mutex lock for the critical section
mutex mtx;

//Initial function for each thread
void call_from(int tid){
    mtx.lock();
    cout<<"Launched by thread: "<<tid<<endl;
    mtx.unlock();
}

int main(){
    //Creating an array of 10 thread objects
    thread t[10];

    //Launching 10 threads from the initial function call_from
    for(int i = 0; i<10; i++){
        t[i] = thread(call_from, i);
    }

    
}