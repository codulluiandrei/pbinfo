#include <iostream>
using namespace std;
int n, m, k, mat[101][101], freq[10001];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
    int S = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        	if (mat[i][j] % 2 == 0 && freq[mat[i][j]] == 0) {
                    S = S + mat[i][j];
        			freq[mat[i][j]] = 1;
    			} cout << S;
    return 0;
}