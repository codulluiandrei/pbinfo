// O(n) - 100 puncte - prof.Dan Pracsiu
#include<fstream>
#include<iostream>
#define inFile  "maxp.in"
#define outFile "maxp.out"
#define dim 200001

using namespace std;

int a[dim], st[dim], dr[dim], q[dim], poz[dim], n;

int main()
{
	int i, k, x, nrsol;
	long long p, pmax;
	//citire
	ifstream fin(inFile);
	fin >> n;
	for (i = 1; i <= n; i++)
		fin >> a[i];
	fin.close();
	
	// constructie st
	k = 0;
	q[k] = dim + 2;
	poz[k] = 0;
	st[k] = 0;
	for (i = 1; i <= n; i++)
	{
		x = a[i];
		while (q[k] < x) k--;
		st[i] = i - poz[k] - 1;
		k++;
		q[k] = x;
		poz[k] = i;
	}
	
	// constructie dr
	k = 0;
	q[k] = dim + 2;
	poz[k] = n + 1;
	dr[k] = 0;
	for (i = n; i >= 1; i--)
	{
		x = a[i];
		while (q[k] < x) k--;
		dr[i] = poz[k] - i - 1;
		k++;
		q[k] = x;
		poz[k] = i;
	}

	// calcul
	nrsol = 1;
	pmax = (st[1] + 1);
	pmax *= (dr[1] + 1);
	for (i = 2; i <= n; i++)
	{
		p = (st[i] + 1);
		p = (p * (dr[i] + 1));
		if (p > pmax)
		{
			pmax = p;
			nrsol = 1;
		}
		else if (p == pmax) nrsol++;
	}
	
	ofstream fout(outFile);
	fout << pmax << "
" << nrsol << "
";
	fout.close();
	
	return 0;
}
