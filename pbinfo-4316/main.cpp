#include <iostream>

using namespace std;

int main()
{
	int n, k , p = 1, q = 1;
	
	cin >> n >> k;
	
	while(k)
		q *= 10, k--;
		
	int m = n;
	while(m >= q)
		p *= 10, m /= 10;
		
	if(n / p % 10 < 9)
		n = n + p;
	else
		n -= 9 * p;
	
	cout << n << endl;
	
	return 0;
}
