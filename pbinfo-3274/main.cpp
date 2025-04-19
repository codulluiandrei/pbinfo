#include<fstream>
#define InFile "secvb.in" 
#define OutFile "secvb.out" 
using namespace std ;
int N, T ;
int a[50001] ; // in a[i] se memoreaza pentru fiecare x[i] numarul bitilor de 1
int main()
{
	int i, k, x, st, dr, s;
	ifstream fin(InFile);
	fin >> N >> T ;
	for (i = 0 ; i < N; i++)
	{
		fin >> x;
		k = 0;
		while (x > 0)
		{
			k += (x % 2);
			x /= 2 ;
		}
		a[i] = k ;
	}
	fin.close() ;
	s = k = st = dr = 0;
	for (dr=0 ; dr<N ; dr++)
	{
		s += a[dr] ;
		while (s >= T)
		{	
			if (s == T) k++;
			s -= a[st];
			st++;
		}
	}
	ofstream fout(OutFile) ;
	fout << k << "\n" ;
	fout.close();
	return 0 ;
}