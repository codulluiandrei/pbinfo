#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("anarhie.in");
ofstream fout("anarhie.out");
int n , m , K , p, q , a[105][105], 
	x[105], // backtracking
	z[105], // vector caracteristic, pentru sindicatele din submultimea curenta
	v[105], // vizitati pentru parcurgere
	rasp = 1000
	;
/*
 * Generez toate submultimile de sindicate, si pentru fiecare submultime verific 
 * daca poate fi parcurs traseul folosind doar sindicatele din acea submultime
 * O( 2^k * n^2)
 * */
void citire()
{
	fin >> n >> m >> K;
	fin >> p >> q;
	int i , j , s;
	for(int k = 1 ; k <= m ; ++k)
	{
		fin >> i >> j >> s;
		a[i][j] = s;
	}
}
int DF(int x)
{
	if(x == q)
		return 1;
	v[x] = 1;
	int rez = 0;
	for(int i = 1 ; i <= n ; ++i)
		if(v[i] == 0 && z[a[x][i]] == 1)
			rez |= DF(i);
	return rez;
}
int verif(int k)
{
	for(int i = 1 ; i <= n ; ++i)
		v[i] = z[i] = 0;
	for(int i = 1 ; i <= k ; ++i)
		z[x[i]] = 1;
	int pot = DF(p);
	return pot;
}
void back(int k)
{
	for(int i = x[k-1] + 1  ; i <= K ; i ++)
	{
		x[k] = i;
		if(verif(k))
		{
			if(rasp > k)
				rasp = k;
		}
		back(k+1);
	}
}
int main()
{
    citire();
    back(1);
    fout << rasp;
    return 0;
}