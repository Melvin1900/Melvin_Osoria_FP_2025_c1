#include <stdio.h>
#include <string.h>

typedef struct {
    char zona[20];
    char calle[20];
    char colo[20];
} ubicacion;

typedef struct {
    char clave[5];
    float scu;
    float ste;
    char car[50];
    ubicacion ubi;
    float precio;
    char dispo;
} propiedades;

void Lectura(propiedades A[], int T);
void F1(propiedades A[], int T);
void F2(propiedades A[], int T);

int main(void) {
    propiedades PROPIE[100];
    int TAM;

    do {
        printf("Ingrese el número de propiedades: ");
        scanf("%d", &TAM);
    } while (TAM > 100 || TAM < 1);

    fflush(stdin);
    Lectura(PROPIE, TAM);
    F1(PROPIE, TAM);
    F2(PROPIE, TAM);

    return 0;
}

void Lectura(propiedades A[], int T) {
    int I;
    for (I = 0; I < T; I++) {
        printf("\nIngrese datos de la propiedad %d\n", I + 1);

        printf("Clave: ");
        fflush(stdin);
        fgets(A[I].clave, 5, stdin);
        size_t len = strlen(A[I].clave);
        if (len > 0 && A[I].clave[len - 1] == '\n') A[I].clave[len - 1] = '\0';

        printf("Superficie cubierta: ");
        scanf("%f", &A[I].scu);
        printf("Superficie terreno: ");
        scanf("%f", &A[I].ste);

        fflush(stdin);
        printf("Características: ");
        fgets(A[I].car, 50, stdin);
        len = strlen(A[I].car);
        if (len > 0 && A[I].car[len - 1] == '\n') A[I].car[len - 1] = '\0';

        printf("Zona: ");
        fgets(A[I].ubi.zona, 20, stdin);
        len = strlen(A[I].ubi.zona);
        if (len > 0 && A[I].ubi.zona[len - 1] == '\n') A[I].ubi.zona[len - 1] = '\0';

        printf("Calle: ");
        fgets(A[I].ubi.calle, 20, stdin);
        len = strlen(A[I].ubi.calle);
        if (len > 0 && A[I].ubi.calle[len - 1] == '\n') A[I].ubi.calle[len - 1] = '\0';

        printf("Colonia: ");
        fgets(A[I].ubi.colo, 20, stdin);
        len = strlen(A[I].ubi.colo);
        if (len > 0 && A[I].ubi.colo[len - 1] == '\n') A[I].ubi.colo[len - 1] = '\0';

        printf("Precio: ");
        scanf("%f", &A[I].precio);

        fflush(stdin);
        printf("Disponibilidad (Venta-V Renta-R): ");
        scanf("%c", &A[I].dispo);
        fflush(stdin);
    }
}

void F1(propiedades A[], int T) {
    int I;
    printf("\nListado de Propiedades para Venta en Miraflores\n");
    for (I = 0; I < T; I++) {
        if ((A[I].dispo == 'V' || A[I].dispo == 'v') && (strcmp(A[I].ubi.zona, "Miraflores") == 0)) {
            if (A[I].precio >= 450000 && A[I].precio <= 650000) {
                printf("\nClave de la propiedad: %s\n", A[I].clave);
                printf("Superficie cubierta: %.2f\n", A[I].scu);
                printf("Superficie terreno: %.2f\n", A[I].ste);
                printf("Características: %s\n", A[I].car);
                printf("Calle: %s\n", A[I].ubi.calle);
                printf("Colonia: %s\n", A[I].ubi.colo);
                printf("Precio: %.2f\n", A[I].precio);
            }
        }
    }
}

void F2(propiedades A[], int T) {
    int I;
    float li, ls;
    char zon[20];

    printf("\nListado de Propiedades para Renta\n");
    printf("Ingrese zona geográfica: ");
    fflush(stdin);
    fgets(zon, 20, stdin);
    size_t len = strlen(zon);
    if (len > 0 && zon[len - 1] == '\n') zon[len - 1] = '\0';

    printf("Ingrese el límite inferior del precio: ");
    scanf("%f", &li);
    printf("Ingrese el límite superior del precio: ");
    scanf("%f", &ls);

    for (I = 0; I < T; I++) {
        if ((A[I].dispo == 'R' || A[I].dispo == 'r') && (strcmp(A[I].ubi.zona, zon) == 0)) {
            if (A[I].precio >= li && A[I].precio <= ls) {
                printf("\nClave de la propiedad: %s\n", A[I].clave);
                printf("Superficie cubierta: %.2f\n", A[I].scu);
                printf("Superficie terreno: %.2f\n", A[I].ste);
                printf("Características: %s\n", A[I].car);
                printf("Calle: %s\n", A[I].ubi.calle);
                printf("Colonia: %s\n", A[I].ubi.colo);
                printf("Precio: %.2f\n", A[I].precio);
            }
        }
    }
}
