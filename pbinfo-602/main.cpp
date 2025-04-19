//regine
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("regine.in");
ofstream fout("regine.out");
const int di[]={-1,-1,-1, 0, 0, 1, 1, 1},
		  dj[]={-1, 0, 1,-1, 1,-1, 0, 1};
int a[105][105], n, m ;
int main(){
	fin  >> n >> m ;
	for(int k = 1 ; k <= m ; ++k)
	{
		int i ,j ;
		fin >> i >> j;
		a[i][j] = 1;
	}
	int  p = 0 , q = 0;
	for(int i =1 ; i <= n ; ++i)
		for(int j =1 ; j <= n ; ++j)
			if(a[i][j] == 1)
			{
				int cnt = 0;
				for(int k = 0 ; k < 8 ; k ++)
				{
					int x = 1;
					while(i + di[k] * x > 0 && i + di[k] * x <= n && j + dj[k] * x > 0 && j + dj[k] * x <= n && a[i + di[k] * x][j + dj[k] * x] == 0)
						x ++;
					if(a[i + di[k] * x][j + dj[k] * x] == 1)
						cnt ++;
				}
				if(cnt > p)
					p = cnt, q = 1;
				else
					if(cnt == p)
						q ++;
			}
	fout << p << " " << q << endl;
	return 0;
}