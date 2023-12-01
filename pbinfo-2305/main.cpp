#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    int S = 0;
    int a , b;
    cin >> a >> b;
    while(a != 0 && b != 0)
    {
        int x = a, y = b;
        int pa  = 0, pb = 0;
        while(x) 
            pa = pa * 10 + x % 10, x /= 10;
        while(y) 
            pb = pb * 10 + y % 10, y /= 10;
        x = a, y = b;
        while(y != 0)
		{
			int r = x % y;
			x = y;
			y = r;
		}
		while(pb != 0)
		{
			int r = pa % pb;
			pa = pb;
			pb = r;
		}
		if(x == 1 && pa == 1)
			S += a + b;
        cin >> a >> b;
    }
    cout << S << endl;
    return 0;
}
