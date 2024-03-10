#include <stdio.h>

int sumaWielokrotnosci(int n)
{
    if (n < 0) {
        return 0;
    }

    int suma = 0;

    for (int i = 1; i < n; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            suma += i;
        }
    }

    return suma;
}

int main()
{
    int liczba;

    printf("Podaj liczbę: ");
    scanf("%d", &liczba);

    printf("Suma wielokrotności 3 lub 5 poniżej %d wynosi: %d\n", liczba, sumaWielokrotnosci(liczba));

    return 0;
}