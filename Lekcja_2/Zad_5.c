#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char imie[50];
    char nazwisko[50];
    char numer_telefonu[20];
};

struct Contact ksiazka_adresowa[MAX_CONTACTS];

int liczba_kontaktow = 0;

void dodajKontakt(const char *imie, const char *nazwisko, const char *numer_telefonu) {
    if (liczba_kontaktow < MAX_CONTACTS) {
        strcpy(ksiazka_adresowa[liczba_kontaktow].imie, imie);
        strcpy(ksiazka_adresowa[liczba_kontaktow].nazwisko, nazwisko);
        strcpy(ksiazka_adresowa[liczba_kontaktow].numer_telefonu, numer_telefonu);
        liczba_kontaktow++;
        printf("Kontakt dodany.\n");
    } else {
        printf("Nie mozna dodac nowego kontaktu - ksiazka adresowa pelna.\n");
    }
}

void znajdzKontakt(const char *nazwisko) {
    int znaleziono = 0;
    for (int i = 0; i < liczba_kontaktow; i++) {
        if (strcmp(ksiazka_adresowa[i].nazwisko, nazwisko) == 0) {
            printf("Znaleziono kontakt: %s %s - %s\n", ksiazka_adresowa[i].imie, ksiazka_adresowa[i].nazwisko, ksiazka_adresowa[i].numer_telefonu);
            znaleziono = 1;
        }
    }
    if (!znaleziono) {
        printf("Nie znaleziono kontaktu o nazwisku: %s\n", nazwisko);
    }
}

void usunKontakt(const char *nazwisko) {
    int indeks_usunietego = -1;
    for (int i = 0; i < liczba_kontaktow; i++) {
        if (strcmp(ksiazka_adresowa[i].nazwisko, nazwisko) == 0) {
            indeks_usunietego = i;
            break;
        }
    }
    if (indeks_usunietego != -1) {
        for (int i = indeks_usunietego; i < liczba_kontaktow - 1; i++) {
            ksiazka_adresowa[i] = ksiazka_adresowa[i + 1];
        }
        liczba_kontaktow--;
        printf("Kontakt usuniety.\n");
    } else {
        printf("Nie znaleziono kontaktu o nazwisku: %s\n", nazwisko);
    }
}

void wypiszKsiazkeAdresowa() {
    if (liczba_kontaktow == 0) {
        printf("Ksiazka adresowa jest pusta.\n");
    } else {
        printf("Ksiazka adresowa:\n");
        for (int i = 0; i < liczba_kontaktow; i++) {
            printf("%s %s - %s\n", ksiazka_adresowa[i].imie, ksiazka_adresowa[i].nazwisko, ksiazka_adresowa[i].numer_telefonu);
        }
    }
}

int main() {
    char wybor;
    char imie[50], nazwisko[50], numer_telefonu[20];

    do {
        printf("\nMenu:\n");
        printf("1. Dodaj kontakt\n");
        printf("2. Znajdz kontakt\n");
        printf("3. Usun kontakt\n");
        printf("4. Wypisz wszystkie kontakty\n");
        printf("5. Wyjdz\n");
        printf("Wybierz opcje: ");
        scanf(" %c", &wybor);

        switch (wybor) {
            case '1':
                printf("Podaj imie: ");
                scanf("%s", imie);
                printf("Podaj nazwisko: ");
                scanf("%s", nazwisko);
                printf("Podaj numer telefonu: ");
                scanf("%s", numer_telefonu);
                dodajKontakt(imie, nazwisko, numer_telefonu);
                break;
            case '2':
                printf("Podaj nazwisko do wyszukania: ");
                scanf("%s", nazwisko);
                znajdzKontakt(nazwisko);
                break;
            case '3':
                printf("Podaj nazwisko do usuniecia: ");
                scanf("%s", nazwisko);
                usunKontakt(nazwisko);
                break;
            case '4':
                wypiszKsiazkeAdresowa();
                break;
            case '5':
                printf("Koniec programu.\n");
                break;
            default:
                printf("Nieprawidlowa opcja. Sprobuj ponownie.\n");
        }
    } while (wybor != '5');

    return 0;
}