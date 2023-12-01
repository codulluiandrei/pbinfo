#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

int main()
{
    int n , x , xmin = 1000000001;
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
    {
        assert(cin >> x);
        assert(x <= 1000000000);
        int cnt = 0 , d = 2 , y = x;
        while(x > 1)
        {
            if(x % d == 0)
            {
                cnt ++;
                while(x % d == 0)
                    x /= d;
            }
            d ++;
            if(d * d > x)
                d = x;
        }
        if(cnt == 1)
            if(y < xmin)
                xmin = y;
    }
    if(xmin == 1000000001)
        cout << "NU EXISTA";
    else
        cout << xmin << endl;
    return 0;
}
