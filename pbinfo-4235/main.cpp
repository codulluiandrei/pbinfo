long long PerechiDivP(int a[], int n, int P)
{
    int rest[1000] = {0};
    int r, cr;
    long long cnt = 0;
    for (int i = 0; i < n; i++)
    {
        r = a[i] % P;
        cr = ((r == 0)? (0) : (P - r));
        cnt += rest[cr];
        rest[r]++;
    }
    return cnt;
}