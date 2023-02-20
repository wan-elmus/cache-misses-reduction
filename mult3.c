

/*Implement the blocking method, set the blocking factor B to 8, and vary the array size as above (from	N = 16 to 4096)

Inorder to implement the blocking factor, I modified the matrix multiplication code. Instead of performing the matrix multiplication on the entire matrices A and B at once,I performed the matrix multiplication on smaller sub-matrices of size size/B, where B is the blocking factor.

And then, in the main function, I called the matrix_mult_blocked instead of matrix_mult and passed the blocking factor B=8 as an argument:
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double **P;
double **Q;
double **R;

// Initialize matrices P and Q with random numbers and set matrix R to 0
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

// Perform matrix multiplication on matrices P and Q and store the result in matrix R
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
    for (int size = 16; size <= 4096; size *= 2)
    {
        init_matrices(size);
        gettimeofday(&start, NULL);
        matrix_mult_blocked(size, 8);
        gettimeofday(&end, NULL);
        double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
        printf("Elapsed time for size %d: %d seconds %d microseconds\n", size, (int)elapsed_time, (int)((elapsed_time - (int)elapsed_time) * 1000000));

        for (int i = 0; i < size; i++)
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
