#include <iostream>
#define ll long long
using namespace std;
ll Q,a,b,l,r,e;

void solve()
{
    ll d,sol,j,k,u,x;

    d = b-a;
    sol = 0;
    for(j = 1; j*j < d; j++)
        if(d%j==0)
    {
        k = d/j;
        if(k%2-j%2==0)
        {
            u = (k-j)/2;
            x = u*u-a;
            if((x>=l)and(x<=r)) sol++;
        }
    }
    cout << sol << "\n";
}

int main()
{
    cin >> Q;
    for(e = 1; e <= Q; e++)
    {
        cin >> l >> r >> a >> b;
        solve();
    }
    return 0;
}