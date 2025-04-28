/*
    Complexitate O(n x p x p + n log n)
*/
#include <algorithm>
#include <cstdio>
#define Nmax 50005
#define inFile "aperm.in"
#define outFile "aperm.out"
using namespace std;
struct permut
{
    long long val;
    int ind;
};
long long f[20];
permut a[Nmax];
int n, p, t[20];
void Factoriale()
{
    int i;
    f[0] = f[1] = 1;
    for (i = 2; i <= 16; ++i)
        f[i] = f[i - 1] * i;
}
long long Ordine(int t[])
{
    int i, j;
    long long x;
    x = 1;
    for (i = 1; i <= p; ++i)
    {
        x = x + (t[i] - 1) * f[p - i];
        for (j = i + 1; j <= p; ++j)
            if (t[j] > t[i]) t[j]--;
    }
    return x;
}
void Citire()
{
    int i, j;
    freopen(inFile, "r", stdin);
    scanf("%d %d", &n, &p);
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= p; ++j)
            scanf("%d", t + j);
        a[i].val = Ordine(t);
        a[i].ind = i;
    }
}
inline bool cmp (const permut A, const permut B )
{
    if (A.val == B.val)
        return A.ind < B.ind;
    return A.val < B.val;
}
void Afisare()
{
    int i;
    freopen(outFile, "w", stdout);
    for (i = 1; i <= n; ++i)
        printf("%d\n", a[i].ind);
}
int main()
{
    Factoriale();
    Citire();
    sort(a + 1, a + n + 1, cmp);
    Afisare();
    return 0;
}