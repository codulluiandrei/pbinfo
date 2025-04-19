#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int n , a , b , amax = 0 , bmax = 0;
    cin >> n >> a;
    for(int i = 2 ; i <= n ; i ++)
    {
        cin >> b;
        int x = a , y = b , d , mx = 1 , my = 1; 
        d = 2;
        while(x > 1)
        {
            if(x % d == 0)
            {
                mx *= d;
                while(x % d == 0)
                    x /= d;
            }
            d ++;
            if(d * d > x)
                d = x;
        }
        d = 2;
        while(y > 1)
        {
            if(y % d == 0)
            {
                my *= d;
                while(y % d == 0)
                    y /= d;
            }
            d ++;
            if(d * d > y)
                d = y;
        }
        //cout << a << " " << b << "    " << mx << " " << my << endl;
        if(mx == my)
        {
            if(a + b > amax + bmax)
                amax = a , bmax = b;
        }
        a = b;
    }
    if(amax)
        cout << amax << " " << bmax <<endl;
    else
        cout << "NU EXISTA" << endl;
    return 0;
}