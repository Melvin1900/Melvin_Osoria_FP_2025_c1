#include <stdio.h>
#include <string.h>

void intercambia(char FRA[][30], int n);

int main(void)
{
    int i, n;
    char FRA[20][30];

    printf("\nIngrese el número de filas del arreglo: ");
    scanf("%d", &n);
    getchar(); // limpiar el salto de línea después de scanf

    for (i = 0; i < n; i++)
    {
        printf("Ingrese la línea de texto número %d: ", i + 1);
        fgets(FRA[i], 30, stdin);
        // eliminar salto de línea si existe
        size_t len = strlen(FRA[i]);
        if (len > 0 && FRA[i][len - 1] == '\n')
            FRA[i][len - 1] = '\0';
    }

    printf("\n\n");
    intercambia(FRA, n);

    for (i = 0; i < n; i++)
    {
        printf("Impresión de la línea de texto %d: ", i + 1);
        puts(FRA[i]);
    }

    return 0;
}

void intercambia(char FRA[][30], int n)
{
    int i, j;
    char cad[30];
    j = n - 1;

    for (i = 0; i < (n / 2); i++)
    {
        strcpy(cad, FRA[i]);
        strcpy(FRA[i], FRA[j]);
        strcpy(FRA[j], cad);
        j--;
    }
}
