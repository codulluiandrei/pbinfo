#include <bits/stdtr1c++.h>
#define NM 31624
using namespace std;

ifstream fin("prietene.in");
ofstream fout("prietene.out");
int nrp;
int p[3500],fr1[13],fr2[13];
bool c[NM];
void ciur()
{
    int i,j;
    c[0] = c[1] = 1;
    for(i = 2; i * i <NM; i++)
        if(c[i]==0)
            for(int j = i * i; j <NM; j += i)
                c[j] = 1;
    nrp=0;
    for(i = 1; i <NM; ++i)
        if(c[i]==0)
        {
            nrp++;
            p[nrp] = i;
        }
}

int nr_factori_primi(long long x)
{
    int i = 1,nr=0,e;
    while(i<=nrp && p[i]*p[i]<=x)
    {
        e = 0;
        while(x % p[i] == 0)
        {
            x=x/p[i];
            e++;
        }
        if(e>0)
            nr++;
        i++;
    }
    if(x > 1)
        nr++;
    return nr;
}

int main()
{
    int n,m,i,nr,y,cer,nrm;
    long long x,rez,xm;
    ciur();
    nrm=0;
    fin>>cer>>n>>m;

    for(i=1; i<=n; i++)
    {
        fin>>x;
        nr=nr_factori_primi(x);
        fr1[nr]++;
        if(nr>nrm || nr==nrm && x>xm)
        {
            nrm=nr;
            xm=x;
        }
    }

    for(i=1; i<=m; i++)
    {
        fin>>x;
        nr=nr_factori_primi(x);
        fr2[nr]++;
        if(nr>nrm || nr==nrm && x>xm)
        {
            nrm=nr;
            xm=x;
        }
    }
    if(cer==1)
        fout<<xm<<'\n';
    else
    {
        rez=0;
        for(i=1; i<=12; i++)
            rez=rez+fr1[i]*fr2[i];
        fout<<rez<<'\n';
    }
    return 0;
}

