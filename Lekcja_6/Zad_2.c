#include <stdio.h>

int main() {
    // Tworzenie tablicy dziesięciu liczb całkowitych i inicjalizacja jej wartościami od 0 do 9
    int tablica[10];
    for (int i = 0; i < 10; i++) {
        tablica[i] = i;
    }

    // Używanie wskaźnika do wyświetlenia każdego elementu tablicy z wykorzystaniem arytmetyki wskaźników
    int *wskaznik = tablica; // Inicjalizacja wskaźnika na początek tablicy
    for (int i = 0; i < 10; i++) {
        printf("Wartość elementu %d: %d\n", i, *wskaznik);
        wskaznik++; // Przesunięcie wskaźnika do następnego elementu tablicy
    }

    return 0;
}
