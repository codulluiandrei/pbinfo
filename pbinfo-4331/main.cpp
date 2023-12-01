#include <iostream>

using namespace std;

int main() {
	
	int n , a = -1, b = 1000000005, x;
	
	cin >> n;
	
	for(int i = 1; i <= n ; i ++)
	{
		cin >> x;
		if(x > a)
			a = x;
		if(x < b)
			b = x;
	}
	
	while(b)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	
	cout << a << endl;
	
    return 0;
}
