#include <fstream>
#include<queue>
#define VM 100000000
using namespace std;
ifstream fin("labirint.in");
ofstream fout("labirint.out");
char a[1002][1002];
struct poz
{
    int x,y;
};
int n,m,b[1002][1002],c[1002][1002];
int dx[4]= {-1,0,1,0};
int dy[4]= {0,1,0,-1};
queue<poz>q;

int main()
{
    int i,j,k,w,dm=VM;
    fin>>n>>m;

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            fin>>a[i][j];

///bordare
    for(j=0; j<=m+1; j++)
        a[0][j]=a[n+1][j]='Z';

    for(i=0; i<=n+1; i++)
        a[i][0]=a[i][m+1]='Z';

///matricea b
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i][j]=='A')
            {

                b[i][j]=1;
                q.push({i,j});
            }

    poz p1,p2;
    while(!q.empty())
    {
        p1=q.front();
        q.pop();

        for(k=0; k<4; k++)
        {
            p2.x=p1.x+dx[k];
            p2.y=p1.y+dy[k];

            if(a[p2.x][p2.y]!='Z' && b[p2.x][p2.y]==0)
            {
                w=b[p1.x][p1.y]+1;
                b[p2.x][p2.y]=w;
                q.push(p2);

            }
        }
    }

    ///matricea c
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i][j]=='C')
            {

                c[i][j]=1;
                q.push({i,j});
            }

    while(!q.empty())
    {
        p1=q.front();
        q.pop();

        for(k=0; k<4 ; k++)
        {
            p2.x=p1.x+dx[k];
            p2.y=p1.y+dy[k];

            if(a[p2.x][p2.y]!='Z' && c[p2.x][p2.y]==0)
            {
                w=c[p1.x][p1.y]+1;
                c[p2.x][p2.y]=w;
                q.push(p2);

            }
        }
    }

///final
    dm=VM;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i][j]=='B' && b[i][j]>0 && c[i][j]>0
               && b[i][j]+c[i][j]<dm)
                dm=b[i][j]+c[i][j];
    fout<<dm-1<<endl;
    return 0;
}
