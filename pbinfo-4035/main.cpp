long long NrSecvS(int a[], int n, int S)
{
    int i, j, suma = 0;
    long long nr = 0;
    j = 1;
    for (i = 1; i <= n; i++)
    {
        suma += a[i];
        while (suma > S)
        {
            nr += (n - i + 1);
            suma -= a[j];
            j++;
        }
    }
    return nr;
}