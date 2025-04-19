void Matrix(int a[300][300], int n, int L[], int C[], int k)
{
    int i, j;
    int lin[302] = {0};
    int col[302] = {0};
    for (i = 0; i < k; i++)
        lin[L[i]] = 1 - lin[L[i]];
    for (i = 0; i < k; i++)
        col[C[i]] = 1 - col[C[i]];
    /// operatiile pe linii
    for (i = 0; i < n; i++)
        if (lin[i] == 1) /// aplic operatia pe linia i
            for (j = 0; j < n; j++)
                a[i][j] = 1 - a[i][j];
    /// operatiile pe coloane
    for (i = 0; i < n; i++)
        if (col[i] == 1) /// aplic operatia pe linia i
            for (j = 0; j < n; j++)
                a[j][i] = 1 - a[j][i];
}