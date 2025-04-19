#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("secventa4.in");
ofstream fout("secventa4.out");
int n, A[100001];
int main()
{
	fin >> n;
	for(int i = 1; i <= n ; i ++)
		fin >> A[i];
	int st = 1 , dr = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		int j = i;
		while(j + 1 <= n && A[j] % 10 == A[j+1] % 10)
			j ++;
		if(j-i+1 > dr-st+1)
			st = i, dr = j;
		i = j;
	}
	fout << st << " " << dr;
	return 0;
}