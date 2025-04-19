#include <bits/stdc++.h>
#define st first
#define nd second
using namespace std;
const int N = 1000100;
int n, k, m, op, x;
int t[N], sz[3], where[N];
queue <pair<int, int> > q[3];
int main() {
	freopen("supermarket.in", "r", stdin);
	freopen("supermarket.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin >> n;
	assert(n <= 100000);
	for(int i = 1; i <= n; i++) {
		cin >> op;
		assert(op >= 1 && op <= 4);
		if(op <= 2) {
			while(!q[op].empty() && t[q[op].front().st] != q[op].front().nd)
				q[op].pop();
			if(q[op].empty()) {
				cout << "-1\n";
				continue;
			}
			t[q[op].front().st] = -1; // este scos din coada
			where[q[op].front().st] = 0;
			cout << q[op].front().st << '\n';
			q[op].pop();
			sz[op]--;
		} else if(op == 3) {
			cin >> x;
			assert(1 <= x && x <= 1e6);
			assert(where[x] == 0);
			int sw = 1;
			if(sz[1] > sz[2]) sw = 2;
			sz[sw]++;
			t[x] = i;
			q[sw].push({x, i});
			where[x] = sw;
			cout << sw << '\n';
		} else {
			cin >> x;
			assert(1 <= x && x <= 1e6);
			assert(where[x] <= 2 && where[x] > 0);
			sz[where[x]]--;
			where[x] = 0;
			t[x] = -1; // il scot din coada
		}
	}
} 