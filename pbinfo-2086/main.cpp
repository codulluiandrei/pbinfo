# include <iostream>
# include <cstdio>
# include <climits>
# define maxn 1002
# define N_Max 1000010
using namespace std;
int x[maxn],L[maxn],Nr[maxn],N,k,lgmax,Min,poz,p,n;
bool prime[N_Max];
void ciur()
{
    int i,j;
    prime[0]=prime[1]=1;
    for(i=2; i<=N_Max; ++i)
    {
        if(prime[i]==0)
        {
            for(j=2; i*j<=N_Max; ++j)
                prime[i*j]=1;
        }
    }
}
int main()
{
    int i,j,y;
    freopen("sclmprime.in","r",stdin);
    freopen("sclmprime.out","w",stdout);
    ciur();
    scanf("%d", &n);
    for(i=1; i<=n; ++i)
    {
        scanf("%d", &y);
        if (!prime[y]) {
            x[++N] = y;
        }
    }
    L[N] = 1; lgmax = 1;
    for (i = N-1; i>0; --i)
    {
        L[i] = 1;
        for (j=i+1; j<=N; ++j)
            if (L[i]< 1 + L[j] && x[i]<=x[j])
            {
                L[i] = 1 + L[j];
            }
        if (L[i] > lgmax) lgmax = L[i];
    }
    printf("%d\n",lgmax);
    poz = 0;
    for(k = lgmax; k>0; --k)
    {
        Min = INT_MAX;
        for(i = poz+1; i <= N-k+1; ++i)
            if (Min > x[i] && L[i] == k && x[i] >= x[poz])
                p = i, Min = x[i];
        poz=p;
        printf("%d ",x[p]);
    }
    printf("\n");
    return 0;
}