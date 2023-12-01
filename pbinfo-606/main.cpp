#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("culori.in");
ofstream fout("culori.out");

int n , v[1005], c[1005], nrc;

int main()
{
	fin >> n ; 
	for(int i = 1 ;i <= n ; ++i)
		fin >> v[i];
	nrc = 1, c[1] = v[1];
	bool frumos = true;
	for(int i = 2 ; i <= n ; ++i)
		if(v[i] != v[i-1])
		{
			int poz = 0;
			for(int j = 1 ; j <= nrc && !poz ; j ++)
				if(c[j] == v[i])
					poz = j;
			if(poz == 0)
				c[++nrc] = v[i];
			else
				frumos = false;
		}
	fout << nrc << "
";
	if(frumos)
		fout << "DA";
	else
		fout << "NU";
	return 0;
}
