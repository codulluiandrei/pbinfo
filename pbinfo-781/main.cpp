#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int mat[202][202], n, S1 = 0, S2 = 0, S3 = 0, S4 = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> mat[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            if (i < j && i + j < n + 1)
                S1 = S1 + mat[i][j];
            if (i < j && i + j > n + 1)
                S2 = S2 + mat[i][j];
            if (i > j && i + j > n + 1)
                S3 = S3 + mat[i][j];
            if (i > j && i + j < n + 1)
                S4 = S4 + mat[i][j];
        }
    int v[5];
    v[1] = S1; v[2] = S2; v[3] = S3; v[4] = S4;
    sort(v, v + 4);
    for (int i = 1; i <= 4; ++i)
    	cout << v[i] << " ";
    return 0;
}
