#include <iostream>
#include <fstream>
using namespace std;
int n , a[105][105], x[105], v[105], d[105];
int main()
{
    int i , j , m, p;
    cin >> n >> p >> m;
    while( m )
    {
    	cin >> i >> j;
    	a[i][j] = 1;
    	m --;
    }
	int st = 1, dr = 1;
	x[dr] = p, v[p] = 1, d[p] = 0;
	while(st <= dr)
	{
		int k = x[st];
		for(int i = 1 ; i <= n ; i ++)
			if(a[k][i] == 1 && v[i] == 0)
				x[++dr] = i, v[i] = 1, d[i] = d[k] + 1;
		st ++;
	}
	int c = 0;
	for(int i = 1; i <= n ; ++i)
		if(i != p && d[i] != 0 && d[i] % 2 == 0)
			c ++;
	cout << c << endl;
	for(int i = 1; i <= n ; ++i)
		if(i != p && d[i] != 0 && d[i] % 2 == 0)
			cout << i << " ";
    return 0;
}