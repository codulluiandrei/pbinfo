#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	int mat[N + 2][M + 2];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> mat[i][j];
		}
	}
	ll answer = 0;
	if (N <= M) {
		for (int i1 = 1; i1 <= N; i1++) {
			for (int i2 = i1 + 1; i2 <= N; i2++) {
				int cnt = 0;
				for (int j = 1; j <= M; j++) {
					if (mat[i2][j] == 0) {
						cnt = 0;
					} else if (mat[i1][j] == 1) {
						answer += cnt;
						cnt++;
					}
				}
			}
		}
	} else {
		bool ok[N + 2];
		for (int j1 = 1; j1 <= M; j1++) {
			for (int i = 1; i <= N; i++) {
				ok[i] = mat[i][j1];
			}
			for (int j2 = j1 + 1; j2 <= M; j2++) {
				int cnt = 0;
				for (int i = 1; i <= N; i++) {
					if (mat[i][j2] == false) {
						ok[i] = false;
					}
					if (ok[i] == true) {
						answer += cnt;
					}
					if (mat[i][j1] == true && mat[i][j2] == true) {
						cnt++;
					}
				}
			}
		}
	}
	cout << answer << "\n";
	return 0;
}