//Raluca Costineanu
#include <bits/stdc++.h>

using namespace std;
#define nMax 50010
#define mMax 1010

ifstream f("paralele.in");
ofstream g("paralele.out");

int n, m, t;
long long lin[nMax], col[mMax], lgCol[nMax];
bool a[mMax];
long long peLinii()
{
    int i, j, lg;
    long long total=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            f>>a[j];
        lg=0;
        for(j=1;j<=m+1;j++)
            if(a[j]==1)
                lg++;
            else lin[i]+=1LL*lg*(lg-1)/2, lg=0;
        total+=lin[i];
    }
    total=total*(total-1)/2;
    for(i=1;i<=n;i++)
        total-=1LL*lin[i]*(lin[i]-1)/2;
    return total;
}
long long peColoane()
{
    long long total=0;
    int i, j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            f>>a[j];
        for(j=1;j<=m+1;j++)
            if(a[j]==1)
                lgCol[j]++;
            else col[j]+=1LL*lgCol[j]*(lgCol[j]-1)/2, lgCol[j]=0;
    }
    for(j=1;j<=m;j++)
    {
        if(lgCol[j])
            col[j]+=1LL*lgCol[j]*(lgCol[j]-1)/2;
        total+=col[j];
    }
    total=total*(total-1)/2;
    for(j=1;j<=m;j++)
        total-=1LL*col[j]*(col[j]-1)/2;
    return total;
}
int main()
{
    f>>t>>n>>m;
    if(t==1)
        g<<peLinii()<<'\n';
    else
        g<<peColoane()<<'\n';
    return 0;
}
