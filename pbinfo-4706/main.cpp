void Peak(int a[], int n, int &isPeak, int &poz)
{
    isPeak = poz = 0;
    if (a[1] >= a[2]) return;
    if (a[n - 1] <= a[n]) return;
    int i = 1;
    while (a[i] < a[i + 1]) i++;
    poz = i;
    while (i < n && a[i] > a[i + 1]) i++;
    if (i < n) poz = 0;
    else isPeak = 1;
}