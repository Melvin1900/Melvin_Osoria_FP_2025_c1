#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char c, cad[10];
    int i = 0;
    float sum = 0.0;

    printf("\nDesea ingresar una cadena de caracteres (S/N)? ");
    scanf(" %c", &c);

    while (c == 'S' || c == 's')
    {
        printf("\nIngrese la cadena de caracteres: ");
        scanf("%s", cad);
        sum += atof(cad);
        i++;

        printf("\nDesea ingresar otra cadena de caracteres (S/N)? ");
        scanf(" %c", &c);
    }

    if (i > 0)
    {
        printf("\nSuma: %.2f", sum);
        printf("\nPromedio: %.2f", sum / i);
    }
    else
    {
        printf("\nNo se ingresaron datos.");
    }

    return 0;
}
