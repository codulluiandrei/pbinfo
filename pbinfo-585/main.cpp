#include <iostream>
using namespace std;
int n , a[105][105], s[105];
int main()
{
    int m , kk , v , p , q;
    cin >> n >> m >> kk >> v;
    while( m )
    {
		int i , j;
    	cin >> i >> j;
    	a[i][j] = 1;
    	m --;
    }
    for(int i =1 ; i <= kk ; i ++)
    {
		cin >> p;
		s[p] = 1;
	}
	for(int k = 1 ; k <= n ; ++k)
		if(s[k] == 1)
			for(int i = 1 ; i <= n ; ++i)
				for(int j = 1 ; j <= n ; ++j)
					if(a[i][j] == 0)
						a[i][j] = a[i][k] * a[k][j];
	for(int i =1 ; i <= v ; ++i)
	{
		cin >> p  >> q;
		if(a[p][q] == 1)
			cout << "DA
";
		else
			cout << "NU
";
	}
    return 0;
}