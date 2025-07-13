#include <stdio.h>
#include <string.h>

int longitud(char *cad);  /* Prototipo de funci�n */

int main(void)
{
    int i, n, l = -1, p = 0, t;
    char cad[50], FRA[20][50];

    printf("\nIngrese el n�mero de filas del arreglo: ");
    scanf("%d", &n);
    getchar();  // limpia el salto de l�nea despu�s de scanf

    for (i = 0; i < n; i++)
    {
        printf("Ingrese la l�nea %d de texto. M�ximo 50 caracteres: ", i + 1);
        fgets(FRA[i], 50, stdin);
        // quitar salto de l�nea si existe
        t = strlen(FRA[i]);
        if (t > 0 && FRA[i][t - 1] == '\n')
            FRA[i][t - 1] = '\0';
    }

    printf("\n");

    for (i = 0; i < n; i++)
    {
        strcpy(cad, FRA[i]);
        t = longitud(cad);
        if (t > l)
        {
            l = t;
            p = i;
        }
    }

    printf("\nLa cadena con mayor longitud es:\n");
    puts(FRA[p]);
    printf("\nLongitud: %d\n", l);

    return 0;
}

int longitud(char *cadena)
{
    int cue = 0;
    while (cadena[cue] != '\0')
        cue++;
    return cue;
}
