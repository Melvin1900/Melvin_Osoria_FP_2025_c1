#include <stdio.h>
#include <string.h>

typedef struct {
    int clave;
    char nombre[15];
    float precio;
    int existencia;
} producto;

void Lectura(producto *, int);
void Ventas(producto *, int);
void Reabastecimiento(producto *, int);
void Nuevos_Productos(producto *, int *);
void Inventario(producto *, int);

int main(void)
{
    producto INV[100];
    int TAM, OPE;

    do {
        printf("Ingrese el número de productos: ");
        scanf("%d", &TAM);
    } while (TAM > 100 || TAM < 1);

    Lectura(INV, TAM);

    do {
        printf("\nIngrese operación a realizar.\n\t1 - Ventas\n\t2 - Reabastecimiento\n\t3 - Nuevos Productos\n\t4 - Inventario\n\t0 - Salir: ");
        scanf("%d", &OPE);
        switch (OPE) {
            case 1: Ventas(INV, TAM); break;
            case 2: Reabastecimiento(INV, TAM); break;
            case 3: Nuevos_Productos(INV, &TAM); break;
            case 4: Inventario(INV, TAM); break;
            case 0: break;
            default: printf("Opción inválida.\n");
        }
    } while (OPE != 0);

    return 0;
}

void Lectura(producto A[], int T)
{
    int I;
    for (I = 0; I < T; I++) {
        printf("\nIngrese información del producto %d\n", I + 1);
        printf("\tClave: ");
        scanf("%d", &A[I].clave);
        printf("\tNombre: ");
        fflush(stdin);
        fgets(A[I].nombre, 15, stdin);
        size_t len = strlen(A[I].nombre);
        if (len > 0 && A[I].nombre[len - 1] == '\n')
            A[I].nombre[len - 1] = '\0';
        printf("\tPrecio: ");
        scanf("%f", &A[I].precio);
        printf("\tExistencia: ");
        scanf("%d", &A[I].existencia);
    }
}

void Ventas(producto A[], int T)
{
    int CLA, CAN, I, RES;
    float TOT = 0.0, PAR;
    printf("\nIngrese clave del producto -0 para salir-: ");
    scanf("%d", &CLA);
    while (CLA != 0) {
        printf("\tCantidad: ");
        scanf("%d", &CAN);
        I = 0;
        while ((I < T) && (A[I].clave != CLA))
            I++;
        if (I == T)
            printf("La clave del producto es incorrecta\n");
        else {
            if (A[I].existencia >= CAN) {
                A[I].existencia -= CAN;
                PAR = A[I].precio * CAN;
                TOT += PAR;
            } else {
                printf("No existe en inventario la cantidad solicitada. Solo hay %d\n", A[I].existencia);
                printf("¿Los lleva 1 - Sí / 0 - No?: ");
                scanf("%d", &RES);
                if (RES == 1) {
                    PAR = A[I].precio * A[I].existencia;
                    TOT += PAR;
                    A[I].existencia = 0;
                }
            }
        }
        printf("\nIngrese la siguiente clave del producto -0 para salir-: ");
        scanf("%d", &CLA);
    }
    printf("\nTotal de la venta: %.2f\n", TOT);
}

void Reabastecimiento(producto A[], int T)
{
    int CLA, CAN, I;
    printf("\nIngrese clave del producto -0 para salir-: ");
    scanf("%d", &CLA);
    while (CLA != 0) {
        I = 0;
        while ((I < T) && (A[I].clave != CLA))
            I++;
        if (I == T)
            printf("La clave del producto ingresada es incorrecta\n");
        else {
            printf("\tCantidad: ");
            scanf("%d", &CAN);
            A[I].existencia += CAN;
        }
        printf("\nIngrese otra clave del producto -0 para salir-: ");
        scanf("%d", &CLA);
    }
}

void Nuevos_Productos(producto A[], int *T)
{
    int CLA, I, J;
    printf("\nIngrese clave del producto -0 para salir-: ");
    scanf("%d", &CLA);
    while ((*T < 100) && CLA != 0) {
        I = 0;
        while ((I < *T) && (A[I].clave < CLA))
            I++;
        if (I < *T && A[I].clave == CLA)
            printf("El producto ya se encuentra en el inventario\n");
        else {
            for (J = *T; J > I; J--)
                A[J] = A[J - 1];
            A[I].clave = CLA;
            printf("\tNombre: ");
            fflush(stdin);
            fgets(A[I].nombre, 15, stdin);
            size_t len = strlen(A[I].nombre);
            if (len > 0 && A[I].nombre[len - 1] == '\n')
                A[I].nombre[len - 1] = '\0';
            printf("\tPrecio: ");
            scanf("%f", &A[I].precio);
            printf("\tCantidad: ");
            scanf("%d", &A[I].existencia);
            (*T)++;
        }
        printf("\nIngrese otra clave de producto -0 para salir-: ");
        scanf("%d", &CLA);
    }
    if (*T == 100)
        printf("\nYa no hay espacio para incorporar nuevos productos\n");
}

void Inventario(producto A[], int T)
{
    int I;
    for (I = 0; I < T; I++) {
        printf("\nClave: %d", A[I].clave);
        printf("\tNombre: %s", A[I].nombre);
        printf("\tPrecio: %.2f", A[I].precio);
        printf("\tExistencia: %d\n", A[I].existencia);
    }
}
