#include <iostream>
using namespace std;
int main() {
	int mat[202][202], n, Z, S = 0;
	cin >> n >> Z;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> mat[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            if (Z == 1 && (i < j && i + j < n + 1))
                S = S + mat[i][j];
            if (Z == 2 && (i < j && i + j > n + 1))
                S = S + mat[i][j];
            if (Z == 3 && (i > j && i + j > n + 1))
                S = S + mat[i][j];
            if (Z == 4 && (i > j && i + j < n + 1))
                S = S + mat[i][j];
        } cout << S;
    return 0;
}
