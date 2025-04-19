#include <iostream>
#include <fstream>
using namespace std;
int n , a[105][105], x[105];
int main()
{
    int i , j , m;
    cin >> n;
    m = n * (n - 1) / 2;
    while( m )
    {
    	cin >> i >> j;
    	a[i][j] = 1;
    	m --;
    }
	m = 2;
	if(a[1][2] == 1)
		x[1] = 1, x[2] = 2;
	else
		x[1] = 2, x[2] = 1;
	for(int i = 3 ; i <= n ; ++i)
	{
		int p = 0;
		if(a[x[m]][i] == 1)
			p = m + 1;
		else
			if(a[i][x[1]] == 1)
				p = 1;
			else
				for(int j = 1 ; j < m && p == 0 ; ++j)
					if(a[x[j]][i] == 1 && a[i][x[j+1]] == 1)
						p = j + 1;
		for(int j = m ; j >= p ; --j)
			x[j+1] = x[j];
		x[p] = i;
		m ++;
	}
	for(int i = 1; i <= n ; ++i)
		cout << x[i] << " ";
	cout << "\n";
    return 0;
}