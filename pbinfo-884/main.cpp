#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;
ifstream fin("paznici.in");
ofstream fout("paznici.out");
int n , m , p;
int a[201][201];
short  x[40005], y[40001];
char P[201][201];
const int dx[] = {0 , 0 , 1 , -1}, 
          dy[] = {1 , -1 , 0 , 0};
void fill (int i ,int j , int d)
{
	int st , dr;
	st = dr = 1;
	x[1] = i , y[1] = j;
	a[i][j] = 1;
	P[i][j] = '*';
	while(st <= dr)
	{
		int i = x[st], j = y[st];
		if(a[i][j] <= d)
			for(int k = 0 ; k < 4 ; k ++)
			{
				int ii = i + dx[k], jj = j + dy[k];
				if( ii > 0 && ii <= n && jj > 0 && jj <= m && P[ii][jj] !='#' && a[ii][jj] == 0)
				{
					a[ii][jj] = a[i][j] + 1;
					P[ii][jj] = '*';
					dr ++;
					x[dr] = ii, y[dr] = jj;
				}
			}
		st ++;
	}
}
void resetare()
{
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			a[i][j] = 0;
}
int main(){
	fin >> n >> m >> p;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			fin >> P[i][j];
	for ( ; p ; p --)
	{
		resetare();
		int i , j , d;
		fin >> i >> j >> d;
		if(a[i][j] == 0)
			fill(i,j,d);
	}
	int cnt = 0;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			if(P[i][j] == '-' && a[i][j] == 0)
				cnt ++;
	fout << cnt;
	return 0;
}