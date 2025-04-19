//Lucia Miron -Colegiul C. Negruzzi, Iasi
#include <fstream>
using namespace std;
ifstream fin("prajituri.in");
ofstream fout("prajituri.out");
int n, m, a[10001], b[10001], va[101], vb[101],i,j,nr, sol,st=-1,dr,ok;
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
    {
        fin>>a[i];
        va[a[i]]++;
    }
    for(i=1;i<=m;i++)
    {
        fin>>b[i];
        vb[b[i]]++;
    }
    for(i=1;i<=n-m+1;)
    {
        ok=1;
        for(j=1;j<=m;j++)
            if(a[i+j-1]!=b[j])
            {
                ok=0;break;
            }
        if(ok)
        {
            nr++;
            if(st==-1)
                st=i-1,dr=n-m-i+1;
            i=i+m;
        }
        else i=i+1;
    }
    sol=n;
    for(i=1;i<=100;i++)
        if(vb[i]!=0)
            sol=min(sol,va[i]/vb[i]);
    fout<<st<<' '<<dr<<'\n';
    fout<<nr<<'\n';
    fout<<sol<<'\n';
    fout.close();
    return 0;
}