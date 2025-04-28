#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("detdrum2.in");
ofstream fout("detdrum2.out");
int n , p , q , t[105], dp[105], dq[105], np, nq;
void drum(int k , int d[], int &n)
{
	//determina in vectorul d[] drumul de la k la radacina
	if(k != 0)
	{
		n ++;
		d[n] = k;
		drum(t[k], d, n);
	}
}
int main()
{
	fin >> n >> p >> q;
	for(int i = 1 ; i <= n ; i ++)
		fin >> t[i];
	drum(p , dp , np);
	drum(q , dq , nq);
	while(dp[np-1] == dq[nq-1])
		np --, nq --;
	for(int i = 1 ; i < np ; i ++)
		fout << dp[i] << " ";
	for(int  i = nq ; i > 0 ; i --)
		fout << dq[i] << " ";
	return 0;
}