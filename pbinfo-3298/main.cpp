#include <bits/stdc++.h>
using namespace std;
#define nmax 105
ifstream f("fmi_orase2.in");
ofstream g("fmi_orase2.out");
int a[nmax],m,orase,x;
int main ()
{
    int i;
    f>>m;
    for (i=1; i<=m; i++ )
    {
        f>>x;
        if (x >= m)
            a[m]++;
        else
            a[x]++;
    }
    for (i=m; i ; i--)
    {
        orase=orase+a[i] ;
        if (orase >= i)
        {
            g<<i; return 0;
        }
    }
    f.close();
    g.close();
}