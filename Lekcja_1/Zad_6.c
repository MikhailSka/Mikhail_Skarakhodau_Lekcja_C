#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int losowyRuchKomputera() {
    return rand() % 3 + 1;
}

const char* nazwaRuchu(int numer) {
    switch (numer) {
        case 1:
            return "Papier";
        case 2:
            return "Kamień";
        case 3:
            return "Nożyce";
        default:
            return "Nieznany ruch";
    }
}

int main() {
    srand(time(NULL));

    int liczbaRund;
    printf("Podaj liczbę rund: ");
    scanf("%d", &liczbaRund);

    int wyniki[3] = {0}; 
    int ruchyGracza[liczbaRund];
    int ruchyKomputera[liczbaRund];

    for (int runda = 0; runda < liczbaRund; runda++) {
        printf("\nRunda %d:\n", runda + 1);

        int ruchGracza;
        do {
            printf("Wybierz ruch (1 - Papier, 2 - Kamień, 3 - Nożyce): ");
            scanf("%d", &ruchGracza);
        } while (ruchGracza < 1 || ruchGracza > 3);

        int ruchKomputera = losowyRuchKomputera();

        ruchyGracza[runda] = ruchGracza;
        ruchyKomputera[runda] = ruchKomputera;

        if ((ruchGracza == 1 && ruchKomputera == 3) ||
            (ruchGracza == 2 && ruchKomputera == 1) ||
            (ruchGracza == 3 && ruchKomputera == 2)) {
            printf("Wygrałeś rundę!\n");
            wyniki[0]++;
        } else if (ruchGracza == ruchKomputera) {
            printf("Remis w rundzie.\n");
            wyniki[2]++;
        } else {
            printf("Przegrałeś rundę.\n");
            wyniki[1]++;
        }
    }

    printf("\nWyniki po %d rundach:\n", liczbaRund);
    printf("Gracz: %d, Komputer: %d, Remisy: %d\n", wyniki[0], wyniki[1], wyniki[2]);

    char komenda[10];
    printf("\nWpisz 'scores' aby zobaczyć ruchy z poszczególnych rund: ");
    scanf("%s", komenda);

    if (strcmp(komenda, "scores") == 0) {
        printf("\nRuchy z poszczególnych rund:\n");
        for (int i = 0; i < liczbaRund; i++) {
            printf("Runda %d: Gracz - %s, Komputer - %s\n", i + 1, nazwaRuchu(ruchyGracza[i]), nazwaRuchu(ruchyKomputera[i]));
        }
    }

    return 0;
}