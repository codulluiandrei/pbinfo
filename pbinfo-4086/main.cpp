/**
Implementare Dan Pracsiu - 100p
*/
#include <bits/stdc++.h>
using namespace std;
ifstream  fin("cmmdc.in");
ofstream fout("cmmdc.out");
long long a[100002], st[100002], dr[100002];
int n;
int main()
{
    int i, j, T;
    long long c, d, M;
    /// citire
    fin >> T >> n;
    for (i = 1; i <= n; i++)
        fin >> a[i];
    /// cmmdc partial de la stanga la dreapta
    st[1] = a[1];
    for (i = 2; i <= n; i++)
        st[i] = __gcd(st[i - 1], a[i]);
    /// cmmdc partial de la dreapta la stanga
    dr[n] = a[n];
    for (i = n - 1; i >= 1; i--)
        dr[i] = __gcd(a[i], dr[i + 1]);
    if (T == 1) /// rezolvare a)
    {
        fout << st[n];
    }
    else if (T == 2) /// rezolvare b)
    {
        M = 0;
        for (i = 1; i <= n; i++)
        {
            d = __gcd(st[i - 1], dr[i + 1]);
            M = max(M, d);
        }
        fout << M;
    }
    else /// /// rezolvare c)
    {
        /// aflam cmmdc-ul maxim obtinut prin eliminarea lui a[i] si a[j]
        M = 0;
        for (i = 1; i < n; i++)
        {
            c = 0; /// c = cmmdc(a[i+1..j])
            for (j = i + 1; j <= n; j++)
            {
                d = __gcd(st[i - 1], c);
                d = __gcd(d, dr[j + 1]);
                M = max(M, d);
                c = __gcd(c, a[j]);
            }
        }
        fout << M;
    }
	fin.close();
	fout.close();
    return 0;
}