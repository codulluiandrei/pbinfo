#include <fstream>
using namespace std;
ifstream fin("foto.in");
ofstream fout("foto.out");
const int dx[]={0,-1,0,1,0};
const int dy[]={0,0,1,0,-1};
short a[101][101],n,m;
int mx,nr;
int interior(int x, int y);
void umple(int x, int y, int& mark);
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        fin>>a[i][j];
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        if(a[i][j]==0)
        {
        nr=0;
        umple(i,j,nr);
        if(nr>mx)mx=nr;
        }
    fout<<mx<<'\n';
    return 0;
}
void umple(int x, int y, int &mark)
{
    int l,c,k;
    mark++;
    a[x][y]=-1*mark;
    for(k=1;k<=4;k++)
    {
        l=x+dx[k];
        c=y+dy[k];
        if(interior(l,c) && (a[l][c]==0))
           umple(l,c,mark);
    }
}
int interior(int x, int y)
{
    return x>0 && x<=n && y>0 && y<=m;
}