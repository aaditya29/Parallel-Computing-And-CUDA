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