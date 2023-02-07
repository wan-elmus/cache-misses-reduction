#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N 1024

double A[N][N], B[N][N], C[N][N];

<<<<<<< HEAD
void init_matrices() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
=======
void init_matrices()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
>>>>>>> 425a639256ea2de31346dbcad81a3fbc8f3a354e
            A[i][j] = (double)rand() / RAND_MAX;
            B[i][j] = (double)rand() / RAND_MAX;
            C[i][j] = 0.0;
        }
    }
}

<<<<<<< HEAD
void matrix_mult() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
=======
void matrix_mult()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
>>>>>>> 425a639256ea2de31346dbcad81a3fbc8f3a354e
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

<<<<<<< HEAD
int main() {
=======
int main()
{
>>>>>>> 425a639256ea2de31346dbcad81a3fbc8f3a354e
    struct timeval start, end;
    init_matrices();
    gettimeofday(&start, NULL);
    matrix_mult();
    gettimeofday(&end, NULL);
    double elapsed_time = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
    printf("Elapsed time: %lf microseconds\n", elapsed_time);
    return 0;
}