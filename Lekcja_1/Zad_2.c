#include <stdio.h>

int main() {
    int grades[2][5]; // 2 wiersze dla dwóch przedmiotów, 5 kolumn dla pięciu uczniów

    printf("Podaj oceny z matematyki dla pięciu uczniów: \n");
    for (int i = 0; i < 5; i++) {
        printf("Uczeń %d: ", i + 1);
        scanf("%d", &grades[0][i]); // Wczytanie oceny z matematyki dla danego ucznia
    }

    printf("Podaj oceny z fizyki dla pięciu uczniów: \n");
    for (int i = 0; i < 5; i++) {
        printf("Uczeń %d: ", i + 1);
        scanf("%d", &grades[1][i]); // Wczytanie oceny z fizyki dla danego ucznia
    }

    double matematyka_suma = 0;
    for (int i = 0; i < 5; i++) {
        matematyka_suma += grades[0][i];
    }
    double matematyka_srednia = matematyka_suma / 5;

    double fizyka_suma = 0;
    for (int i = 0; i < 5; i++) {
        fizyka_suma += grades[1][i];
    }
    double fizyka_srednia = fizyka_suma / 5;

    printf("Średnia ocen z matematyki: %.2f\n", matematyka_srednia);
    printf("Średnia ocen z fizyki: %.2f\n", fizyka_srednia);

    return 0;
}