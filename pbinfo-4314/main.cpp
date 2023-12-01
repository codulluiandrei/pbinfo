#include <iostream>

using namespace std;

int main()
{
	int n, p , cnt = 0;
	
	cin >> n;
	
	p = n;
	while(p > 9)
		p /= 10;
	do{
		if(n % 10 < p)
			cnt ++;
		n /= 10;
	}
	while(n);
	
	cout << cnt << endl;
	
	return 0;
}
