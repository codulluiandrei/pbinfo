#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
ifstream fin("taxe2.in");
ofstream fout("taxe2.out");
void afis(int m[101][101],int x,int y)
{
    for(int i=1;i<=x;i++)
        {for(int j=1;j<=y;j++)
            cout<<m[i][j]<<" ";
        cout<<"\n";}
}
struct nod
{
    int x,y,c;
    bool operator <(nod x)const
    {
        return c>x.c;
    }
};nod xx;
priority_queue <nod, vector < nod > > q;
int sb,n,a[101][101],co[101][101];
void citire()
{
    fin>>sb>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            fin>>a[i][j];
}
int main()
{
    citire();
    q.push({1,1,a[1][1]});
    while(!q.empty() and co[n][n]==0)
    {
        xx=q.top();
        if(xx.x>1 and co[xx.x-1][xx.y]==0){q.push({xx.x-1,xx.y,xx.c+a[xx.x-1][xx.y]});co[xx.x-1][xx.y]=xx.c+a[xx.x-1][xx.y];}
        if(xx.x<n and co[xx.x+1][xx.y]==0){q.push({xx.x+1,xx.y,xx.c+a[xx.x+1][xx.y]});co[xx.x+1][xx.y]=xx.c+a[xx.x+1][xx.y];}
        if(xx.y>1 and co[xx.x][xx.y-1]==0){q.push({xx.x,xx.y-1,xx.c+a[xx.x][xx.y-1]});co[xx.x][xx.y-1]=xx.c+a[xx.x][xx.y-1];}
        if(xx.y<n and co[xx.x][xx.y+1]==0){q.push({xx.x,xx.y+1,xx.c+a[xx.x][xx.y+1]});co[xx.x][xx.y+1]=xx.c+a[xx.x][xx.y+1];}
        q.pop();
    }
    int val=co[n][n];
    (val>sb)?fout<<-1:fout<<sb-val;
    return 0;
}