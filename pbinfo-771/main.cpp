#include <iostream>
using namespace std;
int main() {
    int n, m, mat[101][101], v[101], s[101];
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            s[i] = s[i] + mat[i][j];
    for (int j = 1; j <= n; j++) v[j] = j;
    for (int i = 1; i < n; i++)
        for (int t = i + 1; t <= n; t++)
            if (s[v[i]] > s[v[t]]) {
                int temp = v[i];
                v[i] = v[t];
                v[t] = temp;
            } for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << mat[v[i]][j] << " ";
        } cout << endl;
    } return 0;
}