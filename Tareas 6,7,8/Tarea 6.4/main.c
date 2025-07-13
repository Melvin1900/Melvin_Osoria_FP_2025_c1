void Intercambia(float A[][MAX], int F, int C)
{
    int I, J;
    float AUX;
    for (I = 0; I < (C / 2); I++)
        for (J = 0; J < F; J++)
        {
            AUX = A[J][I];
            A[J][I] = A[J][C - I - 1];
            A[J][C - I - 1] = AUX;
        }
}

void Imprime(float A[][MAX], int F, int C)
{
    int I, J;
    for (I = 0; I < F; I++)
        for (J = 0; J < C; J++)
            printf("\nElemento %d %d: %5.2f", I + 1, J + 1, A[I][J]);
}
