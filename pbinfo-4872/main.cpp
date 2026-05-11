#include <bits/stdc++.h>
using namespace std;
ifstream  fin("siruribinare.in");
ofstream fout("siruribinare.out");
int a[100003], b[100003], n;
int c[200010];
int main()
{
    int i, x, *poz, X = 0, Y = 0;
    fin >> n;
    for (i = 1; i <= n; i++)
        fin >> a[i];
    for (i = 1; i <= n; i++)
        fin >> b[i];
    for (i = 1; i <= n; i++)
        a[i] -= b[i];
    /// sume partiale
    poz = c + 100004;
    for (i = -100000; i <= 100000; i++)
        poz[i] = -1;
    x = 0;
    poz[x] = 0;
    for (i = 1; i <= n; i++)
    {
        x += a[i];
        if (poz[x] >= 0)
        {
            if ((Y - X < i - poz[x]) || (Y - X == i - poz[x] && X > poz[x]))
            {
                Y = i;
                X = poz[x];
            }
        }
        else poz[x] = i;
    }
    if (Y != 0) X++;
    fout << X << " " << Y << "\n";
    return 0;
}