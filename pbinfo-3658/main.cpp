int NrTriplete(int a[], int n, int S)
{
    int cnt = 0, i, j, k;
    sort(a, a + n);
    for (i = 1; i < n - 1; i++)
    {
        j = i - 1;
        for (k = i + 1; k < n && j >= 0; k++)
        {
            while (j >= 0 && a[j] + a[i] + a[k] >= S)
                j--;
            cnt += (j + 1);
        }
    }
    return cnt;
}
