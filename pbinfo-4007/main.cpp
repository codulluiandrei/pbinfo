#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int a , b , n, p = -1 , q = -1;
	cin >> n >> a >> b;
	
	for(int i = 0 ; p == -1 ; i ++)
		if( (n - i * a) % b == 0)
			p = i;
	q = (n - p * a) / b;
	for(int i =1 ; i <= p ; i ++)
		cout << a << " ";
	for(int i = 1; i <= q ; i ++)
		cout << b << " ";
	cout << endl;
	return 0;
}
