#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("saritura_calului1.in");
ofstream fout("saritura_calului1.out");
int n, m, istart, jstart, a[105][105], best[105][105], bestpas;
const int di[]={2, 2,1, 1,-1,-1,-2,-2},
		  dj[]={1,-1,2,-2, 2,-2, 1,-1};
int x[8]={0,1,2,3,4,5,6,7};
int numar(int i,int j)
{
	int s = 0 , ii , jj;
	for(int k=0 ; k<8 ; ++k)
	{
		ii = i + di[x[k]], jj = j + dj[x[k]];
		if(ii>0 && ii <=n && jj>=1 && jj<=m && a[ii][jj]==0)
			s ++;
	}
	return s;
}
void greedy(int strict = 0)
{
	for(int i=1 ; i<=n ; ++i)
		for(int j=1 ; j<=m ; ++j)
			a[i][j] = 0;
	int pas = 1;
	int i = istart , j = jstart;
	while(1)
	{
		a[i][j]=pas;
		int min = 10, poz=-1;
		for(int k=0;k<8;++k)
		{
			int ii = i+di[x[k]], jj = j + dj[x[k]];
			if(ii>0 && ii <=n && jj>=1 && jj<=m && a[ii][jj]==0)
			{
				int nr = numar(ii,jj);
				if(strict){
					if(nr < min)
						min = nr, poz = k;
				}
				else
					if(nr <= min)
						min = nr, poz = k;
			}
		}
		if(min == 10)
			break;
		else
			i = i + di[poz], j = j + dj[poz], pas++;
	}
	if(pas > bestpas){
		bestpas = pas;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				best[i][j] = a[i][j];
	}
}
int main(){
	fin >> n >> m >> istart >> jstart;
	greedy();
	if(bestpas!=n*m)
		greedy(1);
	for(int i=1 ; i<=n ; ++i){
		for(int j=1 ; j<=m ; ++j)
			fout << best[i][j] << " ";
		fout << endl;
	}
	return 0;
}