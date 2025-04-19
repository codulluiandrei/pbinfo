#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int a , b , n, p = 0 , q = -1;
	cin >> n >> a >> b;
	for(int i = 0 ; q == -1 ; i ++)
		if( (n - i * b) % a == 0)
			q = i;
	p = (n - q * b) / a;
	for(int i =1 ; i <= p ; i ++)
		cout << a << " ";
	for(int i = 1; i <= q ; i ++)
		cout << b << " ";
	cout << endl;
	return 0;
}