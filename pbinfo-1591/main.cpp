#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,v[270001],x,y,tip,init[100005],maxim;
long long sum[270001],rez;
void UpdateARB(int nod,int destination,int st,int dr,int val)
{
    if (st==dr)
    {
        sum[nod]=val;
        v[nod]=val;
        return;
    }
    int mij=(st+dr)/2;
    if (destination<=mij) UpdateARB(nod*2,destination,st,mij,val);else
                          UpdateARB(nod*2+1,destination,mij+1,dr,val);
    v[nod]=max(v[nod*2],v[nod*2+1]);
    sum[nod]=1LL*sum[nod*2]+1LL*sum[nod*2+1];
}
void QueryARB(int nod,int st,int dr,int left,int right)
{
    if (left<=st && dr<=right)
    {
        maxim=max(maxim,v[nod]);
        rez=rez+1LL*sum[nod];
        return;
    }
    int mij=(st+dr)/2;
    if (left<=mij) QueryARB(nod*2,st,mij,left,right);
    if (right>mij) QueryARB(nod*2+1,mij+1,dr,left,right);
}
int main()
{
    freopen("intervalxy.in","r",stdin);
    freopen("intervalxy.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&init[i]);
        UpdateARB(1,i,1,n,init[i]);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&tip,&x,&y);
        if (tip==1)
        {
            init[x]=y;
            UpdateARB(1,x,1,n,init[x]);
        }else
        {
            rez=0;
            maxim=-100001;
            QueryARB(1,1,n,x,y);
            rez=1LL*maxim*(y-x+1)-rez;
            printf("%lld\n",rez);
        }
    }
    return 0;
}