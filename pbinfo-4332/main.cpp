#include <iostream>

using namespace std;

int main() {
	
	int n , max = -1, min = 1000000005, x;
	
	cin >> n;
	
	for(int i = 1; i <= n ; i ++)
	{
		cin >> x;
		bool prim = true;
		if(x < 2)
			prim = false;
		for(int d = 2 ; d*d <= x ; d ++)
			if(x % d == 0)
				prim = false;
		if(prim)
		{
			if(x > max)
				max = x;
			if(x < min)
				min = x;
		}
	}
	
	cout << max + min << endl;
	
    return 0;
}
