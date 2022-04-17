#include <bits/stdc++.h>
using namespace std;
int main() {
    int mat[25][25], n; cin >> n;
    for (int i = 1 ; i <= n; i++)
        for (int j = 1; j <= n ; j++) {
            if ((i == j) || ((i + j) == (n + 1))) mat[i][j] = 0;
            else if ((i < j) && (i + j)<(n + 1)) mat[i][j] = 1;
                else if ((i > j) && (i + j)>(n + 1)) mat[i][j] = 2;
                    else mat[i][j] = 3;
        }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1; j <= n ; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    } return 0;
}