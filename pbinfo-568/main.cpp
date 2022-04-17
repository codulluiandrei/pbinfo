#include <iostream>
using namespace std;
int main() {
	int mat[1001][1001], n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> mat[i][j];
	for (int j = m; j >= 1; --j) {
		bool adv = false;
		for (int i = 1; i <= n; ++i)
			if (mat[i][j] == 0) adv = true;
		if (adv == true) {
			for (int k = j; k < m; ++k)
				for (int i = 1; i <= n; ++i)
					mat[i][k] = mat[i][k + 1];
			m--;
		}
	} int S = 0, minim = 10001;
	for (int j = 1; j <= m; ++j) {
		for (int i = 1; i <= n; ++i)
			if (mat[i][j] < minim) minim = mat[i][j];
		S = S + minim;
		minim = 10001;
	} cout << S;
	return 0;
}
