#include <fstream>
using namespace std;
ifstream fin("radiera.in");
ofstream fout("radiera.out");
const int MaxN = 1001;
int a[MaxN], L[MaxN], Lmax, N;
void Cmlsc();
int main()
{
    fin >> N;
    for(int i = 1; i <= N; ++i)
        fin >> a[i];
    Cmlsc();
    fout << N - Lmax;
    return 0;
}
void Cmlsc()
{
	for (int i = 1; i <= N; ++i)
	{
		L[i] = 1;
		for (int j = 1; j < i; ++j)
			if (L[i] < L[j] + 1 && a[j] <= a[i])
				L[i] = L[j] + 1;
		Lmax = max(Lmax, L[i]);
	}
}