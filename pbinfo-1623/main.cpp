#include <fstream>
using namespace std;
ifstream f("summax1.in");
ofstream g("summax1.out");
unsigned p,n,x,y,i,j,*a[2001],*b[2001],oo=2000000001,D,s[2001];
void afiseaza(unsigned,unsigned);
int main()
{
    f>>p>>n>>x>>y;
    for(i=0;i<=n;i++)
    {
        a[i]=new unsigned[i+3];
        b[i]=new unsigned[i+3];
        for(j=1;j<=i;j++)
            f>>a[i][j];
    }
    for(j=1;j<=n;j++)
        b[n][j]=a[n][j];
    for(i=n-1;i>=1;i--)
        for(j=1;j<=i;j++)
            b[i][j]=a[i][j]+max(b[i+1][j],b[i+1][j+1]);
    for(j=1;j<=n;j++)
        a[n][j]=1;
    for(i=n-1;i>=1;i--)
        for(j=1;j<=i;j++)
        {
            if(b[i+1][j]>b[i+1][j+1])
                a[i][j]=a[i+1][j];
            else
            if(b[i+1][j]<b[i+1][j+1])
                a[i][j]=a[i+1][j+1];
            else
                a[i][j]=min(a[i+1][j]+a[i+1][j+1],oo);
        }
    if(p==1)
    {
        g<<a[1][1];
        return 0;
    }
    afiseaza(1,1);
    return 0;
}
void afiseaza(unsigned I,unsigned J)
{
    if(D+a[I][J]<x)
    {
        D+=a[I][J];
        return;
    }
    s[I]=J;
    if(I==n)
    {
        D++;
        for(unsigned k=1;k<=n;k++)
            g<<s[k]<<' ';
        g<<'\n';
        return;
    }
    if(b[I+1][J]>=b[I+1][J+1])
    {
        afiseaza(I+1,J);
        if(D==y)return;
    }
    if(b[I+1][J+1]>=b[I+1][J])
        afiseaza(I+1,J+1);
}