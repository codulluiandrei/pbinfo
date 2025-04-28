#include <fstream>
using namespace std;
ifstream fin("saturate.in");
ofstream fout("saturate.out");
int n,m,A[101][101],G[101],gasit;
int grad(int i)
{
    int c=0;
    for(int j=1;j<=n;j++)
        if(A[i][j]==1) c++;
    return c;
}
int main()
{
    fin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        fin>>x>>y;
        A[x][y]=A[y][x]=1;
    }
    for(int i=1;i<=n;i++)
        G[i]=grad(i);
    for(int i=1;i<=n;i++)
        if((n%2==0 && G[i]>=n/2) || (n%2==1 && G[i]>n/2))
    {
        fout<<i<<" ";
        gasit=1;
    }
    if(!gasit) fout<<"Nu exista";
    return 0;
}