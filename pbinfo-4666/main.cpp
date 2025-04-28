#include <bits/stdc++.h>
using namespace std;
#ifndef LOCAL
ifstream in("apgreid.in");
ofstream out("apgreid.out");
#define cin in
#define cout out
#endif // LOCAL
const int mod = 1e9 + 7;
int lgpow(int b, int e) {
	int ret = 1;
	while(e) {
		if(e & 1) ret = (1LL * ret * b) % mod;
		b = (1LL * b * b) % mod;
		e /= 2;
	}
	return ret;
}
bool cmp(pair<char, int> a, pair<char, int> b) {
	if(a.first != b.first) {
		map<char, int> ord;
		ord['p'] = 0;
		ord['n'] = 1;
		ord['c'] = 2;
		return ord[a.first] < ord[b.first];
	}
	return a.second < b.second;
}
int main() {
	int c; cin >> c;
	int n, p; cin >> n >> p;
	vector<pair<char, int>> obj(n);
	for(auto &e : obj) {
		cin >> e.first >> e.second;
	}
	if(c == 1) {
		map<char, int> maxims;
		for(auto e : obj) {
			maxims[e.first] = max(maxims[e.first], e.second);
		}
		cout << maxims['c'] << ' ';
		cout << maxims['p'] << ' ';
		cout << maxims['n'];
	}
	if(c == 2) {
		sort(obj.begin(), obj.end(), cmp);
		for(int i = 0; i < obj.size(); i++) {
			cout << obj[i].first << ' ' << obj[i].second;
			if(i < obj.size() - 1) cout << '\n';
		}
	}
	if(c == 3) {
		sort(obj.begin(), obj.end(), cmp);
		for(auto e : obj) {
			char tip; int val;
			tip = e.first; val = e.second;
			if(tip == 'p') p = (1LL * p + val) % mod;
			if(tip == 'n') p = (1LL * p * val) % mod;
			if(tip == 'c') p = (1LL * lgpow(p, val)) % mod;
		}
		cout << p << '\n';
	}
}