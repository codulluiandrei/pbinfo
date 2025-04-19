int FGreater(int a[], int n, int x)
{
    int M, i;
    // cauta primul numar mai mare decat x
    for (i = 0; i < n && a[i] <= x; i++)
        ;
    // daca nu exista niciun numar mai mare decat x
    if (i >= n) return -1;
    // s-a gasit primul numar > x, cauta in continuare pe cel mai mic, mai mare ca x
    M = a[i];
    for (; i < n; i++)
        if (M > a[i] && a[i] > x)
            M = a[i];
    return M;
}