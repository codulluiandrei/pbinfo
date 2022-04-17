#include <iostream>
using namespace std;
int main() {
    int mat[101][101], n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
	bool adv = true;
    int mijloc = m / 2 + 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (mat[i][mijloc - j] != mat[i][mijloc + j]) adv = false;
	if (adv == true) cout << "DA";
    else cout << "NU";
    return 0;
}