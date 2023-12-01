#include <iostream>

using namespace std;

int main() {
	
	int n, d = 2;
	
	int a = 0 , b = 0;
	
	cin >> n;
	
	while(d*d <= n && b == 0)
	{
		if(n % d == 0)
			if(a == 0)
				a = d;
			else
				b = d;
		d ++;
	}
	
	if(b == 0)
		b = n / a;
	
	
	cout << a + b << endl;
	
    return 0;
}
