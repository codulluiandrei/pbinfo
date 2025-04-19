/// Complexitate O(n log n)
void f_expo(int a[], int n)
{
    int x, e;
    for (int i = 0; i < n; i++)
    {
        x = a[i];
        for (e = 0; (1 << e) <= x; e++)
            ;
        a[i] = e - 1;
    }
}