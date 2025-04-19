#include <iostream>
#include <fstream>
using namespace std;
int n , a[105][105];
int main()
{
    int m;
    cin >> n >> m;
    while( m )
    {
		int i , j;
    	cin >> i >> j;
    	a[i][j] = 1;
    	m --;
    }
	for(int k = 1 ; k <= n ; ++k)
		for(int i = 1 ; i <= n ; ++i)
			for(int j = 1 ; j <= n ; ++j)
				if(a[i][j] == 0)
					a[i][j] = a[i][k] * a[k][j];
	for(int i =1 ; i <= n ; ++i)
	{
		int ok = 1;
		for(int j = 1 ; j <= n ; ++j)
			if(a[i][j] == 0 && j != i)
				ok = 0;
		if(ok)
			cout << i << " ";
	}
    return 0;
}