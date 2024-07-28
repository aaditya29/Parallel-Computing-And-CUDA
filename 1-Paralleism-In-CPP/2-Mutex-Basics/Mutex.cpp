#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

//Adding global mutex lock for the critical section
mutex mtx;