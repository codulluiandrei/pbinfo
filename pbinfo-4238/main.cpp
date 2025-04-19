int NrZero(int a[], int n)
{
    int st, dr, mid, p, q;
    /// cauta cea mai din stanga pozitie p cu a[p] = 0
    p = -1; st = 1; dr = n;
    while (st <= dr)
    {
        mid = (st + dr) / 2;
        if (a[mid] % 2 == 1) st = mid + 1;
        else if (a[mid] > 0) dr = mid - 1;
        else /// a[mid] = 0
        {
            p = mid;
            dr = mid - 1;
        }
    }
    if (p == -1) return 0;
    /// cauta cea mai din dreapta pozitie q cu a[q] = 0
    q = -1; st = 1; dr = n;
    while (st <= dr)
    {
        mid = (st + dr) / 2;
        if (a[mid] % 2 == 1) st = mid + 1;
        else if (a[mid] > 0) dr = mid - 1;
        else /// a[mid] = 0
        {
            q = mid;
            st = mid + 1;
        }
    }
    return q - p + 1;
}