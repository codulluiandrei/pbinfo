#include <fstream>
#include<stdio.h>
using namespace std;
int c[10005],l[10005],n,m,p,i,j,nr=0,lr,cr,x,y,ni,nj;
int main()
{
    ifstream fin("sah1.in");
    fin>>p>>n>>m>>lr>>cr;
    for(i=1;i<=m;i++){
        fin>>x>>y;
        l[x]=1;
        c[y]=1;
        if(x==lr||y==cr)
            nr++;
    }
    fin.close();
    ofstream fout("sah1.out");
    ni=nj=0;
    for(i=1;i<=n;i++){
        if(l[i]==0)
            ni++;
        if(c[i]==0)
            nj++;
    }
    if(p==1)
        fout<<nr<<'\n';
    else
        fout<<ni*nj<<'\n';
    fout.close();
    return 0;
}