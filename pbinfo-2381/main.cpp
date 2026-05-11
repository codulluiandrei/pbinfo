#include<fstream>
#define dim 3001
#define InFile  "petrecere.in"
#define OutFile "petrecere.out"
using namespace std ;
int a[dim], b[dim], c[dim], na, nb, nc, n ;
void Citire()
{
	ifstream fin(InFile) ;
	fin>>n ;
	fin.close() ;
}
void Aduna(int *a, int na, int *b, int nb, int *c, int &nc)
{
	int i, t ;
	nc = na > nb ? na : nb ;
	t = 0 ;
	for (i=0 ; i<nc ; i++)
	{
		c[i] = a[i] + b[i] + t ;
		if (c[i] > 9)
		{
			c[i] -= 10 ;
			t = 1 ;
		}
		else t = 0 ;
	}
	if (t > 0)
		c[nc++] = 1 ;
}
void Copie(int *a, int &na, int *b, int nb)
{
	int i ;
	na = nb ;
	for (i=0 ; i<na ; i++)
		a[i] = b[i] ;
}
void Produs(int *a, int &na, int x)
{
	int i, t, p ;
	t = 0 ;
	for (i=0 ; i<na ; i++)
	{
		p = a[i] * x + t ;
		a[i] = p % 10 ;
		t = p / 10 ;
	}
	while (t > 0)
	{
		a[na++] = t %10 ;
		t /= 10 ;
	}
}
void Calcul()
{
	int i ;
	ofstream fout(OutFile) ;
	if (n == 1)
	{
		fout<<"1\n" ;
		fout.close() ;
		return ;
	}
	if (n == 2)
	{
		fout<<"2\n" ;
		fout.close() ;
		return ;
	}
	a[0] = 1 ;
	b[0] = 2 ;
	na = nb = 1 ;
	for (i=3 ; i <= n ; i++)
	{
		Produs(a, na, i-1) ;
		Aduna(a, na, b, nb, c, nc) ;
		Copie(a, na, b, nb) ;
		Copie(b, nb, c, nc) ;
	}
	for (i=nc-1 ; i>=0 ; i--)
		fout<<c[i] ;
	fout<<"\n" ;
	fout.close() ;
}
int main()
{
	Citire() ;
	Calcul() ;
	return 0 ;
}