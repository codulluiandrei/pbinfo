#include <cstdio>
#include <algorithm>
#define MOD 100003
#define N 2002
using namespace std;
int n,i,j,k,m,cod,U[N],D[N][N];
int main()
{
    freopen("fractii2.in","r",stdin);
    freopen("fractii2.out","w",stdout) ;
    scanf("%d%d",&cod,&n);
    if(cod==1)
    {
        for(i=1;i<n;i++)printf("%d ",i);printf("%d\n",n-1);
        return 0;
    }
    n-=2;
    U[n+1]=2;
    for(i=n+1;i>=2;i--)
        for(m=U[i],j=1;j<=m;j++)
            U[i-j]=max(U[i-j],min(2*j,i-j));
    D[0][0]=D[1][1]=1;
    for(i=2;i<=n;i++)
    {
        m=U[i];
        for(j=1;j<=m;j++)
        {
            k=min(2*j,i-j);
            D[i][j]=D[i][j-1]+D[i-j][k]>=MOD?D[i][j-1]+D[i-j][k]-MOD:D[i][j-1]+D[i-j][k];
        }
    }
    printf("%d",D[n][2]);
    return 0;
}