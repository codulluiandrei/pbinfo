#include <bits/stdc++.h>
using namespace std;
ifstream in("romburi.in");
ofstream out("romburi.out");
#define cin in
#define cout out
int n, m, p, mat[1200][1200];
int main() {
	cin >> n >> m >> p;
	for (int k = 1; k <= p; ++k) {
		int i, j, L;
		in >> i >> j >> L;
		for (int x = 0; x < L; x++)
			for (int y = 0; y <= x; y++) {
				mat[i + x][j + y] = 1;
				mat[i + x][j - y] = 1;
			} i = i + 2 * (L - 1);
			for (int x = 0; x < L - 1; x++)
				for (int y = 0; y <= x; y++) {
					mat[i - x][j + y] = 1;
					mat[i - x][j - y] = 1;
				}
	} int contor = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (mat[i][j] == 0)
				contor++;
	cout << contor;
	return 0;
}
