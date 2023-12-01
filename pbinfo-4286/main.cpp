#include <iostream>

using namespace std;

int main(){
	int n, x[205], m, y[205];
	cin  >> n;	
	for(int i = 0 ; i < n ; ++ i)
		cin >> x[i];
	m = 0;
	for(int i = n-1 ; i >= 0 ; --i)
	{
		if(x[i] % 2 != 0)
			y[m++] = x[i];
	}
	for(int  i = 0; i < m ; ++i)
		cout << y[i] << " ";
	cout << '\n';
	return 0;
}
