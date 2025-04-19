#include <bits/stdc++.h>
using namespace std;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());
	vector<int> ans(n);
	bool bad = false;
	for (int i = 0; i < n/2; ++i) {
		ans[i*2] = v[i];
		ans[i*2+1] = v[n/2+i];
		if (ans[i*2] == ans[i*2+1])
			bad = true;
	}
	if (n%4 == 2)
		swap(ans[n-2], ans[n-1]);
	if (bad)
		sort(ans.begin(), ans.end());
	for (auto x : ans)
		cout << x << " ";
	cout << "\n";
	return 0;
}