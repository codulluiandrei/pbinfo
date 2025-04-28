#include <bits/stdc++.h>
#define nmax 100001
using namespace std;
ifstream fin("aint.in");
ofstream fout("aint.out");
int arb[4*nmax+55];
int i,n,v,m,mi,x,y,t;
void update(int nod, int st, int dr, int poz, int val)
{
    if(st==dr)
    {
        arb[nod]=val;
        return;
    }
    int mij=(st+dr)/2;
    if(poz<=mij)update(2*nod,st,mij,poz,val);
    else update(2*nod+1,mij+1,dr,poz,val);
    arb[nod]=min(arb[2*nod],arb[2*nod+1]);
}
void query(int nod, int st, int dr, int a, int b)
{
    if(a<=st && dr<=b)
    {
        mi=min(mi,arb[nod]);
        return;
    }
    int mij=(st+dr)/2;
    if(a<=mij)query(2*nod,st,mij,a,b);
    if(mij<b)query(2*nod+1,mij+1,dr,a,b);
}
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
    {
        fin>>v;
        update(1,1,n,i,v);
    }
    while(m--)
    {
        fin>>t>>x>>y;
        if(t==1)
            update(1,1,n,x,y);
        else
        {
            mi=INT_MAX;
            query(1,1,n,x,y);
            fout<<mi<<"\n";
        }
    }
    return 0;
}