#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("fill.in");
ofstream fout("fill.out");
int n,m, a[102][102];
const int dx[]={0 , 0 , 1 , -1}, dy[]={1 , -1 , 0 , 0};
void fill(int i , int j , int valoare)
{
	a[i][j] = valoare;
	for(int k = 0 ; k < 4 ; k ++)
		if(a[i+dx[k]][j+dy[k]] == -1)
			fill(i+dx[k] , j+dy[k] , valoare);
}
int main(){
	fin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			fin >> a[i][j] , a[i][j] = - a[i][j];
	fin.close();
	//bordare , chiar daca este inutila pentru aceasta problema
	for(int i = 0 ; i <= n + 1 ; i ++)
		a[i][0] = a[i][m+1] = 0;
	for(int j = 0 ; j <= m + 1; j ++)
		a[0][j] = a[n+1][j] = 0;
	//cautam valorile -1, le numaram si facem fill
	int cnt = 0;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			if(a[i][j] == -1)
			{
				cnt ++;
				fill(i , j , cnt);
			}
	fout << cnt ;
	fout.close();
	return 0;
}