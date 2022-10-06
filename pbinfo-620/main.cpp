#include <iostream>
using namespace std;
int mat[101][101], n, m;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> mat[i][j];
    for (int j = 1; j <= m; ++j)
        for (int i = 1; i < n; ++i)
            for (int k = i + 1; k <= n; ++k)
                if(mat[i][j] < mat[k][j])
        			swap(mat[i][j], mat[k][j]);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            cout << mat[i][j] << " ";
        cout << "\n";
    } return 0;
}