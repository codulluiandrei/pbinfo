///Ispir Alexandru - 100p
#include <fstream>
#define DIM 500
using namespace std;
ifstream fin("pestelee.in");
ofstream fout("pestelee.out");
int m,n,x1,y1,x2,y2,c;
int a[DIM+5][DIM+5];
long long int b[DIM+5][DIM+5];
struct coada
{
    int x,y;
}C[DIM*DIM+5];
void bordare()
{
    for(int i=0;i<=m+1;i++)
        a[i][0]=a[i][n+1]=-1;
    for(int j=0;j<=n+1;j++)
        a[0][j]=a[m+1][j]=-1;
    return;
}
void lee()
{
    int i,lim=1;
    C[lim].x=x1;
    C[lim].y=y1;
    a[C[lim].x][C[lim].y]=1;
    b[C[lim].x][C[lim].y]=1;
    for(i=1;i<=lim && (C[i].x!=x2 || C[i].y!=y2);i++)
    {
        if(a[C[i].x+1][C[i].y]==0)
        {
            C[++lim].x=C[i].x+1,C[lim].y=C[i].y;
            a[C[i].x+1][C[i].y]=a[C[i].x][C[i].y]+1;
            b[C[i].x+1][C[i].y]=b[C[i].x+2][C[i].y]+b[C[i].x+1][C[i].y+1]+b[C[i].x+1][C[i].y-1]+b[C[i].x][C[i].y];
            b[C[i].x+1][C[i].y]%=10007;
        }
        if(a[C[i].x][C[i].y+1]==0)
        {
            C[++lim].x=C[i].x,C[lim].y=C[i].y+1;
            a[C[i].x][C[i].y+1]=a[C[i].x][C[i].y]+1;
            b[C[i].x][C[i].y+1]=b[C[i].x+1][C[i].y+1]+b[C[i].x-1][C[i].y+1]+b[C[i].x][C[i].y]+b[C[i].x][C[i].y+2];
            b[C[i].x][C[i].y+1]%=10007;
        }
        if(a[C[i].x-1][C[i].y]==0)
        {
            C[++lim].x=C[i].x-1,C[lim].y=C[i].y;
            a[C[i].x-1][C[i].y]=a[C[i].x][C[i].y]+1;
            b[C[i].x-1][C[i].y]=b[C[i].x-2][C[i].y]+b[C[i].x][C[i].y]+b[C[i].x-1][C[i].y-1]+b[C[i].x-1][C[i].y+1];
            b[C[i].x-1][C[i].y]%=10007;
        }
        if(a[C[i].x][C[i].y-1]==0)
        {
            C[++lim].x=C[i].x,C[lim].y=C[i].y-1;
            a[C[i].x][C[i].y-1]=a[C[i].x][C[i].y]+1;
            b[C[i].x][C[i].y-1]=b[C[i].x+1][C[i].y-1]+b[C[i].x-1][C[i].y-1]+b[C[i].x][C[i].y-2]+b[C[i].x][C[i].y];
            b[C[i].x][C[i].y-1]%=10007;
        }
    }
    if(a[x2][y2]==0)
        fout<<"0";
    else
        if(c==1)
            fout<<a[x2][y2];
        else
            fout<<b[x2][y2]%10007;
    return;
}
int main()
{
    fin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            fin>>a[i][j];
            if(a[i][j]==1)
                a[i][j]=-1;
        }
    }
    fin>>x1>>y1>>x2>>y2;
    fin>>c;
    bordare();
    lee();
    ///for(int i=1;i<=m;i++)
    ///{
        ///for(int j=1;j<=n;j++)
        ///{
            ///fout<<a[i][j]<<" ";
        ///}
        ///fout<<"\n";
    ///}
    return 0;
}