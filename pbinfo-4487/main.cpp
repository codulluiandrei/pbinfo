// Problema moser - solutie in O(Q+max(N)^2) timp si O(N^2) spatiu - 25 puncte
#include <iostream>
// Valoarea noastra MOD.
const int MOD = 1000000007;
// comb[i][j] = C(i,j)
int comb[5001][5001];
// Precalculam toate combinarile folosind formula:
// C(n,k) = C(n-1,k) + C(n-1,k-1)
void preprocess() {
	comb[0][0] = 1;
	for (int i = 1; i < 5001; i++) {
		comb[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
			if (comb[i][j]>=MOD) {
				comb[i][j] -= MOD;
			}
		}
	}
}
// In sol, evitam folosirea operatiilor modulo pentru a optimiza mai departe programul.
int sol(int x) {
	int ret = 1 + comb[x][2] + comb[x][4];
	while (ret>=MOD) {
		ret -= MOD;
	}
	return ret;
}
int main() {
	// Fastio
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	// Precalculam triunghiul lui Pascal
	preprocess();
	// Citim si raspundem la query-uri.
	int q;
	std::cin >> q;
	while (q--) {
		int x;
		std::cin >> x;
		std::cout << sol(x) << "\n";
	}
}