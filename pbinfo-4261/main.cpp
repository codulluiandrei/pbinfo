int AlternDivImp(int a[], int st, int dr)
{
    if (st > dr) return 1;
    if (st == dr) return 1;
    int m = (st + dr) / 2;
    return AlternDivImp(a, st, m) && AlternDivImp(a, m + 1, dr)
           && (a[m] % 2 != a[m + 1] % 2);
}