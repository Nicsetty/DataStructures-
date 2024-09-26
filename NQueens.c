#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void printSolution(int** board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int** board, int N, int row, int col) {
    int i, j;

    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    for (i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

bool solveNQueensUtil(int** board, int N, int col) {
    if (col >= N) {
        return true;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(board, N, i, col)) {
            board[i][col] = 1;

            if (solveNQueensUtil(board, N, col + 1)) {
                return true;
            }

            board[i][col] = 0;
        }
    }

    return false;
}

bool solveNQueens(int N) {
    int** board = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        board[i] = (int*)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    if (solveNQueensUtil(board, N, 0) == false) {
        printf("Solution does not exist.\n");
        return false;
    }

    printSolution(board, N);
    for (int i = 0; i < N; i++) {
        free(board[i]);
    }
    free(board);
    return true;
}

int main() {
    int N;
    printf("Enter the number of queens (N): ");
    scanf("%d", &N);

    solveNQueens(N);
    return 0;
}
