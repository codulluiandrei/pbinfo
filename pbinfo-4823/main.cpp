// Solutie de 100 de puncte folosind programare dinamica si sume partiale
#include <iostream>
#include <vector>
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int x;
	std::cin >> x;
	const int MOD = 666013;
	std::vector<std::vector<int>> dp(x, std::vector<int>(x, 0));
	std::vector<std::vector<int>> sfx(x, std::vector<int>(x, 0));
	for (int i = x-1; i >= 0; i--) {
		for (int j = x-1; j >= 0; j--) {
			if (i == x-1 && j == x-1) {
				dp[i][j] = sfx[i][j] = 1;
				continue;
			}
			if (i+1 <= x-1) {
				dp[i][j] += sfx[i+1][j];
				sfx[i][j] += sfx[i+1][j];
			}
			if (j+1 <= x-1) {
				dp[i][j] += sfx[i][j+1];
				sfx[i][j] += sfx[i][j+1];
				if (dp[i][j]>=MOD) {
					dp[i][j] -= MOD;
				}
				if (sfx[i][j]>=MOD) {
					sfx[i][j] -= MOD;
				}
			}
			if (i+1 <= x-1 && j+1 <= x-1) {
				dp[i][j] -= sfx[i+1][j+1];
				sfx[i][j] -= sfx[i+1][j+1];
				if (dp[i][j]<0) {
					dp[i][j] += MOD;
				}
				if (sfx[i][j]<0) {
					sfx[i][j] += MOD;
				}
			}
			sfx[i][j] += dp[i][j];
			if (sfx[i][j]>=MOD) {
				sfx[i][j] -= MOD;
			}
		}
	}
	std::cout << dp[0][0] << "\n";
}