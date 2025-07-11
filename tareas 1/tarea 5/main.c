#include <stdio.h>
#include <stdio.h>

int main(void)
{
    float ECA;

    printf("Ingrese la extensión de la estancia: ");
    scanf("%f", &ECA);

    ECA = ECA * 4047 / 10000;

    printf("\nExtensión de la estancia en hectáreas: %5.2f", ECA);

    return 0;
}
