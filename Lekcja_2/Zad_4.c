#include <stdio.h>
#include <string.h>

struct Student {
    char imie[50];
    float ocena_koncowa;
};

void zamien(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

void sortujStudentow(struct Student *tablica, int rozmiar) {
    int i, j;
    for (i = 0; i < rozmiar - 1; i++) {
        for (j = 0; j < rozmiar - i - 1; j++) {
            if (tablica[j].ocena_koncowa < tablica[j + 1].ocena_koncowa) {
                zamien(&tablica[j], &tablica[j + 1]);
            }
        }
    }
}

int main() {
    struct Student lista_studentow[10] = {
        {"Adam", 4.5},
        {"Barbara", 3.2},
        {"Cezary", 5.0},
        {"Dorota", 4.1},
        {"Ewa", 4.8},
        {"Filip", 3.9},
        {"Gosia", 4.7},
        {"Henryk", 4.0},
        {"Irena", 3.5},
        {"Jan", 4.3}
    };

    sortujStudentow(lista_studentow, 10);

    printf("Posortowana lista studentow:\n");
    for (int i = 0; i < 10; i++) {
        printf("%s - %.1f\n", lista_studentow[i].imie, lista_studentow[i].ocena_koncowa);
    }

    return 0;
}