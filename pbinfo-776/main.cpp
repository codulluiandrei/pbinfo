#include <iostream>
using namespace std;
int main() {
    int n, m, mat[101][101], nr = 0, temp = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        	cin >> mat[i][j];
    for (int i = 0; i < n; i++) {
        nr = 0;
        for (int j = 1; j < m; j++) {
            if (mat[i][j] == mat[i][0]) nr++;
        } if (nr == m - 1) temp++;
    } cout << temp;
    return 0;
}