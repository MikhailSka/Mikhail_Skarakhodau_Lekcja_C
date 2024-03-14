#include <stdio.h>

void modyfikuj(float *ptr) {
    *ptr *= 2;
}

int main() {
    float liczba = 5.5;

    modyfikuj(&liczba);

    printf("Nowa wartość zmiennej: %.2f\n", liczba);

    return 0;
}