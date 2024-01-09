#include <iostream>
#include <fstream>
using namespace std;

int n , a[105][105], v[105];

void df(int x)
{
	v[x] = 1;
	for(int i = 1; i <= n ; ++i)
		if(a[i][x] == 1 && v[i] == 0)
			df(i);
}

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
	int p = 0;
	for(int i = 1 ; i <= n && p == 0 ; ++i)
	{
		for(int j = 1 ; j <= n ; ++j)
			v[j] = 0;
		df(i);
		int ok = 1;
		for(int j = 1 ; j <= n ; ++j)
			if(v[j] == 0)
				ok = 0;
		if(ok)
			p = i;
	}
	if(p == 0)
		cout << "NU EXISTA";
	else
		cout << p;
    return 0;
}
