#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int Max = -1;
    for(int i = 1 ; i <= n ; i ++)
    {
		int x, y;
		cin >> x;
		if(x >= 100000 && x < 1000000)
		{
			y = x;
			/// adidas
			/// aditus
			int a, d, i, s, t ,u;
			s = x % 10, x /= 10;
			u = x % 10, x /= 10;
			t = x % 10, x /= 10;
			i = x % 10, x /= 10;
			d = x % 10, x /= 10;
			a = x % 10, x /= 10;
			/// cout << a << d << i << t << u << s << endl;
			bool ok = true;
			if(a != u) ok = false;
			if(d != t) ok = false;
			if(a == d || a == i || a == s) ok = false;
			if(d == i || d == s) ok = false;
			if(i == s) ok = false;
			if(ok)
			{
				/// cout << "Adidas: " << y << endl;
				if(y > Max)
					Max = y;
			}
		}
	}
    if(Max == -1)
		cout << "nu exista\n";
	else
		cout << Max << endl;
    return 0;
}