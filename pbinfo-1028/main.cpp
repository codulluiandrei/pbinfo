//Prof Nicu Vlad-Laurentiu - Liceul Teoretic "Mihail Kogalniceanu" Vaslui
#include <algorithm>
#include <cstdio>
using namespace std;
const int N=405;
int n, m, nrzones;
char a[N][N],cu;
int  b[N][N], dx[]={-1, 0, 1, 0}, dy[]={0, 1, 0, -1}, d[N*N],p;
bool c[N*N];
void filll(int x, int y)
{
    b[x][y]=nrzones;
    d[nrzones]++;
    for(int i=0;i<4;i++)
    {
        if(!b[x+dx[i]][y+dy[i]]&&a[x][y]==a[x+dx[i]][y+dy[i]]) filll(x+dx[i], y+dy[i]);
    }
}
int main()
{
    freopen("ferma.in", "r", stdin);
    freopen("ferma.out", "w", stdout);
    int i, j, k, l, sol=0, s=0,v,ma=0,p=0;
    pair<int, int> soli;
    scanf("%d\n%d%d",&v, &n, &m);
    for(i=1;i<=n;i++)
    {
            scanf("%s", a[i]+1);
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(!b[i][j])
            {
                nrzones++;
                filll(i, j);
                if(ma<d[nrzones]){ma=d[nrzones];}
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            char aux=a[i][j];
            for(k=0;k<4;k++)
            {
                a[i][j]=a[i+dx[k]][j+dy[k]];
                for(l=0, s=0;l<4;l++)
                {
                    if(!c[b[i+dx[l]][j+dy[l]]]&&a[i][j]==a[i+dx[l]][j+dy[l]])
                    {
                        c[b[i+dx[l]][j+dy[l]]]=1;
                        s+=d[b[i+dx[l]][j+dy[l]]];
                    }
                }
                if(!c[b[i][j]]) s++;
                if(s>sol)
                {
                    sol=s; cu=a[i][j];
                    soli=make_pair(i, j);
                }
                for(l=0;l<4;l++)
                {
                    c[b[i+dx[l]][j+dy[l]]]=0;
                }
            }
            a[i][j]=aux;
        }
    }
    if(v==1) printf("%d\n",ma);
    else{printf("%d %d\n", soli.first, soli.second);
    printf("%c\n",cu);}
}