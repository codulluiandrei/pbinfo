#include <bits/stdc++.h>

using namespace std;
ifstream fin("legenda.in");
ofstream fout("legenda.out");
typedef long long ll;
ll v[1005][1005],n,m,q,diag[1005][1005];
int main()
{
    ios_base::sync_with_stdio(false);
    fin.tie(0);
    fin>>n>>m>>q;
    while(q--)
    {
        ll i,j,val;
        fin>>i>>j>>val;
        if((i-val+1)<1||(j-val+1)<1)
            continue;
        for(int x=val;x>=1;x--)
        {
            int x1=i-(val-x);
            int y1=j;

            int x2=i+1;
            int y2=j-(val-x+1);

            diag[x1][y1]+=x;
            diag[x2][y2]-=x;
        }
    }
    for(int j=1;j<=m;j++)
    {
        ll suma=0;
        ll x1=1;
        ll y1=j;
        while(x1<=n&&y1>=1)
        {
            suma+=diag[x1][y1];
            v[x1][y1]=suma;
            x1++;
            y1--;
        }
    }
    for(int i=2;i<=n;i++)
    {
        ll suma=0;
        ll x1=i;
        ll y1=m;
        while(x1<=n&&y1>=1)
        {
            suma+=diag[x1][y1];
            v[x1][y1]=suma;
            x1++;
            y1--;
        }
    }
    for(int i=1;i<=n;i++,fout<<'\n')
        for(int j=1;j<=m;j++)
            fout<<v[i][j]<<' ';
    return 0;
}
