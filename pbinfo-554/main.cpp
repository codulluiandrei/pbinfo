#include <iostream>
using namespace std;
int main(){
	int n, v[55], m, x, Max = -1, imax = 0, s;
	cin  >> n;
	for(int i = 1 ; i <= n ; ++ i)
		cin >> v[i];
	cin >> m;
	for(int i = 1 ;i <= m ; ++i)
	{
		s = 0;
		for(int j = 1 ; j <= n ; ++j)
		{
			cin >> x;
			s += x * v[j];
		}
		if(s > Max)
			Max= s, imax = i;
	}
	cout << imax;
	return 0;
}