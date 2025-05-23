#include <bits/stdc++.h>
#define st first
#define nd second
using namespace std;
void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
const int N = 2005;
const int K = 2005;
int n, k;
int a[N], b[N], dp[N][K];
string s;
int main() {
	//ios_base::sync_with_stdio(false);
	freopen("becuri.in", "r", stdin);
	freopen("becuri.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		cin >> b[i];
	for(int i = 1; i <= k; i++)
		dp[0][i] = -1000000000;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= k; j++)
			dp[i][j] = -1000000000;
		for(int j = 0; j <= k; j++) {
			dp[i][min(j + a[i], k)] = max(dp[i][min(j + a[i], k)], dp[i - 1][j]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j] + b[i]);
		}
		// dbg_v(dp[i], k + 1);
	}
	cout << max(dp[n][k], -1) << '\n';
} 