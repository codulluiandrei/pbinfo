#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long x,y,pc,sc=0;
    int n,k,i;
    bool ok=0;
    cin>>n>>k;
    while(n--)
    {
        cin>>x;
        pc=x;
        while(pc>=10)pc/=10;
        if(pc==k)
        {
            ok=1;
            while(x)
            {
                sc+=x%10;
                x/=10;
            }
        }
    }
    if(ok)cout<<sc;
    else cout<<-1;
    return 0;
}