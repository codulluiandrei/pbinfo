#include <bits/stdc++.h>
using namespace std;
const int N=200010;
int n,k,q,u[15];
int64_t a[N],b[N],v[N],U[15];
int64_t S(int p,int64_t *AIB)
{
    int64_t ret=0;
    for(; p; p-=p&(-p))ret+=AIB[p];
    return ret;
}
void upd(int p,int64_t *AIB,int64_t val)
{
    for(; p<=n; p+=p&(-p))AIB[p]+=val;
}
void upd(int p,int64_t newVal)
{
    upd(p,b,1LL*p*(newVal-v[p]));
    upd(p,a,1LL*(newVal-v[p]));
    v[p]=newVal;
}
void upd()
{
    for(int i=1;i<=k;i++)
        cin>>u[i];
    for(int i=1;i<k;i++)
        U[i]=v[u[i+1]];
    U[k]=v[u[1]];
    for(int i=1;i<=k;i++)
        upd(u[i],U[i]);
}
int64_t trapez(int st,int dr)
{
    return S(dr,b)-S(st-1,b);
}
int64_t dreptunghi(int st,int dr,int h)
{
    return h*(S(dr,a)-S(st-1,a));
}
int64_t triunghi(int st,int dr)
{
    return trapez(st,dr)-dreptunghi(st,dr,st-1);
}
int64_t r_triunghi(int st,int dr)
{
    return dreptunghi(st,dr,dr+1)-trapez(st,dr);
}
int64_t solution(int64_t L,int64_t R,int64_t M)
{
    int64_t H;
    if(R-L+1<=2*M-1)
        H=R-L-M+2;
    else
        H=M;
    return triunghi(L,L+H-2)+dreptunghi(L+H-1,R-H+1,H)+r_triunghi(R-H+2,R);
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int64_t x;
        cin>>x;
        upd(i,x);
    }
    cin>>q;
    for(;q;q--)
    {
        int t;
        cin>>t;
        if(t==1)
            upd();
        else
        {
            int64_t L,R,M;
            cin>>L>>R>>M;
            cout<<solution(L,R,M)<<'\n';
        }
    }
    return 0;
}