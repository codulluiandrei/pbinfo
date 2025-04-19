/* 
   Complexitate O (N x N)
*/
#include<fstream>
#define inFile  "split.in"
#define outFile "split.out"
#define Dim 10005
using namespace std;
int a[Dim], minst[Dim], mindr[Dim], maxdr[Dim], maxst[Dim], n;
int main()
{
	int i, j, k, x, di, dk, maxim, minim, xi, xj, xk;
	int solst, soldr, solmax;
	// citire
	ifstream fin(inFile);
	fin >> n;
	for (i = 1; i <= n; i++)
		fin >> a[i];
	fin.close();
	//min max stg
	minst[1] = maxst[1] = a[1];
	for (i = 2; i <= n; i++)
	{
		if (a[i] > maxst[i-1]) maxst[i] = a[i];
		else maxst[i] = maxst[i-1];
		if (a[i] < minst[i-1]) minst[i] = a[i];
		else minst[i] = minst[i-1];
	}
	//min max drp
	mindr[n] = maxdr[n] = a[n];
	for (i = n - 1; i >= 1; i--)
	{
		if (a[i] > maxdr[i+1]) maxdr[i] = a[i];
		else maxdr[i] = maxdr[i+1];
		if (a[i] < mindr[i+1]) mindr[i] = a[i];
		else mindr[i] = mindr[i+1];
	}
	// calcul
	solmax = 0;
	di = dk = 0;
	xi = 2; xj = 4; xk = 6;
	for (j = 4; j <= n - 3; j++)
	{
		// maximul din stanga: i=2..j-2
		if (a[j] > a[j - 1])
		{
			maxim = a[j];
			minim = a[j - 1];
		}
		else
		{
			maxim = a[j - 1];
			minim = a[j];
		}
		solst = maxim - minim + maxst[j-2] - minst[j-2];
		di = j - 2;
		for (i = j - 2; i > 2; i--)
		{
			if (a[i] > maxim) maxim = a[i];
			if (a[i] < minim) minim = a[i];
			x = maxim - minim + maxst[i-1] - minst[i-1];
			if (solst <= x) { solst = x; di = i-1;}
		}
		//maximul din dreapta k=j+2..n-2
		if (a[j+1] > a[j+2])
		{
			maxim = a[j+1];
			minim = a[j+2];
		}
		else
		{
			maxim = a[j+2];
			minim = a[j+1];
		}
		soldr = maxim - minim + maxdr[j+3] - mindr[j+3];
		dk = j + 2;
		for (k = j + 3; k <= n - 2; k++)
		{
			if (a[k] > maxim) maxim = a[k];
			if (a[k] < minim) minim = a[k];
			x = maxim - minim + maxdr[k+1] - mindr[k+1];
			if (soldr < x) { soldr = x; dk = k;}
		}
		x = solst + soldr;
		if (x > solmax) 
		{
			solmax = x;
			xi = di; 
			xj = j;
			xk = dk;
		}
	}
	ofstream fout(outFile);
	fout << solmax << "\n";
	fout << xi << " " << xj << " " << xk << "\n";
	fout.close();
	return 0;
}