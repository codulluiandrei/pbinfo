#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("eureni.in");
ofstream fout("eureni.out");

int v[20], x[20], S, n , e;

int main()
{
	fin >> S >> n >> e;
	v[0] = 1;
	for(int i = 1 ; i <= n ; i++)
		v[i] = v[i-1] * e;
	for(int i = n ; i >= 0 ; i --)
	{
		x[i] = S / v[i];
		S %= v[i];
	}
	
	S = 0;
	for(int i = n ; i >= 0 ; i --)
		if(x[i] > 0)
		{
			fout << v[i] << " " << x[i] << endl;
			S += x[i];
		}
	fout << S << endl;
	return 0;
}
