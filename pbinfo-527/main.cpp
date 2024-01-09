#include <iostream>
using namespace std;

int v[105], a[105][105], n ,m;

int main(){
	cin  >> n;	
	for(int i = 1 ; i <= n ;  ++i)
		cin >> v[i];
	cin >> m;
	for(int i = 1 ; i <= m ; ++i)
		for(int j = 1 ; j <= n ; ++j)
			cin >> a[i][j];
	int smin = 1000 * 1000 * 100 + 5;
	for(int  i = 1 ; i <= m ; ++i)
	{
		bool ok = true;
		for(int j = 1 ; j <= n ; ++j)
			if(a[i][j] == -1)
				ok = false;
		if(ok)
		{
			int s = 0;
			for(int j =1 ; j <= n ; ++j)
				s += a[i][j] * v[j];
			if(s < smin)
				smin = s;
		}
	}
	cout << smin;
	return 0;
}
