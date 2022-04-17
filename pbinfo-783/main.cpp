#include <iostream>
using namespace std;
int main() {
	int mat[101][101], n, dea = 0, sub = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> mat[i][j];
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == (j + 1)) sub = sub + mat[i][j];
			else if (i == (j - 1)) dea = dea + mat[i][j];
		}
	} cout << dea + sub;
	return 0;
}
