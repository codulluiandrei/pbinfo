#include<bits/stdc++.h>
using namespace std;

ifstream in("intersectie.in");
ofstream out("intersectie.out");

int n,m,i,t,x,y,nri,nrs,St[200005],Dr[200005];
pair<int,int> I[200005];

int checkin(int val)
{
    int i,rez=0;
    for(i=17;i>=0;i--)
        if(rez+(1<<i)<=nrs && I[rez+(1<<i)].first<=val)
            rez=rez+(1<<i);
    return (rez!=0 && I[rez].second>=val);
}

int srcst(int val)
{
    int i,rez=0;
    for(i=17;i>=0;i--)
        if(rez+(1<<i)<nri && St[rez+(1<<i)]<val)
            rez=rez+(1<<i);
    return St[rez+1];
}

int srcdr(int val)
{
    int i,rez=0;
    for(i=17;i>=0;i--)
        if(rez+(1<<i)<nri && Dr[rez+(1<<i)]<val)
            rez=rez+(1<<i);
    return Dr[rez+1];
}

int main()
{
    in>>n>>m>>t;
    for(i=1; i<=m; i++)
    {
        in>>x>>y;
        if(x<=y)
        {
            nri++;
            St[nri]=x;
            Dr[nri]=y;
            I[nri]={x,y};
        }
        else
        {
            nri++;
            St[nri]=x;
            Dr[nri]=n+1;
            I[nri]={x,n+1};
            nri++;
            St[nri]=0;
            Dr[nri]=y;
            I[nri]= {0,y};
        }
    }
    St[++nri]=n+1;
    Dr[nri]=n+1;
    sort(St+1,St+nri+1);
    sort(Dr+1,Dr+nri+1);
    sort(I+1,I+nri+1);
    I[0]={-1,-1};
    for(i=1;i<=nri;i++)
    {
        if(I[nrs].second<I[i].first)
        {
            nrs++;
            I[nrs]=I[i];
        }
        else
            I[nrs].second=max(I[nrs].second,I[i].second);
    }
    for(i=1;i<=t;i++)
    {
        in>>x>>y;
        if(x==y)
        {
            out<<"1\n";
            continue;
        }
        if(x<y)
        {
            if(srcst(x+1)>y && srcdr(x)>=y)
                out<<"1\n";
            else
                out<<"0\n";
            continue;
        }
        if(srcst(x+1)>n && srcdr(x)>n && srcst(1)>y && srcdr(0)>=y)
            out<<"1\n";
        else
            out<<"0\n";
    }
    return 0;
}
