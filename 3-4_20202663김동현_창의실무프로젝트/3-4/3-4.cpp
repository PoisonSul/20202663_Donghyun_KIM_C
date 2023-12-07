#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ROWS 3
#define COLS 3

int main(void) {
    int A[ROWS][COLS] = { {1, 1, 1}, {2, 2, 2}, {3, 3, 3} };
    int B[ROWS][COLS] = { {4, 4, 4}, {5, 5, 6}, {6, 6, 6} };
    int C[ROWS][COLS];


    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            C[i][j] = 0;
            for (int k = 0; k < ROWS; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }


    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%2d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}