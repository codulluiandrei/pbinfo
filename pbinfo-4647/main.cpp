#include <bits/stdc++.h>
using namespace std;
ifstream  fin("esm.in");
ofstream fout("esm.out");
int a[100003], n, P;
int poz1[100003], poz2[100003];
void Citire()
{
    fin >> P >> n;
    for (int i = 1; i <= n; i++)
        fin >> a[i];
}
void Cerinta1()
{
    int i, cnt = 0;
    for (i = 3; i <= n; i++)
        if (1LL * a[i - 2] * a[i - 1] == a[i]) cnt++;
    fout << cnt << "\n";
}
void Cerinta2()
{
    int i, x, p;
    for (i = 1; i < n; i++)
    {
        x = a[i];
        if (poz1[x] == 0) poz1[x] = i;
        else
        {
            poz2[x] = poz1[x];
            poz1[x] = i;
        }
    }
    x = a[n]; p = 0;
    for (i = 1; i * i < x; i++)
        if (x % i == 0)
        {
            if (poz1[i] > 0 && poz1[x / i] > 0)
                p = max(p, min(poz1[i], poz1[x / i]));
        }
    if (i * i == x)
    {
        if (poz1[i] > 0 && poz2[i] > 0)
            p = max(p, poz2[i]);
    }
    fout << p << "\n";
}
void Cerinta3()
{
    int i, j, p, x;
    long long cnt = 0;
    poz1[a[2]] = 2;
    if (a[1] == a[2]) poz2[a[1]] = 1;
    else poz1[a[1]] = 1;
    for (j = 3; j <= n; j++)
    {
        x = a[j];
        p = 0;
        for (i = 1; i * i < x; i++)
            if (x % i == 0)
            {
                if (poz1[i] > 0 && poz1[x / i] > 0)
                    p = max(p, min(poz1[i], poz1[x / i]));
            }
        if (i * i == x)
        {
            if (poz1[i] > 0 && poz2[i] > 0)
                p = max(p, poz2[i]);
        }
        cnt += p;
        /// pun pe x=a[j] in vectorii de frecventa
        if (poz1[x] == 0) poz1[x] = j;
        else
        {
            poz2[x] = poz1[x];
            poz1[x] = j;
        }
    }
    fout << cnt << "\n";
}
int main()
{
    Citire();
    if (P == 1) Cerinta1();
    else if (P == 2) Cerinta2();
    else Cerinta3();
    return 0;
}