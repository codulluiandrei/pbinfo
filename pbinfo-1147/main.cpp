//lucia miron
#include <fstream>
using namespace std;
ifstream fin("onigim.in");
ofstream fout("onigim.out");
int n,k,i,j,v[1001],a[1001],p[301],fr[1001],nrdistinctii,nr;
int main()
{
    fin>>n>>k;
    for(i=1;i<=k;i++)
            fin>>p[i];
    for(i=1;i<=n;i++)
            {
                fin>>a[i];
                fr[a[i]]++;
            }
    i=1;
    for(j=0;j<=n;j++)
        if(fr[j]!=0)
        {
            v[j]=p[i];
            i++;
        }
    for(i=1;i<=n;i++)
            a[i]=v[a[i]];
    for(i=1;i<=n;i++)
            fout<<a[i]<<' ';
    fout<<'\n';
    nrdistinctii=0;nr=0;
    for(i=n;i>=0;i--)
        if(fr[i]!=0&&nr<3)
        {
            nrdistinctii+=fr[i];
            nr++;
        }
    fout<<nrdistinctii<<'\n';
    nr=0;
    for(i=0;i<n;i++)
            if(nr<fr[i])nr=fr[i];
    fout<<nr<<'\n';
    fout.close();
    return 0;
}