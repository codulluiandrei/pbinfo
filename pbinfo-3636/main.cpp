#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
ifstream iredirect;
ofstream oredirect;
const string file = "data";
const ll INF = 9223372036854775807ll;
const int dx[] = {1, -1, 0, 0, 1, 1, -1, -1}, dy[] = {0, 0, 1, -1, 1, -1, 1, -1}, inf = 2147483647;
void prepare_IO()
{
	#ifndef WATER_ADDICT
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	#else
		iredirect.open(file+".in");
		cin.rdbuf(iredirect.rdbuf());
		// oredirect.open(file+".out");
		// cout.rdbuf(oredirect.rdbuf());
	#endif
}
void solve()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	int ans = 0, mx = v[n-1], pos = n-1;
	for (int i = n-2; i >= 0; --i){
		if (v[i] >= mx) {
			mx = v[i];
			pos = i;
		}
		ans = max(ans, pos-i);
	}
	cout << ans << "\n";
}
signed main()
{
	prepare_IO();
	int number_of_tests = 1;
	cin >> number_of_tests;
	for (int testcase = 1; testcase <= number_of_tests; ++testcase)
		solve();
	return 0;
}