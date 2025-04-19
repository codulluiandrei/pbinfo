#include<bits/stdc++.h>
using namespace std;
ifstream in("cifra4.in");
ofstream out("cifra4.out");
long long n,nr,x,y,p9[30];
int t,c,i,k,v[30];
long long getpoz(long long x)
{
    long long nr=x;
    k=0;
    while(nr)
    {
        v[++k]=nr%10;
        nr/=10;
    }
    for(int i=1;i<=k;i++)
        if(v[i]>c)
            v[i]--;
    nr=0;
    for(i=k;i>=1;i--)
        nr=nr*9+v[i];
    if(c!=0)
        return nr+1;
    long long sol=0,p=1;
    nr=0;
    do
    {
        int cif=x%10;
        sol+=(cif-1)*p;
        p*=9;
        nr++;
        x/=10;
    }
    while(x>0);
    for(int i=1;i<nr;i++)
        sol+=p9[i];
    return sol;
}
int main()
{
    in>>t;
    p9[0]=1;
    for(i=1;i<=17;i++)
        p9[i]=p9[i-1]*9;
    if(t==1)
    {
        in>>c>>n;
        if(c!=0)
        {
            nr = n-1;
            while(nr)
            {
                v[++k]=nr%9;
                nr/=9;
            }
            for(i=1;i<=k;i++)
                if(v[i]>=c)
                    v[i]++;
            for(i=k;i>=1;i--)
                out<<v[i];
            return 0;
        }
        nr=n-1;
        i=1;
        while(1)
        {
            if(nr-p9[i]>=0)
            {
                nr -= p9[i];
                i++;
            }
            else
                break;
        }
        /// in i avem numarul de cifre al numarului cautat
        /// acum repretam in baza 9 numarul
        while(k<i)
        {
            v[++k]=nr%9;
            nr/=9;
        }
        for(i=1;i<=k;i++)
            if(v[i]>=c)
                v[i]++;
        for(i=k;i>=1;i--)
            out<<v[i];
        return 0;
    }
    in>>c>>x>>y;
    if(x>y)
        swap(x,y);
    out<<(y-x+1)-(getpoz(y)-getpoz(x)+1);
    return 0;
}