#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("crb.in");
ofstream fout("crb.out");
int n, v[1005], u[1005];
int main()
{
	fin >> n ;
	for(int i =1 ; i <= n ; ++i)
		fin >> v[i];
	for(int i =1 ; i <= n ; ++i)
		u[i] = v[i];
	for(int i =1 ; i < n ; i ++)
		for(int j = i + 1 ; j <= n ; j ++)
			if(u[i] < u[j])
			{
				int aux= u[i];
				u[i] = u[j];
				u[j] = aux;
			}
	int C = 0;
	for(int i = 1 ; i <= n ; ++i)
		if(u[i] == v[i])
			C ++;
	fout << C;
	return 0;
}