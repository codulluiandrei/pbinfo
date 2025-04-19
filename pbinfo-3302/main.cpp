#include <bits/stdc++.h>
using namespace std;
ifstream f("suminvdiv.in");
ofstream g("suminvdiv.out");
#define ull unsigned long long
double SumDivInv(ull n, ull s)
{
    double rez = (double)(s)*1.0 / (double)(n);
    return rez;
}
ull SumDiv(ull n)
{
    ull d = 2, k, s=1, p;
    while(n > 1)
    {
        k = 0;
        p = 1;
        while(n % d == 0)
            k++,p*=d,n/=d;
        if(k)
            s = s * (p * d - 1)/(d - 1);
        d++;
        if(n > 1 && d * d > n)
            d = n;
    }
    return s;
}
int main()
{
    ull x;
    while(f>>x)
    {
        ull z = SumDiv(x);
        g << fixed << setprecision(2)<< SumDivInv(x, z)<<' ';
    }
    return 0;
}