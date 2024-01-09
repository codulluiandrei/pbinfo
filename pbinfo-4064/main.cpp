#include <fstream>
using namespace std;
ifstream fin("ghiocel.in");
ofstream fout("ghiocel.out");

int A[101][101],n,m,k,g,x,y,D[1001],Q[1001],P[101],dmin=101;

void BF(int x)
{
    int st=1,dr=1;
    D[x]=1;
    Q[1]=x;
    while(st<=dr)
    {
        int v=Q[st];
        for(int i=1;i<=n;i++)
            if(A[v][i] && !D[i])
            {
                D[i]=D[v]+1;
                Q[++dr]=i;
            }
        st++;
    }
}

int main()
{
    fin>>n>>m>>g;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        fin>>x>>y;
        A[x][y]=A[y][x]=1;
    }
    fin>>k;
    for(int i=1;i<=k;i++)
    {
        int x;
        fin>>x;
        P[x]=1;
    }
    BF(g);
    for(int i=1;i<=n;i++)
        if(P[i] && D[i]<dmin) dmin=D[i];
    for(int i=1;i<=n;i++)
        if(P[i] && D[i]==dmin) fout<<i<<" ";
    return 0;
}
