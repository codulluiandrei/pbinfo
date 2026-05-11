#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("mugur.in");
ofstream g("mugur.out");
int n;
int p, t, nr;
int push_val[100005];
int x, y;
string s;
struct {
	int val, maxsuf;
} aint[400005];
void update(int st, int dr, int ind, int val) {
	if (p < st || dr < p) return;
	if (st == dr) {
		aint[ind].val = aint[ind].maxsuf = val;
		return;
	}
	int mij = (st + dr + 1) / 2;
	update(st, mij - 1, 2 * ind, val);
	update(mij, dr, 2 * ind + 1, val);
	aint[ind].val = aint[2 * ind].val + aint[2 * ind + 1].val;
	aint[ind].maxsuf = max(aint[2 * ind + 1].maxsuf, aint[2 * ind].maxsuf + aint[2 * ind + 1].val);
}
void push() {
	f >> nr;
	push_val[p] = nr;
	update(1, n, 1, 1);
}
void pop() {
	x = p; y = n;
	update(1, n, 1, -1);
}
int query(int st, int dr, int ind, int pref) {
	if (st == dr) return st;
	int mij = (st + dr + 1) / 2;
	if (aint[2 * ind + 1].maxsuf >= pref)
		return query(mij, dr, 2 * ind + 1, pref);
	else
		return query(st, mij - 1, 2 * ind, pref - aint[2 * ind + 1].val);
}
void solve() {
	int rez = query(1, n, 1, 1);
	if (aint[1].maxsuf <= 0) g << -1 << '\n';
	else g << push_val[rez] << '\n';
}
int main() {
	f >> n;
	for (int i = 1; i <= n; i++) {
		f >> p >> s;
		if (s == "push") {
			push();
		}
		else pop();
		solve();
	}
}