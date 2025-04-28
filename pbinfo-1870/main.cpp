// Popa Bogdan Ioan clasa a 10-a, Colegiul National Aurel Vlaicu
#include <bits/stdc++.h>
#define nmax 100002
#define vmax 1000000000
#define pb push_back
using namespace std;
ifstream fin("easyxy.in");
ofstream fout("easyxy.out");
vector <int> arb[4*nmax+55];
int a[nmax];
int n,m;
int i;
void build(int nod, int st, int dr)
{
    if(st==dr)
    {
        arb[nod].pb(a[st]);
        return;
    }
    int mij=(st+dr)/2;
    build(2*nod,st,mij);
    build(2*nod+1,mij+1,dr);
    int i,j;
    for(i=0,j=0;i<(int)arb[2*nod].size() && j<(int)arb[2*nod+1].size();)
    {
        if(arb[2*nod][i]<=arb[2*nod+1][j])
            arb[nod].pb(arb[2*nod][i++]);
        else arb[nod].pb(arb[2*nod+1][j++]);
    }
    while(i<(int)arb[2*nod].size())
        arb[nod].pb(arb[2*nod][i++]);
    while(j<(int)arb[2*nod+1].size())
        arb[nod].pb(arb[2*nod+1][j++]);
}
int lwr;
bool ok;
void query(int nod, int st, int dr, int a, int b, int val)
{
    if(a<=st && dr<=b)
    {
        int p=upper_bound(arb[nod].begin(),arb[nod].end(),val)-arb[nod].begin();
        lwr+=p;
        if(p!=0)
            if(arb[nod][p-1]==val)ok=1;
        return;
    }
    int mij=(st+dr)/2;
    if(a<=mij)
        query(2*nod,st,mij,a,b,val);
    if(b>mij)
        query(2*nod+1,mij+1,dr,a,b,val);
}
int sol(int st, int dr, int poz)
{
    int s=1,d=n,m,best=-1;
    while(s<=d)
    {
        m=s+(d-s)/2;
        lwr=0;
        ok=0;
        query(1,1,n,st,dr,a[m]);
        if(st+lwr-1>=poz)
        {
            if(ok==1)
            {
                best=a[m];
                if(st+lwr-1==poz)return a[m];
            }
            d=m-1;
        }
        else s=m+1;
    }
    return best;
}
int x,y,p;
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    build(1,1,n);
    for(i=1;i<=n;i++)
        a[i]=arb[1][i-1];
    while(m--)
    {
        fin>>x>>y>>p;
        fout<<sol(x,y,p)<<"\n";
    }
    return 0;
}