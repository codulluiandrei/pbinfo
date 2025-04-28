/// autor Ciobanu Bogdan
#include <stdio.h>
#include <algorithm>
#include <numeric>
#include <memory>
using namespace std;
const int MAX_N = 100, MAX_D = 10000;
const int MOD = int(1e9) + 7;
bool A[MAX_N][MAX_N];
int p[MAX_N], d[MAX_N];
int dp[2][MAX_D + 1];
int N;
bool is_leaf(int node) {
	if (node == 0) return false;
	bool has_adj = false;
	for (int i = 0; i < N; ++i) if (A[node][i]) {
		if (has_adj) return false;
		has_adj = true;
	}
	return true;
}
int main() {
	unique_ptr<FILE, decltype(&fclose)> f(fopen("tairos.in", "r"), fclose);
	int D; fscanf(f.get(), "%d%d", &N, &D);
	for (int _ = 0; _ < N - 1; ++_) {
		int x, y; fscanf(f.get(), "%d%d", &x, &y); --x; --y;
		A[x][y] = A[y][x] = true;
	}
	fill(p + 1, p + N, -1);
	while (true) {
		bool changed = false;
		for (int i = 0; i < N; ++i) if (p[i] != -1) {
			for (int j = 0; j < N; ++j) if (A[i][j] && p[j] == -1) {
				p[j] = i;
				d[j] = d[i] + 1;
				changed = true;
			}
		}
		if (!changed) break;
	}
	dp[0][0] = 1;
	for (int s = 0; s <= D; ++s) {
		for (int i = 0; i < N; ++i) if (s + d[i] <= D) {
			(dp[!is_leaf(i)][s + d[i]] += dp[0][s]) %= MOD;
		}
	}
	f.reset(fopen("tairos.out", "w"));
	fprintf(f.get(), "%d\n", dp[1][D]);
	return 0;
}