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
	for(int k = 1 ; k <= n ; ++k)
		for(int i = 1 ; i <= n ; ++i)
			for(int j = 1 ; j <= n ; ++j)
				if(a[i][j] == 0)
					a[i][j] = a[i][k] * a[k][j];
	for(int i =1 ; i <= n ; ++i)
	{
		for(int j = 1 ; j <= n ; ++j)
			cout << a[i][j] << " ";
		cout << "\n";
	}
    return 0;
}