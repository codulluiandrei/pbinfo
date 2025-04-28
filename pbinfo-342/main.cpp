#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
ifstream fin("soarece.in");
ofstream fout("soarece.out");
int n,m,is,js,ib,jb,a[11][11], nrsol = 0;
const int di[]={0,0,1,-1}, dj[]={1,-1,0,0};
void afis(){
	nrsol++;;
	//for(int i=1;i<=n;++i){
	//	for(int j=1;j<=m;++j)
	//		cout << setw(3) << a[i][j];
	//	cout << endl;
	//}
	//cout << endl;
}
void back(int i,int j, int pas)
{
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
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			fin >> a[i][j], a[i][j] = -a[i][j];
	fin >> is >> js >> ib >> jb;
	back(is, js, 1);
	fout << nrsol;
	return 0;
}