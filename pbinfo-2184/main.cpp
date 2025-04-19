#include <fstream>
using namespace std;
ifstream fin("schior.in");
ofstream fout("schior.out");
struct poz
{
    int x,y;
} c[10001];
int dx[]= {0,-1,-1,0,1,1,1,0,-1};
int dy[]= {0,0,1,1,1,0,-1,-1,-1};
int a[103][103], b[103][103], n, m, l1,c1, pr, ul, min1;
int main()
{
    int i,j,xc,yc,xu,yu;
    fin>>n>>m>>l1>>c1;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            fin>>a[i][j];
    c[1].x=l1;
    c[1].y=c1;
    pr=1;
    ul=1;
    b[l1][c1]=1;
    min1=a[l1][c1];
    while(pr<=ul)
    {
        xc=c[pr].x;
        yc=c[pr].y;
        pr++;
        for(int d=1; d<=8; d++)
        {
            xu=xc+dx[d];
            yu=yc+dy[d];
            if(xu>=1&& xu<=n && yu>=1 && yu<=m && b[xu][yu]==0 && a[xc][yc]>=a[xu][yu])
            {
                ul++;
                c[ul].x=xu;
                c[ul].y=yu;
                b[xu][yu]=1;
                if(a[xu][yu]<min1)
                    min1=a[xu][yu];
            }
        }
    }
    fout<<min1;
    return 0;
}