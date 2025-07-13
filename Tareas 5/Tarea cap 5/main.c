#include <stdio.h>

int main() {
    int N, i;
    int positivos = 0, negativos = 0, ceros = 0;
    int VEC[100];

    printf("Ingrese el n�mero de elementos (1 a 100): ");
    scanf("%d", &N);

    if (N < 1 || N > 100) {
        printf("N�mero de elementos fuera de rango.\n");
        return 1;
    }

    printf("Ingrese %d n�meros enteros:\n", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &VEC[i]);

        if (VEC[i] > 0)
            positivos++;
        else if (VEC[i] < 0)
            negativos++;
        else
            ceros++;
    }

    printf("Positivos: %d\n", positivos);
    printf("Negativos: %d\n", negativos);
    printf("Ceros: %d\n", ceros);

    return 0;
}
