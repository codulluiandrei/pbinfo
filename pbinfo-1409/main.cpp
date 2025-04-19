#include <iostream>
#include <cassert>
using namespace std;
int main()
{
    int n , x;
    long long s = 0;
    cin >> n;
    for(int i = 1; i <= n ; i ++)
    {
        cin >> x;
        assert(x > 1 && x < 1000000000);
        int dmax = 0 , d = 2;
        while(x > 1)
        {
            int p = 0;
            while(x % d == 0)
                x /= d, p ++;
            if(p > 0)
                dmax = d;
            d ++;
            if(d * d > x)
                d = x;
        }
        s += dmax;
    }
    cout << s << endl;
    return 0;
}