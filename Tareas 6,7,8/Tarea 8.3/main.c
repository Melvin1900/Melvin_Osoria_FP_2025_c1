#include <stdio.h>
#include <string.h>

typedef struct {
    char cal[20];
    int num;
    char col[20];
    char cp[5];
    char ciu[20];
} domicilio;

typedef struct {
    char nom[20];
    int edad;
    char sexo;
    int con;
    domicilio dom;
    char tel[10];
} paciente;

void Lectura(paciente *, int);
void F1(paciente *, int);
void F2(paciente *, int);
void F3(paciente *, int);

int main(void) {
    paciente HOSPITAL[100];
    int TAM, i;

    do {
        printf("Ingrese el número de pacientes: ");
        scanf("%d", &TAM);
    } while (TAM > 50 || TAM < 1);

    fflush(stdin);
    Lectura(HOSPITAL, TAM);
    F1(HOSPITAL, TAM);
    F2(HOSPITAL, TAM);
    F3(HOSPITAL, TAM);

    return 0;
}

void Lectura(paciente A[], int T) {
    int I;
    for (I = 0; I < T; I++) {
        printf("\nPaciente %d\n", I + 1);
        fflush(stdin);
        printf("Nombre: ");
        fgets(A[I].nom, 20, stdin);
        size_t len = strlen(A[I].nom);
        if (len > 0 && A[I].nom[len - 1] == '\n') A[I].nom[len - 1] = '\0';

        printf("Edad: ");
        scanf("%d", &A[I].edad);

        printf("Sexo (F-M): ");
        fflush(stdin);
        scanf("%c", &A[I].sexo);

        printf("Condición (1..5): ");
        scanf("%d", &A[I].con);

        fflush(stdin);
        printf("Calle: ");
        fgets(A[I].dom.cal, 20, stdin);
        len = strlen(A[I].dom.cal);
        if (len > 0 && A[I].dom.cal[len - 1] == '\n') A[I].dom.cal[len - 1] = '\0';

        printf("Número: ");
        scanf("%d", &A[I].dom.num);

        fflush(stdin);
        printf("Colonia: ");
        fgets(A[I].dom.col, 20, stdin);
        len = strlen(A[I].dom.col);
        if (len > 0 && A[I].dom.col[len - 1] == '\n') A[I].dom.col[len - 1] = '\0';

        printf("Código Postal: ");
        fgets(A[I].dom.cp, 5, stdin);
        len = strlen(A[I].dom.cp);
        if (len > 0 && A[I].dom.cp[len - 1] == '\n') A[I].dom.cp[len - 1] = '\0';

        printf("Ciudad: ");
        fgets(A[I].dom.ciu, 20, stdin);
        len = strlen(A[I].dom.ciu);
        if (len > 0 && A[I].dom.ciu[len - 1] == '\n') A[I].dom.ciu[len - 1] = '\0';

        printf("Teléfono: ");
        fgets(A[I].tel, 10, stdin);
        len = strlen(A[I].tel);
        if (len > 0 && A[I].tel[len - 1] == '\n') A[I].tel[len - 1] = '\0';
    }
}

void F1(paciente A[], int T) {
    int I, FEM = 0, MAS = 0;
    for (I = 0; I < T; I++) {
        switch (A[I].sexo) {
            case 'F': case 'f': FEM++; break;
            case 'M': case 'm': MAS++; break;
        }
    }
    int TOT = FEM + MAS;
    if (TOT > 0) {
        printf("\nPorcentaje de Hombres: %.2f%%", (float)MAS / TOT * 100);
        printf("\nPorcentaje de Mujeres: %.2f%%", (float)FEM / TOT * 100);
    } else {
        printf("\nNo hay pacientes registrados.");
    }
}

void F2(paciente A[], int T) {
    int I, C1 = 0, C2 = 0, C3 = 0, C4 = 0, C5 = 0;
    for (I = 0; I < T; I++) {
        switch (A[I].con) {
            case 1: C1++; break;
            case 2: C2++; break;
            case 3: C3++; break;
            case 4: C4++; break;
            case 5: C5++; break;
        }
    }
    printf("\nNúmero pacientes en condición 1: %d", C1);
    printf("\nNúmero pacientes en condición 2: %d", C2);
    printf("\nNúmero pacientes en condición 3: %d", C3);
    printf("\nNúmero pacientes en condición 4: %d", C4);
    printf("\nNúmero pacientes en condición 5: %d", C5);
}

void F3(paciente A[], int T) {
    int I;
    printf("\nPacientes ingresados en estado de gravedad:");
    for (I = 0; I < T; I++) {
        if (A[I].con == 5) {
            printf("\nNombre: %s\tTeléfono: %s", A[I].nom, A[I].tel);
        }
    }
}
