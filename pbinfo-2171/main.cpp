#include <bits/stdc++.h>
using namespace std;
int n, k, D, st[30], a[30], S;
ofstream fout("pluricex1.out");
void Citire()
{
    int i, j, p, x;
    ifstream fin("pluricex1.in");
    fin >> n >> k >> D;
    for (i = 1; i <= n; i++)
    {
        fin >> p;
        a[i] = 1;
        for (j = 1; j <= p; j++)
        {
            fin >> x;
            a[i] |= (1 << x);
        }
    }
    fin.close();
    S = (1 << (D+1)) - 1;
}
void Afisare()
{
    int i, rez;
    rez = 0;
    for (i = 1; i <= k; i++)
        rez |= a[st[i]];
    if (rez != S) return;
    for (i = 1; i <= k; i++)
        fout << st[i] << " ";
    fout << "\n";
}
void Gen(int top)
{
    int i;
    if (top == k + 1) Afisare();
    else for (i = st[top-1]+1; i <= n; i++)
    {
        st[top] = i;
        Gen(top + 1);
    }
}
int main()
{
    Citire();
    Gen(1);
    fout.close();
    return 0;
}