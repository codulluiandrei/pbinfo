#include <cstdio>
#define N 50001
using namespace std;
int n,m,a[N],i,j,k,x,sol;
int main()
{
    freopen("binremove.in","r",stdin);
    freopen("binremove.out","w",stdout);
    scanf("%d",&n);
    for(i=0,j=n-1;i<n;i++,j--)
    {
        scanf("%d",&x);
        if(x)a[++k]=j;
    }
    scanf("%d",&m);
    for(;m;m--)
    {
        scanf("%d",&x);
        sol=0;
        for(i=1;i<=k;i++)
        {
            if(a[i]<=x)break;
            a[i]--;sol=a[i]&1?sol+2:sol+1;
        }
        if(i<=k)
        {
            j=i;
            if(a[j]==x)j++;
            for(;j<=k;j++)
            {
                a[i++]=a[j];
                sol=a[j]&1?sol+2:sol+1;
            }
        }
        k=i-1;
        sol%3==0?printf("1\n"):printf("0\n");
    }
    return 0;
}