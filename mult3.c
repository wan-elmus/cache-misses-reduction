
/*
using the blocking method,set the array size N to 2048 and vary the blocking factor B from 4 to 512(in power of two only)
To achieve this I only modified the main function.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double **A;
double **B;
double **C;

// Initialize matrices A and B with random numbers and set matrix C to 0
void init_matrices(int size)
{
    A = malloc(size * sizeof(double *));
    B = malloc(size * sizeof(double *));
    C = malloc(size * sizeof(double *));
    for (int i = 0; i < size; i++)
    {
        A[i] = malloc(size * sizeof(double));
        B[i] = malloc(size * sizeof(double));
        C[i] = malloc(size * sizeof(double));
        for (int j = 0; j < size; j++)
        {
            A[i][j] = (double)rand() / RAND_MAX;
            B[i][j] = (double)rand() / RAND_MAX;
            C[i][j] = 0.0;
        }
    }
}

// Perform matrix multiplication on matrices A and B and store the result in matrix C
void matrix_mult_blocked(int size, int B)
{
    for (int i = 0; i < size; i += B)
    {
        for (int j = 0; j < size; j += B)
        {
            for (int k = 0; k < size; k += B)
            {
                for (int ii = i; ii < i + B; ii++)
                {
                    for (int jj = j; jj < j + B; jj++)
                    {
                        for (int kk = k; kk < k + B; kk++)
                        {
                            C[ii][jj] += A[ii][kk] * B[kk][jj];
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    struct timeval start, end;
    int N = 2048;
    for (int B = 4; B <= 512; B *= 2)
    {
        init_matrices(N);
        gettimeofday(&start, NULL);
        matrix_mult_blocked(N, B);
        gettimeofday(&end, NULL);
        double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
        printf("Elapsed time for size %d: %d seconds %d microseconds\n", size, (int)elapsed_time, (int)((elapsed_time - (int)elapsed_time) * 1000000));

        for (int i = 0; i < N; i++)
        {
            free(A[i]);
            free(B[i]);
            free(C[i]);
        }
        free(A);
        free(B);
        free(C);
    }
    return 0;
}
