#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, m, mat[101][101];
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> mat[i][j];
    for (int i = 0; i < n; ++i) 
        sort(mat[i], mat[i] + m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << mat[i][j] << " ";
        cout << endl;
    } return 0;
}