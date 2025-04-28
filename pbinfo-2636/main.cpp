#include<bits/stdc++.h>
using namespace std;
long long a, b;
int main()
{
    cin >> a >> b;
    if(b == 0)
    {
        cout << a << " " << a << '\n';
        return 0;
    }
    int sol = a;
    for(long long i = 1; i <= b; ++i)
    {
        if(sol >= 2)
            sol -= 2;
        else
            --sol;
        if(sol == 0)
            break;
    }
    cout << sol << " ";
    long long gauss = 1;
    while(gauss * (gauss-1) / 2 < b)
        ++gauss;
    cout << max(0LL, a - gauss);
    return 0;
}