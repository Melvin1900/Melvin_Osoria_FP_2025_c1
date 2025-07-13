#include <stdio.h>
#include <string.h>

typedef struct {
    char mat[20];
    int pro;
} matpro;

typedef struct {
    int matri;
    char nom[20];
    matpro cal[5];
} alumno;

void Lectura(alumno *, int);
void F1(alumno *, int);
void F2(alumno *, int);
void F3(alumno *, int);

int main(void)
{
    alumno ALU[50];
    int TAM;

    do {
        printf("Ingrese el tama�o del arreglo: ");
        scanf("%d", &TAM);
    } while (TAM > 50 || TAM < 1);

    Lectura(ALU, TAM);
    F1(ALU, TAM);
    F2(ALU, TAM);
    F3(ALU, TAM);

    return 0;
}

void Lectura(alumno A[], int T)
{
    int I, J;
    for (I = 0; I < T; I++) {
        printf("\nIngrese los datos del alumno %d\n", I + 1);
        printf("Ingrese la matr�cula del alumno: ");
        scanf("%d", &A[I].matri);
        fflush(stdin);
        printf("Ingrese el nombre del alumno: ");
        fgets(A[I].nom, 20, stdin);
        size_t len = strlen(A[I].nom);
        if (len > 0 && A[I].nom[len - 1] == '\n') A[I].nom[len - 1] = '\0';

        for (J = 0; J < 5; J++) {
            printf("\tMateria %d: ", J + 1);
            fflush(stdin);
            fgets(A[I].cal[J].mat, 20, stdin);
            len = strlen(A[I].cal[J].mat);
            if (len > 0 && A[I].cal[J].mat[len - 1] == '\n') A[I].cal[J].mat[len - 1] = '\0';
            printf("\tPromedio %d: ", J + 1);
            scanf("%d", &A[I].cal[J].pro);
        }
    }
}

void F1(alumno A[], int T)
{
    int I, J;
    float SUM;
    for (I = 0; I < T; I++) {
        printf("\nMatr�cula del alumno: %d", A[I].matri);
        SUM = 0.0;
        for (J = 0; J < 5; J++)
            SUM += A[I].cal[J].pro;
        SUM /= 5;
        printf("\tPromedio: %.2f", SUM);
    }
}

void F2(alumno A[], int T)
{
    int I;
    printf("\nAlumnos con calificaci�n mayor a 9 en la tercera materia:");
    for (I = 0; I < T; I++) {
        if (A[I].cal[2].pro > 9)
            printf("\nMatr�cula del alumno: %d", A[I].matri);
    }
}

void F3(alumno A[], int T)
{
    int I;
    float SUM = 0.0;
    for (I = 0; I < T; I++)
        SUM += A[I].cal[3].pro;
    SUM /= T;
    printf("\n\nPromedio de la cuarta materia: %.2f\n", SUM);
}
