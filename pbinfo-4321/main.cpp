#include <iostream>
using namespace std;
int main()
{
	int n, x, xmin, a_min = 1000000001;
	cin >> n;
	for(int i = 1; i <= n ; i ++)
	{
		cin >> x;
		int a = 0, p = 1, y = x;
		while(y > 0)
		{
			int c = y % 10;
			if(c % 2 == 0)
				c ++;
			a += c * p, p *= 10;
			y /= 10;
		}
		if(a < a_min)
			a_min = a, xmin = x;
		else
			if(a == a_min)
				if(x < xmin)
					xmin = x;
	}
	cout << xmin << endl;
	return 0;
}