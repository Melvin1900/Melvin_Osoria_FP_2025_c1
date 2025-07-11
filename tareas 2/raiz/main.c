#include <stdio.h>
#include <stdio.h>

int main() {
    float numero, x, y, error;

    numero = 2;
    x = numero;
    y = 1;
    error = 0.00001;
    while ((x - y) > error) {
        x = (x + y) / 2;
        y = numero / x;
    }
    printf("La raiz cuadrada de 2 es aproximadamente: %.4f\n", x);

    numero = 4;
    x = numero;
    y = 1;
    while ((x - y) > error) {
        x = (x + y) / 2;
        y = numero / x;
    }
    printf("La raiz cuadrada de 4 es aproximadamente: %.4f\n", x);

    numero = 16;
    x = numero;
    y = 1;
    while ((x - y) > error) {
        x = (x + y) / 2;
        y = numero / x;
    }
    printf("La raiz cuadrada de 16 es aproximadamente: %.4f\n", x);

    return 0;
}
