#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, mat[20][20], temp = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            mat[i][j] = temp;
            temp++;
        }
    } for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
        for (int j = m; j >= 1; j--) cout << mat[i][j] << " ";
		} else {
        for (int j = 1; j <= m; j++) cout << mat[i][j] << " "; 
    } cout << endl;
    } return 0;
}