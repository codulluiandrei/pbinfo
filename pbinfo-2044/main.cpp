#include <bits/stdc++.h>
#define nmax 1005
#define inFile "cursuri.in"
#define outFile "cursuri.out"
using namespace std;
struct Interval
{
    int a, b;
};
Interval t[nmax];
/// dmax[i] = timpul final al ultimului interval
///           pus in sala i, i=1..K
int d[nmax];
int n, K, op, M;
void Citire()
{
    int i;
    ifstream fin(inFile);
    fin >> op;
    fin >> n >> K;
    for (i = 1; i <= n; i++)
    {
        fin >> t[i].a >> t[i].b;
        M = max(M, t[i].b - t[i].a);
    }
    fin.close();
}
inline bool Cmp(const Interval X, const Interval Y)
{
    if (X.b == Y.b) return X.a < Y.a;
    return X.b < Y.b;
}
void Optiune1()
{
    int i, j, p, ans, D;
    sort(t + 1, t + n + 1, Cmp);
    ans = 0;
    for (i = 1; i <= n; i++)
    {
        /// caut d[p] maxim, p=1..K
        /// cat mai aproape de capatul stang al intervalului i
        p = 0; D = -1;
        for (j = 1; j <= K; j++)
            if (d[j] <= t[i].a && d[j] > D)
            {
                p = j;
                D = d[j];
            }
        if (p != 0)
        {
            d[p] = t[i].b;
            ans++;
        }
    }
    ofstream fout(outFile);
    fout << ans << "\n";
    fout.close();
}
/// returneaza 1 daca toate intervalele (de lungime L)
/// se incadreaza in K clase
int Verifica(int L)
{
    int i, j, p;
    for (i = 1; i <= n; i++)
        t[i].b = t[i].a + L;
    for (i = 1; i <= K; i++)
        d[i] = 0;
    sort(t + 1, t + n + 1, Cmp);
    for (i = 1; i <= n; i++)
    {
        /// caut d[p] minim, p=1..K
        p = 1;
        for (j = 2; j <= K; j++)
            if (d[p] > d[j]) p = j;
        if (d[p] <= t[i].a)
            d[p] = t[i].b;
        else return 0;
    }
    return 1;
}
void Optiune2()
{
    int st, dr, L, sol;
    st = 1; dr = M; sol = 0;
    while (st <= dr)
    {
        L = (st + dr) / 2;
        if (Verifica(L))
        {
            sol = L;
            st = L + 1;
        }
        else dr = L - 1;
    }
    ofstream fout(outFile);
    fout << sol << "\n";
    fout.close();
}
int main()
{
    Citire();
    if (op == 1) Optiune1();
        else Optiune2();
    return 0;
}