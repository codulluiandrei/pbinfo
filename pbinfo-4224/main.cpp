int MaxMinDif1(int a[], int n)
{
    if (n <= 1) return n;
    int i, j, lgMax = 0;
    sort(a, a + n);
    j = 0;
    for (i = 0; i < n; i++)
    {
        while (a[i] - a[j] > 1)
            j++;
        lgMax = max(lgMax, i - j + 1);
    }
    return lgMax;
}