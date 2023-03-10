// varying the array size from N=16 to 4096 (doubling the value of N each time)

/*using a loop to vary the array size from N=16 to 4096, doubling the value of N each time, I replaced the macro definition of N with a variable size and changed the macro usage in the code with the variable size. I then used a loop to iterate size from 16 to 4096, doubling its value at each iteration*/

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
void matrix_mult(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main()
{
    struct timeval start, end;
    for (int size = 16; size <= 4096; size *= 2)
    {
        init_matrices(size);
        gettimeofday(&start, NULL);
        matrix_mult(size);
        gettimeofday(&end, NULL);
        double elapsed_time = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
        printf("Elapsed time for size %d: %lf microseconds\n", size, elapsed_time);
        for (int i = 0; i < size; i++)
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
