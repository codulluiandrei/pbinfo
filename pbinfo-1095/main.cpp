/*
	Recursie cu memoizare
	Complexitate: O(n * k)
	Constantin Galatan
*/
#include <fstream>
#include <climits>
using namespace std;
#define INF INT_MAX / 2
#define sus 0
#define dr  1
#define jos 2
ifstream fin("joc4.in");
ofstream fout("joc4.out");
int a[2][5001];
int n;
int K;
int s[2][5001][3][11];              // s[l][c][dir][k] - suma maxima pana la linia l, coloana c, daca s-a intrat in
                                    //                   celula din directia dir, cu k celule consecutive pe linia l
void Read();
int Sum(int l, int c, int d, int k);
int max(int a, int b);
int main()
{
	Read();
	fout << Sum(1, n - 1, dr, 1) << '\n';
	fout.close();
    return 0;
}
int Sum(int l, int c, int dir, int k)
{
	int& ret = s[l][c][dir][k];     // ret - alias pentru s[l][c][dir][k];
	if ( ret != -INF )              // Daca se trece printr-o stare anterior calculata
	 	return ret;                 // se returneaza valoarea din matrice
	if ( l == 0 && c == 0 ) return ret = a[0][0];
	if ( l == 1 && c == 0 ) return ret = a[l][c] + a[0][0];
	// Suma maxima se calculeaza in functie de linia curenta, directia din care s-a intrat in celula
	// si numarul de celule consecutive  parcurse pe linie
	int r(0);
	if ( l == 1 )
	{
		if ( dir == dr )
			if ( k < K  )
				r = max(Sum(l, c - 1, dr, k + 1), Sum(l - 1, c, jos, 1));
			else
				r = Sum(l - 1, c, jos, 1);
		if ( dir == sus )
			r = Sum(l, c - 1, dr, k + 1);
	}
	if ( l == 0 )
	{
		if ( dir == dr )
			if ( k < K )
				r = max(Sum(l, c - 1, dr, k + 1), Sum(l + 1, c, sus, 1));
			else
				r = Sum(l + 1, c, sus, 1);
		if ( dir == jos) r = Sum(l, c - 1, dr, k + 1);
	}
	return ret = r + a[l][c];
}
int max(int a, int b)
{
	if ( a >= b ) return a;
	return b;
}
void Read()
{
	int i(0), j(0);
	fin >> n >> K;
	for ( i = 0; i < 2; ++i )
		for ( j = 0; j < n; ++j )
			fin >> a[i][j];
	for ( i = 0; i < 2; ++i )
		for ( j = 0; j < n; ++j )
			for ( int d = 0; d < 3; ++d )
				for (int k = 0; k <= K; ++k )
				s[i][j][d][k] = -INF;
	fin.close();
}