#include <bits/stdc++.h>
using namespace std;
ifstream f("lumini.in");
ofstream g("lumini.out");
#define L 1010
struct fulger
{
    long long poz;
    int fr;
} lin[L], col[L], diag[2*L];
int nLin, nCol, nDiag, n;
int cauta(fulger a[], int n, long long v)
{
    int s=1, d=n, m;
    while(s<=d)
    {
        m=(s+d)/2;
        if(a[m].poz==v)return m;
        else if(v<a[m].poz)d=m-1;
        else s=m+1;
    }
    return s;
}
void insereaza(fulger a[], int &n, long long v)
{
    if(n==0)
    {
        a[++n].poz=v;
        a[n].fr=1;
        return;
    }
    int pozitie=cauta(a,n,v), i;
    if(pozitie<=n && a[pozitie].poz==v)a[pozitie].fr++;
    else
    {
        i=n;
        while(i>0 && a[i].poz>v)a[i+1]=a[i--];
        a[i+1].poz=v;
        a[i+1].fr=1;
        n++;
    }
}
int main()
{
    f>>n;
    int x, y, z, i, Q;
    f>>Q;
    for(i=1; i<=Q; i++)
    {
        f>>x;
        if(x==1)f>>y, insereaza(lin, nLin, y);
        else if(x==2)f>>y, insereaza(col, nCol, y);
        else f>>y>>z, insereaza(diag, nDiag, 1LL*y+1LL*z-1);
    }
    lin[nLin+1].poz=col[nCol+1].poz=diag[nDiag+1].poz=n+1;
    for(i=2; i<=nLin+1; i++)lin[i].fr+=lin[i-1].fr;
    for(i=1; i<=nCol+1; i++)col[i].fr+=col[i-1].fr;
    for(i=1; i<=nDiag+1; i++)diag[i].fr+=diag[i-1].fr;
    f>>Q;
    for(i=1; i<=Q; i++)
    {
        f>>x>>y;
        int far=1-(x%2+y%2)%2;
        int p=cauta(lin,nLin, x);
        if(lin[p].poz>x)p--;
        if(lin[p].fr%2)far=!far;
        p=cauta(col,nCol, y);
        if(col[p].poz>y)p--;
        if(col[p].fr%2)far=!far;
        p=cauta(diag,nDiag, 1LL*x+1LL*y-1);
        if(diag[p].poz>1LL*x+1LL*y-1)p--;
        if(diag[p].fr%2)far=!far;
        g<<far<<' ';
    }
    return 0;
}