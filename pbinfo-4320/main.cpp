#include <iostream>
using namespace std;
int main()
{
	int n, x, xmax, a_max = -1;
	cin >> n;
	for(int i = 1; i <= n ; i ++)
	{
		cin >> x;
		int a = 0, p = 1, y = x;
		while(y > 0)
		{
			if(y % 2 == 0)
				a += y % 10 * p, p *= 10;
			y /= 10;
		}
		if(a > a_max)
			a_max = a, xmax = x;
		else
			if(a == a_max)
				if(x > xmax)
					xmax = x;
	}
	cout << xmax << endl;
	return 0;
}