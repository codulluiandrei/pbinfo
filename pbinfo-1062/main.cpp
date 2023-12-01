#include <fstream>
using namespace std;

ifstream fin("flori1.in");
ofstream fout("flori1.out");

int N, K, H;
int h[100];
int S;

int main()
{
	fin >> N >> H;
	for ( int i = 0; i < N; ++i )
	{
		fin >> h[i];
		S += h[i];
	}
	// Cerinta a)
	for (int i = 1; i <= N; ++i )
		S += i;
	fout << S << '\n';

	// Cerinta b)
	bool ok = true;
	while ( ok )
	{
		for ( int i = 0; i < N - 1; ++i )
			for ( int j = i + 1; j < N; ++j )
				if ( h[i] > h[j] )
				{
					int aux = h[i];
					h[i] = h[j];
					h[j] = aux;
				}

		for (int i = 0; i <= K && ok; ++i )
			if ( h[i] + 1 >= H )
				ok = false;

		if ( ok )
		{
			for (int i = 0; i <= K; ++i )
				h[i]++;
			K++;
		}
	}

	fout << K << '\n';

	fin.close();
	fout.close();
	return 0;
}
