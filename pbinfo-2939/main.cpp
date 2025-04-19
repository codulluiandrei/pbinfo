#include<bits/stdc++.h>
using namespace std;
int v[100005],cnt;
int main()
{
    freopen("permutari4.in","r",stdin);
    freopen("permutari4.out","w",stdout);
    int n,x;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&x);
        v[x]=i;
    }
    int maxx=-1e9;
    int minn=1e9;
    for(int i=1;i<=n;++i)
    {
        maxx=max(maxx,v[i]);
        minn=min(minn,v[i]);
        if(maxx-minn+1==i)
            cnt++;
    }
    printf("%d",cnt);
    return 0;
}