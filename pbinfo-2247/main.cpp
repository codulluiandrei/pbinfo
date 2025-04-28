#include <bits/stdc++.h>
using namespace std;
int t[] = {0, 3,5,7,11,13,17,19,23};
int c[] = {0,15,7,6, 4, 2, 2, 2, 2};
int st[12], n, nrdiv, x;
long long nrImpar;
int d[12];
void Citire()
{
    cin >> x;
}
void NrDivizori()
{
    int i;
    nrdiv = 0;
    for (i = 1; i * i < x; ++i)
        if (x % i == 0) nrdiv += 2;
    if (i * i == x) nrdiv++;
}
inline bool Valid(int top)
{
    d[top] = d[top - 1] * (1 + st[top]);
    if (d[top] <= nrdiv) return true;
    return false;
}
inline int Putt(int a, int k)
{
    int i, x = 1;
    for (i = 1; i <= k; ++i)
        x *= a;
    return x;
}
inline void UpdateSol(int top)
{
    int i;
    long long w = 1;
    for (i = 1; i <= top; ++i)
        w *= Putt(t[i], st[i]);
    nrImpar = min(nrImpar, w);
}
inline void Back()
{
    bool cand;
    int top;
    d[0] = 1;
    top = 1;
    st[top] = 0;
    while (top > 0)
    {
        cand = false;
        while (!cand && st[top] < c[top])
        {
            st[top]++;
            cand = Valid(top);
        }
        if (!cand) top--;
        else if (d[top] == nrdiv) UpdateSol(top);
        else if (top < 8) st[++top] = 0;
    }
}
int main()
{
    nrImpar = 2000000000;
    Citire();
    NrDivizori();
    Back();
    cout << nrImpar << "\n";
    return 0;
}