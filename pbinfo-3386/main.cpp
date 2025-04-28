#include <fstream>
#include<cstring>
#include<algorithm>
using namespace std;
ifstream fin("serbare.in");
ofstream fout("serbare.out");
struct copil
{
    char p[51];
    int h;
} v[101];
int cond(copil a, copil b)
{
    if(a.h>b.h)return 0;
    else if(a.h==b.h&&strcmp(a.p,b.p)>0)return 0;
    return 1;
}
int cond1(copil a, copil b)
{
    if(a.h<b.h)return 0;
    else if(a.h==b.h&&strcmp(a.p,b.p)>0)return 0;
    return 1;
}
int n, i,j, k, fr[151], frmax, cer,hmax,x,y,ult;
int main()
{
    fin>>cer;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>v[i].p>>v[i].h;
        if(v[i].h>hmax)hmax=v[i].h;
        fr[v[i].h]++;
        if(fr[v[i].h]>frmax)
            frmax=fr[v[i].h];
    }
    if(cer==1)
    {
        fout<<frmax;
        fout<<'\n';
    }
    else
    {
        k=n-fr[hmax];
        x=0;
        ult=0;
        for(i=1; i<hmax; i++)
            if(fr[i])
            if(fr[i]+x<(k+1)/2)
            {
                ult=i,x=x+fr[i];
            }
            else
            {
                ult=i,x=x+fr[i];
                break;
            }
        y=n-x-fr[hmax];
        sort(v+1,v+n+1,cond);
        if(cer==2)
        {
            for(i=1; i<=ult; i++)
                for(j=1; j<=fr[i]; j++)
                    fout<<i<<' ';
            for(j=1; j<=fr[hmax]; j++)
                fout<<hmax<<' ';
            for(i=hmax-1; i>=ult+1; i--)
                for(j=1; j<=fr[i]; j++)
                    fout<<i<<' ';
        }
        else
        {
            for(i=1; i<=x; i++)
                fout<<v[i].p<<' ';
            for(i=n-fr[hmax]+1; i<=n; i++)
                fout<<v[i].p<<' ';
            sort(v+1,v+n+1,cond1);
            for(i=fr[hmax]+1; i<=fr[hmax]+y; i++)
                fout<<v[i].p<<' ';
        }
    }
    return 0;
}