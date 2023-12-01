#include <iostream>

using namespace std;

int main()
{
	int n, m , max = -1, min = 10;
	
	cin >> n;
	
	m = n;
	while(m)
	{
		int c = m % 10;
		if(c > max)
			max = c;
		if(c < min)
			min = c;
		m /= 10;
	}
	
	int p = 1;
	
	while(n)
	{
		int c = n % 10;
		if(c == max)
			c = min;
		else
			if(c == min)
				c = max;
		m += c * p, p *= 10;
		n /= 10;
	}
	
	cout << m << endl;
	
	return 0;
}
