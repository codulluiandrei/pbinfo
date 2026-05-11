#include <bits/stdc++.h>
using namespace std;
ifstream f("extrapare.in");
ofstream g("extrapare.out");
int n,k;
void solveTest()
{
    string s,t;
    f>>s;
    int lg=s.size(),R,L;
    R=lg-2;
    while(R>=0&&s[R]=='0')R-=2;
    if(R<k)
        t=s.substr(k,1000001);
    else
        t=s.substr(0,R-k+1)+s.substr(R+1,1000001);
    lg=t.size();L=0;
    while(L<lg-1&&t[L]=='0')L++;
    t=t.substr(L,1000010);
    lg=t.size();
    if(lg%2==0)
    {
        g<<"-1\n";
        return;
    }
    for(int i=1;i<lg;i+=2)
        if(t[i]=='1')
        {
            g<<"-1\n";
            return;
        }
    g<<t<<'\n';
}
int main()
{
    f>>n>>k;
    for(int i=1;i<=n;i++)
        solveTest();
    return 0;
}