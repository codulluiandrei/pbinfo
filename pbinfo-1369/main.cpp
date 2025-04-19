#include <fstream>
using namespace std;
ifstream f("parcela.in");
ofstream g("parcela.out");
int aria;
int a[1001][1001];
void FILL(int x,int y,int c)
{
    if(a[x][y]==1)
        {
            a[x][y]=c;
            aria++;
            FILL(x-1,y,c);
            FILL(x,y+1,c);
            FILL(x+1,y,c);
            FILL(x,y-1,c);
        }
}
int main()
{
    int n,m,color=1,amax=0,cmax=0;
    f>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            f>>a[i][j];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i][j]==1)
                {
                    color++;
                    aria=0;
                    FILL(i,j,color);
                    if(aria>amax)
                        {
                            amax=aria;
                            cmax=color;
                        }
                }
    g<<color-1<<' '<<amax<<' '<<cmax-1;
    return 0;
}