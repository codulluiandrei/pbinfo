#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, m, k = 0, mat[101][101], v[1001];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    for (int i = 0; i < n; i = i + n - 1)
        for (int j = 0; j < m; j++) {
            v[k] = mat[i][j];
            k++;
        }
    for (int i = 1; i < n - 1; i++)
        for (int j = 0; j < m; j = j + m - 1) {
            v[k] = mat[i][j];
            k++;
        }
    sort(v, v + k);
    for (int i = 0; i < k; i++) {
        if (v[i] != v[i - 1])
        cout << v[i] << " ";
    } return 0;
}