#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;
ifstream fin("gears.in");
ofstream fout("gears.out");
int n , a[105][105], v[105] , x , d[105];
void df(int x, int directie)
{
	v[x] = 1;
	d[x] = directie;
	for(int i =1 ; i <= n ; ++i)
		if(v[i] == 0 && a[x][i] == 1)
			df(i, 1 - directie);
}
int main()
{
    int i , j , m;
    fin >> n >> x;
    m = n - 1;
    while(m > 0)
    {
		fin >> i >> j;
    	a[i][j] = a[j][i] = 1;
    	m --;
    }
	df(x , 0);
	for(int i = 1 ; i <= n ; ++ i)
		fout << (d[i] ? "S" : "D");
	return 0;
}