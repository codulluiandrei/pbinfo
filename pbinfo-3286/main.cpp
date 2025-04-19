#include <bits/stdc++.h>
using namespace std;
ifstream f("nrnot.in");
ofstream g("nrnot.out");
int main()
{
    int n,x,y,k=1;
    f>>n>>x;
    while(f>>y)
    {
        if(x!=y)
            k++;
        x=y;
    }
    g<<n-k;
    f.close();
    g.close();
    return 0;
}