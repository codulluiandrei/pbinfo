int NrXDivImp(int a[], int st, int dr, int x)
{
    if (st > dr) return 0;
    if (st == dr) return (a[st] == x);
    int m = (st + dr) / 2;
    return NrXDivImp(a, st, m, x) + NrXDivImp(a, m + 1, dr, x);
}