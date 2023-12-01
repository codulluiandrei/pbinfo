int MatDiag(int a[100][100], int n)
{
    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
            if (a[i][j] != a[i - 1][j - 1]) return 0;
    return 1;
}