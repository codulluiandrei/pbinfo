#include <cstdio>
#include <cmath>
using namespace std;
const int NMAX=105;
int a[NMAX][NMAX],dx[]={-1,0,1,0},dy[]={0,1,0,-1};
int n,m;
void fill_cerinta2(int i,int j,int cod)
{
    int dir;
    if(a[i][j]==cod)
    {
        a[i][j]=-1;
        for(dir=0;dir<4;dir++)
            fill_cerinta2(i+dx[dir],j+dy[dir],cod);
    }
}
int main()
{
    freopen("phil.in","r",stdin);
    freopen("phil.out","w",stdout);
    int c,i,j,supr_phil=0,supr_palat=0,r,nr_case=0,nr_verzi=0,d;
    scanf("%d%d%d",&c,&n,&m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    }
    if(c==1)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(a[i][j]==0)
                    supr_phil++;
                else
                {
                    if(a[i][j]==1)
                        supr_palat++;
                }
            }
        }
        r=supr_palat/supr_phil;
        printf("%d",r);
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(a[i][j]==2)
                {
                    nr_case++;
                    fill_cerinta2(i,j,2);
                }
                else
                {
                    if(a[i][j]==3)
                    {
                        nr_verzi++;
                        fill_cerinta2(i,j,3);
                    }
                }
            }
        }
        d=fabs(nr_verzi-nr_case);
        printf("%d",d);
    }
    return 0;
}