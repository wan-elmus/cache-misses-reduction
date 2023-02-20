
/*
using the blocking method,set the array size N to 2048 and vary the blocking factor B from 4 to 512(in power of two only)
To achieve this I only modified the main function.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double **P;
double **Q;
double **R;

// Initialize matrices A and B with random numbers and set matrix C to 0
void init_matrices(int size)
{
    P = malloc(size * sizeof(double *));
    Q = malloc(size * sizeof(double *));
    R = malloc(size * sizeof(double *));
    for (int i = 0; i < size; i++)
    {
        P[i] = malloc(size * sizeof(double));
        Q[i] = malloc(size * sizeof(double));
        R[i] = malloc(size * sizeof(double));
        for (int j = 0; j < size; j++)
        {
            P[i][j] = (double)rand() / RAND_MAX;
            Q[i][j] = (double)rand() / RAND_MAX;
            R[i][j] = 0.0;
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
                            R[ii][jj] += P[ii][kk] * Q[kk][jj];
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
        double elapsed_time = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
        printf("Elapsed time for B %d: %lf microseconds\n", B, elapsed_time);
        for (int i = 0; i < N; i++)
        {
            free(P[i]);
            free(Q[i]);
            free(R[i]);
        }
        free(P);
        free(Q);
        free(R);
    }
    return 0;
}
