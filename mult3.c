
// While using the blocking method, set the array size N to 2048, and vary the blocking factor B from 4 to 512 (in power of two only)

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N 1024

double **A;
double **B;
double **C;

// Initialize matrices A and B with random numbers and set matrix C to 0
void init_matrices()
{
    A = malloc(N * sizeof(double *));
    B = malloc(N * sizeof(double *));
    C = malloc(N * sizeof(double *));
    for (int i = 0; i < N; i++)
    {
        A[i] = malloc(N * sizeof(double));
        B[i] = malloc(N * sizeof(double));
        C[i] = malloc(N * sizeof(double));
        for (int j = 0; j < N; j++)
        {
            A[i][j] = (double)rand() / RAND_MAX;
            B[i][j] = (double)rand() / RAND_MAX;
            C[i][j] = 0.0;
        }
    }
}

// Perform matrix multiplication on matrices A and B and store the result in matrix C

void matrix_mult_block(int N, int B)
{
    for (int i = 0; i < N; i += B)
    {
        for (int j = 0; j < N; j += B)
        {
            for (int k = 0; k < N; k += B)
            {
                for (int i1 = i; i1 < i + B; i1++)
                {
                    for (int j1 = j; j1 < j + B; j1++)
                    {
                        for (int k1 = k; k1 < k + B; k1++)
                        {
                            C[i1][j1] += A[i1][k1] * B[k1][j1];
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
    init_matrices();

    for (int b = 4; b <= 512; b *= 2)
    {
        gettimeofday(&start, NULL);
        matrix_mult_block(2048, b);
        gettimeofday(&end, NULL);
        double elapsed_time = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
        printf("Blocking factor: %d, Elapsed time: %lf microseconds\n", b, elapsed_time);
    }

    return 0;
}

/*
int main()
{
    struct timeval start, end;
    init_matrices();
    gettimeofday(&start, NULL);
    matrix_mult();
    gettimeofday(&end, NULL);
    double elapsed_time = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
    printf("Elapsed time: %lf microseconds\n", elapsed_time);
    for (int i = 0; i < N; i++)
    {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);
    return 0;
}
*/
