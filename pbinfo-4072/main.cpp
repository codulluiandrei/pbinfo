#include <fstream>
using namespace std;
ifstream fin("graf_partial_5.in");
ofstream fout("graf_partial_5.out");

int n,A[101][101],G[101],k;

int grad(int i)
{
    int g=0;
    for(int j=1;j<=n;j++)
        g=g+A[i][j];
    return g;
}

int main()
{
    int x,y;
    fin>>n>>k;
    while(fin>>x>>y)
        A[x][y]=A[y][x]=1;
    for(int i=1;i<=n;i++)
        G[i]=grad(i);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(A[i][j]==1 && G[i]>=k && G[j]>=k)
                    A[i][j]=A[j][i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            fout<<A[i][j]<<" ";
        fout<<endl;
    }
    return 0;
}
