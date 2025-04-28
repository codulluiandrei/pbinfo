#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("nrfii.in");
ofstream fout("nrfii.out");
int n , t[105], nr[105];
int main()
{
	fin >> n;
	for(int i = 1 ; i <= n ; i ++)
		fin >> t[i];
	for(int i = 1 ; i <= n ; i ++)
		if(t[i] != 0)
			nr[t[i]] ++;
	int max = nr[1];
	for(int i = 2 ; i <= n ; i ++)
		if(nr[i] > max)
			max = nr[i];
	for(int i = 1 ; i <= n ; i ++)
		if(nr[i] == max)
			fout << i << " ";
	return 0;
}