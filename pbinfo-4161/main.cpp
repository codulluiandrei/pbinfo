#include <fstream>
using namespace std;
ifstream fin("picard.in");
ofstream fout("picard.out");

const int inf=100000;
int C[101][101],n,m,smax;

int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j) C[i][j]=inf;
    for(int i=1;i<=m;i++)
    {
        int x,y,c;
        fin>>x>>y>>c;
        C[x][y]=C[y][x]=c;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(C[i][j]>C[i][k]+C[k][j])
                    C[i][j]=C[i][k]+C[k][j];
    for(int i=1;i<=n;i++)
    {
        int s=0;
        for(int j=1;j<=n;j++)
            s=s+C[i][j];
        //fout<<s<<" " ;
        if(s>smax)
            smax=s;
    }
    for(int i=1;i<=n;i++)
    {
        int s=0;
        for(int j=1;j<=n;j++)
            s=s+C[i][j];
        if(s==smax)
            fout<<i<<" ";
    }
    return 0;
}
