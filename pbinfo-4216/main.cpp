int EliminaElemente(int a[], int n, int m)
{
    int i, fr[1001] = {0};
    int b[10002], k = 0;
    for (i = 0; i < n; i++)
        fr[a[i]]++;
    for (i = 0; i <= 1000; i++)
        if (fr[i] > 0) b[k++] = fr[i];
    sort(b, b + k);
    for (i = 0; i < k && m >= b[i]; i++)
            m -= b[i];
    return k - i;
}