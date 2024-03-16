#include <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    int num;
    printf("Podaj liczbę, dla której chcesz obliczyć silnię: ");
    scanf("%d", &num);

    printf("%d! = %d\n", num, factorial(num));

    return 0;
}
