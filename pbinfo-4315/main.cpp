#include <iostream>
using namespace std;
int main()
{
	int n, c , cnt = 0;
	cin >> n;
	c = n;
	while(c > 99)
		c /= 10;
	c = c % 10;
	do{
		if(n % 10 > c)
			cnt ++;
		n /= 10;
	}
	while(n);
	cout << cnt << endl;
	return 0;
}