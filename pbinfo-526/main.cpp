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
	int s = 0;
	for(int i = 1; i <= n ; ++i)
	{
		int pmin = 1005;
		for(int j = 1 ; j <= m ; ++j)
			if(a[j][i] != -1)
				if(a[j][i] < pmin)
					pmin = a[j][i];
		s += pmin * v[i];
	}
	cout << s;
	return 0;
}
