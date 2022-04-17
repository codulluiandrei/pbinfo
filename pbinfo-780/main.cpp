#include <iostream>
using namespace std;
int main() {
	int mat[101][101], n, dea = 0, sub = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> mat[i][j];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (i < j)
				dea = dea + mat[i][j];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j<= n; ++j)
			if (i > j)
				sub = sub + mat[i][j];
	while (sub != dea)
		if (sub > dea) sub = sub - dea;
		else dea = dea - sub;
	cout << sub;
	return 0;
}
