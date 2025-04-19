#include<bits/stdc++.h>
using namespace std;
ifstream f("pergament.in");
ofstream g("pergament.out");
int s[52];
struct elem
{
    int l,c,t;
};
elem v[200002];
inline bool cmp(const elem &a,const elem &b)
{
    return a.l<b.l;
}
int main()
{
    int n,k,q,i,a,b,c,d,x,y,r,j,m=0,sol=0,l,ss;
    f>>n>>k>>q>>a>>b>>c>>d>>x>>y;
    for(i=1;i<=q;i++)
    {
        f>>r>>ss>>j;
        v[++m]={ss,r,1};
        v[++m]={ss+j,r,-1};
    }
    sort(v+1,v+m+1,cmp);
    j=1;
    for(i=1;i<=n;i++)
    {
        while(j<=m&&v[j].l<=i)
        {
            for(l=v[j].c;l<=k;l++)
                s[l]+=v[j].t;
            j++;
        }
        sol+=s[x+y-1]-s[x-1];
        x=(x*a+b)%k+1;
        y=(y*c+d)%(k-x+1)+1;
    }
    g<<sol;
    return 0;
}