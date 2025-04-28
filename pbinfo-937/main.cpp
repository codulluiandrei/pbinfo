#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
ifstream fin("hercule.in");
ofstream fout("hercule.out");
int n, m, a[25][25], b[25][25], nrsol = 0;
const int di[]={0,0,1,-1}, dj[]={1,-1,0,0};
void afis(){
	nrsol++;
	return;
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j)
			cout << b[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}
void back(int i, int j, int pas)
{
	if(i >= 1 && i <= n && j >= 1 && j <= m && pas <= a[i][j] && b[i][j] == 0)
	{
		b[i][j] = pas;
		if(i == n && j == m)
			nrsol++;
		else
			for(int k = 0 ; k < 4 ; ++k)
				back(i + di[k], j + dj[k], pas + 1);
		b[i][j] = 0;
	}
}
int main()
{
	fin >> n >> m;
	for(int i = 1 ; i <= n ; ++i)
		for(int j = 1 ; j <= m ; ++j)
			fin >> a[i][j];
	back(1, 1, 1);
	fout << nrsol;
	//cout << nrsol;
	return 0;
}