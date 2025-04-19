#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("iesire.in");
ofstream fout("iesire.out");
int n,m, a[102][102];
const int dx[]={0 , 0 , 1 , -1}, dy[]={1 , -1 , 0 , 0};
bool fill(int i , int j , int valoare_veche , int valoare_noua)
{
	a[i][j] = valoare_noua;
	if( i == 1 || i == n || j == 1 || j == n)
		return true;
	bool rez = false;
	for(int k = 0 ; k < 4 ; k ++)
		if(a[i+dx[k]][j+dy[k]] == valoare_veche)
			rez = rez || fill(i+dx[k] , j+dy[k] , valoare_veche, valoare_noua);
	return rez;
}
void fill2(int i , int j , int valoare_veche , int valoare_noua)
{
	a[i][j] = valoare_noua;
	for(int k = 0 ; k < 4 ; k ++)
		if(a[i+dx[k]][j+dy[k]] == valoare_veche)
			fill2(i+dx[k] , j+dy[k] , valoare_veche, valoare_noua);
}
int main(){
	fin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			fin >> a[i][j];
	//bordare , chiar daca este inutila pentru aceasta problema
	for(int i = 0 ; i <= n + 1 ; i ++)
		a[i][0] = a[i][n+1] = 1;
	for(int j = 0 ; j <= n + 1; j ++)
		a[0][j] = a[n+1][j] = 1;
	for(int k = 1 ; k <= m ; k ++)
	{
		int i , j ;
		fin >> i >> j;
		if(a[i][j] == 1)
			fout << "nu\n";
		else
		{
			if(fill(i , j , 0 , 2))
				fout << "da\n";
			else
				fout << "nu\n";
			fill2(i , j , 2 , 0);
		}
	}
	fout.close();
	fin.close();
	return 0;
}