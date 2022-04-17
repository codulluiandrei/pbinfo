#include <bits/stdc++.h>
using namespace std;
int n, mat[100][100];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> mat[i][j];
    int rezultat = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (mat[i][j] > mat[i - 1][j] 
                && mat[i][j] > mat[i + 1][j] 
                && mat[i][j] > mat[i][j + 1] 
                && mat[i][j] > mat[i][j - 1])
                rezultat++;
    cout << rezultat;
    return 0;
}