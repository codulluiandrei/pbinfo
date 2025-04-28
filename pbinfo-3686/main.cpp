#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n+3, vector<int> (m+3, 0));
	auto pr = v;
	auto diagleft = v;
	auto diagright = v;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> v[i][j];
	for (int i = n; i >= 1; --i) {
		for (int j = 1; j <= m+1; ++j) {
			diagleft[i][j] = diagleft[i+1][j-1] + v[i][j];
			diagright[i][j] = diagright[i+1][j+1] + v[i][j];
		}
		diagright[i][0] = diagright[i+1][1] + v[i][0];
	}
	for (int i = n; i >= 1; --i) {
		for (int j = 2; j < m; ++j)
			pr[i][j] = pr[i+1][j-1] + pr[i+1][j+1] - pr[i+2][j] + v[i][j] + v[i+1][j]; 
		pr[i][1] = pr[i+1][1] + diagright[i][1];
		pr[i][m] = pr[i+1][m] + diagleft[i][m];
	}
	int mx = -1, I = -1, J = -1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			int d = min(i-1, j-1);
			d = min(d, n-i);
			d = min(d, m-j);
			int sum = pr[i-d][j] - pr[i+1][j-d] - pr[i+1][j+d] + pr[i+d+1][j] - diagleft[i+1][j-d-1] - diagright[i+1][j+d+1];
			if (sum > mx) {
				mx = sum;
				I = i;
				J = j;
			}
		}
	cout << I << " " << J << "\n";
	return 0;
}