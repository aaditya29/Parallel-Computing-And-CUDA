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
