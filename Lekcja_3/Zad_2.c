#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **allocateMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        printf("Błąd alokacji pamięci!\n");
        exit(1);
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Błąd alokacji pamięci!\n");
            exit(1);
        }
    }
    return matrix;
}

void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void fillMatrix(int **matrix, int rows, int cols) {
    srand(time(NULL)); 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100; 
        }
    }
}

void displayMatrix(int **matrix, int rows, int cols) {
    printf("Zawartość macierzy:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

    printf("Podaj liczbę wierszy macierzy: ");
    scanf("%d", &rows);
    printf("Podaj liczbę kolumn macierzy: ");
    scanf("%d", &cols);

    int **matrix = allocateMatrix(rows, cols);

    fillMatrix(matrix, rows, cols);

    displayMatrix(matrix, rows, cols);

    freeMatrix(matrix, rows);

    return 0;
}
