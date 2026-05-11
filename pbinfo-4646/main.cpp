#include <bits/stdc++.h>
using namespace std;
ifstream  fin("cb1.in");
ofstream fout("cb1.out");
int a[500003], n;
/// returneaza numarul de elemente din sir <= x
int CautBin1(int x)
{
    if (x < a[1]) return 0;
    if (a[n] <= x) return n;
    int st, dr, p, mij;
    st = 1; dr = n; p = 1;
    while (st <= dr)
    {
        mij = (st + dr) / 2;
        if (a[mij] <= x)
        {
            p = mij;
            st = mij + 1;
        }
        else dr = mij - 1;
    }
    return p;
}
/// returneaza numarul de elemente din sir > x
int CautBin2(int x)
{
    if (x < a[1]) return n;
    if (a[n] <= x) return 0;
    int st, dr, p, mij;
    st = 1; dr = n; p = n;
    while (st <= dr)
    {
        mij = (st + dr) / 2;
        if (a[mij] > x)
        {
            p = mij;
            dr = mij - 1;
        }
        else st = mij + 1;
    }
    return n - p + 1;
}
/// returneaza numarul de elemente din sir egale cu x
int CautBin3(int x)
{
    if (x < a[1] || a[n] < x) return 0;
    int st, dr, p, q, mij;
    st = 1; dr = n;
    p = 0;
    while (st <= dr)
    {
        mij = (st + dr) / 2;
        if (a[mij] == x)
        {
            p = mij;
            dr = mij - 1;
        }
        else if (a[mij] < x) st = mij + 1;
        else dr = mij - 1;
    }
    if (p == 0) return 0;
    q = 0;
    st = 1; dr = n;
    while (st <= dr)
    {
        mij = (st + dr) / 2;
        if (a[mij] == x)
        {
            q = mij;
            st = mij + 1;
        }
        else if (a[mij] < x) st = mij + 1;
        else dr = mij - 1;
    }
    return q - p + 1;
}
int main()
{
    int i, Q, x, op;
    fin >> n;
    for (i = 1; i <= n; i++)
        fin >> a[i];
    fin >> Q;
    for (i = 1; i <= Q; i++)
    {
        fin >> op >> x;
        if (op == 1) fout << CautBin1(x) << "\n";
        else if (op == 2) fout << CautBin2(x) << "\n";
        else fout << CautBin3(x) << "\n";
    }
    return 0;
}