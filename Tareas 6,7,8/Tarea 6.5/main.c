#include <stdio.h>

void Lectura1(int FAB[15][12]);
void Lectura2(float COS[], int);
void Funcion1(int FAB[][12], int filas, int columnas, float COS[], float VEN[]);
void Funcion2(float VEN[], int n);
void Funcion3(float VEN[], int n);

void main(void)
{
    int FAB[15][12] = {0};
    float COS[15], VEN[15];

    Lectura1(FAB);
    Lectura2(COS, 15);
    Funcion1(FAB, 15, 12, COS, VEN);

    Funcion2(VEN, 15);
    Funcion3(VEN, 15);
}
