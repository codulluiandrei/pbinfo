/*
    Autor: Raileanu Alin-Gabriel
*/
#include <fstream>
#include <queue>
#include <algorithm>
const int NMAX=1005;
using namespace std;
ifstream fin("moara.in");
ofstream fout("moara.out");
struct moment
{
    int lin, col;
};
queue <moment> s;
bool viz[NMAX][NMAX];
long long n, m, k, maxim, nrc;
long long d[NMAX][NMAX], f[NMAX*NMAX];
long long c[NMAX][NMAX], a[NMAX][NMAX];
int dl[]= {0, 0, -1, 1};
int dc[]= {-1, 1, 0, 0};
bool traverseaza(long long);
long long cautare_binara();
void bordare();
int main()
{
    ios_base::sync_with_stdio(false);
    fin.tie(0);
    int i, j;
    int minim, ans=0;
    fin>>n>>m>>nrc;
    bordare();
    for(i=1; i<=nrc; i++)
    {
        fin>>f[i];
    }
    sort(f+1, f+nrc+1);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            fin>>a[i][j];
        }
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            fin>>c[i][j];
        }
    }
    minim=cautare_binara();
    fout<<nrc-minim+1<<'\n';
    return 0;
}
void bordare()
{
    int i;
    for(i=0; i<=n+1; i++) a[i][0]=a[i][m+1]=1e18;
    for(i=0; i<=m+1; i++) a[0][i]=a[n+1][i]=1e18;
}
long long cautare_binara()
{
    long long st=1, dr=nrc, mij, gasit=nrc+1;
    while(st<=dr)
    {
        mij=(st+dr)/2;
        if(traverseaza(f[mij]))
        {
            dr=mij-1;
            gasit=mij;
        }
        else st=mij+1;
    }
    return gasit;
}
bool traverseaza(long long fortza)
{
    int i, j;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            d[i][j]=-1;
        }
    }
    if(fortza<a[1][1]) return false;
    moment p;
    while(!s.empty()) s.pop();
    s.push({1, 1});
    d[1][1]=fortza;
    while(!s.empty())
    {
        p=s.front();
        if(p.lin==n && p.col==m) return true;
        for(i=0; i<4; i++)
        {
            if(d[p.lin+dl[i]][p.col+dc[i]]<(d[p.lin][p.col]-c[p.lin][p.col]) && (d[p.lin][p.col]-c[p.lin][p.col])>=a[p.lin+dl[i]][p.col+dc[i]])
            {
                d[p.lin+dl[i]][p.col+dc[i]]=(d[p.lin][p.col]-c[p.lin][p.col]);
                s.push({p.lin+dl[i], p.col+dc[i]});
            }
        }
        s.pop();
    }
    return false;
}