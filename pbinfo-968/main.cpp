#include <iostream>
using namespace std;

int main()
{ 
	long long n,x,y,z,a,b,c;
	x = y = 2; z = 3;
	cin >> n;
	for(int i = 1 ; i <= n + 1 ; i++)
	{
		a = x + y;
		b = x + z;c = y + z + x;
		x = a; y = b; z = c;
	}
	cout << x << " " << y << " " << z <<endl;
	return 0;
}
