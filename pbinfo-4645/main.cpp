#include <bits/stdc++.h>
using namespace std;
ifstream fin("matrix.in");
ofstream fout("matrix.out");
typedef long long ll;
struct func /// functie de forma a*i + b*j + c, care va da coordonata pentru linie/coloana
{
    ll a,b,c;
} lin,col;
bool invers;
ll n,m,k;
ll v[1505][1505];
ll eval(func f,ll i,ll j)
{
    return f.a*i+f.b*j+f.c;
}
func combine(func f,func fi,func fj)
{
    func rez;
    rez.a=f.a*fi.a+f.b*fj.a;
    rez.b=f.a*fi.b+f.b*fj.b;
    rez.c=f.a*fi.c+f.b*fj.c+f.c;
    return rez;
}
void rotire() /// (i,j) -> (n-j+1,i), deci functia inversa va fi (i,j) -> (j,n-i+1)
{
    func fi={0,1,0};
    func fj={-1,0,n+1};
    lin=combine(lin,fi,fj);
    col=combine(col,fi,fj);
}
void linswap()
{
    func fi={-1,0,n+1};
    func fj={0,1,0};
    lin=combine(lin,fi,fj);
    col=combine(col,fi,fj);
}
void colswap()
{
    func fi={1,0,0};
    func fj={0,-1,n+1};
    lin=combine(lin,fi,fj);
    col=combine(col,fi,fj);
}
int main()
{
    fin>>n>>m;
    lin={1,0,0};
    col={0,1,0};
    while(m--)
    {
        ll tip;
        fin>>tip;
        if(tip==1)
        {
            ll i1,j1,i2,j2,val;
            fin>>i1>>j1>>i2>>j2>>val;
            ll is=1e9;
            is=min(is,eval(lin,i1,j1));
            is=min(is,eval(lin,i1,j2));
            is=min(is,eval(lin,i2,j1));
            is=min(is,eval(lin,i2,j2));
            ll ij=0;
            ij=max(ij,eval(lin,i1,j1));
            ij=max(ij,eval(lin,i1,j2));
            ij=max(ij,eval(lin,i2,j1));
            ij=max(ij,eval(lin,i2,j2));
            ll js=1e9;
            js=min(js,eval(col,i1,j1));
            js=min(js,eval(col,i1,j2));
            js=min(js,eval(col,i2,j1));
            js=min(js,eval(col,i2,j2));
            ll jj=0;
            jj=max(jj,eval(col,i1,j1));
            jj=max(jj,eval(col,i1,j2));
            jj=max(jj,eval(col,i2,j1));
            jj=max(jj,eval(col,i2,j2));
            v[is][js]+=val;
            v[is][jj+1]-=val;
            v[ij+1][js]-=val;
            v[ij+1][jj+1]+=val;
        }
        if(tip==2)
        {
            ll k;
            fin>>k;
            k%=4;
            while(k--)
                rotire();
        }
        if(tip==3)
            linswap();
        if(tip==4)
            colswap();
        assert(abs(lin.a)<=1&&abs(lin.b)<=1&&abs(lin.c)<=n+1);
        assert(abs(col.a)<=1&&abs(col.b)<=1&&abs(col.c)<=n+1);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            v[i][j]+=v[i-1][j]+v[i][j-1]-v[i-1][j-1];
    for(int i=1;i<=n;i++,fout<<'\n')
        for(int j=1;j<=n;j++)
        {
            ll x=eval(lin,i,j);
            ll y=eval(col,i,j);
            fout<<v[x][y]<<' ';
        }
    return 0;
} 