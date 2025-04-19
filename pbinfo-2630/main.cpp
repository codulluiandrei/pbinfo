int PermD(int a[], int n)
{
    int i, j;
    i = n;
    while (a[i] != 0)
    {
        j = a[i];
        a[i] = 0;
        i = j;
    }
    return i;
}