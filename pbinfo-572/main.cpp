//problema arma
/*
 * Mai intai vom inlocui cu zero toate elementele care corespund unor caramizi distruse, pentru toate tragerile
 * Apoi vom elimina de pe fiecare coloana elementele nule din interiorul coloanei, mutandu-le in partea de sus.
 * Pentru aceasta, vom folosi un vector suplimentar.
 * 
 * */

#include <iostream>
using namespace std;

int v[105], a[105][105], n, m, k;

int main(){
	cin  >> n >> m >> k;
	for (int i = 1 ;i <= n ; ++i)
		for(int j = 1 ; j <= m ; ++j)
			cin >> a[i][j];
	for( ; k ; k --)
	{
		int x;
		cin >> x;
		for (int i = 1 ;i <= n ; ++i)
			for(int j = 1 ; j <= m ; ++j)
				if(a[i][j] == x)
					a[i][j] = 0;
	}
	for(int j = 1; j <= m ; j ++)
	{
		for(int i = 1 ; i <= n ; ++i)
			v[i] = 0;
		for(int i = n, p = 0 ; i >= 1 ; i--)
			if(a[i][j] > 0)
				v[++p] = a[i][j];
		for(int i = n, p = 1 ; i >= 1 ; i--, p++)
			a[i][j] = v[p];
	}
	for(int i = 1 ; i <= n ; ++i)
	{
		for(int j = 1 ; j <= m ; ++j)
			cout << a[i][j] << " ";
		cout << endl;
	}
	
	return 0;
}
