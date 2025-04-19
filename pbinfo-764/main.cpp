#include <iostream>
using namespace std;
int n,m,k,a[101][101];
int main()
{
	cin >> n >> m >> k;
	for(int i = 1 ; i <= n ; ++i)
		for(int j = 1 ; j <= m ; ++j)
			cin >> a[i][j];
	int Max = 0;
	for(int p = 1 ; p <= k ; p ++)
	{
		int i1,j1,i2,j2;
		cin >> i1 >> j1 >> i2 >> j2;
		int s = 0;
		for(int i = i1 ; i <= i2 ; i ++)
			for(int j = j1 ; j <= j2 ; j ++)
				s += a[i][j];
		if(s > Max)
			Max = s;
	}
	cout << Max << endl;
	return 0;
}