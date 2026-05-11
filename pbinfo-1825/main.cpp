// Popa Bogdan Ioan, clasa a 10-a, Colegiul National Aurel Vlaicu Orastie
#include <bits/stdc++.h>
#define kmax 10
#define nmax 203
#define pb push_back
#define inf (int)1e9
using namespace std;
ifstream fin("zoomba.in");
ofstream fout("zoomba.out");
vector<int>g[nmax];
int n,k,m,z;
int i,j,l,c;
int dp[nmax][1<<(kmax+1)];
int a[kmax];
int sol=inf;
queue < int > coada;
void lee(int v)
{
    int i,k;
    while(!coada.empty())
    {
        k=coada.front();
        coada.pop();
        for(i=0;i<g[k].size();i++)
            if(dp[g[k][i]][v]>dp[k][v]+1)
            {
                dp[g[k][i]][v]=dp[k][v]+1;
                coada.push(g[k][i]);
            }
    }
}
int construct(int l)
{
    int i=0;
    int ret=0;
    while(l--)
        ret^=(1<<(i++));
    return ret;
}
int nbiti(int x)
{
    int k=0;
    while(x)
    {
        k+=(x&1);
        x>>=1;
    }
    return k;
}
int main()
{
    fin>>n>>m>>k>>z;
    for(i=0;i<k;i++)
        fin>>a[i];
    while(m--)
    {
        fin>>i>>j;
        g[i].pb(j);
        g[j].pb(i);
    }
    for(i=1;i<=n;i++)
        for(j=1;j<(1<<kmax);j++)
            dp[i][j]=inf;
    for(i=0;i<k;i++)
    {
        dp[a[i]][1<<i]=0;
        coada.push(a[i]);
        lee(1<<i);
    }
    for(l=2;l<=k;l++)
        for(j=construct(l);j<(1<<k);j++)
            if(nbiti(j)==l)
            {
                for(i=1;i<=n;i++)
                {
                    for(c=1;c<j;c++)
                        if((j|c)==j)
                        dp[i][j]=min(dp[i][j],dp[i][c]+dp[i][j^c]);
                    coada.push(i);
                }
                lee(j);
            }
    fout<<(dp[z][(1<<k)-1] == inf ? -1 : dp[z][(1<<k)-1])<<"\n";
    return 0;
}