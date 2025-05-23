#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    float PIE, LIB, MET, KIL;

    printf("Ingrese los datos del objeto (longitud en pies y peso en libras): ");
    scanf("%f %f", &PIE, &LIB);

    MET = PIE * 0.3048;
    KIL = LIB * 0.45359;

    printf("\nDatos del objeto\nLongitud: %5.2f m\tPeso: %5.2f kg\n", MET, KIL);
}
