#include <bits/stdc++.h>
using namespace std;
ifstream f("cifrazecmax.in");
ofstream g("cifrazecmax.out");
#define frq fr[x/10%10]
int main()
{
    int fr[10]={0},x,i=0,poz=0,maxi=0;
    while(f>>x)
    {
        i++;
        frq++;
        if(frq>maxi)
            maxi=frq,poz=i;
    }
    g<<poz;
    f.close();
    g.close();
    return 0;
}
