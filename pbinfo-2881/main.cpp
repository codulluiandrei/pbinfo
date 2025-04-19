#include<bits/stdc++.h>
using namespace std;
ifstream in("cartonase1.in");
ofstream out("cartonase1.out");
/*
int cmmdc(int a,int b)
{
    if(!a || !b)
        return max(a,b);
    int r=a%b;
    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
*/
int main()
{
    int a,b,n;
    in>>n>>a>>b;
    if(a==1)
    {
        out<<1;
        return 0;
    }
    int g=__gcd(a,b);
    if(g==1)
    {
        out<<2;
        return 0;
    }
    for(int i=3;i<=n;i++)
    {
        a=b;
        in>>b;
        g=__gcd(g,b);
        if(g==1)
        {
            out<<i;
            return 0;
        }
    }
    out<<-1;
    return 0;
}