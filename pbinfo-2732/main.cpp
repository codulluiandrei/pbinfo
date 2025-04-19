void Succesor(int a[], int n, int k)
{
    int M, i;
    M = n;
    for (i = k; a[i] == M; i--)
        M--;
    a[i]++;
    for ( ; i < k; i++)
        a[i + 1] = a[i] + 1;
}