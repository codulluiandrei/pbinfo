#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;
ifstream fin("secv2.in");
ofstream fout("secv2.out");
const int NMAX = 200000 + 5;
int n , k , A[NMAX];
int E[1000001];
int main()
{
	E[0] = E[1] = 1;
	for(int i = 2 ; i * i <= 1000000 ; i ++)
		if(E[i] == 0)
			for(int j = 2 * i  ; j <= 1000000 ; j += i)
				E[j] = 1;
	fin >> n >> k;
	for(int i = 1; i <= n ; i ++)
	{
		int x;
		fin >> x;
		A[i] = E[x];
	}
	int cnt = 0, i = 0, L = 0, I = 0;
	for(int j = 1 ; j <= n ; j ++)
	{
		if(A[j] == 1)
			cnt ++;
		while(cnt > k)
		{
			i ++;
			if(A[i] == 1)
				cnt --;
		}
		if(j - i > L)
			L = j - i , I = i + 1;
	}
	fout << L << " " << I << '\n';
	cout << L << " " << I << '\n';
	return 0;
}