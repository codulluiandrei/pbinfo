#include <iostream>
#include <fstream>
using namespace std;
int n , a[105][105];
int main()
{
    int i , j , m;
    cin >> n >> m;
    while( m )
    {
    	cin >> i >> j;
    	a[i][j] = 1;
    	m --;
    }
	for(int i = 1 ; i <= n ; ++i)
		for(int j = 1; j <= n ; ++j)
			if( a[i][j] )
				for(int k =1 ; k <= n ; k++)
					if( a[j][k] && a[k][i] )
						cout << i << " " << j << " " << k << "\n";
    return 0;
}