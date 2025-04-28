#include <iostream>
#define ll long long
using namespace std;
ll i,m,c,n,nn,k,maxim,nmax,x;
ll e[21],p[21];
void solve(int niv, ll nr)
{
    if(niv==m+1)
    {
        if(nr > maxim)
            maxim = nr;
    }
    else
    {
        int h;
        ll prod = 1, y;
        for(h = 0; h <= e[niv]; h++)
        {
            y = nr*prod;
            if(y < nmax)
            {
                solve(niv+1,y);
                prod = prod*p[niv];
            }
            else break;
        }
    }
}
int main()
{
    cin >> n >> k;
    nmax = 1;
    for(i = 1; i <= k; i++)
        nmax = nmax*10;
    nn = n;
    for(i = 2; i*i <= n; i++)
        if(n%i==0)
    {
        m++;
        p[m] = i;
        e[m] = 0;
        while(n%i==0)
        {
            e[m]++;
            n = n/i;
        }
    }
    if(n > 1)
    {
        m++;
        p[m] = n;
        e[m] = 1;
    }
    for(i = 1; i <= m; i++)
    {
        e[i] = e[i]*nn;
        x = 1;
        c = 0;
        while(x <= nmax)
        {
            x = x*p[i];
            c++;
        }
        if(c < e[i])
            e[i] = c;
    }
    maxim = 1;
    solve(1,1);
    cout << maxim;
    return 0;
}