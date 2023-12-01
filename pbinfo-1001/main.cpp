#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("rotund.in");
ofstream fout("rotund.out");

bool rotund(int n)
{
	int m = n , k = 0, x[15];
	do
	{
		x[++k] = m % 10;
		m /= 10;
	}
	while(m != 0);
	for(int i = 1 , j = k ; i < j ; i ++, j --)
	{
		m = x[i], x[i] = x[j] , x[j] = m;
	}
	for(int kk = 1 ; kk <= k / 2 ; kk ++)
	{
		m = x[k];
		for(int i = k ; i > 1 ; i --)
			x[i] = x[i-1];
		x[1] = m;
		m = 0;
		for(int i = 1 ; i <= k ; i ++)
			m = 10 * m + x[i];
		if(m == n)
			return true;
	}
	return false;
}

int main()
{
	int n , x , m = 0 , v[55];
	fin >> n;
	while(n > 0)
	{
		fin >> x;
		if( rotund(x) )
			v[m++] = x;
		n --;
	}
	fout << m << endl;
	for(int i = 0 ; i < m ; i ++)
		fout << v[i] << " ";
	return 0;
}

