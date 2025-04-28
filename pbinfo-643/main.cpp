#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("detdrum1.in");
ofstream fout("detdrum1.out");
int n , k , t[105];
void drum(int k)
{
	if(k != 0)
	{
		drum(t[k]);
		fout << k << " ";
	}
}
int main()
{
	fin >> n >> k;
	for(int i = 1 ; i <= n ; i ++)
		fin >> t[i];
	drum(k);
	return 0;
}