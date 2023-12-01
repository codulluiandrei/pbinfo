#include <iostream>
using namespace std;

int main(){
	int n, x[1005], m , y[1005];
	cin  >> n;	
	for(int i = 1 ; i <= n ; ++ i)
		cin >> x[i];
	cin >> m;
	for(int i = 1 ; i <= m ; ++i)
		cin >> y[i];
	int p = 0;
	for(int i = 1 ; i <= n - m + 1 ; i ++)
	{
		bool ok = true;
		for(int j = 1 ; j <= m; ++j)
			if(x[i + j - 1] != y[j])
				ok = false;
		if(ok)
			p ++;
	}
	cout << p;
	return 0;
}
