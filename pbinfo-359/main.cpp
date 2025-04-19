#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
	int n , a , s , max;
	cin >> n >> a ;
	s = a , max = a;
	for(int i=2 ; i<=n ; ++i)
	{
		cin >> a;
		s += a;
		if(a > max)
			max = a;
	}
	cout << n*max - s;
	return 0;
}