#include <bits/stdc++.h>
using namespace std;
int ap[31], i, j, n, k, x, a, b, m, S, nra, nrb;
ifstream f("2lap.in");
ofstream g("2lap.out");
int main()
{
    f >> n >> m;
    while (f >> x)
    {
        k = 0;
        while (x != 1)
        {
            k++;
            x /= 2;
        }
        ap[k]++; //pastrez intr-un vector de aparitii câte numere apar la puterea k, a lui 2
    }
    k=0;
    for (i = 0; i <= 30; i++)
    {
        x = ap[i];
        while(x)
        {
            x--;
            k++;
            if (n == k)
            {
                a = i;
                nra = x; //câte valori egale cu elementul de pe poziția N sunt între pozițíile N și M
            }
            if (m == k)
            {
                b = i;
                nrb = ap[i]-x-1;//câte valori egale cu elementul de pe poziția M sunt între pozițíile N și M
            }
        }
    }
    g << (1 << a) << ' ' << (1 << b) << '\n';
    S = nra*a  + nrb*b;
    //g << nra << ' ' << nrb << '\n';
    for (i = a + 1; i <= b - 1; i++)
        if (ap[i]) S += ap[i]*i;
    if (a==b) S = (m - n - 1)*a;
    g << S << '\n';
    if (nra==0) a++;
    if (nrb==0) b--;
    for (i = a; i <= b; i++)
        if (ap[i] != 0) g << (1 << i) << ' ';//pentru reconstrucția numărului de pe poziția i, folosesc operatorul de deplasare stânga
    return 0;
}