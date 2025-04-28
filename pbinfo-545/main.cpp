#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;
ifstream fin ("euler.in");
ofstream fout("euler.out");
int n , a[205][205], d[205], x[50000], y[50000], p , q;
int main()
{
    int i , j;
    fin >> n;
    while(fin >> i >> j)
    {
		a[i][j] = a[j][i] = 1;
		d[i] ++, d[j] ++;
    }
    p = 1; x[1] = 1;
    while(1)
    {
		int xpoz = 0;
		for(int i = 1 ; i <= p && xpoz == 0 ; ++i)
			if(d[x[i]] > 0)
				xpoz = i;
		if(xpoz == 0)
			break;
		q = 1; y[1] = x[xpoz];
		do
		{
			int ypoz = 0;
			for(int i =1 ; i <= n && ypoz == 0 ; i ++)
				if(a[y[q]][i] != 0)
					ypoz = i;
			d[y[q]] --;
			d[ypoz] --;
			a[y[q]][ypoz] = a[ypoz][y[q]] = 0;
			y[ ++ q] = ypoz;
		}
		while(y[q] != y[1]);
		for(int i = p; i > xpoz ; i --)
			x[i + q - 1] = x[i];
		for(int i = xpoz, j = 1 ; j <= q ; i ++, j ++)
			x[i] = y[j];
		p += q - 1;
	}
	fout << p << "\n";
	for(int i =1 ; i <= p ; i ++)
		fout << x[i] << " ";
	return 0;
}