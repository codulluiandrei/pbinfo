#include <bits/stdc++.h>
#define MOD 9973
using namespace std;
int n, P, nrsol;
int a[10], k;   /// retin cifrele divizibile cu P
int e[10];      /// retin exponentii pentru a[i]
int fact[9001]; /// fact[i] = i! % MOD
int st[10];     /// stiva pentru back
void Citire()
{
    ifstream fin("numere19.in");
    fin >> n >> P;
    fin.close();
}
void Constructie()
{
    int i, x;
    for(i = 2; i <= 9; i++)
        if(P % i == 0)
        {
            a[++k] = i;
            x = P;
            while(x % i == 0)
            {
                e[k]++;
                x /= i;
            }
        }
}
void Factorial()
{
    int i;
    fact[1] = 1;
    for(i = 2; i <= 9000; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
}
int LogPut(int x, int n)
{
    int s = 1;
    while(n > 0)
    {
        if(n % 2 == 1)
        {
            s = (s * x) % MOD;
            n--;
        }
        n /= 2;
        x = (x * x) % MOD;
    }
    return s;
}
int Valid(int top,int x)
{
    int prod, i, j;
    prod = 1;
    for (i = 1; i < top; i++)
        if (st[i] != 0)
          for (j = 1; j <= st[i]; j++)
            prod *= a[i];
    for (i = 1; i <= x; i++)
        prod *= a[top];
    if (prod > P) return 0;
    if (top == k && prod != P) return 0;
    return 1;
}
void Solutie()
{
    int i, s ,t[10], m, cnt, x;
    s = 0;
    for(i = 1; i <= k; i++)
        s += st[i];
    if (s > n) return;
    m = 0;
    for(i = 1; i <= k; i++)
        if(st[i] > 1)
            t[++m]=st[i];
    if(n - s > 1)
        t[++m] = n - s;
    cnt = fact[n];
    for(i = 1; i <= m; i++)
    {
        x = LogPut(fact[t[i]], MOD - 2);
        cnt = (cnt * x) % MOD;
    }
    nrsol += cnt;
}
void Back(int top)
{
    int i;
    if(top == k + 1) Solutie();
    else
    {
        for(i = 0; i <= e[top]; i++)
            if(Valid(top, i))
            {
                st[top] = i;
                Back(top + 1);
            }
    }
}
void Afisare()
{
    ofstream fout("numere19.out");
    nrsol = nrsol % MOD;
    fout << nrsol << "\n";
    fout.close();
}
int main()
{
    Citire();
    Factorial();
    Constructie();
    Back(1);
    Afisare();
    return 0;
}