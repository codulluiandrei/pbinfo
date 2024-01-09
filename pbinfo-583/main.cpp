#include <iostream>
#include <fstream>
using namespace std;

int n , a[105][105], ctc[105] , s[105], p[105], nrc;

void df1(int x)
{
	s[x] = 1;
	for(int i =1 ; i <= n ; i ++)
		if(s[i] == 0 && a[x][i] == 1)
			df1(i);
}

void df2(int x)
{
	p[x] = 1;
	for(int i =1 ; i <= n ; i ++)
		if(p[i] == 0 && a[i][x] == 1)
			df2(i);
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
	for(int i = 1 ; i <= n ; ++i)
		if(ctc[i] == 0)
		{
			for(int j = 1; j <= n ; ++j)
				s[j] = p[j] = 0;
			nrc ++;
			df1(i); df2(i);
			for(int j = 1; j <= n ; ++j)
				if(s[j] == 1 && p[j] == 1)
					ctc[j] = nrc;
		}
	cout << nrc << "
";
	/*
	for(int i =1 ; i <= nrc ;++i)
	{
		for(int j =1 ; j <= n ; ++j)
			if(ctc[j] == i)
				cout << j << " ";
		cout << endl;
	}
    */
    return 0;
}
