#include <stdio.h>

// Funkcja do dodawania dwóch liczb
int dodawanie(int a, int b) {
    return a + b;
}

// Funkcja do mnożenia dwóch liczb
int mnozenie(int a, int b) {
    return a * b;
}

// Funkcja do odejmowania dwóch liczb
int odejmowanie(int a, int b) {
    return a - b;
}

int main() {
    int (*wskaźnik_do_funkcji)(int, int); // Definicja wskaźnika do funkcji

    // Zapytanie użytkownika, jaką operację chce wykonać
    printf("Wybierz operację:\n");
    printf("1. Dodawanie\n");
    printf("2. Mnożenie\n");
    printf("3. Odejmowanie\n");
    int wybor;
    scanf("%d", &wybor);

    // Ustawienie wskaźnika do odpowiedniej funkcji w zależności od wyboru użytkownika
    switch (wybor) {
        case 1:
            wskaźnik_do_funkcji = &dodawanie;
            break;
        case 2:
            wskaźnik_do_funkcji = &mnozenie;
            break;
        case 3:
            wskaźnik_do_funkcji = &odejmowanie;
            break;
        default:
            printf("Błędny wybór.\n");
            return 1;
    }

    // Pobranie liczb od użytkownika
    int a, b;
    printf("Podaj dwie liczby: ");
    scanf("%d %d", &a, &b);

    // Wywołanie odpowiedniej funkcji za pomocą wskaźnika do funkcji i wyświetlenie wyniku
    int wynik = (*wskaźnik_do_funkcji)(a, b);
    printf("Wynik operacji: %d\n", wynik);

    return 0;
}
