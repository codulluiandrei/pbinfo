#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
ifstream fin("traseucal.in");
ofstream fout("traseucal.out");
int n,m,is,js,ib,jb,a[11][11], nrsol = 0;
const int   di[]={2, 2, 1, 1,-1,-1,-2,-2}, 
            dj[]={1,-1, 2,-2, 2,-2, 1,-1};
void afis(int a[][11]){
	nrsol++;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)
			if(a[i][j]<1)
				fout << 0 << " ";
			else
				fout << a[i][j] << " ";
		fout << endl;
	}
}
void back(int i,int j, int pas)
{
        if(i>0 && i<=n && j>0 && j<=m && a[i][j]==0)
		{
			a[i][j] = pas;
            //afis(a);
            if(i==n && j==m)
				afis(a);
			else
				for(int k = 0 ; k < 8 && nrsol == 0 ; ++k)
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
	if(nrsol == 0)
		for(int i = 1 ; i <= n ; ++i)
        {
			for(int j = 1 ; j <= m ; ++j)
				fout << 0 << " ";
			fout << endl;
		}
	return 0;
}