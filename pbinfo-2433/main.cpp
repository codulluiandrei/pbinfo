//prof. Cristian Toncea - Colegiul National "Nicolae Balcescu" - Braila
#include <cstdio>

using namespace std;
int p;
long long s=0;
long a[1000005],k[1000005]={-1},i,n,j,c,l;

int main()
{
     freopen("cufar.in","r",stdin);
    freopen("cufar.out","w",stdout);
    scanf("%d %lld",&p,&n);
    if(p==1)
    {
        scanf("%d%d",&l,&c);
        for(i=2;i<=500000;i++)
        if(a[i]==0)
        for(j=1;j<=1000000/i;j++)
        {
            a[i*j]++;
            if(a[i*j]==c && i*j==l)
                printf("%ld",i);
        }

    }
    else
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&j,&c);
            k[j]=c;
        }
    for(i=2;i<=1000000;i++)
        if(a[i]==0)
        for(j=1;j<=1000000/i;j++)
        {
            a[i*j]++;
            if(a[i*j]==k[i*j])
{s=s+i;
}
        }
    printf("%lld",s);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
