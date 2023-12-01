int DistMin(int a[], int n, int x, int y)
{
    int X[10001], nx, Y[10001], ny, i, j, d;
    nx = ny = 0;
    for (i = 0; i < n; i++)
        if (a[i] == x) X[nx++] = i;
        else if (a[i] == y) Y[ny++] = i;

    int dmin = n + 1;
    i = j = 0;
    while (i < nx && j < ny)
    {
        d = abs(X[i] - Y[j]);
        dmin = min(d, dmin);
        if (X[i] < Y[j]) i++;
        else j++;
    }
    if (i < nx) dmin = min(dmin, X[i] - Y[ny - 1]);
    if (j < ny) dmin = min(dmin, Y[j] - X[nx - 1]);
    return dmin;
}