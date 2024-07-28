# Mutex Basics

### Introduction to Mutex

A **mutex** (short for "mutual exclusion") is a synchronization primitive used to prevent multiple threads from simultaneously accessing a shared resource, such as a variable, data structure, or file. This helps avoid data races and ensures data consistency.

### Why Use a Mutex?

In multithreaded programs, different threads might need to access and modify shared resources concurrently. Without proper synchronization, this can lead to data races, where the outcome depends on the non-deterministic timing of the threads. Mutexes provide a way to ensure that only one thread can access a shared resource at a time, maintaining data integrity.

### Functions of a Mutex

1. **Locking (`lock()`)**:

   - A thread calls `lock()` on a mutex to gain exclusive access to the shared resource.
   - If the mutex is already locked by another thread, the calling thread will block (wait) until the mutex becomes available.

2. **Unlocking (`unlock()`)**:

   - A thread calls `unlock()` on a mutex to release the lock, allowing other threads to acquire the mutex.
   - It is crucial to ensure that every `lock()` is paired with a corresponding `unlock()` to avoid deadlocks.

3. **Try Locking (`try_lock()`)**:

   - A thread calls `try_lock()` on a mutex to attempt to acquire the lock without blocking.
   - If the mutex is already locked, `try_lock()` returns `false`; otherwise, it locks the mutex and returns `true`.

4. **Timed Locking (`try_lock_for()` and `try_lock_until()`)**:
   - These functions allow a thread to attempt to acquire a lock for a specific duration or until a certain point in time.
   - Useful in scenarios where a thread should not block indefinitely.

### Using Mutex in C++

The C++ Standard Library provides the `<mutex>` header, which includes various mutex types and functions for thread synchronization.

#### Example: Basic Mutex Usage

Here's a simple example demonstrating how to use a `std::mutex` to protect a shared resource:

```cpp
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx; // Global mutex

void print_thread_id(int id) {
    mtx.lock(); // Acquire the lock
    std::cout << "Thread " << id << " is accessing the shared resource.\n";
    mtx.unlock(); // Release the lock
}

int main() {
    std::thread threads[10];
    for (int i = 0; i < 10; ++i) {
        threads[i] = std::thread(print_thread_id, i);
    }
    for (auto& th : threads) {
        th.join();
    }
    return 0;
}
```

In this example:

- A global `std::mutex` object `mtx` is used to synchronize access to the `std::cout` stream.
- Each thread calls `print_thread_id`, which locks the mutex before printing and unlocks it afterward.

#### Example: Using `std::lock_guard`

A safer and more exception-safe way to manage locks is by using `std::lock_guard`:

```cpp
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx; // Global mutex

void print_thread_id(int id) {
    std::lock_guard<std::mutex> guard(mtx); // Acquire the lock and automatically release it when out of scope
    std::cout << "Thread " << id << " is accessing the shared resource.\n";
}

int main() {
    std::thread threads[10];
    for (int i = 0; i < 10; ++i) {
        threads[i] = std::thread(print_thread_id, i);
    }
    for (auto& th : threads) {
        th.join();
    }
    return 0;
}
```

In this example:

- `std::lock_guard` is a RAII (Resource Acquisition Is Initialization) class that locks the mutex when it is created and automatically unlocks it when it goes out of scope, ensuring that the mutex is always properly released even if an exception occurs.
