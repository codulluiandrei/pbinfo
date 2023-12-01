#include <iostream>
using namespace std;

int main(){
	int n , x;
	cin >> n;
	int max = -1, exp = 0;
	for(int i = 1 ; i <= n ; ++i)
	{
		cin >> x;
		int d = 2, p;
		while(x > 1)
		{
			p = 0;
			while(x % d == 0)
				p ++, x /= d;
			if(p)
			{
				if(d > max)
					max = d, exp = p;
				else
					if(d == max)
						exp += p;
			}
			d ++;
			if(x > 1 && d * d > x)
				d = x;
		}
	}
	cout << max << " " << exp;
	return 0;
}
