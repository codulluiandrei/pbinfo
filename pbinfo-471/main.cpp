#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

ifstream fin("bipartit.in");
ofstream fout("bipartit.out");

int n , a[105][105], x[105] , k;

int main()
{
    int i , j , m;
    fin >> n >> m;
    while(m > 0)
    {
		fin >> i >> j;
    	a[i][j] = a[j][i] = 1;
    	m --;
    }
	fin >> k;
	for(int i = 1 ; i <= k ;++i)
	{
		int p;
		fin >> p;
		x[p] = 1;
	}
	for(int i = 1; i <= n ; i++)
		for(int j = 1 ; j <= n ; ++j)
			if(x[i] != x[j])
				if(a[i][j] != 0)
					a[i][j] = a[j][i] = 2;
	int  cnt = 0;
	for(int i = 1 ; i < n ; ++i)
		for(int  j = i + 1 ; j <= n ; ++j)
			if(a[i][j] == 1)
				cnt ++;
	for(int i = 1; i <= n ; i++){
		for(int j = 1 ; j <= n ; ++j)
			cout << a[i][j] << " ";
		cout << endl;
	}
	if(cnt == 0)
		fout << "DA";
	else
		fout << "NU";
	return 0;
}
