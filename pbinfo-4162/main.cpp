#include <fstream>
using namespace std;
ifstream fin("dmin2.in");
ofstream fout("dmin2.out");
int k,n,m,A[101][101],V[101],D[101];
int dist_min(int x, int y)
{
    int Q[101],st=1,dr=1;
    for(int i=1;i<=n;i++)
        V[i]=D[i]=0;
    Q[st]=x;
    V[x]=1;
    D[x]=0;
    while(st<=dr && D[y]==0)
    {
        int v=Q[st];
        for(int i=1;i<=n;i++)
            if(!V[i] && A[v][i]==1)
            {
                dr++;
                Q[dr]=i;
                V[i]=1;
                D[i]=D[v]+1;
            }
        st++;
    }
    if(V[y]) return D[y];
    else return -1;
}
int main()
{
    int x,y;
    fin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        fin>>x>>y;
        A[x][y]=1;
    }
    fin>>k;
    for(int i=1;i<=k;i++)
    {
        fin>>x>>y;
        fout<<dist_min(x,y)<<endl;
    }
    return 0;
}