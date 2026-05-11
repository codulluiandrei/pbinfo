/// Solutie - Moca Andrei - 100p
#include <bits/stdc++.h>
using namespace std;
const int mod = 666013;
map<int, bool> M;
map<int, int> poz;
int aib[111][111111], x, n, K, res, cnt;
inline void Update(int k, int poz, int val)
{
	for (int i = poz; i <= n; i += i & -i)
	{
		aib[k][i] += val;
		if (aib[k][i] > mod)
			aib[k][i] -= mod;
	}
}
inline int Query(int k, int poz)
{
	int s = 0;
	for (int i = poz; i > 0; i -= i & -i)
	{
		s += aib[k][i];
		if (s > mod)
			s -= mod;
	}
	return s;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> K;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> v[i], M[v[i]] = true;
	for (const auto& p : M)
        poz[p.first] = ++cnt;
    for (int i = 1; i <= n; ++i)
        v[i] = poz[v[i]];
    for (int i = 1; i <= n; ++i)
    {
        Update(1, v[i], 1);
		for (int k = 2; k <= K; ++k)
			Update(k, v[i], Query(k - 1, v[i] - 1));
    }
	cout << Query(K, n);
	return 0;
}