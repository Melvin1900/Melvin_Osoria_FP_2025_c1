#include <stdio.h>
#include <string.h>

typedef struct {
    char noba[10];
    char nucu[10];
} banco;

typedef union {
    banco che;
    banco nomi;
    char venta;
} fpago;

typedef struct {
    char cnu[20];
    char col[20];
    char cp[5];
    char ciu[15];
} domicilio;

typedef struct {
    int num;
    char nom[20];
    float ven[12];
    domicilio domi;
    float sal;
    fpago pago;
    int cla;
} vendedor;

void Lectura(vendedor *, int);
void F1(vendedor *, int);
void F2(vendedor *, int);
void F3(vendedor *, int);
void F4(vendedor *, int);

int main(void) {
    vendedor VENDEDORES[100];
    int TAM;

    do {
        printf("Ingrese el número de vendedores: ");
        scanf("%d", &TAM);
    } while (TAM > 100 || TAM < 1);

    fflush(stdin);
    Lectura(VENDEDORES, TAM);
    F1(VENDEDORES, TAM);
    F2(VENDEDORES, TAM);
    F3(VENDEDORES, TAM);
    F4(VENDEDORES, TAM);

    printf("\n\tFIN DEL PROGRAMA\n");
    return 0;
}

void Lectura(vendedor A[], int T) {
    int I, J;
    for (I = 0; I < T; I++) {
        printf("\nIngrese datos del vendedor %d\n", I + 1);
        printf("Número de vendedor: ");
        scanf("%d", &A[I].num);
        fflush(stdin);
        printf("Nombre del vendedor: ");
        fgets(A[I].nom, 20, stdin);
        size_t len = strlen(A[I].nom);
        if (len > 0 && A[I].nom[len - 1] == '\n') A[I].nom[len - 1] = '\0';

        printf("Ventas del año:\n");
        for (J = 0; J < 12; J++) {
            printf("\tMes %d: ", J + 1);
            scanf("%f", &A[I].ven[J]);
        }
        fflush(stdin);

        printf("Domicilio del vendedor:\n");
        printf("\tCalle y número: ");
        fgets(A[I].domi.cnu, 20, stdin);
        len = strlen(A[I].domi.cnu);
        if (len > 0 && A[I].domi.cnu[len - 1] == '\n') A[I].domi.cnu[len - 1] = '\0';

        printf("\tColonia: ");
        fgets(A[I].domi.col, 20, stdin);
        len = strlen(A[I].domi.col);
        if (len > 0 && A[I].domi.col[len - 1] == '\n') A[I].domi.col[len - 1] = '\0';

        printf("\tCódigo Postal: ");
        fgets(A[I].domi.cp, 5, stdin);
        len = strlen(A[I].domi.cp);
        if (len > 0 && A[I].domi.cp[len - 1] == '\n') A[I].domi.cp[len - 1] = '\0';

        printf("\tCiudad: ");
        fgets(A[I].domi.ciu, 15, stdin);
        len = strlen(A[I].domi.ciu);
        if (len > 0 && A[I].domi.ciu[len - 1] == '\n') A[I].domi.ciu[len - 1] = '\0';

        printf("Salario del vendedor: ");
        scanf("%f", &A[I].sal);

        printf("Forma de Pago (Banco-1 Nómina-2 Ventanilla-3): ");
        scanf("%d", &A[I].cla);
        fflush(stdin);

        switch (A[I].cla) {
            case 1:
                printf("\tNombre del banco: ");
                fgets(A[I].pago.che.noba, 10, stdin);
                len = strlen(A[I].pago.che.noba);
                if (len > 0 && A[I].pago.che.noba[len - 1] == '\n') A[I].pago.che.noba[len - 1] = '\0';

                printf("\tNúmero de cuenta: ");
                fgets(A[I].pago.che.nucu, 10, stdin);
                len = strlen(A[I].pago.che.nucu);
                if (len > 0 && A[I].pago.che.nucu[len - 1] == '\n') A[I].pago.che.nucu[len - 1] = '\0';
                break;
            case 2:
                printf("\tNombre del banco: ");
                fgets(A[I].pago.nomi.noba, 10, stdin);
                len = strlen(A[I].pago.nomi.noba);
                if (len > 0 && A[I].pago.nomi.noba[len - 1] == '\n') A[I].pago.nomi.noba[len - 1] = '\0';

                printf("\tNúmero de cuenta: ");
                fgets(A[I].pago.nomi.nucu, 10, stdin);
                len = strlen(A[I].pago.nomi.nucu);
                if (len > 0 && A[I].pago.nomi.nucu[len - 1] == '\n') A[I].pago.nomi.nucu[len - 1] = '\0';
                break;
            case 3:
                A[I].pago.venta = 'S';
                b
