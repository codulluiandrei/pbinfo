int CautaPoz(int a[], int n)
{
    int i, p, s, stot, difMin;
    stot = 0;
    for (i = 0; i < n; i++)
        stot += a[i];
    p = s = 0;
    difMin = 2e9;
    for (i = 0; i < n - 1; i++)
    {
        stot -= a[i];
        s += a[i];
        if (difMin > abs(s - stot))
        {
            difMin = abs(s - stot);
            p = i;
        }
    }
    return p;
}