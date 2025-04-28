#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("croco1.in");
ofstream fout("croco1.out");
int n,m, a[102][102];
const int dx[]={0 , 0 , 1 , -1}, dy[]={1 , -1 , 0 , 0};
int C, E , EA , CA;
void fillA(int i , int j , int v)
{
	if(v == 2)
		CA ++;
	else
		EA ++;
	a[i][j] = v;
	for(int k = 0 ; k < 4 ; k ++)
		if(a[i+dx[k]][j+dy[k]] == 0)
		{
			if(v == 2)
				fillA(i+dx[k] , j+dy[k] , 3);
			else
				fillA(i+dx[k] , j+dy[k] , 2);
		}
}
int main(){
	fin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			fin >> a[i][j] ;
	fin.close();
	//bordare cu 1 = obstacol, sa nu iesim din matrice
	for(int i = 0 ; i <= n + 1 ; i ++)
		a[i][0] = a[i][m+1] = 1;
	for(int j = 0 ; j <= m + 1; j ++)
		a[0][j] = a[n+1][j] = 1;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; ++j)
			if(a[i][j] == 0)
			{
				EA = CA =  0;
				fillA(i , j , 3);
				if(CA > EA)
					C += CA, E += EA;
				else
					C += EA, E += CA;
			}
	fout << C << " " << E;
	fout.close();
	return 0;
}