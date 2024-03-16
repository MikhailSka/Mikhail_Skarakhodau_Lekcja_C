#include <stdio.h>


int pascalValue(int row, int col) {
    if (col == 0 || col == row)
        return 1;
    else
        return pascalValue(row - 1, col - 1) + pascalValue(row - 1, col);
}


void displayPascalTriangle(int height) {
    int row, col;
    for (row = 0; row < height; row++) {
        for (col = 0; col <= row; col++) {
            printf("%d ", pascalValue(row, col));
        }
        printf("\n");
    }
}

int main() {
    int height;
    printf("Podaj wysokość trójkąta Pascala: ");
    scanf("%d", &height);

    displayPascalTriangle(height);

    return 0;
}