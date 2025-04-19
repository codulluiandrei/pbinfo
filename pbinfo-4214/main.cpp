int DouaNumere(int A[], int n)
{
    int a[100], b[100];
    int s, k, i, x;
    for (i = 0; i < 100; i++)
        a[i] = b[i] = -1;
    for (i = 0; i < n; i++)
    {
        k = x = A[i];
        s = 0;
        while (x > 0)
        {
            s += x % 10;
            x /= 10;
        }
        if (a[s] == -1) a[s] = k;
        else
        {
            if (b[s] < k) b[s] = k;
            if (a[s] < b[s]) swap(a[s], b[s]);
        }
    }
    k = -1;
    for (i = 0; i < 100; i++)
        if (b[i] >= 0 && k < a[i] + b[i])
            k = a[i] + b[i];
    return k;
}