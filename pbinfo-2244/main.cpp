#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
ifstream fin("traseucalmax.in");
ofstream fout("traseucalmax.out");
int n,m,is,js,ib,jb,a[11][11], tmax[11][11], dmax = 0,  ical, jcal, ifan, jfan;
const int   di[]={2, 2, 1, 1,-1,-1,-2,-2}, 
            dj[]={1,-1, 2,-2, 2,-2, 1,-1};
void afis(int a[][11], ostream & out){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)
			if(a[i][j]<1)
				out << 0 << " ";
			else
				out << a[i][j] << " ";
		out << endl;
	}
}
void back(int i,int j, int pas)
{
        if(i>0 && i<=n && j>0 && j<=m && a[i][j]==0)
		{
			a[i][j] = pas;
            if(i == n && j == m)
            {
				if(pas > dmax)
				{
					dmax = pas;
					for(int i =1 ; i <= n ; i ++)
						for(int j =1 ; j <= m ; j ++)
							tmax[i][j] = a[i][j];
				}
			}
			else
				for(int k = 0 ; k < 8; ++k)
					back(i+di[k], j+dj[k], pas+1);
			a[i][j] = 0;
		}
}
int main()
{
	fin >> n >> m;
	for(int i = 1 ; i <= n ; ++i)
		for(int j = 1 ; j <= m ; ++j)
		{
			fin >> a[i][j];
			a[i][j] *= -1;
		}
    back(1, 1, 1);
    afis(tmax, fout);
	return 0;
}