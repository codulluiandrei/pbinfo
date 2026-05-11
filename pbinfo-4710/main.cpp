#include<cstdio>
using namespace std;
int n,q,i,x,L,R,M,a[100010];
int main()
{
    freopen("eliminarex.in","r",stdin);
    freopen("eliminarex.out","w",stdout);
    scanf("%d%d",&n,&q);for(i=1;i<=n;i++)scanf("%d",&a[i]);
    a[n+1]=2000000001;n++;
    for(;q;q--)
    {
        scanf("%d",&x);
        for(L=0,R=n;R-L-1;)
        {
            M=(L+R)/2;
            if(a[M]>x)R=M;
            else L=M;
        }
        a[L]==x?printf("0\n"):printf("%d\n",x-L);
    }
    return 0;
}