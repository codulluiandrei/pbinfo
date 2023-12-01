/*
   Implementare : prof. Dan Pracsiu
*/

#include<fstream>

using namespace std ;

int prime[200], a[100001], n, k, maxL ;

void Ciur()
{
	int i, j ;
	for(i=4; i<=1000 ; i+=2)
		a[i] = 1 ;
	k = 0 ;
	prime[k++] = 2;
	for (i = 3 ; i <= 1000 ; i++)
		if (a[i] == 0)
		{
			prime[k++] = i;
			for (j=i*i ; j <= 1000 ; j = j + 2*i)
				a[j] = 1 ;
		}
}

void Citire()
{
	ifstream fin("cmmdcsecv.in") ;
	fin >> n ;
	for (int i = 0 ; i < n ; i++)
		fin >> a[i] ;
	fin.close(); 
}

int Calcul(int x)
{
	int i, lung, lungmax ;
	lungmax = 0 ;
	i = 0 ;
	while (i < n)
		if (a[i] % x != 0) i++ ;
		else
		{
			i++ ;
			lung = 1 ;
			while (a[i] % x == 0 && i < n)
				{ i++ ; lung++ ; }
			if (lung > lungmax) lungmax = lung ;
		}
	return lungmax ;
}

void DetSol()
{
	int i, p ;
	maxL = 0 ;
	for (i = 0 ; i < k ; i++)
	{
		p = Calcul(prime[i]) ;
		if (maxL < p) maxL = p ;
	}
	
	ofstream fout("cmmdcsecv.out") ;
	fout << maxL << "\n" ;
	fout.close() ;
}

int main()
{
	Ciur() ;
	Citire() ;
	DetSol() ;
	
	return 0 ;
}
