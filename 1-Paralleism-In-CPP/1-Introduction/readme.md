# Introduction to Paralleism in C++

## What is Parallelism?

Parallelism is the process of executing multiple tasks or computations simultaneously to improve performance and efficiency. This can be done by dividing a task into smaller subtasks that can be processed concurrently, utilizing multiple processors or cores in a computer system.

### Types of Parallelism

1. **Task Parallelism**:
   - **Definition**: Different tasks are executed concurrently.
   - **Example**: One thread processes user input while another handles network communication.
2. **Data Parallelism**:

   - **Definition**: The same task is executed on different subsets of data.
   - **Example**: Performing the same operation on each element of an array concurrently.

3. **Instruction-Level Parallelism (ILP)**:

   - **Definition**: Multiple instructions from a single thread are executed simultaneously.
   - **Example**: Modern CPUs with pipelining and superscalar architecture.

4. **Bit-Level Parallelism**:
   - **Definition**: Operations are performed on the binary representation of data in parallel.
   - **Example**: Using bitwise operations to manipulate data in parallel.

### Why Parallelism is Needed in the Modern World

1. **Performance Improvement**: Parallelism can significantly reduce the time required to complete computationally intensive tasks by utilizing multiple processing units.

2. **Efficient Resource Utilization**: Modern computer systems come with multiple cores and processors. Parallelism helps in efficiently utilizing these resources to maximize throughput.

3. **Scalability**: As data volumes and computational requirements grow, parallelism provides a scalable solution to handle large-scale problems efficiently.

4. **Real-time Processing**: Applications like gaming, simulations, and real-time data analysis require rapid processing. Parallelism enables these applications to meet their performance requirements.

5. **Energy Efficiency**: By completing tasks faster and reducing idle times, parallelism can lead to more energy-efficient computing.

## Parallelism in C++

C++ provides several mechanisms and libraries to support parallelism:

1. **Multithreading with `<thread>` Library**:

   - **Example**:

     ```cpp
     #include <iostream>
     #include <thread>

     void task() {
         std::cout << "Task is running\n";
     }

     int main() {
         std::thread t(task);
         t.join();  // Wait for the thread to complete
         return 0;
     }
     ```

2. **OpenMP**:

   - **Example**:

     ```cpp
     #include <iostream>
     #include <omp.h>

     int main() {
         #pragma omp parallel
         {
             std::cout << "Hello from thread " << omp_get_thread_num() << "\n";
         }
         return 0;
     }
     ```

3. **Parallel STL (C++17)**:

   - **Example**:

     ```cpp
     #include <algorithm>
     #include <vector>
     #include <execution>
     #include <iostream>

     int main() {
         std::vector<int> v = {1, 2, 3, 4, 5};
         std::for_each(std::execution::par, v.begin(), v.end(), [](int& n) { n *= 2; });

         for (int n : v) {
             std::cout << n << " ";
         }
         return 0;
     }
     ```
