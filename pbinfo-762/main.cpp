#include <iostream>
using namespace std;
int main() {
    int mat[101][101], n, m, nr = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) 
	        cin >> mat[i][j];
    for (int i = 1; i < n; i++)
        for (int t = i + 1; t <= n; t++) {
        bool adv = true;
        for (int j = 1; j <= m; j++)
            if (mat[i][j] != mat[t][j]) adv = false;
            if (adv == true) nr++;
    } cout << nr;
    return 0;
}