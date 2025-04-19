/*
	dreptel (si chiar punctele se pot suprapune)
	fie NrO = numarul de drepte orizontale si NrV = numarul de drepte verticale
	Atunci rezultatul este (NrO - 1) * (NrV - 1)
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("dreptunghiuri.in");
ofstream fout("dreptunghiuri.out");
int n, x[1005], y[1005];
int main()
{
	fin >> n ;
	for(int i = 1 ; i <= n ; ++i)
		fin >> x[i] >> y[i];
	x[0] = 0; y[0] = 0; // axele de coordonate
	// pentru a afla cate drepte verticale diferite avem, determinam 
	// numarul de valori diferite din x[]. Pentru aceasta, sortam vectorul 
	// si numaram cate secvente de elemente egale exista
	//		Similar pentru dreptele orizontale
	for(int i = 0 ; i < n ; ++i)
		for(int j = i + 1; j <= n ; ++j)
			if(x[i] > x[j])
			{
				int aux = x[i]; x[i] = x[j] ; x[j] = aux;
			}
	int NrV = 1;
	for(int i = 1 ; i <= n ; ++i)
		if(x[i] !=x[i-1])
			NrV ++;
	for(int i = 0 ; i < n ; ++i)
		for(int j = i + 1; j <= n ; ++j)
			if(y[i] > y[j])
			{
				int aux = y[i]; y[i] = y[j] ; y[j] = aux;
			}
	int NrO = 1;
	for(int i = 1 ; i <= n ; ++i)
		if(y[i] !=y[i-1])
			NrO ++;
	fout << (NrV - 1) * (NrO - 1);
	return 0;
}