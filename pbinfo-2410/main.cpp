#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("produsxxl.in");
ofstream fout("produsxxl.out");
int x[105],y[105],p[205];
int main()
{
    int n, m, l, i, j, r;
    fin>>n;
    for(i=n; i>=1; i--)
    {
        fin>>x[i];
    }
    fin>>m;
    for(i=m; i>=1; i--)
    {
        fin>>y[i];
    }
    l=n+m-1;
    for(i=1; i<=n ; i++)
    {
        for(j=1; j<=m; j++)
        {
            p[i+j-1] += x[i]*y[j];
        }
    }
    r=0;
    for(i=1; i<=l; i++)
    {
        r+=p[i];
        p[i]=r%10;
        r/=10;
    }
    while(r)
    {
        p[++l]=r;
        r=r/10;
    }
    while(l>1 && p[l]==0)
    {
        l--;
    }
    for(i=l; i>=1; i--)
    {
        fout<<p[i];
    }
    fin.close();
    fout.close();
    return 0;
}