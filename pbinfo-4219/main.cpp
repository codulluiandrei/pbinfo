int Egalitate(int a[], int n)
{
    int i, fr[1001] = {0}, nrMin;
    int b[1001], k;
    for (i = 0; i < n; i++)
        fr[a[i]]++;
    k = 0;
    for (i = 0; i < 1001; i++)
        if (fr[i] > 0) b[k++] = fr[i];
    sort(b, b + k);
    nrMin = n - b[0] * k;
    for (i = 1; i < k; i++)
        nrMin = min(nrMin, n - b[i] * (k - i));
    return nrMin;
}