
# Optimization of matrix multiplication algorithms</h1>

This falls under High Performance Computing (HPC). It involves improving the performance of matrix multiplication algorithms through techniques such as blocking and compiler optimization. It also involves understanding the underlying hardware architecture and how it impacts the performance of the algorithm, and finding ways to optimize the code to take advantage of the hardware's features.

## Matrix Multiplication

Matrix multiplication is an operation in mathematics and computer science that takes two matrices as input and returns a single matrix as output. It is used in a wide range of applications, such as numerical computing, image processing, and machine learning. Matrix multiplication is important because it is used as the building block of many more complex algorithms and operations.

## Problem Statement

Matrix multiplication is a computationally expensive task, particularly when the size of the matrices being multiplied is large. As the size of the matrices increases, the number of operations required to compute the result grows exponentially, leading to longer execution times and increased resource usage. This is a major performance challenge in matrix multiplication, as it can limit the scalability and efficiency of many important applications.

## Background

There are two main methods for performing matrix multiplication: the traditional method and the blocking method. The traditional method computes the result by multiplying each element of one matrix with each element of the other matrix and summing the results. This method is straightforward, but it can be slow for large matrices due to the high number of operations required.

The blocking method **(which was the one that was implemented for this program)** is a more optimized approach that involves dividing the matrices into smaller blocks, multiplying the blocks, and combining the results. This method takes advantage of the cache hierarchy in modern computers to reduce the number of cache misses and improve performance. The blocking factor, B, determines the size of the blocks and can be tuned to achieve the optimal performance for a given system.

## Methodology

In the implementation of the blocking method, the blocking factor B was set to 8, and the array size was varied from N=16 to 4096. The performance of the blocking method was compared to the traditional method by measuring the execution time for each configuration. The testing environment was a standard desktop computer running Windows, with 500GB ROM and 8GB RAM, 4 intel corei5 First Generation processors, and the performance was measured using performance counters in the OS.

The optimal blocking factor was determined by varying the blocking factor B and measuring the execution time for each configuration. The optimal blocking factor depends on the size of the matrices, the cache size of the system, and the specifics of the implementation.

In conclusion, the blocking method provides a significant improvement in performance over the traditional method for matrix multiplication, especially for large-scale matrices. The choice of the optimal blocking factor is a trade-off between the overhead of dividing the matrices into blocks and the reduction in cache misses and computation time. The blocking method is a powerful technique that can be used to improve the performance of many other algorithms and operations.

