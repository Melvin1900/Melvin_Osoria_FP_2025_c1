#include <stdio.h>
#include <math.h>

int main(void)
{
    float RAD, ALT, VOL, ARE;

    printf("Ingrese el radio y la altura del cilindro: ");
    scanf("%f %f", &RAD, &ALT);

    VOL = M_PI * pow(RAD, 2) * ALT;
    ARE = 2 * M_PI * RAD * ALT;

    printf("\nEl volumen es: %6.2f\tEl área es: %6.2f", VOL, ARE);

    return 0;
}
