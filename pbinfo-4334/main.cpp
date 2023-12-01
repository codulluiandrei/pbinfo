#include <iostream>

using namespace std;

int main() {
	
	int n , k, x;
	long long S = 0;
	
	cin >> k >> n;
	
	for(int i = 1; i <= n ; i ++)
	{
		cin >> x;
		int cx = x, d = 2 , sump = 0;
		while(x > 1)
		{
			if(x % d == 0)
			{
				int p = 0;
				while(x % d == 0)
					p ++, x /= d;
                sump += p;
			}
			d ++;
			if(d*d > x)
				d = x;
		}
		if(sump >= k)
			S += cx;
	}
	
	cout << S << endl;
	
    return 0;
}
