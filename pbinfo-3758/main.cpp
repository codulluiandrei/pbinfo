#include <bits/stdc++.h>
#define inFile "inno.in"
#define outFile "inno.out"
#define nmax 200003
using namespace std;

int a[nmax], st[nmax], dr[nmax], n, k;
long long nrSecv;

int NrBiti_1(int n)
{
    int s = 0;
    while (n > 0)
    {
        n = (n & (n - 1));
        s++;
    }
    return s;
}

void Citire()
{
    ifstream fin(inFile);
    fin >> n >> k;
    for (int i = 1; i <= n; i++)
        fin >> a[i];
}

void Rezolvare()
{
    int i, j, x, y, stop;
    ofstream fout(outFile);
    x = 0;
    st[0] = (1 << 30) - 1;
    stop = 0;
    for (i = 1; i <= n && !stop; i++)
    {
        st[i] = st[i - 1] & a[i];
        if (NrBiti_1(st[i]) >= k) x = i;
        else stop = 1;
    }
    if (x == n)
    {
        nrSecv = 1LL * n * (n + 1) / 2 - 1;
        fout << nrSecv << "\n";
        fout.close();
        return;
    }
    y = n + 1;
    dr[n + 1] = (1 << 30) - 1;
    stop = 0;
    for (i = n; i >= 1; i--)
    {
        dr[i] = dr[i + 1] & a[i];
        if (NrBiti_1(dr[i]) >= k) y = i;
        else stop = 1;
    }

    if (x == 0 && y == n + 1) /// nu sunt solutii
    {
        fout << "0\n";
        fout.close();
        return;
    }
    if (y == n + 1)
    {
        fout << x << "\n";
        fout.close();
        return;
    }
    if (x == 0)
    {
        fout << (n - y + 1) << "\n";
        fout.close();
        return;
    }

    j = y;
    nrSecv = (n - y + 1);
    for (i = 1; i <= x && j <= n; i++)
    {
        while (j <= n && NrBiti_1(st[i] & dr[j]) < k)
            j++;
        nrSecv += (n - j + 2);
    }
    fout << nrSecv << "\n";
    fout.close();
}

int main()
{
    Citire();
    Rezolvare();
    return 0;
}
