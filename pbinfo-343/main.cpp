#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
ifstream fin("soarece1.in");
ofstream fout("soarece1.out");
int n,m,is,js,ib,jb,a[11][11], nrsol = 0;
const int di[]={0,0,1,-1}, dj[]={1,-1,0,0};
void afis(){
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
	if(nrsol==0)
		if(i>0 && i<=n && j>0 && j<=m && a[i][j]==0)
		{
			a[i][j] = pas;
			if(i==ib && j==jb)
				afis();
			else
				for(int k=0;k<4;++k)
					back(i+di[k], j+dj[k], pas+1);
			a[i][j] = 0;
		}
}
int main()
{
	fin >> n >> m;
	char c;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			fin >> c;
			if(c=='S')
				is = i, js = j;
			if(c=='B')
				ib = i, jb = j;
			if(c=='#')
				a[i][j] = -1;
			if(c=='_')
				a[i][j] = 0;
		}
	back(is, js, 1);
	if(nrsol==0)
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)
				fout << 0 << " ";
			fout << endl;
		}
	return 0;
}