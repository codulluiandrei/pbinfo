#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;
ifstream fin("acces2.in");
ofstream fout("acces2.out");
int n , m;
short a[1001][1001];
int  x[1000001], y[1000001];
char P[1001][1001];
int nrechipe;
const int dx[] = {0 , 0 , 1 , -1}, 
          dy[] = {1 , -1 , 0 , 0};
void fill(int istart , int jstart , int nrz)
{
	//parcurgem zona curenta si determinam cate echipe sunt in ea
	int st = 1 , dr = 1;
	a[istart][jstart] = nrz;
	x[1] = istart, y[1] = jstart;
	nrechipe = 0;
	while(st <= dr)
	{
		int i = x[st], j = y[st];
		for(int k = 0 ; k < 4 ; k ++)
		{
			int ii = i + dx[k], jj = j + dy[k];
			if( ii > 0 && ii <= n && jj > 0 && jj <= m && P[ii][jj] != '#' && a[ii][jj] == 0)
			{
				dr ++;
				x[dr] = ii, y[dr] = jj;
				a[ii][jj] = nrz;
			}
		}
		if(P[i][j] == 'P')
			nrechipe ++;
		st ++;
	}
}
int main(){
	fin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			fin >> P[i][j];
	fin.close();
	int nrzone = 0 , echipe_in_plus = 0;
	int nrz = 0;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			if(a[i][j] == 0 && P[i][j] != '#')
			{
				nrz ++;
				fill(i, j, nrz);
				if(nrechipe == 0)
				{
					nrzone ++;
				}
				else
					echipe_in_plus += nrechipe - 1;
			}
	if(echipe_in_plus >= nrzone)
		fout << nrzone;
	else
		fout << echipe_in_plus + 2 * (nrzone - echipe_in_plus);
	fout.close();
	return 0;
}