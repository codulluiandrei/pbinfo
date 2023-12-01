#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("divizori2.in");
    ofstream fout("divizori2.out");
    int P,n,i,x,maxim,prim,nrdiv,d,a[1001],minim,nr,j;
    fin>>P;
    if(P==1)
    {
        fin>>n;
        maxim=0;
        for(i=1;i<=n;i++)
        {
            fin>>x;
            if(x>maxim)
                maxim=x;
        }
        for(i=1;i<=maxim;i++)
            if(maxim%i==0)
                fout<<i<<' ';
    }
    if(P==2)
    {
        fin>>n;
        prim=0;
        for(i=1;i<=n;i++)
        {
            fin>>x;
            nrdiv=0;
            for(d=1;d<=x;d++)
                if(x%d==0)
                    nrdiv++;
            if(nrdiv==2)
            {
                fout<<x<<' ';
                prim=1;
            }
        }
        if(prim==0)
            fout<<-1;
    }
    if(P==3)
    {
        fin>>n;
        for(i=1;i<=n;i++)
            fin>>a[i];
        minim=a[1];
        for(i=1;i<=n;i++)
            if(a[i]<minim)
                minim=a[i];
        for(i=1;i<=minim;i++)
        {
            nr=0;
            for(j=1;j<=n;j++)
                if(a[j]%i==0)
                    nr++;
            if(nr==n)
                fout<<i<<' ';
        }
    }
    fin.close();
    fout.close();
    return 0;
}
