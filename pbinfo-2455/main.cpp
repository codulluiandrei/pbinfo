/*
    prof. Constantin Galatan
    solutie O(K * log T)
*/
#include <fstream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

ifstream fin("plaja2.in");
ofstream fout("plaja2.out");

using LL = long long;
using VLL = vector<LL>;
int N, K, T;
VLL d, t;

bool Try(LL t0, int i);

int main()
{
	fin >> N >> K >> T;
	d = t = VLL(K + 1);

	for (int i = 1; i <= K; ++i)
		fin >> d[i] >> t[i];

	for (int i = 1; i < K; ++i)
		t[i + 1] = min(t[i + 1], t[i] + (d[i + 1] - d[i]) * T);

	for (int i = K - 1; i >= 1; --i)
		t[i] = min(t[i], t[i + 1] + (d[i + 1] - d[i]) * T);

	LL res = 0, l, r, m, tmp;

	for (int i = 1; i < K; ++i)
	{
		l = max(t[i], t[i + 1]), r = 1LL * N * T;
		while (l <= r)
		{
			m = (l + r) / 2;
			if (Try(m, i))
			{
				l = m + 1;
				tmp = m;
			}
			else
				r = m - 1;
		}
		res = max(res, tmp);
	}
	res = max(res, max(t[K] + (N - d[K]) * T, t[1] + (d[1] - 1) * T));
	fout << res;

}

bool Try(LL t0, int i)
{
	return d[i + 1] - d[i] >= (t0 - t[i] + T - 1) / T + (t0 - t[i + 1] + T - 1) / T;
} 