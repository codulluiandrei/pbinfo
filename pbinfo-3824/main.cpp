#include <fstream>
using namespace std;
ifstream f("perechi6.in");
ofstream g("perechi6.out");
int a[100001],b[100001];
long long aa[100001],bb[100001];
int main()
{
    int n,m,i,j,p=0,nr;
    long long perechi=0;
    f>>n;
    for(i=1; i<=n; i++)
        f>>a[i];
    f>>m;
    for(i=1; i<=m; i++)
        f>>b[i];
    nr=1;
    j=1;
    for(i=2; i<=n; i++)
        if(a[i-1]==a[i])nr++;
        else
        {
            aa[j]=nr;
            nr=1;
            j=i;
        }
    aa[j]=nr;
    nr=1;
    j=1;
    for(i=2; i<=m; i++)
        if(b[i-1]==b[i])nr++;
        else
        {
            bb[j]=nr;
            nr=1;
            j=i;
        }
    bb[j]=nr;
    i=1;
    j=1;
    while(j<=m &&i<=n)
    {
        if(a[i]==b[j])
        {
            perechi=perechi+aa[i]*bb[j];
            i=i+aa[i];
            j=j+bb[j];
        }
        else if(a[i]<b[j])i=i+aa[i];
        else j=j+bb[j];
    }
    g<<perechi;
    return 0;
}