#include <iostream>
#include <algorithm>
using namespace std;
int mat[202][202], n, x, r;
int main() {
    cin >> x >> r >> n;
    for (int j = 1; j <= n; j++)
        for (int i = 1; i <= n; i ++)
            mat[i][j] = x, x = x + r;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << mat[i][j] << " ";
        cout << "\n";
    } return 0;
}