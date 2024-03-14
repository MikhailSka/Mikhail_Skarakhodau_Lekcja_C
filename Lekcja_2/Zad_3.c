#include <stdio.h>

struct Point {
    int x;
    int y;
};

void zmienWspolrzedne(struct Point *punkt, int nowe_x, int nowe_y) {
    punkt->x = nowe_x;
    punkt->y = nowe_y;
}

struct Rectangle {
    struct Point gorny_lewy;
    struct Point dolny_prawy;
};

int poleProstokata(struct Rectangle *prostokat) {
    int szerokosc = prostokat->dolny_prawy.x - prostokat->gorny_lewy.x;
    int wysokosc = prostokat->dolny_prawy.y - prostokat->gorny_lewy.y;
    return szerokosc * wysokosc;
}

int obwodProstokata(struct Rectangle *prostokat) {
    int szerokosc = prostokat->dolny_prawy.x - prostokat->gorny_lewy.x;
    int wysokosc = prostokat->dolny_prawy.y - prostokat->gorny_lewy.y;
    return 2 * (szerokosc + wysokosc);
}

int main() {
    struct Point punkt = {3, 5};

    zmienWspolrzedne(&punkt, 7, 9);

    printf("Nowe wspolrzedne punktu: (%d, %d)\n", punkt.x, punkt.y);

    struct Rectangle prostokat = {{2, 3}, {6, 9}};

    printf("Pole prostokata: %d\n", poleProstokata(&prostokat));
    printf("Obwod prostokata: %d\n", obwodProstokata(&prostokat));

    return 0;
}
