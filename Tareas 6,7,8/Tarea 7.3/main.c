#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char p, cad[50];
    int n;

    printf("\nIngrese la cadena de caracteres (m�ximo 50): ");
    scanf(" %[^\n]", cad);  // Lee toda la l�nea, incluyendo espacios

    printf("\nIngrese la posici�n en la cadena que desea verificar: ");
    scanf("%d", &n);

    if ((n >= 1) && (n <= 50) && cad[n - 1] != '\0')
    {
        p = cad[n - 1];
        if (islower(p))
            printf("\n%c es una letra min�scula", p);
        else
            printf("\n%c no es una letra min�scula", p);
    }
    else
    {
        printf("\nEl valor ingresado de n es incorrecto");
    }

    return 0;
}
