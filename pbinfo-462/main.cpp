#include <iostream>
using namespace std;

int main()
{
	int a, b , n , max = -1, nrmax = -1, nrd , d;
	cin >> a;
	nrd = 0, d = 2;
	n = a;
	while(n > 1)
	{
		if(n % d == 0)
		{
			nrd ++;
			while(n % d == 0)
				n /= d;
		}
		d ++;
		if(n > 1 && d * d > n)
			nrd ++ , n = 1;
	}
	if(nrd > nrmax)
		nrmax = nrd, max = a;
	else
		if(nrd == nrmax)
			if(a > max)
				max = a;
	cin >> b;
	while(a != b)
	{
		nrd = 0, d = 2;
		n = b;
		while(n > 1)
		{
			if(n % d == 0)
			{
				nrd ++;
				while(n % d == 0)
					n /= d;
			}
			d ++;
			if(n > 1 && d * d > n)
				nrd ++ , n = 1;
		}
		if(nrd > nrmax)
			nrmax = nrd, max = b;
		else
			if(nrd == nrmax)
				if(b > max)
					max = b;
		a = b;
		cin >> b;
	}
	cout << max << " " << nrmax;
	return 0;
}
